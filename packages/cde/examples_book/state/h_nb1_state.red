% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t)
de!*:=(u_2x)
% odd equation
principal_odd!*:=(q_t)
de_odd!*(q_2x)
% Settings:
indep_var!*:=(t x)
dep_var!*:=(u)
odd_var!*:=(q)
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
all_odd_mind!*:=((q (0 0)) (q (1 0)) (q (0 1)) (q (2 0)) (q (1 1)) (q (0 2)) (q
(3 0)) (q (2 1)) (q (1 2)) (q (0 3)) (q (4 0)) (q (3 1)) (q (2 2)) (q (1 3)) (q
(0 4)) (q (5 0)) (q (4 1)) (q (3 2)) (q (2 3)) (q (1 4)) (q (0 5)) (q (6 0)) (q
(5 1)) (q (4 2)) (q (3 3)) (q (2 4)) (q (1 5)) (q (0 6)) (q (7 0)) (q (6 1)) (q
(5 2)) (q (4 3)) (q (3 4)) (q (2 5)) (q (1 6)) (q (0 7)) (q (8 0)) (q (7 1)) (q
(6 2)) (q (5 3)) (q (4 4)) (q (3 5)) (q (2 6)) (q (1 7)) (q (0 8)) (q (9 0)) (q
(8 1)) (q (7 2)) (q (6 3)) (q (5 4)) (q (4 5)) (q (3 6)) (q (2 7)) (q (1 8)) (q
(0 9)) (q (10 0)) (q (9 1)) (q (8 2)) (q (7 3)) (q (6 4)) (q (5 5)) (q (4 6)) (q
(3 7)) (q (2 8)) (q (1 9)) (q (0 10)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_t u_x u_2t u_tx u_2x u_3t u_2tx u_t2x u_3x u_4t u_3tx u_2t2x
u_t3x u_4x u_5t u_4tx u_3t2x u_2t3x u_t4x u_5x u_6t u_5tx u_4t2x u_3t3x u_2t4x
u_t5x u_6x u_7t u_6tx u_5t2x u_4t3x u_3t4x u_2t5x u_t6x u_7x u_8t u_7tx u_6t2x
u_5t3x u_4t4x u_3t5x u_2t6x u_t7x u_8x u_9t u_8tx u_7t2x u_6t3x u_5t4x u_4t5x
u_3t6x u_2t7x u_t8x u_9x u_10t u_9tx u_8t2x u_7t3x u_6t4x u_5t5x u_4t6x u_3t7x
u_2t8x u_t9x u_10x)
% all odd derivatives in identifier notation:
all_odd_id!*:=(q q_t q_x q_2t q_tx q_2x q_3t q_2tx q_t2x q_3x q_4t q_3tx q_2t2x
q_t3x q_4x q_5t q_4tx q_3t2x q_2t3x q_t4x q_5x q_6t q_5tx q_4t2x q_3t3x q_2t4x
q_t5x q_6x q_7t q_6tx q_5t2x q_4t3x q_3t4x q_2t5x q_t6x q_7x q_8t q_7tx q_6t2x
q_5t3x q_4t4x q_3t5x q_2t6x q_t7x q_8x q_9t q_8tx q_7t2x q_6t3x q_5t4x q_4t5x
q_3t6x q_2t7x q_t8x q_9x q_10t q_9tx q_8t2x q_7t3x q_6t4x q_5t5x q_4t6x q_3t7x
q_2t8x q_t9x q_10x)
% number of all ext symbols:
n_all_ext:=66
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0)) (u_t u (1 0)) (u_x u (0 1)) (u_2t u (2 0)) (u_tx u
(1 1)) (u_2x u (0 2)) (u_3t u (3 0)) (u_2tx u (2 1)) (u_t2x u (1 2)) (u_3x u (0
3)) (u_4t u (4 0)) (u_3tx u (3 1)) (u_2t2x u (2 2)) (u_t3x u (1 3)) (u_4x u (0 4
)) (u_5t u (5 0)) (u_4tx u (4 1)) (u_3t2x u (3 2)) (u_2t3x u (2 3)) (u_t4x u (1
4)) (u_5x u (0 5)) (u_6t u (6 0)) (u_5tx u (5 1)) (u_4t2x u (4 2)) (u_3t3x u (3
3)) (u_2t4x u (2 4)) (u_t5x u (1 5)) (u_6x u (0 6)) (u_7t u (7 0)) (u_6tx u (6 1
)) (u_5t2x u (5 2)) (u_4t3x u (4 3)) (u_3t4x u (3 4)) (u_2t5x u (2 5)) (u_t6x u
(1 6)) (u_7x u (0 7)) (u_8t u (8 0)) (u_7tx u (7 1)) (u_6t2x u (6 2)) (u_5t3x u
(5 3)) (u_4t4x u (4 4)) (u_3t5x u (3 5)) (u_2t6x u (2 6)) (u_t7x u (1 7)) (u_8x
u (0 8)) (u_9t u (9 0)) (u_8tx u (8 1)) (u_7t2x u (7 2)) (u_6t3x u (6 3)) (
u_5t4x u (5 4)) (u_4t5x u (4 5)) (u_3t6x u (3 6)) (u_2t7x u (2 7)) (u_t8x u (1 8
)) (u_9x u (0 9)) (u_10t u (10 0)) (u_9tx u (9 1)) (u_8t2x u (8 2)) (u_7t3x u (7
3)) (u_6t4x u (6 4)) (u_5t5x u (5 5)) (u_4t6x u (4 6)) (u_3t7x u (3 7)) (u_2t8x
u (2 8)) (u_t9x u (1 9)) (u_10x u (0 10)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((q q (0 0)) (q_t q (1 0)) (q_x q (0 1)) (q_2t q (2 0)) (
q_tx q (1 1)) (q_2x q (0 2)) (q_3t q (3 0)) (q_2tx q (2 1)) (q_t2x q (1 2)) (
q_3x q (0 3)) (q_4t q (4 0)) (q_3tx q (3 1)) (q_2t2x q (2 2)) (q_t3x q (1 3)) (
q_4x q (0 4)) (q_5t q (5 0)) (q_4tx q (4 1)) (q_3t2x q (3 2)) (q_2t3x q (2 3)) (
q_t4x q (1 4)) (q_5x q (0 5)) (q_6t q (6 0)) (q_5tx q (5 1)) (q_4t2x q (4 2)) (
q_3t3x q (3 3)) (q_2t4x q (2 4)) (q_t5x q (1 5)) (q_6x q (0 6)) (q_7t q (7 0)) (
q_6tx q (6 1)) (q_5t2x q (5 2)) (q_4t3x q (4 3)) (q_3t4x q (3 4)) (q_2t5x q (2 5
)) (q_t6x q (1 6)) (q_7x q (0 7)) (q_8t q (8 0)) (q_7tx q (7 1)) (q_6t2x q (6 2)
) (q_5t3x q (5 3)) (q_4t4x q (4 4)) (q_3t5x q (3 5)) (q_2t6x q (2 6)) (q_t7x q (
1 7)) (q_8x q (0 8)) (q_9t q (9 0)) (q_8tx q (8 1)) (q_7t2x q (7 2)) (q_6t3x q (
6 3)) (q_5t4x q (5 4)) (q_4t5x q (4 5)) (q_3t6x q (3 6)) (q_2t7x q (2 7)) (q_t8x
q (1 8)) (q_9x q (0 9)) (q_10t q (10 0)) (q_9tx q (9 1)) (q_8t2x q (8 2)) (
q_7t3x q (7 3)) (q_6t4x q (6 4)) (q_5t5x q (5 5)) (q_4t6x q (4 6)) (q_3t7x q (3
7)) (q_2t8x q (2 8)) (q_t9x q (1 9)) (q_10x q (0 10)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (u_t . 1) (u_x . 1) (u_2t . 2) (u_tx . 2) (u_2x . 2) (
u_3t . 3) (u_2tx . 3) (u_t2x . 3) (u_3x . 3) (u_4t . 4) (u_3tx . 4) (u_2t2x . 4)
(u_t3x . 4) (u_4x . 4) (u_5t . 5) (u_4tx . 5) (u_3t2x . 5) (u_2t3x . 5) (u_t4x .
5) (u_5x . 5) (u_6t . 6) (u_5tx . 6) (u_4t2x . 6) (u_3t3x . 6) (u_2t4x . 6) (
u_t5x . 6) (u_6x . 6) (u_7t . 7) (u_6tx . 7) (u_5t2x . 7) (u_4t3x . 7) (u_3t4x .
7) (u_2t5x . 7) (u_t6x . 7) (u_7x . 7) (u_8t . 8) (u_7tx . 8) (u_6t2x . 8) (
u_5t3x . 8) (u_4t4x . 8) (u_3t5x . 8) (u_2t6x . 8) (u_t7x . 8) (u_8x . 8) (u_9t
. 9) (u_8tx . 9) (u_7t2x . 9) (u_6t3x . 9) (u_5t4x . 9) (u_4t5x . 9) (u_3t6x . 9
) (u_2t7x . 9) (u_t8x . 9) (u_9x . 9) (u_10t . 10) (u_9tx . 10) (u_8t2x . 10) (
u_7t3x . 10) (u_6t4x . 10) (u_5t5x . 10) (u_4t6x . 10) (u_3t7x . 10) (u_2t8x .
10) (u_t9x . 10) (u_10x . 10))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((q . 0) (q_t . 1) (q_x . 1) (q_2t . 2) (q_tx . 2) (q_2x . 2
) (q_3t . 3) (q_2tx . 3) (q_t2x . 3) (q_3x . 3) (q_4t . 4) (q_3tx . 4) (q_2t2x .
4) (q_t3x . 4) (q_4x . 4) (q_5t . 5) (q_4tx . 5) (q_3t2x . 5) (q_2t3x . 5) (
q_t4x . 5) (q_5x . 5) (q_6t . 6) (q_5tx . 6) (q_4t2x . 6) (q_3t3x . 6) (q_2t4x .
6) (q_t5x . 6) (q_6x . 6) (q_7t . 7) (q_6tx . 7) (q_5t2x . 7) (q_4t3x . 7) (
q_3t4x . 7) (q_2t5x . 7) (q_t6x . 7) (q_7x . 7) (q_8t . 8) (q_7tx . 8) (q_6t2x .
8) (q_5t3x . 8) (q_4t4x . 8) (q_3t5x . 8) (q_2t6x . 8) (q_t7x . 8) (q_8x . 8) (
q_9t . 9) (q_8tx . 9) (q_7t2x . 9) (q_6t3x . 9) (q_5t4x . 9) (q_4t5x . 9) (
q_3t6x . 9) (q_2t7x . 9) (q_t8x . 9) (q_9x . 9) (q_10t . 10) (q_9tx . 10) (
q_8t2x . 10) (q_7t3x . 10) (q_6t4x . 10) (q_5t5x . 10) (q_4t6x . 10) (q_3t7x .
10) (q_2t8x . 10) (q_t9x . 10) (q_10x . 10))
% list of even principal derivatives:
all_principal_der!*:=(u_t u_tx u_2t u_t2x u_2tx u_3t u_t3x u_2t2x u_3tx u_4t
u_t4x u_2t3x u_3t2x u_4tx u_5t u_t5x u_2t4x u_3t3x u_4t2x u_5tx u_6t u_t6x
u_2t5x u_3t4x u_4t3x u_5t2x u_6tx u_7t u_t7x u_2t6x u_3t5x u_4t4x u_5t3x u_6t2x
u_7tx u_8t u_t8x u_2t7x u_3t6x u_4t5x u_5t4x u_6t3x u_7t2x u_8tx u_9t u_t9x
u_2t8x u_3t7x u_4t6x u_5t5x u_6t4x u_7t3x u_8t2x u_9tx u_10t)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_x u_2x u_3x u_4x u_5x u_6x u_7x u_8x u_9x u_10x)
% list of odd principal derivatives:
all_principal_odd!*:=(q_t q_tx q_2t q_t2x q_2tx q_3t q_t3x q_2t2x q_3tx q_4t
q_t4x q_2t3x q_3t2x q_4tx q_5t q_t5x q_2t4x q_3t3x q_4t2x q_5tx q_6t q_t6x
q_2t5x q_3t4x q_4t3x q_5t2x q_6tx q_7t q_t7x q_2t6x q_3t5x q_4t4x q_5t3x q_6t2x
q_7tx q_8t q_t8x q_2t7x q_3t6x q_4t5x q_5t4x q_6t3x q_7t2x q_8tx q_9t q_t9x
q_2t8x q_3t7x q_4t6x q_5t5x q_6t4x q_7t3x q_8t2x q_9tx q_10t)
q_t = (ext 12)
q_tx = (ext 13)
q_2t = (ext 14)
q_t2x = (ext 15)
q_2tx = (ext 16)
q_3t = (ext 17)
q_t3x = (ext 18)
q_2t2x = (ext 19)
q_3tx = (ext 20)
q_4t = (ext 21)
q_t4x = (ext 22)
q_2t3x = (ext 23)
q_3t2x = (ext 24)
q_4tx = (ext 25)
q_5t = (ext 26)
q_t5x = (ext 27)
q_2t4x = (ext 28)
q_3t3x = (ext 29)
q_4t2x = (ext 30)
q_5tx = (ext 31)
q_6t = (ext 32)
q_t6x = (ext 33)
q_2t5x = (ext 34)
q_3t4x = (ext 35)
q_4t3x = (ext 36)
q_5t2x = (ext 37)
q_6tx = (ext 38)
q_7t = (ext 39)
q_t7x = (ext 40)
q_2t6x = (ext 41)
q_3t5x = (ext 42)
q_4t4x = (ext 43)
q_5t3x = (ext 44)
q_6t2x = (ext 45)
q_7tx = (ext 46)
q_8t = (ext 47)
q_t8x = (ext 48)
q_2t7x = (ext 49)
q_3t6x = (ext 50)
q_4t5x = (ext 51)
q_5t4x = (ext 52)
q_6t3x = (ext 53)
q_7t2x = (ext 54)
q_8tx = (ext 55)
q_9t = (ext 56)
q_t9x = (ext 57)
q_2t8x = (ext 58)
q_3t7x = (ext 59)
q_4t6x = (ext 60)
q_5t5x = (ext 61)
q_6t4x = (ext 62)
q_7t3x = (ext 63)
q_8t2x = (ext 64)
q_9tx = (ext 65)
q_10t = (ext 66)
% list of odd parametric derivatives:
all_parametric_odd!*:=(q q_x q_2x q_3x q_4x q_5x q_6x q_7x q_8x q_9x q_10x)
q = (ext 1)
q_x = (ext 2)
q_2x = (ext 3)
q_3x = (ext 4)
q_4x = (ext 5)
q_5x = (ext 6)
q_6x = (ext 7)
q_7x = (ext 8)
q_8x = (ext 9)
q_9x = (ext 10)
q_10x = (ext 11)
% number of ext principal derivatives:
n_all_principal_ext:=55
% number of ext parametric derivatives:
n_all_parametric_ext:=11
% set of identifiers for total derivatives:
tot_der!*:=(ddt ddx)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 u_tx) (ddt 0 5 u_t2x) (ddt 0
6 u_t3x) (ddt 0 7 u_t4x) (ddt 0 8 u_t5x) (ddt 0 9 u_t6x) (ddt 0 10 u_t7x) (ddt 0
11 u_t8x) (ddt 0 12 u_t9x))
primary_diffcon_odd_tot!*:=((ddt 1 1 q_t) (ddt 1 2 q_tx) (ddt 1 3 q_t2x) (ddt 1
4 q_t3x) (ddt 1 5 q_t4x) (ddt 1 6 q_t5x) (ddt 1 7 q_t6x) (ddt 1 8 q_t7x) (ddt 1
9 q_t8x) (ddt 1 10 q_t9x))
primary_diffcon_der!*:=(u_tx u_t2x u_t3x u_t4x u_t5x u_t6x u_t7x u_t8x u_t9x)
primary_diffcon_odd!*:=(q_tx q_t2x q_t3x q_t4x q_t5x q_t6x q_t7x q_t8x q_t9x)
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_t9x (*sq ((((letop . 1) . 1)) . 1) nil)) (u_t8x (*sq ((((
u_10x . 1) . 1)) . 1) nil)) (u_t7x (*sq ((((u_9x . 1) . 1)) . 1) nil)) (u_t6x (
*sq ((((u_8x . 1) . 1)) . 1) nil)) (u_t5x (*sq ((((u_7x . 1) . 1)) . 1) nil)) (
u_t4x (*sq ((((u_6x . 1) . 1)) . 1) nil)) (u_t3x (*sq ((((u_5x . 1) . 1)) . 1)
nil)) (u_t2x (*sq ((((u_4x . 1) . 1)) . 1) nil)) (u_tx (*sq ((((u_3x . 1) . 1))
. 1) nil)) (u_t u_2x))
diffcon_odd!*:=((q_t9x (*sq ((((letop . 1) . 1)) . 1) nil)) (q_t8x (*sq (((((ext
11) . 1) . 1)) . 1) nil)) (q_t7x (*sq (((((ext 10) . 1) . 1)) . 1) nil)) (q_t6x
(*sq (((((ext 9) . 1) . 1)) . 1) nil)) (q_t5x (*sq (((((ext 8) . 1) . 1)) . 1)
nil)) (q_t4x (*sq (((((ext 7) . 1) . 1)) . 1) nil)) (q_t3x (*sq (((((ext 6) . 1)
. 1)) . 1) nil)) (q_t2x (*sq (((((ext 5) . 1) . 1)) . 1) nil)) (q_tx (*sq (((((
ext 4) . 1) . 1)) . 1) nil)) (q_t (*sq (((((ext 3) . 1) . 1)) . 1) nil)))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_t9x u_t8x u_t7x u_t6x u_t5x u_t4x u_t3x u_t2x u_tx u_t)
diffcon_comp_odd!*:=(q_t9x q_t8x q_t7x q_t6x q_t5x q_t4x q_t3x q_t2x q_tx q_t)
diffcon_comp_ext!*:=((ext 57) (ext 48) (ext 40) (ext 33) (ext 27) (ext 22) (ext
18) (ext 15) (ext 13) (ext 12))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_t9x *sq ((((letop . 1) . 1)) . 1) nil) (u_t8x *sq ((((
u_10x . 1) . 1)) . 1) nil) (u_t7x *sq ((((u_9x . 1) . 1)) . 1) nil) (u_t6x *sq (
(((u_8x . 1) . 1)) . 1) nil) (u_t5x *sq ((((u_7x . 1) . 1)) . 1) nil) (u_t4x *sq
((((u_6x . 1) . 1)) . 1) nil) (u_t3x *sq ((((u_5x . 1) . 1)) . 1) nil) (u_t2x
*sq ((((u_4x . 1) . 1)) . 1) nil) (u_tx *sq ((((u_3x . 1) . 1)) . 1) nil) (u_t
*sq ((((u_2x . 1) . 1)) . 1) nil))
diffcon_param_ext!*:=(((ext 57) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 48) *sq
(((((ext 11) . 1) . 1)) . 1) nil) ((ext 40) *sq (((((ext 10) . 1) . 1)) . 1) nil
) ((ext 33) *sq (((((ext 9) . 1) . 1)) . 1) nil) ((ext 27) *sq (((((ext 8) . 1)
. 1)) . 1) nil) ((ext 22) *sq (((((ext 7) . 1) . 1)) . 1) nil) ((ext 18) *sq (((
((ext 6) . 1) . 1)) . 1) nil) ((ext 15) *sq (((((ext 5) . 1) . 1)) . 1) nil) ((
ext 13) *sq (((((ext 4) . 1) . 1)) . 1) nil) ((ext 12) *sq (((((ext 3) . 1) . 1)
) . 1) nil))
% Coefficients of total derivatives:
% component of ddt w.r.t. t
ddt(0,1):=1
% component of ddt w.r.t. x
ddt(0,2):=0
% component of ddt w.r.t. u
ddt(0,3):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,4):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x
ddt(0,5):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,6):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,7):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,8):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,9):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7x
ddt(0,10):=(*sq ((((u_9x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,11):=(*sq ((((u_10x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_9x
ddt(0,12):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_10x
ddt(0,13):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,14):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_tx
ddt(0,15):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,16):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2x
ddt(0,17):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2tx
ddt(0,18):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,19):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t3x
ddt(0,20):=(*sq ((((u_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t2x
ddt(0,21):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3tx
ddt(0,22):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,23):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t4x
ddt(0,24):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t3x
ddt(0,25):=(*sq ((((u_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t2x
ddt(0,26):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4tx
ddt(0,27):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,28):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t5x
ddt(0,29):=(*sq ((((u_2t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t4x
ddt(0,30):=(*sq ((((u_3t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t3x
ddt(0,31):=(*sq ((((u_4t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t2x
ddt(0,32):=(*sq ((((u_5t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5tx
ddt(0,33):=(*sq ((((u_6tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,34):=(*sq ((((u_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t6x
ddt(0,35):=(*sq ((((u_2t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t5x
ddt(0,36):=(*sq ((((u_3t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t4x
ddt(0,37):=(*sq ((((u_4t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t3x
ddt(0,38):=(*sq ((((u_5t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t2x
ddt(0,39):=(*sq ((((u_6t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6tx
ddt(0,40):=(*sq ((((u_7tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t
ddt(0,41):=(*sq ((((u_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t7x
ddt(0,42):=(*sq ((((u_2t7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t6x
ddt(0,43):=(*sq ((((u_3t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t5x
ddt(0,44):=(*sq ((((u_4t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t4x
ddt(0,45):=(*sq ((((u_5t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t3x
ddt(0,46):=(*sq ((((u_6t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t2x
ddt(0,47):=(*sq ((((u_7t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7tx
ddt(0,48):=(*sq ((((u_8tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t
ddt(0,49):=(*sq ((((u_9t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t8x
ddt(0,50):=(*sq ((((u_2t8x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t7x
ddt(0,51):=(*sq ((((u_3t7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t6x
ddt(0,52):=(*sq ((((u_4t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t5x
ddt(0,53):=(*sq ((((u_5t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t4x
ddt(0,54):=(*sq ((((u_6t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t3x
ddt(0,55):=(*sq ((((u_7t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t2x
ddt(0,56):=(*sq ((((u_8t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8tx
ddt(0,57):=(*sq ((((u_9tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_9t
ddt(0,58):=(*sq ((((u_10t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t9x
ddt(0,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t8x
ddt(0,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t7x
ddt(0,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t6x
ddt(0,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t5x
ddt(0,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t4x
ddt(0,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t3x
ddt(0,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t2x
ddt(0,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_9tx
ddt(0,67):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_10t
ddt(0,68):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q
ddt(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x
ddt(1,2):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x
ddt(1,3):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x
ddt(1,4):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x
ddt(1,5):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x
ddt(1,6):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6x
ddt(1,7):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7x
ddt(1,8):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8x
ddt(1,9):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_9x
ddt(1,10):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_10x
ddt(1,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t
ddt(1,12):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_tx
ddt(1,13):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t
ddt(1,14):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t2x
ddt(1,15):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2tx
ddt(1,16):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t
ddt(1,17):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t3x
ddt(1,18):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t2x
ddt(1,19):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3tx
ddt(1,20):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t
ddt(1,21):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t4x
ddt(1,22):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t3x
ddt(1,23):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t2x
ddt(1,24):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4tx
ddt(1,25):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t
ddt(1,26):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t5x
ddt(1,27):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t4x
ddt(1,28):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t3x
ddt(1,29):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t2x
ddt(1,30):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5tx
ddt(1,31):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t
ddt(1,32):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t6x
ddt(1,33):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t5x
ddt(1,34):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t4x
ddt(1,35):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t3x
ddt(1,36):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t2x
ddt(1,37):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6tx
ddt(1,38):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7t
ddt(1,39):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t7x
ddt(1,40):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t6x
ddt(1,41):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t5x
ddt(1,42):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t4x
ddt(1,43):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t3x
ddt(1,44):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t2x
ddt(1,45):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7tx
ddt(1,46):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8t
ddt(1,47):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t8x
ddt(1,48):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t7x
ddt(1,49):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t6x
ddt(1,50):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t5x
ddt(1,51):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t4x
ddt(1,52):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t3x
ddt(1,53):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7t2x
ddt(1,54):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8tx
ddt(1,55):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_9t
ddt(1,56):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t9x
ddt(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t8x
ddt(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t7x
ddt(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t6x
ddt(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t5x
ddt(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t4x
ddt(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7t3x
ddt(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8t2x
ddt(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_9tx
ddt(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_10t
ddt(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. t
ddx(0,1):=0
% component of ddx w.r.t. x
ddx(0,2):=1
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
ddx(0,14):=(*sq ((((u_tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_tx
ddx(0,15):=(*sq ((((u_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,16):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2x
ddx(0,17):=(*sq ((((u_t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2tx
ddx(0,18):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t
ddx(0,19):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t3x
ddx(0,20):=(*sq ((((u_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t2x
ddx(0,21):=(*sq ((((u_2t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3tx
ddx(0,22):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t
ddx(0,23):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t4x
ddx(0,24):=(*sq ((((u_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t3x
ddx(0,25):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t2x
ddx(0,26):=(*sq ((((u_3t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4tx
ddx(0,27):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t
ddx(0,28):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t5x
ddx(0,29):=(*sq ((((u_t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t4x
ddx(0,30):=(*sq ((((u_2t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t3x
ddx(0,31):=(*sq ((((u_3t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t2x
ddx(0,32):=(*sq ((((u_4t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5tx
ddx(0,33):=(*sq ((((u_5t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t
ddx(0,34):=(*sq ((((u_6tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t6x
ddx(0,35):=(*sq ((((u_t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t5x
ddx(0,36):=(*sq ((((u_2t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t4x
ddx(0,37):=(*sq ((((u_3t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t3x
ddx(0,38):=(*sq ((((u_4t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t2x
ddx(0,39):=(*sq ((((u_5t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6tx
ddx(0,40):=(*sq ((((u_6t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t
ddx(0,41):=(*sq ((((u_7tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t7x
ddx(0,42):=(*sq ((((u_t8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t6x
ddx(0,43):=(*sq ((((u_2t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t5x
ddx(0,44):=(*sq ((((u_3t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t4x
ddx(0,45):=(*sq ((((u_4t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t3x
ddx(0,46):=(*sq ((((u_5t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t2x
ddx(0,47):=(*sq ((((u_6t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7tx
ddx(0,48):=(*sq ((((u_7t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8t
ddx(0,49):=(*sq ((((u_8tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t8x
ddx(0,50):=(*sq ((((u_t9x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t7x
ddx(0,51):=(*sq ((((u_2t8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t6x
ddx(0,52):=(*sq ((((u_3t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t5x
ddx(0,53):=(*sq ((((u_4t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t4x
ddx(0,54):=(*sq ((((u_5t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t3x
ddx(0,55):=(*sq ((((u_6t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t2x
ddx(0,56):=(*sq ((((u_7t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8tx
ddx(0,57):=(*sq ((((u_8t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9t
ddx(0,58):=(*sq ((((u_9tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t9x
ddx(0,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t8x
ddx(0,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t7x
ddx(0,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t6x
ddx(0,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t5x
ddx(0,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t4x
ddx(0,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t3x
ddx(0,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8t2x
ddx(0,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9tx
ddx(0,67):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_10t
ddx(0,68):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q
ddx(1,1):=(*sq (((((ext 2) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x
ddx(1,2):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x
ddx(1,3):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x
ddx(1,4):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x
ddx(1,5):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x
ddx(1,6):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x
ddx(1,7):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x
ddx(1,8):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x
ddx(1,9):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9x
ddx(1,10):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_10x
ddx(1,11):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t
ddx(1,12):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_tx
ddx(1,13):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t
ddx(1,14):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t2x
ddx(1,15):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2tx
ddx(1,16):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t
ddx(1,17):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t3x
ddx(1,18):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t2x
ddx(1,19):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3tx
ddx(1,20):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t
ddx(1,21):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t4x
ddx(1,22):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t3x
ddx(1,23):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t2x
ddx(1,24):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4tx
ddx(1,25):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t
ddx(1,26):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t5x
ddx(1,27):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t4x
ddx(1,28):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t3x
ddx(1,29):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t2x
ddx(1,30):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5tx
ddx(1,31):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t
ddx(1,32):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t6x
ddx(1,33):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t5x
ddx(1,34):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t4x
ddx(1,35):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t3x
ddx(1,36):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t2x
ddx(1,37):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6tx
ddx(1,38):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7t
ddx(1,39):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t7x
ddx(1,40):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t6x
ddx(1,41):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t5x
ddx(1,42):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t4x
ddx(1,43):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t3x
ddx(1,44):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t2x
ddx(1,45):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7tx
ddx(1,46):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8t
ddx(1,47):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t8x
ddx(1,48):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t7x
ddx(1,49):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t6x
ddx(1,50):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t5x
ddx(1,51):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t4x
ddx(1,52):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t3x
ddx(1,53):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7t2x
ddx(1,54):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8tx
ddx(1,55):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9t
ddx(1,56):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t9x
ddx(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t8x
ddx(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t7x
ddx(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t6x
ddx(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t5x
ddx(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t4x
ddx(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7t3x
ddx(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8t2x
ddx(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9tx
ddx(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_10t
ddx(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
