%% Several of the algorithms in NLopt (MMA, COBYLA, and ORIG_DIRECT) also support
%% arbitrary nonlinear inequality constraints, and some additionally allow
%% nonlinear equality constraints (ISRES and AUGLAG).


%% ==========================================================================
%% Some basic tests of the interface
%% ==========================================================================

%% Global optimization

%% All of the global optimization algorithms currently require you to specify
%% bound constraints on all the optimization parameters. Of these algorithms,
%% only ISRES and ORIG_DIRECT support nonlinear inequality constraints, and only
%% ISRES supports nonlinear equality constraints. (However, any of them can be
%% applied to nonlinearly constrained problems by combining them with the
%% augmented Lagrangean method below.)

%% Local, derivative-free optimization 

%% Of these algorithms, only COBYLA currently supports arbitrary nonlinear
%% inequality and equality constraints; the rest of them support
%% bound-constrained or unconstrained problems only. (However, any of them can be
%% applied to nonlinearly constrained problems by combining them with the
%% augmented Lagrangean method below.)


load_package assist;

%% ============================================================================
%% A lot of effort has gone into making the package work even if we are not
%% in rounded mode. Still, we're doing numerical optimization, so having it on
%% can't hurt, and might avoid problems that haven't been discovered yet.
on rounded;
%% ============================================================================

print_precision 6;

%% ============================================================================
%% Functions from tests/testfuncs.c.
%% ============================================================================

% 2-dimensional
procedure rosenbrock_f(x);
   begin scalar a,b;
      a := x.2 - (x.1)^2;
      b := 1 - x.1;
      return 100*a^2 + b^2;
   end;

% 30-dimensional
procedure rosenbrock30_f(x);
   begin scalar a, b, f;
     f := 0;
     for i := 1:29 do <<
	a := x.(i+1) - (x.i)^2;
	b := 1 - x.i;
	f := f + 100*a^2 + b^2;
     >>;
     return f;
   end;

procedure mc_cormic_f(x);
   begin scalar a,b;
      a := x.1 + x.2;  
      b := x.1 - x.2;
      return sin(a) + b^2 - 1.5*x.1 + 2.5*x.2 + 1;
   end;


% ============================================================================
procedure tst_ros(x0,m,alg);
   begin scalar ans;
      nlopt_create(alg, 2);
      nlopt_set_maxeval(m);
      nlopt_set_lower_bounds({-2,-2});
      nlopt_set_upper_bounds({2,2});
      nlopt_set_min_objective(rosenbrock_f);
      ans := nlopt_optimize(x0);
      write nlopt_algorithm_name(alg), ":";
      nlopt_destroy();
      return ans;
   end;

procedure tst_ros30(x0,m,alg);
   begin scalar ans;
      nlopt_create(alg, 30);
      nlopt_set_maxeval(m);
      nlopt_set_lower_bounds(for i := 1:30 collect -30);
      nlopt_set_upper_bounds(for i := 1:30 collect 30);
      nlopt_set_min_objective(rosenbrock30_f);
      ans := nlopt_optimize(x0);
      write nlopt_algorithm_name(alg), ":";
      nlopt_destroy();
      return ans;
   end;

procedure tst_mc(x0,m,alg);
   begin scalar ans;
      nlopt_create(alg,2);
      nlopt_set_maxeval(m);
      nlopt_set_lower_bounds({-1.5,-3});
      nlopt_set_upper_bounds({4,4});
      nlopt_set_min_objective(mc_cormic_f);
      ans := nlopt_optimize(x0);
      write nlopt_algorithm_name(alg), ":";
      nlopt_destroy();
      return ans;
   end;


%% ============================================================================
%% Test function from the tutorial: non-linear constraints + gradients
%% ============================================================================

procedure sqt_f(x);
   begin scalar s;
      s := sqrt(x.2);
%      return s;
      return append({s}, {0,0.5/s});
   end;

procedure sq_c1(x);
   begin scalar a,b,f,df;
      % you can do this in symbolic mode; is there an equivalent in algebraic mode?
      % {a,b} := {2,0};
      a := 2;  b := 0;
      f := (a*x.1 + b)^3 - x.2;          % function value
%      return f;
      df := {3*a*(a*x.1 + b)^2, -1.0};   % gradient
      return append({f}, df);
   end;
procedure sq_c2(x);
   begin scalar a,b,f,df;
      a := -1;  b := 1;
      f := (a*x.1 + b)^3 - x.2;          % function value
%      return f;
      df := {3*a*(a*x.1 + b)^2, -1.0};   % gradient
      return append({f}, df);
   end;

% Combination of the two constraints
% x2 >= (a1*x1+b1)^3, x2 >= (a2*x1+b2)^3
% into one vector-valued constraint {C1,C2} <= 0.
clear a,b;  % kludgy!

procedure sq_c1c2(x);
   begin scalar c,c1,c2,dc,dc1,dc2;
      % Do NOT declare a, b; scalars are automatically initialized to 0 in
      % algebraic mode, so the 'sub' won't work!
      c := (a*x.1+b)^3 - x.2;           % parameterized constraint function
      c1 := sub({a=2, b=0}, c);
      c2 := sub({a=-1,b=1}, c);
      dc := {3*a*(a*x.1 + b)^2, -1.0};  % its gradient
      dc1 := sub({a=2, b=0}, dc);
      dc2 := sub({a=-1,b=1}, dc);
      return appendn({c1,c2},dc1,dc2);  % in 'assist' package
   end;


