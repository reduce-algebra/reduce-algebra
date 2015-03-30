%**********************************************************************
module crackinit$
%**********************************************************************
%  Initialisation 
%  Author: Andreas Brand 1993 - 97
%          Thomas Wolf since 1994

% BSDlicense: *****************************************************************
%                                                                             *
% Redistribution and use in source and binary forms, with or without          *
% modification, are permitted provided that the following conditions are met: *
%                                                                             *
%    * Redistributions of source code must retain the relevant copyright      *
%      notice, this list of conditions and the following disclaimer.          *
%    * Redistributions in binary form must reproduce the above copyright      *
%      notice, this list of conditions and the following disclaimer in the    *
%      documentation and/or other materials provided with the distribution.   *
%                                                                             *
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE   *
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
% POSSIBILITY OF SUCH DAMAGE.                                                 *
%******************************************************************************

% variables that can change during a computation, for example, interactively
% and that are backed up in crackmain calls, i.e. they are ONLY passed on

pass_on:='( asymplis!* !*batch_mode !*complex !*iconic adjust_fnc alg_poly
allflags_ auto_para_mode batchcount_ batch_mode_sub call_crack_out case_list
choose_6_20_max_ftem choose_6_20_max_terms choose_27_8_16_max
choose_30_47_21_max choose_70_65_8_47_origmem choose_70_65_8_47_origterms
choose_70_65_8_47_ratiomem choose_70_65_8_47_ratioterms choose_30_47_72_eqn
choose_11_30_max_11 choose_11_30_max_30 collect_sol confirm_subst cont_
contradiction_ cost_limit5 depl!* crack_download_add crack_ini_file
crack_load_command currently_to_be_substituted_in diffelim_steps eqn_input
eqn_no eqname_ eqn_to_be_gen equations_file expert_mode explog_ facint_ fhom_
flin_ fname_ fnew_ form_comp form_eqn_idx form_eqn_on_disk form_max_read
freeabs_ freeint_ fsub_ ftem_ genint_ groeb_diff_max groeb_solve high_gensep
idnties_ independence_ ineq_ ineq_or inter_divint keep_case_tree keep_parti
kord!* largest_fully_shortened last_free_cells last_steps lazy_eval
length_inc_alg length_inc_dec lex_df lex_fc lin_problem logoprint_ low_gensep
max_coeff_len max_gc_elimin max_gc_fac max_gc_gb max_gc_int max_gc_minsub
max_gc_ode max_gc_red_len max_gc_short max_gc_ss max_proc_no max_red_len
maxalgsys_ max_term_to_fac_complex max_term_to_fac_real max_term_to_pred nequ_
min_nu_of_eqn new_gensep odesolve_ paracrack_initialized poly_only potint_
print_ print_all print_more proc_list_ process_counter pvm_able quick_decoup
record_hist recycle_eqns recycle_fcts reduce_call repeat_mode safeint_ session_
singular_call singular_lib singular_time size_watch solvealg_ stop_ 
struc_eqn subst_0 subst_1 subst_2 subst_3 subst_4 target_limit_0
target_limit_1 target_limit_2 target_limit_3 time_ to_do_list tr_decouple
tr_genint tr_gensep tr_main tr_orderings tr_short tr_redlength ud_1 ud_2 ud_3
ud_4 userrules_ verify_end_of_parallel_run vl_)$

% Variables in pass_back are backed up before recursive calls such that
% their value is available when reading a backup file with the rb 
% command but when merging results from a sub-case (in restore_and_merge()
% in crutil.red) then the current value from the sub-case computation
% overwrites the backup value.

pass_back:='(done_trafo history_ limit_time level_ nfct_ size_hist sol_list 
             stepcounter_ time_limit inverse_trafo_list_incomplete)$

COMMENT :

Variables not to be changed interactively are not updated:
   allflags_ crack_load_cmd default_proc_list_ full_proc_list_ 
   lin_test_const my_gc_counter max_gc_counter max_eqn_to_conti
   prop_list one_argument_functions_ reducefunctions_ 
   algebraic mode: abs_ sqrt1_ sqrt2_ 
   trig1_ trig2_ trig3_ trig4_ trig5_ trig6_ trig7_ trig8_ 
   
Variables in pass_on are needed in each case of a computation
and they can be changed interactively but not to be passed back.
Therefore they have to be backed up.
Variables in pass_back can also be changed interactively but
are ment to be used continuously, so they are not backed up.

These variables are separately backed up in crutil.red in backup_to_file()
and updated in restore_backup_from_file(), see also restore_and_merge().

For example, history_ is not backed up to accumulate all input also during 
subcases. Because function names and function dependencies generated
in subcalls of crack are passed back in the solution that is passed back 
and on the other hand the backup depl!* is restored, i.e. the dependencies
of the new functions is dropped, this has to be carried over by
adding their dependencies to the backup depl!*.

An issue is that in parallel computations nothing is returned back
currently (Sep 2003). This has consequences for each of the variables
in pass_back.
$

global_list_integer := '(odesolve_ subst_0 subst_1 subst_2 subst_3
   target_limit_0 target_limit_1 target_limit_2 cost_limit5 
   max_gc_fac max_gc_gb max_gc_ode max_gc_red_len max_gc_short 
   max_gc_ss  maxalgsys_ max_eqn_to_conti nfct_ nequ_ low_gensep 
   high_gensep)$

global_list_ninteger := '(genint_ facint_ new_gensep target_limit_0
   target_limit_1 target_limit_2 target_limit_3 print_ )$

global_list_float := '(length_inc_alg length_inc_dec)$

switch batch_mode$

compiletime global '(groebresmax plotheader!*)$

symbolic procedure name_session$
begin
 random_init()$
 %random_new_seed(1)$ % if a non-random seed is needed for test purposes

 %session_:=explode date()$
 %session_:=
 %   for each c in session_ collect
 %    (if c memq '(!: ! ) then '!- else c);
 %session_ := compress session_;    % proposed by ACN
 %%%session_:=reverse cons(car session_,cdr cddddr reverse session_)$
 %%%if cadr session_ = '!  then session_:=cons(car session_,cddr session_)$
 %%%session_:=compress session_$
 %setq(session_,bldmsg("%w%d-%w-","bu",random 1000,session_))$
 %		    % name of the session, used to generate filename
 %		    % for backup when case splitting
 setq(session_,bldmsg("%w%d-","bu",random 1000000));

 % To allow parallel processes to add found solutions to the file
 % bu*sol_list, and because during adding this file does temporarily
 % not exist, the process which wants to add a solution name does have to
 % wait. If it failed to add the new solution name a couple of time it does
 % not know whether too many processes try to add solutions or whether the
 % bu*so_list file does not exist. Therefore the file bu*so_list has to be
 % created when session_ is assigned:
 sol_list:=nil$
 save_sol_list()
end$

