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
   {'NLOPT_GN_DIRECT,0},
   {'NLOPT_GN_DIRECT_L,1},
   {'NLOPT_GN_DIRECT_L_RAND,2},
   {'NLOPT_GN_DIRECT_NOSCAL,3},
   {'NLOPT_GN_DIRECT_L_NOSCAL,4},
   {'NLOPT_GN_DIRECT_L_RAND_NOSCAL,5},
   {'NLOPT_GN_ORIG_DIRECT,6},
   {'NLOPT_GN_ORIG_DIRECT_L,7},
   {'NLOPT_GD_STOGO,8},
   {'NLOPT_GD_STOGO_RAND,9},
   {'NLOPT_LD_LBFGS_NOCEDAL,10},
   {'NLOPT_LD_LBFGS,11},
   {'NLOPT_LN_PRAXIS,12},
   {'NLOPT_LD_VAR1,13},
   {'NLOPT_LD_VAR2,14},
   {'NLOPT_LD_TNEWTON,15},
   {'NLOPT_LD_TNEWTON_RESTART,16},
   {'NLOPT_LD_TNEWTON_PRECOND,17},
   {'NLOPT_LD_TNEWTON_PRECOND_RESTART,18},
   {'NLOPT_GN_CRS2_LM,19},
   {'NLOPT_GN_MLSL,20},
   {'NLOPT_GD_MLSL,21},
   {'NLOPT_GN_MLSL_LDS,22},
   {'NLOPT_GD_MLSL_LDS,23},
   {'NLOPT_LD_MMA,24},
   {'NLOPT_LN_COBYLA,25},
   {'NLOPT_LN_NEWUOA,26},
   {'NLOPT_LN_NEWUOA_BOUND,27},
   {'NLOPT_LN_NELDERMEAD,28},
   {'NLOPT_LN_SBPLX,29},
   {'NLOPT_LN_AUGLAG,30},
   {'NLOPT_LD_AUGLAG,31},
   {'NLOPT_LN_AUGLAG_EQ,32},
   {'NLOPT_LD_AUGLAG_EQ,33},
   {'NLOPT_LN_BOBYQA,34},
   {'NLOPT_GN_ISRES,35},
   {'NLOPT_AUGLAG,36},
   {'NLOPT_AUGLAG_EQ,37},
   {'NLOPT_G_MLSL,38},
   {'NLOPT_G_MLSL_LDS,39},
   {'NLOPT_LD_SLSQP,40},
   {'NLOPT_LD_CCSAQ,41},
   {'NLOPT_GN_ESCH,42}
};

% An association list with the reverse association:
nlopt_algorithm_rev_codes!* := 
   for each p in nlopt_algorithm_codes!* collect reverse p;

%% Basics
NLOPT_create!*  := find!-foreign!-function("NLOPT_create", librednlopt!*);
NLOPT_set_local_optimizer!* := find!-foreign!-function("NLOPT_set_local_optimizer", librednlopt!*);
NLOPT_destroy!* := find!-foreign!-function("NLOPT_destroy", librednlopt!*);
NLOPT_get_algorithm!* :=  find!-foreign!-function("NLOPT_get_algorithm", librednlopt!*);
nlopt_algorithm_name!* := find!-foreign!-function("nlopt_algorithm_name", librednlopt!*);
NLOPT_get_dimension!* := find!-foreign!-function("NLOPT_get_dimension", librednlopt!*);

%% Bounds
NLOPT_set_lower_bounds!* := find!-foreign!-function("NLOPT_set_lower_bounds", librednlopt!*);
NLOPT_set_upper_bounds!* := find!-foreign!-function("NLOPT_set_upper_bounds", librednlopt!*);
NLOPT_get_lower_bound!*  := find!-foreign!-function("NLOPT_get_lower_bound", librednlopt!*);
NLOPT_get_upper_bound!*  := find!-foreign!-function("NLOPT_get_upper_bound", librednlopt!*);

%% Stopping criteria
NLOPT_set_xtol_rel!*     := find!-foreign!-function("NLOPT_set_xtol_rel", librednlopt!*);
NLOPT_set_ftol_rel!*     := find!-foreign!-function("NLOPT_set_ftol_rel", librednlopt!*);
NLOPT_set_maxeval!*      := find!-foreign!-function("NLOPT_set_maxeval", librednlopt!*);
NLOPT_set_maxtime!*      := find!-foreign!-function("NLOPT_set_maxtime", librednlopt!*);
NLOPT_set_stopval!*      := find!-foreign!-function("NLOPT_set_stopval", librednlopt!*);
NLOPT_set_ftol_abs!*     := find!-foreign!-function("NLOPT_set_ftol_abs", librednlopt!*);
NLOPT_get_xtol_rel!*     := find!-foreign!-function("NLOPT_get_xtol_rel", librednlopt!*);
NLOPT_get_ftol_rel!*     := find!-foreign!-function("NLOPT_get_ftol_rel", librednlopt!*);
NLOPT_get_maxeval!*      := find!-foreign!-function("NLOPT_get_maxeval", librednlopt!*);
NLOPT_get_maxtime!*      := find!-foreign!-function("NLOPT_get_maxtime", librednlopt!*);
NLOPT_get_ftol_abs!*     := find!-foreign!-function("NLOPT_get_ftol_abs", librednlopt!*);

%% Arrays of doubles
newDoubleArray!*  := find!-foreign!-function("newDoubleArray", librednlopt!*);
setDoubleArray!*  := find!-foreign!-function("setDoubleArray", librednlopt!*);
freeDoubleArray!* := find!-foreign!-function("freeDoubleArray", librednlopt!*);

%% Optimization.
% The interface gets very complicated here!!!  To understand why the following 3
% lines are here and not in rednlopt.c, see the comments on the function 
% "register_callback" in "C_call_CSL.h".
register_callback := find!-foreign!-function("register_callback", librednlopt!*); 
for i := 0:32 do 
   call!-foreign!-function(register_callback, 'int32, i, 'int64, get!-callback(i));

NLOPT_set_min_objective!* := find!-foreign!-function("NLOPT_set_min_objective", librednlopt!*);
NLOPT_set_max_objective!* := find!-foreign!-function("NLOPT_set_max_objective", librednlopt!*);
NLOPT_optimize!* := find!-foreign!-function("NLOPT_optimize", librednlopt!*);
get_result!*     := find!-foreign!-function("get_result",  librednlopt!*);
free_result!*    := find!-foreign!-function("free_result", librednlopt!*);

%% Constraints
% scalar
NLOPT_add_eq_constraint!*   := find!-foreign!-function("NLOPT_add_eq_constraint", librednlopt!*);
NLOPT_add_ineq_constraint!* := find!-foreign!-function("NLOPT_add_ineq_constraint", librednlopt!*);
% m-valued
NLOPT_add_eq_mconstraint!*   := find!-foreign!-function("NLOPT_add_eq_mconstraint", librednlopt!*);
NLOPT_add_ineq_mconstraint!* := find!-foreign!-function("NLOPT_add_ineq_mconstraint", librednlopt!*);
% removal
NLOPT_remove_eq_constraints!*  := find!-foreign!-function("NLOPT_remove_eq_constraints", librednlopt!*);
NLOPT_remove_ineq_constraints!* := find!-foreign!-function("NLOPT_remove_ineq_constraints", librednlopt!*);


%% Step size for derivative-free algorithms
NLOPT_set_initial_step!*  := find!-foreign!-function("NLOPT_set_initial_step", librednlopt!*);
NLOPT_set_initial_step1!* := find!-foreign!-function("NLOPT_set_initial_step1", librednlopt!*);
%NLOPT_get_initial_step!*  := find!-foreign!-function("NLOPT_get_initial_step", librednlopt!*);


%% Stochastic search algorithms
NLOPT_set_population!* := find!-foreign!-function("NLOPT_set_population", librednlopt!*);
NLOPT_srand!* := find!-foreign!-function("NLOPT_srand", librednlopt!*);


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
   call!-foreign!-function(NLOPT_get_algorithm!*, 'int32);

procedure nlopt_get_dimension();
   call!-foreign!-function(NLOPT_get_dimension!*, 'int32);

procedure nlopt_create(alg, ndim);
   begin scalar alg_num;
      if alg_num := assoc(alg,nlopt_algorithm_codes!*) then <<
 	 alg_num := second(alg_num);
	 call!-foreign!-function(NLOPT_create!*, 'int32,alg_num, 'int32,ndim);
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
      % nlopt_algorithm_name is built-in to the NLopt library
   end;

procedure nlopt_destroy();
   call!-foreign!-function(NLOPT_destroy!*);

% ==========================================
% C arrays of doubles
% ==========================================

% These procedures are internal to the interface!
procedure newDoubleArray(n);
   % the 'int64 represents the fact that the foreign function's result is a pointer
   call!-foreign!-function(newDoubleArray!*, 'int32,n, 'int64);

procedure setDoubleArray(a,i,x);
   call!-foreign!-function(setDoubleArray!*, 'int64,a, 'int32,i, 'double,x);

procedure freeDoubleArray(a);
   call!-foreign!-function(freeDoubleArray!*, 'int64,a);


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
   begin scalar savedmode, r, n, lb, Clb;
      n := nlopt_get_dimension();
      if not listp(bounds) or length(bounds) neq n+1 then
	 rederr {"nlopt_set_lower_bounds: list of size", n, "expected!"};
      % rounded mode is necessary for the code in 'alg_intf.red' to work!
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      lb := alg_to_lisp_list(bounds);
      Clb := newDoubleArray(n);
      for i := 0:n-1 do
	 setDoubleArray(Clb, i, pop lb);
      % pointers are represented by 'int64
      r := call!-foreign!-function(NLOPT_set_lower_bounds!*, 'int64,Clb, 'int32);
      freeDoubleArray(Clb);
      if savedmode then off rounded;
      ret_check("nlopt_set_lower_bounds", r);
   end;

procedure nlopt_set_upper_bounds(bounds);
   begin scalar savedmode, r, n, ub, Cub;
      n := nlopt_get_dimension();
      if not listp(bounds) or length(bounds) neq n+1 then
   	 rederr {"nlopt_set_upper_bounds: list of size", n, "expected!"};
      % rounded mode is necessary for the code in 'alg_intf.red' to work!
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      ub := alg_to_lisp_list(bounds);
      Cub := newDoubleArray(n);
      for i := 0:n-1 do
	 setDoubleArray(Cub, i, pop ub);
      % pointers are represented by 'int64
      r := call!-foreign!-function(NLOPT_set_upper_bounds!*, 'int64,Cub, 'int32);
      freeDoubleArray(Cub);
      if savedmode then off rounded;
      ret_check("nlopt_set_upper_bounds", r);
   end;

procedure nlopt_get_lower_bounds();
   % the problem dealt with here is that the C nlopt_get_lower_bounds returns an 
   % n-element array of doubles.
   begin scalar lb, n;
      n := nlopt_get_dimension();
      lb := for i := 0:n-1 collect
	 call!-foreign!-function(NLOPT_get_lower_bound!*, 'int32,i, 'int32,n, 'double);
      % Turn r into a Reduce list. See Primer, sec. 3.3.1:
      return 'list . lb;
   end;

procedure nlopt_get_upper_bounds();
   % the problem dealt with here is that the C nlopt_get_upper_bounds returns an 
   % n-element array of doubles.
   begin scalar ub, n;
      n := nlopt_get_dimension();
      ub := for i := 0:n-1 collect
 	 call!-foreign!-function(NLOPT_get_upper_bound!*, 'int32,i, 'int32,n, 'double);
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
      r := call!-foreign!-function(NLOPT_set_xtol_rel!*, 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_xtol_rel", r);
   end;

procedure nlopt_set_ftol_rel(tol);
   begin scalar savedmode, r;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;
      r := call!-foreign!-function(NLOPT_set_ftol_rel!*, 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_ftol_rel", r);
   end;

procedure nlopt_set_ftol_abs(tol);
   begin scalar savedmode, r;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;
      r := call!-foreign!-function(NLOPT_set_ftol_abs!*, 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_ftol_abs", r);
   end;

procedure nlopt_set_maxeval(m);
   begin scalar r;
      r := call!-foreign!-function(NLOPT_set_maxeval!*, 'int32,m, 'int32);
      ret_check("nlopt_set_maxeval", r);
   end;
procedure nlopt_set_maxtime(m);
   begin scalar r;
      r := call!-foreign!-function(NLOPT_set_maxtime!*, 'double,m, 'int32);
      ret_check("nlopt_set_maxtime", r);
   end;

procedure nlopt_set_stopval(v);
 begin scalar savedmode, r;
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      v := to_num v;
      call!-foreign!-function(NLOPT_set_stopval!*, 'double,v, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_set_stopval", r);
   end;


procedure nlopt_get_xtol_rel();
   call!-foreign!-function(NLOPT_get_xtol_rel!*, 'double);
procedure nlopt_get_ftol_rel();
   call!-foreign!-function(NLOPT_get_ftol_rel!*, 'double);
procedure nlopt_get_ftol_abs();
   call!-foreign!-function(NLOPT_get_ftol_abs!*, 'double);
procedure nlopt_get_maxeval();
   call!-foreign!-function(NLOPT_get_maxeval!*, 'int32);
procedure nlopt_get_maxtime();
   call!-foreign!-function(NLOPT_get_maxtime!*, 'double);

% ==========================================
% Optimization
% ==========================================

procedure nlopt_set_min_objective(fun);
   begin scalar r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      r := call!-foreign!-function(NLOPT_set_min_objective!*, 'string,
	 symbol!-name fun, 'int32);  % symbol-name: id -> string name
      ret_check("nlopt_set_min_objective", r);
   end;

procedure nlopt_set_max_objective(fun);
   begin scalar r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      r := call!-foreign!-function(NLOPT_set_max_objective!*, 'string, 
	 symbol!-name fun, 'int32);  % symbol-name: id -> string name
      ret_check("nlopt_set_max_objective", r);
   end;

procedure nlopt_optimize(x0);
   % the problem dealt with here is that the C nlopt_optimize() returns results via its two
   % arguments, which are pointers, the 1st to an array of doubles, the 2nd to a double.
   begin scalar savedmode, n, Cx0, r, xval, fval;
      n := nlopt_get_dimension();
      if not listp(x0) or length(x0) neq n+1 then
	 rederr {"nlopt_optimize: list of size", n, "expected!"};
      % rounded mode is necessary for the code in 'alg_intf.red' to work!
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      x0 := alg_to_lisp_list(x0);
      Cx0 := newDoubleArray(n);
      for i := 0:n-1 do setDoubleArray(Cx0, i, pop x0);
      r := call!-foreign!-function(NLOPT_optimize!*, 'int64,Cx0, 'int32,n, 'int32);
      ret_check("nlopt_optimize", r);
      fval := call!-foreign!-function(get_result!*, 'int32,0, 'double);
      xval := for i := 1:n collect
	 call!-foreign!-function(get_result!*, 'int32,i, 'double);
      freeDoubleArray(Cx0);
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
      r := call!-foreign!-function(NLOPT_add_eq_constraint!*, 
	 'string, symbol!-name fun,  % symbol-name: id -> string
	 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_optimize", r);
   end;

% Scalar inequality constraints should be expressed as g(x) b	$ 0.
procedure nlopt_add_inequality_constraint(fun,tol);
   begin scalar savedmode, r;
      if not getd(fun) then
      	 rederr {"function '", fun, "' is not defined!"};
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      tol := to_num tol;  % tricky: see 'alg_intf.red'.
      r := call!-foreign!-function(NLOPT_add_ineq_constraint!*, 
	 'string, symbol!-name fun,  % symbol-name: id -> string
	 'double,tol, 'int32);
      if savedmode then off rounded;
      ret_check("nlopt_add_inequality_constraint", r);
   end;

% Now m-valued constraints, tol is an m-vector
procedure nlopt_add_equality_mconstraint(fun,m,tol);
   begin scalar savedmode, Ctol, r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      if not listp(tol) or length(tol) neq m+1 then
	 rederr {"nlopt_add_equality_mconstraint: 3d argument should be a ", m, "-list!"};
      if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      % see 'alg_intf.red'.
      tol := alg_to_lisp_list(tol);
      Ctol := newDoubleArray(m);
      for i := 0:m-1 do
	 setDoubleArray(Ctol, i, pop tol);
      r := call!-foreign!-function(NLOPT_add_eq_mconstraint!*,
	 'string, symbol!-name fun,  % symbol-name: id -> string
 	 'int32,m, 'int64,Ctol, 'int32);
      freeDoubleArray(Ctol);
      if savedmode then off rounded;
      ret_check("nlopt_add_equality_mconstraint", r);
   end;

procedure nlopt_add_inequality_mconstraint(fun,m,tol);
  begin scalar savedmode, Ctol, r;
      if not getd(fun) then
	 rederr {"function '", fun, "' is not defined!"};
      if not listp(tol) or length(tol) neq m+1 then
	 rederr {"nlopt_add_inequality_mconstraint: 3d argument should be a ", m, "-list!"};
     if not !*rounded then <<
      	 savedmode := t;  on rounded;
      >>;
      % see 'alg_intf.red'.
      tol := alg_to_lisp_list(tol);
      Ctol := newDoubleArray(m);
      for i := 0:m-1 do
	 setDoubleArray(Ctol, i, pop tol);
      r := call!-foreign!-function(NLOPT_add_ineq_mconstraint!*, 
	 'string, symbol!-name fun,  % symbol-name: id -> string
	 'int32,m, 'int64,Ctol, 'int32);
      freeDoubleArray(Ctol);
      if savedmode then off rounded;
      ret_check("nlopt_add_inequality_mconstraint", r);
   end;

procedure nlopt_remove_equality_constraints();
   begin scalar r;
      r := call!-foreign!-function(NLOPT_remove_eq_constraints!*, 'int32);
      ret_check("nlopt_remove_equality_constraints", r);
   end;
procedure nlopt_remove_inequality_constraints();
   begin scalar r;
      r := call!-foreign!-function(NLOPT_remove_ineq_constraints!*, 'int32);
      ret_check("nlopt_remove_inequality_constraints", r);
   end;


% ==============================================
% Step size for derivative-free algorithms
% ==============================================

procedure nlopt_set_initial_step(dx);
   begin scalar n, Cdx, r;
      n := nlopt_get_dimension();
      if length(dx) neq n then
	 rederr {"nlopt_set_initial_step: list of size ", n, " expected!"};
      Cdx := newDoubleArray(n);
      dx := alg_to_lisp_list(dx);
      for i := 0:n-1 do setDoubleArray(Cdx, i, pop dx);
      r := call!-foreign!-function(NLOPT_set_initial_step!*, 'int64,Cdx, 'int32);
      freeDoubleArray(Cdx);
      ret_check("nlopt_set_initial_step", r);
   end;

procedure nlopt_set_initial_step1(dx);
   begin scalar r;
      r := call!-foreign!-function(NLOPT_set_initial_step1!*, 'double, to_num dx, 'int32);
      ret_check("nlopt_set_initial_step1", r);
   end;

% ================================================
% Stochastic search algorithms
% ================================================

procedure nlopt_set_population(p);
   begin scalar r;
      r := call!-foreign!-function(NLOPT_set_population!*, 'int32,p, 'int32);
      ret_check("nlopt_set_population", r);
   end;

procedure nlopt_srand(s);
   call!-foreign!-function(NLOPT_srand!*, 'int64,s);


% ====================================================
% Subsidiary (local) optimization algorithms
% ====================================================

procedure nlopt_set_local_optimizer(alg);
   call!-foreign!-function(NLOPT_set_local_optimizer!*, 'int32, alg);


% =====================================================
% "Hidden constraints" for the DIRECT global algorithm
% =====================================================
% The algorithm requires that the objective function F(x)
% returns Inf at any x that violates the (arbitrary) constraints.

%- % On a temporary basis these few lines are commented out while CSL and PSL
%- % decide  just what to do about exceptional floating point values.
%- %
%- % In lisp mode, these procedures return 'inf' and 'minusinf' respectively.
%- % Check by
%- %   float!-infinity!-p nlopt_inf();
%- %   float!-infinity!-p nlopt_minf();
%- procedure nlopt_inf();
%-    1e400;  % inf;
%-
%- procedure nlopt_minf();
%-    -1e400; %  minusinf;



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
