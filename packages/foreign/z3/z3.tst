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

args := z3_init_args(3);

args := z3_push_to_args zwei;
args := z3_push_to_args drei;
args := z3_push_to_args vier;

ast := z3_mk_app(ctx, "plus");

z3_cleanup_args();

z3_prin2_ast(ctx, ast);

% form2ast
ast := z3_form2ast(ctx, '(plus 1 (times 5711 z) (times 2 x) y));
z3_prin2_ast(ctx, ast);

z3_del_context ctx$
z3_del_config cfg$

end;  % of file