symbolic operator setcrackflags$
symbolic procedure setcrackflags$
<<
one_argument_functions_:='(abs acos acosd acosh acot acotd acoth acsc
 			   acscd acsch asec asecd asech asin asind asinh
			   atan atand atanh cbrt cos cosd cosh cot
			   cotd coth csc cscd csch exp hypot ln
			   log logb log10 sec secd sech sin sind sinh sqrt
			   tan tand tanh minus)$

reducefunctions_:=append(one_argument_functions_,
                         '(atan2 atan2d factorial plus difference df times 
                           quotient expt int))$

allflags_:='(to_eval to_fullint to_int to_sep to_gensep to_casesep to_decoup 
             to_diff to_under 
             to_separant % =t if it is possible that the separant 
               % (=df(eqn,lead_deriv)) vanishes, i.e. if it is known to 
               % vanish or if nothing is known, i.e. =nil iff it is known 
               % not to vanish. One would expect to give it 3 values: nil,0,1 
               % for 'unknown, 'possibly_zero, 'non_zero but the value 0
               % would constantly have to be set to nil when inequalities
               % are updated, so the value 0 would be equivalent to nil
               % which is why to_separant is chosen to be a flag which is
               % still dependent on the ordering. Furthermore, in the
               % March 07 version of dec.red when the separant is computed
               % and found to be possibly zero then its vanishing is
               % instantly investigated as a case next.
            )$

% Most of the following properties are assigned in updateSQ() in crutil.red

prop_list:='(sqval  % the value of the equation in SQ form, always assigned
             fac    % =nil iff not yet factorized,  
                    % =1 if tested by sffac() and no non-trivial factor 
                    % =2 if tested by err_catch_fac2() and no non-trivial factor
                    % else list of factors in SQ form, which may factorize further
             pval   % the value of the equation in prefix form, sometimes assigned
             partitioned % the value of the equation in a special form needed for
                         % integration, assigned in crint.red
             kern   % list of kernels in sqval (numerator and denominator)
             non_rat_kern % All non-rational kernels, including, e.g. sqrt(3) but
                          % not {'df,..}, is used to decide whether simp* is needed
             fct_kern_lin % /both determined in add_fct_kern() in crshort.red,
             fct_kern_nli % \both include all kernels that involve 'fcts
                    % (if alg_poly then the kernels are the 'fcts) where
                    % fct_kern_lin involves flin_ and fct_kern_nli all others
                    % except the non-vanishing ones from ineq_, i.e. it depends
                    % on ineq_ at the time of determining fct_kern_nli
             fcts   % list of dependent variables, i.e. functions
             fct_hom  % the intersection of fcts and the fluid list fhom_
             nfct_lin % number of flin_ functions (used in get_fact_pde())
             vars   % list of independent variables
             nvars  % number of independent variables
             level  % value of level_ when the equation was formulated
             derivs % all powers of all functions and their derivatives, eg.
                    % ((f) . 5)  or ((f x y 2) . 2)
                    % maybe one should store only derivatives which could be leading
                    % wrt some ordering? --> No, one would not know the intersection
                    % of all derivatives to substitute a derivative by a function 
             no_derivs % the number of all different powers of all different
                       % derivatives (proper derivatives, not 0th order derivatives)
             fcteval_lin % list of substitutions (coeff_of_f . f) where coeff_of_f is
                         % free of any 'fcts
             fcteval_nca % ... where coeff_of_f is non-zero
             fcteval_nli % ... where coeff_of_f may be zero
             fcteval_n2l % =t if a function not in flin_ is to be replaced and
                         % the equation contains allvarfcts in flin_, otherwise nil
             fct_nli_lin % subset of 'fcteval_nli where 
                         %        coeff_of_f=0 has an 'fcteval_lin substitution
             fct_nli_nca % subset of 'fcteval_nli where 
                         %        coeff_of_f=0 has an 'fcteval_nca substitution
             fct_nli_nli % subset of 'fcteval_nli where 
                         %        coeff_of_f=0 has an 'fcteval_nli substitution
             fct_nli_nus % subset of 'fcteval_nli where 
                         %        coeff_of_f=0 has no substitutions
             terms       % no_of_tm_sf numr sqval
             length      % pdeweightSF numr + pdeweightSF denr
             printlength %  delengthSF numr +  delengthSF denr
             rational    % list of all rationally occuring functions
             nonrational % list of all non-rationally occuring functions
             allvarfcts  % list of functions of all indep. variables
             starde      % =nil if at lest one function of 'fcts depends 
                         % on all variables 'vars, otherwise =(v . n) with 
                         % v being a list of variables on which the fewest number of
                         % functions depend on and n is that number of functions
             dec_with    % list of equations this equation has been paired with under 30
             dec_with_rl % list of equations this equation has been paired with under 27
             rl_with     % list of equations this equation has been paired with under 11
             hom_deg     % = {total degree of flin_ functions, 
                         %    total degree of all other functions}
             split_test  % =nil if not tested, =1 iff all factors=0 yield 
                         % case-free substitutions, =0 otherwise
             linear_     % =t iff completely linear in all 'fcts (no products) else =nil
             histry_     % how this equation resulted from others, assigned in mkeqSQ()
             not_to_eval % if not nil then a list of unknows which should not be 
                         % eliminated and substituted using this equation
             case2sep    % either nil or a standard quotient expression which if known to
                         % be non-zero will lead to separations
             %orderings   % list of orderings where the equations are valid
             %            % currently = list(0),  inactive
             % degrees
             % dec_info 
            )$

% Some of the modules in the following list are still experimental.
% The order in which they appear in full_proc_list_ is a proposal for
% the order to appear in proc_list_.

full_proc_list_:='(to_do                      % 1
                   separation                 % 2
                   subst_level_0              % 3
                   subst_level_03             % 4
                   subst_level_05             % 5
                   subst_level_45             % 6
                   quick_integration          % 7
                   factorize_to_substitute    % 8
                   subst_derivative           % 9
                   quick_gen_separation       % 10
                   alg_length_reduction       % 11
                   drop_lin_dep               % 12
                   find_1_term_eqn            % 13
                   trian_lin_alg              % 14
                   subst_level_1              % 15
                   subst_level_3              % 16 
                   subst_level_5              % 17
                   subst_level_2              % 18
                   subst_level_33             % 19
                   subst_level_35             % 20
                   subst_level_4              % 21
                   undetlinode                % 22
                   undetlinpde                % 23
                   full_integration           % 24 
                   integration                % 25
                   gen_separation             % 26
                   diff_length_reduction      % 27
                   del_redundant_de           % 28
                   idty_integration           % 29
                   decoupling                 % 30
                   add_differentiated_pdes    % 31
                   add_diff_ise               % 32
                   multintfac                 % 33
                   alg_solve_single           % 34
                   alg_solve_system           % 35
                   undo_subst_derivative      % 36
                   change_proc_list           % 37
                   stop_batch                 % 38
                   find_trafo                 % 39
                   del_redundant_fc           % 40
                   sub_problem                % 41
                   drop_dep_bi_lin            % 42
                   find_factor_bi_lin         % 43
                   split_into_cases           % 44
                   subst_level_04             % 45
                   first_int_for_ode          % 46
                   factorize_any              % 47
                   gen_separation2            % 48
                   find_and_use_sub_systems12 % 49
                   find_and_use_sub_systems13 % 50
                   find_and_use_sub_systems14 % 51
                   find_and_use_sub_systems15 % 52
                   find_and_use_sub_systems22 % 53
                   find_and_use_sub_systems23 % 54
                   find_and_use_sub_systems24 % 55
                   find_and_use_sub_systems25 % 56
                   high_prio_decoupling       % 57
                   user_defined               % 58
                   external_groebner          % 59
                   solution_check1            % 60
                   choose_6_20                % 61
                   choose_27_8_16             % 62
                   choose_30_47_21            % 63
                   solution_check2            % 64
		   case_on_most_frequ_fnc     % 65
                   back_up                    % 66
                   alg_length_reduce_1        % 67
                   check_ineq                 % 68
                   case_separation            % 69
                   pre_determined_case_splits % 70
                   choose_70_65_8_47          % 71
                   read_equation              % 72
                   choose_30_47_72            % 73
		   case_on_most_frequ_factors % 74
                   choose_11_30               % 75
                   try_other_ordering         % 76
                   find_factorization         % 77 
                   para_solve_hom_equ         % 78
                   undetalg                   % 79
                   subst_power                % 80
                   bottom_up_subst            % 81
                   solution_check3            % 82
                   sublinfct                  % 83
                   case_gen_separation        % 84
                  )$ 

