%**********************************************************************
module crackinit$
%**********************************************************************
%  Initialisation 
%  Author: Andreas Brand 1993, continued by Thomas Wolf
%
% $Id: crinit.red,v 1.22 1998/06/25 18:18:27 tw Exp tw $
%  
symbolic fluid '(REDUCEFUNCTIONS_ 
         cont_ odesolve_ print_ print_more print_all
         facint_ potint_ freeint_ level_ poly_only safeint_ solvealg_
         logoprint_ independence_ tr_gensep tr_decouple homogen_
         tr_genint tr_main contradiction_ stop_ fname_ nfct_ fnew_
         ftem_ genint_ gensep_ new_gensep ineq_ time_ adjust_fnc
         subst_0 subst_1 subst_2 subst_3 subst_4 cost_limit5
         pdelimit_0 pdelimit_1 pdelimit_2 pdelimit_3 pdelimit_4 
         length_inc tr_redlength proc_list_ full_proc_list_ to_do_list   
         !*batch_mode printmenu_ expert_mode repeat_mode 
	 dec_hist dec_hist_list depl_copy_ 
         nequ_ eqname_ allflags_ prop_list maxalgsys_ stepcounter_
	 batchcount_ crackrules_ userrules_ rulelist_ history_
         explog_ trig1_ trig2_ trig3_ trig4_ trig5_ trig6_ trig7_ trig8_
         max_red_len max_factor orderings_ tr_orderings simple_orderings
         lex_ collect_sol)$

switch batch_mode$

symbolic operator setcrackflags$
symbolic procedure setcrackflags$
<<REDUCEFUNCTIONS_:= '(ABS ACOS ACOSD ACOSH ACOT ACOTD ACOTH ACSC ACSCD
                       ACSCH ASEC ASECD ASECH ASIN ASIND ASINH ATAN 
                       ATAND ATANH ATAN2 ATAN2D CBRT COS COSD COSH COT 
                       COTD COTH CSC CSCD CSCH EXP FACTORIAL HYPOT LN 
                       LOG LOGB LOG10 SEC SECD SECH SIN SIND SINH SQRT 
                       TAN TAND TANH PLUS DIFFERENCE DF MINUS TIMES 
                       QUOTIENT EXPT INT)$
crackrules_:=nil$
userrules_:=nil$
to_do_list:=nil$

allflags_:='(to_eval to_int to_sep to_gensep to_decoup to_diff)$
prop_list:='(val fcts vars nvars level derivs fcteval_lin fcteval_nca
             fcteval_nli printlength length rational nonrational 
             allvarfcts starde dec_with dec_with_rl dec_info rl_with 
             terms orderings)$

full_proc_list_:='(
              to_do
              subst_level_0
              subst_level_05
              subst_level_45
              separation
              quick_integration       
              factorization 
              subst_derivative
              length_reduction_1      
              subst_level_1
              subst_level_3 
              full_integration        
              integration             
              gen_separation 
              subst_level_5
              subst_level_2 
              subst_level_33
              subst_level_35
              subst_level_4
              add_differentiated_pdes
              length_reduction_2   
              decoupling
              add_diff_star_pdes
              multintfac
              alg_solve_deriv
              alg_solve_system
              undo_subst_derivative
              stop_batch
             )$

proc_list_:=setdiff(full_proc_list_,
      	       	     '(add_differentiated_pdes
                       multintfac
                       subst_level_45
                       subst_level_5
                       alg_solve_system
                       stop_batch
		       length_reduction_1))$

%stepcounter_:=0$   % counter for solving steps
!*batch_mode:=t$   % running crack in batchmode
printmenu_:=nil$   % print interactive mode menu
expert_mode:=nil$  % "half automatic" when running crack in non batch mode
repeat_mode:=nil$  % "repeat mode" when running crack in non batch mode
if not fixp nfct_ then
nfct_:=1$          % index of new functions and constants initialized
level_:=nil$       % actual level of crack recursion
cont_:=nil$        % interactive user control for integration or 
                   % substitution oflarge expressions is disabled
