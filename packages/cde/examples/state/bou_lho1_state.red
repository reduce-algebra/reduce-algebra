% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t v_t)
de!*:=((plus (times sig v_3x) (times u v_x) (times u_x v)) (plus u_x (times v
v_x)))
% odd equation
principal_odd!*:=(p_t q_t)
de_odd!*((plus (times p_x v) q_x) (plus (times p_3x sig) (times p_x u) (times
q_x v)))
% Settings:
indep_var!*:=(x t)
dep_var!*:=(u v)
odd_var!*:=(p q)
deg_indep_var!*:=(-1 -2)
deg_dep_var!*:=(2 1)
deg_odd_var!*:=(1 2)
total_order:=8
id_tot_der!*:=dd
% Here starts the output of computations of the program.
% number of independent variables:
n_indep_var:=2
% all multiindexes in table format:
all_mind_table!*:=(((0 0) ((1 0) (0 1))) ((1 0) ((2 0) (1 1) (1 1) (0 2))) ((0 1
) ((1 1) (0 2))) ((2 0) ((3 0) (2 1) (2 1) (1 2) (1 2) (0 3))) ((1 1) ((2 1) (1
2) (1 2) (0 3))) ((0 2) ((1 2) (0 3))) ((3 0) ((4 0) (3 1) (3 1) (2 2) (2 2) (1
3) (1 3) (0 4))) ((2 1) ((3 1) (2 2) (2 2) (1 3) (1 3) (0 4))) ((1 2) ((2 2) (1
3) (1 3) (0 4))) ((0 3) ((1 3) (0 4))) ((4 0) ((5 0) (4 1) (4 1) (3 2) (3 2) (2
3) (2 3) (1 4) (1 4) (0 5))) ((3 1) ((4 1) (3 2) (3 2) (2 3) (2 3) (1 4) (1 4) (
0 5))) ((2 2) ((3 2) (2 3) (2 3) (1 4) (1 4) (0 5))) ((1 3) ((2 3) (1 4) (1 4) (
0 5))) ((0 4) ((1 4) (0 5))) ((5 0) ((6 0) (5 1) (5 1) (4 2) (4 2) (3 3) (3 3) (
2 4) (2 4) (1 5) (1 5) (0 6))) ((4 1) ((5 1) (4 2) (4 2) (3 3) (3 3) (2 4) (2 4)
(1 5) (1 5) (0 6))) ((3 2) ((4 2) (3 3) (3 3) (2 4) (2 4) (1 5) (1 5) (0 6))) ((
2 3) ((3 3) (2 4) (2 4) (1 5) (1 5) (0 6))) ((1 4) ((2 4) (1 5) (1 5) (0 6))) ((
0 5) ((1 5) (0 6))) ((6 0) ((7 0) (6 1) (6 1) (5 2) (5 2) (4 3) (4 3) (3 4) (3 4
) (2 5) (2 5) (1 6) (1 6) (0 7))) ((5 1) ((6 1) (5 2) (5 2) (4 3) (4 3) (3 4) (3
4) (2 5) (2 5) (1 6) (1 6) (0 7))) ((4 2) ((5 2) (4 3) (4 3) (3 4) (3 4) (2 5) (
2 5) (1 6) (1 6) (0 7))) ((3 3) ((4 3) (3 4) (3 4) (2 5) (2 5) (1 6) (1 6) (0 7)
)) ((2 4) ((3 4) (2 5) (2 5) (1 6) (1 6) (0 7))) ((1 5) ((2 5) (1 6) (1 6) (0 7)
)) ((0 6) ((1 6) (0 7))) ((7 0) ((8 0) (7 1) (7 1) (6 2) (6 2) (5 3) (5 3) (4 4)
(4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((6 1) ((7 1) (6 2) (6 2) (5 3
) (5 3) (4 4) (4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((5 2) ((6 2) (5
3) (5 3) (4 4) (4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((4 3) ((5 3) (
4 4) (4 4) (3 5) (3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((3 4) ((4 4) (3 5) (3 5)
(2 6) (2 6) (1 7) (1 7) (0 8))) ((2 5) ((3 5) (2 6) (2 6) (1 7) (1 7) (0 8))) ((
1 6) ((2 6) (1 7) (1 7) (0 8))) ((0 7) ((1 7) (0 8))) ((8 0) nil) ((7 1) nil) ((
6 2) nil) ((5 3) nil) ((4 4) nil) ((3 5) nil) ((2 6) nil) ((1 7) nil) ((0 8) nil
))
% all even derivatives in multiindex notation:
all_der_mind!*:=((u (0 0)) (v (0 0)) (u (1 0)) (v (1 0)) (u (0 1)) (v (0 1)) (u
(2 0)) (v (2 0)) (u (1 1)) (v (1 1)) (u (0 2)) (v (0 2)) (u (3 0)) (v (3 0)) (u
(2 1)) (v (2 1)) (u (1 2)) (v (1 2)) (u (0 3)) (v (0 3)) (u (4 0)) (v (4 0)) (u
(3 1)) (v (3 1)) (u (2 2)) (v (2 2)) (u (1 3)) (v (1 3)) (u (0 4)) (v (0 4)) (u
(5 0)) (v (5 0)) (u (4 1)) (v (4 1)) (u (3 2)) (v (3 2)) (u (2 3)) (v (2 3)) (u
(1 4)) (v (1 4)) (u (0 5)) (v (0 5)) (u (6 0)) (v (6 0)) (u (5 1)) (v (5 1)) (u
(4 2)) (v (4 2)) (u (3 3)) (v (3 3)) (u (2 4)) (v (2 4)) (u (1 5)) (v (1 5)) (u
(0 6)) (v (0 6)) (u (7 0)) (v (7 0)) (u (6 1)) (v (6 1)) (u (5 2)) (v (5 2)) (u
(4 3)) (v (4 3)) (u (3 4)) (v (3 4)) (u (2 5)) (v (2 5)) (u (1 6)) (v (1 6)) (u
(0 7)) (v (0 7)) (u (8 0)) (v (8 0)) (u (7 1)) (v (7 1)) (u (6 2)) (v (6 2)) (u
(5 3)) (v (5 3)) (u (4 4)) (v (4 4)) (u (3 5)) (v (3 5)) (u (2 6)) (v (2 6)) (u
(1 7)) (v (1 7)) (u (0 8)) (v (0 8)))
% all odd derivatives in multiindex notation:
all_odd_mind!*:=((p (0 0)) (q (0 0)) (p (1 0)) (q (1 0)) (p (0 1)) (q (0 1)) (p
(2 0)) (q (2 0)) (p (1 1)) (q (1 1)) (p (0 2)) (q (0 2)) (p (3 0)) (q (3 0)) (p
(2 1)) (q (2 1)) (p (1 2)) (q (1 2)) (p (0 3)) (q (0 3)) (p (4 0)) (q (4 0)) (p
(3 1)) (q (3 1)) (p (2 2)) (q (2 2)) (p (1 3)) (q (1 3)) (p (0 4)) (q (0 4)) (p
(5 0)) (q (5 0)) (p (4 1)) (q (4 1)) (p (3 2)) (q (3 2)) (p (2 3)) (q (2 3)) (p
(1 4)) (q (1 4)) (p (0 5)) (q (0 5)) (p (6 0)) (q (6 0)) (p (5 1)) (q (5 1)) (p
(4 2)) (q (4 2)) (p (3 3)) (q (3 3)) (p (2 4)) (q (2 4)) (p (1 5)) (q (1 5)) (p
(0 6)) (q (0 6)) (p (7 0)) (q (7 0)) (p (6 1)) (q (6 1)) (p (5 2)) (q (5 2)) (p
(4 3)) (q (4 3)) (p (3 4)) (q (3 4)) (p (2 5)) (q (2 5)) (p (1 6)) (q (1 6)) (p
(0 7)) (q (0 7)) (p (8 0)) (q (8 0)) (p (7 1)) (q (7 1)) (p (6 2)) (q (6 2)) (p
(5 3)) (q (5 3)) (p (4 4)) (q (4 4)) (p (3 5)) (q (3 5)) (p (2 6)) (q (2 6)) (p
(1 7)) (q (1 7)) (p (0 8)) (q (0 8)))
% all even derivatives in identifier notation:
all_der_id!*:=(u v u_x v_x u_t v_t u_2x v_2x u_xt v_xt u_2t v_2t u_3x v_3x u_2xt
v_2xt u_x2t v_x2t u_3t v_3t u_4x v_4x u_3xt v_3xt u_2x2t v_2x2t u_x3t v_x3t u_4t
v_4t u_5x v_5x u_4xt v_4xt u_3x2t v_3x2t u_2x3t v_2x3t u_x4t v_x4t u_5t v_5t
u_6x v_6x u_5xt v_5xt u_4x2t v_4x2t u_3x3t v_3x3t u_2x4t v_2x4t u_x5t v_x5t u_6t
v_6t u_7x v_7x u_6xt v_6xt u_5x2t v_5x2t u_4x3t v_4x3t u_3x4t v_3x4t u_2x5t
v_2x5t u_x6t v_x6t u_7t v_7t u_8x v_8x u_7xt v_7xt u_6x2t v_6x2t u_5x3t v_5x3t
u_4x4t v_4x4t u_3x5t v_3x5t u_2x6t v_2x6t u_x7t v_x7t u_8t v_8t)
% all odd derivatives in identifier notation:
all_odd_id!*:=(p q p_x q_x p_t q_t p_2x q_2x p_xt q_xt p_2t q_2t p_3x q_3x p_2xt
q_2xt p_x2t q_x2t p_3t q_3t p_4x q_4x p_3xt q_3xt p_2x2t q_2x2t p_x3t q_x3t p_4t
q_4t p_5x q_5x p_4xt q_4xt p_3x2t q_3x2t p_2x3t q_2x3t p_x4t q_x4t p_5t q_5t
p_6x q_6x p_5xt q_5xt p_4x2t q_4x2t p_3x3t q_3x3t p_2x4t q_2x4t p_x5t q_x5t p_6t
q_6t p_7x q_7x p_6xt q_6xt p_5x2t q_5x2t p_4x3t q_4x3t p_3x4t q_3x4t p_2x5t
q_2x5t p_x6t q_x6t p_7t q_7t p_8x q_8x p_7xt q_7xt p_6x2t q_6x2t p_5x3t q_5x3t
p_4x4t q_4x4t p_3x5t q_3x5t p_2x6t q_2x6t p_x7t q_x7t p_8t q_8t)
% number of all ext symbols:
n_all_ext:=90
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0)) (v v (0 0)) (u_x u (1 0)) (v_x v (1 0)) (u_t u (0 1
)) (v_t v (0 1)) (u_2x u (2 0)) (v_2x v (2 0)) (u_xt u (1 1)) (v_xt v (1 1)) (
u_2t u (0 2)) (v_2t v (0 2)) (u_3x u (3 0)) (v_3x v (3 0)) (u_2xt u (2 1)) (
v_2xt v (2 1)) (u_x2t u (1 2)) (v_x2t v (1 2)) (u_3t u (0 3)) (v_3t v (0 3)) (
u_4x u (4 0)) (v_4x v (4 0)) (u_3xt u (3 1)) (v_3xt v (3 1)) (u_2x2t u (2 2)) (
v_2x2t v (2 2)) (u_x3t u (1 3)) (v_x3t v (1 3)) (u_4t u (0 4)) (v_4t v (0 4)) (
u_5x u (5 0)) (v_5x v (5 0)) (u_4xt u (4 1)) (v_4xt v (4 1)) (u_3x2t u (3 2)) (
v_3x2t v (3 2)) (u_2x3t u (2 3)) (v_2x3t v (2 3)) (u_x4t u (1 4)) (v_x4t v (1 4)
) (u_5t u (0 5)) (v_5t v (0 5)) (u_6x u (6 0)) (v_6x v (6 0)) (u_5xt u (5 1)) (
v_5xt v (5 1)) (u_4x2t u (4 2)) (v_4x2t v (4 2)) (u_3x3t u (3 3)) (v_3x3t v (3 3
)) (u_2x4t u (2 4)) (v_2x4t v (2 4)) (u_x5t u (1 5)) (v_x5t v (1 5)) (u_6t u (0
6)) (v_6t v (0 6)) (u_7x u (7 0)) (v_7x v (7 0)) (u_6xt u (6 1)) (v_6xt v (6 1))
(u_5x2t u (5 2)) (v_5x2t v (5 2)) (u_4x3t u (4 3)) (v_4x3t v (4 3)) (u_3x4t u (3
4)) (v_3x4t v (3 4)) (u_2x5t u (2 5)) (v_2x5t v (2 5)) (u_x6t u (1 6)) (v_x6t v
(1 6)) (u_7t u (0 7)) (v_7t v (0 7)) (u_8x u (8 0)) (v_8x v (8 0)) (u_7xt u (7 1
)) (v_7xt v (7 1)) (u_6x2t u (6 2)) (v_6x2t v (6 2)) (u_5x3t u (5 3)) (v_5x3t v
(5 3)) (u_4x4t u (4 4)) (v_4x4t v (4 4)) (u_3x5t u (3 5)) (v_3x5t v (3 5)) (
u_2x6t u (2 6)) (v_2x6t v (2 6)) (u_x7t u (1 7)) (v_x7t v (1 7)) (u_8t u (0 8))
(v_8t v (0 8)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((p p (0 0)) (q q (0 0)) (p_x p (1 0)) (q_x q (1 0)) (p_t p
(0 1)) (q_t q (0 1)) (p_2x p (2 0)) (q_2x q (2 0)) (p_xt p (1 1)) (q_xt q (1 1))
(p_2t p (0 2)) (q_2t q (0 2)) (p_3x p (3 0)) (q_3x q (3 0)) (p_2xt p (2 1)) (
q_2xt q (2 1)) (p_x2t p (1 2)) (q_x2t q (1 2)) (p_3t p (0 3)) (q_3t q (0 3)) (
p_4x p (4 0)) (q_4x q (4 0)) (p_3xt p (3 1)) (q_3xt q (3 1)) (p_2x2t p (2 2)) (
q_2x2t q (2 2)) (p_x3t p (1 3)) (q_x3t q (1 3)) (p_4t p (0 4)) (q_4t q (0 4)) (
p_5x p (5 0)) (q_5x q (5 0)) (p_4xt p (4 1)) (q_4xt q (4 1)) (p_3x2t p (3 2)) (
q_3x2t q (3 2)) (p_2x3t p (2 3)) (q_2x3t q (2 3)) (p_x4t p (1 4)) (q_x4t q (1 4)
) (p_5t p (0 5)) (q_5t q (0 5)) (p_6x p (6 0)) (q_6x q (6 0)) (p_5xt p (5 1)) (
q_5xt q (5 1)) (p_4x2t p (4 2)) (q_4x2t q (4 2)) (p_3x3t p (3 3)) (q_3x3t q (3 3
)) (p_2x4t p (2 4)) (q_2x4t q (2 4)) (p_x5t p (1 5)) (q_x5t q (1 5)) (p_6t p (0
6)) (q_6t q (0 6)) (p_7x p (7 0)) (q_7x q (7 0)) (p_6xt p (6 1)) (q_6xt q (6 1))
(p_5x2t p (5 2)) (q_5x2t q (5 2)) (p_4x3t p (4 3)) (q_4x3t q (4 3)) (p_3x4t p (3
4)) (q_3x4t q (3 4)) (p_2x5t p (2 5)) (q_2x5t q (2 5)) (p_x6t p (1 6)) (q_x6t q
(1 6)) (p_7t p (0 7)) (q_7t q (0 7)) (p_8x p (8 0)) (q_8x q (8 0)) (p_7xt p (7 1
)) (q_7xt q (7 1)) (p_6x2t p (6 2)) (q_6x2t q (6 2)) (p_5x3t p (5 3)) (q_5x3t q
(5 3)) (p_4x4t p (4 4)) (q_4x4t q (4 4)) (p_3x5t p (3 5)) (q_3x5t q (3 5)) (
p_2x6t p (2 6)) (q_2x6t q (2 6)) (p_x7t p (1 7)) (q_x7t q (1 7)) (p_8t p (0 8))
(q_8t q (0 8)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (v . 0) (u_x . 1) (v_x . 1) (u_t . 1) (v_t . 1) (u_2x .
2) (v_2x . 2) (u_xt . 2) (v_xt . 2) (u_2t . 2) (v_2t . 2) (u_3x . 3) (v_3x . 3)
(u_2xt . 3) (v_2xt . 3) (u_x2t . 3) (v_x2t . 3) (u_3t . 3) (v_3t . 3) (u_4x . 4)
(v_4x . 4) (u_3xt . 4) (v_3xt . 4) (u_2x2t . 4) (v_2x2t . 4) (u_x3t . 4) (v_x3t
. 4) (u_4t . 4) (v_4t . 4) (u_5x . 5) (v_5x . 5) (u_4xt . 5) (v_4xt . 5) (u_3x2t
. 5) (v_3x2t . 5) (u_2x3t . 5) (v_2x3t . 5) (u_x4t . 5) (v_x4t . 5) (u_5t . 5) (
v_5t . 5) (u_6x . 6) (v_6x . 6) (u_5xt . 6) (v_5xt . 6) (u_4x2t . 6) (v_4x2t . 6
) (u_3x3t . 6) (v_3x3t . 6) (u_2x4t . 6) (v_2x4t . 6) (u_x5t . 6) (v_x5t . 6) (
u_6t . 6) (v_6t . 6) (u_7x . 7) (v_7x . 7) (u_6xt . 7) (v_6xt . 7) (u_5x2t . 7)
(v_5x2t . 7) (u_4x3t . 7) (v_4x3t . 7) (u_3x4t . 7) (v_3x4t . 7) (u_2x5t . 7) (
v_2x5t . 7) (u_x6t . 7) (v_x6t . 7) (u_7t . 7) (v_7t . 7) (u_8x . 8) (v_8x . 8)
(u_7xt . 8) (v_7xt . 8) (u_6x2t . 8) (v_6x2t . 8) (u_5x3t . 8) (v_5x3t . 8) (
u_4x4t . 8) (v_4x4t . 8) (u_3x5t . 8) (v_3x5t . 8) (u_2x6t . 8) (v_2x6t . 8) (
u_x7t . 8) (v_x7t . 8) (u_8t . 8) (v_8t . 8))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((p . 0) (q . 0) (p_x . 1) (q_x . 1) (p_t . 1) (q_t . 1) (
p_2x . 2) (q_2x . 2) (p_xt . 2) (q_xt . 2) (p_2t . 2) (q_2t . 2) (p_3x . 3) (
q_3x . 3) (p_2xt . 3) (q_2xt . 3) (p_x2t . 3) (q_x2t . 3) (p_3t . 3) (q_3t . 3)
(p_4x . 4) (q_4x . 4) (p_3xt . 4) (q_3xt . 4) (p_2x2t . 4) (q_2x2t . 4) (p_x3t .
4) (q_x3t . 4) (p_4t . 4) (q_4t . 4) (p_5x . 5) (q_5x . 5) (p_4xt . 5) (q_4xt .
5) (p_3x2t . 5) (q_3x2t . 5) (p_2x3t . 5) (q_2x3t . 5) (p_x4t . 5) (q_x4t . 5) (
p_5t . 5) (q_5t . 5) (p_6x . 6) (q_6x . 6) (p_5xt . 6) (q_5xt . 6) (p_4x2t . 6)
(q_4x2t . 6) (p_3x3t . 6) (q_3x3t . 6) (p_2x4t . 6) (q_2x4t . 6) (p_x5t . 6) (
q_x5t . 6) (p_6t . 6) (q_6t . 6) (p_7x . 7) (q_7x . 7) (p_6xt . 7) (q_6xt . 7) (
p_5x2t . 7) (q_5x2t . 7) (p_4x3t . 7) (q_4x3t . 7) (p_3x4t . 7) (q_3x4t . 7) (
p_2x5t . 7) (q_2x5t . 7) (p_x6t . 7) (q_x6t . 7) (p_7t . 7) (q_7t . 7) (p_8x . 8
) (q_8x . 8) (p_7xt . 8) (q_7xt . 8) (p_6x2t . 8) (q_6x2t . 8) (p_5x3t . 8) (
q_5x3t . 8) (p_4x4t . 8) (q_4x4t . 8) (p_3x5t . 8) (q_3x5t . 8) (p_2x6t . 8) (
q_2x6t . 8) (p_x7t . 8) (q_x7t . 8) (p_8t . 8) (q_8t . 8))
% list of even principal derivatives:
all_principal_der!*:=(u_t v_t u_2t u_xt v_2t v_xt u_3t u_x2t u_2xt v_3t v_x2t
v_2xt u_4t u_x3t u_2x2t u_3xt v_4t v_x3t v_2x2t v_3xt u_5t u_x4t u_2x3t u_3x2t
u_4xt v_5t v_x4t v_2x3t v_3x2t v_4xt u_6t u_x5t u_2x4t u_3x3t u_4x2t u_5xt v_6t
v_x5t v_2x4t v_3x3t v_4x2t v_5xt u_7t u_x6t u_2x5t u_3x4t u_4x3t u_5x2t u_6xt
v_7t v_x6t v_2x5t v_3x4t v_4x3t v_5x2t v_6xt u_8t u_x7t u_2x6t u_3x5t u_4x4t
u_5x3t u_6x2t u_7xt v_8t v_x7t v_2x6t v_3x5t v_4x4t v_5x3t v_6x2t v_7xt)
% list of even parametric derivatives:
all_parametric_der!*:=(u v u_x v_x u_2x v_2x u_3x v_3x u_4x v_4x u_5x v_5x u_6x
v_6x u_7x v_7x u_8x v_8x)
% list of odd principal derivatives:
all_principal_odd!*:=(p_t q_t p_2t p_xt q_2t q_xt p_3t p_x2t p_2xt q_3t q_x2t
q_2xt p_4t p_x3t p_2x2t p_3xt q_4t q_x3t q_2x2t q_3xt p_5t p_x4t p_2x3t p_3x2t
p_4xt q_5t q_x4t q_2x3t q_3x2t q_4xt p_6t p_x5t p_2x4t p_3x3t p_4x2t p_5xt q_6t
q_x5t q_2x4t q_3x3t q_4x2t q_5xt p_7t p_x6t p_2x5t p_3x4t p_4x3t p_5x2t p_6xt
q_7t q_x6t q_2x5t q_3x4t q_4x3t q_5x2t q_6xt p_8t p_x7t p_2x6t p_3x5t p_4x4t
p_5x3t p_6x2t p_7xt q_8t q_x7t q_2x6t q_3x5t q_4x4t q_5x3t q_6x2t q_7xt)
p_t = (ext 19)
q_t = (ext 20)
p_2t = (ext 21)
p_xt = (ext 22)
q_2t = (ext 23)
q_xt = (ext 24)
p_3t = (ext 25)
p_x2t = (ext 26)
p_2xt = (ext 27)
q_3t = (ext 28)
q_x2t = (ext 29)
q_2xt = (ext 30)
p_4t = (ext 31)
p_x3t = (ext 32)
p_2x2t = (ext 33)
p_3xt = (ext 34)
q_4t = (ext 35)
q_x3t = (ext 36)
q_2x2t = (ext 37)
q_3xt = (ext 38)
p_5t = (ext 39)
p_x4t = (ext 40)
p_2x3t = (ext 41)
p_3x2t = (ext 42)
p_4xt = (ext 43)
q_5t = (ext 44)
q_x4t = (ext 45)
q_2x3t = (ext 46)
q_3x2t = (ext 47)
q_4xt = (ext 48)
p_6t = (ext 49)
p_x5t = (ext 50)
p_2x4t = (ext 51)
p_3x3t = (ext 52)
p_4x2t = (ext 53)
p_5xt = (ext 54)
q_6t = (ext 55)
q_x5t = (ext 56)
q_2x4t = (ext 57)
q_3x3t = (ext 58)
q_4x2t = (ext 59)
q_5xt = (ext 60)
p_7t = (ext 61)
p_x6t = (ext 62)
p_2x5t = (ext 63)
p_3x4t = (ext 64)
p_4x3t = (ext 65)
p_5x2t = (ext 66)
p_6xt = (ext 67)
q_7t = (ext 68)
q_x6t = (ext 69)
q_2x5t = (ext 70)
q_3x4t = (ext 71)
q_4x3t = (ext 72)
q_5x2t = (ext 73)
q_6xt = (ext 74)
p_8t = (ext 75)
p_x7t = (ext 76)
p_2x6t = (ext 77)
p_3x5t = (ext 78)
p_4x4t = (ext 79)
p_5x3t = (ext 80)
p_6x2t = (ext 81)
p_7xt = (ext 82)
q_8t = (ext 83)
q_x7t = (ext 84)
q_2x6t = (ext 85)
q_3x5t = (ext 86)
q_4x4t = (ext 87)
q_5x3t = (ext 88)
q_6x2t = (ext 89)
q_7xt = (ext 90)
% list of odd parametric derivatives:
all_parametric_odd!*:=(p q p_x q_x p_2x q_2x p_3x q_3x p_4x q_4x p_5x q_5x p_6x
q_6x p_7x q_7x p_8x q_8x)
p = (ext 1)
q = (ext 2)
p_x = (ext 3)
q_x = (ext 4)
p_2x = (ext 5)
q_2x = (ext 6)
p_3x = (ext 7)
q_3x = (ext 8)
p_4x = (ext 9)
q_4x = (ext 10)
p_5x = (ext 11)
q_5x = (ext 12)
p_6x = (ext 13)
q_6x = (ext 14)
p_7x = (ext 15)
q_7x = (ext 16)
p_8x = (ext 17)
q_8x = (ext 18)
% number of ext principal derivatives:
n_all_principal_ext:=72
% number of ext parametric derivatives:
n_all_parametric_ext:=18
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddt)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 v_t) (ddt 0 5 u_xt) (ddt 0 6
v_xt) (ddt 0 7 u_2xt) (ddt 0 8 v_2xt) (ddt 0 9 u_3xt) (ddt 0 10 v_3xt) (ddt 0 11
u_4xt) (ddt 0 12 v_4xt) (ddt 0 13 u_5xt) (ddt 0 14 v_5xt) (ddt 0 15 u_6xt) (ddt
0 16 v_6xt) (ddt 0 17 u_7xt) (ddt 0 18 v_7xt))
primary_diffcon_odd_tot!*:=((ddt 1 1 p_t) (ddt 1 2 q_t) (ddt 1 3 p_xt) (ddt 1 4
q_xt) (ddt 1 5 p_2xt) (ddt 1 6 q_2xt) (ddt 1 7 p_3xt) (ddt 1 8 q_3xt) (ddt 1 9
p_4xt) (ddt 1 10 q_4xt) (ddt 1 11 p_5xt) (ddt 1 12 q_5xt) (ddt 1 13 p_6xt) (ddt
1 14 q_6xt) (ddt 1 15 p_7xt) (ddt 1 16 q_7xt))
primary_diffcon_der!*:=(u_xt v_xt u_2xt v_2xt u_3xt v_3xt u_4xt v_4xt u_5xt
v_5xt u_6xt v_6xt u_7xt v_7xt)
primary_diffcon_odd!*:=(p_xt q_xt p_2xt q_2xt p_3xt q_3xt p_4xt q_4xt p_5xt
q_5xt p_6xt q_6xt p_7xt q_7xt)
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((v_7xt (*sq ((((u_8x . 1) . 1) ((v . 1) ((v_8x . 1) . 1)) ((v_2x
. 1) ((v_6x . 1) . 28)) ((v_3x . 1) ((v_5x . 1) . 56)) ((v_4x . 2) . 35) ((v_7x
. 1) ((v_x . 1) . 8))) . 1) nil)) (u_7xt (*sq ((((letop . 1) . 1)) . 1) nil)) (
v_6xt (*sq ((((u_7x . 1) . 1) ((v . 1) ((v_7x . 1) . 1)) ((v_2x . 1) ((v_5x . 1)
. 21)) ((v_3x . 1) ((v_4x . 1) . 35)) ((v_6x . 1) ((v_x . 1) . 7))) . 1) nil)) (
u_6xt (*sq ((((letop . 1) . 1)) . 1) nil)) (v_5xt (*sq ((((u_6x . 1) . 1) ((v .
1) ((v_6x . 1) . 1)) ((v_2x . 1) ((v_4x . 1) . 15)) ((v_3x . 2) . 10) ((v_5x . 1
) ((v_x . 1) . 6))) . 1) nil)) (u_5xt (*sq ((((sig . 1) ((v_8x . 1) . 1)) ((u .
1) ((v_6x . 1) . 1)) ((u_2x . 1) ((v_4x . 1) . 15)) ((u_3x . 1) ((v_3x . 1) . 20
)) ((u_4x . 1) ((v_2x . 1) . 15)) ((u_5x . 1) ((v_x . 1) . 6)) ((u_6x . 1) ((v .
1) . 1)) ((u_x . 1) ((v_5x . 1) . 6))) . 1) nil)) (v_4xt (*sq ((((u_5x . 1) . 1)
((v . 1) ((v_5x . 1) . 1)) ((v_2x . 1) ((v_3x . 1) . 10)) ((v_4x . 1) ((v_x . 1)
. 5))) . 1) nil)) (u_4xt (*sq ((((sig . 1) ((v_7x . 1) . 1)) ((u . 1) ((v_5x . 1
) . 1)) ((u_2x . 1) ((v_3x . 1) . 10)) ((u_3x . 1) ((v_2x . 1) . 10)) ((u_4x . 1
) ((v_x . 1) . 5)) ((u_5x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_4x . 1) . 5))) . 1)
nil)) (v_3xt (*sq ((((u_4x . 1) . 1) ((v . 1) ((v_4x . 1) . 1)) ((v_2x . 2) . 3)
((v_3x . 1) ((v_x . 1) . 4))) . 1) nil)) (u_3xt (*sq ((((sig . 1) ((v_6x . 1) .
1)) ((u . 1) ((v_4x . 1) . 1)) ((u_2x . 1) ((v_2x . 1) . 6)) ((u_3x . 1) ((v_x .
1) . 4)) ((u_4x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_3x . 1) . 4))) . 1) nil)) (
v_2xt (*sq ((((u_3x . 1) . 1) ((v . 1) ((v_3x . 1) . 1)) ((v_2x . 1) ((v_x . 1)
. 3))) . 1) nil)) (u_2xt (*sq ((((sig . 1) ((v_5x . 1) . 1)) ((u . 1) ((v_3x . 1
) . 1)) ((u_2x . 1) ((v_x . 1) . 3)) ((u_3x . 1) ((v . 1) . 1)) ((u_x . 1) ((
v_2x . 1) . 3))) . 1) nil)) (v_xt (*sq ((((u_2x . 1) . 1) ((v . 1) ((v_2x . 1) .
1)) ((v_x . 2) . 1)) . 1) nil)) (u_xt (*sq ((((sig . 1) ((v_4x . 1) . 1)) ((u .
1) ((v_2x . 1) . 1)) ((u_2x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_x . 1) . 2))) . 1
) nil)) (v_t (plus u_x (times v v_x))) (u_t (plus (times sig v_3x) (times u v_x)
(times u_x v))))
diffcon_odd!*:=((q_7xt (*sq ((((letop . 1) . 1)) . 1) nil)) (p_7xt (*sq (((((ext
18) . 1) . 1) (((ext 17) . 1) ((v . 1) . 1)) (((ext 15) . 1) ((v_x . 1) . 7)) ((
(ext 13) . 1) ((v_2x . 1) . 21)) (((ext 11) . 1) ((v_3x . 1) . 35)) (((ext 9) .
1) ((v_4x . 1) . 35)) (((ext 7) . 1) ((v_5x . 1) . 21)) (((ext 5) . 1) ((v_6x .
1) . 7)) (((ext 3) . 1) ((v_7x . 1) . 1))) . 1) nil)) (q_6xt (*sq ((((letop . 1)
. 1)) . 1) nil)) (p_6xt (*sq (((((ext 16) . 1) . 1) (((ext 15) . 1) ((v . 1) . 1
)) (((ext 13) . 1) ((v_x . 1) . 6)) (((ext 11) . 1) ((v_2x . 1) . 15)) (((ext 9)
. 1) ((v_3x . 1) . 20)) (((ext 7) . 1) ((v_4x . 1) . 15)) (((ext 5) . 1) ((v_5x
. 1) . 6)) (((ext 3) . 1) ((v_6x . 1) . 1))) . 1) nil)) (q_5xt (*sq (((((ext 17)
. 1) ((sig . 1) . 1)) (((ext 14) . 1) ((v . 1) . 1)) (((ext 13) . 1) ((u . 1) .
1)) (((ext 12) . 1) ((v_x . 1) . 5)) (((ext 11) . 1) ((u_x . 1) . 5)) (((ext 10)
. 1) ((v_2x . 1) . 10)) (((ext 9) . 1) ((u_2x . 1) . 10)) (((ext 8) . 1) ((v_3x
. 1) . 10)) (((ext 7) . 1) ((u_3x . 1) . 10)) (((ext 6) . 1) ((v_4x . 1) . 5)) (
((ext 5) . 1) ((u_4x . 1) . 5)) (((ext 4) . 1) ((v_5x . 1) . 1)) (((ext 3) . 1)
((u_5x . 1) . 1))) . 1) nil)) (p_5xt (*sq (((((ext 14) . 1) . 1) (((ext 13) . 1)
((v . 1) . 1)) (((ext 11) . 1) ((v_x . 1) . 5)) (((ext 9) . 1) ((v_2x . 1) . 10)
) (((ext 7) . 1) ((v_3x . 1) . 10)) (((ext 5) . 1) ((v_4x . 1) . 5)) (((ext 3) .
1) ((v_5x . 1) . 1))) . 1) nil)) (q_4xt (*sq (((((ext 15) . 1) ((sig . 1) . 1))
(((ext 12) . 1) ((v . 1) . 1)) (((ext 11) . 1) ((u . 1) . 1)) (((ext 10) . 1) ((
v_x . 1) . 4)) (((ext 9) . 1) ((u_x . 1) . 4)) (((ext 8) . 1) ((v_2x . 1) . 6))
(((ext 7) . 1) ((u_2x . 1) . 6)) (((ext 6) . 1) ((v_3x . 1) . 4)) (((ext 5) . 1)
((u_3x . 1) . 4)) (((ext 4) . 1) ((v_4x . 1) . 1)) (((ext 3) . 1) ((u_4x . 1) .
1))) . 1) nil)) (p_4xt (*sq (((((ext 12) . 1) . 1) (((ext 11) . 1) ((v . 1) . 1)
) (((ext 9) . 1) ((v_x . 1) . 4)) (((ext 7) . 1) ((v_2x . 1) . 6)) (((ext 5) . 1
) ((v_3x . 1) . 4)) (((ext 3) . 1) ((v_4x . 1) . 1))) . 1) nil)) (q_3xt (*sq (((
((ext 13) . 1) ((sig . 1) . 1)) (((ext 10) . 1) ((v . 1) . 1)) (((ext 9) . 1) ((
u . 1) . 1)) (((ext 8) . 1) ((v_x . 1) . 3)) (((ext 7) . 1) ((u_x . 1) . 3)) (((
ext 6) . 1) ((v_2x . 1) . 3)) (((ext 5) . 1) ((u_2x . 1) . 3)) (((ext 4) . 1) ((
v_3x . 1) . 1)) (((ext 3) . 1) ((u_3x . 1) . 1))) . 1) nil)) (p_3xt (*sq (((((
ext 10) . 1) . 1) (((ext 9) . 1) ((v . 1) . 1)) (((ext 7) . 1) ((v_x . 1) . 3))
(((ext 5) . 1) ((v_2x . 1) . 3)) (((ext 3) . 1) ((v_3x . 1) . 1))) . 1) nil)) (
q_2xt (*sq (((((ext 11) . 1) ((sig . 1) . 1)) (((ext 8) . 1) ((v . 1) . 1)) (((
ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1) ((v_x . 1) . 2)) (((ext 5) . 1) ((u_x
. 1) . 2)) (((ext 4) . 1) ((v_2x . 1) . 1)) (((ext 3) . 1) ((u_2x . 1) . 1))) .
1) nil)) (p_2xt (*sq (((((ext 8) . 1) . 1) (((ext 7) . 1) ((v . 1) . 1)) (((ext
5) . 1) ((v_x . 1) . 2)) (((ext 3) . 1) ((v_2x . 1) . 1))) . 1) nil)) (q_xt (*sq
(((((ext 9) . 1) ((sig . 1) . 1)) (((ext 6) . 1) ((v . 1) . 1)) (((ext 5) . 1) (
(u . 1) . 1)) (((ext 4) . 1) ((v_x . 1) . 1)) (((ext 3) . 1) ((u_x . 1) . 1))) .
1) nil)) (p_xt (*sq (((((ext 6) . 1) . 1) (((ext 5) . 1) ((v . 1) . 1)) (((ext 3
) . 1) ((v_x . 1) . 1))) . 1) nil)) (q_t (*sq (((((ext 7) . 1) ((sig . 1) . 1))
(((ext 4) . 1) ((v . 1) . 1)) (((ext 3) . 1) ((u . 1) . 1))) . 1) nil)) (p_t (
*sq (((((ext 4) . 1) . 1) (((ext 3) . 1) ((v . 1) . 1))) . 1) nil)))
% Principal derivatives computed:
diffcon_comp_der!*:=(v_7xt u_7xt v_6xt u_6xt v_5xt u_5xt v_4xt u_4xt v_3xt u_3xt
v_2xt u_2xt v_xt u_xt v_t u_t)
diffcon_comp_odd!*:=(q_7xt p_7xt q_6xt p_6xt q_5xt p_5xt q_4xt p_4xt q_3xt p_3xt
q_2xt p_2xt q_xt p_xt q_t p_t)
diffcon_comp_ext!*:=((ext 90) (ext 82) (ext 74) (ext 67) (ext 60) (ext 54) (ext
48) (ext 43) (ext 38) (ext 34) (ext 30) (ext 27) (ext 24) (ext 22) (ext 20) (ext
19))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((v_7xt *sq ((((u_8x . 1) . 1) ((v . 1) ((v_8x . 1) . 1)) (
(v_2x . 1) ((v_6x . 1) . 28)) ((v_3x . 1) ((v_5x . 1) . 56)) ((v_4x . 2) . 35) (
(v_7x . 1) ((v_x . 1) . 8))) . 1) nil) (u_7xt *sq ((((letop . 1) . 1)) . 1) nil)
(v_6xt *sq ((((u_7x . 1) . 1) ((v . 1) ((v_7x . 1) . 1)) ((v_2x . 1) ((v_5x . 1)
. 21)) ((v_3x . 1) ((v_4x . 1) . 35)) ((v_6x . 1) ((v_x . 1) . 7))) . 1) nil) (
u_6xt *sq ((((letop . 1) . 1)) . 1) nil) (v_5xt *sq ((((u_6x . 1) . 1) ((v . 1)
((v_6x . 1) . 1)) ((v_2x . 1) ((v_4x . 1) . 15)) ((v_3x . 2) . 10) ((v_5x . 1) (
(v_x . 1) . 6))) . 1) nil) (u_5xt *sq ((((sig . 1) ((v_8x . 1) . 1)) ((u . 1) ((
v_6x . 1) . 1)) ((u_2x . 1) ((v_4x . 1) . 15)) ((u_3x . 1) ((v_3x . 1) . 20)) ((
u_4x . 1) ((v_2x . 1) . 15)) ((u_5x . 1) ((v_x . 1) . 6)) ((u_6x . 1) ((v . 1) .
1)) ((u_x . 1) ((v_5x . 1) . 6))) . 1) nil) (v_4xt *sq ((((u_5x . 1) . 1) ((v .
1) ((v_5x . 1) . 1)) ((v_2x . 1) ((v_3x . 1) . 10)) ((v_4x . 1) ((v_x . 1) . 5))
) . 1) nil) (u_4xt *sq ((((sig . 1) ((v_7x . 1) . 1)) ((u . 1) ((v_5x . 1) . 1))
((u_2x . 1) ((v_3x . 1) . 10)) ((u_3x . 1) ((v_2x . 1) . 10)) ((u_4x . 1) ((v_x
. 1) . 5)) ((u_5x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_4x . 1) . 5))) . 1) nil) (
v_3xt *sq ((((u_4x . 1) . 1) ((v . 1) ((v_4x . 1) . 1)) ((v_2x . 2) . 3) ((v_3x
. 1) ((v_x . 1) . 4))) . 1) nil) (u_3xt *sq ((((sig . 1) ((v_6x . 1) . 1)) ((u .
1) ((v_4x . 1) . 1)) ((u_2x . 1) ((v_2x . 1) . 6)) ((u_3x . 1) ((v_x . 1) . 4))
((u_4x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_3x . 1) . 4))) . 1) nil) (v_2xt *sq ((
((u_3x . 1) . 1) ((v . 1) ((v_3x . 1) . 1)) ((v_2x . 1) ((v_x . 1) . 3))) . 1)
nil) (u_2xt *sq ((((sig . 1) ((v_5x . 1) . 1)) ((u . 1) ((v_3x . 1) . 1)) ((u_2x
. 1) ((v_x . 1) . 3)) ((u_3x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_2x . 1) . 3))) .
1) nil) (v_xt *sq ((((u_2x . 1) . 1) ((v . 1) ((v_2x . 1) . 1)) ((v_x . 2) . 1))
. 1) nil) (u_xt *sq ((((sig . 1) ((v_4x . 1) . 1)) ((u . 1) ((v_2x . 1) . 1)) ((
u_2x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_x . 1) . 2))) . 1) nil) (v_t *sq ((((u_x
. 1) . 1) ((v . 1) ((v_x . 1) . 1))) . 1) nil) (u_t *sq ((((sig . 1) ((v_3x . 1)
. 1)) ((u . 1) ((v_x . 1) . 1)) ((u_x . 1) ((v . 1) . 1))) . 1) nil))
diffcon_param_ext!*:=(((ext 90) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 82) *sq
(((((ext 18) . 1) . 1) (((ext 17) . 1) ((v . 1) . 1)) (((ext 15) . 1) ((v_x . 1)
. 7)) (((ext 13) . 1) ((v_2x . 1) . 21)) (((ext 11) . 1) ((v_3x . 1) . 35)) (((
ext 9) . 1) ((v_4x . 1) . 35)) (((ext 7) . 1) ((v_5x . 1) . 21)) (((ext 5) . 1)
((v_6x . 1) . 7)) (((ext 3) . 1) ((v_7x . 1) . 1))) . 1) nil) ((ext 74) *sq ((((
letop . 1) . 1)) . 1) nil) ((ext 67) *sq (((((ext 16) . 1) . 1) (((ext 15) . 1)
((v . 1) . 1)) (((ext 13) . 1) ((v_x . 1) . 6)) (((ext 11) . 1) ((v_2x . 1) . 15
)) (((ext 9) . 1) ((v_3x . 1) . 20)) (((ext 7) . 1) ((v_4x . 1) . 15)) (((ext 5)
. 1) ((v_5x . 1) . 6)) (((ext 3) . 1) ((v_6x . 1) . 1))) . 1) nil) ((ext 60) *sq
(((((ext 17) . 1) ((sig . 1) . 1)) (((ext 14) . 1) ((v . 1) . 1)) (((ext 13) . 1
) ((u . 1) . 1)) (((ext 12) . 1) ((v_x . 1) . 5)) (((ext 11) . 1) ((u_x . 1) . 5
)) (((ext 10) . 1) ((v_2x . 1) . 10)) (((ext 9) . 1) ((u_2x . 1) . 10)) (((ext 8
) . 1) ((v_3x . 1) . 10)) (((ext 7) . 1) ((u_3x . 1) . 10)) (((ext 6) . 1) ((
v_4x . 1) . 5)) (((ext 5) . 1) ((u_4x . 1) . 5)) (((ext 4) . 1) ((v_5x . 1) . 1)
) (((ext 3) . 1) ((u_5x . 1) . 1))) . 1) nil) ((ext 54) *sq (((((ext 14) . 1) .
1) (((ext 13) . 1) ((v . 1) . 1)) (((ext 11) . 1) ((v_x . 1) . 5)) (((ext 9) . 1
) ((v_2x . 1) . 10)) (((ext 7) . 1) ((v_3x . 1) . 10)) (((ext 5) . 1) ((v_4x . 1
) . 5)) (((ext 3) . 1) ((v_5x . 1) . 1))) . 1) nil) ((ext 48) *sq (((((ext 15) .
1) ((sig . 1) . 1)) (((ext 12) . 1) ((v . 1) . 1)) (((ext 11) . 1) ((u . 1) . 1)
) (((ext 10) . 1) ((v_x . 1) . 4)) (((ext 9) . 1) ((u_x . 1) . 4)) (((ext 8) . 1
) ((v_2x . 1) . 6)) (((ext 7) . 1) ((u_2x . 1) . 6)) (((ext 6) . 1) ((v_3x . 1)
. 4)) (((ext 5) . 1) ((u_3x . 1) . 4)) (((ext 4) . 1) ((v_4x . 1) . 1)) (((ext 3
) . 1) ((u_4x . 1) . 1))) . 1) nil) ((ext 43) *sq (((((ext 12) . 1) . 1) (((ext
11) . 1) ((v . 1) . 1)) (((ext 9) . 1) ((v_x . 1) . 4)) (((ext 7) . 1) ((v_2x .
1) . 6)) (((ext 5) . 1) ((v_3x . 1) . 4)) (((ext 3) . 1) ((v_4x . 1) . 1))) . 1)
nil) ((ext 38) *sq (((((ext 13) . 1) ((sig . 1) . 1)) (((ext 10) . 1) ((v . 1) .
1)) (((ext 9) . 1) ((u . 1) . 1)) (((ext 8) . 1) ((v_x . 1) . 3)) (((ext 7) . 1)
((u_x . 1) . 3)) (((ext 6) . 1) ((v_2x . 1) . 3)) (((ext 5) . 1) ((u_2x . 1) . 3
)) (((ext 4) . 1) ((v_3x . 1) . 1)) (((ext 3) . 1) ((u_3x . 1) . 1))) . 1) nil)
((ext 34) *sq (((((ext 10) . 1) . 1) (((ext 9) . 1) ((v . 1) . 1)) (((ext 7) . 1
) ((v_x . 1) . 3)) (((ext 5) . 1) ((v_2x . 1) . 3)) (((ext 3) . 1) ((v_3x . 1) .
1))) . 1) nil) ((ext 30) *sq (((((ext 11) . 1) ((sig . 1) . 1)) (((ext 8) . 1) (
(v . 1) . 1)) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1) ((v_x . 1) . 2)) (((
ext 5) . 1) ((u_x . 1) . 2)) (((ext 4) . 1) ((v_2x . 1) . 1)) (((ext 3) . 1) ((
u_2x . 1) . 1))) . 1) nil) ((ext 27) *sq (((((ext 8) . 1) . 1) (((ext 7) . 1) ((
v . 1) . 1)) (((ext 5) . 1) ((v_x . 1) . 2)) (((ext 3) . 1) ((v_2x . 1) . 1))) .
1) nil) ((ext 24) *sq (((((ext 9) . 1) ((sig . 1) . 1)) (((ext 6) . 1) ((v . 1)
. 1)) (((ext 5) . 1) ((u . 1) . 1)) (((ext 4) . 1) ((v_x . 1) . 1)) (((ext 3) .
1) ((u_x . 1) . 1))) . 1) nil) ((ext 22) *sq (((((ext 6) . 1) . 1) (((ext 5) . 1
) ((v . 1) . 1)) (((ext 3) . 1) ((v_x . 1) . 1))) . 1) nil) ((ext 20) *sq (((((
ext 7) . 1) ((sig . 1) . 1)) (((ext 4) . 1) ((v . 1) . 1)) (((ext 3) . 1) ((u .
1) . 1))) . 1) nil) ((ext 19) *sq (((((ext 4) . 1) . 1) (((ext 3) . 1) ((v . 1)
. 1))) . 1) nil))
% Coefficients of total derivatives:
% component of ddx w.r.t. x
ddx(0,1):=1
% component of ddx w.r.t. t
ddx(0,2):=0
% component of ddx w.r.t. u
ddx(0,3):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v
ddx(0,4):=(*sq ((((v_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x
ddx(0,5):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x
ddx(0,6):=(*sq ((((v_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x
ddx(0,7):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x
ddx(0,8):=(*sq ((((v_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x
ddx(0,9):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x
ddx(0,10):=(*sq ((((v_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x
ddx(0,11):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x
ddx(0,12):=(*sq ((((v_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x
ddx(0,13):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5x
ddx(0,14):=(*sq ((((v_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x
ddx(0,15):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6x
ddx(0,16):=(*sq ((((v_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x
ddx(0,17):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_7x
ddx(0,18):=(*sq ((((v_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x
ddx(0,19):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_8x
ddx(0,20):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t
ddx(0,21):=(*sq ((((u_xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_t
ddx(0,22):=(*sq ((((v_xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,23):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_xt
ddx(0,24):=(*sq ((((u_2xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2t
ddx(0,25):=(*sq ((((v_x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_xt
ddx(0,26):=(*sq ((((v_2xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t
ddx(0,27):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x2t
ddx(0,28):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2xt
ddx(0,29):=(*sq ((((u_3xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3t
ddx(0,30):=(*sq ((((v_x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x2t
ddx(0,31):=(*sq ((((v_2x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2xt
ddx(0,32):=(*sq ((((v_3xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t
ddx(0,33):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x3t
ddx(0,34):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x2t
ddx(0,35):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3xt
ddx(0,36):=(*sq ((((u_4xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4t
ddx(0,37):=(*sq ((((v_x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x3t
ddx(0,38):=(*sq ((((v_2x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x2t
ddx(0,39):=(*sq ((((v_3x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3xt
ddx(0,40):=(*sq ((((v_4xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t
ddx(0,41):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x4t
ddx(0,42):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x3t
ddx(0,43):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x2t
ddx(0,44):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4xt
ddx(0,45):=(*sq ((((u_5xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5t
ddx(0,46):=(*sq ((((v_x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x4t
ddx(0,47):=(*sq ((((v_2x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x3t
ddx(0,48):=(*sq ((((v_3x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x2t
ddx(0,49):=(*sq ((((v_4x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4xt
ddx(0,50):=(*sq ((((v_5xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t
ddx(0,51):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x5t
ddx(0,52):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x4t
ddx(0,53):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x3t
ddx(0,54):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x2t
ddx(0,55):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5xt
ddx(0,56):=(*sq ((((u_6xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6t
ddx(0,57):=(*sq ((((v_x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x5t
ddx(0,58):=(*sq ((((v_2x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x4t
ddx(0,59):=(*sq ((((v_3x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x3t
ddx(0,60):=(*sq ((((v_4x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x2t
ddx(0,61):=(*sq ((((v_5x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5xt
ddx(0,62):=(*sq ((((v_6xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t
ddx(0,63):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x6t
ddx(0,64):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x5t
ddx(0,65):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x4t
ddx(0,66):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x3t
ddx(0,67):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x2t
ddx(0,68):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6xt
ddx(0,69):=(*sq ((((u_7xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_7t
ddx(0,70):=(*sq ((((v_x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x6t
ddx(0,71):=(*sq ((((v_2x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x5t
ddx(0,72):=(*sq ((((v_3x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x4t
ddx(0,73):=(*sq ((((v_4x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x3t
ddx(0,74):=(*sq ((((v_5x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5x2t
ddx(0,75):=(*sq ((((v_6x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6xt
ddx(0,76):=(*sq ((((v_7xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8t
ddx(0,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x7t
ddx(0,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x6t
ddx(0,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x5t
ddx(0,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x4t
ddx(0,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x3t
ddx(0,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x2t
ddx(0,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7xt
ddx(0,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_8t
ddx(0,85):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x7t
ddx(0,86):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x6t
ddx(0,87):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x5t
ddx(0,88):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x4t
ddx(0,89):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5x3t
ddx(0,90):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6x2t
ddx(0,91):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_7xt
ddx(0,92):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p
ddx(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q
ddx(1,2):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x
ddx(1,3):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x
ddx(1,4):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x
ddx(1,5):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x
ddx(1,6):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x
ddx(1,7):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x
ddx(1,8):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x
ddx(1,9):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x
ddx(1,10):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x
ddx(1,11):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x
ddx(1,12):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x
ddx(1,13):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x
ddx(1,14):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x
ddx(1,15):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x
ddx(1,16):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8x
ddx(1,17):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x
ddx(1,18):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t
ddx(1,19):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t
ddx(1,20):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t
ddx(1,21):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_xt
ddx(1,22):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t
ddx(1,23):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_xt
ddx(1,24):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t
ddx(1,25):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x2t
ddx(1,26):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2xt
ddx(1,27):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t
ddx(1,28):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x2t
ddx(1,29):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2xt
ddx(1,30):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t
ddx(1,31):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x3t
ddx(1,32):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x2t
ddx(1,33):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3xt
ddx(1,34):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t
ddx(1,35):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x3t
ddx(1,36):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x2t
ddx(1,37):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3xt
ddx(1,38):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t
ddx(1,39):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x4t
ddx(1,40):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x3t
ddx(1,41):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x2t
ddx(1,42):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4xt
ddx(1,43):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t
ddx(1,44):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x4t
ddx(1,45):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x3t
ddx(1,46):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x2t
ddx(1,47):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4xt
ddx(1,48):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t
ddx(1,49):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x5t
ddx(1,50):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x4t
ddx(1,51):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x3t
ddx(1,52):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x2t
ddx(1,53):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5xt
ddx(1,54):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t
ddx(1,55):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x5t
ddx(1,56):=(*sq (((((ext 70) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x4t
ddx(1,57):=(*sq (((((ext 71) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x3t
ddx(1,58):=(*sq (((((ext 72) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x2t
ddx(1,59):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5xt
ddx(1,60):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7t
ddx(1,61):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x6t
ddx(1,62):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x5t
ddx(1,63):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x4t
ddx(1,64):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x3t
ddx(1,65):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x2t
ddx(1,66):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6xt
ddx(1,67):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7t
ddx(1,68):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x6t
ddx(1,69):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x5t
ddx(1,70):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x4t
ddx(1,71):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x3t
ddx(1,72):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x2t
ddx(1,73):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6xt
ddx(1,74):=(*sq (((((ext 90) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8t
ddx(1,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x7t
ddx(1,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x6t
ddx(1,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x5t
ddx(1,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x4t
ddx(1,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x3t
ddx(1,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x2t
ddx(1,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7xt
ddx(1,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8t
ddx(1,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x7t
ddx(1,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x6t
ddx(1,85):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x5t
ddx(1,86):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x4t
ddx(1,87):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x3t
ddx(1,88):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x2t
ddx(1,89):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7xt
ddx(1,90):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. x
ddt(0,1):=0
% component of ddt w.r.t. t
ddt(0,2):=1
% component of ddt w.r.t. u
ddt(0,3):=(*sq ((((sig . 1) ((v_3x . 1) . 1)) ((u . 1) ((v_x . 1) . 1)) ((u_x .
1) ((v . 1) . 1))) . 1) t)
% component of ddt w.r.t. v
ddt(0,4):=(*sq ((((u_x . 1) . 1) ((v . 1) ((v_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,5):=(*sq ((((sig . 1) ((v_4x . 1) . 1)) ((u . 1) ((v_2x . 1) . 1)) ((u_2x
. 1) ((v . 1) . 1)) ((u_x . 1) ((v_x . 1) . 2))) . 1) t)
% component of ddt w.r.t. v_x
ddt(0,6):=(*sq ((((u_2x . 1) . 1) ((v . 1) ((v_2x . 1) . 1)) ((v_x . 2) . 1)) .
1) t)
% component of ddt w.r.t. u_2x
ddt(0,7):=(*sq ((((sig . 1) ((v_5x . 1) . 1)) ((u . 1) ((v_3x . 1) . 1)) ((u_2x
. 1) ((v_x . 1) . 3)) ((u_3x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_2x . 1) . 3))) .
1) t)
% component of ddt w.r.t. v_2x
ddt(0,8):=(*sq ((((u_3x . 1) . 1) ((v . 1) ((v_3x . 1) . 1)) ((v_2x . 1) ((v_x .
1) . 3))) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,9):=(*sq ((((sig . 1) ((v_6x . 1) . 1)) ((u . 1) ((v_4x . 1) . 1)) ((u_2x
. 1) ((v_2x . 1) . 6)) ((u_3x . 1) ((v_x . 1) . 4)) ((u_4x . 1) ((v . 1) . 1)) (
(u_x . 1) ((v_3x . 1) . 4))) . 1) t)
% component of ddt w.r.t. v_3x
ddt(0,10):=(*sq ((((u_4x . 1) . 1) ((v . 1) ((v_4x . 1) . 1)) ((v_2x . 2) . 3) (
(v_3x . 1) ((v_x . 1) . 4))) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,11):=(*sq ((((sig . 1) ((v_7x . 1) . 1)) ((u . 1) ((v_5x . 1) . 1)) ((u_2x
. 1) ((v_3x . 1) . 10)) ((u_3x . 1) ((v_2x . 1) . 10)) ((u_4x . 1) ((v_x . 1) .
5)) ((u_5x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_4x . 1) . 5))) . 1) t)
% component of ddt w.r.t. v_4x
ddt(0,12):=(*sq ((((u_5x . 1) . 1) ((v . 1) ((v_5x . 1) . 1)) ((v_2x . 1) ((v_3x
. 1) . 10)) ((v_4x . 1) ((v_x . 1) . 5))) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,13):=(*sq ((((sig . 1) ((v_8x . 1) . 1)) ((u . 1) ((v_6x . 1) . 1)) ((u_2x
. 1) ((v_4x . 1) . 15)) ((u_3x . 1) ((v_3x . 1) . 20)) ((u_4x . 1) ((v_2x . 1) .
15)) ((u_5x . 1) ((v_x . 1) . 6)) ((u_6x . 1) ((v . 1) . 1)) ((u_x . 1) ((v_5x .
1) . 6))) . 1) t)
% component of ddt w.r.t. v_5x
ddt(0,14):=(*sq ((((u_6x . 1) . 1) ((v . 1) ((v_6x . 1) . 1)) ((v_2x . 1) ((v_4x
. 1) . 15)) ((v_3x . 2) . 10) ((v_5x . 1) ((v_x . 1) . 6))) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,15):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_6x
ddt(0,16):=(*sq ((((u_7x . 1) . 1) ((v . 1) ((v_7x . 1) . 1)) ((v_2x . 1) ((v_5x
. 1) . 21)) ((v_3x . 1) ((v_4x . 1) . 35)) ((v_6x . 1) ((v_x . 1) . 7))) . 1) t)
% component of ddt w.r.t. u_7x
ddt(0,17):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_7x
ddt(0,18):=(*sq ((((u_8x . 1) . 1) ((v . 1) ((v_8x . 1) . 1)) ((v_2x . 1) ((v_6x
. 1) . 28)) ((v_3x . 1) ((v_5x . 1) . 56)) ((v_4x . 2) . 35) ((v_7x . 1) ((v_x .
1) . 8))) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,19):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_8x
ddt(0,20):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,21):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_t
ddt(0,22):=(*sq ((((v_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,23):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_xt
ddt(0,24):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2t
ddt(0,25):=(*sq ((((v_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_xt
ddt(0,26):=(*sq ((((v_x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,27):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x2t
ddt(0,28):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2xt
ddt(0,29):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3t
ddt(0,30):=(*sq ((((v_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x2t
ddt(0,31):=(*sq ((((v_x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2xt
ddt(0,32):=(*sq ((((v_2x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,33):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x3t
ddt(0,34):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x2t
ddt(0,35):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3xt
ddt(0,36):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4t
ddt(0,37):=(*sq ((((v_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x3t
ddt(0,38):=(*sq ((((v_x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x2t
ddt(0,39):=(*sq ((((v_2x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3xt
ddt(0,40):=(*sq ((((v_3x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,41):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x4t
ddt(0,42):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x3t
ddt(0,43):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x2t
ddt(0,44):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4xt
ddt(0,45):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5t
ddt(0,46):=(*sq ((((v_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x4t
ddt(0,47):=(*sq ((((v_x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x3t
ddt(0,48):=(*sq ((((v_2x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x2t
ddt(0,49):=(*sq ((((v_3x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4xt
ddt(0,50):=(*sq ((((v_4x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,51):=(*sq ((((u_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x5t
ddt(0,52):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x4t
ddt(0,53):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x3t
ddt(0,54):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x2t
ddt(0,55):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5xt
ddt(0,56):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_6t
ddt(0,57):=(*sq ((((v_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x5t
ddt(0,58):=(*sq ((((v_x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x4t
ddt(0,59):=(*sq ((((v_2x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x3t
ddt(0,60):=(*sq ((((v_3x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4x2t
ddt(0,61):=(*sq ((((v_4x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5xt
ddt(0,62):=(*sq ((((v_5x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t
ddt(0,63):=(*sq ((((u_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x6t
ddt(0,64):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x5t
ddt(0,65):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x4t
ddt(0,66):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x3t
ddt(0,67):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x2t
ddt(0,68):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6xt
ddt(0,69):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_7t
ddt(0,70):=(*sq ((((v_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x6t
ddt(0,71):=(*sq ((((v_x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x5t
ddt(0,72):=(*sq ((((v_2x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x4t
ddt(0,73):=(*sq ((((v_3x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4x3t
ddt(0,74):=(*sq ((((v_4x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5x2t
ddt(0,75):=(*sq ((((v_5x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_6xt
ddt(0,76):=(*sq ((((v_6x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t
ddt(0,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x7t
ddt(0,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x6t
ddt(0,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x5t
ddt(0,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x4t
ddt(0,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x3t
ddt(0,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x2t
ddt(0,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7xt
ddt(0,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_8t
ddt(0,85):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x7t
ddt(0,86):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x6t
ddt(0,87):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x5t
ddt(0,88):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4x4t
ddt(0,89):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5x3t
ddt(0,90):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_6x2t
ddt(0,91):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_7xt
ddt(0,92):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p
ddt(1,1):=(*sq (((((ext 4) . 1) . 1) (((ext 3) . 1) ((v . 1) . 1))) . 1) t)
% component of ddt w.r.t. q
ddt(1,2):=(*sq (((((ext 7) . 1) ((sig . 1) . 1)) (((ext 4) . 1) ((v . 1) . 1)) (
((ext 3) . 1) ((u . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_x
ddt(1,3):=(*sq (((((ext 6) . 1) . 1) (((ext 5) . 1) ((v . 1) . 1)) (((ext 3) . 1
) ((v_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_x
ddt(1,4):=(*sq (((((ext 9) . 1) ((sig . 1) . 1)) (((ext 6) . 1) ((v . 1) . 1)) (
((ext 5) . 1) ((u . 1) . 1)) (((ext 4) . 1) ((v_x . 1) . 1)) (((ext 3) . 1) ((
u_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_2x
ddt(1,5):=(*sq (((((ext 8) . 1) . 1) (((ext 7) . 1) ((v . 1) . 1)) (((ext 5) . 1
) ((v_x . 1) . 2)) (((ext 3) . 1) ((v_2x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_2x
ddt(1,6):=(*sq (((((ext 11) . 1) ((sig . 1) . 1)) (((ext 8) . 1) ((v . 1) . 1))
(((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1) ((v_x . 1) . 2)) (((ext 5) . 1) ((
u_x . 1) . 2)) (((ext 4) . 1) ((v_2x . 1) . 1)) (((ext 3) . 1) ((u_2x . 1) . 1))
) . 1) t)
% component of ddt w.r.t. p_3x
ddt(1,7):=(*sq (((((ext 10) . 1) . 1) (((ext 9) . 1) ((v . 1) . 1)) (((ext 7) .
1) ((v_x . 1) . 3)) (((ext 5) . 1) ((v_2x . 1) . 3)) (((ext 3) . 1) ((v_3x . 1)
. 1))) . 1) t)
% component of ddt w.r.t. q_3x
ddt(1,8):=(*sq (((((ext 13) . 1) ((sig . 1) . 1)) (((ext 10) . 1) ((v . 1) . 1))
(((ext 9) . 1) ((u . 1) . 1)) (((ext 8) . 1) ((v_x . 1) . 3)) (((ext 7) . 1) ((
u_x . 1) . 3)) (((ext 6) . 1) ((v_2x . 1) . 3)) (((ext 5) . 1) ((u_2x . 1) . 3))
(((ext 4) . 1) ((v_3x . 1) . 1)) (((ext 3) . 1) ((u_3x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_4x
ddt(1,9):=(*sq (((((ext 12) . 1) . 1) (((ext 11) . 1) ((v . 1) . 1)) (((ext 9) .
1) ((v_x . 1) . 4)) (((ext 7) . 1) ((v_2x . 1) . 6)) (((ext 5) . 1) ((v_3x . 1)
. 4)) (((ext 3) . 1) ((v_4x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_4x
ddt(1,10):=(*sq (((((ext 15) . 1) ((sig . 1) . 1)) (((ext 12) . 1) ((v . 1) . 1)
) (((ext 11) . 1) ((u . 1) . 1)) (((ext 10) . 1) ((v_x . 1) . 4)) (((ext 9) . 1)
((u_x . 1) . 4)) (((ext 8) . 1) ((v_2x . 1) . 6)) (((ext 7) . 1) ((u_2x . 1) . 6
)) (((ext 6) . 1) ((v_3x . 1) . 4)) (((ext 5) . 1) ((u_3x . 1) . 4)) (((ext 4) .
1) ((v_4x . 1) . 1)) (((ext 3) . 1) ((u_4x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_5x
ddt(1,11):=(*sq (((((ext 14) . 1) . 1) (((ext 13) . 1) ((v . 1) . 1)) (((ext 11)
. 1) ((v_x . 1) . 5)) (((ext 9) . 1) ((v_2x . 1) . 10)) (((ext 7) . 1) ((v_3x .
1) . 10)) (((ext 5) . 1) ((v_4x . 1) . 5)) (((ext 3) . 1) ((v_5x . 1) . 1))) . 1
) t)
% component of ddt w.r.t. q_5x
ddt(1,12):=(*sq (((((ext 17) . 1) ((sig . 1) . 1)) (((ext 14) . 1) ((v . 1) . 1)
) (((ext 13) . 1) ((u . 1) . 1)) (((ext 12) . 1) ((v_x . 1) . 5)) (((ext 11) . 1
) ((u_x . 1) . 5)) (((ext 10) . 1) ((v_2x . 1) . 10)) (((ext 9) . 1) ((u_2x . 1)
. 10)) (((ext 8) . 1) ((v_3x . 1) . 10)) (((ext 7) . 1) ((u_3x . 1) . 10)) (((
ext 6) . 1) ((v_4x . 1) . 5)) (((ext 5) . 1) ((u_4x . 1) . 5)) (((ext 4) . 1) ((
v_5x . 1) . 1)) (((ext 3) . 1) ((u_5x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_6x
ddt(1,13):=(*sq (((((ext 16) . 1) . 1) (((ext 15) . 1) ((v . 1) . 1)) (((ext 13)
. 1) ((v_x . 1) . 6)) (((ext 11) . 1) ((v_2x . 1) . 15)) (((ext 9) . 1) ((v_3x .
1) . 20)) (((ext 7) . 1) ((v_4x . 1) . 15)) (((ext 5) . 1) ((v_5x . 1) . 6)) (((
ext 3) . 1) ((v_6x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_6x
ddt(1,14):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7x
ddt(1,15):=(*sq (((((ext 18) . 1) . 1) (((ext 17) . 1) ((v . 1) . 1)) (((ext 15)
. 1) ((v_x . 1) . 7)) (((ext 13) . 1) ((v_2x . 1) . 21)) (((ext 11) . 1) ((v_3x
. 1) . 35)) (((ext 9) . 1) ((v_4x . 1) . 35)) (((ext 7) . 1) ((v_5x . 1) . 21))
(((ext 5) . 1) ((v_6x . 1) . 7)) (((ext 3) . 1) ((v_7x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_7x
ddt(1,16):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8x
ddt(1,17):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8x
ddt(1,18):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t
ddt(1,19):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t
ddt(1,20):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t
ddt(1,21):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_xt
ddt(1,22):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t
ddt(1,23):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_xt
ddt(1,24):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t
ddt(1,25):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x2t
ddt(1,26):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2xt
ddt(1,27):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t
ddt(1,28):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x2t
ddt(1,29):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2xt
ddt(1,30):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t
ddt(1,31):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x3t
ddt(1,32):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x2t
ddt(1,33):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3xt
ddt(1,34):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t
ddt(1,35):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x3t
ddt(1,36):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x2t
ddt(1,37):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3xt
ddt(1,38):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t
ddt(1,39):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x4t
ddt(1,40):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x3t
ddt(1,41):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x2t
ddt(1,42):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4xt
ddt(1,43):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t
ddt(1,44):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x4t
ddt(1,45):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x3t
ddt(1,46):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x2t
ddt(1,47):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4xt
ddt(1,48):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t
ddt(1,49):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x5t
ddt(1,50):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x4t
ddt(1,51):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x3t
ddt(1,52):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x2t
ddt(1,53):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5xt
ddt(1,54):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t
ddt(1,55):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x5t
ddt(1,56):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x4t
ddt(1,57):=(*sq (((((ext 70) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x3t
ddt(1,58):=(*sq (((((ext 71) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x2t
ddt(1,59):=(*sq (((((ext 72) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5xt
ddt(1,60):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7t
ddt(1,61):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x6t
ddt(1,62):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x5t
ddt(1,63):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x4t
ddt(1,64):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x3t
ddt(1,65):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x2t
ddt(1,66):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6xt
ddt(1,67):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7t
ddt(1,68):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x6t
ddt(1,69):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x5t
ddt(1,70):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x4t
ddt(1,71):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x3t
ddt(1,72):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x2t
ddt(1,73):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6xt
ddt(1,74):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8t
ddt(1,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x7t
ddt(1,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x6t
ddt(1,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x5t
ddt(1,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x4t
ddt(1,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x3t
ddt(1,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x2t
ddt(1,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7xt
ddt(1,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8t
ddt(1,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x7t
ddt(1,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x6t
ddt(1,85):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x5t
ddt(1,86):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x4t
ddt(1,87):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x3t
ddt(1,88):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6x2t
ddt(1,89):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7xt
ddt(1,90):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
