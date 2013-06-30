module crack$  

comment

This is the top level CRACK module. (It may require more than one run to
compile using Win32-PSL.)

Authors:

	Thomas Wolf
	Department of Mathematics
	Brock University, 
	500 Glenridge Avenue, St.Catharines, 
	Ontario, Canada L2S 3A1
	email: twolf@brocku.ca

        until 1997:

        Andreas Brand 
        Institut fuer Informatik 
        Friedrich Schiller Universitaet Jena  
        07740 Jena,  Germany 
        email: maa@hpux.rz.uni-jena.de

Abstract:
CRACK is a package for solving overdetermined systems of ordinary or
partial differential equations (ODEs, PDEs). Examples of programs 
using CRACK are LIEPDE (for determining point and higher order
symmetries), APPLYSYM (to compute symmetry and similarity variables
for given point symmetries (symmetry reduction)) and CONLAW (for 
determining first integrals for ODEs or conservation laws for PDEs).
For more details see the manual CRACK.TEX and the manuals of the
other packages$

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

!#if (null(getd 'setprop))
symbolic procedure setprop(U, L)$
   %% Store item L as the property list of U.
   %% FJW: Defined (but NOT flagged lose) in PSL only.
   %% FJW: A crude implementation for CSL.
   %% Note that in CSL flags are properties with value t.
   << for each p in plist U do remprop(U, car p)$
      for each p in L do put(U, car p, cdr p) >>$
!#endif

% The following smacro definitions MUST be in this header file!

!#if (null(getd 'flag1))
symbolic inline procedure flag1(U, V)$
   %% smacro is replaced by inline as new policy in sourceforge Reduce
   %% The identifier U is flagged V.
   %% FJW: Defined and flagged lose in PSL only.
   %% FJW: This implementation based on the PSL manual.
   flag({U}, V)$
!#endif

!#if (null(getd 'remflag1))
symbolic inline procedure remflag1(U, V)$
   %% smacro is replaced by inline as new policy in sourceforge Reduce
   %% Remove V from the property list of identifier U.
   %% FJW: Defined and flagged lose in PSL only.
   %% FJW: This implementation based on the PSL manual.
   remflag({U}, V)$
!#endif