independence_:=nil$% interactive control of linear independence disabled
genint_:=15$       % if =nil then generalized integration disabled
                   % else the maximal number of new functions and extra
                   % equations due to generalized integration                
facint_:=1000$     % =nil then no search for integrating factors
                   % otherwise max product terms*kernels for investigation
potint_:=t$        % allowing `potential integration'
safeint_:=t$       % uses only solutions of ODEs with non-vanishing denom.
freeint_:=t$       % Do only integrations if expl. part is integrable
odesolve_:=10$     % maximal length of a de (number of terms) to be
                   % integrated as ode
max_factor:=400$   % maximal number of terms to be factorized
gensep_:=1000$     % max. size of expressions to separate in a 
		   % generalized way
new_gensep:=nil$   % whether or not a new form of gensep should be used
subst_0:=2$        % maximal length of an expression to be substituted
subst_1:=8$        %
subst_2:=100$      % 
subst_3:=20$       %
subst_4:=10^3$     %
cost_limit5:=100$  % maximal number of extra terms generated by a subst.
max_red_len:=50000$% maximal product of lengths of two equ.s to be
                   % combined with length-reducing decoupling
pdelimit_0:=nil$   % maximal product length(pde)*length(subst_expr)
pdelimit_1:=10^3$  % nil=no length limit
pdelimit_2:=10^4$  %
pdelimit_3:=10^3$  %
pdelimit_4:=10^5$  %
%same_length:=2$    % 
%same_fcts:=10$     %
%same_derivs:=10$   %
length_inc:=1.0$   % factor by which the length of an expression may
                   % grow during decoupling
tr_main:=t$        % Trace main procedure
tr_gensep:=nil$    % Trace generalized separation
tr_genint:=nil$    % Trace generalized integration
tr_decouple:=nil$  % Trace decoupling process
tr_redlength:=nil$ % Trace length reduction
tr_orderings:=nil$ % Trace orderings stuff
homogen_:=nil$     % Test for homogeneity of each equation (for debugging)
solvealg_:=nil$    % Use SOLVE for algebraic equations
print_more:=t$     % Print more informations about the pdes
print_all:=nil$    % Print all informations about the pdes
fname_:='c_$       % name of new functions and constants (integration)
nequ_:=1$          % index of new equations initialized
eqname_:='e$       % name of new equations
logoprint_:=t$     % print logo for crack call
poly_only:=nil$    % all equations are polynomials only 
time_:=nil$        % print the time needed for running crack 
print_:=12$        % maximal length of an expression to be printed
dec_hist:=0$       % length of pde history list during decoupling
maxalgsys_:=20$    % max. number of equations to be solved in specialsol
adjust_fnc:=nil$   % if t then free constants/functions are scaled and
                   % redundant ones are droped to simplify the result 
orderings_:=nil$   % Stores the orderings list, nil initially	
simple_orderings:=t$ % Turn off orderings support except for trivial case
lex_:=nil$	   % if t then use lexicographic instead of tot. degree
collect_sol:=t$    % whether solutions found shall be collected and
                   % returned together at the end or not (to save memory)

put('to_do,'description,
    list("To do list"))$

put('subst_level_0,'description,
    list("Substitution:",
         if subst_0 then " subst. expr.<=",subst_0,
         if pdelimit_0 then ", pde<=",pdelimit_0,
         ", fcts. of less vars."))$
put('subst_level_05,'description,
    list("Substitution:",
         if subst_0 then " subst. expr.<=",subst_0,
         if pdelimit_0 then ", pde<=",pdelimit_0,
         ", alg. expressions."))$
put('subst_level_1,'description,
    list("Substitution:",
         if subst_1 then " subst. expr.<=",subst_1,
         if pdelimit_1 then ", pde<=",pdelimit_1,
         ", fcts. of less vars."))$
put('subst_level_2,'description,
    list("Substitution:",
         if subst_2 then " subst. expr.<=",subst_2,
         if pdelimit_2 then ", pde<=",pdelimit_2,
         ", fcts. of less vars."))$
put('subst_level_3,'description,
    list("Substitution:",
         if subst_3 then " subst. expr.<=",subst_3,
         if pdelimit_3 then ", pde<=",pdelimit_3))$
put('subst_level_33,'description,
    list("Substitution:",
         if subst_4 then " subst. expr.<=",subst_4,
         if pdelimit_4 then ", pde<=",pdelimit_4,
         " no cases, f-indep. coeff."))$
put('subst_level_35,'description,
    list("Substitution:",
         if subst_4 then " subst. expr.<=",subst_4,
         if pdelimit_4 then ", pde<=",pdelimit_4," no cases"))$
put('subst_level_4,'description,
    list("Substitution:",
         if subst_4 then " subst. expr.<=",subst_4,
         if pdelimit_4 then ", pde<=",pdelimit_4))$
put('subst_level_45,'description,
    list("Substitution of zero minimal growth, no cases"))$
put('subst_level_5,'description,
    list("Unlimited substitution of minimal growth"))$
put('subst_derivative,'description,
    list("Substitution of derivatives by new functions"))$
put('undo_subst_derivative,'description,
    list("Undo Substitutions of derivatives by new functions"))$
put('factorization,'description,
    list("Factorization",
         " and investigation of resulting subcases"))$
put('separation,'description,
    list("Direct separation"))$
put('quick_integration,'description,
    list("Integration of a first order de with at",
         " most two terms."))$
put('full_integration,'description,
    list("Integration of a pde such that",
         " a function can be subst."))$
put('integration,'description,
    list("Integration"))$
put('multintfac,'description,
    list("Find an integrating factor for a set of pde's"))$
put('length_reduction_2,'description,
    list("Length reducing decoupling steps"))$
put('decoupling,'description,
    list("Do one decoupling step"))$
put('gen_separation,'description,
    list("Indirect separation"))$
put('add_differentiated_pdes,'description,
    list("Differentiate pdes with nonlinear leading derivs"))$
put('add_diff_star_pde,'description,
    list("Differentiate star - pdes"))$
put('length_reduction_1,'description,
    list("Length reducing algebraic combinations of equations"))$
put('alg_solve_deriv,'description,
    list("Solving an algebraic equation."))$
put('alg_solve_system,'description,
    list("Solving equations for fnct.s or deriv.s algebraically"))$
put('stop_batch,'description,
    list("Stop batch mode"))$

  ini_let_rules()
>>$

algebraic procedure ini_let_rules$
begin 
  explog_:= {
  cot(~x) => 1/tan(x),
  e**(~x+~y) => e**x*e**y,
  sqrt(e)**(~x+~y) => sqrt(e)**x*sqrt(e)**y,
  e**((~x+~y)/~z) => e**(x/z)*e**(y/z),
  sqrt(e)**((~x+~y)/~z) => sqrt(e)**(x/z)*sqrt(e)**(y/z),
  sqrt(e)**(log(~y)/~x) => y**(1/x/2),
  sqrt(e)**(-log(~y)/~x) => y**(-1/x/2),
  sqrt(e)**(~x*log(~y)/~z) => y**(x/z/2),
  sqrt(e)**(-~x*log(~y)/~z) => y**(-x/z/2),
  sqrt(e)**((~x*log(~y))/~z) => y**(x/z/2),
  e**(log(~y)/~x) => y**(1/x),
  e**(~x*log(~y)/~z) => y**(x/z),
  e**((~x*log(~y))/~z) => y**(x/z),
  int(df(~y,~x)/~y,~x) => log(y) } $

  trig1_:={sin(~x)**2  => 1-cos(x)**2}$
  trig2_:={cosh(~x)**2 => (sinh(x)**2 + 1)}$
  trig3_:={tan(~x/2)   => (1-cos(x))/sin(x)}$
  trig4_:={cot(~x/2)   => (1+cos(x))/sin(x)}$
  trig5_:={cos(2*~x)   => 1-2*sin(x)**2}$
  trig6_:={sin(2*~x)   => 2*cos(x)*sin(x)}$
  trig7_:={sinh(2*~x)  => 2*sinh(x)*cosh(x)}$
  trig8_:={cosh(2*~x)  => 2*cosh(x)**2-1}$
end$

endmodule$

end$



