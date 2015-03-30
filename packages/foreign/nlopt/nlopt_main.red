% The interface between Reduce and NLopt is in two parts.  This file is part 1.
% Part 2 is the file "rednlopt.c", which is used to make a C library
% "librednlopt.so" serving as "glue" between Reduce/CSL and the NLopt 
% library "libnlopt.so".

% Author: Kostas N. Oikonomou

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

module nlopt_main;

off lower;

% The next line is unsatisfactory (for much the reason it was in Redlog)
% because it can ONLY behave while the Reduce source tree is available, and so
% it will FAIL when Reduce has been distributed as a binary archive and
% installed on a fresh computer. Furthermore if native Windows is ever to
% be supported one would need a ".dll" suffix not ".so".
librednlopt_loc!* := lto_sconcat {rltools_trunk(),
   "packages/foreign/nlopt/librednlopt.so"};

if filep librednlopt_loc!* then
   librednlopt!* := open!-foreign!-library(librednlopt_loc!*)
else <<
   if filep lto_sconcat {rltools_trunk(), "packages/foreign/nlopt/Makefile"} then
   begin
      scalar w;
      w := lto_sconcat {rltools_trunk(), "packages/foreign/nlopt"};
      % One bad thing here is that lto_sconcat is coded so it fails if some of
      % the strings passed contain double-quote marks, and I would have liked to
      % use some here!
      w := lto_sconcat {"sh -c 'cd ", w, "; make'"};
      system w
   end;
   % The call to system() might have managed to create the library
   if filep librednlopt_loc!* then
      librednlopt!* := open!-foreign!-library(librednlopt_loc!*);
>>;
if not librednlopt!* then
   rederr {"Can't open the NLopt library ", librednlopt_loc!*};


% =================================================
% The NLopt algorithms, from nlopt.h in NLopt 2.4.2
% =================================================
% Naming conventions:
% 
%       NLOPT_{G/L}{D/N}_* = global/local derivative/no-derivative optimization
% 	*_RAND algorithms involve some randomization
% 	*_NOSCAL algorithms are *not* scaled to a unit hypercube
% 	         (i.e. they are sensitive to the units of x)
%