procedure tst_tut(x0,m,alg);
   begin scalar ans;
      nlopt_create(alg, 2);
      nlopt_set_lower_bounds({-20000,0});
      nlopt_set_min_objective(sqt_f);
%      nlopt_add_inequality_constraint(sq_c1,1e-8);
%      nlopt_add_inequality_constraint(sq_c2,1e-8);
      nlopt_add_inequality_mconstraint(sq_c1c2, 2, {1e-8,1e-8});
      nlopt_set_xtol_rel(1e-4);
      % stop when answer is accurate to 3 decimals:
      % nlopt_set_stopval(sqrt(8./27)+1e-3);
      nlopt_set_maxeval(m);
      ans := nlopt_optimize(x0);
      write nlopt_algorithm_name(alg), ":";
      nlopt_destroy();
      write "answer should be 0.544331 @ (0.333333,0.296296): ";
      return ans;
   end;



%% =========================================================================
%% Entropy maximization test with an n-sided die.
%% =========================================================================

procedure h(x);
   - for each xi in x sum xi*log(xi);  % Reduce treats 0*log(0) properly

procedure sum_c(x);
  (for each xi in x sum xi) - 1;

procedure nonneg_c(x);
   for each xi in x collect -xi;

procedure mean_c(x);
   begin scalar n, m1;
      n := length(x);
      return (for i := 1:n sum i*part(x,i)) - mean;
   end;

% An n-sided die with a specified average throw 'av'
procedure tst_die(n,av,tol,m,alg);
   begin scalar x0, mtol, ans;
      nlopt_create(alg, n);
      nlopt_set_max_objective(h);
      x0 := for k := 1:n collect 1/n;
      mtol := for k := 1:n collect tol;
      nlopt_set_maxeval(m);
      % constraints: all x_i >= 0, sum x_i = 1, sum i*x_i = av.
      % inequalities are expressed as <expn> <= 0:
      nlopt_add_inequality_mconstraint(nonneg_c,n,mtol);
      % equalities are expressed as <expn> = 0:
      nlopt_add_equality_constraint(sum_c,tol);
       % 'mean' is global; inelegant, but I can't think of a better way right now.
      mean := av;
      nlopt_add_equality_constraint(mean_c,tol);
      nlopt_set_xtol_rel(1e-6);
      ans := nlopt_optimize(x0);
      nlopt_destroy();
      write nlopt_algorithm_name(alg), ":";
      return ans;
   end;



% ===================================================================================

% Emulates testopt.

procedure testopt(algorithm, problem);
   begin scalar dim;
      % need some data structure (association list?) to hold dimension, constraints/bounds, ...
      nlopt_create(algorithm,dim);
      nlopt_set_min_objective(problem);
   end;




%% ==================================================================
%% The tests, all with derivative-free algorithms
%% ==================================================================

end;


% 2-d Rosenbrock
tst_ros({0,0},500,nlopt_ln_cobyla);
write "testopt -a 25 -c -e 500  -o 0 yields {0.0579211,{0.759468,0.575982}}";
tst_ros({0,0},5000,nlopt_ln_cobyla);
write "testopt -a 25 -c -e 5000 -o 0 yields {0.0000793492,{0.991096,0.982245}}";
tst_ros({0,0},201,nlopt_gn_orig_direct);
write "testopt -a 6 -c -e 200 -o 0 yields {0.0123457,{0.888889,0.790123}}";
tst_ros({0,0},1016,nlopt_gn_orig_direct);
write "testopt -a 6 -c -e 1000 -o 0 yields {0.000106815,{0.989687,0.979413}}";
% McCormick
tst_mc({1.25,0.5},100,nlopt_ln_cobyla);
write "testopt -a 25 -c -e 100 -o 1 yields  {-1.91322,{-0.547198,-1.5472}}";
tst_mc({1.25,0.5},113,nlopt_gn_orig_direct);
write "testopt -a 6 -c -e 100 -o 1 yields {-1.91315,{-0.553155,-1.54527}}";
% 30-dimensional Rosenbrock, with z0 = {0,...,0}.
tst_ros30(z0,2000, nlopt_gn_orig_direct);
write "testopt -a 5  -c -e 8000 -o 4 yields {28.0396},{0.356653,0.118884,0.0274348,0.00914495,...}}";
% HERE WE HAVE A DISAGREEMENT
tst_ros30(z0,1000, nlopt_gn_mlsl);
write "testopt -a 20 -c -e 1000 -o 4 yields {27.5606,{0.460273 0.21201 0.0532263 0.0100821 0.00908559,...}}";
% Tutorial. The trajectory to the result (but not the final result) depends on the lower bound!
tst_tut({1.234,5.678},4,nlopt_ln_cobyla);   % COBYLA
tst_tut({1.234,5.678},4,nlopt_ld_mma);   % MMA
% Entropy, die
% Should yield {1.61358, {0.0543531,0.0787714,0.11416,0.165447,0.239775,0.347494}}
tst_die(6,4.5,1e-5,300,nlopt_ln_cobyla);
