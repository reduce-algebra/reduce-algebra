% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t)
de!*:=((plus (times 2 u u_x) u_2x))
% odd equation
principal_odd!*:=(g0001_10x)
de_odd!*(letop)
% Settings:
indep_var!*:=(x t)
dep_var!*:=(u)
odd_var!*:=(g0001)
deg_indep_var!*:=nil
deg_dep_var!*:=nil
deg_odd_var!*:=nil
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
all_odd_mind!*:=((g0001 (0 0)) (g0001 (1 0)) (g0001 (0 1)) (g0001 (2 0)) (g0001
(1 1)) (g0001 (0 2)) (g0001 (3 0)) (g0001 (2 1)) (g0001 (1 2)) (g0001 (0 3)) (
g0001 (4 0)) (g0001 (3 1)) (g0001 (2 2)) (g0001 (1 3)) (g0001 (0 4)) (g0001 (5 0
)) (g0001 (4 1)) (g0001 (3 2)) (g0001 (2 3)) (g0001 (1 4)) (g0001 (0 5)) (g0001
(6 0)) (g0001 (5 1)) (g0001 (4 2)) (g0001 (3 3)) (g0001 (2 4)) (g0001 (1 5)) (
g0001 (0 6)) (g0001 (7 0)) (g0001 (6 1)) (g0001 (5 2)) (g0001 (4 3)) (g0001 (3 4
)) (g0001 (2 5)) (g0001 (1 6)) (g0001 (0 7)) (g0001 (8 0)) (g0001 (7 1)) (g0001
(6 2)) (g0001 (5 3)) (g0001 (4 4)) (g0001 (3 5)) (g0001 (2 6)) (g0001 (1 7)) (
g0001 (0 8)) (g0001 (9 0)) (g0001 (8 1)) (g0001 (7 2)) (g0001 (6 3)) (g0001 (5 4
)) (g0001 (4 5)) (g0001 (3 6)) (g0001 (2 7)) (g0001 (1 8)) (g0001 (0 9)) (g0001
(10 0)) (g0001 (9 1)) (g0001 (8 2)) (g0001 (7 3)) (g0001 (6 4)) (g0001 (5 5)) (
g0001 (4 6)) (g0001 (3 7)) (g0001 (2 8)) (g0001 (1 9)) (g0001 (0 10)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_x u_t u_2x u_xt u_2t u_3x u_2xt u_x2t u_3t u_4x u_3xt u_2x2t
u_x3t u_4t u_5x u_4xt u_3x2t u_2x3t u_x4t u_5t u_6x u_5xt u_4x2t u_3x3t u_2x4t
u_x5t u_6t u_7x u_6xt u_5x2t u_4x3t u_3x4t u_2x5t u_x6t u_7t u_8x u_7xt u_6x2t
u_5x3t u_4x4t u_3x5t u_2x6t u_x7t u_8t u_9x u_8xt u_7x2t u_6x3t u_5x4t u_4x5t
u_3x6t u_2x7t u_x8t u_9t u_10x u_9xt u_8x2t u_7x3t u_6x4t u_5x5t u_4x6t u_3x7t
u_2x8t u_x9t u_10t)
% all odd derivatives in identifier notation:
all_odd_id!*:=(g0001 g0001_x g0001_t g0001_2x g0001_xt g0001_2t g0001_3x
g0001_2xt g0001_x2t g0001_3t g0001_4x g0001_3xt g0001_2x2t g0001_x3t g0001_4t
g0001_5x g0001_4xt g0001_3x2t g0001_2x3t g0001_x4t g0001_5t g0001_6x g0001_5xt
g0001_4x2t g0001_3x3t g0001_2x4t g0001_x5t g0001_6t g0001_7x g0001_6xt
g0001_5x2t g0001_4x3t g0001_3x4t g0001_2x5t g0001_x6t g0001_7t g0001_8x
g0001_7xt g0001_6x2t g0001_5x3t g0001_4x4t g0001_3x5t g0001_2x6t g0001_x7t
g0001_8t g0001_9x g0001_8xt g0001_7x2t g0001_6x3t g0001_5x4t g0001_4x5t
g0001_3x6t g0001_2x7t g0001_x8t g0001_9t g0001_10x g0001_9xt g0001_8x2t
g0001_7x3t g0001_6x4t g0001_5x5t g0001_4x6t g0001_3x7t g0001_2x8t g0001_x9t
g0001_10t)
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
i2m_jetspace_odd!*:=((g0001 g0001 (0 0)) (g0001_x g0001 (1 0)) (g0001_t g0001 (0
1)) (g0001_2x g0001 (2 0)) (g0001_xt g0001 (1 1)) (g0001_2t g0001 (0 2)) (
g0001_3x g0001 (3 0)) (g0001_2xt g0001 (2 1)) (g0001_x2t g0001 (1 2)) (g0001_3t
g0001 (0 3)) (g0001_4x g0001 (4 0)) (g0001_3xt g0001 (3 1)) (g0001_2x2t g0001 (2
2)) (g0001_x3t g0001 (1 3)) (g0001_4t g0001 (0 4)) (g0001_5x g0001 (5 0)) (
g0001_4xt g0001 (4 1)) (g0001_3x2t g0001 (3 2)) (g0001_2x3t g0001 (2 3)) (
g0001_x4t g0001 (1 4)) (g0001_5t g0001 (0 5)) (g0001_6x g0001 (6 0)) (g0001_5xt
g0001 (5 1)) (g0001_4x2t g0001 (4 2)) (g0001_3x3t g0001 (3 3)) (g0001_2x4t g0001
(2 4)) (g0001_x5t g0001 (1 5)) (g0001_6t g0001 (0 6)) (g0001_7x g0001 (7 0)) (
g0001_6xt g0001 (6 1)) (g0001_5x2t g0001 (5 2)) (g0001_4x3t g0001 (4 3)) (
g0001_3x4t g0001 (3 4)) (g0001_2x5t g0001 (2 5)) (g0001_x6t g0001 (1 6)) (
g0001_7t g0001 (0 7)) (g0001_8x g0001 (8 0)) (g0001_7xt g0001 (7 1)) (g0001_6x2t
g0001 (6 2)) (g0001_5x3t g0001 (5 3)) (g0001_4x4t g0001 (4 4)) (g0001_3x5t g0001
(3 5)) (g0001_2x6t g0001 (2 6)) (g0001_x7t g0001 (1 7)) (g0001_8t g0001 (0 8)) (
g0001_9x g0001 (9 0)) (g0001_8xt g0001 (8 1)) (g0001_7x2t g0001 (7 2)) (
g0001_6x3t g0001 (6 3)) (g0001_5x4t g0001 (5 4)) (g0001_4x5t g0001 (4 5)) (
g0001_3x6t g0001 (3 6)) (g0001_2x7t g0001 (2 7)) (g0001_x8t g0001 (1 8)) (
g0001_9t g0001 (0 9)) (g0001_10x g0001 (10 0)) (g0001_9xt g0001 (9 1)) (
g0001_8x2t g0001 (8 2)) (g0001_7x3t g0001 (7 3)) (g0001_6x4t g0001 (6 4)) (
g0001_5x5t g0001 (5 5)) (g0001_4x6t g0001 (4 6)) (g0001_3x7t g0001 (3 7)) (
g0001_2x8t g0001 (2 8)) (g0001_x9t g0001 (1 9)) (g0001_10t g0001 (0 10)))
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
i2o_jetspace_odd!*:=((g0001 . 0) (g0001_x . 1) (g0001_t . 1) (g0001_2x . 2) (
g0001_xt . 2) (g0001_2t . 2) (g0001_3x . 3) (g0001_2xt . 3) (g0001_x2t . 3) (
g0001_3t . 3) (g0001_4x . 4) (g0001_3xt . 4) (g0001_2x2t . 4) (g0001_x3t . 4) (
g0001_4t . 4) (g0001_5x . 5) (g0001_4xt . 5) (g0001_3x2t . 5) (g0001_2x3t . 5) (
g0001_x4t . 5) (g0001_5t . 5) (g0001_6x . 6) (g0001_5xt . 6) (g0001_4x2t . 6) (
g0001_3x3t . 6) (g0001_2x4t . 6) (g0001_x5t . 6) (g0001_6t . 6) (g0001_7x . 7) (
g0001_6xt . 7) (g0001_5x2t . 7) (g0001_4x3t . 7) (g0001_3x4t . 7) (g0001_2x5t .
7) (g0001_x6t . 7) (g0001_7t . 7) (g0001_8x . 8) (g0001_7xt . 8) (g0001_6x2t . 8
) (g0001_5x3t . 8) (g0001_4x4t . 8) (g0001_3x5t . 8) (g0001_2x6t . 8) (g0001_x7t
. 8) (g0001_8t . 8) (g0001_9x . 9) (g0001_8xt . 9) (g0001_7x2t . 9) (g0001_6x3t
. 9) (g0001_5x4t . 9) (g0001_4x5t . 9) (g0001_3x6t . 9) (g0001_2x7t . 9) (
g0001_x8t . 9) (g0001_9t . 9) (g0001_10x . 10) (g0001_9xt . 10) (g0001_8x2t . 10
) (g0001_7x3t . 10) (g0001_6x4t . 10) (g0001_5x5t . 10) (g0001_4x6t . 10) (
g0001_3x7t . 10) (g0001_2x8t . 10) (g0001_x9t . 10) (g0001_10t . 10))
% list of even principal derivatives:
all_principal_der!*:=(u_t u_2t u_xt u_3t u_x2t u_2xt u_4t u_x3t u_2x2t u_3xt
u_5t u_x4t u_2x3t u_3x2t u_4xt u_6t u_x5t u_2x4t u_3x3t u_4x2t u_5xt u_7t u_x6t
u_2x5t u_3x4t u_4x3t u_5x2t u_6xt u_8t u_x7t u_2x6t u_3x5t u_4x4t u_5x3t u_6x2t
u_7xt u_9t u_x8t u_2x7t u_3x6t u_4x5t u_5x4t u_6x3t u_7x2t u_8xt u_10t u_x9t
u_2x8t u_3x7t u_4x6t u_5x5t u_6x4t u_7x3t u_8x2t u_9xt)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_x u_2x u_3x u_4x u_5x u_6x u_7x u_8x u_9x u_10x)
% list of odd principal derivatives:
all_principal_odd!*:=(g0001_10x)
g0001_10x = (ext 66)
% list of odd parametric derivatives:
all_parametric_odd!*:=(g0001 g0001_x g0001_t g0001_2x g0001_xt g0001_2t g0001_3x
g0001_2xt g0001_x2t g0001_3t g0001_4x g0001_3xt g0001_2x2t g0001_x3t g0001_4t
g0001_5x g0001_4xt g0001_3x2t g0001_2x3t g0001_x4t g0001_5t g0001_6x g0001_5xt
g0001_4x2t g0001_3x3t g0001_2x4t g0001_x5t g0001_6t g0001_7x g0001_6xt
g0001_5x2t g0001_4x3t g0001_3x4t g0001_2x5t g0001_x6t g0001_7t g0001_8x
g0001_7xt g0001_6x2t g0001_5x3t g0001_4x4t g0001_3x5t g0001_2x6t g0001_x7t
g0001_8t g0001_9x g0001_8xt g0001_7x2t g0001_6x3t g0001_5x4t g0001_4x5t
g0001_3x6t g0001_2x7t g0001_x8t g0001_9t g0001_9xt g0001_8x2t g0001_7x3t
g0001_6x4t g0001_5x5t g0001_4x6t g0001_3x7t g0001_2x8t g0001_x9t g0001_10t)
g0001 = (ext 1)
g0001_x = (ext 2)
g0001_t = (ext 3)
g0001_2x = (ext 4)
g0001_xt = (ext 5)
g0001_2t = (ext 6)
g0001_3x = (ext 7)
g0001_2xt = (ext 8)
g0001_x2t = (ext 9)
g0001_3t = (ext 10)
g0001_4x = (ext 11)
g0001_3xt = (ext 12)
g0001_2x2t = (ext 13)
g0001_x3t = (ext 14)
g0001_4t = (ext 15)
g0001_5x = (ext 16)
g0001_4xt = (ext 17)
g0001_3x2t = (ext 18)
g0001_2x3t = (ext 19)
g0001_x4t = (ext 20)
g0001_5t = (ext 21)
g0001_6x = (ext 22)
g0001_5xt = (ext 23)
g0001_4x2t = (ext 24)
g0001_3x3t = (ext 25)
g0001_2x4t = (ext 26)
g0001_x5t = (ext 27)
g0001_6t = (ext 28)
g0001_7x = (ext 29)
g0001_6xt = (ext 30)
g0001_5x2t = (ext 31)
g0001_4x3t = (ext 32)
g0001_3x4t = (ext 33)
g0001_2x5t = (ext 34)
g0001_x6t = (ext 35)
g0001_7t = (ext 36)
g0001_8x = (ext 37)
g0001_7xt = (ext 38)
g0001_6x2t = (ext 39)
g0001_5x3t = (ext 40)
g0001_4x4t = (ext 41)
g0001_3x5t = (ext 42)
g0001_2x6t = (ext 43)
g0001_x7t = (ext 44)
g0001_8t = (ext 45)
g0001_9x = (ext 46)
g0001_8xt = (ext 47)
g0001_7x2t = (ext 48)
g0001_6x3t = (ext 49)
g0001_5x4t = (ext 50)
g0001_4x5t = (ext 51)
g0001_3x6t = (ext 52)
g0001_2x7t = (ext 53)
g0001_x8t = (ext 54)
g0001_9t = (ext 55)
g0001_9xt = (ext 56)
g0001_8x2t = (ext 57)
g0001_7x3t = (ext 58)
g0001_6x4t = (ext 59)
g0001_5x5t = (ext 60)
g0001_4x6t = (ext 61)
g0001_3x7t = (ext 62)
g0001_2x8t = (ext 63)
g0001_x9t = (ext 64)
g0001_10t = (ext 65)
% number of ext principal derivatives:
n_all_principal_ext:=1
% number of ext parametric derivatives:
n_all_parametric_ext:=65
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddt)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 u_xt) (ddt 0 5 u_2xt) (ddt 0
6 u_3xt) (ddt 0 7 u_4xt) (ddt 0 8 u_5xt) (ddt 0 9 u_6xt) (ddt 0 10 u_7xt) (ddt 0
11 u_8xt) (ddt 0 12 u_9xt))
primary_diffcon_odd_tot!*:=((ddx 1 46 g0001_10x))
primary_diffcon_der!*:=(u_xt u_2xt u_3xt u_4xt u_5xt u_6xt u_7xt u_8xt u_9xt)
primary_diffcon_odd!*:=nil
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_9xt (*sq ((((letop . 1) . 1)) . 1) nil)) (u_8xt (*sq ((((u .
1) ((u_9x . 1) . 2)) ((u_10x . 1) . 1) ((u_2x . 1) ((u_7x . 1) . 72)) ((u_3x . 1
) ((u_6x . 1) . 168)) ((u_4x . 1) ((u_5x . 1) . 252)) ((u_8x . 1) ((u_x . 1) .
18))) . 1) nil)) (u_7xt (*sq ((((u . 1) ((u_8x . 1) . 2)) ((u_2x . 1) ((u_6x . 1
) . 56)) ((u_3x . 1) ((u_5x . 1) . 112)) ((u_4x . 2) . 70) ((u_7x . 1) ((u_x . 1
) . 16)) ((u_9x . 1) . 1)) . 1) nil)) (u_6xt (*sq ((((u . 1) ((u_7x . 1) . 2)) (
(u_2x . 1) ((u_5x . 1) . 42)) ((u_3x . 1) ((u_4x . 1) . 70)) ((u_6x . 1) ((u_x .
1) . 14)) ((u_8x . 1) . 1)) . 1) nil)) (u_5xt (*sq ((((u . 1) ((u_6x . 1) . 2))
((u_2x . 1) ((u_4x . 1) . 30)) ((u_3x . 2) . 20) ((u_5x . 1) ((u_x . 1) . 12)) (
(u_7x . 1) . 1)) . 1) nil)) (u_4xt (*sq ((((u . 1) ((u_5x . 1) . 2)) ((u_2x . 1)
((u_3x . 1) . 20)) ((u_4x . 1) ((u_x . 1) . 10)) ((u_6x . 1) . 1)) . 1) nil)) (
u_3xt (*sq ((((u . 1) ((u_4x . 1) . 2)) ((u_2x . 2) . 6) ((u_3x . 1) ((u_x . 1)
. 8)) ((u_5x . 1) . 1)) . 1) nil)) (u_2xt (*sq ((((u . 1) ((u_3x . 1) . 2)) ((
u_2x . 1) ((u_x . 1) . 6)) ((u_4x . 1) . 1)) . 1) nil)) (u_xt (*sq ((((u . 1) ((
u_2x . 1) . 2)) ((u_3x . 1) . 1) ((u_x . 2) . 2)) . 1) nil)) (u_t (plus (times 2
u u_x) u_2x)))
diffcon_odd!*:=((g0001_10x letop))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_9xt u_8xt u_7xt u_6xt u_5xt u_4xt u_3xt u_2xt u_xt u_t)
diffcon_comp_odd!*:=(g0001_10x)
diffcon_comp_ext!*:=((ext 66))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_9xt *sq ((((letop . 1) . 1)) . 1) nil) (u_8xt *sq ((((u
. 1) ((u_9x . 1) . 2)) ((u_10x . 1) . 1) ((u_2x . 1) ((u_7x . 1) . 72)) ((u_3x .
1) ((u_6x . 1) . 168)) ((u_4x . 1) ((u_5x . 1) . 252)) ((u_8x . 1) ((u_x . 1) .
18))) . 1) nil) (u_7xt *sq ((((u . 1) ((u_8x . 1) . 2)) ((u_2x . 1) ((u_6x . 1)
. 56)) ((u_3x . 1) ((u_5x . 1) . 112)) ((u_4x . 2) . 70) ((u_7x . 1) ((u_x . 1)
. 16)) ((u_9x . 1) . 1)) . 1) nil) (u_6xt *sq ((((u . 1) ((u_7x . 1) . 2)) ((
u_2x . 1) ((u_5x . 1) . 42)) ((u_3x . 1) ((u_4x . 1) . 70)) ((u_6x . 1) ((u_x .
1) . 14)) ((u_8x . 1) . 1)) . 1) nil) (u_5xt *sq ((((u . 1) ((u_6x . 1) . 2)) ((
u_2x . 1) ((u_4x . 1) . 30)) ((u_3x . 2) . 20) ((u_5x . 1) ((u_x . 1) . 12)) ((
u_7x . 1) . 1)) . 1) nil) (u_4xt *sq ((((u . 1) ((u_5x . 1) . 2)) ((u_2x . 1) ((
u_3x . 1) . 20)) ((u_4x . 1) ((u_x . 1) . 10)) ((u_6x . 1) . 1)) . 1) nil) (
u_3xt *sq ((((u . 1) ((u_4x . 1) . 2)) ((u_2x . 2) . 6) ((u_3x . 1) ((u_x . 1) .
8)) ((u_5x . 1) . 1)) . 1) nil) (u_2xt *sq ((((u . 1) ((u_3x . 1) . 2)) ((u_2x .
1) ((u_x . 1) . 6)) ((u_4x . 1) . 1)) . 1) nil) (u_xt *sq ((((u . 1) ((u_2x . 1)
. 2)) ((u_3x . 1) . 1) ((u_x . 2) . 2)) . 1) nil) (u_t *sq ((((u . 1) ((u_x . 1)
. 2)) ((u_2x . 1) . 1)) . 1) nil))
diffcon_param_ext!*:=(((ext 66) *sq ((((letop . 1) . 1)) . 1) nil))
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
% component of ddx w.r.t. g0001
ddx(1,1):=(*sq (((((ext 2) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x
ddx(1,2):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_t
ddx(1,3):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x
ddx(1,4):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_xt
ddx(1,5):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2t
ddx(1,6):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3x
ddx(1,7):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2xt
ddx(1,8):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x2t
ddx(1,9):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3t
ddx(1,10):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4x
ddx(1,11):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3xt
ddx(1,12):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x2t
ddx(1,13):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x3t
ddx(1,14):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4t
ddx(1,15):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_5x
ddx(1,16):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4xt
ddx(1,17):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3x2t
ddx(1,18):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x3t
ddx(1,19):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x4t
ddx(1,20):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_5t
ddx(1,21):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_6x
ddx(1,22):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_5xt
ddx(1,23):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4x2t
ddx(1,24):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3x3t
ddx(1,25):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x4t
ddx(1,26):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x5t
ddx(1,27):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_6t
ddx(1,28):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_7x
ddx(1,29):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_6xt
ddx(1,30):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_5x2t
ddx(1,31):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4x3t
ddx(1,32):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3x4t
ddx(1,33):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x5t
ddx(1,34):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x6t
ddx(1,35):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_7t
ddx(1,36):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_8x
ddx(1,37):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_7xt
ddx(1,38):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_6x2t
ddx(1,39):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_5x3t
ddx(1,40):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4x4t
ddx(1,41):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3x5t
ddx(1,42):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x6t
ddx(1,43):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x7t
ddx(1,44):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_8t
ddx(1,45):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_9x
ddx(1,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_8xt
ddx(1,47):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_7x2t
ddx(1,48):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_6x3t
ddx(1,49):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_5x4t
ddx(1,50):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4x5t
ddx(1,51):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3x6t
ddx(1,52):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x7t
ddx(1,53):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x8t
ddx(1,54):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_9t
ddx(1,55):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_9xt
ddx(1,56):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_8x2t
ddx(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_7x3t
ddx(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_6x4t
ddx(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_5x5t
ddx(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_4x6t
ddx(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_3x7t
ddx(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_2x8t
ddx(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_x9t
ddx(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_10t
ddx(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. g0001_10x
ddx(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. x
ddt(0,1):=0
% component of ddt w.r.t. t
ddt(0,2):=1
% component of ddt w.r.t. u
ddt(0,3):=(*sq ((((u . 1) ((u_x . 1) . 2)) ((u_2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,4):=(*sq ((((u . 1) ((u_2x . 1) . 2)) ((u_3x . 1) . 1) ((u_x . 2) . 2)) .
1) t)
% component of ddt w.r.t. u_2x
ddt(0,5):=(*sq ((((u . 1) ((u_3x . 1) . 2)) ((u_2x . 1) ((u_x . 1) . 6)) ((u_4x
. 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,6):=(*sq ((((u . 1) ((u_4x . 1) . 2)) ((u_2x . 2) . 6) ((u_3x . 1) ((u_x .
1) . 8)) ((u_5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,7):=(*sq ((((u . 1) ((u_5x . 1) . 2)) ((u_2x . 1) ((u_3x . 1) . 20)) ((
u_4x . 1) ((u_x . 1) . 10)) ((u_6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,8):=(*sq ((((u . 1) ((u_6x . 1) . 2)) ((u_2x . 1) ((u_4x . 1) . 30)) ((
u_3x . 2) . 20) ((u_5x . 1) ((u_x . 1) . 12)) ((u_7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,9):=(*sq ((((u . 1) ((u_7x . 1) . 2)) ((u_2x . 1) ((u_5x . 1) . 42)) ((
u_3x . 1) ((u_4x . 1) . 70)) ((u_6x . 1) ((u_x . 1) . 14)) ((u_8x . 1) . 1)) . 1
) t)
% component of ddt w.r.t. u_7x
ddt(0,10):=(*sq ((((u . 1) ((u_8x . 1) . 2)) ((u_2x . 1) ((u_6x . 1) . 56)) ((
u_3x . 1) ((u_5x . 1) . 112)) ((u_4x . 2) . 70) ((u_7x . 1) ((u_x . 1) . 16)) ((
u_9x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,11):=(*sq ((((u . 1) ((u_9x . 1) . 2)) ((u_10x . 1) . 1) ((u_2x . 1) ((
u_7x . 1) . 72)) ((u_3x . 1) ((u_6x . 1) . 168)) ((u_4x . 1) ((u_5x . 1) . 252))
((u_8x . 1) ((u_x . 1) . 18))) . 1) t)
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
% component of ddt w.r.t. g0001
ddt(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x
ddt(1,2):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_t
ddt(1,3):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x
ddt(1,4):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_xt
ddt(1,5):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2t
ddt(1,6):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3x
ddt(1,7):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2xt
ddt(1,8):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x2t
ddt(1,9):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3t
ddt(1,10):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4x
ddt(1,11):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3xt
ddt(1,12):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x2t
ddt(1,13):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x3t
ddt(1,14):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4t
ddt(1,15):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_5x
ddt(1,16):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4xt
ddt(1,17):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3x2t
ddt(1,18):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x3t
ddt(1,19):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x4t
ddt(1,20):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_5t
ddt(1,21):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_6x
ddt(1,22):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_5xt
ddt(1,23):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4x2t
ddt(1,24):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3x3t
ddt(1,25):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x4t
ddt(1,26):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x5t
ddt(1,27):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_6t
ddt(1,28):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_7x
ddt(1,29):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_6xt
ddt(1,30):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_5x2t
ddt(1,31):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4x3t
ddt(1,32):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3x4t
ddt(1,33):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x5t
ddt(1,34):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x6t
ddt(1,35):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_7t
ddt(1,36):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_8x
ddt(1,37):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_7xt
ddt(1,38):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_6x2t
ddt(1,39):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_5x3t
ddt(1,40):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4x4t
ddt(1,41):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3x5t
ddt(1,42):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x6t
ddt(1,43):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x7t
ddt(1,44):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_8t
ddt(1,45):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_9x
ddt(1,46):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_8xt
ddt(1,47):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_7x2t
ddt(1,48):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_6x3t
ddt(1,49):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_5x4t
ddt(1,50):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4x5t
ddt(1,51):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3x6t
ddt(1,52):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x7t
ddt(1,53):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x8t
ddt(1,54):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_9t
ddt(1,55):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_9xt
ddt(1,56):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_8x2t
ddt(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_7x3t
ddt(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_6x4t
ddt(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_5x5t
ddt(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_4x6t
ddt(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_3x7t
ddt(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_2x8t
ddt(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_x9t
ddt(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_10t
ddt(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. g0001_10x
ddt(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
