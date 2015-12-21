% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t)
de!*:=((plus (times u u_x) u_3x))
% odd equation
principal_odd!*:=(p_t r1_x r1_t r2_x r2_t r3_x r3_t)
de_odd!*((plus p_3x (times p_x u)) (plus (times p t u_x) p) (plus (times p t u
u_x) (times p t u_3x) (times p u) (times p_2x t u_x) p_2x (minus (times p_x t
u_2x))) (times p u_x) (plus (times p u u_x) (times p u_3x) (times p_2x u_x) (
minus (times p_x u_2x))) (plus (times p u u_x) (times p u_3x)) (plus (times p (
expt u 2) u_x) (times 2 p u u_3x) (times 3 p u_2x u_x) (times p u_5x) (times
p_2x u u_x) (times p_2x u_3x) (minus (times p_x u u_2x)) (minus (times p_x u_4x)
) (minus (times p_x (expt u_x 2)))))
% Settings:
indep_var!*:=(x t)
dep_var!*:=(u)
odd_var!*:=(p r1 r2 r3)
deg_indep_var!*:=(-1 -3)
deg_dep_var!*:=(2)
deg_odd_var!*:=(2 1 4 6)
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
all_der_mind!*:=((u (0 0)) (u (1 0)) (u (0 1)) (u (2 0)) (u (1 1)) (u (0 2)) (u
(3 0)) (u (2 1)) (u (1 2)) (u (0 3)) (u (4 0)) (u (3 1)) (u (2 2)) (u (1 3)) (u
(0 4)) (u (5 0)) (u (4 1)) (u (3 2)) (u (2 3)) (u (1 4)) (u (0 5)) (u (6 0)) (u
(5 1)) (u (4 2)) (u (3 3)) (u (2 4)) (u (1 5)) (u (0 6)) (u (7 0)) (u (6 1)) (u
(5 2)) (u (4 3)) (u (3 4)) (u (2 5)) (u (1 6)) (u (0 7)) (u (8 0)) (u (7 1)) (u
(6 2)) (u (5 3)) (u (4 4)) (u (3 5)) (u (2 6)) (u (1 7)) (u (0 8)))
% all odd derivatives in multiindex notation:
all_odd_mind!*:=((p (0 0)) (r1 (0 0)) (r2 (0 0)) (r3 (0 0)) (p (1 0)) (r1 (1 0))
(r2 (1 0)) (r3 (1 0)) (p (0 1)) (r1 (0 1)) (r2 (0 1)) (r3 (0 1)) (p (2 0)) (r1 (
2 0)) (r2 (2 0)) (r3 (2 0)) (p (1 1)) (r1 (1 1)) (r2 (1 1)) (r3 (1 1)) (p (0 2))
(r1 (0 2)) (r2 (0 2)) (r3 (0 2)) (p (3 0)) (r1 (3 0)) (r2 (3 0)) (r3 (3 0)) (p (
2 1)) (r1 (2 1)) (r2 (2 1)) (r3 (2 1)) (p (1 2)) (r1 (1 2)) (r2 (1 2)) (r3 (1 2)
) (p (0 3)) (r1 (0 3)) (r2 (0 3)) (r3 (0 3)) (p (4 0)) (r1 (4 0)) (r2 (4 0)) (r3
(4 0)) (p (3 1)) (r1 (3 1)) (r2 (3 1)) (r3 (3 1)) (p (2 2)) (r1 (2 2)) (r2 (2 2)
) (r3 (2 2)) (p (1 3)) (r1 (1 3)) (r2 (1 3)) (r3 (1 3)) (p (0 4)) (r1 (0 4)) (r2
(0 4)) (r3 (0 4)) (p (5 0)) (r1 (5 0)) (r2 (5 0)) (r3 (5 0)) (p (4 1)) (r1 (4 1)
) (r2 (4 1)) (r3 (4 1)) (p (3 2)) (r1 (3 2)) (r2 (3 2)) (r3 (3 2)) (p (2 3)) (r1
(2 3)) (r2 (2 3)) (r3 (2 3)) (p (1 4)) (r1 (1 4)) (r2 (1 4)) (r3 (1 4)) (p (0 5)
) (r1 (0 5)) (r2 (0 5)) (r3 (0 5)) (p (6 0)) (r1 (6 0)) (r2 (6 0)) (r3 (6 0)) (p
(5 1)) (r1 (5 1)) (r2 (5 1)) (r3 (5 1)) (p (4 2)) (r1 (4 2)) (r2 (4 2)) (r3 (4 2
)) (p (3 3)) (r1 (3 3)) (r2 (3 3)) (r3 (3 3)) (p (2 4)) (r1 (2 4)) (r2 (2 4)) (
r3 (2 4)) (p (1 5)) (r1 (1 5)) (r2 (1 5)) (r3 (1 5)) (p (0 6)) (r1 (0 6)) (r2 (0
6)) (r3 (0 6)) (p (7 0)) (r1 (7 0)) (r2 (7 0)) (r3 (7 0)) (p (6 1)) (r1 (6 1)) (
r2 (6 1)) (r3 (6 1)) (p (5 2)) (r1 (5 2)) (r2 (5 2)) (r3 (5 2)) (p (4 3)) (r1 (4
3)) (r2 (4 3)) (r3 (4 3)) (p (3 4)) (r1 (3 4)) (r2 (3 4)) (r3 (3 4)) (p (2 5)) (
r1 (2 5)) (r2 (2 5)) (r3 (2 5)) (p (1 6)) (r1 (1 6)) (r2 (1 6)) (r3 (1 6)) (p (0
7)) (r1 (0 7)) (r2 (0 7)) (r3 (0 7)) (p (8 0)) (r1 (8 0)) (r2 (8 0)) (r3 (8 0))
(p (7 1)) (r1 (7 1)) (r2 (7 1)) (r3 (7 1)) (p (6 2)) (r1 (6 2)) (r2 (6 2)) (r3 (
6 2)) (p (5 3)) (r1 (5 3)) (r2 (5 3)) (r3 (5 3)) (p (4 4)) (r1 (4 4)) (r2 (4 4))
(r3 (4 4)) (p (3 5)) (r1 (3 5)) (r2 (3 5)) (r3 (3 5)) (p (2 6)) (r1 (2 6)) (r2 (
2 6)) (r3 (2 6)) (p (1 7)) (r1 (1 7)) (r2 (1 7)) (r3 (1 7)) (p (0 8)) (r1 (0 8))
(r2 (0 8)) (r3 (0 8)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_x u_t u_2x u_xt u_2t u_3x u_2xt u_x2t u_3t u_4x u_3xt u_2x2t
u_x3t u_4t u_5x u_4xt u_3x2t u_2x3t u_x4t u_5t u_6x u_5xt u_4x2t u_3x3t u_2x4t
u_x5t u_6t u_7x u_6xt u_5x2t u_4x3t u_3x4t u_2x5t u_x6t u_7t u_8x u_7xt u_6x2t
u_5x3t u_4x4t u_3x5t u_2x6t u_x7t u_8t)
% all odd derivatives in identifier notation:
all_odd_id!*:=(p r1 r2 r3 p_x r1_x r2_x r3_x p_t r1_t r2_t r3_t p_2x r1_2x r2_2x
r3_2x p_xt r1_xt r2_xt r3_xt p_2t r1_2t r2_2t r3_2t p_3x r1_3x r2_3x r3_3x p_2xt
r1_2xt r2_2xt r3_2xt p_x2t r1_x2t r2_x2t r3_x2t p_3t r1_3t r2_3t r3_3t p_4x
r1_4x r2_4x r3_4x p_3xt r1_3xt r2_3xt r3_3xt p_2x2t r1_2x2t r2_2x2t r3_2x2t
p_x3t r1_x3t r2_x3t r3_x3t p_4t r1_4t r2_4t r3_4t p_5x r1_5x r2_5x r3_5x p_4xt
r1_4xt r2_4xt r3_4xt p_3x2t r1_3x2t r2_3x2t r3_3x2t p_2x3t r1_2x3t r2_2x3t
r3_2x3t p_x4t r1_x4t r2_x4t r3_x4t p_5t r1_5t r2_5t r3_5t p_6x r1_6x r2_6x r3_6x
p_5xt r1_5xt r2_5xt r3_5xt p_4x2t r1_4x2t r2_4x2t r3_4x2t p_3x3t r1_3x3t r2_3x3t
r3_3x3t p_2x4t r1_2x4t r2_2x4t r3_2x4t p_x5t r1_x5t r2_x5t r3_x5t p_6t r1_6t
r2_6t r3_6t p_7x r1_7x r2_7x r3_7x p_6xt r1_6xt r2_6xt r3_6xt p_5x2t r1_5x2t
r2_5x2t r3_5x2t p_4x3t r1_4x3t r2_4x3t r3_4x3t p_3x4t r1_3x4t r2_3x4t r3_3x4t
p_2x5t r1_2x5t r2_2x5t r3_2x5t p_x6t r1_x6t r2_x6t r3_x6t p_7t r1_7t r2_7t r3_7t
p_8x r1_8x r2_8x r3_8x p_7xt r1_7xt r2_7xt r3_7xt p_6x2t r1_6x2t r2_6x2t r3_6x2t
p_5x3t r1_5x3t r2_5x3t r3_5x3t p_4x4t r1_4x4t r2_4x4t r3_4x4t p_3x5t r1_3x5t
r2_3x5t r3_3x5t p_2x6t r1_2x6t r2_2x6t r3_2x6t p_x7t r1_x7t r2_x7t r3_x7t p_8t
r1_8t r2_8t r3_8t)
% number of all ext symbols:
n_all_ext:=243
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
u (0 8)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((p p (0 0)) (r1 r1 (0 0)) (r2 r2 (0 0)) (r3 r3 (0 0)) (p_x
p (1 0)) (r1_x r1 (1 0)) (r2_x r2 (1 0)) (r3_x r3 (1 0)) (p_t p (0 1)) (r1_t r1
(0 1)) (r2_t r2 (0 1)) (r3_t r3 (0 1)) (p_2x p (2 0)) (r1_2x r1 (2 0)) (r2_2x r2
(2 0)) (r3_2x r3 (2 0)) (p_xt p (1 1)) (r1_xt r1 (1 1)) (r2_xt r2 (1 1)) (r3_xt
r3 (1 1)) (p_2t p (0 2)) (r1_2t r1 (0 2)) (r2_2t r2 (0 2)) (r3_2t r3 (0 2)) (
p_3x p (3 0)) (r1_3x r1 (3 0)) (r2_3x r2 (3 0)) (r3_3x r3 (3 0)) (p_2xt p (2 1))
(r1_2xt r1 (2 1)) (r2_2xt r2 (2 1)) (r3_2xt r3 (2 1)) (p_x2t p (1 2)) (r1_x2t r1
(1 2)) (r2_x2t r2 (1 2)) (r3_x2t r3 (1 2)) (p_3t p (0 3)) (r1_3t r1 (0 3)) (
r2_3t r2 (0 3)) (r3_3t r3 (0 3)) (p_4x p (4 0)) (r1_4x r1 (4 0)) (r2_4x r2 (4 0)
) (r3_4x r3 (4 0)) (p_3xt p (3 1)) (r1_3xt r1 (3 1)) (r2_3xt r2 (3 1)) (r3_3xt
r3 (3 1)) (p_2x2t p (2 2)) (r1_2x2t r1 (2 2)) (r2_2x2t r2 (2 2)) (r3_2x2t r3 (2
2)) (p_x3t p (1 3)) (r1_x3t r1 (1 3)) (r2_x3t r2 (1 3)) (r3_x3t r3 (1 3)) (p_4t
p (0 4)) (r1_4t r1 (0 4)) (r2_4t r2 (0 4)) (r3_4t r3 (0 4)) (p_5x p (5 0)) (
r1_5x r1 (5 0)) (r2_5x r2 (5 0)) (r3_5x r3 (5 0)) (p_4xt p (4 1)) (r1_4xt r1 (4
1)) (r2_4xt r2 (4 1)) (r3_4xt r3 (4 1)) (p_3x2t p (3 2)) (r1_3x2t r1 (3 2)) (
r2_3x2t r2 (3 2)) (r3_3x2t r3 (3 2)) (p_2x3t p (2 3)) (r1_2x3t r1 (2 3)) (
r2_2x3t r2 (2 3)) (r3_2x3t r3 (2 3)) (p_x4t p (1 4)) (r1_x4t r1 (1 4)) (r2_x4t
r2 (1 4)) (r3_x4t r3 (1 4)) (p_5t p (0 5)) (r1_5t r1 (0 5)) (r2_5t r2 (0 5)) (
r3_5t r3 (0 5)) (p_6x p (6 0)) (r1_6x r1 (6 0)) (r2_6x r2 (6 0)) (r3_6x r3 (6 0)
) (p_5xt p (5 1)) (r1_5xt r1 (5 1)) (r2_5xt r2 (5 1)) (r3_5xt r3 (5 1)) (p_4x2t
p (4 2)) (r1_4x2t r1 (4 2)) (r2_4x2t r2 (4 2)) (r3_4x2t r3 (4 2)) (p_3x3t p (3 3
)) (r1_3x3t r1 (3 3)) (r2_3x3t r2 (3 3)) (r3_3x3t r3 (3 3)) (p_2x4t p (2 4)) (
r1_2x4t r1 (2 4)) (r2_2x4t r2 (2 4)) (r3_2x4t r3 (2 4)) (p_x5t p (1 5)) (r1_x5t
r1 (1 5)) (r2_x5t r2 (1 5)) (r3_x5t r3 (1 5)) (p_6t p (0 6)) (r1_6t r1 (0 6)) (
r2_6t r2 (0 6)) (r3_6t r3 (0 6)) (p_7x p (7 0)) (r1_7x r1 (7 0)) (r2_7x r2 (7 0)
) (r3_7x r3 (7 0)) (p_6xt p (6 1)) (r1_6xt r1 (6 1)) (r2_6xt r2 (6 1)) (r3_6xt
r3 (6 1)) (p_5x2t p (5 2)) (r1_5x2t r1 (5 2)) (r2_5x2t r2 (5 2)) (r3_5x2t r3 (5
2)) (p_4x3t p (4 3)) (r1_4x3t r1 (4 3)) (r2_4x3t r2 (4 3)) (r3_4x3t r3 (4 3)) (
p_3x4t p (3 4)) (r1_3x4t r1 (3 4)) (r2_3x4t r2 (3 4)) (r3_3x4t r3 (3 4)) (p_2x5t
p (2 5)) (r1_2x5t r1 (2 5)) (r2_2x5t r2 (2 5)) (r3_2x5t r3 (2 5)) (p_x6t p (1 6)
) (r1_x6t r1 (1 6)) (r2_x6t r2 (1 6)) (r3_x6t r3 (1 6)) (p_7t p (0 7)) (r1_7t r1
(0 7)) (r2_7t r2 (0 7)) (r3_7t r3 (0 7)) (p_8x p (8 0)) (r1_8x r1 (8 0)) (r2_8x
r2 (8 0)) (r3_8x r3 (8 0)) (p_7xt p (7 1)) (r1_7xt r1 (7 1)) (r2_7xt r2 (7 1)) (
r3_7xt r3 (7 1)) (p_6x2t p (6 2)) (r1_6x2t r1 (6 2)) (r2_6x2t r2 (6 2)) (r3_6x2t
r3 (6 2)) (p_5x3t p (5 3)) (r1_5x3t r1 (5 3)) (r2_5x3t r2 (5 3)) (r3_5x3t r3 (5
3)) (p_4x4t p (4 4)) (r1_4x4t r1 (4 4)) (r2_4x4t r2 (4 4)) (r3_4x4t r3 (4 4)) (
p_3x5t p (3 5)) (r1_3x5t r1 (3 5)) (r2_3x5t r2 (3 5)) (r3_3x5t r3 (3 5)) (p_2x6t
p (2 6)) (r1_2x6t r1 (2 6)) (r2_2x6t r2 (2 6)) (r3_2x6t r3 (2 6)) (p_x7t p (1 7)
) (r1_x7t r1 (1 7)) (r2_x7t r2 (1 7)) (r3_x7t r3 (1 7)) (p_8t p (0 8)) (r1_8t r1
(0 8)) (r2_8t r2 (0 8)) (r3_8t r3 (0 8)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (u_x . 1) (u_t . 1) (u_2x . 2) (u_xt . 2) (u_2t . 2) (
u_3x . 3) (u_2xt . 3) (u_x2t . 3) (u_3t . 3) (u_4x . 4) (u_3xt . 4) (u_2x2t . 4)
(u_x3t . 4) (u_4t . 4) (u_5x . 5) (u_4xt . 5) (u_3x2t . 5) (u_2x3t . 5) (u_x4t .
5) (u_5t . 5) (u_6x . 6) (u_5xt . 6) (u_4x2t . 6) (u_3x3t . 6) (u_2x4t . 6) (
u_x5t . 6) (u_6t . 6) (u_7x . 7) (u_6xt . 7) (u_5x2t . 7) (u_4x3t . 7) (u_3x4t .
7) (u_2x5t . 7) (u_x6t . 7) (u_7t . 7) (u_8x . 8) (u_7xt . 8) (u_6x2t . 8) (
u_5x3t . 8) (u_4x4t . 8) (u_3x5t . 8) (u_2x6t . 8) (u_x7t . 8) (u_8t . 8))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((p . 0) (r1 . 0) (r2 . 0) (r3 . 0) (p_x . 1) (r1_x . 1) (
r2_x . 1) (r3_x . 1) (p_t . 1) (r1_t . 1) (r2_t . 1) (r3_t . 1) (p_2x . 2) (
r1_2x . 2) (r2_2x . 2) (r3_2x . 2) (p_xt . 2) (r1_xt . 2) (r2_xt . 2) (r3_xt . 2
) (p_2t . 2) (r1_2t . 2) (r2_2t . 2) (r3_2t . 2) (p_3x . 3) (r1_3x . 3) (r2_3x .
3) (r3_3x . 3) (p_2xt . 3) (r1_2xt . 3) (r2_2xt . 3) (r3_2xt . 3) (p_x2t . 3) (
r1_x2t . 3) (r2_x2t . 3) (r3_x2t . 3) (p_3t . 3) (r1_3t . 3) (r2_3t . 3) (r3_3t
. 3) (p_4x . 4) (r1_4x . 4) (r2_4x . 4) (r3_4x . 4) (p_3xt . 4) (r1_3xt . 4) (
r2_3xt . 4) (r3_3xt . 4) (p_2x2t . 4) (r1_2x2t . 4) (r2_2x2t . 4) (r3_2x2t . 4)
(p_x3t . 4) (r1_x3t . 4) (r2_x3t . 4) (r3_x3t . 4) (p_4t . 4) (r1_4t . 4) (r2_4t
. 4) (r3_4t . 4) (p_5x . 5) (r1_5x . 5) (r2_5x . 5) (r3_5x . 5) (p_4xt . 5) (
r1_4xt . 5) (r2_4xt . 5) (r3_4xt . 5) (p_3x2t . 5) (r1_3x2t . 5) (r2_3x2t . 5) (
r3_3x2t . 5) (p_2x3t . 5) (r1_2x3t . 5) (r2_2x3t . 5) (r3_2x3t . 5) (p_x4t . 5)
(r1_x4t . 5) (r2_x4t . 5) (r3_x4t . 5) (p_5t . 5) (r1_5t . 5) (r2_5t . 5) (r3_5t
. 5) (p_6x . 6) (r1_6x . 6) (r2_6x . 6) (r3_6x . 6) (p_5xt . 6) (r1_5xt . 6) (
r2_5xt . 6) (r3_5xt . 6) (p_4x2t . 6) (r1_4x2t . 6) (r2_4x2t . 6) (r3_4x2t . 6)
(p_3x3t . 6) (r1_3x3t . 6) (r2_3x3t . 6) (r3_3x3t . 6) (p_2x4t . 6) (r1_2x4t . 6
) (r2_2x4t . 6) (r3_2x4t . 6) (p_x5t . 6) (r1_x5t . 6) (r2_x5t . 6) (r3_x5t . 6)
(p_6t . 6) (r1_6t . 6) (r2_6t . 6) (r3_6t . 6) (p_7x . 7) (r1_7x . 7) (r2_7x . 7
) (r3_7x . 7) (p_6xt . 7) (r1_6xt . 7) (r2_6xt . 7) (r3_6xt . 7) (p_5x2t . 7) (
r1_5x2t . 7) (r2_5x2t . 7) (r3_5x2t . 7) (p_4x3t . 7) (r1_4x3t . 7) (r2_4x3t . 7
) (r3_4x3t . 7) (p_3x4t . 7) (r1_3x4t . 7) (r2_3x4t . 7) (r3_3x4t . 7) (p_2x5t .
7) (r1_2x5t . 7) (r2_2x5t . 7) (r3_2x5t . 7) (p_x6t . 7) (r1_x6t . 7) (r2_x6t .
7) (r3_x6t . 7) (p_7t . 7) (r1_7t . 7) (r2_7t . 7) (r3_7t . 7) (p_8x . 8) (r1_8x
. 8) (r2_8x . 8) (r3_8x . 8) (p_7xt . 8) (r1_7xt . 8) (r2_7xt . 8) (r3_7xt . 8)
(p_6x2t . 8) (r1_6x2t . 8) (r2_6x2t . 8) (r3_6x2t . 8) (p_5x3t . 8) (r1_5x3t . 8
) (r2_5x3t . 8) (r3_5x3t . 8) (p_4x4t . 8) (r1_4x4t . 8) (r2_4x4t . 8) (r3_4x4t
. 8) (p_3x5t . 8) (r1_3x5t . 8) (r2_3x5t . 8) (r3_3x5t . 8) (p_2x6t . 8) (
r1_2x6t . 8) (r2_2x6t . 8) (r3_2x6t . 8) (p_x7t . 8) (r1_x7t . 8) (r2_x7t . 8) (
r3_x7t . 8) (p_8t . 8) (r1_8t . 8) (r2_8t . 8) (r3_8t . 8))
% list of even principal derivatives:
all_principal_der!*:=(u_t u_2t u_xt u_3t u_x2t u_2xt u_4t u_x3t u_2x2t u_3xt
u_5t u_x4t u_2x3t u_3x2t u_4xt u_6t u_x5t u_2x4t u_3x3t u_4x2t u_5xt u_7t u_x6t
u_2x5t u_3x4t u_4x3t u_5x2t u_6xt u_8t u_x7t u_2x6t u_3x5t u_4x4t u_5x3t u_6x2t
u_7xt)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_x u_2x u_3x u_4x u_5x u_6x u_7x u_8x)
% list of odd principal derivatives:
all_principal_odd!*:=(p_t r1_t r1_x r2_t r2_x r3_t r3_x p_2t p_xt r1_2t r1_xt
r1_xt r1_2x r2_2t r2_xt r2_xt r2_2x r3_2t r3_xt r3_xt r3_2x p_3t p_x2t p_2xt
r1_3t r1_x2t r1_2xt r1_x2t r1_2xt r1_3x r2_3t r2_x2t r2_2xt r2_x2t r2_2xt r2_3x
r3_3t r3_x2t r3_2xt r3_x2t r3_2xt r3_3x p_4t p_x3t p_2x2t p_3xt r1_4t r1_x3t
r1_2x2t r1_3xt r1_x3t r1_2x2t r1_3xt r1_4x r2_4t r2_x3t r2_2x2t r2_3xt r2_x3t
r2_2x2t r2_3xt r2_4x r3_4t r3_x3t r3_2x2t r3_3xt r3_x3t r3_2x2t r3_3xt r3_4x
p_5t p_x4t p_2x3t p_3x2t p_4xt r1_5t r1_x4t r1_2x3t r1_3x2t r1_4xt r1_x4t
r1_2x3t r1_3x2t r1_4xt r1_5x r2_5t r2_x4t r2_2x3t r2_3x2t r2_4xt r2_x4t r2_2x3t
r2_3x2t r2_4xt r2_5x r3_5t r3_x4t r3_2x3t r3_3x2t r3_4xt r3_x4t r3_2x3t r3_3x2t
r3_4xt r3_5x p_6t p_x5t p_2x4t p_3x3t p_4x2t p_5xt r1_6t r1_x5t r1_2x4t r1_3x3t
r1_4x2t r1_5xt r1_x5t r1_2x4t r1_3x3t r1_4x2t r1_5xt r1_6x r2_6t r2_x5t r2_2x4t
r2_3x3t r2_4x2t r2_5xt r2_x5t r2_2x4t r2_3x3t r2_4x2t r2_5xt r2_6x r3_6t r3_x5t
r3_2x4t r3_3x3t r3_4x2t r3_5xt r3_x5t r3_2x4t r3_3x3t r3_4x2t r3_5xt r3_6x p_7t
p_x6t p_2x5t p_3x4t p_4x3t p_5x2t p_6xt r1_7t r1_x6t r1_2x5t r1_3x4t r1_4x3t
r1_5x2t r1_6xt r1_x6t r1_2x5t r1_3x4t r1_4x3t r1_5x2t r1_6xt r1_7x r2_7t r2_x6t
r2_2x5t r2_3x4t r2_4x3t r2_5x2t r2_6xt r2_x6t r2_2x5t r2_3x4t r2_4x3t r2_5x2t
r2_6xt r2_7x r3_7t r3_x6t r3_2x5t r3_3x4t r3_4x3t r3_5x2t r3_6xt r3_x6t r3_2x5t
r3_3x4t r3_4x3t r3_5x2t r3_6xt r3_7x p_8t p_x7t p_2x6t p_3x5t p_4x4t p_5x3t
p_6x2t p_7xt r1_8t r1_x7t r1_2x6t r1_3x5t r1_4x4t r1_5x3t r1_6x2t r1_7xt r1_8x
r2_8t r2_x7t r2_2x6t r2_3x5t r2_4x4t r2_5x3t r2_6x2t r2_7xt r2_8x r3_8t r3_x7t
r3_2x6t r3_3x5t r3_4x4t r3_5x3t r3_6x2t r3_7xt r3_8x)
p_t = (ext 13)
r1_t = (ext 14)
r1_x = (ext 15)
r2_t = (ext 16)
r2_x = (ext 17)
r3_t = (ext 18)
r3_x = (ext 19)
p_2t = (ext 20)
p_xt = (ext 21)
r1_2t = (ext 22)
r1_xt = (ext 23)
r1_xt = (ext 23)
r1_2x = (ext 25)
r2_2t = (ext 26)
r2_xt = (ext 27)
r2_xt = (ext 27)
r2_2x = (ext 29)
r3_2t = (ext 30)
r3_xt = (ext 31)
r3_xt = (ext 31)
r3_2x = (ext 33)
p_3t = (ext 34)
p_x2t = (ext 35)
p_2xt = (ext 36)
r1_3t = (ext 37)
r1_x2t = (ext 38)
r1_2xt = (ext 39)
r1_x2t = (ext 38)
r1_2xt = (ext 39)
r1_3x = (ext 42)
r2_3t = (ext 43)
r2_x2t = (ext 44)
r2_2xt = (ext 45)
r2_x2t = (ext 44)
r2_2xt = (ext 45)
r2_3x = (ext 48)
r3_3t = (ext 49)
r3_x2t = (ext 50)
r3_2xt = (ext 51)
r3_x2t = (ext 50)
r3_2xt = (ext 51)
r3_3x = (ext 54)
p_4t = (ext 55)
p_x3t = (ext 56)
p_2x2t = (ext 57)
p_3xt = (ext 58)
r1_4t = (ext 59)
r1_x3t = (ext 60)
r1_2x2t = (ext 61)
r1_3xt = (ext 62)
r1_x3t = (ext 60)
r1_2x2t = (ext 61)
r1_3xt = (ext 62)
r1_4x = (ext 66)
r2_4t = (ext 67)
r2_x3t = (ext 68)
r2_2x2t = (ext 69)
r2_3xt = (ext 70)
r2_x3t = (ext 68)
r2_2x2t = (ext 69)
r2_3xt = (ext 70)
r2_4x = (ext 74)
r3_4t = (ext 75)
r3_x3t = (ext 76)
r3_2x2t = (ext 77)
r3_3xt = (ext 78)
r3_x3t = (ext 76)
r3_2x2t = (ext 77)
r3_3xt = (ext 78)
r3_4x = (ext 82)
p_5t = (ext 83)
p_x4t = (ext 84)
p_2x3t = (ext 85)
p_3x2t = (ext 86)
p_4xt = (ext 87)
r1_5t = (ext 88)
r1_x4t = (ext 89)
r1_2x3t = (ext 90)
r1_3x2t = (ext 91)
r1_4xt = (ext 92)
r1_x4t = (ext 89)
r1_2x3t = (ext 90)
r1_3x2t = (ext 91)
r1_4xt = (ext 92)
r1_5x = (ext 97)
r2_5t = (ext 98)
r2_x4t = (ext 99)
r2_2x3t = (ext 100)
r2_3x2t = (ext 101)
r2_4xt = (ext 102)
r2_x4t = (ext 99)
r2_2x3t = (ext 100)
r2_3x2t = (ext 101)
r2_4xt = (ext 102)
r2_5x = (ext 107)
r3_5t = (ext 108)
r3_x4t = (ext 109)
r3_2x3t = (ext 110)
r3_3x2t = (ext 111)
r3_4xt = (ext 112)
r3_x4t = (ext 109)
r3_2x3t = (ext 110)
r3_3x2t = (ext 111)
r3_4xt = (ext 112)
r3_5x = (ext 117)
p_6t = (ext 118)
p_x5t = (ext 119)
p_2x4t = (ext 120)
p_3x3t = (ext 121)
p_4x2t = (ext 122)
p_5xt = (ext 123)
r1_6t = (ext 124)
r1_x5t = (ext 125)
r1_2x4t = (ext 126)
r1_3x3t = (ext 127)
r1_4x2t = (ext 128)
r1_5xt = (ext 129)
r1_x5t = (ext 125)
r1_2x4t = (ext 126)
r1_3x3t = (ext 127)
r1_4x2t = (ext 128)
r1_5xt = (ext 129)
r1_6x = (ext 135)
r2_6t = (ext 136)
r2_x5t = (ext 137)
r2_2x4t = (ext 138)
r2_3x3t = (ext 139)
r2_4x2t = (ext 140)
r2_5xt = (ext 141)
r2_x5t = (ext 137)
r2_2x4t = (ext 138)
r2_3x3t = (ext 139)
r2_4x2t = (ext 140)
r2_5xt = (ext 141)
r2_6x = (ext 147)
r3_6t = (ext 148)
r3_x5t = (ext 149)
r3_2x4t = (ext 150)
r3_3x3t = (ext 151)
r3_4x2t = (ext 152)
r3_5xt = (ext 153)
r3_x5t = (ext 149)
r3_2x4t = (ext 150)
r3_3x3t = (ext 151)
r3_4x2t = (ext 152)
r3_5xt = (ext 153)
r3_6x = (ext 159)
p_7t = (ext 160)
p_x6t = (ext 161)
p_2x5t = (ext 162)
p_3x4t = (ext 163)
p_4x3t = (ext 164)
p_5x2t = (ext 165)
p_6xt = (ext 166)
r1_7t = (ext 167)
r1_x6t = (ext 168)
r1_2x5t = (ext 169)
r1_3x4t = (ext 170)
r1_4x3t = (ext 171)
r1_5x2t = (ext 172)
r1_6xt = (ext 173)
r1_x6t = (ext 168)
r1_2x5t = (ext 169)
r1_3x4t = (ext 170)
r1_4x3t = (ext 171)
r1_5x2t = (ext 172)
r1_6xt = (ext 173)
r1_7x = (ext 180)
r2_7t = (ext 181)
r2_x6t = (ext 182)
r2_2x5t = (ext 183)
r2_3x4t = (ext 184)
r2_4x3t = (ext 185)
r2_5x2t = (ext 186)
r2_6xt = (ext 187)
r2_x6t = (ext 182)
r2_2x5t = (ext 183)
r2_3x4t = (ext 184)
r2_4x3t = (ext 185)
r2_5x2t = (ext 186)
r2_6xt = (ext 187)
r2_7x = (ext 194)
r3_7t = (ext 195)
r3_x6t = (ext 196)
r3_2x5t = (ext 197)
r3_3x4t = (ext 198)
r3_4x3t = (ext 199)
r3_5x2t = (ext 200)
r3_6xt = (ext 201)
r3_x6t = (ext 196)
r3_2x5t = (ext 197)
r3_3x4t = (ext 198)
r3_4x3t = (ext 199)
r3_5x2t = (ext 200)
r3_6xt = (ext 201)
r3_7x = (ext 208)
p_8t = (ext 209)
p_x7t = (ext 210)
p_2x6t = (ext 211)
p_3x5t = (ext 212)
p_4x4t = (ext 213)
p_5x3t = (ext 214)
p_6x2t = (ext 215)
p_7xt = (ext 216)
r1_8t = (ext 217)
r1_x7t = (ext 218)
r1_2x6t = (ext 219)
r1_3x5t = (ext 220)
r1_4x4t = (ext 221)
r1_5x3t = (ext 222)
r1_6x2t = (ext 223)
r1_7xt = (ext 224)
r1_8x = (ext 225)
r2_8t = (ext 226)
r2_x7t = (ext 227)
r2_2x6t = (ext 228)
r2_3x5t = (ext 229)
r2_4x4t = (ext 230)
r2_5x3t = (ext 231)
r2_6x2t = (ext 232)
r2_7xt = (ext 233)
r2_8x = (ext 234)
r3_8t = (ext 235)
r3_x7t = (ext 236)
r3_2x6t = (ext 237)
r3_3x5t = (ext 238)
r3_4x4t = (ext 239)
r3_5x3t = (ext 240)
r3_6x2t = (ext 241)
r3_7xt = (ext 242)
r3_8x = (ext 243)
% list of odd parametric derivatives:
all_parametric_odd!*:=(p r1 r2 r3 p_x p_2x p_3x p_4x p_5x p_6x p_7x p_8x)
p = (ext 1)
r1 = (ext 2)
r2 = (ext 3)
r3 = (ext 4)
p_x = (ext 5)
p_2x = (ext 6)
p_3x = (ext 7)
p_4x = (ext 8)
p_5x = (ext 9)
p_6x = (ext 10)
p_7x = (ext 11)
p_8x = (ext 12)
% number of ext principal derivatives:
n_all_principal_ext:=231
% number of ext parametric derivatives:
n_all_parametric_ext:=12
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddt)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 u_xt) (ddt 0 5 u_2xt) (ddt 0
6 u_3xt) (ddt 0 7 u_4xt) (ddt 0 8 u_5xt) (ddt 0 9 u_6xt) (ddt 0 10 u_7xt))
primary_diffcon_odd_tot!*:=((ddx 1 2 r1_x) (ddx 1 3 r2_x) (ddx 1 4 r3_x) (ddt 1
1 p_t) (ddt 1 2 r1_t) (ddt 1 3 r2_t) (ddt 1 4 r3_t) (ddt 1 5 p_xt) (ddt 1 6
p_2xt) (ddt 1 7 p_3xt) (ddt 1 8 p_4xt) (ddt 1 9 p_5xt) (ddt 1 10 p_6xt) (ddt 1
11 p_7xt))
primary_diffcon_der!*:=(u_xt u_2xt u_3xt u_4xt u_5xt u_6xt u_7xt)
primary_diffcon_odd!*:=(p_xt p_2xt p_3xt p_4xt p_5xt p_6xt p_7xt)
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_7xt (*sq ((((letop . 1) . 1)) . 1) nil)) (u_6xt (*sq ((((
letop . 1) . 1)) . 1) nil)) (u_5xt (*sq ((((u . 1) ((u_6x . 1) . 1)) ((u_2x . 1)
((u_4x . 1) . 15)) ((u_3x . 2) . 10) ((u_5x . 1) ((u_x . 1) . 6)) ((u_8x . 1) .
1)) . 1) nil)) (u_4xt (*sq ((((u . 1) ((u_5x . 1) . 1)) ((u_2x . 1) ((u_3x . 1)
. 10)) ((u_4x . 1) ((u_x . 1) . 5)) ((u_7x . 1) . 1)) . 1) nil)) (u_3xt (*sq (((
(u . 1) ((u_4x . 1) . 1)) ((u_2x . 2) . 3) ((u_3x . 1) ((u_x . 1) . 4)) ((u_6x .
1) . 1)) . 1) nil)) (u_2xt (*sq ((((u . 1) ((u_3x . 1) . 1)) ((u_2x . 1) ((u_x .
1) . 3)) ((u_5x . 1) . 1)) . 1) nil)) (u_xt (*sq ((((u . 1) ((u_2x . 1) . 1)) ((
u_4x . 1) . 1) ((u_x . 2) . 1)) . 1) nil)) (u_t (plus (times u u_x) u_3x)))
diffcon_odd!*:=((p_7xt (*sq ((((letop . 1) . 1)) . 1) nil)) (p_6xt (*sq ((((
letop . 1) . 1)) . 1) nil)) (p_5xt (*sq (((((ext 12) . 1) . 1) (((ext 10) . 1) (
(u . 1) . 1)) (((ext 9) . 1) ((u_x . 1) . 5)) (((ext 8) . 1) ((u_2x . 1) . 10))
(((ext 7) . 1) ((u_3x . 1) . 10)) (((ext 6) . 1) ((u_4x . 1) . 5)) (((ext 5) . 1
) ((u_5x . 1) . 1))) . 1) nil)) (p_4xt (*sq (((((ext 11) . 1) . 1) (((ext 9) . 1
) ((u . 1) . 1)) (((ext 8) . 1) ((u_x . 1) . 4)) (((ext 7) . 1) ((u_2x . 1) . 6)
) (((ext 6) . 1) ((u_3x . 1) . 4)) (((ext 5) . 1) ((u_4x . 1) . 1))) . 1) nil))
(p_3xt (*sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((u . 1) . 1)) (((ext 7) . 1)
((u_x . 1) . 3)) (((ext 6) . 1) ((u_2x . 1) . 3)) (((ext 5) . 1) ((u_3x . 1) . 1
))) . 1) nil)) (p_2xt (*sq (((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (
((ext 6) . 1) ((u_x . 1) . 2)) (((ext 5) . 1) ((u_2x . 1) . 1))) . 1) nil)) (
p_xt (*sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1) ((
u_x . 1) . 1))) . 1) nil)) (r3_t (*sq (((((ext 6) . 1) ((u . 1) ((u_x . 1) . 1))
((u_3x . 1) . 1)) (((ext 5) . 1) ((u . 1) ((u_2x . 1) . -1)) ((u_4x . 1) . -1) (
(u_x . 2) . -1)) (((ext 1) . 1) ((u . 2) ((u_x . 1) . 1)) ((u . 1) ((u_3x . 1) .
2)) ((u_2x . 1) ((u_x . 1) . 3)) ((u_5x . 1) . 1))) . 1) nil)) (r3_x (*sq (((((
ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) . 1) nil)) (r2_t (*sq (
((((ext 6) . 1) ((u_x . 1) . 1)) (((ext 5) . 1) ((u_2x . 1) . -1)) (((ext 1) . 1
) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) . 1) nil)) (r2_x (*sq (((((ext 1)
. 1) ((u_x . 1) . 1))) . 1) nil)) (r1_t (*sq (((((ext 6) . 1) ((t . 1) ((u_x . 1
) . 1)) . 1) (((ext 5) . 1) ((t . 1) ((u_2x . 1) . -1))) (((ext 1) . 1) ((t . 1)
((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1)) ((u . 1) . 1))) . 1) nil)) (r1_x (
*sq (((((ext 1) . 1) ((t . 1) ((u_x . 1) . 1)) . 1)) . 1) nil)) (p_t (*sq (((((
ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1))) . 1) nil)))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_7xt u_6xt u_5xt u_4xt u_3xt u_2xt u_xt u_t)
diffcon_comp_odd!*:=(p_7xt p_6xt p_5xt p_4xt p_3xt p_2xt p_xt r3_t r3_x r2_t
r2_x r1_t r1_x p_t)
diffcon_comp_ext!*:=((ext 216) (ext 166) (ext 123) (ext 87) (ext 58) (ext 36) (
ext 21) (ext 18) (ext 19) (ext 16) (ext 17) (ext 14) (ext 15) (ext 13))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_7xt *sq ((((letop . 1) . 1)) . 1) nil) (u_6xt *sq ((((
letop . 1) . 1)) . 1) nil) (u_5xt *sq ((((u . 1) ((u_6x . 1) . 1)) ((u_2x . 1) (
(u_4x . 1) . 15)) ((u_3x . 2) . 10) ((u_5x . 1) ((u_x . 1) . 6)) ((u_8x . 1) . 1
)) . 1) nil) (u_4xt *sq ((((u . 1) ((u_5x . 1) . 1)) ((u_2x . 1) ((u_3x . 1) .
10)) ((u_4x . 1) ((u_x . 1) . 5)) ((u_7x . 1) . 1)) . 1) nil) (u_3xt *sq ((((u .
1) ((u_4x . 1) . 1)) ((u_2x . 2) . 3) ((u_3x . 1) ((u_x . 1) . 4)) ((u_6x . 1) .
1)) . 1) nil) (u_2xt *sq ((((u . 1) ((u_3x . 1) . 1)) ((u_2x . 1) ((u_x . 1) . 3
)) ((u_5x . 1) . 1)) . 1) nil) (u_xt *sq ((((u . 1) ((u_2x . 1) . 1)) ((u_4x . 1
) . 1) ((u_x . 2) . 1)) . 1) nil) (u_t *sq ((((u . 1) ((u_x . 1) . 1)) ((u_3x .
1) . 1)) . 1) nil))
diffcon_param_ext!*:=(((ext 216) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 166)
*sq ((((letop . 1) . 1)) . 1) nil) ((ext 123) *sq (((((ext 12) . 1) . 1) (((ext
10) . 1) ((u . 1) . 1)) (((ext 9) . 1) ((u_x . 1) . 5)) (((ext 8) . 1) ((u_2x .
1) . 10)) (((ext 7) . 1) ((u_3x . 1) . 10)) (((ext 6) . 1) ((u_4x . 1) . 5)) (((
ext 5) . 1) ((u_5x . 1) . 1))) . 1) nil) ((ext 87) *sq (((((ext 11) . 1) . 1) ((
(ext 9) . 1) ((u . 1) . 1)) (((ext 8) . 1) ((u_x . 1) . 4)) (((ext 7) . 1) ((
u_2x . 1) . 6)) (((ext 6) . 1) ((u_3x . 1) . 4)) (((ext 5) . 1) ((u_4x . 1) . 1)
)) . 1) nil) ((ext 58) *sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((u . 1) . 1))
(((ext 7) . 1) ((u_x . 1) . 3)) (((ext 6) . 1) ((u_2x . 1) . 3)) (((ext 5) . 1)
((u_3x . 1) . 1))) . 1) nil) ((ext 36) *sq (((((ext 9) . 1) . 1) (((ext 7) . 1)
((u . 1) . 1)) (((ext 6) . 1) ((u_x . 1) . 2)) (((ext 5) . 1) ((u_2x . 1) . 1)))
. 1) nil) ((ext 21) *sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((
ext 5) . 1) ((u_x . 1) . 1))) . 1) nil) ((ext 18) *sq (((((ext 6) . 1) ((u . 1)
((u_x . 1) . 1)) ((u_3x . 1) . 1)) (((ext 5) . 1) ((u . 1) ((u_2x . 1) . -1)) ((
u_4x . 1) . -1) ((u_x . 2) . -1)) (((ext 1) . 1) ((u . 2) ((u_x . 1) . 1)) ((u .
1) ((u_3x . 1) . 2)) ((u_2x . 1) ((u_x . 1) . 3)) ((u_5x . 1) . 1))) . 1) nil) (
(ext 19) *sq (((((ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) . 1)
nil) ((ext 16) *sq (((((ext 6) . 1) ((u_x . 1) . 1)) (((ext 5) . 1) ((u_2x . 1)
. -1)) (((ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) . 1) nil) ((
ext 17) *sq (((((ext 1) . 1) ((u_x . 1) . 1))) . 1) nil) ((ext 14) *sq (((((ext
6) . 1) ((t . 1) ((u_x . 1) . 1)) . 1) (((ext 5) . 1) ((t . 1) ((u_2x . 1) . -1)
)) (((ext 1) . 1) ((t . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1)) ((u . 1)
. 1))) . 1) nil) ((ext 15) *sq (((((ext 1) . 1) ((t . 1) ((u_x . 1) . 1)) . 1))
. 1) nil) ((ext 13) *sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1))) . 1
) nil))
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
ddx(0,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t
ddx(0,12):=(*sq ((((u_xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,13):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_xt
ddx(0,14):=(*sq ((((u_2xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t
ddx(0,15):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x2t
ddx(0,16):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2xt
ddx(0,17):=(*sq ((((u_3xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t
ddx(0,18):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x3t
ddx(0,19):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x2t
ddx(0,20):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3xt
ddx(0,21):=(*sq ((((u_4xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t
ddx(0,22):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x4t
ddx(0,23):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x3t
ddx(0,24):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x2t
ddx(0,25):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4xt
ddx(0,26):=(*sq ((((u_5xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t
ddx(0,27):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x5t
ddx(0,28):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x4t
ddx(0,29):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x3t
ddx(0,30):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x2t
ddx(0,31):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5xt
ddx(0,32):=(*sq ((((u_6xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t
ddx(0,33):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x6t
ddx(0,34):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x5t
ddx(0,35):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x4t
ddx(0,36):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x3t
ddx(0,37):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x2t
ddx(0,38):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6xt
ddx(0,39):=(*sq ((((u_7xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8t
ddx(0,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x7t
ddx(0,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x6t
ddx(0,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x5t
ddx(0,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x4t
ddx(0,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x3t
ddx(0,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x2t
ddx(0,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7xt
ddx(0,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p
ddx(1,1):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1
ddx(1,2):=(*sq (((((ext 1) . 1) ((t . 1) ((u_x . 1) . 1)) . 1)) . 1) t)
% component of ddx w.r.t. r2
ddx(1,3):=(*sq (((((ext 1) . 1) ((u_x . 1) . 1))) . 1) t)
% component of ddx w.r.t. r3
ddx(1,4):=(*sq (((((ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) . 1
) t)
% component of ddx w.r.t. p_x
ddx(1,5):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x
ddx(1,6):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x
ddx(1,7):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x
ddx(1,8):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x
ddx(1,9):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x
ddx(1,10):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x
ddx(1,11):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8x
ddx(1,12):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t
ddx(1,13):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_t
ddx(1,14):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x
ddx(1,15):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_t
ddx(1,16):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x
ddx(1,17):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_t
ddx(1,18):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x
ddx(1,19):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t
ddx(1,20):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_xt
ddx(1,21):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2t
ddx(1,22):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_xt
ddx(1,23):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_xt
ddx(1,24):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x
ddx(1,25):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2t
ddx(1,26):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_xt
ddx(1,27):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_xt
ddx(1,28):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x
ddx(1,29):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2t
ddx(1,30):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_xt
ddx(1,31):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_xt
ddx(1,32):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x
ddx(1,33):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t
ddx(1,34):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x2t
ddx(1,35):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2xt
ddx(1,36):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3t
ddx(1,37):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x2t
ddx(1,38):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2xt
ddx(1,39):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x2t
ddx(1,40):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2xt
ddx(1,41):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x
ddx(1,42):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3t
ddx(1,43):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x2t
ddx(1,44):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2xt
ddx(1,45):=(*sq (((((ext 70) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x2t
ddx(1,46):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2xt
ddx(1,47):=(*sq (((((ext 70) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x
ddx(1,48):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3t
ddx(1,49):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x2t
ddx(1,50):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2xt
ddx(1,51):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x2t
ddx(1,52):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2xt
ddx(1,53):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x
ddx(1,54):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t
ddx(1,55):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x3t
ddx(1,56):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x2t
ddx(1,57):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3xt
ddx(1,58):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4t
ddx(1,59):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x3t
ddx(1,60):=(*sq (((((ext 90) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x2t
ddx(1,61):=(*sq (((((ext 91) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3xt
ddx(1,62):=(*sq (((((ext 92) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x3t
ddx(1,63):=(*sq (((((ext 90) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x2t
ddx(1,64):=(*sq (((((ext 91) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3xt
ddx(1,65):=(*sq (((((ext 92) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x
ddx(1,66):=(*sq (((((ext 97) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4t
ddx(1,67):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x3t
ddx(1,68):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x2t
ddx(1,69):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3xt
ddx(1,70):=(*sq (((((ext 102) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x3t
ddx(1,71):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x2t
ddx(1,72):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3xt
ddx(1,73):=(*sq (((((ext 102) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4x
ddx(1,74):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4t
ddx(1,75):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x3t
ddx(1,76):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x2t
ddx(1,77):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3xt
ddx(1,78):=(*sq (((((ext 112) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x3t
ddx(1,79):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x2t
ddx(1,80):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3xt
ddx(1,81):=(*sq (((((ext 112) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4x
ddx(1,82):=(*sq (((((ext 117) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t
ddx(1,83):=(*sq (((((ext 119) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x4t
ddx(1,84):=(*sq (((((ext 120) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x3t
ddx(1,85):=(*sq (((((ext 121) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x2t
ddx(1,86):=(*sq (((((ext 122) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4xt
ddx(1,87):=(*sq (((((ext 123) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5t
ddx(1,88):=(*sq (((((ext 125) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x4t
ddx(1,89):=(*sq (((((ext 126) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x3t
ddx(1,90):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x2t
ddx(1,91):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4xt
ddx(1,92):=(*sq (((((ext 129) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x4t
ddx(1,93):=(*sq (((((ext 126) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x3t
ddx(1,94):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x2t
ddx(1,95):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4xt
ddx(1,96):=(*sq (((((ext 129) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x
ddx(1,97):=(*sq (((((ext 135) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_5t
ddx(1,98):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x4t
ddx(1,99):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x3t
ddx(1,100):=(*sq (((((ext 139) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x2t
ddx(1,101):=(*sq (((((ext 140) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4xt
ddx(1,102):=(*sq (((((ext 141) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x4t
ddx(1,103):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x3t
ddx(1,104):=(*sq (((((ext 139) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x2t
ddx(1,105):=(*sq (((((ext 140) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4xt
ddx(1,106):=(*sq (((((ext 141) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_5x
ddx(1,107):=(*sq (((((ext 147) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_5t
ddx(1,108):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x4t
ddx(1,109):=(*sq (((((ext 150) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x3t
ddx(1,110):=(*sq (((((ext 151) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x2t
ddx(1,111):=(*sq (((((ext 152) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4xt
ddx(1,112):=(*sq (((((ext 153) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x4t
ddx(1,113):=(*sq (((((ext 150) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x3t
ddx(1,114):=(*sq (((((ext 151) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x2t
ddx(1,115):=(*sq (((((ext 152) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4xt
ddx(1,116):=(*sq (((((ext 153) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_5x
ddx(1,117):=(*sq (((((ext 159) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t
ddx(1,118):=(*sq (((((ext 161) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x5t
ddx(1,119):=(*sq (((((ext 162) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x4t
ddx(1,120):=(*sq (((((ext 163) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x3t
ddx(1,121):=(*sq (((((ext 164) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x2t
ddx(1,122):=(*sq (((((ext 165) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5xt
ddx(1,123):=(*sq (((((ext 166) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6t
ddx(1,124):=(*sq (((((ext 168) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x5t
ddx(1,125):=(*sq (((((ext 169) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x4t
ddx(1,126):=(*sq (((((ext 170) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x3t
ddx(1,127):=(*sq (((((ext 171) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x2t
ddx(1,128):=(*sq (((((ext 172) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5xt
ddx(1,129):=(*sq (((((ext 173) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x5t
ddx(1,130):=(*sq (((((ext 169) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x4t
ddx(1,131):=(*sq (((((ext 170) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x3t
ddx(1,132):=(*sq (((((ext 171) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x2t
ddx(1,133):=(*sq (((((ext 172) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5xt
ddx(1,134):=(*sq (((((ext 173) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6x
ddx(1,135):=(*sq (((((ext 180) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_6t
ddx(1,136):=(*sq (((((ext 182) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x5t
ddx(1,137):=(*sq (((((ext 183) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x4t
ddx(1,138):=(*sq (((((ext 184) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x3t
ddx(1,139):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4x2t
ddx(1,140):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_5xt
ddx(1,141):=(*sq (((((ext 187) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x5t
ddx(1,142):=(*sq (((((ext 183) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x4t
ddx(1,143):=(*sq (((((ext 184) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x3t
ddx(1,144):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4x2t
ddx(1,145):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_5xt
ddx(1,146):=(*sq (((((ext 187) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_6x
ddx(1,147):=(*sq (((((ext 194) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_6t
ddx(1,148):=(*sq (((((ext 196) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x5t
ddx(1,149):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x4t
ddx(1,150):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x3t
ddx(1,151):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4x2t
ddx(1,152):=(*sq (((((ext 200) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_5xt
ddx(1,153):=(*sq (((((ext 201) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x5t
ddx(1,154):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x4t
ddx(1,155):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x3t
ddx(1,156):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4x2t
ddx(1,157):=(*sq (((((ext 200) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_5xt
ddx(1,158):=(*sq (((((ext 201) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_6x
ddx(1,159):=(*sq (((((ext 208) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7t
ddx(1,160):=(*sq (((((ext 210) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x6t
ddx(1,161):=(*sq (((((ext 211) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x5t
ddx(1,162):=(*sq (((((ext 212) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x4t
ddx(1,163):=(*sq (((((ext 213) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x3t
ddx(1,164):=(*sq (((((ext 214) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x2t
ddx(1,165):=(*sq (((((ext 215) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6xt
ddx(1,166):=(*sq (((((ext 216) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_7t
ddx(1,167):=(*sq (((((ext 218) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x6t
ddx(1,168):=(*sq (((((ext 219) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x5t
ddx(1,169):=(*sq (((((ext 220) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x4t
ddx(1,170):=(*sq (((((ext 221) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x3t
ddx(1,171):=(*sq (((((ext 222) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x2t
ddx(1,172):=(*sq (((((ext 223) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6xt
ddx(1,173):=(*sq (((((ext 224) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x6t
ddx(1,174):=(*sq (((((ext 219) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x5t
ddx(1,175):=(*sq (((((ext 220) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x4t
ddx(1,176):=(*sq (((((ext 221) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x3t
ddx(1,177):=(*sq (((((ext 222) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x2t
ddx(1,178):=(*sq (((((ext 223) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6xt
ddx(1,179):=(*sq (((((ext 224) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_7x
ddx(1,180):=(*sq (((((ext 225) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_7t
ddx(1,181):=(*sq (((((ext 227) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x6t
ddx(1,182):=(*sq (((((ext 228) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x5t
ddx(1,183):=(*sq (((((ext 229) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x4t
ddx(1,184):=(*sq (((((ext 230) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4x3t
ddx(1,185):=(*sq (((((ext 231) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_5x2t
ddx(1,186):=(*sq (((((ext 232) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_6xt
ddx(1,187):=(*sq (((((ext 233) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x6t
ddx(1,188):=(*sq (((((ext 228) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x5t
ddx(1,189):=(*sq (((((ext 229) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x4t
ddx(1,190):=(*sq (((((ext 230) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4x3t
ddx(1,191):=(*sq (((((ext 231) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_5x2t
ddx(1,192):=(*sq (((((ext 232) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_6xt
ddx(1,193):=(*sq (((((ext 233) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_7x
ddx(1,194):=(*sq (((((ext 234) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_7t
ddx(1,195):=(*sq (((((ext 236) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x6t
ddx(1,196):=(*sq (((((ext 237) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x5t
ddx(1,197):=(*sq (((((ext 238) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x4t
ddx(1,198):=(*sq (((((ext 239) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4x3t
ddx(1,199):=(*sq (((((ext 240) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_5x2t
ddx(1,200):=(*sq (((((ext 241) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_6xt
ddx(1,201):=(*sq (((((ext 242) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x6t
ddx(1,202):=(*sq (((((ext 237) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x5t
ddx(1,203):=(*sq (((((ext 238) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x4t
ddx(1,204):=(*sq (((((ext 239) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4x3t
ddx(1,205):=(*sq (((((ext 240) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_5x2t
ddx(1,206):=(*sq (((((ext 241) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_6xt
ddx(1,207):=(*sq (((((ext 242) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_7x
ddx(1,208):=(*sq (((((ext 243) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8t
ddx(1,209):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x7t
ddx(1,210):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x6t
ddx(1,211):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x5t
ddx(1,212):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x4t
ddx(1,213):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x3t
ddx(1,214):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x2t
ddx(1,215):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7xt
ddx(1,216):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_8t
ddx(1,217):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x7t
ddx(1,218):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x6t
ddx(1,219):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x5t
ddx(1,220):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x4t
ddx(1,221):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x3t
ddx(1,222):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6x2t
ddx(1,223):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_7xt
ddx(1,224):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_8x
ddx(1,225):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_8t
ddx(1,226):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_x7t
ddx(1,227):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_2x6t
ddx(1,228):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_3x5t
ddx(1,229):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_4x4t
ddx(1,230):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_5x3t
ddx(1,231):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_6x2t
ddx(1,232):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_7xt
ddx(1,233):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r2_8x
ddx(1,234):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_8t
ddx(1,235):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_x7t
ddx(1,236):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_2x6t
ddx(1,237):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_3x5t
ddx(1,238):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_4x4t
ddx(1,239):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_5x3t
ddx(1,240):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_6x2t
ddx(1,241):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_7xt
ddx(1,242):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r3_8x
ddx(1,243):=(*sq ((((letop . 1) . 1)) . 1) t)
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
ddt(0,9):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7x
ddt(0,10):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,12):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,13):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_xt
ddt(0,14):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,15):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x2t
ddt(0,16):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2xt
ddt(0,17):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,18):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x3t
ddt(0,19):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x2t
ddt(0,20):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3xt
ddt(0,21):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,22):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x4t
ddt(0,23):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x3t
ddt(0,24):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x2t
ddt(0,25):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4xt
ddt(0,26):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,27):=(*sq ((((u_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x5t
ddt(0,28):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x4t
ddt(0,29):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x3t
ddt(0,30):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x2t
ddt(0,31):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5xt
ddt(0,32):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t
ddt(0,33):=(*sq ((((u_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x6t
ddt(0,34):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x5t
ddt(0,35):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x4t
ddt(0,36):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x3t
ddt(0,37):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x2t
ddt(0,38):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6xt
ddt(0,39):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t
ddt(0,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x7t
ddt(0,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x6t
ddt(0,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x5t
ddt(0,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x4t
ddt(0,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x3t
ddt(0,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x2t
ddt(0,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7xt
ddt(0,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p
ddt(1,1):=(*sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1))) . 1) t)
% component of ddt w.r.t. r1
ddt(1,2):=(*sq (((((ext 6) . 1) ((t . 1) ((u_x . 1) . 1)) . 1) (((ext 5) . 1) ((
t . 1) ((u_2x . 1) . -1))) (((ext 1) . 1) ((t . 1) ((u . 1) ((u_x . 1) . 1)) ((
u_3x . 1) . 1)) ((u . 1) . 1))) . 1) t)
% component of ddt w.r.t. r2
ddt(1,3):=(*sq (((((ext 6) . 1) ((u_x . 1) . 1)) (((ext 5) . 1) ((u_2x . 1) . -1
)) (((ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) . 1) t)
% component of ddt w.r.t. r3
ddt(1,4):=(*sq (((((ext 6) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1)) (((
ext 5) . 1) ((u . 1) ((u_2x . 1) . -1)) ((u_4x . 1) . -1) ((u_x . 2) . -1)) (((
ext 1) . 1) ((u . 2) ((u_x . 1) . 1)) ((u . 1) ((u_3x . 1) . 2)) ((u_2x . 1) ((
u_x . 1) . 3)) ((u_5x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_x
ddt(1,5):=(*sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1
) ((u_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_2x
ddt(1,6):=(*sq (((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1
) ((u_x . 1) . 2)) (((ext 5) . 1) ((u_2x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_3x
ddt(1,7):=(*sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((u . 1) . 1)) (((ext 7) .
1) ((u_x . 1) . 3)) (((ext 6) . 1) ((u_2x . 1) . 3)) (((ext 5) . 1) ((u_3x . 1)
. 1))) . 1) t)
% component of ddt w.r.t. p_4x
ddt(1,8):=(*sq (((((ext 11) . 1) . 1) (((ext 9) . 1) ((u . 1) . 1)) (((ext 8) .
1) ((u_x . 1) . 4)) (((ext 7) . 1) ((u_2x . 1) . 6)) (((ext 6) . 1) ((u_3x . 1)
. 4)) (((ext 5) . 1) ((u_4x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_5x
ddt(1,9):=(*sq (((((ext 12) . 1) . 1) (((ext 10) . 1) ((u . 1) . 1)) (((ext 9) .
1) ((u_x . 1) . 5)) (((ext 8) . 1) ((u_2x . 1) . 10)) (((ext 7) . 1) ((u_3x . 1)
. 10)) (((ext 6) . 1) ((u_4x . 1) . 5)) (((ext 5) . 1) ((u_5x . 1) . 1))) . 1) t
)
% component of ddt w.r.t. p_6x
ddt(1,10):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7x
ddt(1,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8x
ddt(1,12):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t
ddt(1,13):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_t
ddt(1,14):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x
ddt(1,15):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_t
ddt(1,16):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x
ddt(1,17):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_t
ddt(1,18):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x
ddt(1,19):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t
ddt(1,20):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_xt
ddt(1,21):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2t
ddt(1,22):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_xt
ddt(1,23):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_xt
ddt(1,24):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x
ddt(1,25):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2t
ddt(1,26):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_xt
ddt(1,27):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_xt
ddt(1,28):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x
ddt(1,29):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2t
ddt(1,30):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_xt
ddt(1,31):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_xt
ddt(1,32):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x
ddt(1,33):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t
ddt(1,34):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x2t
ddt(1,35):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2xt
ddt(1,36):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3t
ddt(1,37):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x2t
ddt(1,38):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2xt
ddt(1,39):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x2t
ddt(1,40):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2xt
ddt(1,41):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x
ddt(1,42):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3t
ddt(1,43):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x2t
ddt(1,44):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2xt
ddt(1,45):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x2t
ddt(1,46):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2xt
ddt(1,47):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x
ddt(1,48):=(*sq (((((ext 70) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3t
ddt(1,49):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x2t
ddt(1,50):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2xt
ddt(1,51):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x2t
ddt(1,52):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2xt
ddt(1,53):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x
ddt(1,54):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t
ddt(1,55):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x3t
ddt(1,56):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x2t
ddt(1,57):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3xt
ddt(1,58):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4t
ddt(1,59):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x3t
ddt(1,60):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x2t
ddt(1,61):=(*sq (((((ext 90) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3xt
ddt(1,62):=(*sq (((((ext 91) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x3t
ddt(1,63):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x2t
ddt(1,64):=(*sq (((((ext 90) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3xt
ddt(1,65):=(*sq (((((ext 91) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x
ddt(1,66):=(*sq (((((ext 92) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4t
ddt(1,67):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x3t
ddt(1,68):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x2t
ddt(1,69):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3xt
ddt(1,70):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x3t
ddt(1,71):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x2t
ddt(1,72):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3xt
ddt(1,73):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4x
ddt(1,74):=(*sq (((((ext 102) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4t
ddt(1,75):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x3t
ddt(1,76):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x2t
ddt(1,77):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3xt
ddt(1,78):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x3t
ddt(1,79):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x2t
ddt(1,80):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3xt
ddt(1,81):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4x
ddt(1,82):=(*sq (((((ext 112) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t
ddt(1,83):=(*sq (((((ext 118) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x4t
ddt(1,84):=(*sq (((((ext 119) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x3t
ddt(1,85):=(*sq (((((ext 120) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x2t
ddt(1,86):=(*sq (((((ext 121) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4xt
ddt(1,87):=(*sq (((((ext 122) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5t
ddt(1,88):=(*sq (((((ext 124) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x4t
ddt(1,89):=(*sq (((((ext 125) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x3t
ddt(1,90):=(*sq (((((ext 126) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x2t
ddt(1,91):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4xt
ddt(1,92):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x4t
ddt(1,93):=(*sq (((((ext 125) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x3t
ddt(1,94):=(*sq (((((ext 126) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x2t
ddt(1,95):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4xt
ddt(1,96):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x
ddt(1,97):=(*sq (((((ext 129) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_5t
ddt(1,98):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x4t
ddt(1,99):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x3t
ddt(1,100):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x2t
ddt(1,101):=(*sq (((((ext 139) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4xt
ddt(1,102):=(*sq (((((ext 140) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x4t
ddt(1,103):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x3t
ddt(1,104):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x2t
ddt(1,105):=(*sq (((((ext 139) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4xt
ddt(1,106):=(*sq (((((ext 140) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_5x
ddt(1,107):=(*sq (((((ext 141) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_5t
ddt(1,108):=(*sq (((((ext 148) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x4t
ddt(1,109):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x3t
ddt(1,110):=(*sq (((((ext 150) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x2t
ddt(1,111):=(*sq (((((ext 151) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4xt
ddt(1,112):=(*sq (((((ext 152) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x4t
ddt(1,113):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x3t
ddt(1,114):=(*sq (((((ext 150) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x2t
ddt(1,115):=(*sq (((((ext 151) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4xt
ddt(1,116):=(*sq (((((ext 152) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_5x
ddt(1,117):=(*sq (((((ext 153) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t
ddt(1,118):=(*sq (((((ext 160) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x5t
ddt(1,119):=(*sq (((((ext 161) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x4t
ddt(1,120):=(*sq (((((ext 162) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x3t
ddt(1,121):=(*sq (((((ext 163) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x2t
ddt(1,122):=(*sq (((((ext 164) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5xt
ddt(1,123):=(*sq (((((ext 165) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6t
ddt(1,124):=(*sq (((((ext 167) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x5t
ddt(1,125):=(*sq (((((ext 168) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x4t
ddt(1,126):=(*sq (((((ext 169) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x3t
ddt(1,127):=(*sq (((((ext 170) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x2t
ddt(1,128):=(*sq (((((ext 171) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5xt
ddt(1,129):=(*sq (((((ext 172) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x5t
ddt(1,130):=(*sq (((((ext 168) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x4t
ddt(1,131):=(*sq (((((ext 169) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x3t
ddt(1,132):=(*sq (((((ext 170) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x2t
ddt(1,133):=(*sq (((((ext 171) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5xt
ddt(1,134):=(*sq (((((ext 172) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6x
ddt(1,135):=(*sq (((((ext 173) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_6t
ddt(1,136):=(*sq (((((ext 181) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x5t
ddt(1,137):=(*sq (((((ext 182) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x4t
ddt(1,138):=(*sq (((((ext 183) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x3t
ddt(1,139):=(*sq (((((ext 184) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4x2t
ddt(1,140):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_5xt
ddt(1,141):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x5t
ddt(1,142):=(*sq (((((ext 182) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x4t
ddt(1,143):=(*sq (((((ext 183) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x3t
ddt(1,144):=(*sq (((((ext 184) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4x2t
ddt(1,145):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_5xt
ddt(1,146):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_6x
ddt(1,147):=(*sq (((((ext 187) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_6t
ddt(1,148):=(*sq (((((ext 195) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x5t
ddt(1,149):=(*sq (((((ext 196) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x4t
ddt(1,150):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x3t
ddt(1,151):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4x2t
ddt(1,152):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_5xt
ddt(1,153):=(*sq (((((ext 200) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x5t
ddt(1,154):=(*sq (((((ext 196) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x4t
ddt(1,155):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x3t
ddt(1,156):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4x2t
ddt(1,157):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_5xt
ddt(1,158):=(*sq (((((ext 200) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_6x
ddt(1,159):=(*sq (((((ext 201) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7t
ddt(1,160):=(*sq (((((ext 209) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x6t
ddt(1,161):=(*sq (((((ext 210) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x5t
ddt(1,162):=(*sq (((((ext 211) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x4t
ddt(1,163):=(*sq (((((ext 212) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x3t
ddt(1,164):=(*sq (((((ext 213) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x2t
ddt(1,165):=(*sq (((((ext 214) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6xt
ddt(1,166):=(*sq (((((ext 215) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_7t
ddt(1,167):=(*sq (((((ext 217) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x6t
ddt(1,168):=(*sq (((((ext 218) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x5t
ddt(1,169):=(*sq (((((ext 219) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x4t
ddt(1,170):=(*sq (((((ext 220) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x3t
ddt(1,171):=(*sq (((((ext 221) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x2t
ddt(1,172):=(*sq (((((ext 222) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6xt
ddt(1,173):=(*sq (((((ext 223) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x6t
ddt(1,174):=(*sq (((((ext 218) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x5t
ddt(1,175):=(*sq (((((ext 219) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x4t
ddt(1,176):=(*sq (((((ext 220) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x3t
ddt(1,177):=(*sq (((((ext 221) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x2t
ddt(1,178):=(*sq (((((ext 222) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6xt
ddt(1,179):=(*sq (((((ext 223) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_7x
ddt(1,180):=(*sq (((((ext 224) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_7t
ddt(1,181):=(*sq (((((ext 226) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x6t
ddt(1,182):=(*sq (((((ext 227) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x5t
ddt(1,183):=(*sq (((((ext 228) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x4t
ddt(1,184):=(*sq (((((ext 229) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4x3t
ddt(1,185):=(*sq (((((ext 230) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_5x2t
ddt(1,186):=(*sq (((((ext 231) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_6xt
ddt(1,187):=(*sq (((((ext 232) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x6t
ddt(1,188):=(*sq (((((ext 227) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x5t
ddt(1,189):=(*sq (((((ext 228) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x4t
ddt(1,190):=(*sq (((((ext 229) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4x3t
ddt(1,191):=(*sq (((((ext 230) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_5x2t
ddt(1,192):=(*sq (((((ext 231) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_6xt
ddt(1,193):=(*sq (((((ext 232) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_7x
ddt(1,194):=(*sq (((((ext 233) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_7t
ddt(1,195):=(*sq (((((ext 235) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x6t
ddt(1,196):=(*sq (((((ext 236) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x5t
ddt(1,197):=(*sq (((((ext 237) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x4t
ddt(1,198):=(*sq (((((ext 238) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4x3t
ddt(1,199):=(*sq (((((ext 239) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_5x2t
ddt(1,200):=(*sq (((((ext 240) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_6xt
ddt(1,201):=(*sq (((((ext 241) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x6t
ddt(1,202):=(*sq (((((ext 236) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x5t
ddt(1,203):=(*sq (((((ext 237) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x4t
ddt(1,204):=(*sq (((((ext 238) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4x3t
ddt(1,205):=(*sq (((((ext 239) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_5x2t
ddt(1,206):=(*sq (((((ext 240) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_6xt
ddt(1,207):=(*sq (((((ext 241) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_7x
ddt(1,208):=(*sq (((((ext 242) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8t
ddt(1,209):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x7t
ddt(1,210):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x6t
ddt(1,211):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x5t
ddt(1,212):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x4t
ddt(1,213):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x3t
ddt(1,214):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x2t
ddt(1,215):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7xt
ddt(1,216):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_8t
ddt(1,217):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x7t
ddt(1,218):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x6t
ddt(1,219):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x5t
ddt(1,220):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x4t
ddt(1,221):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x3t
ddt(1,222):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6x2t
ddt(1,223):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_7xt
ddt(1,224):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_8x
ddt(1,225):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_8t
ddt(1,226):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_x7t
ddt(1,227):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_2x6t
ddt(1,228):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_3x5t
ddt(1,229):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_4x4t
ddt(1,230):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_5x3t
ddt(1,231):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_6x2t
ddt(1,232):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_7xt
ddt(1,233):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r2_8x
ddt(1,234):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_8t
ddt(1,235):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_x7t
ddt(1,236):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_2x6t
ddt(1,237):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_3x5t
ddt(1,238):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_4x4t
ddt(1,239):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_5x3t
ddt(1,240):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_6x2t
ddt(1,241):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_7xt
ddt(1,242):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r3_8x
ddt(1,243):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
