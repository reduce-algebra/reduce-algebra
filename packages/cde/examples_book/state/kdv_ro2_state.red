% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t)
de!*:=((plus (times u u_x) u_3x))
% odd equation
principal_odd!*:=(q_t r_x r_t)
de_odd!*((plus (times q u_x) q_3x (times q_x u)) q (plus (times q u) q_2x))
% Settings:
indep_var!*:=(x t)
dep_var!*:=(u)
odd_var!*:=(q r)
deg_indep_var!*:=(-1 -3)
deg_dep_var!*:=(2)
deg_odd_var!*:=(2 1)
total_order:=10
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
1 6) ((2 6) (1 7) (1 7) (0 8))) ((0 7) ((1 7) (0 8))) ((8 0) ((9 0) (8 1) (8 1)
(7 2) (7 2) (6 3) (6 3) (5 4) (5 4) (4 5) (4 5) (3 6) (3 6) (2 7) (2 7) (1 8) (1
8) (0 9))) ((7 1) ((8 1) (7 2) (7 2) (6 3) (6 3) (5 4) (5 4) (4 5) (4 5) (3 6) (
3 6) (2 7) (2 7) (1 8) (1 8) (0 9))) ((6 2) ((7 2) (6 3) (6 3) (5 4) (5 4) (4 5)
(4 5) (3 6) (3 6) (2 7) (2 7) (1 8) (1 8) (0 9))) ((5 3) ((6 3) (5 4) (5 4) (4 5
) (4 5) (3 6) (3 6) (2 7) (2 7) (1 8) (1 8) (0 9))) ((4 4) ((5 4) (4 5) (4 5) (3
6) (3 6) (2 7) (2 7) (1 8) (1 8) (0 9))) ((3 5) ((4 5) (3 6) (3 6) (2 7) (2 7) (
1 8) (1 8) (0 9))) ((2 6) ((3 6) (2 7) (2 7) (1 8) (1 8) (0 9))) ((1 7) ((2 7) (
1 8) (1 8) (0 9))) ((0 8) ((1 8) (0 9))) ((9 0) ((10 0) (9 1) (9 1) (8 2) (8 2)
(7 3) (7 3) (6 4) (6 4) (5 5) (5 5) (4 6) (4 6) (3 7) (3 7) (2 8) (2 8) (1 9) (1
9) (0 10))) ((8 1) ((9 1) (8 2) (8 2) (7 3) (7 3) (6 4) (6 4) (5 5) (5 5) (4 6)
(4 6) (3 7) (3 7) (2 8) (2 8) (1 9) (1 9) (0 10))) ((7 2) ((8 2) (7 3) (7 3) (6
4) (6 4) (5 5) (5 5) (4 6) (4 6) (3 7) (3 7) (2 8) (2 8) (1 9) (1 9) (0 10))) ((
6 3) ((7 3) (6 4) (6 4) (5 5) (5 5) (4 6) (4 6) (3 7) (3 7) (2 8) (2 8) (1 9) (1
9) (0 10))) ((5 4) ((6 4) (5 5) (5 5) (4 6) (4 6) (3 7) (3 7) (2 8) (2 8) (1 9)
(1 9) (0 10))) ((4 5) ((5 5) (4 6) (4 6) (3 7) (3 7) (2 8) (2 8) (1 9) (1 9) (0
10))) ((3 6) ((4 6) (3 7) (3 7) (2 8) (2 8) (1 9) (1 9) (0 10))) ((2 7) ((3 7) (
2 8) (2 8) (1 9) (1 9) (0 10))) ((1 8) ((2 8) (1 9) (1 9) (0 10))) ((0 9) ((1 9)
(0 10))) ((10 0) nil) ((9 1) nil) ((8 2) nil) ((7 3) nil) ((6 4) nil) ((5 5) nil
) ((4 6) nil) ((3 7) nil) ((2 8) nil) ((1 9) nil) ((0 10) nil))
% all even derivatives in multiindex notation:
all_der_mind!*:=((u (0 0)) (u (1 0)) (u (0 1)) (u (2 0)) (u (1 1)) (u (0 2)) (u
(3 0)) (u (2 1)) (u (1 2)) (u (0 3)) (u (4 0)) (u (3 1)) (u (2 2)) (u (1 3)) (u
(0 4)) (u (5 0)) (u (4 1)) (u (3 2)) (u (2 3)) (u (1 4)) (u (0 5)) (u (6 0)) (u
(5 1)) (u (4 2)) (u (3 3)) (u (2 4)) (u (1 5)) (u (0 6)) (u (7 0)) (u (6 1)) (u
(5 2)) (u (4 3)) (u (3 4)) (u (2 5)) (u (1 6)) (u (0 7)) (u (8 0)) (u (7 1)) (u
(6 2)) (u (5 3)) (u (4 4)) (u (3 5)) (u (2 6)) (u (1 7)) (u (0 8)) (u (9 0)) (u
(8 1)) (u (7 2)) (u (6 3)) (u (5 4)) (u (4 5)) (u (3 6)) (u (2 7)) (u (1 8)) (u
(0 9)) (u (10 0)) (u (9 1)) (u (8 2)) (u (7 3)) (u (6 4)) (u (5 5)) (u (4 6)) (u
(3 7)) (u (2 8)) (u (1 9)) (u (0 10)))
% all odd derivatives in multiindex notation:
all_odd_mind!*:=((q (0 0)) (r (0 0)) (q (1 0)) (r (1 0)) (q (0 1)) (r (0 1)) (q
(2 0)) (r (2 0)) (q (1 1)) (r (1 1)) (q (0 2)) (r (0 2)) (q (3 0)) (r (3 0)) (q
(2 1)) (r (2 1)) (q (1 2)) (r (1 2)) (q (0 3)) (r (0 3)) (q (4 0)) (r (4 0)) (q
(3 1)) (r (3 1)) (q (2 2)) (r (2 2)) (q (1 3)) (r (1 3)) (q (0 4)) (r (0 4)) (q
(5 0)) (r (5 0)) (q (4 1)) (r (4 1)) (q (3 2)) (r (3 2)) (q (2 3)) (r (2 3)) (q
(1 4)) (r (1 4)) (q (0 5)) (r (0 5)) (q (6 0)) (r (6 0)) (q (5 1)) (r (5 1)) (q
(4 2)) (r (4 2)) (q (3 3)) (r (3 3)) (q (2 4)) (r (2 4)) (q (1 5)) (r (1 5)) (q
(0 6)) (r (0 6)) (q (7 0)) (r (7 0)) (q (6 1)) (r (6 1)) (q (5 2)) (r (5 2)) (q
(4 3)) (r (4 3)) (q (3 4)) (r (3 4)) (q (2 5)) (r (2 5)) (q (1 6)) (r (1 6)) (q
(0 7)) (r (0 7)) (q (8 0)) (r (8 0)) (q (7 1)) (r (7 1)) (q (6 2)) (r (6 2)) (q
(5 3)) (r (5 3)) (q (4 4)) (r (4 4)) (q (3 5)) (r (3 5)) (q (2 6)) (r (2 6)) (q
(1 7)) (r (1 7)) (q (0 8)) (r (0 8)) (q (9 0)) (r (9 0)) (q (8 1)) (r (8 1)) (q
(7 2)) (r (7 2)) (q (6 3)) (r (6 3)) (q (5 4)) (r (5 4)) (q (4 5)) (r (4 5)) (q
(3 6)) (r (3 6)) (q (2 7)) (r (2 7)) (q (1 8)) (r (1 8)) (q (0 9)) (r (0 9)) (q
(10 0)) (r (10 0)) (q (9 1)) (r (9 1)) (q (8 2)) (r (8 2)) (q (7 3)) (r (7 3)) (
q (6 4)) (r (6 4)) (q (5 5)) (r (5 5)) (q (4 6)) (r (4 6)) (q (3 7)) (r (3 7)) (
q (2 8)) (r (2 8)) (q (1 9)) (r (1 9)) (q (0 10)) (r (0 10)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_x u_t u_2x u_xt u_2t u_3x u_2xt u_x2t u_3t u_4x u_3xt u_2x2t
u_x3t u_4t u_5x u_4xt u_3x2t u_2x3t u_x4t u_5t u_6x u_5xt u_4x2t u_3x3t u_2x4t
u_x5t u_6t u_7x u_6xt u_5x2t u_4x3t u_3x4t u_2x5t u_x6t u_7t u_8x u_7xt u_6x2t
u_5x3t u_4x4t u_3x5t u_2x6t u_x7t u_8t u_9x u_8xt u_7x2t u_6x3t u_5x4t u_4x5t
u_3x6t u_2x7t u_x8t u_9t u_10x u_9xt u_8x2t u_7x3t u_6x4t u_5x5t u_4x6t u_3x7t
u_2x8t u_x9t u_10t)
% all odd derivatives in identifier notation:
all_odd_id!*:=(q r q_x r_x q_t r_t q_2x r_2x q_xt r_xt q_2t r_2t q_3x r_3x q_2xt
r_2xt q_x2t r_x2t q_3t r_3t q_4x r_4x q_3xt r_3xt q_2x2t r_2x2t q_x3t r_x3t q_4t
r_4t q_5x r_5x q_4xt r_4xt q_3x2t r_3x2t q_2x3t r_2x3t q_x4t r_x4t q_5t r_5t
q_6x r_6x q_5xt r_5xt q_4x2t r_4x2t q_3x3t r_3x3t q_2x4t r_2x4t q_x5t r_x5t q_6t
r_6t q_7x r_7x q_6xt r_6xt q_5x2t r_5x2t q_4x3t r_4x3t q_3x4t r_3x4t q_2x5t
r_2x5t q_x6t r_x6t q_7t r_7t q_8x r_8x q_7xt r_7xt q_6x2t r_6x2t q_5x3t r_5x3t
q_4x4t r_4x4t q_3x5t r_3x5t q_2x6t r_2x6t q_x7t r_x7t q_8t r_8t q_9x r_9x q_8xt
r_8xt q_7x2t r_7x2t q_6x3t r_6x3t q_5x4t r_5x4t q_4x5t r_4x5t q_3x6t r_3x6t
q_2x7t r_2x7t q_x8t r_x8t q_9t r_9t q_10x r_10x q_9xt r_9xt q_8x2t r_8x2t q_7x3t
r_7x3t q_6x4t r_6x4t q_5x5t r_5x5t q_4x6t r_4x6t q_3x7t r_3x7t q_2x8t r_2x8t
q_x9t r_x9t q_10t r_10t)
% number of all ext symbols:
n_all_ext:=168
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0)) (u_x u (1 0)) (u_t u (0 1)) (u_2x u (2 0)) (u_xt u
(1 1)) (u_2t u (0 2)) (u_3x u (3 0)) (u_2xt u (2 1)) (u_x2t u (1 2)) (u_3t u (0
3)) (u_4x u (4 0)) (u_3xt u (3 1)) (u_2x2t u (2 2)) (u_x3t u (1 3)) (u_4t u (0 4
)) (u_5x u (5 0)) (u_4xt u (4 1)) (u_3x2t u (3 2)) (u_2x3t u (2 3)) (u_x4t u (1
4)) (u_5t u (0 5)) (u_6x u (6 0)) (u_5xt u (5 1)) (u_4x2t u (4 2)) (u_3x3t u (3
3)) (u_2x4t u (2 4)) (u_x5t u (1 5)) (u_6t u (0 6)) (u_7x u (7 0)) (u_6xt u (6 1
)) (u_5x2t u (5 2)) (u_4x3t u (4 3)) (u_3x4t u (3 4)) (u_2x5t u (2 5)) (u_x6t u
(1 6)) (u_7t u (0 7)) (u_8x u (8 0)) (u_7xt u (7 1)) (u_6x2t u (6 2)) (u_5x3t u
(5 3)) (u_4x4t u (4 4)) (u_3x5t u (3 5)) (u_2x6t u (2 6)) (u_x7t u (1 7)) (u_8t
u (0 8)) (u_9x u (9 0)) (u_8xt u (8 1)) (u_7x2t u (7 2)) (u_6x3t u (6 3)) (
u_5x4t u (5 4)) (u_4x5t u (4 5)) (u_3x6t u (3 6)) (u_2x7t u (2 7)) (u_x8t u (1 8
)) (u_9t u (0 9)) (u_10x u (10 0)) (u_9xt u (9 1)) (u_8x2t u (8 2)) (u_7x3t u (7
3)) (u_6x4t u (6 4)) (u_5x5t u (5 5)) (u_4x6t u (4 6)) (u_3x7t u (3 7)) (u_2x8t
u (2 8)) (u_x9t u (1 9)) (u_10t u (0 10)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((q q (0 0)) (r r (0 0)) (q_x q (1 0)) (r_x r (1 0)) (q_t q
(0 1)) (r_t r (0 1)) (q_2x q (2 0)) (r_2x r (2 0)) (q_xt q (1 1)) (r_xt r (1 1))
(q_2t q (0 2)) (r_2t r (0 2)) (q_3x q (3 0)) (r_3x r (3 0)) (q_2xt q (2 1)) (
r_2xt r (2 1)) (q_x2t q (1 2)) (r_x2t r (1 2)) (q_3t q (0 3)) (r_3t r (0 3)) (
q_4x q (4 0)) (r_4x r (4 0)) (q_3xt q (3 1)) (r_3xt r (3 1)) (q_2x2t q (2 2)) (
r_2x2t r (2 2)) (q_x3t q (1 3)) (r_x3t r (1 3)) (q_4t q (0 4)) (r_4t r (0 4)) (
q_5x q (5 0)) (r_5x r (5 0)) (q_4xt q (4 1)) (r_4xt r (4 1)) (q_3x2t q (3 2)) (
r_3x2t r (3 2)) (q_2x3t q (2 3)) (r_2x3t r (2 3)) (q_x4t q (1 4)) (r_x4t r (1 4)
) (q_5t q (0 5)) (r_5t r (0 5)) (q_6x q (6 0)) (r_6x r (6 0)) (q_5xt q (5 1)) (
r_5xt r (5 1)) (q_4x2t q (4 2)) (r_4x2t r (4 2)) (q_3x3t q (3 3)) (r_3x3t r (3 3
)) (q_2x4t q (2 4)) (r_2x4t r (2 4)) (q_x5t q (1 5)) (r_x5t r (1 5)) (q_6t q (0
6)) (r_6t r (0 6)) (q_7x q (7 0)) (r_7x r (7 0)) (q_6xt q (6 1)) (r_6xt r (6 1))
(q_5x2t q (5 2)) (r_5x2t r (5 2)) (q_4x3t q (4 3)) (r_4x3t r (4 3)) (q_3x4t q (3
4)) (r_3x4t r (3 4)) (q_2x5t q (2 5)) (r_2x5t r (2 5)) (q_x6t q (1 6)) (r_x6t r
(1 6)) (q_7t q (0 7)) (r_7t r (0 7)) (q_8x q (8 0)) (r_8x r (8 0)) (q_7xt q (7 1
)) (r_7xt r (7 1)) (q_6x2t q (6 2)) (r_6x2t r (6 2)) (q_5x3t q (5 3)) (r_5x3t r
(5 3)) (q_4x4t q (4 4)) (r_4x4t r (4 4)) (q_3x5t q (3 5)) (r_3x5t r (3 5)) (
q_2x6t q (2 6)) (r_2x6t r (2 6)) (q_x7t q (1 7)) (r_x7t r (1 7)) (q_8t q (0 8))
(r_8t r (0 8)) (q_9x q (9 0)) (r_9x r (9 0)) (q_8xt q (8 1)) (r_8xt r (8 1)) (
q_7x2t q (7 2)) (r_7x2t r (7 2)) (q_6x3t q (6 3)) (r_6x3t r (6 3)) (q_5x4t q (5
4)) (r_5x4t r (5 4)) (q_4x5t q (4 5)) (r_4x5t r (4 5)) (q_3x6t q (3 6)) (r_3x6t
r (3 6)) (q_2x7t q (2 7)) (r_2x7t r (2 7)) (q_x8t q (1 8)) (r_x8t r (1 8)) (q_9t
q (0 9)) (r_9t r (0 9)) (q_10x q (10 0)) (r_10x r (10 0)) (q_9xt q (9 1)) (r_9xt
r (9 1)) (q_8x2t q (8 2)) (r_8x2t r (8 2)) (q_7x3t q (7 3)) (r_7x3t r (7 3)) (
q_6x4t q (6 4)) (r_6x4t r (6 4)) (q_5x5t q (5 5)) (r_5x5t r (5 5)) (q_4x6t q (4
6)) (r_4x6t r (4 6)) (q_3x7t q (3 7)) (r_3x7t r (3 7)) (q_2x8t q (2 8)) (r_2x8t
r (2 8)) (q_x9t q (1 9)) (r_x9t r (1 9)) (q_10t q (0 10)) (r_10t r (0 10)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (u_x . 1) (u_t . 1) (u_2x . 2) (u_xt . 2) (u_2t . 2) (
u_3x . 3) (u_2xt . 3) (u_x2t . 3) (u_3t . 3) (u_4x . 4) (u_3xt . 4) (u_2x2t . 4)
(u_x3t . 4) (u_4t . 4) (u_5x . 5) (u_4xt . 5) (u_3x2t . 5) (u_2x3t . 5) (u_x4t .
5) (u_5t . 5) (u_6x . 6) (u_5xt . 6) (u_4x2t . 6) (u_3x3t . 6) (u_2x4t . 6) (
u_x5t . 6) (u_6t . 6) (u_7x . 7) (u_6xt . 7) (u_5x2t . 7) (u_4x3t . 7) (u_3x4t .
7) (u_2x5t . 7) (u_x6t . 7) (u_7t . 7) (u_8x . 8) (u_7xt . 8) (u_6x2t . 8) (
u_5x3t . 8) (u_4x4t . 8) (u_3x5t . 8) (u_2x6t . 8) (u_x7t . 8) (u_8t . 8) (u_9x
. 9) (u_8xt . 9) (u_7x2t . 9) (u_6x3t . 9) (u_5x4t . 9) (u_4x5t . 9) (u_3x6t . 9
) (u_2x7t . 9) (u_x8t . 9) (u_9t . 9) (u_10x . 10) (u_9xt . 10) (u_8x2t . 10) (
u_7x3t . 10) (u_6x4t . 10) (u_5x5t . 10) (u_4x6t . 10) (u_3x7t . 10) (u_2x8t .
10) (u_x9t . 10) (u_10t . 10))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((q . 0) (r . 0) (q_x . 1) (r_x . 1) (q_t . 1) (r_t . 1) (
q_2x . 2) (r_2x . 2) (q_xt . 2) (r_xt . 2) (q_2t . 2) (r_2t . 2) (q_3x . 3) (
r_3x . 3) (q_2xt . 3) (r_2xt . 3) (q_x2t . 3) (r_x2t . 3) (q_3t . 3) (r_3t . 3)
(q_4x . 4) (r_4x . 4) (q_3xt . 4) (r_3xt . 4) (q_2x2t . 4) (r_2x2t . 4) (q_x3t .
4) (r_x3t . 4) (q_4t . 4) (r_4t . 4) (q_5x . 5) (r_5x . 5) (q_4xt . 5) (r_4xt .
5) (q_3x2t . 5) (r_3x2t . 5) (q_2x3t . 5) (r_2x3t . 5) (q_x4t . 5) (r_x4t . 5) (
q_5t . 5) (r_5t . 5) (q_6x . 6) (r_6x . 6) (q_5xt . 6) (r_5xt . 6) (q_4x2t . 6)
(r_4x2t . 6) (q_3x3t . 6) (r_3x3t . 6) (q_2x4t . 6) (r_2x4t . 6) (q_x5t . 6) (
r_x5t . 6) (q_6t . 6) (r_6t . 6) (q_7x . 7) (r_7x . 7) (q_6xt . 7) (r_6xt . 7) (
q_5x2t . 7) (r_5x2t . 7) (q_4x3t . 7) (r_4x3t . 7) (q_3x4t . 7) (r_3x4t . 7) (
q_2x5t . 7) (r_2x5t . 7) (q_x6t . 7) (r_x6t . 7) (q_7t . 7) (r_7t . 7) (q_8x . 8
) (r_8x . 8) (q_7xt . 8) (r_7xt . 8) (q_6x2t . 8) (r_6x2t . 8) (q_5x3t . 8) (
r_5x3t . 8) (q_4x4t . 8) (r_4x4t . 8) (q_3x5t . 8) (r_3x5t . 8) (q_2x6t . 8) (
r_2x6t . 8) (q_x7t . 8) (r_x7t . 8) (q_8t . 8) (r_8t . 8) (q_9x . 9) (r_9x . 9)
(q_8xt . 9) (r_8xt . 9) (q_7x2t . 9) (r_7x2t . 9) (q_6x3t . 9) (r_6x3t . 9) (
q_5x4t . 9) (r_5x4t . 9) (q_4x5t . 9) (r_4x5t . 9) (q_3x6t . 9) (r_3x6t . 9) (
q_2x7t . 9) (r_2x7t . 9) (q_x8t . 9) (r_x8t . 9) (q_9t . 9) (r_9t . 9) (q_10x .
10) (r_10x . 10) (q_9xt . 10) (r_9xt . 10) (q_8x2t . 10) (r_8x2t . 10) (q_7x3t .
10) (r_7x3t . 10) (q_6x4t . 10) (r_6x4t . 10) (q_5x5t . 10) (r_5x5t . 10) (
q_4x6t . 10) (r_4x6t . 10) (q_3x7t . 10) (r_3x7t . 10) (q_2x8t . 10) (r_2x8t .
10) (q_x9t . 10) (r_x9t . 10) (q_10t . 10) (r_10t . 10))
% list of even principal derivatives:
all_principal_der!*:=(u_t u_2t u_xt u_3t u_x2t u_2xt u_4t u_x3t u_2x2t u_3xt
u_5t u_x4t u_2x3t u_3x2t u_4xt u_6t u_x5t u_2x4t u_3x3t u_4x2t u_5xt u_7t u_x6t
u_2x5t u_3x4t u_4x3t u_5x2t u_6xt u_8t u_x7t u_2x6t u_3x5t u_4x4t u_5x3t u_6x2t
u_7xt u_9t u_x8t u_2x7t u_3x6t u_4x5t u_5x4t u_6x3t u_7x2t u_8xt u_10t u_x9t
u_2x8t u_3x7t u_4x6t u_5x5t u_6x4t u_7x3t u_8x2t u_9xt)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_x u_2x u_3x u_4x u_5x u_6x u_7x u_8x u_9x u_10x)
% list of odd principal derivatives:
all_principal_odd!*:=(q_t r_t r_x q_2t q_xt r_2t r_xt r_xt r_2x q_3t q_x2t q_2xt
r_3t r_x2t r_2xt r_x2t r_2xt r_3x q_4t q_x3t q_2x2t q_3xt r_4t r_x3t r_2x2t
r_3xt r_x3t r_2x2t r_3xt r_4x q_5t q_x4t q_2x3t q_3x2t q_4xt r_5t r_x4t r_2x3t
r_3x2t r_4xt r_x4t r_2x3t r_3x2t r_4xt r_5x q_6t q_x5t q_2x4t q_3x3t q_4x2t
q_5xt r_6t r_x5t r_2x4t r_3x3t r_4x2t r_5xt r_x5t r_2x4t r_3x3t r_4x2t r_5xt
r_6x q_7t q_x6t q_2x5t q_3x4t q_4x3t q_5x2t q_6xt r_7t r_x6t r_2x5t r_3x4t
r_4x3t r_5x2t r_6xt r_x6t r_2x5t r_3x4t r_4x3t r_5x2t r_6xt r_7x q_8t q_x7t
q_2x6t q_3x5t q_4x4t q_5x3t q_6x2t q_7xt r_8t r_x7t r_2x6t r_3x5t r_4x4t r_5x3t
r_6x2t r_7xt r_x7t r_2x6t r_3x5t r_4x4t r_5x3t r_6x2t r_7xt r_8x q_9t q_x8t
q_2x7t q_3x6t q_4x5t q_5x4t q_6x3t q_7x2t q_8xt r_9t r_x8t r_2x7t r_3x6t r_4x5t
r_5x4t r_6x3t r_7x2t r_8xt r_x8t r_2x7t r_3x6t r_4x5t r_5x4t r_6x3t r_7x2t r_8xt
r_9x q_10t q_x9t q_2x8t q_3x7t q_4x6t q_5x5t q_6x4t q_7x3t q_8x2t q_9xt r_10t
r_x9t r_2x8t r_3x7t r_4x6t r_5x5t r_6x4t r_7x3t r_8x2t r_9xt r_10x)
q_t = (ext 13)
r_t = (ext 14)
r_x = (ext 15)
q_2t = (ext 16)
q_xt = (ext 17)
r_2t = (ext 18)
r_xt = (ext 19)
r_xt = (ext 19)
r_2x = (ext 21)
q_3t = (ext 22)
q_x2t = (ext 23)
q_2xt = (ext 24)
r_3t = (ext 25)
r_x2t = (ext 26)
r_2xt = (ext 27)
r_x2t = (ext 26)
r_2xt = (ext 27)
r_3x = (ext 30)
q_4t = (ext 31)
q_x3t = (ext 32)
q_2x2t = (ext 33)
q_3xt = (ext 34)
r_4t = (ext 35)
r_x3t = (ext 36)
r_2x2t = (ext 37)
r_3xt = (ext 38)
r_x3t = (ext 36)
r_2x2t = (ext 37)
r_3xt = (ext 38)
r_4x = (ext 42)
q_5t = (ext 43)
q_x4t = (ext 44)
q_2x3t = (ext 45)
q_3x2t = (ext 46)
q_4xt = (ext 47)
r_5t = (ext 48)
r_x4t = (ext 49)
r_2x3t = (ext 50)
r_3x2t = (ext 51)
r_4xt = (ext 52)
r_x4t = (ext 49)
r_2x3t = (ext 50)
r_3x2t = (ext 51)
r_4xt = (ext 52)
r_5x = (ext 57)
q_6t = (ext 58)
q_x5t = (ext 59)
q_2x4t = (ext 60)
q_3x3t = (ext 61)
q_4x2t = (ext 62)
q_5xt = (ext 63)
r_6t = (ext 64)
r_x5t = (ext 65)
r_2x4t = (ext 66)
r_3x3t = (ext 67)
r_4x2t = (ext 68)
r_5xt = (ext 69)
r_x5t = (ext 65)
r_2x4t = (ext 66)
r_3x3t = (ext 67)
r_4x2t = (ext 68)
r_5xt = (ext 69)
r_6x = (ext 75)
q_7t = (ext 76)
q_x6t = (ext 77)
q_2x5t = (ext 78)
q_3x4t = (ext 79)
q_4x3t = (ext 80)
q_5x2t = (ext 81)
q_6xt = (ext 82)
r_7t = (ext 83)
r_x6t = (ext 84)
r_2x5t = (ext 85)
r_3x4t = (ext 86)
r_4x3t = (ext 87)
r_5x2t = (ext 88)
r_6xt = (ext 89)
r_x6t = (ext 84)
r_2x5t = (ext 85)
r_3x4t = (ext 86)
r_4x3t = (ext 87)
r_5x2t = (ext 88)
r_6xt = (ext 89)
r_7x = (ext 96)
q_8t = (ext 97)
q_x7t = (ext 98)
q_2x6t = (ext 99)
q_3x5t = (ext 100)
q_4x4t = (ext 101)
q_5x3t = (ext 102)
q_6x2t = (ext 103)
q_7xt = (ext 104)
r_8t = (ext 105)
r_x7t = (ext 106)
r_2x6t = (ext 107)
r_3x5t = (ext 108)
r_4x4t = (ext 109)
r_5x3t = (ext 110)
r_6x2t = (ext 111)
r_7xt = (ext 112)
r_x7t = (ext 106)
r_2x6t = (ext 107)
r_3x5t = (ext 108)
r_4x4t = (ext 109)
r_5x3t = (ext 110)
r_6x2t = (ext 111)
r_7xt = (ext 112)
r_8x = (ext 120)
q_9t = (ext 121)
q_x8t = (ext 122)
q_2x7t = (ext 123)
q_3x6t = (ext 124)
q_4x5t = (ext 125)
q_5x4t = (ext 126)
q_6x3t = (ext 127)
q_7x2t = (ext 128)
q_8xt = (ext 129)
r_9t = (ext 130)
r_x8t = (ext 131)
r_2x7t = (ext 132)
r_3x6t = (ext 133)
r_4x5t = (ext 134)
r_5x4t = (ext 135)
r_6x3t = (ext 136)
r_7x2t = (ext 137)
r_8xt = (ext 138)
r_x8t = (ext 131)
r_2x7t = (ext 132)
r_3x6t = (ext 133)
r_4x5t = (ext 134)
r_5x4t = (ext 135)
r_6x3t = (ext 136)
r_7x2t = (ext 137)
r_8xt = (ext 138)
r_9x = (ext 147)
q_10t = (ext 148)
q_x9t = (ext 149)
q_2x8t = (ext 150)
q_3x7t = (ext 151)
q_4x6t = (ext 152)
q_5x5t = (ext 153)
q_6x4t = (ext 154)
q_7x3t = (ext 155)
q_8x2t = (ext 156)
q_9xt = (ext 157)
r_10t = (ext 158)
r_x9t = (ext 159)
r_2x8t = (ext 160)
r_3x7t = (ext 161)
r_4x6t = (ext 162)
r_5x5t = (ext 163)
r_6x4t = (ext 164)
r_7x3t = (ext 165)
r_8x2t = (ext 166)
r_9xt = (ext 167)
r_10x = (ext 168)
% list of odd parametric derivatives:
all_parametric_odd!*:=(q r q_x q_2x q_3x q_4x q_5x q_6x q_7x q_8x q_9x q_10x)
q = (ext 1)
r = (ext 2)
q_x = (ext 3)
q_2x = (ext 4)
q_3x = (ext 5)
q_4x = (ext 6)
q_5x = (ext 7)
q_6x = (ext 8)
q_7x = (ext 9)
q_8x = (ext 10)
q_9x = (ext 11)
q_10x = (ext 12)
% number of ext principal derivatives:
n_all_principal_ext:=156
% number of ext parametric derivatives:
n_all_parametric_ext:=12
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddt)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 u_xt) (ddt 0 5 u_2xt) (ddt 0
6 u_3xt) (ddt 0 7 u_4xt) (ddt 0 8 u_5xt) (ddt 0 9 u_6xt) (ddt 0 10 u_7xt) (ddt 0
11 u_8xt) (ddt 0 12 u_9xt))
primary_diffcon_odd_tot!*:=((ddx 1 2 r_x) (ddt 1 1 q_t) (ddt 1 2 r_t) (ddt 1 3
q_xt) (ddt 1 4 q_2xt) (ddt 1 5 q_3xt) (ddt 1 6 q_4xt) (ddt 1 7 q_5xt) (ddt 1 8
q_6xt) (ddt 1 9 q_7xt) (ddt 1 10 q_8xt) (ddt 1 11 q_9xt))
primary_diffcon_der!*:=(u_xt u_2xt u_3xt u_4xt u_5xt u_6xt u_7xt u_8xt u_9xt)
primary_diffcon_odd!*:=(q_xt q_2xt q_3xt q_4xt q_5xt q_6xt q_7xt q_8xt q_9xt)
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_9xt (*sq ((((letop . 1) . 1)) . 1) nil)) (u_8xt (*sq ((((
letop . 1) . 1)) . 1) nil)) (u_7xt (*sq ((((u . 1) ((u_8x . 1) . 1)) ((u_10x . 1
) . 1) ((u_2x . 1) ((u_6x . 1) . 28)) ((u_3x . 1) ((u_5x . 1) . 56)) ((u_4x . 2)
. 35) ((u_7x . 1) ((u_x . 1) . 8))) . 1) nil)) (u_6xt (*sq ((((u . 1) ((u_7x . 1
) . 1)) ((u_2x . 1) ((u_5x . 1) . 21)) ((u_3x . 1) ((u_4x . 1) . 35)) ((u_6x . 1
) ((u_x . 1) . 7)) ((u_9x . 1) . 1)) . 1) nil)) (u_5xt (*sq ((((u . 1) ((u_6x .
1) . 1)) ((u_2x . 1) ((u_4x . 1) . 15)) ((u_3x . 2) . 10) ((u_5x . 1) ((u_x . 1)
. 6)) ((u_8x . 1) . 1)) . 1) nil)) (u_4xt (*sq ((((u . 1) ((u_5x . 1) . 1)) ((
u_2x . 1) ((u_3x . 1) . 10)) ((u_4x . 1) ((u_x . 1) . 5)) ((u_7x . 1) . 1)) . 1)
nil)) (u_3xt (*sq ((((u . 1) ((u_4x . 1) . 1)) ((u_2x . 2) . 3) ((u_3x . 1) ((
u_x . 1) . 4)) ((u_6x . 1) . 1)) . 1) nil)) (u_2xt (*sq ((((u . 1) ((u_3x . 1) .
1)) ((u_2x . 1) ((u_x . 1) . 3)) ((u_5x . 1) . 1)) . 1) nil)) (u_xt (*sq ((((u .
1) ((u_2x . 1) . 1)) ((u_4x . 1) . 1) ((u_x . 2) . 1)) . 1) nil)) (u_t (plus (
times u u_x) u_3x)))
diffcon_odd!*:=((q_9xt (*sq ((((letop . 1) . 1)) . 1) nil)) (q_8xt (*sq ((((
letop . 1) . 1)) . 1) nil)) (q_7xt (*sq (((((ext 12) . 1) . 1) (((ext 10) . 1) (
(u . 1) . 1)) (((ext 9) . 1) ((u_x . 1) . 8)) (((ext 8) . 1) ((u_2x . 1) . 28))
(((ext 7) . 1) ((u_3x . 1) . 56)) (((ext 6) . 1) ((u_4x . 1) . 70)) (((ext 5) .
1) ((u_5x . 1) . 56)) (((ext 4) . 1) ((u_6x . 1) . 28)) (((ext 3) . 1) ((u_7x .
1) . 8)) (((ext 1) . 1) ((u_8x . 1) . 1))) . 1) nil)) (q_6xt (*sq (((((ext 11) .
1) . 1) (((ext 9) . 1) ((u . 1) . 1)) (((ext 8) . 1) ((u_x . 1) . 7)) (((ext 7)
. 1) ((u_2x . 1) . 21)) (((ext 6) . 1) ((u_3x . 1) . 35)) (((ext 5) . 1) ((u_4x
. 1) . 35)) (((ext 4) . 1) ((u_5x . 1) . 21)) (((ext 3) . 1) ((u_6x . 1) . 7)) (
((ext 1) . 1) ((u_7x . 1) . 1))) . 1) nil)) (q_5xt (*sq (((((ext 10) . 1) . 1) (
((ext 8) . 1) ((u . 1) . 1)) (((ext 7) . 1) ((u_x . 1) . 6)) (((ext 6) . 1) ((
u_2x . 1) . 15)) (((ext 5) . 1) ((u_3x . 1) . 20)) (((ext 4) . 1) ((u_4x . 1) .
15)) (((ext 3) . 1) ((u_5x . 1) . 6)) (((ext 1) . 1) ((u_6x . 1) . 1))) . 1) nil
)) (q_4xt (*sq (((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1
) ((u_x . 1) . 5)) (((ext 5) . 1) ((u_2x . 1) . 10)) (((ext 4) . 1) ((u_3x . 1)
. 10)) (((ext 3) . 1) ((u_4x . 1) . 5)) (((ext 1) . 1) ((u_5x . 1) . 1))) . 1)
nil)) (q_3xt (*sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5)
. 1) ((u_x . 1) . 4)) (((ext 4) . 1) ((u_2x . 1) . 6)) (((ext 3) . 1) ((u_3x . 1
) . 4)) (((ext 1) . 1) ((u_4x . 1) . 1))) . 1) nil)) (q_2xt (*sq (((((ext 7) . 1
) . 1) (((ext 5) . 1) ((u . 1) . 1)) (((ext 4) . 1) ((u_x . 1) . 3)) (((ext 3) .
1) ((u_2x . 1) . 3)) (((ext 1) . 1) ((u_3x . 1) . 1))) . 1) nil)) (q_xt (*sq (((
((ext 6) . 1) . 1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1) ((u_x . 1) . 2))
(((ext 1) . 1) ((u_2x . 1) . 1))) . 1) nil)) (r_t (*sq (((((ext 4) . 1) . 1) (((
ext 1) . 1) ((u . 1) . 1))) . 1) nil)) (r_x (*sq (((((ext 1) . 1) . 1)) . 1) nil
)) (q_t (*sq (((((ext 5) . 1) . 1) (((ext 3) . 1) ((u . 1) . 1)) (((ext 1) . 1)
((u_x . 1) . 1))) . 1) nil)))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_9xt u_8xt u_7xt u_6xt u_5xt u_4xt u_3xt u_2xt u_xt u_t)
diffcon_comp_odd!*:=(q_9xt q_8xt q_7xt q_6xt q_5xt q_4xt q_3xt q_2xt q_xt r_t
r_x q_t)
diffcon_comp_ext!*:=((ext 157) (ext 129) (ext 104) (ext 82) (ext 63) (ext 47) (
ext 34) (ext 24) (ext 17) (ext 14) (ext 15) (ext 13))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_9xt *sq ((((letop . 1) . 1)) . 1) nil) (u_8xt *sq ((((
letop . 1) . 1)) . 1) nil) (u_7xt *sq ((((u . 1) ((u_8x . 1) . 1)) ((u_10x . 1)
. 1) ((u_2x . 1) ((u_6x . 1) . 28)) ((u_3x . 1) ((u_5x . 1) . 56)) ((u_4x . 2) .
35) ((u_7x . 1) ((u_x . 1) . 8))) . 1) nil) (u_6xt *sq ((((u . 1) ((u_7x . 1) .
1)) ((u_2x . 1) ((u_5x . 1) . 21)) ((u_3x . 1) ((u_4x . 1) . 35)) ((u_6x . 1) ((
u_x . 1) . 7)) ((u_9x . 1) . 1)) . 1) nil) (u_5xt *sq ((((u . 1) ((u_6x . 1) . 1
)) ((u_2x . 1) ((u_4x . 1) . 15)) ((u_3x . 2) . 10) ((u_5x . 1) ((u_x . 1) . 6))
((u_8x . 1) . 1)) . 1) nil) (u_4xt *sq ((((u . 1) ((u_5x . 1) . 1)) ((u_2x . 1)
((u_3x . 1) . 10)) ((u_4x . 1) ((u_x . 1) . 5)) ((u_7x . 1) . 1)) . 1) nil) (
u_3xt *sq ((((u . 1) ((u_4x . 1) . 1)) ((u_2x . 2) . 3) ((u_3x . 1) ((u_x . 1) .
4)) ((u_6x . 1) . 1)) . 1) nil) (u_2xt *sq ((((u . 1) ((u_3x . 1) . 1)) ((u_2x .
1) ((u_x . 1) . 3)) ((u_5x . 1) . 1)) . 1) nil) (u_xt *sq ((((u . 1) ((u_2x . 1)
. 1)) ((u_4x . 1) . 1) ((u_x . 2) . 1)) . 1) nil) (u_t *sq ((((u . 1) ((u_x . 1)
. 1)) ((u_3x . 1) . 1)) . 1) nil))
diffcon_param_ext!*:=(((ext 157) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 129)
*sq ((((letop . 1) . 1)) . 1) nil) ((ext 104) *sq (((((ext 12) . 1) . 1) (((ext
10) . 1) ((u . 1) . 1)) (((ext 9) . 1) ((u_x . 1) . 8)) (((ext 8) . 1) ((u_2x .
1) . 28)) (((ext 7) . 1) ((u_3x . 1) . 56)) (((ext 6) . 1) ((u_4x . 1) . 70)) ((
(ext 5) . 1) ((u_5x . 1) . 56)) (((ext 4) . 1) ((u_6x . 1) . 28)) (((ext 3) . 1)
((u_7x . 1) . 8)) (((ext 1) . 1) ((u_8x . 1) . 1))) . 1) nil) ((ext 82) *sq ((((
(ext 11) . 1) . 1) (((ext 9) . 1) ((u . 1) . 1)) (((ext 8) . 1) ((u_x . 1) . 7))
(((ext 7) . 1) ((u_2x . 1) . 21)) (((ext 6) . 1) ((u_3x . 1) . 35)) (((ext 5) .
1) ((u_4x . 1) . 35)) (((ext 4) . 1) ((u_5x . 1) . 21)) (((ext 3) . 1) ((u_6x .
1) . 7)) (((ext 1) . 1) ((u_7x . 1) . 1))) . 1) nil) ((ext 63) *sq (((((ext 10)
. 1) . 1) (((ext 8) . 1) ((u . 1) . 1)) (((ext 7) . 1) ((u_x . 1) . 6)) (((ext 6
) . 1) ((u_2x . 1) . 15)) (((ext 5) . 1) ((u_3x . 1) . 20)) (((ext 4) . 1) ((
u_4x . 1) . 15)) (((ext 3) . 1) ((u_5x . 1) . 6)) (((ext 1) . 1) ((u_6x . 1) . 1
))) . 1) nil) ((ext 47) *sq (((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1))
(((ext 6) . 1) ((u_x . 1) . 5)) (((ext 5) . 1) ((u_2x . 1) . 10)) (((ext 4) . 1)
((u_3x . 1) . 10)) (((ext 3) . 1) ((u_4x . 1) . 5)) (((ext 1) . 1) ((u_5x . 1) .
1))) . 1) nil) ((ext 34) *sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1))
(((ext 5) . 1) ((u_x . 1) . 4)) (((ext 4) . 1) ((u_2x . 1) . 6)) (((ext 3) . 1)
((u_3x . 1) . 4)) (((ext 1) . 1) ((u_4x . 1) . 1))) . 1) nil) ((ext 24) *sq ((((
(ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1)) (((ext 4) . 1) ((u_x . 1) . 3))
(((ext 3) . 1) ((u_2x . 1) . 3)) (((ext 1) . 1) ((u_3x . 1) . 1))) . 1) nil) ((
ext 17) *sq (((((ext 6) . 1) . 1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1) (
(u_x . 1) . 2)) (((ext 1) . 1) ((u_2x . 1) . 1))) . 1) nil) ((ext 14) *sq (((((
ext 4) . 1) . 1) (((ext 1) . 1) ((u . 1) . 1))) . 1) nil) ((ext 15) *sq (((((ext
1) . 1) . 1)) . 1) nil) ((ext 13) *sq (((((ext 5) . 1) . 1) (((ext 3) . 1) ((u .
1) . 1)) (((ext 1) . 1) ((u_x . 1) . 1))) . 1) nil))
% Coefficients of total derivatives:
% component of ddx w.r.t. x
ddx(0,1):=1
% component of ddx w.r.t. t
ddx(0,2):=0
% component of ddx w.r.t. u
ddx(0,3):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x
ddx(0,4):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x
ddx(0,5):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x
ddx(0,6):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x
ddx(0,7):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x
ddx(0,8):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x
ddx(0,9):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x
ddx(0,10):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x
ddx(0,11):=(*sq ((((u_9x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9x
ddx(0,12):=(*sq ((((u_10x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_10x
ddx(0,13):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t
ddx(0,14):=(*sq ((((u_xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,15):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_xt
ddx(0,16):=(*sq ((((u_2xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t
ddx(0,17):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x2t
ddx(0,18):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2xt
ddx(0,19):=(*sq ((((u_3xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t
ddx(0,20):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x3t
ddx(0,21):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x2t
ddx(0,22):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3xt
ddx(0,23):=(*sq ((((u_4xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t
ddx(0,24):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x4t
ddx(0,25):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x3t
ddx(0,26):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x2t
ddx(0,27):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4xt
ddx(0,28):=(*sq ((((u_5xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t
ddx(0,29):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x5t
ddx(0,30):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x4t
ddx(0,31):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x3t
ddx(0,32):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x2t
ddx(0,33):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5xt
ddx(0,34):=(*sq ((((u_6xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t
ddx(0,35):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x6t
ddx(0,36):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x5t
ddx(0,37):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x4t
ddx(0,38):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x3t
ddx(0,39):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x2t
ddx(0,40):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6xt
ddx(0,41):=(*sq ((((u_7xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8t
ddx(0,42):=(*sq ((((u_x8t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x7t
ddx(0,43):=(*sq ((((u_2x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x6t
ddx(0,44):=(*sq ((((u_3x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x5t
ddx(0,45):=(*sq ((((u_4x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x4t
ddx(0,46):=(*sq ((((u_5x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x3t
ddx(0,47):=(*sq ((((u_6x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x2t
ddx(0,48):=(*sq ((((u_7x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7xt
ddx(0,49):=(*sq ((((u_8xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9t
ddx(0,50):=(*sq ((((u_x9t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x8t
ddx(0,51):=(*sq ((((u_2x8t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x7t
ddx(0,52):=(*sq ((((u_3x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x6t
ddx(0,53):=(*sq ((((u_4x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x5t
ddx(0,54):=(*sq ((((u_5x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x4t
ddx(0,55):=(*sq ((((u_6x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x3t
ddx(0,56):=(*sq ((((u_7x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x2t
ddx(0,57):=(*sq ((((u_8x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8xt
ddx(0,58):=(*sq ((((u_9xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_10t
ddx(0,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x9t
ddx(0,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x8t
ddx(0,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x7t
ddx(0,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x6t
ddx(0,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x5t
ddx(0,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x4t
ddx(0,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x3t
ddx(0,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x2t
ddx(0,67):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9xt
ddx(0,68):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q
ddx(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r
ddx(1,2):=(*sq (((((ext 1) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x
ddx(1,3):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x
ddx(1,4):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x
ddx(1,5):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x
ddx(1,6):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x
ddx(1,7):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x
ddx(1,8):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x
ddx(1,9):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x
ddx(1,10):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9x
ddx(1,11):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_10x
ddx(1,12):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t
ddx(1,13):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_t
ddx(1,14):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x
ddx(1,15):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t
ddx(1,16):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_xt
ddx(1,17):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2t
ddx(1,18):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_xt
ddx(1,19):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_xt
ddx(1,20):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x
ddx(1,21):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t
ddx(1,22):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x2t
ddx(1,23):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2xt
ddx(1,24):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3t
ddx(1,25):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x2t
ddx(1,26):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2xt
ddx(1,27):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x2t
ddx(1,28):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2xt
ddx(1,29):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x
ddx(1,30):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t
ddx(1,31):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x3t
ddx(1,32):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x2t
ddx(1,33):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3xt
ddx(1,34):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4t
ddx(1,35):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x3t
ddx(1,36):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x2t
ddx(1,37):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3xt
ddx(1,38):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x3t
ddx(1,39):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x2t
ddx(1,40):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3xt
ddx(1,41):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x
ddx(1,42):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t
ddx(1,43):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x4t
ddx(1,44):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x3t
ddx(1,45):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x2t
ddx(1,46):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4xt
ddx(1,47):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5t
ddx(1,48):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x4t
ddx(1,49):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x3t
ddx(1,50):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x2t
ddx(1,51):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4xt
ddx(1,52):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x4t
ddx(1,53):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x3t
ddx(1,54):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x2t
ddx(1,55):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4xt
ddx(1,56):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x
ddx(1,57):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t
ddx(1,58):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x5t
ddx(1,59):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x4t
ddx(1,60):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x3t
ddx(1,61):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x2t
ddx(1,62):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5xt
ddx(1,63):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6t
ddx(1,64):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x5t
ddx(1,65):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x4t
ddx(1,66):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x3t
ddx(1,67):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x2t
ddx(1,68):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5xt
ddx(1,69):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x5t
ddx(1,70):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x4t
ddx(1,71):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x3t
ddx(1,72):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x2t
ddx(1,73):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5xt
ddx(1,74):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x
ddx(1,75):=(*sq (((((ext 96) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7t
ddx(1,76):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x6t
ddx(1,77):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x5t
ddx(1,78):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x4t
ddx(1,79):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x3t
ddx(1,80):=(*sq (((((ext 102) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x2t
ddx(1,81):=(*sq (((((ext 103) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6xt
ddx(1,82):=(*sq (((((ext 104) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7t
ddx(1,83):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x6t
ddx(1,84):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x5t
ddx(1,85):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x4t
ddx(1,86):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x3t
ddx(1,87):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x2t
ddx(1,88):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6xt
ddx(1,89):=(*sq (((((ext 112) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x6t
ddx(1,90):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x5t
ddx(1,91):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x4t
ddx(1,92):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x3t
ddx(1,93):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x2t
ddx(1,94):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6xt
ddx(1,95):=(*sq (((((ext 112) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7x
ddx(1,96):=(*sq (((((ext 120) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8t
ddx(1,97):=(*sq (((((ext 122) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x7t
ddx(1,98):=(*sq (((((ext 123) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x6t
ddx(1,99):=(*sq (((((ext 124) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x5t
ddx(1,100):=(*sq (((((ext 125) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x4t
ddx(1,101):=(*sq (((((ext 126) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x3t
ddx(1,102):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x2t
ddx(1,103):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7xt
ddx(1,104):=(*sq (((((ext 129) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_8t
ddx(1,105):=(*sq (((((ext 131) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x7t
ddx(1,106):=(*sq (((((ext 132) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x6t
ddx(1,107):=(*sq (((((ext 133) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x5t
ddx(1,108):=(*sq (((((ext 134) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x4t
ddx(1,109):=(*sq (((((ext 135) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x3t
ddx(1,110):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x2t
ddx(1,111):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7xt
ddx(1,112):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x7t
ddx(1,113):=(*sq (((((ext 132) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x6t
ddx(1,114):=(*sq (((((ext 133) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x5t
ddx(1,115):=(*sq (((((ext 134) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x4t
ddx(1,116):=(*sq (((((ext 135) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x3t
ddx(1,117):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x2t
ddx(1,118):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7xt
ddx(1,119):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_8x
ddx(1,120):=(*sq (((((ext 147) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9t
ddx(1,121):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x8t
ddx(1,122):=(*sq (((((ext 150) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x7t
ddx(1,123):=(*sq (((((ext 151) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x6t
ddx(1,124):=(*sq (((((ext 152) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x5t
ddx(1,125):=(*sq (((((ext 153) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x4t
ddx(1,126):=(*sq (((((ext 154) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x3t
ddx(1,127):=(*sq (((((ext 155) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x2t
ddx(1,128):=(*sq (((((ext 156) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8xt
ddx(1,129):=(*sq (((((ext 157) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_9t
ddx(1,130):=(*sq (((((ext 159) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x8t
ddx(1,131):=(*sq (((((ext 160) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x7t
ddx(1,132):=(*sq (((((ext 161) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x6t
ddx(1,133):=(*sq (((((ext 162) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x5t
ddx(1,134):=(*sq (((((ext 163) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x4t
ddx(1,135):=(*sq (((((ext 164) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x3t
ddx(1,136):=(*sq (((((ext 165) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7x2t
ddx(1,137):=(*sq (((((ext 166) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_8xt
ddx(1,138):=(*sq (((((ext 167) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x8t
ddx(1,139):=(*sq (((((ext 160) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x7t
ddx(1,140):=(*sq (((((ext 161) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x6t
ddx(1,141):=(*sq (((((ext 162) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x5t
ddx(1,142):=(*sq (((((ext 163) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x4t
ddx(1,143):=(*sq (((((ext 164) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x3t
ddx(1,144):=(*sq (((((ext 165) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7x2t
ddx(1,145):=(*sq (((((ext 166) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_8xt
ddx(1,146):=(*sq (((((ext 167) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_9x
ddx(1,147):=(*sq (((((ext 168) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_10t
ddx(1,148):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x9t
ddx(1,149):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x8t
ddx(1,150):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x7t
ddx(1,151):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x6t
ddx(1,152):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x5t
ddx(1,153):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x4t
ddx(1,154):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x3t
ddx(1,155):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x2t
ddx(1,156):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9xt
ddx(1,157):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_10t
ddx(1,158):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x9t
ddx(1,159):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x8t
ddx(1,160):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x7t
ddx(1,161):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x6t
ddx(1,162):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x5t
ddx(1,163):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x4t
ddx(1,164):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7x3t
ddx(1,165):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_8x2t
ddx(1,166):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_9xt
ddx(1,167):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_10x
ddx(1,168):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. x
ddt(0,1):=0
% component of ddt w.r.t. t
ddt(0,2):=1
% component of ddt w.r.t. u
ddt(0,3):=(*sq ((((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,4):=(*sq ((((u . 1) ((u_2x . 1) . 1)) ((u_4x . 1) . 1) ((u_x . 2) . 1)) .
1) t)
% component of ddt w.r.t. u_2x
ddt(0,5):=(*sq ((((u . 1) ((u_3x . 1) . 1)) ((u_2x . 1) ((u_x . 1) . 3)) ((u_5x
. 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,6):=(*sq ((((u . 1) ((u_4x . 1) . 1)) ((u_2x . 2) . 3) ((u_3x . 1) ((u_x .
1) . 4)) ((u_6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,7):=(*sq ((((u . 1) ((u_5x . 1) . 1)) ((u_2x . 1) ((u_3x . 1) . 10)) ((
u_4x . 1) ((u_x . 1) . 5)) ((u_7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,8):=(*sq ((((u . 1) ((u_6x . 1) . 1)) ((u_2x . 1) ((u_4x . 1) . 15)) ((
u_3x . 2) . 10) ((u_5x . 1) ((u_x . 1) . 6)) ((u_8x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,9):=(*sq ((((u . 1) ((u_7x . 1) . 1)) ((u_2x . 1) ((u_5x . 1) . 21)) ((
u_3x . 1) ((u_4x . 1) . 35)) ((u_6x . 1) ((u_x . 1) . 7)) ((u_9x . 1) . 1)) . 1)
t)
% component of ddt w.r.t. u_7x
ddt(0,10):=(*sq ((((u . 1) ((u_8x . 1) . 1)) ((u_10x . 1) . 1) ((u_2x . 1) ((
u_6x . 1) . 28)) ((u_3x . 1) ((u_5x . 1) . 56)) ((u_4x . 2) . 35) ((u_7x . 1) ((
u_x . 1) . 8))) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_9x
ddt(0,12):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_10x
ddt(0,13):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,14):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,15):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_xt
ddt(0,16):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,17):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x2t
ddt(0,18):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2xt
ddt(0,19):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,20):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x3t
ddt(0,21):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x2t
ddt(0,22):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3xt
ddt(0,23):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,24):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x4t
ddt(0,25):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x3t
ddt(0,26):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x2t
ddt(0,27):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4xt
ddt(0,28):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,29):=(*sq ((((u_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x5t
ddt(0,30):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x4t
ddt(0,31):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x3t
ddt(0,32):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x2t
ddt(0,33):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5xt
ddt(0,34):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t
ddt(0,35):=(*sq ((((u_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x6t
ddt(0,36):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x5t
ddt(0,37):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x4t
ddt(0,38):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x3t
ddt(0,39):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x2t
ddt(0,40):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6xt
ddt(0,41):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t
ddt(0,42):=(*sq ((((u_9t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x7t
ddt(0,43):=(*sq ((((u_x8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x6t
ddt(0,44):=(*sq ((((u_2x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x5t
ddt(0,45):=(*sq ((((u_3x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x4t
ddt(0,46):=(*sq ((((u_4x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x3t
ddt(0,47):=(*sq ((((u_5x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x2t
ddt(0,48):=(*sq ((((u_6x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7xt
ddt(0,49):=(*sq ((((u_7x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_9t
ddt(0,50):=(*sq ((((u_10t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x8t
ddt(0,51):=(*sq ((((u_x9t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x7t
ddt(0,52):=(*sq ((((u_2x8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x6t
ddt(0,53):=(*sq ((((u_3x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x5t
ddt(0,54):=(*sq ((((u_4x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x4t
ddt(0,55):=(*sq ((((u_5x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x3t
ddt(0,56):=(*sq ((((u_6x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7x2t
ddt(0,57):=(*sq ((((u_7x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8xt
ddt(0,58):=(*sq ((((u_8x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_10t
ddt(0,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x9t
ddt(0,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x8t
ddt(0,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x7t
ddt(0,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x6t
ddt(0,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x5t
ddt(0,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x4t
ddt(0,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7x3t
ddt(0,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8x2t
ddt(0,67):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_9xt
ddt(0,68):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q
ddt(1,1):=(*sq (((((ext 5) . 1) . 1) (((ext 3) . 1) ((u . 1) . 1)) (((ext 1) . 1
) ((u_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. r
ddt(1,2):=(*sq (((((ext 4) . 1) . 1) (((ext 1) . 1) ((u . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_x
ddt(1,3):=(*sq (((((ext 6) . 1) . 1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1
) ((u_x . 1) . 2)) (((ext 1) . 1) ((u_2x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_2x
ddt(1,4):=(*sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1)) (((ext 4) . 1
) ((u_x . 1) . 3)) (((ext 3) . 1) ((u_2x . 1) . 3)) (((ext 1) . 1) ((u_3x . 1) .
1))) . 1) t)
% component of ddt w.r.t. q_3x
ddt(1,5):=(*sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1
) ((u_x . 1) . 4)) (((ext 4) . 1) ((u_2x . 1) . 6)) (((ext 3) . 1) ((u_3x . 1) .
4)) (((ext 1) . 1) ((u_4x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_4x
ddt(1,6):=(*sq (((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1
) ((u_x . 1) . 5)) (((ext 5) . 1) ((u_2x . 1) . 10)) (((ext 4) . 1) ((u_3x . 1)
. 10)) (((ext 3) . 1) ((u_4x . 1) . 5)) (((ext 1) . 1) ((u_5x . 1) . 1))) . 1) t
)
% component of ddt w.r.t. q_5x
ddt(1,7):=(*sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((u . 1) . 1)) (((ext 7) .
1) ((u_x . 1) . 6)) (((ext 6) . 1) ((u_2x . 1) . 15)) (((ext 5) . 1) ((u_3x . 1)
. 20)) (((ext 4) . 1) ((u_4x . 1) . 15)) (((ext 3) . 1) ((u_5x . 1) . 6)) (((ext
1) . 1) ((u_6x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_6x
ddt(1,8):=(*sq (((((ext 11) . 1) . 1) (((ext 9) . 1) ((u . 1) . 1)) (((ext 8) .
1) ((u_x . 1) . 7)) (((ext 7) . 1) ((u_2x . 1) . 21)) (((ext 6) . 1) ((u_3x . 1)
. 35)) (((ext 5) . 1) ((u_4x . 1) . 35)) (((ext 4) . 1) ((u_5x . 1) . 21)) (((
ext 3) . 1) ((u_6x . 1) . 7)) (((ext 1) . 1) ((u_7x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_7x
ddt(1,9):=(*sq (((((ext 12) . 1) . 1) (((ext 10) . 1) ((u . 1) . 1)) (((ext 9) .
1) ((u_x . 1) . 8)) (((ext 8) . 1) ((u_2x . 1) . 28)) (((ext 7) . 1) ((u_3x . 1)
. 56)) (((ext 6) . 1) ((u_4x . 1) . 70)) (((ext 5) . 1) ((u_5x . 1) . 56)) (((
ext 4) . 1) ((u_6x . 1) . 28)) (((ext 3) . 1) ((u_7x . 1) . 8)) (((ext 1) . 1) (
(u_8x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_8x
ddt(1,10):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_9x
ddt(1,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_10x
ddt(1,12):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t
ddt(1,13):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_t
ddt(1,14):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x
ddt(1,15):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t
ddt(1,16):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_xt
ddt(1,17):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2t
ddt(1,18):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_xt
ddt(1,19):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_xt
ddt(1,20):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x
ddt(1,21):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t
ddt(1,22):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x2t
ddt(1,23):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2xt
ddt(1,24):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3t
ddt(1,25):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x2t
ddt(1,26):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2xt
ddt(1,27):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x2t
ddt(1,28):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2xt
ddt(1,29):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x
ddt(1,30):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t
ddt(1,31):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x3t
ddt(1,32):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x2t
ddt(1,33):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3xt
ddt(1,34):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4t
ddt(1,35):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x3t
ddt(1,36):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x2t
ddt(1,37):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3xt
ddt(1,38):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x3t
ddt(1,39):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x2t
ddt(1,40):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3xt
ddt(1,41):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x
ddt(1,42):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t
ddt(1,43):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x4t
ddt(1,44):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x3t
ddt(1,45):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x2t
ddt(1,46):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4xt
ddt(1,47):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5t
ddt(1,48):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x4t
ddt(1,49):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x3t
ddt(1,50):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x2t
ddt(1,51):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4xt
ddt(1,52):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x4t
ddt(1,53):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x3t
ddt(1,54):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x2t
ddt(1,55):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4xt
ddt(1,56):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x
ddt(1,57):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t
ddt(1,58):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x5t
ddt(1,59):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x4t
ddt(1,60):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x3t
ddt(1,61):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x2t
ddt(1,62):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5xt
ddt(1,63):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6t
ddt(1,64):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x5t
ddt(1,65):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x4t
ddt(1,66):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x3t
ddt(1,67):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x2t
ddt(1,68):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5xt
ddt(1,69):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x5t
ddt(1,70):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x4t
ddt(1,71):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x3t
ddt(1,72):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x2t
ddt(1,73):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5xt
ddt(1,74):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6x
ddt(1,75):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7t
ddt(1,76):=(*sq (((((ext 97) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x6t
ddt(1,77):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x5t
ddt(1,78):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x4t
ddt(1,79):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x3t
ddt(1,80):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x2t
ddt(1,81):=(*sq (((((ext 102) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6xt
ddt(1,82):=(*sq (((((ext 103) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7t
ddt(1,83):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x6t
ddt(1,84):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x5t
ddt(1,85):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x4t
ddt(1,86):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x3t
ddt(1,87):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x2t
ddt(1,88):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6xt
ddt(1,89):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x6t
ddt(1,90):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x5t
ddt(1,91):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x4t
ddt(1,92):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x3t
ddt(1,93):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x2t
ddt(1,94):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6xt
ddt(1,95):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7x
ddt(1,96):=(*sq (((((ext 112) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8t
ddt(1,97):=(*sq (((((ext 121) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x7t
ddt(1,98):=(*sq (((((ext 122) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x6t
ddt(1,99):=(*sq (((((ext 123) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x5t
ddt(1,100):=(*sq (((((ext 124) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x4t
ddt(1,101):=(*sq (((((ext 125) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x3t
ddt(1,102):=(*sq (((((ext 126) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6x2t
ddt(1,103):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7xt
ddt(1,104):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_8t
ddt(1,105):=(*sq (((((ext 130) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x7t
ddt(1,106):=(*sq (((((ext 131) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x6t
ddt(1,107):=(*sq (((((ext 132) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x5t
ddt(1,108):=(*sq (((((ext 133) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x4t
ddt(1,109):=(*sq (((((ext 134) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x3t
ddt(1,110):=(*sq (((((ext 135) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6x2t
ddt(1,111):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7xt
ddt(1,112):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x7t
ddt(1,113):=(*sq (((((ext 131) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x6t
ddt(1,114):=(*sq (((((ext 132) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x5t
ddt(1,115):=(*sq (((((ext 133) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x4t
ddt(1,116):=(*sq (((((ext 134) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x3t
ddt(1,117):=(*sq (((((ext 135) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6x2t
ddt(1,118):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7xt
ddt(1,119):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_8x
ddt(1,120):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_9t
ddt(1,121):=(*sq (((((ext 148) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x8t
ddt(1,122):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x7t
ddt(1,123):=(*sq (((((ext 150) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x6t
ddt(1,124):=(*sq (((((ext 151) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x5t
ddt(1,125):=(*sq (((((ext 152) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x4t
ddt(1,126):=(*sq (((((ext 153) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6x3t
ddt(1,127):=(*sq (((((ext 154) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7x2t
ddt(1,128):=(*sq (((((ext 155) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8xt
ddt(1,129):=(*sq (((((ext 156) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_9t
ddt(1,130):=(*sq (((((ext 158) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x8t
ddt(1,131):=(*sq (((((ext 159) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x7t
ddt(1,132):=(*sq (((((ext 160) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x6t
ddt(1,133):=(*sq (((((ext 161) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x5t
ddt(1,134):=(*sq (((((ext 162) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x4t
ddt(1,135):=(*sq (((((ext 163) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6x3t
ddt(1,136):=(*sq (((((ext 164) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7x2t
ddt(1,137):=(*sq (((((ext 165) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_8xt
ddt(1,138):=(*sq (((((ext 166) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x8t
ddt(1,139):=(*sq (((((ext 159) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x7t
ddt(1,140):=(*sq (((((ext 160) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x6t
ddt(1,141):=(*sq (((((ext 161) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x5t
ddt(1,142):=(*sq (((((ext 162) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x4t
ddt(1,143):=(*sq (((((ext 163) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6x3t
ddt(1,144):=(*sq (((((ext 164) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7x2t
ddt(1,145):=(*sq (((((ext 165) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_8xt
ddt(1,146):=(*sq (((((ext 166) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_9x
ddt(1,147):=(*sq (((((ext 167) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_10t
ddt(1,148):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x9t
ddt(1,149):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x8t
ddt(1,150):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x7t
ddt(1,151):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x6t
ddt(1,152):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x5t
ddt(1,153):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6x4t
ddt(1,154):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7x3t
ddt(1,155):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8x2t
ddt(1,156):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_9xt
ddt(1,157):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_10t
ddt(1,158):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x9t
ddt(1,159):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x8t
ddt(1,160):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x7t
ddt(1,161):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x6t
ddt(1,162):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x5t
ddt(1,163):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6x4t
ddt(1,164):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7x3t
ddt(1,165):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_8x2t
ddt(1,166):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_9xt
ddt(1,167):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_10x
ddt(1,168):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