if lisp(null(getd 'redfront_color) ) then
symbolic procedure redfront_color(a)$ a$

remprop('cursym!*,'vartype)$ % to avoid compiler message:
                             % *** global `cursym!*' cannot become fluid
remprop('nxtsym!*,'vartype)$ % to avoid compiler message:
                             % *** global `nxtsym!*' cannot become fluid
global '(!*iconic)$          % for crpvm.red

% global algebraic mode variabes (used as names of LET-rules):
% abs_,explog_,trig1_,trig2_,trig3_,trig4_,trig5_,trig6_,trig7_,trig8_

symbolic fluid '(!*allowdfint_bak !*dfprint_bak !*diffelimverbosity!*
!*exp_bak !*ezgcd_bak !*fullroots_bak !*gcd_bak !*mcd_bak
!*nopowers_bak !*ratarg_bak !*rational_bak !*batch_mode alg_poly
adjust_fnc allflags_ auto_para_mode batchcount_ backup_ batch_mode_sub
call_crack_out case_list choose_6_20_max_ftem choose_6_20_max_terms
choose_27_8_16_max choose_30_47_21_max choose_70_65_8_47_origmem
choose_70_65_8_47_origterms choose_70_65_8_47_ratiomem
choose_70_65_8_47_ratioterms choose_30_47_72_eqn choose_11_30_max_11
choose_11_30_max_30 collect_sol confirm_subst cont_ contradiction_
cost_limit5 crack_download_add crack_ini_file crack_load_command
currently_to_be_substituted_in default_proc_list_ diffelim_steps
do_recycle_eqn do_recycle_fnc done_trafo eqname_ eqn_input eqn_no
eqn_to_be_gen equations_file expert_mode explog_ facint_ fhom_ flin_
force_sep form_comp form_eqn_idx form_eqn_on_disk form_max_read
form_pipe form_tmp_dir fname_ fnew_ freeabs_ freeint_ fsub_ ftem_
full_proc_list_ gcfree!* genint_ global_list_integer
global_list_ninteger global_list_float groeb_diff_max groeb_solve
high_gensep history_ idname_ idnties_ independence_ ineq_ ineq_or
inter_divint keep_case_tree keep_parti inverse_trafo_list_incomplete
largest_fully_shortened last_free_cells last_steps lazy_eval
length_inc_alg length_inc_dec level_ lex_df lex_fc limit_time
lin_problem lin_test_const logoprint_ low_gensep max_coeff_len
max_eqn_to_conti max_gc_counter max_gc_elimin max_gc_fac max_gc_gb
max_gc_int max_gc_minsub max_gc_ode max_gc_red_len max_gc_short
max_gc_ss max_proc_no max_red_len maxalgsys_ max_term_to_fac_complex
max_term_to_fac_real max_term_to_pred mem_eff min_nu_of_eqn
my_gc_counter nequ_ new_gensep nfct_ nid_ odesolve_ old_history
one_argument_functions_ para_case_dir paracrack_initialized pass_back
pass_on poly_only potint_ print_ print_all print_more proc_list_
process_counter prop_list pvm_able quick_decoup record_hist
recycle_eqns recycle_fcts recycle_ids reduce_call reducefunctions_
reducerc_initialized repeat_mode safeint_ session_ singular_call
singular_lib singular_time size_hist size_watch sol_list solvealg_
stepcounter_  struc_eqn subst_0 subst_1 subst_2 subst_3
subst_4 switch_list target_limit_0 target_limit_1 target_limit_2
target_limit_3 time_ time_limit to_do_list tr_decouple tr_genint
tr_gensep tr_main tr_orderings tr_redlength tr_short trig1_ trig2_
trig3_ trig4_ trig5_ trig6_ trig7_ trig8_ ud_1 ud_2 ud_3 ud_4
userrules_ verify_end_of_parallel_run vl_)$

!#if (getd 'packages_to_load)  % Load support packages, but not when compiling:
     packages_to_load ezgcd,odesolve,factor,int,algint,matrix,groebner,gnuplot$
     if getd('pvm_mytid) then  % Load PVM support
     packages_to_load pvm,reducepvm$
!#else                         % for REDUCE 3.6
     apply1('load_package, '(ezgcd odesolve factor int algint matrix
                             groebner gnuplot))$
!#endif

!#if (memq 'psl lispsystem!*)
     load pipes$       % to detect the operating system for parallel runs
                       % See calls of pipe!-open() in crpvm.red and crutil.red.
                       % There is a function "pipe!-open" in CSL.
!#endif  

compiletime load_package dipoly$    %  for the procedure a2dip() in fixes.red

% for creating a new package to be submitted to sourceforge

create!-package('(
 crack         % this file
 crinit        % initialisation and help
 crmain        % main module
 crdec         % decouple module
 crsep         % separation module
 crgensep      % generalized separation module
 crint         % integration of pde's module
 crsimp        % simplification and substitution module
 crsimpso      % simplification of the results
 crequsol      % equivalence of solutions
 crutil        % procedures used in several modules
 crshort       % reductions in length
 crstruc       % special module for structural eqn.
 crunder       % param. solution of underdet. lin. DEs
 crlinalg      % simpl. and sol. of lin. alg. systems
 crsubsys      % identifying and solving subsystems
 crtrafo       % point transformations module
 crident       % working with identities
 crhomalg      % working with bilinear algebraic systems
 crpvm         % working parallel on PVM
 crgb          % an interface to GB (J.P.Faugere) & Singular
 crineq        % procedures dealing with inequalities
 crdiffelim    % interface to DiffElim (Allan Wittkopf)
 fixes2        % recent reduce patches
                 ), nil)$

endmodule$

% lisp (loadtime setcrackflags())$

end$
