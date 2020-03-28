% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t)
de!*:=((plus (times u u_x) u_3x))
% odd equation
principal_odd!*:=(p_t)
de_odd!*((plus p_3x (times p_x u)))
% Settings:
indep_var!*:=(x t)
dep_var!*:=(u)
odd_var!*:=(p)
deg_indep_var!*:=(-1 -3)
deg_dep_var!*:=(2)
deg_odd_var!*:=(1)
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
all_odd_mind!*:=((p (0 0)) (p (1 0)) (p (0 1)) (p (2 0)) (p (1 1)) (p (0 2)) (p
(3 0)) (p (2 1)) (p (1 2)) (p (0 3)) (p (4 0)) (p (3 1)) (p (2 2)) (p (1 3)) (p
(0 4)) (p (5 0)) (p (4 1)) (p (3 2)) (p (2 3)) (p (1 4)) (p (0 5)) (p (6 0)) (p
(5 1)) (p (4 2)) (p (3 3)) (p (2 4)) (p (1 5)) (p (0 6)) (p (7 0)) (p (6 1)) (p
(5 2)) (p (4 3)) (p (3 4)) (p (2 5)) (p (1 6)) (p (0 7)) (p (8 0)) (p (7 1)) (p
(6 2)) (p (5 3)) (p (4 4)) (p (3 5)) (p (2 6)) (p (1 7)) (p (0 8)) (p (9 0)) (p
(8 1)) (p (7 2)) (p (6 3)) (p (5 4)) (p (4 5)) (p (3 6)) (p (2 7)) (p (1 8)) (p
(0 9)) (p (10 0)) (p (9 1)) (p (8 2)) (p (7 3)) (p (6 4)) (p (5 5)) (p (4 6)) (p
(3 7)) (p (2 8)) (p (1 9)) (p (0 10)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_x u_t u_2x u_xt u_2t u_3x u_2xt u_x2t u_3t u_4x u_3xt u_2x2t
u_x3t u_4t u_5x u_4xt u_3x2t u_2x3t u_x4t u_5t u_6x u_5xt u_4x2t u_3x3t u_2x4t
u_x5t u_6t u_7x u_6xt u_5x2t u_4x3t u_3x4t u_2x5t u_x6t u_7t u_8x u_7xt u_6x2t
u_5x3t u_4x4t u_3x5t u_2x6t u_x7t u_8t u_9x u_8xt u_7x2t u_6x3t u_5x4t u_4x5t
u_3x6t u_2x7t u_x8t u_9t u_10x u_9xt u_8x2t u_7x3t u_6x4t u_5x5t u_4x6t u_3x7t
u_2x8t u_x9t u_10t)
% all odd derivatives in identifier notation:
all_odd_id!*:=(p p_x p_t p_2x p_xt p_2t p_3x p_2xt p_x2t p_3t p_4x p_3xt p_2x2t
p_x3t p_4t p_5x p_4xt p_3x2t p_2x3t p_x4t p_5t p_6x p_5xt p_4x2t p_3x3t p_2x4t
p_x5t p_6t p_7x p_6xt p_5x2t p_4x3t p_3x4t p_2x5t p_x6t p_7t p_8x p_7xt p_6x2t
p_5x3t p_4x4t p_3x5t p_2x6t p_x7t p_8t p_9x p_8xt p_7x2t p_6x3t p_5x4t p_4x5t
p_3x6t p_2x7t p_x8t p_9t p_10x p_9xt p_8x2t p_7x3t p_6x4t p_5x5t p_4x6t p_3x7t
p_2x8t p_x9t p_10t)
% number of all ext symbols:
n_all_ext:=66
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
i2m_jetspace_odd!*:=((p p (0 0)) (p_x p (1 0)) (p_t p (0 1)) (p_2x p (2 0)) (
p_xt p (1 1)) (p_2t p (0 2)) (p_3x p (3 0)) (p_2xt p (2 1)) (p_x2t p (1 2)) (
p_3t p (0 3)) (p_4x p (4 0)) (p_3xt p (3 1)) (p_2x2t p (2 2)) (p_x3t p (1 3)) (
p_4t p (0 4)) (p_5x p (5 0)) (p_4xt p (4 1)) (p_3x2t p (3 2)) (p_2x3t p (2 3)) (
p_x4t p (1 4)) (p_5t p (0 5)) (p_6x p (6 0)) (p_5xt p (5 1)) (p_4x2t p (4 2)) (
p_3x3t p (3 3)) (p_2x4t p (2 4)) (p_x5t p (1 5)) (p_6t p (0 6)) (p_7x p (7 0)) (
p_6xt p (6 1)) (p_5x2t p (5 2)) (p_4x3t p (4 3)) (p_3x4t p (3 4)) (p_2x5t p (2 5
)) (p_x6t p (1 6)) (p_7t p (0 7)) (p_8x p (8 0)) (p_7xt p (7 1)) (p_6x2t p (6 2)
) (p_5x3t p (5 3)) (p_4x4t p (4 4)) (p_3x5t p (3 5)) (p_2x6t p (2 6)) (p_x7t p (
1 7)) (p_8t p (0 8)) (p_9x p (9 0)) (p_8xt p (8 1)) (p_7x2t p (7 2)) (p_6x3t p (
6 3)) (p_5x4t p (5 4)) (p_4x5t p (4 5)) (p_3x6t p (3 6)) (p_2x7t p (2 7)) (p_x8t
p (1 8)) (p_9t p (0 9)) (p_10x p (10 0)) (p_9xt p (9 1)) (p_8x2t p (8 2)) (
p_7x3t p (7 3)) (p_6x4t p (6 4)) (p_5x5t p (5 5)) (p_4x6t p (4 6)) (p_3x7t p (3
7)) (p_2x8t p (2 8)) (p_x9t p (1 9)) (p_10t p (0 10)))
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
i2o_jetspace_odd!*:=((p . 0) (p_x . 1) (p_t . 1) (p_2x . 2) (p_xt . 2) (p_2t . 2
) (p_3x . 3) (p_2xt . 3) (p_x2t . 3) (p_3t . 3) (p_4x . 4) (p_3xt . 4) (p_2x2t .
4) (p_x3t . 4) (p_4t . 4) (p_5x . 5) (p_4xt . 5) (p_3x2t . 5) (p_2x3t . 5) (
p_x4t . 5) (p_5t . 5) (p_6x . 6) (p_5xt . 6) (p_4x2t . 6) (p_3x3t . 6) (p_2x4t .
6) (p_x5t . 6) (p_6t . 6) (p_7x . 7) (p_6xt . 7) (p_5x2t . 7) (p_4x3t . 7) (
p_3x4t . 7) (p_2x5t . 7) (p_x6t . 7) (p_7t . 7) (p_8x . 8) (p_7xt . 8) (p_6x2t .
8) (p_5x3t . 8) (p_4x4t . 8) (p_3x5t . 8) (p_2x6t . 8) (p_x7t . 8) (p_8t . 8) (
p_9x . 9) (p_8xt . 9) (p_7x2t . 9) (p_6x3t . 9) (p_5x4t . 9) (p_4x5t . 9) (
p_3x6t . 9) (p_2x7t . 9) (p_x8t . 9) (p_9t . 9) (p_10x . 10) (p_9xt . 10) (
p_8x2t . 10) (p_7x3t . 10) (p_6x4t . 10) (p_5x5t . 10) (p_4x6t . 10) (p_3x7t .
10) (p_2x8t . 10) (p_x9t . 10) (p_10t . 10))
% list of even principal derivatives:
all_principal_der!*:=(u_t u_2t u_xt u_3t u_x2t u_2xt u_4t u_x3t u_2x2t u_3xt
u_5t u_x4t u_2x3t u_3x2t u_4xt u_6t u_x5t u_2x4t u_3x3t u_4x2t u_5xt u_7t u_x6t
u_2x5t u_3x4t u_4x3t u_5x2t u_6xt u_8t u_x7t u_2x6t u_3x5t u_4x4t u_5x3t u_6x2t
u_7xt u_9t u_x8t u_2x7t u_3x6t u_4x5t u_5x4t u_6x3t u_7x2t u_8xt u_10t u_x9t
u_2x8t u_3x7t u_4x6t u_5x5t u_6x4t u_7x3t u_8x2t u_9xt)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_x u_2x u_3x u_4x u_5x u_6x u_7x u_8x u_9x u_10x)
% list of odd principal derivatives:
all_principal_odd!*:=(p_t p_2t p_xt p_3t p_x2t p_2xt p_4t p_x3t p_2x2t p_3xt
p_5t p_x4t p_2x3t p_3x2t p_4xt p_6t p_x5t p_2x4t p_3x3t p_4x2t p_5xt p_7t p_x6t
p_2x5t p_3x4t p_4x3t p_5x2t p_6xt p_8t p_x7t p_2x6t p_3x5t p_4x4t p_5x3t p_6x2t
p_7xt p_9t p_x8t p_2x7t p_3x6t p_4x5t p_5x4t p_6x3t p_7x2t p_8xt p_10t p_x9t
p_2x8t p_3x7t p_4x6t p_5x5t p_6x4t p_7x3t p_8x2t p_9xt)
p_t = (ext 12)
p_2t = (ext 13)
p_xt = (ext 14)
p_3t = (ext 15)
p_x2t = (ext 16)
p_2xt = (ext 17)
p_4t = (ext 18)
p_x3t = (ext 19)
p_2x2t = (ext 20)
p_3xt = (ext 21)
p_5t = (ext 22)
p_x4t = (ext 23)
p_2x3t = (ext 24)
p_3x2t = (ext 25)
p_4xt = (ext 26)
p_6t = (ext 27)
p_x5t = (ext 28)
p_2x4t = (ext 29)
p_3x3t = (ext 30)
p_4x2t = (ext 31)
p_5xt = (ext 32)
p_7t = (ext 33)
p_x6t = (ext 34)
p_2x5t = (ext 35)
p_3x4t = (ext 36)
p_4x3t = (ext 37)
p_5x2t = (ext 38)
p_6xt = (ext 39)
p_8t = (ext 40)
p_x7t = (ext 41)
p_2x6t = (ext 42)
p_3x5t = (ext 43)
p_4x4t = (ext 44)
p_5x3t = (ext 45)
p_6x2t = (ext 46)
p_7xt = (ext 47)
p_9t = (ext 48)
p_x8t = (ext 49)
p_2x7t = (ext 50)
p_3x6t = (ext 51)
p_4x5t = (ext 52)
p_5x4t = (ext 53)
p_6x3t = (ext 54)
p_7x2t = (ext 55)
p_8xt = (ext 56)
p_10t = (ext 57)
p_x9t = (ext 58)
p_2x8t = (ext 59)
p_3x7t = (ext 60)
p_4x6t = (ext 61)
p_5x5t = (ext 62)
p_6x4t = (ext 63)
p_7x3t = (ext 64)
p_8x2t = (ext 65)
p_9xt = (ext 66)
% list of odd parametric derivatives:
all_parametric_odd!*:=(p p_x p_2x p_3x p_4x p_5x p_6x p_7x p_8x p_9x p_10x)
p = (ext 1)
p_x = (ext 2)
p_2x = (ext 3)
p_3x = (ext 4)
p_4x = (ext 5)
p_5x = (ext 6)
p_6x = (ext 7)
p_7x = (ext 8)
p_8x = (ext 9)
p_9x = (ext 10)
p_10x = (ext 11)
% number of ext principal derivatives:
n_all_principal_ext:=55
% number of ext parametric derivatives:
n_all_parametric_ext:=11
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddt)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 u_xt) (ddt 0 5 u_2xt) (ddt 0
6 u_3xt) (ddt 0 7 u_4xt) (ddt 0 8 u_5xt) (ddt 0 9 u_6xt) (ddt 0 10 u_7xt) (ddt 0
11 u_8xt) (ddt 0 12 u_9xt))
primary_diffcon_odd_tot!*:=((ddt 1 1 p_t) (ddt 1 2 p_xt) (ddt 1 3 p_2xt) (ddt 1
4 p_3xt) (ddt 1 5 p_4xt) (ddt 1 6 p_5xt) (ddt 1 7 p_6xt) (ddt 1 8 p_7xt) (ddt 1
9 p_8xt) (ddt 1 10 p_9xt))
primary_diffcon_der!*:=(u_xt u_2xt u_3xt u_4xt u_5xt u_6xt u_7xt u_8xt u_9xt)
primary_diffcon_odd!*:=(p_xt p_2xt p_3xt p_4xt p_5xt p_6xt p_7xt p_8xt p_9xt)
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
diffcon_odd!*:=((p_9xt (*sq ((((letop . 1) . 1)) . 1) nil)) (p_8xt (*sq ((((
letop . 1) . 1)) . 1) nil)) (p_7xt (*sq (((((ext 11) . 1) . 1) (((ext 9) . 1) ((
u . 1) . 1)) (((ext 8) . 1) ((u_x . 1) . 7)) (((ext 7) . 1) ((u_2x . 1) . 21)) (
((ext 6) . 1) ((u_3x . 1) . 35)) (((ext 5) . 1) ((u_4x . 1) . 35)) (((ext 4) . 1
) ((u_5x . 1) . 21)) (((ext 3) . 1) ((u_6x . 1) . 7)) (((ext 2) . 1) ((u_7x . 1)
. 1))) . 1) nil)) (p_6xt (*sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((u . 1) . 1
)) (((ext 7) . 1) ((u_x . 1) . 6)) (((ext 6) . 1) ((u_2x . 1) . 15)) (((ext 5) .
1) ((u_3x . 1) . 20)) (((ext 4) . 1) ((u_4x . 1) . 15)) (((ext 3) . 1) ((u_5x .
1) . 6)) (((ext 2) . 1) ((u_6x . 1) . 1))) . 1) nil)) (p_5xt (*sq (((((ext 9) .
1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1) ((u_x . 1) . 5)) (((ext 5)
. 1) ((u_2x . 1) . 10)) (((ext 4) . 1) ((u_3x . 1) . 10)) (((ext 3) . 1) ((u_4x
. 1) . 5)) (((ext 2) . 1) ((u_5x . 1) . 1))) . 1) nil)) (p_4xt (*sq (((((ext 8)
. 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1) ((u_x . 1) . 4)) (((ext 4
) . 1) ((u_2x . 1) . 6)) (((ext 3) . 1) ((u_3x . 1) . 4)) (((ext 2) . 1) ((u_4x
. 1) . 1))) . 1) nil)) (p_3xt (*sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1)
. 1)) (((ext 4) . 1) ((u_x . 1) . 3)) (((ext 3) . 1) ((u_2x . 1) . 3)) (((ext 2)
. 1) ((u_3x . 1) . 1))) . 1) nil)) (p_2xt (*sq (((((ext 6) . 1) . 1) (((ext 4) .
1) ((u . 1) . 1)) (((ext 3) . 1) ((u_x . 1) . 2)) (((ext 2) . 1) ((u_2x . 1) . 1
))) . 1) nil)) (p_xt (*sq (((((ext 5) . 1) . 1) (((ext 3) . 1) ((u . 1) . 1)) ((
(ext 2) . 1) ((u_x . 1) . 1))) . 1) nil)) (p_t (*sq (((((ext 4) . 1) . 1) (((ext
2) . 1) ((u . 1) . 1))) . 1) nil)))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_9xt u_8xt u_7xt u_6xt u_5xt u_4xt u_3xt u_2xt u_xt u_t)
diffcon_comp_odd!*:=(p_9xt p_8xt p_7xt p_6xt p_5xt p_4xt p_3xt p_2xt p_xt p_t)
diffcon_comp_ext!*:=((ext 66) (ext 56) (ext 47) (ext 39) (ext 32) (ext 26) (ext
21) (ext 17) (ext 14) (ext 12))
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
diffcon_param_ext!*:=(((ext 66) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 56) *sq
((((letop . 1) . 1)) . 1) nil) ((ext 47) *sq (((((ext 11) . 1) . 1) (((ext 9) .
1) ((u . 1) . 1)) (((ext 8) . 1) ((u_x . 1) . 7)) (((ext 7) . 1) ((u_2x . 1) .
21)) (((ext 6) . 1) ((u_3x . 1) . 35)) (((ext 5) . 1) ((u_4x . 1) . 35)) (((ext
4) . 1) ((u_5x . 1) . 21)) (((ext 3) . 1) ((u_6x . 1) . 7)) (((ext 2) . 1) ((
u_7x . 1) . 1))) . 1) nil) ((ext 39) *sq (((((ext 10) . 1) . 1) (((ext 8) . 1) (
(u . 1) . 1)) (((ext 7) . 1) ((u_x . 1) . 6)) (((ext 6) . 1) ((u_2x . 1) . 15))
(((ext 5) . 1) ((u_3x . 1) . 20)) (((ext 4) . 1) ((u_4x . 1) . 15)) (((ext 3) .
1) ((u_5x . 1) . 6)) (((ext 2) . 1) ((u_6x . 1) . 1))) . 1) nil) ((ext 32) *sq (
((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1) ((u_x . 1) . 5
)) (((ext 5) . 1) ((u_2x . 1) . 10)) (((ext 4) . 1) ((u_3x . 1) . 10)) (((ext 3)
. 1) ((u_4x . 1) . 5)) (((ext 2) . 1) ((u_5x . 1) . 1))) . 1) nil) ((ext 26) *sq
(((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1) ((u_x . 1) .
4)) (((ext 4) . 1) ((u_2x . 1) . 6)) (((ext 3) . 1) ((u_3x . 1) . 4)) (((ext 2)
. 1) ((u_4x . 1) . 1))) . 1) nil) ((ext 21) *sq (((((ext 7) . 1) . 1) (((ext 5)
. 1) ((u . 1) . 1)) (((ext 4) . 1) ((u_x . 1) . 3)) (((ext 3) . 1) ((u_2x . 1) .
3)) (((ext 2) . 1) ((u_3x . 1) . 1))) . 1) nil) ((ext 17) *sq (((((ext 6) . 1) .
1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1) ((u_x . 1) . 2)) (((ext 2) . 1)
((u_2x . 1) . 1))) . 1) nil) ((ext 14) *sq (((((ext 5) . 1) . 1) (((ext 3) . 1)
((u . 1) . 1)) (((ext 2) . 1) ((u_x . 1) . 1))) . 1) nil) ((ext 12) *sq (((((ext
4) . 1) . 1) (((ext 2) . 1) ((u . 1) . 1))) . 1) nil))
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
% component of ddx w.r.t. p
ddx(1,1):=(*sq (((((ext 2) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x
ddx(1,2):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x
ddx(1,3):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x
ddx(1,4):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x
ddx(1,5):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x
ddx(1,6):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x
ddx(1,7):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x
ddx(1,8):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8x
ddx(1,9):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_9x
ddx(1,10):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_10x
ddx(1,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t
ddx(1,12):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t
ddx(1,13):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_xt
ddx(1,14):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t
ddx(1,15):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x2t
ddx(1,16):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2xt
ddx(1,17):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t
ddx(1,18):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x3t
ddx(1,19):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x2t
ddx(1,20):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3xt
ddx(1,21):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t
ddx(1,22):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x4t
ddx(1,23):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x3t
ddx(1,24):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x2t
ddx(1,25):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4xt
ddx(1,26):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t
ddx(1,27):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x5t
ddx(1,28):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x4t
ddx(1,29):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x3t
ddx(1,30):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x2t
ddx(1,31):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5xt
ddx(1,32):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7t
ddx(1,33):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x6t
ddx(1,34):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x5t
ddx(1,35):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x4t
ddx(1,36):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x3t
ddx(1,37):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x2t
ddx(1,38):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6xt
ddx(1,39):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8t
ddx(1,40):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x7t
ddx(1,41):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x6t
ddx(1,42):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x5t
ddx(1,43):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x4t
ddx(1,44):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x3t
ddx(1,45):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x2t
ddx(1,46):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7xt
ddx(1,47):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_9t
ddx(1,48):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x8t
ddx(1,49):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x7t
ddx(1,50):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x6t
ddx(1,51):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x5t
ddx(1,52):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x4t
ddx(1,53):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x3t
ddx(1,54):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x2t
ddx(1,55):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8xt
ddx(1,56):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_10t
ddx(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x9t
ddx(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x8t
ddx(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x7t
ddx(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x6t
ddx(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x5t
ddx(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x4t
ddx(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x3t
ddx(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8x2t
ddx(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_9xt
ddx(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
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
% component of ddt w.r.t. p
ddt(1,1):=(*sq (((((ext 4) . 1) . 1) (((ext 2) . 1) ((u . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_x
ddt(1,2):=(*sq (((((ext 5) . 1) . 1) (((ext 3) . 1) ((u . 1) . 1)) (((ext 2) . 1
) ((u_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_2x
ddt(1,3):=(*sq (((((ext 6) . 1) . 1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1
) ((u_x . 1) . 2)) (((ext 2) . 1) ((u_2x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_3x
ddt(1,4):=(*sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1)) (((ext 4) . 1
) ((u_x . 1) . 3)) (((ext 3) . 1) ((u_2x . 1) . 3)) (((ext 2) . 1) ((u_3x . 1) .
1))) . 1) t)
% component of ddt w.r.t. p_4x
ddt(1,5):=(*sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1
) ((u_x . 1) . 4)) (((ext 4) . 1) ((u_2x . 1) . 6)) (((ext 3) . 1) ((u_3x . 1) .
4)) (((ext 2) . 1) ((u_4x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_5x
ddt(1,6):=(*sq (((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1
) ((u_x . 1) . 5)) (((ext 5) . 1) ((u_2x . 1) . 10)) (((ext 4) . 1) ((u_3x . 1)
. 10)) (((ext 3) . 1) ((u_4x . 1) . 5)) (((ext 2) . 1) ((u_5x . 1) . 1))) . 1) t
)
% component of ddt w.r.t. p_6x
ddt(1,7):=(*sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((u . 1) . 1)) (((ext 7) .
1) ((u_x . 1) . 6)) (((ext 6) . 1) ((u_2x . 1) . 15)) (((ext 5) . 1) ((u_3x . 1)
. 20)) (((ext 4) . 1) ((u_4x . 1) . 15)) (((ext 3) . 1) ((u_5x . 1) . 6)) (((ext
2) . 1) ((u_6x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_7x
ddt(1,8):=(*sq (((((ext 11) . 1) . 1) (((ext 9) . 1) ((u . 1) . 1)) (((ext 8) .
1) ((u_x . 1) . 7)) (((ext 7) . 1) ((u_2x . 1) . 21)) (((ext 6) . 1) ((u_3x . 1)
. 35)) (((ext 5) . 1) ((u_4x . 1) . 35)) (((ext 4) . 1) ((u_5x . 1) . 21)) (((
ext 3) . 1) ((u_6x . 1) . 7)) (((ext 2) . 1) ((u_7x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_8x
ddt(1,9):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_9x
ddt(1,10):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_10x
ddt(1,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t
ddt(1,12):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t
ddt(1,13):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_xt
ddt(1,14):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t
ddt(1,15):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x2t
ddt(1,16):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2xt
ddt(1,17):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t
ddt(1,18):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x3t
ddt(1,19):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x2t
ddt(1,20):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3xt
ddt(1,21):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t
ddt(1,22):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x4t
ddt(1,23):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x3t
ddt(1,24):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x2t
ddt(1,25):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4xt
ddt(1,26):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t
ddt(1,27):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x5t
ddt(1,28):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x4t
ddt(1,29):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x3t
ddt(1,30):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x2t
ddt(1,31):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5xt
ddt(1,32):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7t
ddt(1,33):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x6t
ddt(1,34):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x5t
ddt(1,35):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x4t
ddt(1,36):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x3t
ddt(1,37):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x2t
ddt(1,38):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6xt
ddt(1,39):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8t
ddt(1,40):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x7t
ddt(1,41):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x6t
ddt(1,42):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x5t
ddt(1,43):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x4t
ddt(1,44):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x3t
ddt(1,45):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x2t
ddt(1,46):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7xt
ddt(1,47):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_9t
ddt(1,48):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x8t
ddt(1,49):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x7t
ddt(1,50):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x6t
ddt(1,51):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x5t
ddt(1,52):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x4t
ddt(1,53):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x3t
ddt(1,54):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7x2t
ddt(1,55):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8xt
ddt(1,56):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_10t
ddt(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x9t
ddt(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x8t
ddt(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x7t
ddt(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x6t
ddt(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x5t
ddt(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x4t
ddt(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7x3t
ddt(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8x2t
ddt(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_9xt
ddt(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
