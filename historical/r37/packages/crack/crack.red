module crack;   % Top level CRACK module.

% Revised for development system by FJW, 28 July 1998
% May require more than one run to compile using Win32-PSL.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                   %
%   CRACK Version  21 March 96                                      %
%                                                                   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

comment

Title: CRACK
Authors:

        Andreas Brand 
        Institut fuer Informatik 
        Friedrich Schiller Universitaet Jena  
        07740 Jena,  Germany 
        email: maa@hpux.rz.uni-jena.de
        tel.:  + 49 3641 631123 ,

        Thomas Wolf 
        School of Mathematical Sciences 
        Queen Mary and Westfield College 
        University of London 
        London E1 4NS 
        email: T.Wolf@maths.qmw.ac.uk
        tel.:  + 44 71 975 5493

Date of last change: 1996-03-21

Abstract:
CRACK is a package for solving overdetermined systems of partial or
ordinary differential equations (PDEs, ODEs). Examples of programs 
which make use of CRACK for investigating ODEs (finding symmetries, 
first integrals, an equivalent Lagrangian or a "differential 
factorization") are added. The manual CRACK.TEX gives further details.

REDUCE version: 3.6.
CRACK uses the package ODESOLVE of Malcolm MacCallum which is included
in REDUCE 3.6. 

T. Wolf, An Analytic Algorithm for Decoupling and Integrating
         systems of Nonlinear Partial Differential Equations, J. Comp. 
         Phys., no. 3, 60 (1985) 437-446.
T. Wolf, The Symbolic Integration of Exact PDEs, preprint.
M.A.H. MacCallum, An Ordinary Differential Equation Solver for REDUCE,
         Proc. ISAAC'88, Springer Lect. Notes in Comp Sci. 358, 
         196--205.

Keywords: partial differential equations, computer analytic

$

%% Additions by FJW.  The following are defined in PSL but not CSL.
%% (See also crstart.)

fluid '(promptstring!*)$

if getd 'setprop then flag('(setprop), 'lose);
% Could also use conditional parsing (!#if) for this.

% The following smacro definitions MUST be in this header file!

symbolic smacro procedure flag1(U, V);
   %% The identifier U is flagged V.
   %% FJW: Defined and flagged lose in PSL only.
   %% FJW: This implementation based on the PSL manual.
   flag({U}, V)$

symbolic smacro procedure remflag1(U, V);
   %% Remove V from the property list of identifier U.
   %% FJW: Defined and flagged lose in PSL only.
   %% FJW: This implementation based on the PSL manual.
   remflag({U}, V)$

%% !#if (equal version!* "REDUCE Development Version")
%% ACH: To build with the bootstrappping version need this test instead:
!#if (neq version!* "REDUCE 3.6")

% Taken from crinit, but needs to be here:
fluid '(REDUCEFUNCTIONS_ 
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

create!-package('(
   crack
   crinit        %  initialisation and help
   crmain        %  main module	
   crdec         %  decouple module
   crsep         %  separation module
   crgensep      %  generalized separation module
   crint         %  integration of pde's module
   crsimp        %  simplification and substitution module
   crutil        %  procedures used in several modules
   crsimpso      %  simplification of the results
   %% FJW: crintfix is for REDUCE 3.6 (and earlier versions?)
   %% crintfix      %  patch for the integration
   crequsol      %  equivalence of solutions
   crshort       %  reductions in length
   crorder       %  orderings support
   crstart       %  FJW: Startup code (moved from module crack)
   ), nil);

!#else

% For distributed REDUCE:

% FJW: Load support packages, but not when compiling:
!#if (getd 'packages_to_load)
packages_to_load ezgcd,odesolve,factor,int,algint;
!#else                                  % for REDUCE 3.6
apply1('load_package, '(ezgcd odesolve factor int algint));
!#endif

in crinit!.red$        %  initialisation and help
in crmain!.red$        %  main module
in crdec!.red$         %  decouple module
in crsep!.red$         %  separation module
in crgensep!.red$      %  generalized separation module
in crint!.red$         %  integration of pde's module
in crsimp!.red$        %  simplification and substitution module
in crutil!.red$        %  procedures used in several modules
in crsimpso!.red$      %  simplification of the results

!#if (equal version!* "REDUCE 3.6")
in crintfix!.red$      %  patch for the integration
!#endif

in crequsol!.red$      %  equivalence of solutions
in crshort!.red$       %  reductions in length
in crorder!.red$       %  orderings support

%********************************************************************
%
% $Id: crack.red,v 1.1 1998/06/04 15:03:16 tw Exp tw $
%
%********************************************************************

setcrackflags()$
!*fullroots:=t$
!*dfprint:=t$

!#endif

endmodule;

end$