for h:=1:length(full_proc_list_) do put(nth(full_proc_list_,h),'no,h)$

default_proc_list_:='(to_do
                     separation
                     subst_level_0
                     subst_level_03
		     quick_integration   
                     find_factorization        
		     factorize_to_substitute
                     factorize_any     
		     subst_derivative
		     subst_level_1
		     full_integration        
		     subst_level_3 
		     subst_level_2 
		     subst_level_33
		     subst_level_35
		     subst_level_4
		     gen_separation 
                     case_separation
		     integration             
		     diff_length_reduction
		     decoupling
                     undetlinode               
		     add_diff_ise
                     try_other_ordering
		     alg_solve_single
		     undo_subst_derivative
                    )$

%--------- Initialization of global variables and their description
put('!*allowdfint_bak,'description,list("backup value of switch"))$
put('!*dfprint_bak,'description,list("backup value of switch"))$
put('!*diffelimverbosity!*,'description,list("backup value of switch"))$
put('!*exp_bak,'description,list("backup value of switch"))$
put('!*ezgcd_bak,'description,list("backup value of switch"))$
put('!*fullroots_bak,'description,list("backup value of switch"))$
put('!*gcd_bak,'description,list("backup value of switch"))$
put('!*mcd_bak,'description,list("backup value of switch"))$
put('!*nopowers_bak,'description,list("backup value of switch"))$
put('!*ratarg_bak,'description,list("backup value of switch"))$
put('!*rational_bak,'description,list("backup value of switch"))$
put('!*batch_mode,'description,list("backup value of switch"))$
put('allflags_,'description,list("list of all flags characterizing each equations"))$
put('batchcount_,'description,list("counter of steps in automatic mode"))$
put('backup_,'description,list("mainly used to read expressions from files"))$
put('contradiction_,'description,list("variable to communicate to calling routines that a contradiction resulted forbidding any solutions"))$
put('fnew_,'description,list("temporary list of new functions/constants in crint.red"))$
put('fsub_,'description,list("if lazy_eval=t then the list of substitutions still to be done in forg"))$
put('ftem_,'description,list("current list of unknown functions and constants to be determined"))$
put('full_proc_list_ ,'description,list("complete list of (automatic) modules"))$
put('gcfree!*,'description,list("number of free cells"))$
put('global_list_integer,'description,list("list of variables that are integers"))$
put('global_list_ninteger,'description,list("list of variables that are integers or nil"))$
put('global_list_float,'description,list("list of floating point variables"))$
put('history_,'description,list("list of interactive input"))$
put('ineq_,'description,list("list of inequalities in sq-form"))$
put('ineq_or,'description,list("list of OR-inequalities each being a list"))$
put('lin_test_const,'description,list("a global variable used to determine linearity of equations"))$
put('max_eqn_to_conti,'description,list("the maximal number of equations to continue in batch_mode (automatic execution)"))$
put('one_argument_functions,'description,list("list of functions iin REDUCE with one argument"))$
put('paracrack_initialized,'description,list("=t if file .reducerc initializes parallelization"))$
put('pass_on,'description,list("variable names whos values are only passed on to subcalls of crackmain"))$
put('pass_back,'description,list("variable names with values passed back from subcalls of crackmain"))$
put('prop_list,'description,list("list of properties of equations"))$
put('pvm_able,'description,list("flag whether current session runs in Parallel-Reduce"))$
put('recycle_eqns,'description,list("list of re-usable equation names previously in use"))$
put('recycle_fcts,'description,list("list of re-usable function names previously in use"))$
put('recycle_ids,'description,list("list of re-usable identity names previously in use"))$
put('reducefunctions,'description,list("the list of REDUCE functions"))$
put('reducerc_initialized,'description,list("used in crpvm to check whether the file .reducerc with pvm initializations was loaded at the start of REDUCE"))$
put('session_,'description,list("the name of the session"))$
put('size_hist,'description,list("list of data about the history of the computation, see size_watch whih determines whether size_hist is created during computation"))$
put('stepcounter_,'description,list("counter od steps"))$
put('to_do_list,'description,list("list of most urgent steps done next"))$
put('userrules_,'description,list("list of user defined LET-rules"))$
put('vl_,'description,list("list of independent variables"))$
put('default_proc_list_,'description,list("default priority list of procedures"))$

verify_end_of_parallel_run:=t$ put('verify_end_of_parallel_run,'description,list("whether at the end a parallel run shall stop to verify the thhat all went well"))$

proc_list_:=default_proc_list_$  put('proc_list_,'description,list("priority list of procedure in use"))$

!*uncached:=t$     put('!*uncached,'description,list("if nil then any long computations with >10,000 algebraic mode steps or expressions read from files become extremely slow"))$

!*batch_mode:=t$   put('!*batch_mode,'description,list("running crack in batchmode"))$

expert_mode:=nil$  put('expert_mode,'description,list("is set with command 't', if expert_mode=t then user has to select equations to be worked with in all steps"))$

repeat_mode:=nil$  put('repeat_mode,'description,list("is set in non batch mode, counter for number of times a step is to be repeated"))$

if not fixp nfct_ then
nfct_:=1$          put('nfct_,'description,list("index of next new functions and constants to be initialized"))$

nequ_:=1$          put('nequ_,'description,list("index of next new equation to be initialized"))$

