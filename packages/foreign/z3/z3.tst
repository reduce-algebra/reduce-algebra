load_package z3;

lisp;

cfg := z3_mk_config()$
ctx := z3_mk_context cfg$
slv := z3_mk_simple_solver ctx$

% unsat example
f := z3_parse_smtlib2_string(ctx, "(declare-fun x () Int) (assert (and (and (>= x 0) (= (mod x 4) 0)) (not (= (+ (- (* 88 (div (+ x 2) 44))) (* 88 (div (+ x 1) 44)) (- (mod (+ x 2) 44)) (mod (+ x 1) 44) 1) 0))))");
z3_solver_assert(ctx, slv, f)$
b := z3_check!-sat(ctx, slv);

z3_solver_reset(ctx, slv)$

% sat example
f := z3_parse_smtlib2_string(ctx, "(declare-fun x () Int) (assert (and (and (>= x 0) (= (mod x 4) 0)) (not (= (+ (- (* 90 (div (+ x 3) 45))) (* 90 (div (+ x 2) 45)) (- (mod (+ x 3) 45)) (mod (+ x 2) 45) 1) 0))))")$
z3_solver_assert(ctx, slv, f)$
b := z3_check!-sat(ctx, slv);

% manual test of the protocol for passing argument lists
zwei := z3_mk_int(ctx, 2);
drei := z3_mk_int(ctx, 3);
vier := z3_mk_int(ctx, 4);

z3_init_args(3);

z3_push_to_args zwei;
z3_push_to_args drei;
z3_push_to_args vier;

ast := z3_mk_app(ctx, "plus");

z3_cleanup_args();

z3_prin2_ast(ctx, ast);

% form2ast tests

% arithmetic operations:
ast := z3_form2ast(ctx, '(plus 1 (times 5711 z) (times 2 x) y));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(plus (minus x) (minus x (* 10 y))));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(* (minus 5) (difference x (* y z w (plus 1 3 x)))));
z3_prin2_ast(ctx, ast);

% relations:
ast := z3_form2ast(ctx, '(neq 1 2));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(equal 1 x));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(geq x y));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(leq 147 (plus y x)));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(greaterp 47 (plus y (times x 3))));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(lessp (minus 10) (minus x y)));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(equiv (equal 0 (modc a 4)) (cong a 0 4)));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(equiv (ncong a 0 47) (greaterp (modc a 47) 0)));
z3_prin2_ast(ctx, ast);

% logical connectives:

ast := z3_form2ast(ctx, 'true);
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, 'false);
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(and (neq 1 2) (equal 1 3)));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(and true false true true false));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(and (geq x y) false));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(equiv (equal 1 0) false));
z3_prin2_ast(ctx, ast);

ast := z3_form2ast(ctx, '(impl false (not (equal (minus x) 0))));
z3_prin2_ast(ctx, ast);

z3_del_context ctx$
z3_del_config cfg$

end;  % of file