nlopt_algorithm_codes!* := {
   {'nlopt_gn_direct,0},
   {'nlopt_gn_direct_l,1},
   {'nlopt_gn_direct_l_rand,2},
   {'nlopt_gn_direct_noscal,3},
   {'nlopt_gn_direct_l_noscal,4},
   {'nlopt_gn_direct_l_rand_noscal,5},
   {'nlopt_gn_orig_direct,6},
   {'nlopt_gn_orig_direct_l,7},
   {'nlopt_gd_stogo,8},
   {'nlopt_gd_stogo_rand,9},
   {'nlopt_ld_lbfgs_nocedal,10},
   {'nlopt_ld_lbfgs,11},
   {'nlopt_ln_praxis,12},
   {'nlopt_ld_var1,13},
   {'nlopt_ld_var2,14},
   {'nlopt_ld_tnewton,15},
   {'nlopt_ld_tnewton_restart,16},
   {'nlopt_ld_tnewton_precond,17},
   {'nlopt_ld_tnewton_precond_restart,18},
   {'nlopt_gn_crs2_lm,19},
   {'nlopt_gn_mlsl,20},
   {'nlopt_gd_mlsl,21},
   {'nlopt_gn_mlsl_lds,22},
   {'nlopt_gd_mlsl_lds,23},
   {'nlopt_ld_mma,24},
   {'nlopt_ln_cobyla,25},
   {'nlopt_ln_newuoa,26},
   {'nlopt_ln_newuoa_bound,27},
   {'nlopt_ln_neldermead,28},
   {'nlopt_ln_sbplx,29},
   {'nlopt_ln_auglag,30},
   {'nlopt_ld_auglag,31},
   {'nlopt_ln_auglag_eq,32},
   {'nlopt_ld_auglag_eq,33},
   {'nlopt_ln_bobyqa,34},
   {'nlopt_gn_isres,35},
   {'nlopt_auglag,36},
   {'nlopt_auglag_eq,37},
   {'nlopt_g_mlsl,38},
   {'nlopt_g_mlsl_lds,39},
   {'nlopt_ld_slsqp,40},
   {'nlopt_ld_ccsaq,41},
   {'nlopt_gn_esch,42}
};

% An association list with the reverse association:
nlopt_algorithm_rev_codes!* := 
   for each p in nlopt_algorithm_codes!* collect reverse p;

%% Basics
nlopt_create!*  := find!-foreign!-function("NLOPT_create", librednlopt!*);
nlopt_set_local_optimizer!* := find!-foreign!-function("NLOPT_set_local_optimizer", librednlopt!*);
nlopt_destroy!* := find!-foreign!-function("NLOPT_destroy", librednlopt!*);
nlopt_get_algorithm!* :=  find!-foreign!-function("NLOPT_get_algorithm", librednlopt!*);
nlopt_algorithm_name!* := find!-foreign!-function("nlopt_algorithm_name", librednlopt!*);
nlopt_get_dimension!* := find!-foreign!-function("NLOPT_get_dimension", librednlopt!*);

%% Bounds
nlopt_set_lower_bounds!* := find!-foreign!-function("NLOPT_set_lower_bounds", librednlopt!*);
nlopt_set_upper_bounds!* := find!-foreign!-function("NLOPT_set_upper_bounds", librednlopt!*);
nlopt_get_lower_bound!*  := find!-foreign!-function("NLOPT_get_lower_bound", librednlopt!*);
nlopt_get_upper_bound!*  := find!-foreign!-function("NLOPT_get_upper_bound", librednlopt!*);

%% Stopping criteria
nlopt_set_xtol_rel!*     := find!-foreign!-function("NLOPT_set_xtol_rel", librednlopt!*);
nlopt_set_ftol_rel!*     := find!-foreign!-function("NLOPT_set_ftol_rel", librednlopt!*);
nlopt_set_maxeval!*      := find!-foreign!-function("NLOPT_set_maxeval", librednlopt!*);
nlopt_set_maxtime!*      := find!-foreign!-function("NLOPT_set_maxtime", librednlopt!*);
nlopt_set_stopval!*      := find!-foreign!-function("NLOPT_set_stopval", librednlopt!*);
nlopt_set_ftol_abs!*     := find!-foreign!-function("NLOPT_set_ftol_abs", librednlopt!*);
nlopt_get_xtol_rel!*     := find!-foreign!-function("NLOPT_get_xtol_rel", librednlopt!*);
nlopt_get_ftol_rel!*     := find!-foreign!-function("NLOPT_get_ftol_rel", librednlopt!*);
nlopt_get_maxeval!*      := find!-foreign!-function("NLOPT_get_maxeval", librednlopt!*);
nlopt_get_maxtime!*      := find!-foreign!-function("NLOPT_get_maxtime", librednlopt!*);
nlopt_get_ftol_abs!*     := find!-foreign!-function("NLOPT_get_ftol_abs", librednlopt!*);

%% Arrays of doubles
newdoublearray!*  := find!-foreign!-function("newDoubleArray", librednlopt!*);
setdoublearray!*  := find!-foreign!-function("setDoubleArray", librednlopt!*);
freedoublearray!* := find!-foreign!-function("freeDoubleArray", librednlopt!*);

%% Optimization.
% The interface gets very complicated here!!!  To understand why the following 3
% lines are here and not in rednlopt.c, see the comments on the function 
% "register_callback" in "C_call_CSL.h".
register_callback := find!-foreign!-function("register_callback", librednlopt!*); 
for i := 0:32 do 
   call!-foreign!-function(register_callback, 'int32, i, 'int64, get!-callback(i));

nlopt_set_min_objective!* := find!-foreign!-function("NLOPT_set_min_objective", librednlopt!*);
nlopt_set_max_objective!* := find!-foreign!-function("NLOPT_set_max_objective", librednlopt!*);
nlopt_optimize!* := find!-foreign!-function("NLOPT_optimize", librednlopt!*);
get_result!*     := find!-foreign!-function("get_result",  librednlopt!*);
free_result!*    := find!-foreign!-function("free_result", librednlopt!*);

%% Constraints
% scalar
nlopt_add_eq_constraint!*   := find!-foreign!-function("NLOPT_add_eq_constraint", librednlopt!*);
nlopt_add_ineq_constraint!* := find!-foreign!-function("NLOPT_add_ineq_constraint", librednlopt!*);
% m-valued
nlopt_add_eq_mconstraint!*   := find!-foreign!-function("NLOPT_add_eq_mconstraint", librednlopt!*);
nlopt_add_ineq_mconstraint!* := find!-foreign!-function("NLOPT_add_ineq_mconstraint", librednlopt!*);
% removal
nlopt_remove_eq_constraints!*  := find!-foreign!-function("NLOPT_remove_eq_constraints", librednlopt!*);
nlopt_remove_ineq_constraints!* := find!-foreign!-function("NLOPT_remove_ineq_constraints", librednlopt!*);


%% Step size for derivative-free algorithms
nlopt_set_initial_step!*  := find!-foreign!-function("NLOPT_set_initial_step", librednlopt!*);
nlopt_set_initial_step1!* := find!-foreign!-function("NLOPT_set_initial_step1", librednlopt!*);
%NLOPT_get_initial_step!*  := find!-foreign!-function("NLOPT_get_initial_step", librednlopt!*);


%% Stochastic search algorithms
nlopt_set_population!* := find!-foreign!-function("NLOPT_set_population", librednlopt!*);
nlopt_srand!* := find!-foreign!-function("NLOPT_srand", librednlopt!*);


% ==========================================
% Basics
% ==========================================

% See if an interface routine returns an error.
procedure ret_check(who,what);
   begin scalar err,mess;
      if what = 1 then return;  % "nlopt success"
      if what < 0 then <<
	 err := 
      	    if what = -1 then "nlopt failure!"
	    else if what = -2 then
 	       "invalid arguments or unsupported constraints! (perhaps for this algorithm)"
      	    else if what = -3 then "out of memory!"
	    else if what = -4 then "progress limited by roundoff"
	    else "forced stop";
 	 rederr {concat(who, ":"), err};
      >>
      else <<
	 % these are informative messages
	 mess := 
	    if what = 2 then "stop value reached" 
	    else if what = 3 then "f-tolerance reached"
	    else if what = 4 then "x-tolerance reached"
	    else if what = 5 then "max evaluations reached"
	    else "max time reached";
	 prin2t mess;
      >>;
   end;


procedure nlopt_algorithms();
   begin scalar n;
      n := length nlopt_algorithm_rev_codes!*;
      for i := 0:n-1 do <<
	 prin2 i;  prin2 ": ";  
	 prin2t second(assoc(i,nlopt_algorithm_rev_codes!*));
 	 prin2 "   [";  prin2 nlopt_algorithm_name(i);  prin2t "]";
      >>
   end;

procedure nlopt_get_algorithm();
   call!-foreign!-function(nlopt_get_algorithm!*, 'int32);

procedure nlopt_get_dimension();
   call!-foreign!-function(nlopt_get_dimension!*, 'int32);

procedure nlopt_create(alg, ndim);
   begin scalar alg_num;
      if alg_num := assoc(alg,nlopt_algorithm_codes!*) then <<
 	 alg_num := second(alg_num);
	 call!-foreign!-function(nlopt_create!*, 'int32,alg_num, 'int32,ndim);
      >>
      else
	 rederr {"Unknown algorithm", alg, "!"};
   end;

procedure nlopt_algorithm_name(code_or_num);
   begin scalar n;
      n := 
	 if numberp code_or_num then
	    code_or_num
      	 else
      	    second(assoc(code_or_num,nlopt_algorithm_rev_codes!*));
      return call!-foreign!-function(nlopt_algorithm_name!*, 'int32,n, 'string);
   end;

procedure nlopt_destroy();
   call!-foreign!-function(nlopt_destroy!*);

% ==========================================
% C arrays of doubles
% ==========================================

% These procedures are internal to the interface!
procedure newdoublearray(n);
   % the 'int64 represents the fact that the foreign function's result is a pointer
   call!-foreign!-function(newdoublearray!*, 'int32,n, 'int64);

procedure setdoublearray(a,i,x);
   call!-foreign!-function(setdoublearray!*, 'int64,a, 'int32,i, 'double,x);

procedure freedoublearray(a);
   call!-foreign!-function(freedoublearray!*, 'int64,a);


% ==========================================
% Setting and getting lower and upper bounds
% ==========================================

procedure nlopt_set_lower_bounds(bounds);
   % Because the Reduce/Lisp interface to C can handle passing values only of simple
   % types (int, double, string), we have to go through some contortions to pass the
   % values in a Reduce list to a C array: first create the array, and then pass each 
   % value one by one.  And the two 'foreign functions' that do this cannot be
   % combined into one.
   % The reverse process, getting an array from C and putting it into a Reduce list, 
   % is also somewhat contorted. See  C_darray_to_Lisp_list() in rednlopt.c.
   begin scalar savedmode, r, n, lb, clb;
      n := nlopt_get_dimension();
      if not listp(bounds) or length(bounds) neq n+1 then
	 rederr {"nlopt_set_lower_bounds: list of size", n, "expected!"};
      % rounded mode is necessary for the code in 'alg_intf.red' to work!
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      lb := alg_to_lisp_list(bounds);
      clb := newdoublearray(n);
      for i := 0:n-1 do
	 setdoublearray(clb, i, pop lb);
      % pointers are represented by 'int64
      r := call!-foreign!-function(nlopt_set_lower_bounds!*, 'int64,clb, 'int32);
      freedoublearray(clb);
      if savedmode then off rounded;
      ret_check("nlopt_set_lower_bounds", r);
   end;

procedure nlopt_set_upper_bounds(bounds);
   begin scalar savedmode, r, n, ub, cub;
      n := nlopt_get_dimension();
      if not listp(bounds) or length(bounds) neq n+1 then
   	 rederr {"nlopt_set_upper_bounds: list of size", n, "expected!"};
      % rounded mode is necessary for the code in 'alg_intf.red' to work!
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      ub := alg_to_lisp_list(bounds);
      cub := newdoublearray(n);
      for i := 0:n-1 do
	 setdoublearray(cub, i, pop ub);
      % pointers are represented by 'int64
      r := call!-foreign!-function(nlopt_set_upper_bounds!*, 'int64,cub, 'int32);
      freedoublearray(cub);
      if savedmode then off rounded;
      ret_check("nlopt_set_upper_bounds", r);
   end;

procedure nlopt_get_lower_bounds();
   % the problem dealt with here is that the C nlopt_get_lower_bounds returns an 
   % n-element array of doubles.
   begin scalar lb, n;
      n := nlopt_get_dimension();
      lb := for i := 0:n-1 collect
	 call!-foreign!-function(nlopt_get_lower_bound!*, 'int32,i, 'int32,n, 'double);
      % Turn r into a Reduce list. See Primer, sec. 3.3.1:
      return 'list . lb;
   end;

procedure nlopt_get_upper_bounds();
   % the problem dealt with here is that the C nlopt_get_upper_bounds returns an 
   % n-element array of doubles.
   begin scalar ub, n;
      n := nlopt_get_dimension();
      ub := for i := 0:n-1 collect
 	 call!-foreign!-function(nlopt_get_upper_bound!*, 'int32,i, 'int32,n, 'double);
      % Turn r into a Reduce list. See Primer, sec. 3.3.1:
      return 'list . ub;
   end;

% ==========================================
% Stopping criteria
% ==========================================

procedure nlopt_set_xtol_rel(tol);
   begin scalar savedmode, r;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;
      r := call!-foreign!-function(nlopt_set_xtol_rel!*, 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_xtol_rel", r);
   end;

procedure nlopt_set_ftol_rel(tol);
   begin scalar savedmode, r;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;
      r := call!-foreign!-function(nlopt_set_ftol_rel!*, 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_ftol_rel", r);
   end;

procedure nlopt_set_ftol_abs(tol);
   begin scalar savedmode, r;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;
      r := call!-foreign!-function(nlopt_set_ftol_abs!*, 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_ftol_abs", r);
   end;

procedure nlopt_set_maxeval(m);
   begin scalar r;
      r := call!-foreign!-function(nlopt_set_maxeval!*, 'int32,m, 'int32);
      ret_check("nlopt_set_maxeval", r);
   end;
procedure nlopt_set_maxtime(m);
   begin scalar r;
      r := call!-foreign!-function(nlopt_set_maxtime!*, 'double,m, 'int32);
      ret_check("nlopt_set_maxtime", r);
   end;

procedure nlopt_set_stopval(v);
 begin scalar savedmode, r;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      v := to_num v;
      call!-foreign!-function(nlopt_set_stopval!*, 'double,v, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_stopval", r);
   end;


procedure nlopt_get_xtol_rel();
   call!-foreign!-function(nlopt_get_xtol_rel!*, 'double);
procedure nlopt_get_ftol_rel();
   call!-foreign!-function(nlopt_get_ftol_rel!*, 'double);
procedure nlopt_get_ftol_abs();
   call!-foreign!-function(nlopt_get_ftol_abs!*, 'double);
procedure nlopt_get_maxeval();
   call!-foreign!-function(nlopt_get_maxeval!*, 'int32);
procedure nlopt_get_maxtime();
   call!-foreign!-function(nlopt_get_maxtime!*, 'double);

% ==========================================
% Optimization
% ==========================================

procedure nlopt_set_min_objective(fun);
   begin scalar r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      r := call!-foreign!-function(nlopt_set_min_objective!*, 'string,
	 symbol!-name fun, 'int32);  % symbol-name: id -> string name
      ret_check("nlopt_set_min_objective", r);
   end;

procedure nlopt_set_max_objective(fun);
   begin scalar r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      r := call!-foreign!-function(nlopt_set_max_objective!*, 'string, 
	 symbol!-name fun, 'int32);  % symbol-name: id -> string name
      ret_check("nlopt_set_max_objective", r);
   end;

procedure nlopt_optimize(x0);
   % the problem dealt with here is that the C nlopt_optimize() returns results via its two
   % arguments, which are pointers, the 1st to an array of doubles, the 2nd to a double.
   begin scalar savedmode, n, cx0, r, xval, fval;
      n := nlopt_get_dimension();
      if not listp(x0) or length(x0) neq n+1 then
	 rederr {"nlopt_optimize: list of size", n, "expected!"};
      % rounded mode is necessary for the code in 'alg_intf.red' to work!
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      x0 := alg_to_lisp_list(x0);
      cx0 := newdoublearray(n);
      for i := 0:n-1 do setdoublearray(cx0, i, pop x0);
      r := call!-foreign!-function(nlopt_optimize!*, 'int64,cx0, 'int32,n, 'int32);
      ret_check("nlopt_optimize", r);
      fval := call!-foreign!-function(get_result!*, 'int32,0, 'double);
      xval := for i := 1:n collect
	 call!-foreign!-function(get_result!*, 'int32,i, 'double);
      freedoublearray(cx0);
      call!-foreign!-function(free_result!*);
      if savedmode then off rounded;
      % Turn {fval,xval} into a Reduce list. See Primer, sec. 3.3.1:
      return 'list . {fval, 'list . xval};
   end;


% ==========================================
% Defining constraints
% ==========================================

% Scalar equality constraints should be expressed as h(x) = 0.
procedure nlopt_add_equality_constraint(fun,tol);
   begin scalar savedmode, r;
      if not getd(fun) then
      	 rederr {"function '", fun, "' is not defined!"};
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;  % tricky: see 'alg_intf.red'.
      r := call!-foreign!-function(nlopt_add_eq_constraint!*, 
	 'string, symbol!-name fun,  % symbol-name: id -> string
	 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_optimize", r);
   end;

% Scalar inequality constraints should be expressed as g(x) ≤ 0.
procedure nlopt_add_inequality_constraint(fun,tol);
   begin scalar savedmode, r;
      if not getd(fun) then
      	 rederr {"function '", fun, "' is not defined!"};
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;  % tricky: see 'alg_intf.red'.
      r := call!-foreign!-function(nlopt_add_ineq_constraint!*, 
	 'string, symbol!-name fun,  % symbol-name: id -> string
	 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_add_inequality_constraint", r);
   end;

% Now m-valued constraints, tol is an m-vector
procedure nlopt_add_equality_mconstraint(fun,m,tol);
   begin scalar savedmode, ctol, r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      if not listp(tol) or length(tol) neq m+1 then
	 rederr {"nlopt_add_equality_mconstraint: 3d argument should be a ", m, "-list!"};
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      % see 'alg_intf.red'.
      tol := alg_to_lisp_list(tol);
      ctol := newdoublearray(m);
      for i := 0:m-1 do
	 setdoublearray(ctol, i, pop tol);
      r := call!-foreign!-function(nlopt_add_eq_mconstraint!*,
	 'string, symbol!-name fun,  % symbol-name: id -> string
 	 'int32,m, 'int64,ctol, 'int32);
      freedoublearray(ctol);
      if savedmode then off rounded;
      ret_check("nlopt_add_equality_mconstraint", r);
   end;

procedure nlopt_add_inequality_mconstraint(fun,m,tol);
  begin scalar savedmode, ctol, r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      if not listp(tol) or length(tol) neq m+1 then
	 rederr {"nlopt_add_inequality_mconstraint: 3d argument should be a ", m, "-list!"};
     if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      % see 'alg_intf.red'.
      tol := alg_to_lisp_list(tol);
      ctol := newdoublearray(m);
      for i := 0:m-1 do
	 setdoublearray(ctol, i, pop tol);
      r := call!-foreign!-function(nlopt_add_ineq_mconstraint!*, 
	 'string, symbol!-name fun,  % symbol-name: id -> string
	 'int32,m, 'int64,ctol, 'int32);
      freedoublearray(ctol);
      if savedmode then off rounded;
      ret_check("nlopt_add_inequality_mconstraint", r);
   end;

procedure nlopt_remove_equality_constraints();
   begin scalar r;
      r := call!-foreign!-function(nlopt_remove_eq_constraints!*, 'int32);
      ret_check("nlopt_remove_equality_constraints", r);
   end;
procedure nlopt_remove_inequality_constraints();
   begin scalar r;
      r := call!-foreign!-function(nlopt_remove_ineq_constraints!*, 'int32);
      ret_check("nlopt_remove_inequality_constraints", r);
   end;


% ==============================================
% Step size for derivative-free algorithms
% ==============================================

procedure nlopt_set_initial_step(dx);
   begin scalar n, cdx, r;
      n := nlopt_get_dimension();
      if length(dx) neq n then
	 rederr {"nlopt_set_initial_step: list of size ", n, " expected!"};
      cdx := newdoublearray(n);
      dx := alg_to_lisp_list(dx);
      for i := 0:n-1 do setdoublearray(cdx, i, pop dx);
      r := call!-foreign!-function(nlopt_set_initial_step!*, 'int64,cdx, 'int32);
      freedoublearray(cdx);
      ret_check("nlopt_set_initial_step", r);
   end;

procedure nlopt_set_initial_step1(dx);
   begin scalar r;
      r := call!-foreign!-function(nlopt_set_initial_step1!*, 'double, to_num dx, 'int32);
      ret_check("nlopt_set_initial_step1", r);
   end;

% ================================================
% Stochastic search algorithms
% ================================================

procedure nlopt_set_population(p);
   begin scalar r;
      r := call!-foreign!-function(nlopt_set_population!*, 'int32,p, 'int32);
      ret_check("nlopt_set_population", r);
   end;

procedure nlopt_srand(s);
   call!-foreign!-function(nlopt_srand!*, 'int64,s);


% ====================================================
% Subsidiary (local) optimization algorithms
% ====================================================

procedure nlopt_set_local_optimizer(alg);
   call!-foreign!-function(nlopt_set_local_optimizer!*, 'int32, alg);


% =====================================================
% "Hidden constraints" for the DIRECT global algorithm
% =====================================================
% The algorithm requires that the objective function F(x)
% returns Inf at any x that violates the (arbitrary) constraints.

% In lisp mode, these procedures return 'inf' and 'minusinf' respectively.
% Check by 
%   float!-infinity!-p nlopt_inf();
%   float!-infinity!-p nlopt_minf();
procedure nlopt_inf();
   1e400;  % inf;

procedure nlopt_minf();
   -1e400; %  minusinf;



% =====================================================

symbolic operator 
   nlopt_get_algorithm, nlopt_algorithm_name, nlopt_get_dimension,
   nlopt_algorithms,
   nlopt_create, nlopt_set_local_optimizer, nlopt_destroy, 
   nlopt_set_lower_bounds, nlopt_set_upper_bounds,
   nlopt_set_xtol_rel,
   nlopt_set_ftol_rel, nlopt_set_ftol_abs,
   nlopt_set_maxeval, nlopt_set_maxtime,
   nlopt_get_lower_bounds, nlopt_get_upper_bounds,
   nlopt_get_xtol_rel,
   nlopt_get_ftol_rel, nlopt_get_ftol_abs,
   nlopt_get_maxeval, nlopt_get_maxtime,
   nlopt_set_stopval,
   nlopt_set_min_objective, nlopt_set_max_objective,
   nlopt_optimize,
   nlopt_add_equality_constraint, nlopt_add_equality_mconstraint,
   nlopt_add_inequality_constraint, nlopt_add_inequality_mconstraint,
   nlopt_remove_equality_constraints, nlopt_remove_inequality_constraints,
   nlopt_inf, nlopt_minf;

#endif

endmodule;  % nlopt

end;  % of file