nid_:=1$           put('nid_,'description,list("index of next new identity to be initialized"))$

fname_:='c_$       put('fname_,'description,list("name of new functions and constants generated, e.g.. in integrations"))$

eqname_:='e_$      put('eqname_,'description,list("name of new equations"))$

idname_:='id_$     put('idname_,'description,list("name of new identities"))$

level_:=nil$       put('level_,'description,list("actual level of crack recursion"))$

cont_:=nil$        put('cont_,'description,list("interactive user control for integration or substitution of large expressions is disabled"))$

independence_:=nil$put('independence_,'description,list("interactive control of linear independence disabled"))$

genint_:=15$       put('genint_,'description,list("if =nil then generalized integration disabled else the maximal number of new functions and extra equations due to generalized integration"))$

facint_:=1000$     put('facint_,'description,list("=nil then no search for integrating factors otherwise max product terms*kernels for investigation"))$

potint_:=t$        put('potint_,'description,list("allowing `potential integration'"))$

safeint_:=t$       put('safeint_,'description,list("uses only solutions of ODEs with non-vanishing denom."))$

freeint_:=t$       put('freeint_,'description,list("Do only integrations if expl. part is integrable"))$

freeabs_:=t$       put('freeabs_,'description,list("Allow only solutions of ODEs without ABS()"))$

odesolve_:=100$    put('odesolve_,'description,list("maximal length of a de (number of terms) to be integrated as ode"))$

low_gensep:=6$     put('low_gensep,'description,list("max. size of expressions to separate in a generalized way with higher priority"))$

high_gensep:=300$  put('high_gensep,'description,list("min. size of expressions to separate in a generalized way with higher priority"))$

new_gensep:=nil$   put('new_gensep,'description,list("whether or not a new form of gensep should be used"))$

my_gc_counter:=0$  put('my_gc_counter,'description,list("initialization of my_gc_counter"))$

max_gc_counter:=100000000$put('max_gc_counter,'description,list("max. number of garbage collections"))$

max_gc_short:=40$  put('max_gc_short,'description,list("maximal number of garbage collections during shortening"))$

max_gc_ss:=10$     put('max_gc_ss,'description,list("maximal number of garbage collections during search of sub_systems"))$

max_gc_red_len:=30$put('max_gc_red_len,'description,list("maximal number of garbage collections during length reduction"))$

max_gc_fac:=15$    put('max_gc_fac,'description,list("maximal number of garbage collections during factorization"))$

max_gc_elimin:=20$ put('max_gc_elimin,'description,list("maximal number of garbage collections during elimination in decoupling"))$

max_gc_gb:=100$    put('max_gc_gb,'description,list("maximal number of garbage collections during Groebner Base computation, this is only for the time reading in the result of the successful external GB computation so once, e.g. Singular has computed the GB, there should be enough time given to read the result into CRACK"))$

max_gc_minsub:=10$ put('max_gc_minsub,'description,list("maximal number of garbage collections during search for minimal growth substitution"))$

max_gc_ode:=1$     put('max_gc_ode,'description,list("the maximal number of garbage collections during a call of ODESOLVE (just to avoid hanging)"))$

max_red_len:=1000000$  put('max_red_len,'description,list("max product of lengths of equations to be length reduced with the decouling procedure"))$

max_eqn_to_conti:=0$ put('max_eqn_to_cont,'description,list("used in stop_batch() to stop only if more than max_eqn_to_conti equations are unsolved"))$

max_gc_int:=1$     put('max_gc_int,'description,list("maximal number of garbage collections during integration"))$

subst_0:=2$        put('subst_0,'description,list("maximal printlength of an expression to be substituted in substitutions using this parameter"))$

subst_1:=8$        put('subst_1,'description,list("maximal printlength of an expression to be substituted in substitutions using this parameter"))$

subst_2:=20$       put('subst_2,'description,list("maximal printlength of an expression to be substituted in substitutions using this parameter"))$

subst_3:=10^3$     put('subst_3,'description,list("maximal printlength of an expression to be substituted in substitutions using this parameter"))$

subst_4:=nil$      put('subst_4,'description,list("maximal printlength of an expression to be substituted in substitutions using this parameter"))$

cost_limit5:=100$  put('cost_limit5,'description,list("maximal number of extra terms generated by a substitution using this parameter"))$

target_limit_0:=10^2$   put('target_limit_0,'description,list("maximal product length(pde)*length(subst_expr) in substitutions using this parameter"))$

target_limit_1:=10^3$  put('target_limit_1,'description,list("maximal product length(pde)*length(subst_expr) in substitutions using this parameter, if nil then no length limit"))$

target_limit_2:=10^5$  put('target_limit_2,'description,list("maximal product length(pde)*length(subst_expr) in substitutions using this parameter, if nil then no length limit"))$

target_limit_3:=nil$   put('target_limit_3,'description,list("maximal product length(pde)*length(subst_expr) in substitutions using this parameter, if nil then no length limit"))$

length_inc_dec:=1.0$   put('length_inc_dec,'description,list("factor by which the length of an expression may grow during decoupling"))$

length_inc_alg:=1.0$   put('length_inc_alg,'description,list("factor by which the length of an expression may grow during shortening compared to the shorter one used"))$

tr_main:=nil$      put('tr_main,'description,list("Trace main procedure"))$

tr_gensep:=nil$    put('tr_gensep,'description,list("Trace generalized separation"))$

tr_genint:=nil$    put('tr_genint,'description,list("Trace generalized integration"))$

tr_decouple:=nil$  put('tr_decouple,'description,list("Trace decoupling process"))$

tr_redlength:=nil$ put('tr_redlength,'description,list("Trace length reduction"))$

tr_orderings:=nil$ put('tr_orderings,'description,list("Trace orderings stuff"))$

tr_short:=nil$     put('tr_short,'description,list("Trace the algebraic shortening"))$

solvealg_:=nil$    put('solvealg_,'description,list("Use SOLVE for algebraic equations"))$

print_more:=nil$   put('print_more,'description,list("Print more informations about the pdes"))$

print_all:=nil$    put('print_all,'description,list("Print all informations about the pdes"))$

logoprint_:=t$     put('logoprint_,'description,list("print logo for crack call"))$

poly_only:=nil$    put('poly_only,'description,list("all equations are polynomials only "))$

time_:=nil$        put('time_,'description,list("print the time needed between top level commands"))$

print_:=12$        put('print_,'description,list("maximal length of an expression to be printed"))$

%dec_hist:=0$      put('dec_hist,'description,list("length of pde history list during decoupling"))$

maxalgsys_:=20$    put('maxalgsys_,'description,list("max. number of equations to be solved in specialsol"))$

adjust_fnc:=nil$   put('adjust_fnc,'description,list("if t then free constants/functions are scaled and redundant ones are droped to simplify the result"))$

%orderings_:=nil$  put('orderings_,'description,list("Stores the orderings list, nil initially"))$

