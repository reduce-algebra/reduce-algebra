% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_3x s1_x s1_t s2_x s2_t)
de!*:=((quotient (plus (times 3 alpha u u_x) (times alpha u_t) (minus (times 2
u_2x u_x)) (minus u_t2x)) u) (plus (times alpha u) (minus u_2x)) (quotient (plus
(minus (times 3 alpha (expt u 2))) (times 2 u u_2x) (expt u_x 2)) 2) (plus (
times alpha (expt u 2)) (minus (times u u_2x))) (plus (minus (times 2 alpha (
expt u 3))) (times 2 (expt u 2) u_2x) (times u u_tx) (minus (times u_t u_x))))
% odd equation
principal_odd!*:=(q_8t)
de_odd!*(letop)
% Settings:
indep_var!*:=(t x)
dep_var!*:=(u s1 s2)
odd_var!*:=(q)
deg_indep_var!*:=(-2 -1)
deg_dep_var!*:=(1 2 3)
deg_odd_var!*:=nil
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
all_der_mind!*:=((u (0 0)) (s1 (0 0)) (s2 (0 0)) (u (1 0)) (s1 (1 0)) (s2 (1 0))
(u (0 1)) (s1 (0 1)) (s2 (0 1)) (u (2 0)) (s1 (2 0)) (s2 (2 0)) (u (1 1)) (s1 (1
1)) (s2 (1 1)) (u (0 2)) (s1 (0 2)) (s2 (0 2)) (u (3 0)) (s1 (3 0)) (s2 (3 0)) (
u (2 1)) (s1 (2 1)) (s2 (2 1)) (u (1 2)) (s1 (1 2)) (s2 (1 2)) (u (0 3)) (s1 (0
3)) (s2 (0 3)) (u (4 0)) (s1 (4 0)) (s2 (4 0)) (u (3 1)) (s1 (3 1)) (s2 (3 1)) (
u (2 2)) (s1 (2 2)) (s2 (2 2)) (u (1 3)) (s1 (1 3)) (s2 (1 3)) (u (0 4)) (s1 (0
4)) (s2 (0 4)) (u (5 0)) (s1 (5 0)) (s2 (5 0)) (u (4 1)) (s1 (4 1)) (s2 (4 1)) (
u (3 2)) (s1 (3 2)) (s2 (3 2)) (u (2 3)) (s1 (2 3)) (s2 (2 3)) (u (1 4)) (s1 (1
4)) (s2 (1 4)) (u (0 5)) (s1 (0 5)) (s2 (0 5)) (u (6 0)) (s1 (6 0)) (s2 (6 0)) (
u (5 1)) (s1 (5 1)) (s2 (5 1)) (u (4 2)) (s1 (4 2)) (s2 (4 2)) (u (3 3)) (s1 (3
3)) (s2 (3 3)) (u (2 4)) (s1 (2 4)) (s2 (2 4)) (u (1 5)) (s1 (1 5)) (s2 (1 5)) (
u (0 6)) (s1 (0 6)) (s2 (0 6)) (u (7 0)) (s1 (7 0)) (s2 (7 0)) (u (6 1)) (s1 (6
1)) (s2 (6 1)) (u (5 2)) (s1 (5 2)) (s2 (5 2)) (u (4 3)) (s1 (4 3)) (s2 (4 3)) (
u (3 4)) (s1 (3 4)) (s2 (3 4)) (u (2 5)) (s1 (2 5)) (s2 (2 5)) (u (1 6)) (s1 (1
6)) (s2 (1 6)) (u (0 7)) (s1 (0 7)) (s2 (0 7)) (u (8 0)) (s1 (8 0)) (s2 (8 0)) (
u (7 1)) (s1 (7 1)) (s2 (7 1)) (u (6 2)) (s1 (6 2)) (s2 (6 2)) (u (5 3)) (s1 (5
3)) (s2 (5 3)) (u (4 4)) (s1 (4 4)) (s2 (4 4)) (u (3 5)) (s1 (3 5)) (s2 (3 5)) (
u (2 6)) (s1 (2 6)) (s2 (2 6)) (u (1 7)) (s1 (1 7)) (s2 (1 7)) (u (0 8)) (s1 (0
8)) (s2 (0 8)))
% all odd derivatives in multiindex notation:
all_odd_mind!*:=((q (0 0)) (q (1 0)) (q (0 1)) (q (2 0)) (q (1 1)) (q (0 2)) (q
(3 0)) (q (2 1)) (q (1 2)) (q (0 3)) (q (4 0)) (q (3 1)) (q (2 2)) (q (1 3)) (q
(0 4)) (q (5 0)) (q (4 1)) (q (3 2)) (q (2 3)) (q (1 4)) (q (0 5)) (q (6 0)) (q
(5 1)) (q (4 2)) (q (3 3)) (q (2 4)) (q (1 5)) (q (0 6)) (q (7 0)) (q (6 1)) (q
(5 2)) (q (4 3)) (q (3 4)) (q (2 5)) (q (1 6)) (q (0 7)) (q (8 0)) (q (7 1)) (q
(6 2)) (q (5 3)) (q (4 4)) (q (3 5)) (q (2 6)) (q (1 7)) (q (0 8)))
% all even derivatives in identifier notation:
all_der_id!*:=(u s1 s2 u_t s1_t s2_t u_x s1_x s2_x u_2t s1_2t s2_2t u_tx s1_tx
s2_tx u_2x s1_2x s2_2x u_3t s1_3t s2_3t u_2tx s1_2tx s2_2tx u_t2x s1_t2x s2_t2x
u_3x s1_3x s2_3x u_4t s1_4t s2_4t u_3tx s1_3tx s2_3tx u_2t2x s1_2t2x s2_2t2x
u_t3x s1_t3x s2_t3x u_4x s1_4x s2_4x u_5t s1_5t s2_5t u_4tx s1_4tx s2_4tx u_3t2x
s1_3t2x s2_3t2x u_2t3x s1_2t3x s2_2t3x u_t4x s1_t4x s2_t4x u_5x s1_5x s2_5x u_6t
s1_6t s2_6t u_5tx s1_5tx s2_5tx u_4t2x s1_4t2x s2_4t2x u_3t3x s1_3t3x s2_3t3x
u_2t4x s1_2t4x s2_2t4x u_t5x s1_t5x s2_t5x u_6x s1_6x s2_6x u_7t s1_7t s2_7t
u_6tx s1_6tx s2_6tx u_5t2x s1_5t2x s2_5t2x u_4t3x s1_4t3x s2_4t3x u_3t4x s1_3t4x
s2_3t4x u_2t5x s1_2t5x s2_2t5x u_t6x s1_t6x s2_t6x u_7x s1_7x s2_7x u_8t s1_8t
s2_8t u_7tx s1_7tx s2_7tx u_6t2x s1_6t2x s2_6t2x u_5t3x s1_5t3x s2_5t3x u_4t4x
s1_4t4x s2_4t4x u_3t5x s1_3t5x s2_3t5x u_2t6x s1_2t6x s2_2t6x u_t7x s1_t7x
s2_t7x u_8x s1_8x s2_8x)
% all odd derivatives in identifier notation:
all_odd_id!*:=(q q_t q_x q_2t q_tx q_2x q_3t q_2tx q_t2x q_3x q_4t q_3tx q_2t2x
q_t3x q_4x q_5t q_4tx q_3t2x q_2t3x q_t4x q_5x q_6t q_5tx q_4t2x q_3t3x q_2t4x
q_t5x q_6x q_7t q_6tx q_5t2x q_4t3x q_3t4x q_2t5x q_t6x q_7x q_8t q_7tx q_6t2x
q_5t3x q_4t4x q_3t5x q_2t6x q_t7x q_8x)
% number of all ext symbols:
n_all_ext:=45
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0)) (s1 s1 (0 0)) (s2 s2 (0 0)) (u_t u (1 0)) (s1_t s1
(1 0)) (s2_t s2 (1 0)) (u_x u (0 1)) (s1_x s1 (0 1)) (s2_x s2 (0 1)) (u_2t u (2
0)) (s1_2t s1 (2 0)) (s2_2t s2 (2 0)) (u_tx u (1 1)) (s1_tx s1 (1 1)) (s2_tx s2
(1 1)) (u_2x u (0 2)) (s1_2x s1 (0 2)) (s2_2x s2 (0 2)) (u_3t u (3 0)) (s1_3t s1
(3 0)) (s2_3t s2 (3 0)) (u_2tx u (2 1)) (s1_2tx s1 (2 1)) (s2_2tx s2 (2 1)) (
u_t2x u (1 2)) (s1_t2x s1 (1 2)) (s2_t2x s2 (1 2)) (u_3x u (0 3)) (s1_3x s1 (0 3
)) (s2_3x s2 (0 3)) (u_4t u (4 0)) (s1_4t s1 (4 0)) (s2_4t s2 (4 0)) (u_3tx u (3
1)) (s1_3tx s1 (3 1)) (s2_3tx s2 (3 1)) (u_2t2x u (2 2)) (s1_2t2x s1 (2 2)) (
s2_2t2x s2 (2 2)) (u_t3x u (1 3)) (s1_t3x s1 (1 3)) (s2_t3x s2 (1 3)) (u_4x u (0
4)) (s1_4x s1 (0 4)) (s2_4x s2 (0 4)) (u_5t u (5 0)) (s1_5t s1 (5 0)) (s2_5t s2
(5 0)) (u_4tx u (4 1)) (s1_4tx s1 (4 1)) (s2_4tx s2 (4 1)) (u_3t2x u (3 2)) (
s1_3t2x s1 (3 2)) (s2_3t2x s2 (3 2)) (u_2t3x u (2 3)) (s1_2t3x s1 (2 3)) (
s2_2t3x s2 (2 3)) (u_t4x u (1 4)) (s1_t4x s1 (1 4)) (s2_t4x s2 (1 4)) (u_5x u (0
5)) (s1_5x s1 (0 5)) (s2_5x s2 (0 5)) (u_6t u (6 0)) (s1_6t s1 (6 0)) (s2_6t s2
(6 0)) (u_5tx u (5 1)) (s1_5tx s1 (5 1)) (s2_5tx s2 (5 1)) (u_4t2x u (4 2)) (
s1_4t2x s1 (4 2)) (s2_4t2x s2 (4 2)) (u_3t3x u (3 3)) (s1_3t3x s1 (3 3)) (
s2_3t3x s2 (3 3)) (u_2t4x u (2 4)) (s1_2t4x s1 (2 4)) (s2_2t4x s2 (2 4)) (u_t5x
u (1 5)) (s1_t5x s1 (1 5)) (s2_t5x s2 (1 5)) (u_6x u (0 6)) (s1_6x s1 (0 6)) (
s2_6x s2 (0 6)) (u_7t u (7 0)) (s1_7t s1 (7 0)) (s2_7t s2 (7 0)) (u_6tx u (6 1))
(s1_6tx s1 (6 1)) (s2_6tx s2 (6 1)) (u_5t2x u (5 2)) (s1_5t2x s1 (5 2)) (s2_5t2x
s2 (5 2)) (u_4t3x u (4 3)) (s1_4t3x s1 (4 3)) (s2_4t3x s2 (4 3)) (u_3t4x u (3 4)
) (s1_3t4x s1 (3 4)) (s2_3t4x s2 (3 4)) (u_2t5x u (2 5)) (s1_2t5x s1 (2 5)) (
s2_2t5x s2 (2 5)) (u_t6x u (1 6)) (s1_t6x s1 (1 6)) (s2_t6x s2 (1 6)) (u_7x u (0
7)) (s1_7x s1 (0 7)) (s2_7x s2 (0 7)) (u_8t u (8 0)) (s1_8t s1 (8 0)) (s2_8t s2
(8 0)) (u_7tx u (7 1)) (s1_7tx s1 (7 1)) (s2_7tx s2 (7 1)) (u_6t2x u (6 2)) (
s1_6t2x s1 (6 2)) (s2_6t2x s2 (6 2)) (u_5t3x u (5 3)) (s1_5t3x s1 (5 3)) (
s2_5t3x s2 (5 3)) (u_4t4x u (4 4)) (s1_4t4x s1 (4 4)) (s2_4t4x s2 (4 4)) (u_3t5x
u (3 5)) (s1_3t5x s1 (3 5)) (s2_3t5x s2 (3 5)) (u_2t6x u (2 6)) (s1_2t6x s1 (2 6
)) (s2_2t6x s2 (2 6)) (u_t7x u (1 7)) (s1_t7x s1 (1 7)) (s2_t7x s2 (1 7)) (u_8x
u (0 8)) (s1_8x s1 (0 8)) (s2_8x s2 (0 8)))
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
1 7)) (q_8x q (0 8)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (s1 . 0) (s2 . 0) (u_t . 1) (s1_t . 1) (s2_t . 1) (u_x
. 1) (s1_x . 1) (s2_x . 1) (u_2t . 2) (s1_2t . 2) (s2_2t . 2) (u_tx . 2) (s1_tx
. 2) (s2_tx . 2) (u_2x . 2) (s1_2x . 2) (s2_2x . 2) (u_3t . 3) (s1_3t . 3) (
s2_3t . 3) (u_2tx . 3) (s1_2tx . 3) (s2_2tx . 3) (u_t2x . 3) (s1_t2x . 3) (
s2_t2x . 3) (u_3x . 3) (s1_3x . 3) (s2_3x . 3) (u_4t . 4) (s1_4t . 4) (s2_4t . 4
) (u_3tx . 4) (s1_3tx . 4) (s2_3tx . 4) (u_2t2x . 4) (s1_2t2x . 4) (s2_2t2x . 4)
(u_t3x . 4) (s1_t3x . 4) (s2_t3x . 4) (u_4x . 4) (s1_4x . 4) (s2_4x . 4) (u_5t .
5) (s1_5t . 5) (s2_5t . 5) (u_4tx . 5) (s1_4tx . 5) (s2_4tx . 5) (u_3t2x . 5) (
s1_3t2x . 5) (s2_3t2x . 5) (u_2t3x . 5) (s1_2t3x . 5) (s2_2t3x . 5) (u_t4x . 5)
(s1_t4x . 5) (s2_t4x . 5) (u_5x . 5) (s1_5x . 5) (s2_5x . 5) (u_6t . 6) (s1_6t .
6) (s2_6t . 6) (u_5tx . 6) (s1_5tx . 6) (s2_5tx . 6) (u_4t2x . 6) (s1_4t2x . 6)
(s2_4t2x . 6) (u_3t3x . 6) (s1_3t3x . 6) (s2_3t3x . 6) (u_2t4x . 6) (s1_2t4x . 6
) (s2_2t4x . 6) (u_t5x . 6) (s1_t5x . 6) (s2_t5x . 6) (u_6x . 6) (s1_6x . 6) (
s2_6x . 6) (u_7t . 7) (s1_7t . 7) (s2_7t . 7) (u_6tx . 7) (s1_6tx . 7) (s2_6tx .
7) (u_5t2x . 7) (s1_5t2x . 7) (s2_5t2x . 7) (u_4t3x . 7) (s1_4t3x . 7) (s2_4t3x
. 7) (u_3t4x . 7) (s1_3t4x . 7) (s2_3t4x . 7) (u_2t5x . 7) (s1_2t5x . 7) (
s2_2t5x . 7) (u_t6x . 7) (s1_t6x . 7) (s2_t6x . 7) (u_7x . 7) (s1_7x . 7) (s2_7x
. 7) (u_8t . 8) (s1_8t . 8) (s2_8t . 8) (u_7tx . 8) (s1_7tx . 8) (s2_7tx . 8) (
u_6t2x . 8) (s1_6t2x . 8) (s2_6t2x . 8) (u_5t3x . 8) (s1_5t3x . 8) (s2_5t3x . 8)
(u_4t4x . 8) (s1_4t4x . 8) (s2_4t4x . 8) (u_3t5x . 8) (s1_3t5x . 8) (s2_3t5x . 8
) (u_2t6x . 8) (s1_2t6x . 8) (s2_2t6x . 8) (u_t7x . 8) (s1_t7x . 8) (s2_t7x . 8)
(u_8x . 8) (s1_8x . 8) (s2_8x . 8))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((q . 0) (q_t . 1) (q_x . 1) (q_2t . 2) (q_tx . 2) (q_2x . 2
) (q_3t . 3) (q_2tx . 3) (q_t2x . 3) (q_3x . 3) (q_4t . 4) (q_3tx . 4) (q_2t2x .
4) (q_t3x . 4) (q_4x . 4) (q_5t . 5) (q_4tx . 5) (q_3t2x . 5) (q_2t3x . 5) (
q_t4x . 5) (q_5x . 5) (q_6t . 6) (q_5tx . 6) (q_4t2x . 6) (q_3t3x . 6) (q_2t4x .
6) (q_t5x . 6) (q_6x . 6) (q_7t . 7) (q_6tx . 7) (q_5t2x . 7) (q_4t3x . 7) (
q_3t4x . 7) (q_2t5x . 7) (q_t6x . 7) (q_7x . 7) (q_8t . 8) (q_7tx . 8) (q_6t2x .
8) (q_5t3x . 8) (q_4t4x . 8) (q_3t5x . 8) (q_2t6x . 8) (q_t7x . 8) (q_8x . 8))
% list of even principal derivatives:
all_principal_der!*:=(s1_t s1_x s2_t s2_x s1_tx s1_2t s1_2x s1_tx s2_tx s2_2t
s2_2x s2_tx u_3x s1_t2x s1_2tx s1_3t s1_3x s1_t2x s1_2tx s2_t2x s2_2tx s2_3t
s2_3x s2_t2x s2_2tx u_4x u_t3x s1_t3x s1_2t2x s1_3tx s1_4t s1_4x s1_t3x s1_2t2x
s1_3tx s2_t3x s2_2t2x s2_3tx s2_4t s2_4x s2_t3x s2_2t2x s2_3tx u_5x u_t4x u_2t3x
s1_t4x s1_2t3x s1_3t2x s1_4tx s1_5t s1_5x s1_t4x s1_2t3x s1_3t2x s1_4tx s2_t4x
s2_2t3x s2_3t2x s2_4tx s2_5t s2_5x s2_t4x s2_2t3x s2_3t2x s2_4tx u_6x u_t5x
u_2t4x u_3t3x s1_t5x s1_2t4x s1_3t3x s1_4t2x s1_5tx s1_6t s1_6x s1_t5x s1_2t4x
s1_3t3x s1_4t2x s1_5tx s2_t5x s2_2t4x s2_3t3x s2_4t2x s2_5tx s2_6t s2_6x s2_t5x
s2_2t4x s2_3t3x s2_4t2x s2_5tx u_7x u_t6x u_2t5x u_3t4x u_4t3x s1_t6x s1_2t5x
s1_3t4x s1_4t3x s1_5t2x s1_6tx s1_7t s1_7x s1_t6x s1_2t5x s1_3t4x s1_4t3x
s1_5t2x s1_6tx s2_t6x s2_2t5x s2_3t4x s2_4t3x s2_5t2x s2_6tx s2_7t s2_7x s2_t6x
s2_2t5x s2_3t4x s2_4t3x s2_5t2x s2_6tx u_8x u_t7x u_2t6x u_3t5x u_4t4x u_5t3x
s1_t7x s1_2t6x s1_3t5x s1_4t4x s1_5t3x s1_6t2x s1_7tx s1_8t s1_8x s2_t7x s2_2t6x
s2_3t5x s2_4t4x s2_5t3x s2_6t2x s2_7tx s2_8t s2_8x)
% list of even parametric derivatives:
all_parametric_der!*:=(u s1 s2 u_t u_x u_2t u_tx u_2x u_3t u_2tx u_t2x u_4t
u_3tx u_2t2x u_5t u_4tx u_3t2x u_6t u_5tx u_4t2x u_7t u_6tx u_5t2x u_8t u_7tx
u_6t2x)
% list of odd principal derivatives:
all_principal_odd!*:=(q_8t)
q_8t = (ext 45)
% list of odd parametric derivatives:
all_parametric_odd!*:=(q q_t q_x q_2t q_tx q_2x q_3t q_2tx q_t2x q_3x q_4t q_3tx
q_2t2x q_t3x q_4x q_5t q_4tx q_3t2x q_2t3x q_t4x q_5x q_6t q_5tx q_4t2x q_3t3x
q_2t4x q_t5x q_6x q_7t q_6tx q_5t2x q_4t3x q_3t4x q_2t5x q_t6x q_7x q_7tx q_6t2x
q_5t3x q_4t4x q_3t5x q_2t6x q_t7x q_8x)
q = (ext 1)
q_t = (ext 2)
q_x = (ext 3)
q_2t = (ext 4)
q_tx = (ext 5)
q_2x = (ext 6)
q_3t = (ext 7)
q_2tx = (ext 8)
q_t2x = (ext 9)
q_3x = (ext 10)
q_4t = (ext 11)
q_3tx = (ext 12)
q_2t2x = (ext 13)
q_t3x = (ext 14)
q_4x = (ext 15)
q_5t = (ext 16)
q_4tx = (ext 17)
q_3t2x = (ext 18)
q_2t3x = (ext 19)
q_t4x = (ext 20)
q_5x = (ext 21)
q_6t = (ext 22)
q_5tx = (ext 23)
q_4t2x = (ext 24)
q_3t3x = (ext 25)
q_2t4x = (ext 26)
q_t5x = (ext 27)
q_6x = (ext 28)
q_7t = (ext 29)
q_6tx = (ext 30)
q_5t2x = (ext 31)
q_4t3x = (ext 32)
q_3t4x = (ext 33)
q_2t5x = (ext 34)
q_t6x = (ext 35)
q_7x = (ext 36)
q_7tx = (ext 37)
q_6t2x = (ext 38)
q_5t3x = (ext 39)
q_4t4x = (ext 40)
q_3t5x = (ext 41)
q_2t6x = (ext 42)
q_t7x = (ext 43)
q_8x = (ext 44)
% number of ext principal derivatives:
n_all_principal_ext:=1
% number of ext parametric derivatives:
n_all_parametric_ext:=44
% set of identifiers for total derivatives:
tot_der!*:=(ddt ddx)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 4 s1_t) (ddt 0 5 s2_t) (ddx 0 4 s1_x) (ddx 0
5 s2_x) (ddx 0 10 u_3x) (ddx 0 13 u_t3x) (ddx 0 16 u_2t3x) (ddx 0 19 u_3t3x) (
ddx 0 22 u_4t3x) (ddx 0 25 u_5t3x))
primary_diffcon_odd_tot!*:=((ddt 1 29 q_8t))
primary_diffcon_der!*:=(u_t3x u_2t3x u_3t3x u_4t3x u_5t3x)
primary_diffcon_odd!*:=nil
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_5t3x (*sq ((((alpha . 1) ((u . 6) ((u_5tx . 1) . 3)) ((u . 5)
((u_6t . 1) . 1)) ((u . 4) ((u_2t . 1) ((u_4t . 1) . -15)) ((u_3t . 2) . -10) ((
u_5t . 1) ((u_t . 1) . -6))) ((u . 3) ((u_2t . 3) . 30) ((u_2t . 1) ((u_3t . 1)
((u_t . 1) . 120))) ((u_4t . 1) ((u_t . 2) . 30))) ((u . 2) ((u_2t . 2) ((u_t .
2) . -270)) ((u_3t . 1) ((u_t . 3) . -120))) ((u . 1) ((u_2t . 1) ((u_t . 4) .
360))) ((u_t . 6) . -120)) ((u . 5) ((u_2t2x . 1) ((u_3tx . 1) . -20)) ((u_2tx .
1) ((u_3t2x . 1) . -20)) ((u_2x . 1) ((u_5tx . 1) . -2)) ((u_4t2x . 1) ((u_tx .
1) . -10)) ((u_4tx . 1) ((u_t2x . 1) . -10)) ((u_5t2x . 1) ((u_x . 1) . -2)) ((
u_6t2x . 1) . -1)) ((u . 4) ((u_2t . 1) ((u_2t2x . 1) ((u_tx . 1) . 60)) ((u_2tx
. 1) ((u_t2x . 1) . 60)) ((u_2x . 1) ((u_3tx . 1) . 20)) ((u_3t2x . 1) ((u_x . 1
) . 20)) ((u_4t2x . 1) . 10)) ((u_2t2x . 1) ((u_2tx . 1) ((u_t . 1) . 60)) ((
u_3t . 1) ((u_x . 1) . 20)) ((u_4t . 1) . 5)) ((u_2tx . 1) ((u_2x . 1) ((u_3t .
1) . 20))) ((u_2x . 1) ((u_4t . 1) ((u_tx . 1) . 10)) ((u_4tx . 1) ((u_t . 1) .
10)) ((u_5t . 1) ((u_x . 1) . 2))) ((u_3t . 1) ((u_3t2x . 1) . 10) ((u_t2x . 1)
((u_tx . 1) . 40))) ((u_3t2x . 1) ((u_t . 1) ((u_tx . 1) . 40))) ((u_3tx . 1) ((
u_t . 1) ((u_t2x . 1) . 40))) ((u_4t . 1) ((u_t2x . 1) ((u_x . 1) . 10))) ((
u_4t2x . 1) ((u_t . 1) ((u_x . 1) . 10))) ((u_5t . 1) ((u_t2x . 1) . 1)) ((
u_5t2x . 1) ((u_t . 1) . 5))) ((u . 3) ((u_2t . 2) ((u_2t2x . 1) . -30) ((u_2x .
1) ((u_tx . 1) . -60)) ((u_t2x . 1) ((u_x . 1) . -60))) ((u_2t . 1) ((u_2t2x . 1
) ((u_t . 1) ((u_x . 1) . -120))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 1) . -120)))
((u_2x . 1) ((u_3t . 1) ((u_x . 1) . -40))) ((u_3t . 1) ((u_t2x . 1) . -20)) ((
u_3t2x . 1) ((u_t . 1) . -60)) ((u_t . 1) ((u_t2x . 1) ((u_tx . 1) . -240)))) ((
u_2t2x . 1) ((u_3t . 1) ((u_t . 1) . -40)) ((u_t . 2) ((u_tx . 1) . -120))) ((
u_2tx . 1) ((u_t . 2) ((u_t2x . 1) . -120))) ((u_2x . 1) ((u_3t . 1) ((u_t . 1)
((u_tx . 1) . -80))) ((u_3tx . 1) ((u_t . 2) . -40)) ((u_4t . 1) ((u_t . 1) ((
u_x . 1) . -20)))) ((u_3t . 1) ((u_t . 1) ((u_t2x . 1) ((u_x . 1) . -80)))) ((
u_3t2x . 1) ((u_t . 2) ((u_x . 1) . -40))) ((u_4t . 1) ((u_t . 1) ((u_t2x . 1) .
-10))) ((u_4t2x . 1) ((u_t . 2) . -20))) ((u . 2) ((u_2t . 2) ((u_2x . 1) ((u_t
. 1) ((u_x . 1) . 180))) ((u_t . 1) ((u_t2x . 1) . 90))) ((u_2t . 1) ((u_2t2x .
1) ((u_t . 2) . 180)) ((u_2x . 1) ((u_t . 2) ((u_tx . 1) . 360))) ((u_t . 2) ((
u_t2x . 1) ((u_x . 1) . 360)))) ((u_2t2x . 1) ((u_t . 3) ((u_x . 1) . 120))) ((
u_2tx . 1) ((u_2x . 1) ((u_t . 3) . 120))) ((u_2x . 1) ((u_3t . 1) ((u_t . 2) ((
u_x . 1) . 120)))) ((u_3t . 1) ((u_t . 2) ((u_t2x . 1) . 60))) ((u_3t2x . 1) ((
u_t . 3) . 60)) ((u_t . 3) ((u_t2x . 1) ((u_tx . 1) . 240)))) ((u . 1) ((u_2t .
1) ((u_2x . 1) ((u_t . 3) ((u_x . 1) . -480))) ((u_t . 3) ((u_t2x . 1) . -240)))
((u_2t2x . 1) ((u_t . 4) . -120)) ((u_2x . 1) ((u_t . 4) ((u_tx . 1) . -240))) (
(u_t . 4) ((u_t2x . 1) ((u_x . 1) . -240)))) ((u_2x . 1) ((u_t . 5) ((u_x . 1) .
240))) ((u_t . 5) ((u_t2x . 1) . 120))) ((u . 6) . 1)) nil)) (u_4t3x (*sq ((((
alpha . 1) ((u . 5) ((u_4tx . 1) . 3)) ((u . 4) ((u_5t . 1) . 1)) ((u . 3) ((
u_2t . 1) ((u_3t . 1) . -10)) ((u_4t . 1) ((u_t . 1) . -5))) ((u . 2) ((u_2t . 2
) ((u_t . 1) . 30)) ((u_3t . 1) ((u_t . 2) . 20))) ((u . 1) ((u_2t . 1) ((u_t .
3) . -60))) ((u_t . 5) . 24)) ((u . 4) ((u_2t2x . 1) ((u_2tx . 1) . -12)) ((u_2x
. 1) ((u_4tx . 1) . -2)) ((u_3t2x . 1) ((u_tx . 1) . -8)) ((u_3tx . 1) ((u_t2x .
1) . -8)) ((u_4t2x . 1) ((u_x . 1) . -2)) ((u_5t2x . 1) . -1)) ((u . 3) ((u_2t .
1) ((u_2t2x . 1) ((u_x . 1) . 12)) ((u_2tx . 1) ((u_2x . 1) . 12)) ((u_3t2x . 1)
. 6) ((u_t2x . 1) ((u_tx . 1) . 24))) ((u_2t2x . 1) ((u_3t . 1) . 4) ((u_t . 1)
((u_tx . 1) . 24))) ((u_2tx . 1) ((u_t . 1) ((u_t2x . 1) . 24))) ((u_2x . 1) ((
u_3t . 1) ((u_tx . 1) . 8)) ((u_3tx . 1) ((u_t . 1) . 8)) ((u_4t . 1) ((u_x . 1)
. 2))) ((u_3t . 1) ((u_t2x . 1) ((u_x . 1) . 8))) ((u_3t2x . 1) ((u_t . 1) ((u_x
. 1) . 8))) ((u_4t . 1) ((u_t2x . 1) . 1)) ((u_4t2x . 1) ((u_t . 1) . 4))) ((u .
2) ((u_2t . 2) ((u_2x . 1) ((u_x . 1) . -12)) ((u_t2x . 1) . -6)) ((u_2t . 1) ((
u_2t2x . 1) ((u_t . 1) . -24)) ((u_2x . 1) ((u_t . 1) ((u_tx . 1) . -48))) ((u_t
. 1) ((u_t2x . 1) ((u_x . 1) . -48)))) ((u_2t2x . 1) ((u_t . 2) ((u_x . 1) . -24
))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 2) . -24))) ((u_2x . 1) ((u_3t . 1) ((u_t .
1) ((u_x . 1) . -16)))) ((u_3t . 1) ((u_t . 1) ((u_t2x . 1) . -8))) ((u_3t2x . 1
) ((u_t . 2) . -12)) ((u_t . 2) ((u_t2x . 1) ((u_tx . 1) . -48)))) ((u . 1) ((
u_2t . 1) ((u_2x . 1) ((u_t . 2) ((u_x . 1) . 72))) ((u_t . 2) ((u_t2x . 1) . 36
))) ((u_2t2x . 1) ((u_t . 3) . 24)) ((u_2x . 1) ((u_t . 3) ((u_tx . 1) . 48))) (
(u_t . 3) ((u_t2x . 1) ((u_x . 1) . 48)))) ((u_2x . 1) ((u_t . 4) ((u_x . 1) .
-48))) ((u_t . 4) ((u_t2x . 1) . -24))) ((u . 5) . 1)) nil)) (u_3t3x (*sq ((((
alpha . 1) ((u . 4) ((u_3tx . 1) . 3)) ((u . 3) ((u_4t . 1) . 1)) ((u . 2) ((
u_2t . 2) . -3) ((u_3t . 1) ((u_t . 1) . -4))) ((u . 1) ((u_2t . 1) ((u_t . 2) .
12))) ((u_t . 4) . -6)) ((u . 3) ((u_2t2x . 1) ((u_tx . 1) . -6)) ((u_2tx . 1) (
(u_t2x . 1) . -6)) ((u_2x . 1) ((u_3tx . 1) . -2)) ((u_3t2x . 1) ((u_x . 1) . -2
)) ((u_4t2x . 1) . -1)) ((u . 2) ((u_2t . 1) ((u_2t2x . 1) . 3) ((u_2x . 1) ((
u_tx . 1) . 6)) ((u_t2x . 1) ((u_x . 1) . 6))) ((u_2t2x . 1) ((u_t . 1) ((u_x .
1) . 6))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 1) . 6))) ((u_2x . 1) ((u_3t . 1) ((
u_x . 1) . 2))) ((u_3t . 1) ((u_t2x . 1) . 1)) ((u_3t2x . 1) ((u_t . 1) . 3)) ((
u_t . 1) ((u_t2x . 1) ((u_tx . 1) . 12)))) ((u . 1) ((u_2t . 1) ((u_2x . 1) ((
u_t . 1) ((u_x . 1) . -12))) ((u_t . 1) ((u_t2x . 1) . -6))) ((u_2t2x . 1) ((u_t
. 2) . -6)) ((u_2x . 1) ((u_t . 2) ((u_tx . 1) . -12))) ((u_t . 2) ((u_t2x . 1)
((u_x . 1) . -12)))) ((u_2x . 1) ((u_t . 3) ((u_x . 1) . 12))) ((u_t . 3) ((
u_t2x . 1) . 6))) ((u . 4) . 1)) nil)) (u_2t3x (*sq ((((alpha . 1) ((u . 3) ((
u_2tx . 1) . 3)) ((u . 2) ((u_3t . 1) . 1)) ((u . 1) ((u_2t . 1) ((u_t . 1) . -3
))) ((u_t . 3) . 2)) ((u . 2) ((u_2t2x . 1) ((u_x . 1) . -2)) ((u_2tx . 1) ((
u_2x . 1) . -2)) ((u_3t2x . 1) . -1) ((u_t2x . 1) ((u_tx . 1) . -4))) ((u . 1) (
(u_2t . 1) ((u_2x . 1) ((u_x . 1) . 2)) ((u_t2x . 1) . 1)) ((u_2t2x . 1) ((u_t .
1) . 2)) ((u_2x . 1) ((u_t . 1) ((u_tx . 1) . 4))) ((u_t . 1) ((u_t2x . 1) ((u_x
. 1) . 4)))) ((u_2x . 1) ((u_t . 2) ((u_x . 1) . -4))) ((u_t . 2) ((u_t2x . 1) .
-2))) ((u . 3) . 1)) nil)) (u_t3x (*sq ((((alpha . 1) ((u . 2) ((u_tx . 1) . 3))
((u . 1) ((u_2t . 1) . 1)) ((u_t . 2) . -1)) ((u . 1) ((u_2t2x . 1) . -1) ((u_2x
. 1) ((u_tx . 1) . -2)) ((u_t2x . 1) ((u_x . 1) . -2))) ((u_2x . 1) ((u_t . 1) (
(u_x . 1) . 2))) ((u_t . 1) ((u_t2x . 1) . 1))) ((u . 2) . 1)) nil)) (u_3x (
quotient (plus (times 3 alpha u u_x) (times alpha u_t) (minus (times 2 u_2x u_x)
) (minus u_t2x)) u)) (s1_x (plus (times alpha u) (minus u_2x))) (s1_t (quotient
(plus (minus (times 3 alpha (expt u 2))) (times 2 u u_2x) (expt u_x 2)) 2)) (
s2_x (plus (times alpha (expt u 2)) (minus (times u u_2x)))) (s2_t (plus (minus
(times 2 alpha (expt u 3))) (times 2 (expt u 2) u_2x) (times u u_tx) (minus (
times u_t u_x)))))
diffcon_odd!*:=((q_8t letop))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_5t3x u_4t3x u_3t3x u_2t3x u_t3x u_3x s1_x s1_t s2_x s2_t)
diffcon_comp_odd!*:=(q_8t)
diffcon_comp_ext!*:=((ext 45))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_5t3x *sq ((((alpha . 1) ((u . 6) ((u_5tx . 1) . 3)) ((u
. 5) ((u_6t . 1) . 1)) ((u . 4) ((u_2t . 1) ((u_4t . 1) . -15)) ((u_3t . 2) .
-10) ((u_5t . 1) ((u_t . 1) . -6))) ((u . 3) ((u_2t . 3) . 30) ((u_2t . 1) ((
u_3t . 1) ((u_t . 1) . 120))) ((u_4t . 1) ((u_t . 2) . 30))) ((u . 2) ((u_2t . 2
) ((u_t . 2) . -270)) ((u_3t . 1) ((u_t . 3) . -120))) ((u . 1) ((u_2t . 1) ((
u_t . 4) . 360))) ((u_t . 6) . -120)) ((u . 5) ((u_2t2x . 1) ((u_3tx . 1) . -20)
) ((u_2tx . 1) ((u_3t2x . 1) . -20)) ((u_2x . 1) ((u_5tx . 1) . -2)) ((u_4t2x .
1) ((u_tx . 1) . -10)) ((u_4tx . 1) ((u_t2x . 1) . -10)) ((u_5t2x . 1) ((u_x . 1
) . -2)) ((u_6t2x . 1) . -1)) ((u . 4) ((u_2t . 1) ((u_2t2x . 1) ((u_tx . 1) .
60)) ((u_2tx . 1) ((u_t2x . 1) . 60)) ((u_2x . 1) ((u_3tx . 1) . 20)) ((u_3t2x .
1) ((u_x . 1) . 20)) ((u_4t2x . 1) . 10)) ((u_2t2x . 1) ((u_2tx . 1) ((u_t . 1)
. 60)) ((u_3t . 1) ((u_x . 1) . 20)) ((u_4t . 1) . 5)) ((u_2tx . 1) ((u_2x . 1)
((u_3t . 1) . 20))) ((u_2x . 1) ((u_4t . 1) ((u_tx . 1) . 10)) ((u_4tx . 1) ((
u_t . 1) . 10)) ((u_5t . 1) ((u_x . 1) . 2))) ((u_3t . 1) ((u_3t2x . 1) . 10) ((
u_t2x . 1) ((u_tx . 1) . 40))) ((u_3t2x . 1) ((u_t . 1) ((u_tx . 1) . 40))) ((
u_3tx . 1) ((u_t . 1) ((u_t2x . 1) . 40))) ((u_4t . 1) ((u_t2x . 1) ((u_x . 1) .
10))) ((u_4t2x . 1) ((u_t . 1) ((u_x . 1) . 10))) ((u_5t . 1) ((u_t2x . 1) . 1))
((u_5t2x . 1) ((u_t . 1) . 5))) ((u . 3) ((u_2t . 2) ((u_2t2x . 1) . -30) ((u_2x
. 1) ((u_tx . 1) . -60)) ((u_t2x . 1) ((u_x . 1) . -60))) ((u_2t . 1) ((u_2t2x .
1) ((u_t . 1) ((u_x . 1) . -120))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 1) . -120)))
((u_2x . 1) ((u_3t . 1) ((u_x . 1) . -40))) ((u_3t . 1) ((u_t2x . 1) . -20)) ((
u_3t2x . 1) ((u_t . 1) . -60)) ((u_t . 1) ((u_t2x . 1) ((u_tx . 1) . -240)))) ((
u_2t2x . 1) ((u_3t . 1) ((u_t . 1) . -40)) ((u_t . 2) ((u_tx . 1) . -120))) ((
u_2tx . 1) ((u_t . 2) ((u_t2x . 1) . -120))) ((u_2x . 1) ((u_3t . 1) ((u_t . 1)
((u_tx . 1) . -80))) ((u_3tx . 1) ((u_t . 2) . -40)) ((u_4t . 1) ((u_t . 1) ((
u_x . 1) . -20)))) ((u_3t . 1) ((u_t . 1) ((u_t2x . 1) ((u_x . 1) . -80)))) ((
u_3t2x . 1) ((u_t . 2) ((u_x . 1) . -40))) ((u_4t . 1) ((u_t . 1) ((u_t2x . 1) .
-10))) ((u_4t2x . 1) ((u_t . 2) . -20))) ((u . 2) ((u_2t . 2) ((u_2x . 1) ((u_t
. 1) ((u_x . 1) . 180))) ((u_t . 1) ((u_t2x . 1) . 90))) ((u_2t . 1) ((u_2t2x .
1) ((u_t . 2) . 180)) ((u_2x . 1) ((u_t . 2) ((u_tx . 1) . 360))) ((u_t . 2) ((
u_t2x . 1) ((u_x . 1) . 360)))) ((u_2t2x . 1) ((u_t . 3) ((u_x . 1) . 120))) ((
u_2tx . 1) ((u_2x . 1) ((u_t . 3) . 120))) ((u_2x . 1) ((u_3t . 1) ((u_t . 2) ((
u_x . 1) . 120)))) ((u_3t . 1) ((u_t . 2) ((u_t2x . 1) . 60))) ((u_3t2x . 1) ((
u_t . 3) . 60)) ((u_t . 3) ((u_t2x . 1) ((u_tx . 1) . 240)))) ((u . 1) ((u_2t .
1) ((u_2x . 1) ((u_t . 3) ((u_x . 1) . -480))) ((u_t . 3) ((u_t2x . 1) . -240)))
((u_2t2x . 1) ((u_t . 4) . -120)) ((u_2x . 1) ((u_t . 4) ((u_tx . 1) . -240))) (
(u_t . 4) ((u_t2x . 1) ((u_x . 1) . -240)))) ((u_2x . 1) ((u_t . 5) ((u_x . 1) .
240))) ((u_t . 5) ((u_t2x . 1) . 120))) ((u . 6) . 1)) nil) (u_4t3x *sq ((((
alpha . 1) ((u . 5) ((u_4tx . 1) . 3)) ((u . 4) ((u_5t . 1) . 1)) ((u . 3) ((
u_2t . 1) ((u_3t . 1) . -10)) ((u_4t . 1) ((u_t . 1) . -5))) ((u . 2) ((u_2t . 2
) ((u_t . 1) . 30)) ((u_3t . 1) ((u_t . 2) . 20))) ((u . 1) ((u_2t . 1) ((u_t .
3) . -60))) ((u_t . 5) . 24)) ((u . 4) ((u_2t2x . 1) ((u_2tx . 1) . -12)) ((u_2x
. 1) ((u_4tx . 1) . -2)) ((u_3t2x . 1) ((u_tx . 1) . -8)) ((u_3tx . 1) ((u_t2x .
1) . -8)) ((u_4t2x . 1) ((u_x . 1) . -2)) ((u_5t2x . 1) . -1)) ((u . 3) ((u_2t .
1) ((u_2t2x . 1) ((u_x . 1) . 12)) ((u_2tx . 1) ((u_2x . 1) . 12)) ((u_3t2x . 1)
. 6) ((u_t2x . 1) ((u_tx . 1) . 24))) ((u_2t2x . 1) ((u_3t . 1) . 4) ((u_t . 1)
((u_tx . 1) . 24))) ((u_2tx . 1) ((u_t . 1) ((u_t2x . 1) . 24))) ((u_2x . 1) ((
u_3t . 1) ((u_tx . 1) . 8)) ((u_3tx . 1) ((u_t . 1) . 8)) ((u_4t . 1) ((u_x . 1)
. 2))) ((u_3t . 1) ((u_t2x . 1) ((u_x . 1) . 8))) ((u_3t2x . 1) ((u_t . 1) ((u_x
. 1) . 8))) ((u_4t . 1) ((u_t2x . 1) . 1)) ((u_4t2x . 1) ((u_t . 1) . 4))) ((u .
2) ((u_2t . 2) ((u_2x . 1) ((u_x . 1) . -12)) ((u_t2x . 1) . -6)) ((u_2t . 1) ((
u_2t2x . 1) ((u_t . 1) . -24)) ((u_2x . 1) ((u_t . 1) ((u_tx . 1) . -48))) ((u_t
. 1) ((u_t2x . 1) ((u_x . 1) . -48)))) ((u_2t2x . 1) ((u_t . 2) ((u_x . 1) . -24
))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 2) . -24))) ((u_2x . 1) ((u_3t . 1) ((u_t .
1) ((u_x . 1) . -16)))) ((u_3t . 1) ((u_t . 1) ((u_t2x . 1) . -8))) ((u_3t2x . 1
) ((u_t . 2) . -12)) ((u_t . 2) ((u_t2x . 1) ((u_tx . 1) . -48)))) ((u . 1) ((
u_2t . 1) ((u_2x . 1) ((u_t . 2) ((u_x . 1) . 72))) ((u_t . 2) ((u_t2x . 1) . 36
))) ((u_2t2x . 1) ((u_t . 3) . 24)) ((u_2x . 1) ((u_t . 3) ((u_tx . 1) . 48))) (
(u_t . 3) ((u_t2x . 1) ((u_x . 1) . 48)))) ((u_2x . 1) ((u_t . 4) ((u_x . 1) .
-48))) ((u_t . 4) ((u_t2x . 1) . -24))) ((u . 5) . 1)) nil) (u_3t3x *sq ((((
alpha . 1) ((u . 4) ((u_3tx . 1) . 3)) ((u . 3) ((u_4t . 1) . 1)) ((u . 2) ((
u_2t . 2) . -3) ((u_3t . 1) ((u_t . 1) . -4))) ((u . 1) ((u_2t . 1) ((u_t . 2) .
12))) ((u_t . 4) . -6)) ((u . 3) ((u_2t2x . 1) ((u_tx . 1) . -6)) ((u_2tx . 1) (
(u_t2x . 1) . -6)) ((u_2x . 1) ((u_3tx . 1) . -2)) ((u_3t2x . 1) ((u_x . 1) . -2
)) ((u_4t2x . 1) . -1)) ((u . 2) ((u_2t . 1) ((u_2t2x . 1) . 3) ((u_2x . 1) ((
u_tx . 1) . 6)) ((u_t2x . 1) ((u_x . 1) . 6))) ((u_2t2x . 1) ((u_t . 1) ((u_x .
1) . 6))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 1) . 6))) ((u_2x . 1) ((u_3t . 1) ((
u_x . 1) . 2))) ((u_3t . 1) ((u_t2x . 1) . 1)) ((u_3t2x . 1) ((u_t . 1) . 3)) ((
u_t . 1) ((u_t2x . 1) ((u_tx . 1) . 12)))) ((u . 1) ((u_2t . 1) ((u_2x . 1) ((
u_t . 1) ((u_x . 1) . -12))) ((u_t . 1) ((u_t2x . 1) . -6))) ((u_2t2x . 1) ((u_t
. 2) . -6)) ((u_2x . 1) ((u_t . 2) ((u_tx . 1) . -12))) ((u_t . 2) ((u_t2x . 1)
((u_x . 1) . -12)))) ((u_2x . 1) ((u_t . 3) ((u_x . 1) . 12))) ((u_t . 3) ((
u_t2x . 1) . 6))) ((u . 4) . 1)) nil) (u_2t3x *sq ((((alpha . 1) ((u . 3) ((
u_2tx . 1) . 3)) ((u . 2) ((u_3t . 1) . 1)) ((u . 1) ((u_2t . 1) ((u_t . 1) . -3
))) ((u_t . 3) . 2)) ((u . 2) ((u_2t2x . 1) ((u_x . 1) . -2)) ((u_2tx . 1) ((
u_2x . 1) . -2)) ((u_3t2x . 1) . -1) ((u_t2x . 1) ((u_tx . 1) . -4))) ((u . 1) (
(u_2t . 1) ((u_2x . 1) ((u_x . 1) . 2)) ((u_t2x . 1) . 1)) ((u_2t2x . 1) ((u_t .
1) . 2)) ((u_2x . 1) ((u_t . 1) ((u_tx . 1) . 4))) ((u_t . 1) ((u_t2x . 1) ((u_x
. 1) . 4)))) ((u_2x . 1) ((u_t . 2) ((u_x . 1) . -4))) ((u_t . 2) ((u_t2x . 1) .
-2))) ((u . 3) . 1)) nil) (u_t3x *sq ((((alpha . 1) ((u . 2) ((u_tx . 1) . 3)) (
(u . 1) ((u_2t . 1) . 1)) ((u_t . 2) . -1)) ((u . 1) ((u_2t2x . 1) . -1) ((u_2x
. 1) ((u_tx . 1) . -2)) ((u_t2x . 1) ((u_x . 1) . -2))) ((u_2x . 1) ((u_t . 1) (
(u_x . 1) . 2))) ((u_t . 1) ((u_t2x . 1) . 1))) ((u . 2) . 1)) nil) (u_3x *sq ((
((alpha . 1) ((u . 1) ((u_x . 1) . 3)) ((u_t . 1) . 1)) ((u_2x . 1) ((u_x . 1) .
-2)) ((u_t2x . 1) . -1)) ((u . 1) . 1)) nil) (s1_x *sq ((((alpha . 1) ((u . 1) .
1)) ((u_2x . 1) . -1)) . 1) nil) (s1_t *sq ((((alpha . 1) ((u . 2) . -3)) ((u .
1) ((u_2x . 1) . 2)) ((u_x . 2) . 1)) . 2) nil) (s2_x *sq ((((alpha . 1) ((u . 2
) . 1)) ((u . 1) ((u_2x . 1) . -1))) . 1) nil) (s2_t *sq ((((alpha . 1) ((u . 3)
. -2)) ((u . 2) ((u_2x . 1) . 2)) ((u . 1) ((u_tx . 1) . 1)) ((u_t . 1) ((u_x .
1) . -1))) . 1) nil))
diffcon_param_ext!*:=(((ext 45) *sq ((((letop . 1) . 1)) . 1) nil))
% Coefficients of total derivatives:
% component of ddt w.r.t. t
ddt(0,1):=1
% component of ddt w.r.t. x
ddt(0,2):=0
% component of ddt w.r.t. u
ddt(0,3):=(*sq ((((u_t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1
ddt(0,4):=(*sq ((((alpha . 1) ((u . 2) . -3)) ((u . 1) ((u_2x . 1) . 2)) ((u_x .
2) . 1)) . 2) t)
% component of ddt w.r.t. s2
ddt(0,5):=(*sq ((((alpha . 1) ((u . 3) . -2)) ((u . 2) ((u_2x . 1) . 2)) ((u . 1
) ((u_tx . 1) . 1)) ((u_t . 1) ((u_x . 1) . -1))) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,6):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,7):=(*sq ((((u_tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,8):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_tx
ddt(0,9):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x
ddt(0,10):=(*sq ((((u_t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,11):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2tx
ddt(0,12):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2x
ddt(0,13):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,14):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3tx
ddt(0,15):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t2x
ddt(0,16):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,17):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4tx
ddt(0,18):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t2x
ddt(0,19):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,20):=(*sq ((((u_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5tx
ddt(0,21):=(*sq ((((u_6tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t2x
ddt(0,22):=(*sq ((((u_5t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t
ddt(0,23):=(*sq ((((u_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6tx
ddt(0,24):=(*sq ((((u_7tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t2x
ddt(0,25):=(*sq ((((u_6t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t
ddt(0,26):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7tx
ddt(0,27):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t2x
ddt(0,28):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t
ddt(0,29):=(*sq ((((s1_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_x
ddt(0,30):=(*sq ((((s1_tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t
ddt(0,31):=(*sq ((((s2_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_x
ddt(0,32):=(*sq ((((s2_tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_tx
ddt(0,33):=(*sq ((((s1_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t
ddt(0,34):=(*sq ((((s1_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2x
ddt(0,35):=(*sq ((((s1_t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_tx
ddt(0,36):=(*sq ((((s1_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_tx
ddt(0,37):=(*sq ((((s2_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t
ddt(0,38):=(*sq ((((s2_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2x
ddt(0,39):=(*sq ((((s2_t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_tx
ddt(0,40):=(*sq ((((s2_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,41):=(*sq ((((u_t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t2x
ddt(0,42):=(*sq ((((s1_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2tx
ddt(0,43):=(*sq ((((s1_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t
ddt(0,44):=(*sq ((((s1_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3x
ddt(0,45):=(*sq ((((s1_t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t2x
ddt(0,46):=(*sq ((((s1_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2tx
ddt(0,47):=(*sq ((((s1_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t2x
ddt(0,48):=(*sq ((((s2_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2tx
ddt(0,49):=(*sq ((((s2_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t
ddt(0,50):=(*sq ((((s2_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3x
ddt(0,51):=(*sq ((((s2_t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t2x
ddt(0,52):=(*sq ((((s2_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2tx
ddt(0,53):=(*sq ((((s2_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,54):=(*sq ((((u_t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t3x
ddt(0,55):=(*sq ((((u_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t3x
ddt(0,56):=(*sq ((((s1_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t2x
ddt(0,57):=(*sq ((((s1_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3tx
ddt(0,58):=(*sq ((((s1_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4t
ddt(0,59):=(*sq ((((s1_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4x
ddt(0,60):=(*sq ((((s1_t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t3x
ddt(0,61):=(*sq ((((s1_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t2x
ddt(0,62):=(*sq ((((s1_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3tx
ddt(0,63):=(*sq ((((s1_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t3x
ddt(0,64):=(*sq ((((s2_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t2x
ddt(0,65):=(*sq ((((s2_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3tx
ddt(0,66):=(*sq ((((s2_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4t
ddt(0,67):=(*sq ((((s2_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4x
ddt(0,68):=(*sq ((((s2_t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t3x
ddt(0,69):=(*sq ((((s2_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t2x
ddt(0,70):=(*sq ((((s2_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3tx
ddt(0,71):=(*sq ((((s2_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,72):=(*sq ((((u_t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t4x
ddt(0,73):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t3x
ddt(0,74):=(*sq ((((u_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t4x
ddt(0,75):=(*sq ((((s1_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t3x
ddt(0,76):=(*sq ((((s1_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t2x
ddt(0,77):=(*sq ((((s1_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4tx
ddt(0,78):=(*sq ((((s1_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_5t
ddt(0,79):=(*sq ((((s1_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_5x
ddt(0,80):=(*sq ((((s1_t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t4x
ddt(0,81):=(*sq ((((s1_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t3x
ddt(0,82):=(*sq ((((s1_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t2x
ddt(0,83):=(*sq ((((s1_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4tx
ddt(0,84):=(*sq ((((s1_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t4x
ddt(0,85):=(*sq ((((s2_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t3x
ddt(0,86):=(*sq ((((s2_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t2x
ddt(0,87):=(*sq ((((s2_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4tx
ddt(0,88):=(*sq ((((s2_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_5t
ddt(0,89):=(*sq ((((s2_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_5x
ddt(0,90):=(*sq ((((s2_t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t4x
ddt(0,91):=(*sq ((((s2_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t3x
ddt(0,92):=(*sq ((((s2_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t2x
ddt(0,93):=(*sq ((((s2_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4tx
ddt(0,94):=(*sq ((((s2_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,95):=(*sq ((((u_t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t5x
ddt(0,96):=(*sq ((((u_2t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t4x
ddt(0,97):=(*sq ((((u_3t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t3x
ddt(0,98):=(*sq ((((u_4t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t5x
ddt(0,99):=(*sq ((((s1_2t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t4x
ddt(0,100):=(*sq ((((s1_3t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t3x
ddt(0,101):=(*sq ((((s1_4t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4t2x
ddt(0,102):=(*sq ((((s1_5t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_5tx
ddt(0,103):=(*sq ((((s1_6tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_6t
ddt(0,104):=(*sq ((((s1_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_6x
ddt(0,105):=(*sq ((((s1_t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t5x
ddt(0,106):=(*sq ((((s1_2t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t4x
ddt(0,107):=(*sq ((((s1_3t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t3x
ddt(0,108):=(*sq ((((s1_4t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4t2x
ddt(0,109):=(*sq ((((s1_5t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_5tx
ddt(0,110):=(*sq ((((s1_6tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t5x
ddt(0,111):=(*sq ((((s2_2t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t4x
ddt(0,112):=(*sq ((((s2_3t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t3x
ddt(0,113):=(*sq ((((s2_4t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4t2x
ddt(0,114):=(*sq ((((s2_5t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_5tx
ddt(0,115):=(*sq ((((s2_6tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_6t
ddt(0,116):=(*sq ((((s2_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_6x
ddt(0,117):=(*sq ((((s2_t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t5x
ddt(0,118):=(*sq ((((s2_2t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t4x
ddt(0,119):=(*sq ((((s2_3t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t3x
ddt(0,120):=(*sq ((((s2_4t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4t2x
ddt(0,121):=(*sq ((((s2_5t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_5tx
ddt(0,122):=(*sq ((((s2_6tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7x
ddt(0,123):=(*sq ((((u_t7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t6x
ddt(0,124):=(*sq ((((u_2t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t5x
ddt(0,125):=(*sq ((((u_3t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t4x
ddt(0,126):=(*sq ((((u_4t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t3x
ddt(0,127):=(*sq ((((u_5t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t6x
ddt(0,128):=(*sq ((((s1_2t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t5x
ddt(0,129):=(*sq ((((s1_3t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t4x
ddt(0,130):=(*sq ((((s1_4t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4t3x
ddt(0,131):=(*sq ((((s1_5t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_5t2x
ddt(0,132):=(*sq ((((s1_6t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_6tx
ddt(0,133):=(*sq ((((s1_7tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_7t
ddt(0,134):=(*sq ((((s1_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_7x
ddt(0,135):=(*sq ((((s1_t7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t6x
ddt(0,136):=(*sq ((((s1_2t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t5x
ddt(0,137):=(*sq ((((s1_3t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t4x
ddt(0,138):=(*sq ((((s1_4t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4t3x
ddt(0,139):=(*sq ((((s1_5t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_5t2x
ddt(0,140):=(*sq ((((s1_6t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_6tx
ddt(0,141):=(*sq ((((s1_7tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t6x
ddt(0,142):=(*sq ((((s2_2t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t5x
ddt(0,143):=(*sq ((((s2_3t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t4x
ddt(0,144):=(*sq ((((s2_4t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4t3x
ddt(0,145):=(*sq ((((s2_5t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_5t2x
ddt(0,146):=(*sq ((((s2_6t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_6tx
ddt(0,147):=(*sq ((((s2_7tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_7t
ddt(0,148):=(*sq ((((s2_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_7x
ddt(0,149):=(*sq ((((s2_t7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t6x
ddt(0,150):=(*sq ((((s2_2t6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t5x
ddt(0,151):=(*sq ((((s2_3t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t4x
ddt(0,152):=(*sq ((((s2_4t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4t3x
ddt(0,153):=(*sq ((((s2_5t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_5t2x
ddt(0,154):=(*sq ((((s2_6t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_6tx
ddt(0,155):=(*sq ((((s2_7tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,156):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t7x
ddt(0,157):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t6x
ddt(0,158):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t5x
ddt(0,159):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t4x
ddt(0,160):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t3x
ddt(0,161):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_t7x
ddt(0,162):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_2t6x
ddt(0,163):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_3t5x
ddt(0,164):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_4t4x
ddt(0,165):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_5t3x
ddt(0,166):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_6t2x
ddt(0,167):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_7tx
ddt(0,168):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_8t
ddt(0,169):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s1_8x
ddt(0,170):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_t7x
ddt(0,171):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_2t6x
ddt(0,172):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_3t5x
ddt(0,173):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_4t4x
ddt(0,174):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_5t3x
ddt(0,175):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_6t2x
ddt(0,176):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_7tx
ddt(0,177):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_8t
ddt(0,178):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. s2_8x
ddt(0,179):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q
ddt(1,1):=(*sq (((((ext 2) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t
ddt(1,2):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x
ddt(1,3):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t
ddt(1,4):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_tx
ddt(1,5):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x
ddt(1,6):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t
ddt(1,7):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2tx
ddt(1,8):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t2x
ddt(1,9):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x
ddt(1,10):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t
ddt(1,11):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3tx
ddt(1,12):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t2x
ddt(1,13):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t3x
ddt(1,14):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x
ddt(1,15):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t
ddt(1,16):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4tx
ddt(1,17):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t2x
ddt(1,18):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t3x
ddt(1,19):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t4x
ddt(1,20):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x
ddt(1,21):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t
ddt(1,22):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5tx
ddt(1,23):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t2x
ddt(1,24):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t3x
ddt(1,25):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t4x
ddt(1,26):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t5x
ddt(1,27):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6x
ddt(1,28):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7t
ddt(1,29):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6tx
ddt(1,30):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t2x
ddt(1,31):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t3x
ddt(1,32):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t4x
ddt(1,33):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t5x
ddt(1,34):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t6x
ddt(1,35):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7x
ddt(1,36):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7tx
ddt(1,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t2x
ddt(1,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t3x
ddt(1,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t4x
ddt(1,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t5x
ddt(1,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t6x
ddt(1,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t7x
ddt(1,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8x
ddt(1,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8t
ddt(1,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. t
ddx(0,1):=0
% component of ddx w.r.t. x
ddx(0,2):=1
% component of ddx w.r.t. u
ddx(0,3):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1
ddx(0,4):=(*sq ((((alpha . 1) ((u . 1) . 1)) ((u_2x . 1) . -1)) . 1) t)
% component of ddx w.r.t. s2
ddx(0,5):=(*sq ((((alpha . 1) ((u . 2) . 1)) ((u . 1) ((u_2x . 1) . -1))) . 1) t
)
% component of ddx w.r.t. u_t
ddx(0,6):=(*sq ((((u_tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x
ddx(0,7):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,8):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_tx
ddx(0,9):=(*sq ((((u_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x
ddx(0,10):=(*sq ((((alpha . 1) ((u . 1) ((u_x . 1) . 3)) ((u_t . 1) . 1)) ((u_2x
. 1) ((u_x . 1) . -2)) ((u_t2x . 1) . -1)) ((u . 1) . 1)) t)
% component of ddx w.r.t. u_3t
ddx(0,11):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2tx
ddx(0,12):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2x
ddx(0,13):=(*sq ((((alpha . 1) ((u . 2) ((u_tx . 1) . 3)) ((u . 1) ((u_2t . 1) .
1)) ((u_t . 2) . -1)) ((u . 1) ((u_2t2x . 1) . -1) ((u_2x . 1) ((u_tx . 1) . -2)
) ((u_t2x . 1) ((u_x . 1) . -2))) ((u_2x . 1) ((u_t . 1) ((u_x . 1) . 2))) ((u_t
. 1) ((u_t2x . 1) . 1))) ((u . 2) . 1)) t)
% component of ddx w.r.t. u_4t
ddx(0,14):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3tx
ddx(0,15):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t2x
ddx(0,16):=(*sq ((((alpha . 1) ((u . 3) ((u_2tx . 1) . 3)) ((u . 2) ((u_3t . 1)
. 1)) ((u . 1) ((u_2t . 1) ((u_t . 1) . -3))) ((u_t . 3) . 2)) ((u . 2) ((u_2t2x
. 1) ((u_x . 1) . -2)) ((u_2tx . 1) ((u_2x . 1) . -2)) ((u_3t2x . 1) . -1) ((
u_t2x . 1) ((u_tx . 1) . -4))) ((u . 1) ((u_2t . 1) ((u_2x . 1) ((u_x . 1) . 2))
((u_t2x . 1) . 1)) ((u_2t2x . 1) ((u_t . 1) . 2)) ((u_2x . 1) ((u_t . 1) ((u_tx
. 1) . 4))) ((u_t . 1) ((u_t2x . 1) ((u_x . 1) . 4)))) ((u_2x . 1) ((u_t . 2) ((
u_x . 1) . -4))) ((u_t . 2) ((u_t2x . 1) . -2))) ((u . 3) . 1)) t)
% component of ddx w.r.t. u_5t
ddx(0,17):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4tx
ddx(0,18):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t2x
ddx(0,19):=(*sq ((((alpha . 1) ((u . 4) ((u_3tx . 1) . 3)) ((u . 3) ((u_4t . 1)
. 1)) ((u . 2) ((u_2t . 2) . -3) ((u_3t . 1) ((u_t . 1) . -4))) ((u . 1) ((u_2t
. 1) ((u_t . 2) . 12))) ((u_t . 4) . -6)) ((u . 3) ((u_2t2x . 1) ((u_tx . 1) .
-6)) ((u_2tx . 1) ((u_t2x . 1) . -6)) ((u_2x . 1) ((u_3tx . 1) . -2)) ((u_3t2x .
1) ((u_x . 1) . -2)) ((u_4t2x . 1) . -1)) ((u . 2) ((u_2t . 1) ((u_2t2x . 1) . 3
) ((u_2x . 1) ((u_tx . 1) . 6)) ((u_t2x . 1) ((u_x . 1) . 6))) ((u_2t2x . 1) ((
u_t . 1) ((u_x . 1) . 6))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 1) . 6))) ((u_2x . 1
) ((u_3t . 1) ((u_x . 1) . 2))) ((u_3t . 1) ((u_t2x . 1) . 1)) ((u_3t2x . 1) ((
u_t . 1) . 3)) ((u_t . 1) ((u_t2x . 1) ((u_tx . 1) . 12)))) ((u . 1) ((u_2t . 1)
((u_2x . 1) ((u_t . 1) ((u_x . 1) . -12))) ((u_t . 1) ((u_t2x . 1) . -6))) ((
u_2t2x . 1) ((u_t . 2) . -6)) ((u_2x . 1) ((u_t . 2) ((u_tx . 1) . -12))) ((u_t
. 2) ((u_t2x . 1) ((u_x . 1) . -12)))) ((u_2x . 1) ((u_t . 3) ((u_x . 1) . 12)))
((u_t . 3) ((u_t2x . 1) . 6))) ((u . 4) . 1)) t)
% component of ddx w.r.t. u_6t
ddx(0,20):=(*sq ((((u_6tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5tx
ddx(0,21):=(*sq ((((u_5t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t2x
ddx(0,22):=(*sq ((((alpha . 1) ((u . 5) ((u_4tx . 1) . 3)) ((u . 4) ((u_5t . 1)
. 1)) ((u . 3) ((u_2t . 1) ((u_3t . 1) . -10)) ((u_4t . 1) ((u_t . 1) . -5))) ((
u . 2) ((u_2t . 2) ((u_t . 1) . 30)) ((u_3t . 1) ((u_t . 2) . 20))) ((u . 1) ((
u_2t . 1) ((u_t . 3) . -60))) ((u_t . 5) . 24)) ((u . 4) ((u_2t2x . 1) ((u_2tx .
1) . -12)) ((u_2x . 1) ((u_4tx . 1) . -2)) ((u_3t2x . 1) ((u_tx . 1) . -8)) ((
u_3tx . 1) ((u_t2x . 1) . -8)) ((u_4t2x . 1) ((u_x . 1) . -2)) ((u_5t2x . 1) .
-1)) ((u . 3) ((u_2t . 1) ((u_2t2x . 1) ((u_x . 1) . 12)) ((u_2tx . 1) ((u_2x .
1) . 12)) ((u_3t2x . 1) . 6) ((u_t2x . 1) ((u_tx . 1) . 24))) ((u_2t2x . 1) ((
u_3t . 1) . 4) ((u_t . 1) ((u_tx . 1) . 24))) ((u_2tx . 1) ((u_t . 1) ((u_t2x .
1) . 24))) ((u_2x . 1) ((u_3t . 1) ((u_tx . 1) . 8)) ((u_3tx . 1) ((u_t . 1) . 8
)) ((u_4t . 1) ((u_x . 1) . 2))) ((u_3t . 1) ((u_t2x . 1) ((u_x . 1) . 8))) ((
u_3t2x . 1) ((u_t . 1) ((u_x . 1) . 8))) ((u_4t . 1) ((u_t2x . 1) . 1)) ((u_4t2x
. 1) ((u_t . 1) . 4))) ((u . 2) ((u_2t . 2) ((u_2x . 1) ((u_x . 1) . -12)) ((
u_t2x . 1) . -6)) ((u_2t . 1) ((u_2t2x . 1) ((u_t . 1) . -24)) ((u_2x . 1) ((u_t
. 1) ((u_tx . 1) . -48))) ((u_t . 1) ((u_t2x . 1) ((u_x . 1) . -48)))) ((u_2t2x
. 1) ((u_t . 2) ((u_x . 1) . -24))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 2) . -24)))
((u_2x . 1) ((u_3t . 1) ((u_t . 1) ((u_x . 1) . -16)))) ((u_3t . 1) ((u_t . 1) (
(u_t2x . 1) . -8))) ((u_3t2x . 1) ((u_t . 2) . -12)) ((u_t . 2) ((u_t2x . 1) ((
u_tx . 1) . -48)))) ((u . 1) ((u_2t . 1) ((u_2x . 1) ((u_t . 2) ((u_x . 1) . 72)
)) ((u_t . 2) ((u_t2x . 1) . 36))) ((u_2t2x . 1) ((u_t . 3) . 24)) ((u_2x . 1) (
(u_t . 3) ((u_tx . 1) . 48))) ((u_t . 3) ((u_t2x . 1) ((u_x . 1) . 48)))) ((u_2x
. 1) ((u_t . 4) ((u_x . 1) . -48))) ((u_t . 4) ((u_t2x . 1) . -24))) ((u . 5) .
1)) t)
% component of ddx w.r.t. u_7t
ddx(0,23):=(*sq ((((u_7tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6tx
ddx(0,24):=(*sq ((((u_6t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t2x
ddx(0,25):=(*sq ((((alpha . 1) ((u . 6) ((u_5tx . 1) . 3)) ((u . 5) ((u_6t . 1)
. 1)) ((u . 4) ((u_2t . 1) ((u_4t . 1) . -15)) ((u_3t . 2) . -10) ((u_5t . 1) ((
u_t . 1) . -6))) ((u . 3) ((u_2t . 3) . 30) ((u_2t . 1) ((u_3t . 1) ((u_t . 1) .
120))) ((u_4t . 1) ((u_t . 2) . 30))) ((u . 2) ((u_2t . 2) ((u_t . 2) . -270)) (
(u_3t . 1) ((u_t . 3) . -120))) ((u . 1) ((u_2t . 1) ((u_t . 4) . 360))) ((u_t .
6) . -120)) ((u . 5) ((u_2t2x . 1) ((u_3tx . 1) . -20)) ((u_2tx . 1) ((u_3t2x .
1) . -20)) ((u_2x . 1) ((u_5tx . 1) . -2)) ((u_4t2x . 1) ((u_tx . 1) . -10)) ((
u_4tx . 1) ((u_t2x . 1) . -10)) ((u_5t2x . 1) ((u_x . 1) . -2)) ((u_6t2x . 1) .
-1)) ((u . 4) ((u_2t . 1) ((u_2t2x . 1) ((u_tx . 1) . 60)) ((u_2tx . 1) ((u_t2x
. 1) . 60)) ((u_2x . 1) ((u_3tx . 1) . 20)) ((u_3t2x . 1) ((u_x . 1) . 20)) ((
u_4t2x . 1) . 10)) ((u_2t2x . 1) ((u_2tx . 1) ((u_t . 1) . 60)) ((u_3t . 1) ((
u_x . 1) . 20)) ((u_4t . 1) . 5)) ((u_2tx . 1) ((u_2x . 1) ((u_3t . 1) . 20))) (
(u_2x . 1) ((u_4t . 1) ((u_tx . 1) . 10)) ((u_4tx . 1) ((u_t . 1) . 10)) ((u_5t
. 1) ((u_x . 1) . 2))) ((u_3t . 1) ((u_3t2x . 1) . 10) ((u_t2x . 1) ((u_tx . 1)
. 40))) ((u_3t2x . 1) ((u_t . 1) ((u_tx . 1) . 40))) ((u_3tx . 1) ((u_t . 1) ((
u_t2x . 1) . 40))) ((u_4t . 1) ((u_t2x . 1) ((u_x . 1) . 10))) ((u_4t2x . 1) ((
u_t . 1) ((u_x . 1) . 10))) ((u_5t . 1) ((u_t2x . 1) . 1)) ((u_5t2x . 1) ((u_t .
1) . 5))) ((u . 3) ((u_2t . 2) ((u_2t2x . 1) . -30) ((u_2x . 1) ((u_tx . 1) .
-60)) ((u_t2x . 1) ((u_x . 1) . -60))) ((u_2t . 1) ((u_2t2x . 1) ((u_t . 1) ((
u_x . 1) . -120))) ((u_2tx . 1) ((u_2x . 1) ((u_t . 1) . -120))) ((u_2x . 1) ((
u_3t . 1) ((u_x . 1) . -40))) ((u_3t . 1) ((u_t2x . 1) . -20)) ((u_3t2x . 1) ((
u_t . 1) . -60)) ((u_t . 1) ((u_t2x . 1) ((u_tx . 1) . -240)))) ((u_2t2x . 1) ((
u_3t . 1) ((u_t . 1) . -40)) ((u_t . 2) ((u_tx . 1) . -120))) ((u_2tx . 1) ((u_t
. 2) ((u_t2x . 1) . -120))) ((u_2x . 1) ((u_3t . 1) ((u_t . 1) ((u_tx . 1) . -80
))) ((u_3tx . 1) ((u_t . 2) . -40)) ((u_4t . 1) ((u_t . 1) ((u_x . 1) . -20))))
((u_3t . 1) ((u_t . 1) ((u_t2x . 1) ((u_x . 1) . -80)))) ((u_3t2x . 1) ((u_t . 2
) ((u_x . 1) . -40))) ((u_4t . 1) ((u_t . 1) ((u_t2x . 1) . -10))) ((u_4t2x . 1)
((u_t . 2) . -20))) ((u . 2) ((u_2t . 2) ((u_2x . 1) ((u_t . 1) ((u_x . 1) . 180
))) ((u_t . 1) ((u_t2x . 1) . 90))) ((u_2t . 1) ((u_2t2x . 1) ((u_t . 2) . 180))
((u_2x . 1) ((u_t . 2) ((u_tx . 1) . 360))) ((u_t . 2) ((u_t2x . 1) ((u_x . 1) .
360)))) ((u_2t2x . 1) ((u_t . 3) ((u_x . 1) . 120))) ((u_2tx . 1) ((u_2x . 1) ((
u_t . 3) . 120))) ((u_2x . 1) ((u_3t . 1) ((u_t . 2) ((u_x . 1) . 120)))) ((u_3t
. 1) ((u_t . 2) ((u_t2x . 1) . 60))) ((u_3t2x . 1) ((u_t . 3) . 60)) ((u_t . 3)
((u_t2x . 1) ((u_tx . 1) . 240)))) ((u . 1) ((u_2t . 1) ((u_2x . 1) ((u_t . 3) (
(u_x . 1) . -480))) ((u_t . 3) ((u_t2x . 1) . -240))) ((u_2t2x . 1) ((u_t . 4) .
-120)) ((u_2x . 1) ((u_t . 4) ((u_tx . 1) . -240))) ((u_t . 4) ((u_t2x . 1) ((
u_x . 1) . -240)))) ((u_2x . 1) ((u_t . 5) ((u_x . 1) . 240))) ((u_t . 5) ((
u_t2x . 1) . 120))) ((u . 6) . 1)) t)
% component of ddx w.r.t. u_8t
ddx(0,26):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7tx
ddx(0,27):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t2x
ddx(0,28):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t
ddx(0,29):=(*sq ((((s1_tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_x
ddx(0,30):=(*sq ((((s1_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t
ddx(0,31):=(*sq ((((s2_tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_x
ddx(0,32):=(*sq ((((s2_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_tx
ddx(0,33):=(*sq ((((s1_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t
ddx(0,34):=(*sq ((((s1_2tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2x
ddx(0,35):=(*sq ((((s1_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_tx
ddx(0,36):=(*sq ((((s1_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_tx
ddx(0,37):=(*sq ((((s2_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t
ddx(0,38):=(*sq ((((s2_2tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2x
ddx(0,39):=(*sq ((((s2_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_tx
ddx(0,40):=(*sq ((((s2_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x
ddx(0,41):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t2x
ddx(0,42):=(*sq ((((s1_t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2tx
ddx(0,43):=(*sq ((((s1_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t
ddx(0,44):=(*sq ((((s1_3tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3x
ddx(0,45):=(*sq ((((s1_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t2x
ddx(0,46):=(*sq ((((s1_t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2tx
ddx(0,47):=(*sq ((((s1_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t2x
ddx(0,48):=(*sq ((((s2_t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2tx
ddx(0,49):=(*sq ((((s2_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t
ddx(0,50):=(*sq ((((s2_3tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3x
ddx(0,51):=(*sq ((((s2_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t2x
ddx(0,52):=(*sq ((((s2_t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2tx
ddx(0,53):=(*sq ((((s2_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x
ddx(0,54):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t3x
ddx(0,55):=(*sq ((((u_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t3x
ddx(0,56):=(*sq ((((s1_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t2x
ddx(0,57):=(*sq ((((s1_2t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3tx
ddx(0,58):=(*sq ((((s1_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4t
ddx(0,59):=(*sq ((((s1_4tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4x
ddx(0,60):=(*sq ((((s1_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t3x
ddx(0,61):=(*sq ((((s1_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t2x
ddx(0,62):=(*sq ((((s1_2t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3tx
ddx(0,63):=(*sq ((((s1_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t3x
ddx(0,64):=(*sq ((((s2_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t2x
ddx(0,65):=(*sq ((((s2_2t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3tx
ddx(0,66):=(*sq ((((s2_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4t
ddx(0,67):=(*sq ((((s2_4tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4x
ddx(0,68):=(*sq ((((s2_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t3x
ddx(0,69):=(*sq ((((s2_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t2x
ddx(0,70):=(*sq ((((s2_2t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3tx
ddx(0,71):=(*sq ((((s2_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x
ddx(0,72):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t4x
ddx(0,73):=(*sq ((((u_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t3x
ddx(0,74):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t4x
ddx(0,75):=(*sq ((((s1_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t3x
ddx(0,76):=(*sq ((((s1_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t2x
ddx(0,77):=(*sq ((((s1_3t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4tx
ddx(0,78):=(*sq ((((s1_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_5t
ddx(0,79):=(*sq ((((s1_5tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_5x
ddx(0,80):=(*sq ((((s1_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t4x
ddx(0,81):=(*sq ((((s1_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t3x
ddx(0,82):=(*sq ((((s1_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t2x
ddx(0,83):=(*sq ((((s1_3t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4tx
ddx(0,84):=(*sq ((((s1_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t4x
ddx(0,85):=(*sq ((((s2_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t3x
ddx(0,86):=(*sq ((((s2_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t2x
ddx(0,87):=(*sq ((((s2_3t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4tx
ddx(0,88):=(*sq ((((s2_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_5t
ddx(0,89):=(*sq ((((s2_5tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_5x
ddx(0,90):=(*sq ((((s2_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t4x
ddx(0,91):=(*sq ((((s2_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t3x
ddx(0,92):=(*sq ((((s2_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t2x
ddx(0,93):=(*sq ((((s2_3t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4tx
ddx(0,94):=(*sq ((((s2_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x
ddx(0,95):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t5x
ddx(0,96):=(*sq ((((u_t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t4x
ddx(0,97):=(*sq ((((u_2t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t3x
ddx(0,98):=(*sq ((((u_3t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t5x
ddx(0,99):=(*sq ((((s1_t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t4x
ddx(0,100):=(*sq ((((s1_2t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t3x
ddx(0,101):=(*sq ((((s1_3t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4t2x
ddx(0,102):=(*sq ((((s1_4t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_5tx
ddx(0,103):=(*sq ((((s1_5t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_6t
ddx(0,104):=(*sq ((((s1_6tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_6x
ddx(0,105):=(*sq ((((s1_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t5x
ddx(0,106):=(*sq ((((s1_t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t4x
ddx(0,107):=(*sq ((((s1_2t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t3x
ddx(0,108):=(*sq ((((s1_3t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4t2x
ddx(0,109):=(*sq ((((s1_4t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_5tx
ddx(0,110):=(*sq ((((s1_5t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t5x
ddx(0,111):=(*sq ((((s2_t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t4x
ddx(0,112):=(*sq ((((s2_2t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t3x
ddx(0,113):=(*sq ((((s2_3t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4t2x
ddx(0,114):=(*sq ((((s2_4t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_5tx
ddx(0,115):=(*sq ((((s2_5t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_6t
ddx(0,116):=(*sq ((((s2_6tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_6x
ddx(0,117):=(*sq ((((s2_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t5x
ddx(0,118):=(*sq ((((s2_t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t4x
ddx(0,119):=(*sq ((((s2_2t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t3x
ddx(0,120):=(*sq ((((s2_3t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4t2x
ddx(0,121):=(*sq ((((s2_4t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_5tx
ddx(0,122):=(*sq ((((s2_5t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x
ddx(0,123):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t6x
ddx(0,124):=(*sq ((((u_t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t5x
ddx(0,125):=(*sq ((((u_2t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t4x
ddx(0,126):=(*sq ((((u_3t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t3x
ddx(0,127):=(*sq ((((u_4t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t6x
ddx(0,128):=(*sq ((((s1_t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t5x
ddx(0,129):=(*sq ((((s1_2t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t4x
ddx(0,130):=(*sq ((((s1_3t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4t3x
ddx(0,131):=(*sq ((((s1_4t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_5t2x
ddx(0,132):=(*sq ((((s1_5t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_6tx
ddx(0,133):=(*sq ((((s1_6t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_7t
ddx(0,134):=(*sq ((((s1_7tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_7x
ddx(0,135):=(*sq ((((s1_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t6x
ddx(0,136):=(*sq ((((s1_t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t5x
ddx(0,137):=(*sq ((((s1_2t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t4x
ddx(0,138):=(*sq ((((s1_3t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4t3x
ddx(0,139):=(*sq ((((s1_4t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_5t2x
ddx(0,140):=(*sq ((((s1_5t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_6tx
ddx(0,141):=(*sq ((((s1_6t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t6x
ddx(0,142):=(*sq ((((s2_t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t5x
ddx(0,143):=(*sq ((((s2_2t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t4x
ddx(0,144):=(*sq ((((s2_3t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4t3x
ddx(0,145):=(*sq ((((s2_4t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_5t2x
ddx(0,146):=(*sq ((((s2_5t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_6tx
ddx(0,147):=(*sq ((((s2_6t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_7t
ddx(0,148):=(*sq ((((s2_7tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_7x
ddx(0,149):=(*sq ((((s2_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t6x
ddx(0,150):=(*sq ((((s2_t7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t5x
ddx(0,151):=(*sq ((((s2_2t6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t4x
ddx(0,152):=(*sq ((((s2_3t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4t3x
ddx(0,153):=(*sq ((((s2_4t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_5t2x
ddx(0,154):=(*sq ((((s2_5t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_6tx
ddx(0,155):=(*sq ((((s2_6t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x
ddx(0,156):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t7x
ddx(0,157):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t6x
ddx(0,158):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t5x
ddx(0,159):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t4x
ddx(0,160):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t3x
ddx(0,161):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_t7x
ddx(0,162):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_2t6x
ddx(0,163):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_3t5x
ddx(0,164):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_4t4x
ddx(0,165):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_5t3x
ddx(0,166):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_6t2x
ddx(0,167):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_7tx
ddx(0,168):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_8t
ddx(0,169):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s1_8x
ddx(0,170):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_t7x
ddx(0,171):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_2t6x
ddx(0,172):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_3t5x
ddx(0,173):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_4t4x
ddx(0,174):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_5t3x
ddx(0,175):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_6t2x
ddx(0,176):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_7tx
ddx(0,177):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_8t
ddx(0,178):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. s2_8x
ddx(0,179):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q
ddx(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t
ddx(1,2):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x
ddx(1,3):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t
ddx(1,4):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_tx
ddx(1,5):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x
ddx(1,6):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t
ddx(1,7):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2tx
ddx(1,8):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t2x
ddx(1,9):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x
ddx(1,10):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t
ddx(1,11):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3tx
ddx(1,12):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t2x
ddx(1,13):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t3x
ddx(1,14):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x
ddx(1,15):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t
ddx(1,16):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4tx
ddx(1,17):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t2x
ddx(1,18):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t3x
ddx(1,19):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t4x
ddx(1,20):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x
ddx(1,21):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t
ddx(1,22):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5tx
ddx(1,23):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t2x
ddx(1,24):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t3x
ddx(1,25):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t4x
ddx(1,26):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t5x
ddx(1,27):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x
ddx(1,28):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7t
ddx(1,29):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6tx
ddx(1,30):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t2x
ddx(1,31):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t3x
ddx(1,32):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t4x
ddx(1,33):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t5x
ddx(1,34):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t6x
ddx(1,35):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x
ddx(1,36):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7tx
ddx(1,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t2x
ddx(1,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t3x
ddx(1,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t4x
ddx(1,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t5x
ddx(1,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t6x
ddx(1,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t7x
ddx(1,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x
ddx(1,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8t
ddx(1,45):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