%simple_orderings:=t$ put('simple_orderings,'description,list("Turn off orderings support except for trivial case in crorder.red"))$

lex_df:=nil$	   put('lex_df,'description,list("if t then use lex. instead of tot. degree ordering of derivatives"))$

lex_fc:=t$	   put('lex_fc,'description,list("if t then lex. ordering of functions has higher priority than any ordering of derivatives, even if lex_fc=nil then still algebraic powers have no influence, i.e. for algebraic problems both are lexicographical ordering"))$

collect_sol:=t$    put('collect_sol,'description,list("whether solutions found shall be collected and returned together at the end or not (to save memory)"))$

struc_eqn:=nil$    put('struc_eqn,'description,list("whether the equations has the form of structural eqn."))$

quick_decoup:=nil$ put('quick_decoup,'description,list("whether decoupling should be done faster with less care for saving memory"))$

idnties_:=nil$     put('idnties_,'description,list("list of identities resulting from reductions and integrability conditions"))$

record_hist:=nil$  put('record_hist,'description,list("whether the history of equations is to be recorded. This slows down large problems because of the prefix form of the history expressions which can become large too if coefficients are large."))$

keep_parti:=nil$   put('keep_parti,'description,list("whether for each equation a copy in partitioned form is to be stored to speed up several simplifications"))$

size_watch:=nil$   put('size_watch,'description,list("whether before each computational step the size of the system shall be recorded in size_hist
=nil: not, --> plot_stat() and print_tree() are not applicable. In history_ the start and end of cases are not stored as comments.
=#: then only the last # lines are stored --> warning this affects plot_stat(), print_tree() and possibly the procedures choose_...(). In history_ the start and end of cases are not stored as comments.
=t: yes --> warning: size_hist can grow large with 10,000's of lines"))$

inter_divint:=nil$ put('inter_divint,'description,list("whether the integration of divergence identities with more than 2 differentiation variables shall be confirmed interactively"))$

do_recycle_eqn:=t$ put('do_recycle_eqn,'description,list("whether equation names shall be recycled or not (saves memory but is less clear when determining histry_ in terms of original equations) recycle_eqns is a pair of 2 lists: (ready to use eqn. names) . (free eqn. names which still may occur in prob_list)"))$

do_recycle_fnc:=nil$ put('do_recycle_fnc,'description,list("whether function names shall be recycled or not (saves memory but is less clear to follow) for nonlinear problems with different solution branches and free/unsolved functions of different numbers of arguments it must be nil as otherwise clash of same function names of different indep. var."))$

old_history:=nil$  put('old_history,'description,list("old_history is interactive input to be read from this list"))$

confirm_subst:=nil$put('confirm_subst,'description,list("whether substitutions and the order of subcase investigations has to be confirmed"))$

mem_eff:=t$        put('mem_eff,'description,list("whether to be memory efficient even if slower"))$

force_sep:=nil$    put('force_sep,'description,list("whether direct separation should be forced even if functions occur in the supposed to be linear independent explicit expressions (for non-lin. prob.)"))$

flin_:=nil$        put('flin_,'description,list("a list of functions occuring only linearly in an otherwise non-linear problem. This matters in a factorization when factors with functions of flin_
 are considered last."))$

last_steps:=nil$   put('last_steps,'description,list("a list of the last steps to avoid cycles"))$

if null lin_test_const then lin_test_const:=gensym()$ put('lin_test_cons,'description,list("a global fixed constant to check linearity"))$

lin_problem:=nil$  put('lin_problem,'description,list("whether the full problem is linear or not"))$

time_limit:=nil$   put('time_limit,'description,list("whether a time limit limit_time is set after
		   which batch-mode is interrupted to interactive mode"))$

limit_time:=0$     put('limit_time,'description,list("= time()+how-much-more-time-allowed-in-batch-mode"))$

groebresmax:=2000$ put('groebresmax,'description,list("parameter for the REDUCE Groebner Basis proram"))$

!#if (memq 'psl lispsystem!*)
pvm_activate()$    % initializes pvm_able in crpvm.red
!#endif

!*iconic:=nil$     put('!*iconic,'description,list("whether new processes in parallelization should appear as icons"))$

done_trafo:={'list}$   put('done_trafo,'description,list("a list of backtransformations of done transformations"))$

inverse_trafo_list_incomplete:=nil$  put('inverse_trafo_list_incomplete,'description,list(""))$

groeb_solve:='reduce$  put('groeb_solve,'description,list("which Groebner package to use and how, options:
 'SL_LEX  for Singular in mode 'lex
 'SL_GRAD for Singular in mode 'gradlex
 'SL_REVGRAD for Singular in mode 'revgradlex
 'GB_LEX  for Faugere's GB in mode 'lex
 'GB_REVGRAD for Faugere's GB in mode 'revgradlex
 'REDUCE  for the REDUCE package groebnerf"))$

last_free_cells:=if boundp 'gcfree!* then gcfree!* 
                                     else known!-free!-space()$
put('last_free_cells,'description,list("free cells after last garbage collections"))$

choose_6_20_max_ftem:=20$   put('choose_6_20_max_ftem,'description,list("parameter in choose_6_20 when to switch between 6 and 20"))$

choose_6_20_max_terms:=4000$put('choose_6_20_max_terms,'description,list("parameter in choose_6_20 when to switch between 6 and 20"))$

choose_27_8_16_max:=15$     put('choose_27_8_16_max,'description,list("parameter in choose_27_8_16 when to switch between 27 and 8 and 16"))$

choose_30_47_21_max:=10$    put('choose_30_47_21_max,'description,list("parameter in choose_30_47_21 when to switch between 30 and 47 and 21"))$

choose_70_65_8_47_origterms:=1000000000$    put('choose_70_65_8_47_origterms,'description,list("parameter in choose_70_65_8_47_origterms: the original number of terms"))$

choose_70_65_8_47_origmem:=last_free_cells$ put('choose_70_65_8_47_origmem,'description,list("parameter in choose_70_65_8_47: the original free cells"))$

choose_70_65_8_47_ratioterms:=200$ put('choose_70_65_8_47_ratioterms,'description,list("parameter in choose_70_65_8_47: percentage of increase of terms when to split into cases"))$

choose_70_65_8_47_ratiomem:=50$   put('choose_70_65_8_47_ratiomem,'description,list("parameter in choose_70_65_8_47: percentage of left free mem when to split"))$

choose_30_47_72_eqn:=50$    put('choose_30_47_72_eqn,'description,list("parameter in choose_30_47_72: no of eqn when decoupling and factorizing become more important than reading more equations"))$

choose_11_30_max_11:=10$    put('choose_11_30_max_11,'description,list("parameter in choose_11_30: max no of steps 11 before 72 (read in equation)"))$

choose_11_30_max_30:=3$     put('choose_11_30_max_30,'description,list("parameter in choose_11_30: max no of steps 30 before 72 (read in equation)"))$

put('choose_70_65_8_47_ratiomem,'description,list("parameter in choose_70_65_8_47"))$

groeb_diff_max:=15$         put('groeb_diff_max,'description,list("a measure of the difficulty of a system such that it is worth to try a groebner package"))$

alg_poly:=nil$       put('alg_poly,'description,list("=t if the system is algebraic and polynomial"))$

case_list:={'list}$  put('case_list,'description,list("an algebraic list of expressions which should be considered =0/<>0 in this order"))$

equations_file:=""$  put('equations_file,'description,list("name of the file from which equations are read and added"))$

eqn_input:=nil$      put('eqn_input,'description,list("global pointer remembering whether the file is still closed (=nil), open (<>nil and <>'done) or already fully read (='done)"))$

eqn_to_be_gen:=nil$  put('eqn_to_be_gen,'description,list("=t initially if equations are generated and later set =nil when no more generations can be generated"))$

eqn_no:=0$           put('eqn_no,'description,list("the number of equations already read in from file"))$

crack_ini_file:=nil$ put('crack_ini_file,'description,list("the name of the compiled initialization file without the suffix .b;  it is a string, like "" /scratch/.."" and is loaded into remote processes in crpvm.red"))$

ud_1:=nil$ put('ud_1,'description,list("automatically backed up parameters to be used in user_defined()"))$
ud_2:=nil$ put('ud_2,'description,list("automatically backed up parameters to be used in user_defined()"))$
ud_3:=nil$ put('ud_3,'description,list("automatically backed up parameters to be used in user_defined()"))$
ud_4:=nil$ put('ud_4,'description,list("automatically backed up parameters to be used in user_defined()"))$

crack_load_command:=nil$ put('crack_load_command,'description,list("determined through a call to crack_load_cmd(), needed for calling external procedures DiffElim, Form and in parallel computations to load automatically exactly the same CRACK as in the initial load. This can not be computed at the time of loading CRACK because the information is taken from the global variable options!* which is updated only at the end of each loading.
"))$

crack_download_add:="http://lie.math.brocku.ca/twolf/crack/"$
                         put('crack_download_add,'description,list("The web address for downloading the latest version of CRACK"))$

auto_para_mode:=nil$  put('auto_para_mode,'description,list("determines whether and how to add automatically extra interactive parallel processes:  
=nil: automatic parallel case solution either not specified yet, or not possible
=1: as xterm, =2: as screen, =3: as sqsub job, =4: PVM "))$

process_counter:="no_of_processes"$  put('process_counter,'description,list("name of file that holds the number of processes in a parallel computation, its content is initialized together with auto_para_mode in crmain.red and updated in proczaehler() in crpvm.red"))$

max_proc_no:=5$       put('max_proc_no,'description,list("maximum number of parallel processes"))$

batch_mode_sub:=t$    put('batch_mode_sub,'description,list("whether sub-calls of crack() should have batch_mode=t or nil. Such calls occur in find_trafo()/crtrafo.red, in dropredund(0)/crsimpso.red and solution_check1"))$

max_term_to_fac_complex:=8$  put('max_term_to_fac_complex,'description,list("maximal number of terms to be factorized properly and automatically in updatesq() and simplifySQ()"))$

max_term_to_fac_real:=100$  put('max_term_to_fac_real,'description,list("maximal number of terms to be factorized properly and automatically in updatesq() and simplifySQ()"))$

max_term_to_pred:=10$ put('max_term_to_pred,'description,list("maximal number of terms to be a parameter to preduce()"))$

form_comp:=nil$       put('form_comp,'description,list("whether the S-polynomial shall be computed by FORM in crdec.red and substitutions done by FORM could be initialized automatically if system ""which form""; finds the file, e.g. under: /usr/local/bin/form"))$

form_pipe:=nil$       put('form_pipe,'description,list("whether the communication REDUCE --> FORM should go through a pipe. If nil then a file interface is used. If it goes through a pipe then FORM is started through 
./form_start < formin > formout &
at the start of the sq!*crack() procedure in crmain.red"))$

form_eqn_idx:=0$      put('form_eqn_idx,'description,list("the index of the last equation generated by form"))$

form_eqn_on_disk:=nil$put('form_eqn_on_disk,'description,list("a list {{# of terms, file name},...} of equations that have been computed by form"))$

form_max_read:=10000$ put('form_max_read,'description,list("the maximal number of terms of an expression computed by FORM that shall be read into REDUCE"))$

form_tmp_dir:="/tmp/"$put('form_tmp_dir,'description,list("the directory in which FORM shall open temporary files = ""/tmp/"" on sharcnet"))$

largest_fully_shortened:=nil$ put('largest_fully_shortened,'description,list("The latest equation in the list pdes of equations (when starting to count from the first) that is fully shortened wrt to all earlier equations on this list"))$

max_coeff_len:=100000000000000000$ put('max_coeff_len,'description,list("the max length of coefficients for shortening to be considered in crshort.red"))$

call_crack_out:=t$    put('call_crack_out,'description,list("If in a user defined procedure crack_out a call of crack is made then set call_crack_out:=nil to avoid a loop"))$

switch_list:=nil$     put('switch_list,'description,list("a list of switches changed, i.e. a list of lists {level_ when change was made, name of switch, value before change}"))$

para_case_dir:=""$    put('para_case_dir,'description,list("the directory in which the initialization files for all cases of a parallel computation shall be stored, this should be long enough until all cases are solved, if necessary in later runs, """" = current directory, =""/scratch/twolf/""$  on SharcNet"))$

!*notseparate:=t$     put('!*notseparate,'description,list("This is a REDUCE flag which now prevents the simplification of x**(5/4) to x**(1/4)*x. Preventing this simplification is necessary for simplifications of, for example, (x**(5/4))**(4/5) to abs(x) {or x if let rule abs_ is active}. The disadvantage of !*notseparate:=t is that factorize (a*x**(5/4)+b*x); would not get x as a factor, but on combineexpt; does get the factorization right."))$

algebraic(off combineexpt)$ % put(','description,list(""))$
   %  see the above !*notseparate:=t$ assignment
   %  (on combineexpt is a minefield and, for example, even in the
   %  sourceforge version of 7 Nov 2011 givs 0 as the product of two
   %  non-zero expressions due to an error in GCD based on a wrong
   %  simplification in aeval when !*mcd is temporarily set to nil.)
   %  WARNING:  off combineexpt  has the effect that
   %  a:=( - 4*f1 + 4*f2 + 2*(f1 - f2))/(f1 - f2);
   %  is not simplified. (as of 28.4.2012)
   %
   %  The problem with ON COMBINEEXPT may be overcome with ON EZGCD
   %  as it is GCD related. An example where ON COMBINEEXPT fails is
   %  stored in the file ONCOMBINEEXPT-BUG

currently_to_be_substituted_in:=nil$ put('currently_to_be_substituted_in,'description,list("The latest/largest equation in the list pdes of equations (when starting to count from the shortest) in which all possible substitutions of shorter equations have been done that do not lead to case distinctions (this variable was previously not in the list pass_on.)"))$

put('sol_list,'description,list("list of file names each containing a solution"))$

reduce_call:=nil$     put('reduce_call,'description,list("The call of the current REDUCE session. In PSL-REDUCE this is stored in unixargs!* but not in CSL-REDUCE. It is needed to start parallel sessions."))$

singular_call:=nil$   put('singular_call,'description,list("The call of Singular including the pathname, determined in crgb.red, possible default value: ""Singular""$ "))$

singular_lib:=nil$    put('singular_lib,'description,list("the directory name of the Singular library, determined in crgb.red, possible default value: """"$ "))$

singular_time:=20$    put('singular_time,'description,list("CPU time limit for a Singular call"))$

diffelim_steps:=10000$ put('diffelim_steps,'description,list("number of steps to be done in DiffElim"))$

lazy_eval:=t$         put('lazy_eval,'description,list("In large non-linear calculations with many variables and many sub-cases which mostly have no solution a lot of time is wasted by substitutions being performed in forg when the case afterall has no solution. If lazy_eval=t then these substitutions are collected in fsub_ until a solution has been found and then they are performed. fsub_ has the form {(f . {'!*SQ,SQ,t})[,..]} Before a call of dropredundant() substitutions should have been made for dropredundant() to be efficient."))$

keep_case_tree:=t$    put('keep_case_tree,'description,list("whether the procedure CaseTree in crutil.red shall maintain a file ct??????- which stores and updates the tree of cases for re-starts."))$

min_nu_of_eqn:=nil$   put('min_nu_of_eqn,'description,list("in decoupling: if t then prefer to start a case distinction rather than to add additional equations"))$

%--------- Adding descriptions of methods 

put('to_do,'description,
    list("Hot list of urgent steps"))$
put('subst_level_0,'description,
    list("Substitution of max ",if subst_0 then subst_0 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "     only fcts. of less vars., no cases"))$
put('subst_level_03,'description,
    list("Substitution of max ",if subst_0 then subst_0 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "     alg. expressions, no cases"))$
put('subst_level_04,'description,
    list("Substitution of max ",if subst_1 then subst_1 else "any number of"," terms in ",
         if target_limit_1 then target_limit_1 else "any number of"," terms,",
         "     alg. expressions, no cases"))$
put('subst_level_05,'description,
    list("Substitution of max ",if subst_3 then subst_3 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "     alg. expressions, no cases"))$
put('subst_level_1,'description,
    list("Substitution of max ",if subst_1 then subst_1 else "any number of"," terms in ",
         if target_limit_2 then target_limit_2 else "any number of"," terms,",
         "     fcts. of less vars."))$
put('subst_level_2,'description,
    list("Substitution of max ",if subst_3 then subst_3 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "     fcts. of less vars., no cases"))$
put('subst_level_3,'description,
    list("Substitution of max ",if subst_2 then subst_2 else "any number of"," terms in ",
         if target_limit_1 then target_limit_1 else "any number of"," terms"))$
put('subst_level_33,'description,
    list("Substitution of max ",if subst_3 then subst_3 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "     only linear expressions, f-indep. coeff."))$
put('subst_level_35,'description,
    list("Substitution of max ",if subst_3 then subst_3 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "     no cases"))$
put('subst_level_4,'description,
    list("Substitution of max ",if subst_3 then subst_3 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms"))$
put('subst_level_45,'description,
    list("Substitution of max ",if subst_3 then subst_3 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "     no cases, minimal growth",
         if cost_limit5 then ", with max ",
         if cost_limit5 then cost_limit5,
         if cost_limit5 then " add. terms"))$
put('subst_level_5,'description,
    list("Substitution of max ",if subst_3 then subst_3 else "any number of"," terms in ",
         if target_limit_3 then target_limit_3 else "any number of"," terms,",
         "    minimal growth"))$
put('subst_derivative,'description,
    list("Substitution of derivatives by new functions"))$
put('undo_subst_derivative,'description,
    list("Undo Substitutions of derivatives by new functions"))$
put('factorize_to_substitute,'description,
    list("Factorization to subcases leading to substitutions"))$
put('factorize_any,'description,
    list("Any factorization"))$
put('separation,'description,
    list("Direct separation"))$
put('quick_integration,'description,
    list("Integration of a first order de with at",
         " most one term."))$
put('full_integration,'description,
    list("Integration of a pde such that",
         " a function can be subst."))$
put('integration,'description,
    list("Any integration"))$
put('multintfac,'description,
    list("Find an integrating factor for a set of pde's"))$
put('diff_length_reduction,'description,
    list("Length reducing decoupling steps"))$
put('decoupling,'description,
    list("Do one decoupling step"))$
put('quick_gen_separation,'description,
    list("Indirect separation of <",low_gensep," or >",
         high_gensep," terms"))$
put('gen_separation,'description,
    list("Indirect separation of equations of any size"))$
put('gen_separation2,'description,
    list("Alternative indirect separation of non-lin equations"))$
put('add_differentiated_pdes,'description,
    list("Differentiate pdes with nonlinear leading derivs"))$
put('alg_length_reduction,'description,
    list("Algebraic length reduction of equations"))$
put('alg_solve_single,'description,
    list("Solving an algebraic equation"))$
put('alg_solve_system,'description,
    list("Solving equations for fnct.s or deriv.s algebraically"))$
put('stop_batch,'description,
    list("Stop batch mode"))$
put('undetlinode,'description,
    list("The parametric solution of underdetermined ODE"))$
put('undetlinpde,'description,
    list("The parametric solution of underdetermined PDE"))$
put('change_proc_list,'description,
    list("Changing the list of priorities"))$
put('drop_lin_dep,'description,
    list("Find and drop linear dependent general equations"))$ 
put('drop_dep_bi_lin,'description,
    list("Find and drop linear dependent bi-linear equations"))$ 
put('find_factor_bi_lin,'description,
    list("Find factorizable bi-linear equations"))$ 
put('find_1_term_eqn,'description,
    list("Find a linear dependent equation with only 1 term"))$ 
put('trian_lin_alg,'description,
    list("Triangularize a linear algebraic system"))$ 
%put('general_trafo,'description,
%    list("An interactive general transformation"))$
put('del_redundant_fc,'description,
    list("Drop redundant functions and constants"))$
put('sub_problem,'description,
    list("Solve a subset of equations first"))$
put('del_redundant_de,'description,
    list("Delete redundant equations"))$
put('idty_integration,'description,
    list("Integrate an identity"))$
put('add_diff_ise,'description,
    list("Differentiate indirectly separable equations"))$
put('split_into_cases,'description,
    list("Consider a given expression to be zero and non-zero"))$
put('first_int_for_ode,'description,
    list("Find symmetries and then first integrals for an ODE"))$
put('find_and_use_sub_systems12,'description,
    list("Find sub-systems with 2 non-flin_ functions"))$
put('find_and_use_sub_systems13,'description,
    list("Find sub-systems with 3 non-flin_ functions"))$
put('find_and_use_sub_systems14,'description,
    list("Find sub-systems with 4 non-flin_ functions"))$
put('find_and_use_sub_systems15,'description,
    list("Find sub-systems with 5 non-flin_ functions"))$
put('find_and_use_sub_systems22,'description,
    list("Find sub-systems with 2 flin_ functions"))$
put('find_and_use_sub_systems23,'description,
    list("Find sub-systems with 3 flin_ functions"))$
put('find_and_use_sub_systems24,'description,
    list("Find sub-systems with 4 flin_ functions"))$
put('find_and_use_sub_systems25,'description,
    list("Find sub-systems with 5 flin_ functions"))$
put('high_prio_decoupling,'description,
    list("Do one high priority decoupling step"))$
put('user_define,'description,
    list("Perform a user defined operation"))$
put('external_groebner,'description,
    list("Computation of the algebraic Groebner basis"))$
put('solution_check1,'description,
    list("Check whether a given solution is contained"))$
put('find_trafo,'description,
    list("Find a transformation to integrate a 1st order PDE"))$
put('choose_6_20,'description,
    list("Reorder modules 6 and 20"))$
put('choose_27_8_16,'description,
    list("Reorder modules 27, 8 and 16"))$
put('choose_30_47_21,'description,
    list("Reorder modules 30, 47 and 21"))$
put('case_on_most_frequ_fnc,'description,
    list("Split into cases whether most frequ. function vanishes"))$
put('back_up,'description,list("Save backup"))$
put('alg_length_reduce_1,'description,
    list("Algebraic length reduction of a single equation"))$
put('check_ineq,'description,
    list("Checking whether inequalities are contradicted"))$
put('case_separation,'description,
    list("Separation that may lead to case distinctions"))$
put('pre_determined_case_splits,'description,
    list("Doing a pre-determined case splitting"))$
put('choose_70_65_8_47,'description,
    list("Inserting a case-splitting if system too big"))$
put('solution_check2,'description,
    list("Check whether a given solution contradicts inequalities"))$
put('read_equation,'description,
    list("Read an additional equation from a file"))$
put('choose_30_47_72,'description,
    list("Reading new equation if not too many"))$
put('case_on_most_frequ_factors,'description,
    list("Split into cases whether most frequ. factor vanishes"))$
put('choose_11_30,'description,list("Limited shortenings"))$
put('try_other_ordering,'description,list("Try other ordering"))$
put('find_factorization,'description,
    list("Perform a thorough factorization"))$
put('para_solve_hom_equ,'description,
    list("Solve a homogeneous alg. equation in two variables"))$
put('undetalg,'description,list("Solve nested polynomial"))$
put('subst_power,'description,list("Replace powers by new unknowns"))$
put('bottom_up_subst,'description,list("Do a single substitution"))$
put('solution_check3,'description,
    list("Fast check of a special solution based on substitutions"))$
put('sublinfct,'description,
    list("Absorb non-linear factors in linear unknowns"))$
put('case_gen_separation,'description,
    list("Normal generalized separation that may lead to case distinctions"))$
 % Check the installation of FORM
 % If later on : if form_comp and form_pipe then ./form_start
 % must start FORM.
 % In any case, form is called by
 %    setq(ss,bldmsg("form -q %w",formputfile));  system ss;
 % Relevant files: ./form_start
 % Check for 32-64 bit system
 % if and(member('csl,lispsystem!*), member('sixty!-four,lispsystem!*)) or
 %    and(member('psl,lispsystem!*), betap lshift(1,20)) then 64 else 32$

 ini_let_rules()

>>$ % end of setcrackflags

algebraic procedure ini_let_rules$
begin 

  lisp(userrules_:={'list})$    % LET rules defined by the user

  explog_:= {
   cot(~x) => 1/tan(x),
%  e**(~x+~y) => e**x*e**y,
%  sqrt(e)**(~x+~y) => sqrt(e)**x*sqrt(e)**y,
%  e**((~x+~y)/~z) => e**(x/z)*e**(y/z),
%  sqrt(e)**((~x+~y)/~z) => sqrt(e)**(x/z)*sqrt(e)**(y/z),

   e**~x*e**~y =>  e**(x+y),
   sqrt(e)**~x*sqrt(e)**~y => sqrt(e)**(x+y),
   e**(~x/~z)*e**(~y/~z) => e**((x+y)/z),
   sqrt(e)**(~x/~z)*sqrt(e)**(~y/~z) => sqrt(e)**((x+y)/z),

   sqrt(e)**(log(~y)/~x) => y**(1/x/2),
   sqrt(e)**(-log(~y)/~x) => y**(-1/x/2),
   sqrt(e)**(~x*log(~y)/~z) => y**(x/z/2),
   sqrt(e)**(-~x*log(~y)/~z) => y**(-x/z/2),
   sqrt(e)**((~x*log(~y))/~z) => y**(x/z/2),
   e**(log(~y)/~x) => y**(1/x),
   e**(~x*log(~y)/~z) => y**(x/z),
   e**((~x*log(~y))/~z) => y**(x/z),
   int(df(~y,~x)/~y,~x) => log(y) 
  } $

  abs_  :={abs(~x)     => x}$

  trig1_:={sin(~x)**2  => 1-cos(x)**2}$
% trig1_:={cos(~x)**2  => 1-sin(x)**2}$
  trig2_:={cosh(~x)**2 => (sinh(x)**2 + 1)}$
  trig3_:={tan(~x/2)   => (1-cos(x))/sin(x)}$
  trig4_:={cot(~x/2)   => (1+cos(x))/sin(x)}$
  trig5_:={cos(2*~x)   => 1-2*sin(x)**2}$
  trig6_:={sin(2*~x)   => 2*cos(x)*sin(x)}$
  trig7_:={sinh(2*~x)  => 2*sinh(x)*cosh(x)}$
  trig8_:={cosh(2*~x)  => 2*cosh(x)**2-1}$
  sqrt1_:={sqrt(~x*~y) => sqrt(x)*sqrt(y)}$
  sqrt2_:={sqrt(~x/~y) => sqrt(x)/sqrt(y)}$
end$

% The following procedures are PSL/CSL specific therefore the test:

!#if (memq 'psl lispsystem!*)
  symbolic procedure random_init()$
  <<external_time(datebuffer)$
    random_new_seed(wand(wgetv(datebuffer,0),65535))
  >>$
  if  flambdalinkp 'random_init then
	compile '(random_init )$
!#endif

!#if (memq 'csl lispsystem!*)
  symbolic procedure random_init()$
  random_new_seed(datestamp())$
!#endif

% symbolic procedure randomhack()$
%  wand(external_time datebuffer,255)$
% random_new_seed ( 100 * lisp randomhack() + 27)$

endmodule$

end$
