% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t)
de!*:=((plus (times u u_x) u_3x))
% odd equation
principal_odd!*:=(p_t r1_x r1_t)
de_odd!*((plus p_3x (times p_x u)) (times p u_x) (plus (times p u u_x) (times p
u_3x) (times p_2x u_x) (minus (times p_x u_2x))))
% Settings:
indep_var!*:=(x t)
dep_var!*:=(u)
odd_var!*:=(p r1)
deg_indep_var!*:=(-1 -3)
deg_dep_var!*:=(2)
deg_odd_var!*:=(2 4)
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
all_odd_mind!*:=((p (0 0)) (r1 (0 0)) (p (1 0)) (r1 (1 0)) (p (0 1)) (r1 (0 1))
(p (2 0)) (r1 (2 0)) (p (1 1)) (r1 (1 1)) (p (0 2)) (r1 (0 2)) (p (3 0)) (r1 (3
0)) (p (2 1)) (r1 (2 1)) (p (1 2)) (r1 (1 2)) (p (0 3)) (r1 (0 3)) (p (4 0)) (r1
(4 0)) (p (3 1)) (r1 (3 1)) (p (2 2)) (r1 (2 2)) (p (1 3)) (r1 (1 3)) (p (0 4))
(r1 (0 4)) (p (5 0)) (r1 (5 0)) (p (4 1)) (r1 (4 1)) (p (3 2)) (r1 (3 2)) (p (2
3)) (r1 (2 3)) (p (1 4)) (r1 (1 4)) (p (0 5)) (r1 (0 5)) (p (6 0)) (r1 (6 0)) (p
(5 1)) (r1 (5 1)) (p (4 2)) (r1 (4 2)) (p (3 3)) (r1 (3 3)) (p (2 4)) (r1 (2 4))
(p (1 5)) (r1 (1 5)) (p (0 6)) (r1 (0 6)) (p (7 0)) (r1 (7 0)) (p (6 1)) (r1 (6
1)) (p (5 2)) (r1 (5 2)) (p (4 3)) (r1 (4 3)) (p (3 4)) (r1 (3 4)) (p (2 5)) (r1
(2 5)) (p (1 6)) (r1 (1 6)) (p (0 7)) (r1 (0 7)) (p (8 0)) (r1 (8 0)) (p (7 1))
(r1 (7 1)) (p (6 2)) (r1 (6 2)) (p (5 3)) (r1 (5 3)) (p (4 4)) (r1 (4 4)) (p (3
5)) (r1 (3 5)) (p (2 6)) (r1 (2 6)) (p (1 7)) (r1 (1 7)) (p (0 8)) (r1 (0 8)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_x u_t u_2x u_xt u_2t u_3x u_2xt u_x2t u_3t u_4x u_3xt u_2x2t
u_x3t u_4t u_5x u_4xt u_3x2t u_2x3t u_x4t u_5t u_6x u_5xt u_4x2t u_3x3t u_2x4t
u_x5t u_6t u_7x u_6xt u_5x2t u_4x3t u_3x4t u_2x5t u_x6t u_7t u_8x u_7xt u_6x2t
u_5x3t u_4x4t u_3x5t u_2x6t u_x7t u_8t)
% all odd derivatives in identifier notation:
all_odd_id!*:=(p r1 p_x r1_x p_t r1_t p_2x r1_2x p_xt r1_xt p_2t r1_2t p_3x
r1_3x p_2xt r1_2xt p_x2t r1_x2t p_3t r1_3t p_4x r1_4x p_3xt r1_3xt p_2x2t
r1_2x2t p_x3t r1_x3t p_4t r1_4t p_5x r1_5x p_4xt r1_4xt p_3x2t r1_3x2t p_2x3t
r1_2x3t p_x4t r1_x4t p_5t r1_5t p_6x r1_6x p_5xt r1_5xt p_4x2t r1_4x2t p_3x3t
r1_3x3t p_2x4t r1_2x4t p_x5t r1_x5t p_6t r1_6t p_7x r1_7x p_6xt r1_6xt p_5x2t
r1_5x2t p_4x3t r1_4x3t p_3x4t r1_3x4t p_2x5t r1_2x5t p_x6t r1_x6t p_7t r1_7t
p_8x r1_8x p_7xt r1_7xt p_6x2t r1_6x2t p_5x3t r1_5x3t p_4x4t r1_4x4t p_3x5t
r1_3x5t p_2x6t r1_2x6t p_x7t r1_x7t p_8t r1_8t)
% number of all ext symbols:
n_all_ext:=111
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
i2m_jetspace_odd!*:=((p p (0 0)) (r1 r1 (0 0)) (p_x p (1 0)) (r1_x r1 (1 0)) (
p_t p (0 1)) (r1_t r1 (0 1)) (p_2x p (2 0)) (r1_2x r1 (2 0)) (p_xt p (1 1)) (
r1_xt r1 (1 1)) (p_2t p (0 2)) (r1_2t r1 (0 2)) (p_3x p (3 0)) (r1_3x r1 (3 0))
(p_2xt p (2 1)) (r1_2xt r1 (2 1)) (p_x2t p (1 2)) (r1_x2t r1 (1 2)) (p_3t p (0 3
)) (r1_3t r1 (0 3)) (p_4x p (4 0)) (r1_4x r1 (4 0)) (p_3xt p (3 1)) (r1_3xt r1 (
3 1)) (p_2x2t p (2 2)) (r1_2x2t r1 (2 2)) (p_x3t p (1 3)) (r1_x3t r1 (1 3)) (
p_4t p (0 4)) (r1_4t r1 (0 4)) (p_5x p (5 0)) (r1_5x r1 (5 0)) (p_4xt p (4 1)) (
r1_4xt r1 (4 1)) (p_3x2t p (3 2)) (r1_3x2t r1 (3 2)) (p_2x3t p (2 3)) (r1_2x3t
r1 (2 3)) (p_x4t p (1 4)) (r1_x4t r1 (1 4)) (p_5t p (0 5)) (r1_5t r1 (0 5)) (
p_6x p (6 0)) (r1_6x r1 (6 0)) (p_5xt p (5 1)) (r1_5xt r1 (5 1)) (p_4x2t p (4 2)
) (r1_4x2t r1 (4 2)) (p_3x3t p (3 3)) (r1_3x3t r1 (3 3)) (p_2x4t p (2 4)) (
r1_2x4t r1 (2 4)) (p_x5t p (1 5)) (r1_x5t r1 (1 5)) (p_6t p (0 6)) (r1_6t r1 (0
6)) (p_7x p (7 0)) (r1_7x r1 (7 0)) (p_6xt p (6 1)) (r1_6xt r1 (6 1)) (p_5x2t p
(5 2)) (r1_5x2t r1 (5 2)) (p_4x3t p (4 3)) (r1_4x3t r1 (4 3)) (p_3x4t p (3 4)) (
r1_3x4t r1 (3 4)) (p_2x5t p (2 5)) (r1_2x5t r1 (2 5)) (p_x6t p (1 6)) (r1_x6t r1
(1 6)) (p_7t p (0 7)) (r1_7t r1 (0 7)) (p_8x p (8 0)) (r1_8x r1 (8 0)) (p_7xt p
(7 1)) (r1_7xt r1 (7 1)) (p_6x2t p (6 2)) (r1_6x2t r1 (6 2)) (p_5x3t p (5 3)) (
r1_5x3t r1 (5 3)) (p_4x4t p (4 4)) (r1_4x4t r1 (4 4)) (p_3x5t p (3 5)) (r1_3x5t
r1 (3 5)) (p_2x6t p (2 6)) (r1_2x6t r1 (2 6)) (p_x7t p (1 7)) (r1_x7t r1 (1 7))
(p_8t p (0 8)) (r1_8t r1 (0 8)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (u_x . 1) (u_t . 1) (u_2x . 2) (u_xt . 2) (u_2t . 2) (
u_3x . 3) (u_2xt . 3) (u_x2t . 3) (u_3t . 3) (u_4x . 4) (u_3xt . 4) (u_2x2t . 4)
(u_x3t . 4) (u_4t . 4) (u_5x . 5) (u_4xt . 5) (u_3x2t . 5) (u_2x3t . 5) (u_x4t .
5) (u_5t . 5) (u_6x . 6) (u_5xt . 6) (u_4x2t . 6) (u_3x3t . 6) (u_2x4t . 6) (
u_x5t . 6) (u_6t . 6) (u_7x . 7) (u_6xt . 7) (u_5x2t . 7) (u_4x3t . 7) (u_3x4t .
7) (u_2x5t . 7) (u_x6t . 7) (u_7t . 7) (u_8x . 8) (u_7xt . 8) (u_6x2t . 8) (
u_5x3t . 8) (u_4x4t . 8) (u_3x5t . 8) (u_2x6t . 8) (u_x7t . 8) (u_8t . 8))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((p . 0) (r1 . 0) (p_x . 1) (r1_x . 1) (p_t . 1) (r1_t . 1)
(p_2x . 2) (r1_2x . 2) (p_xt . 2) (r1_xt . 2) (p_2t . 2) (r1_2t . 2) (p_3x . 3)
(r1_3x . 3) (p_2xt . 3) (r1_2xt . 3) (p_x2t . 3) (r1_x2t . 3) (p_3t . 3) (r1_3t
. 3) (p_4x . 4) (r1_4x . 4) (p_3xt . 4) (r1_3xt . 4) (p_2x2t . 4) (r1_2x2t . 4)
(p_x3t . 4) (r1_x3t . 4) (p_4t . 4) (r1_4t . 4) (p_5x . 5) (r1_5x . 5) (p_4xt .
5) (r1_4xt . 5) (p_3x2t . 5) (r1_3x2t . 5) (p_2x3t . 5) (r1_2x3t . 5) (p_x4t . 5
) (r1_x4t . 5) (p_5t . 5) (r1_5t . 5) (p_6x . 6) (r1_6x . 6) (p_5xt . 6) (r1_5xt
. 6) (p_4x2t . 6) (r1_4x2t . 6) (p_3x3t . 6) (r1_3x3t . 6) (p_2x4t . 6) (r1_2x4t
. 6) (p_x5t . 6) (r1_x5t . 6) (p_6t . 6) (r1_6t . 6) (p_7x . 7) (r1_7x . 7) (
p_6xt . 7) (r1_6xt . 7) (p_5x2t . 7) (r1_5x2t . 7) (p_4x3t . 7) (r1_4x3t . 7) (
p_3x4t . 7) (r1_3x4t . 7) (p_2x5t . 7) (r1_2x5t . 7) (p_x6t . 7) (r1_x6t . 7) (
p_7t . 7) (r1_7t . 7) (p_8x . 8) (r1_8x . 8) (p_7xt . 8) (r1_7xt . 8) (p_6x2t .
8) (r1_6x2t . 8) (p_5x3t . 8) (r1_5x3t . 8) (p_4x4t . 8) (r1_4x4t . 8) (p_3x5t .
8) (r1_3x5t . 8) (p_2x6t . 8) (r1_2x6t . 8) (p_x7t . 8) (r1_x7t . 8) (p_8t . 8)
(r1_8t . 8))
% list of even principal derivatives:
all_principal_der!*:=(u_t u_2t u_xt u_3t u_x2t u_2xt u_4t u_x3t u_2x2t u_3xt
u_5t u_x4t u_2x3t u_3x2t u_4xt u_6t u_x5t u_2x4t u_3x3t u_4x2t u_5xt u_7t u_x6t
u_2x5t u_3x4t u_4x3t u_5x2t u_6xt u_8t u_x7t u_2x6t u_3x5t u_4x4t u_5x3t u_6x2t
u_7xt)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_x u_2x u_3x u_4x u_5x u_6x u_7x u_8x)
% list of odd principal derivatives:
all_principal_odd!*:=(p_t r1_t r1_x p_2t p_xt r1_2t r1_xt r1_xt r1_2x p_3t p_x2t
p_2xt r1_3t r1_x2t r1_2xt r1_x2t r1_2xt r1_3x p_4t p_x3t p_2x2t p_3xt r1_4t
r1_x3t r1_2x2t r1_3xt r1_x3t r1_2x2t r1_3xt r1_4x p_5t p_x4t p_2x3t p_3x2t p_4xt
r1_5t r1_x4t r1_2x3t r1_3x2t r1_4xt r1_x4t r1_2x3t r1_3x2t r1_4xt r1_5x p_6t
p_x5t p_2x4t p_3x3t p_4x2t p_5xt r1_6t r1_x5t r1_2x4t r1_3x3t r1_4x2t r1_5xt
r1_x5t r1_2x4t r1_3x3t r1_4x2t r1_5xt r1_6x p_7t p_x6t p_2x5t p_3x4t p_4x3t
p_5x2t p_6xt r1_7t r1_x6t r1_2x5t r1_3x4t r1_4x3t r1_5x2t r1_6xt r1_x6t r1_2x5t
r1_3x4t r1_4x3t r1_5x2t r1_6xt r1_7x p_8t p_x7t p_2x6t p_3x5t p_4x4t p_5x3t
p_6x2t p_7xt r1_8t r1_x7t r1_2x6t r1_3x5t r1_4x4t r1_5x3t r1_6x2t r1_7xt r1_8x)
p_t = (ext 11)
r1_t = (ext 12)
r1_x = (ext 13)
p_2t = (ext 14)
p_xt = (ext 15)
r1_2t = (ext 16)
r1_xt = (ext 17)
r1_xt = (ext 17)
r1_2x = (ext 19)
p_3t = (ext 20)
p_x2t = (ext 21)
p_2xt = (ext 22)
r1_3t = (ext 23)
r1_x2t = (ext 24)
r1_2xt = (ext 25)
r1_x2t = (ext 24)
r1_2xt = (ext 25)
r1_3x = (ext 28)
p_4t = (ext 29)
p_x3t = (ext 30)
p_2x2t = (ext 31)
p_3xt = (ext 32)
r1_4t = (ext 33)
r1_x3t = (ext 34)
r1_2x2t = (ext 35)
r1_3xt = (ext 36)
r1_x3t = (ext 34)
r1_2x2t = (ext 35)
r1_3xt = (ext 36)
r1_4x = (ext 40)
p_5t = (ext 41)
p_x4t = (ext 42)
p_2x3t = (ext 43)
p_3x2t = (ext 44)
p_4xt = (ext 45)
r1_5t = (ext 46)
r1_x4t = (ext 47)
r1_2x3t = (ext 48)
r1_3x2t = (ext 49)
r1_4xt = (ext 50)
r1_x4t = (ext 47)
r1_2x3t = (ext 48)
r1_3x2t = (ext 49)
r1_4xt = (ext 50)
r1_5x = (ext 55)
p_6t = (ext 56)
p_x5t = (ext 57)
p_2x4t = (ext 58)
p_3x3t = (ext 59)
p_4x2t = (ext 60)
p_5xt = (ext 61)
r1_6t = (ext 62)
r1_x5t = (ext 63)
r1_2x4t = (ext 64)
r1_3x3t = (ext 65)
r1_4x2t = (ext 66)
r1_5xt = (ext 67)
r1_x5t = (ext 63)
r1_2x4t = (ext 64)
r1_3x3t = (ext 65)
r1_4x2t = (ext 66)
r1_5xt = (ext 67)
r1_6x = (ext 73)
p_7t = (ext 74)
p_x6t = (ext 75)
p_2x5t = (ext 76)
p_3x4t = (ext 77)
p_4x3t = (ext 78)
p_5x2t = (ext 79)
p_6xt = (ext 80)
r1_7t = (ext 81)
r1_x6t = (ext 82)
r1_2x5t = (ext 83)
r1_3x4t = (ext 84)
r1_4x3t = (ext 85)
r1_5x2t = (ext 86)
r1_6xt = (ext 87)
r1_x6t = (ext 82)
r1_2x5t = (ext 83)
r1_3x4t = (ext 84)
r1_4x3t = (ext 85)
r1_5x2t = (ext 86)
r1_6xt = (ext 87)
r1_7x = (ext 94)
p_8t = (ext 95)
p_x7t = (ext 96)
p_2x6t = (ext 97)
p_3x5t = (ext 98)
p_4x4t = (ext 99)
p_5x3t = (ext 100)
p_6x2t = (ext 101)
p_7xt = (ext 102)
r1_8t = (ext 103)
r1_x7t = (ext 104)
r1_2x6t = (ext 105)
r1_3x5t = (ext 106)
r1_4x4t = (ext 107)
r1_5x3t = (ext 108)
r1_6x2t = (ext 109)
r1_7xt = (ext 110)
r1_8x = (ext 111)
% list of odd parametric derivatives:
all_parametric_odd!*:=(p r1 p_x p_2x p_3x p_4x p_5x p_6x p_7x p_8x)
p = (ext 1)
r1 = (ext 2)
p_x = (ext 3)
p_2x = (ext 4)
p_3x = (ext 5)
p_4x = (ext 6)
p_5x = (ext 7)
p_6x = (ext 8)
p_7x = (ext 9)
p_8x = (ext 10)
% number of ext principal derivatives:
n_all_principal_ext:=101
% number of ext parametric derivatives:
n_all_parametric_ext:=10
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddt)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 u_xt) (ddt 0 5 u_2xt) (ddt 0
6 u_3xt) (ddt 0 7 u_4xt) (ddt 0 8 u_5xt) (ddt 0 9 u_6xt) (ddt 0 10 u_7xt))
primary_diffcon_odd_tot!*:=((ddx 1 2 r1_x) (ddt 1 1 p_t) (ddt 1 2 r1_t) (ddt 1 3
p_xt) (ddt 1 4 p_2xt) (ddt 1 5 p_3xt) (ddt 1 6 p_4xt) (ddt 1 7 p_5xt) (ddt 1 8
p_6xt) (ddt 1 9 p_7xt))
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
letop . 1) . 1)) . 1) nil)) (p_5xt (*sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((
u . 1) . 1)) (((ext 7) . 1) ((u_x . 1) . 5)) (((ext 6) . 1) ((u_2x . 1) . 10)) (
((ext 5) . 1) ((u_3x . 1) . 10)) (((ext 4) . 1) ((u_4x . 1) . 5)) (((ext 3) . 1)
((u_5x . 1) . 1))) . 1) nil)) (p_4xt (*sq (((((ext 9) . 1) . 1) (((ext 7) . 1) (
(u . 1) . 1)) (((ext 6) . 1) ((u_x . 1) . 4)) (((ext 5) . 1) ((u_2x . 1) . 6)) (
((ext 4) . 1) ((u_3x . 1) . 4)) (((ext 3) . 1) ((u_4x . 1) . 1))) . 1) nil)) (
p_3xt (*sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1) ((
u_x . 1) . 3)) (((ext 4) . 1) ((u_2x . 1) . 3)) (((ext 3) . 1) ((u_3x . 1) . 1))
) . 1) nil)) (p_2xt (*sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1)) (((
ext 4) . 1) ((u_x . 1) . 2)) (((ext 3) . 1) ((u_2x . 1) . 1))) . 1) nil)) (p_xt
(*sq (((((ext 6) . 1) . 1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1) ((u_x .
1) . 1))) . 1) nil)) (r1_t (*sq (((((ext 4) . 1) ((u_x . 1) . 1)) (((ext 3) . 1)
((u_2x . 1) . -1)) (((ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) .
1) nil)) (r1_x (*sq (((((ext 1) . 1) ((u_x . 1) . 1))) . 1) nil)) (p_t (*sq ((((
(ext 5) . 1) . 1) (((ext 3) . 1) ((u . 1) . 1))) . 1) nil)))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_7xt u_6xt u_5xt u_4xt u_3xt u_2xt u_xt u_t)
diffcon_comp_odd!*:=(p_7xt p_6xt p_5xt p_4xt p_3xt p_2xt p_xt r1_t r1_x p_t)
diffcon_comp_ext!*:=((ext 102) (ext 80) (ext 61) (ext 45) (ext 32) (ext 22) (ext
15) (ext 12) (ext 13) (ext 11))
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
diffcon_param_ext!*:=(((ext 102) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 80)
*sq ((((letop . 1) . 1)) . 1) nil) ((ext 61) *sq (((((ext 10) . 1) . 1) (((ext 8
) . 1) ((u . 1) . 1)) (((ext 7) . 1) ((u_x . 1) . 5)) (((ext 6) . 1) ((u_2x . 1)
. 10)) (((ext 5) . 1) ((u_3x . 1) . 10)) (((ext 4) . 1) ((u_4x . 1) . 5)) (((ext
3) . 1) ((u_5x . 1) . 1))) . 1) nil) ((ext 45) *sq (((((ext 9) . 1) . 1) (((ext
7) . 1) ((u . 1) . 1)) (((ext 6) . 1) ((u_x . 1) . 4)) (((ext 5) . 1) ((u_2x . 1
) . 6)) (((ext 4) . 1) ((u_3x . 1) . 4)) (((ext 3) . 1) ((u_4x . 1) . 1))) . 1)
nil) ((ext 32) *sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5)
. 1) ((u_x . 1) . 3)) (((ext 4) . 1) ((u_2x . 1) . 3)) (((ext 3) . 1) ((u_3x . 1
) . 1))) . 1) nil) ((ext 22) *sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) .
1)) (((ext 4) . 1) ((u_x . 1) . 2)) (((ext 3) . 1) ((u_2x . 1) . 1))) . 1) nil)
((ext 15) *sq (((((ext 6) . 1) . 1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1)
((u_x . 1) . 1))) . 1) nil) ((ext 12) *sq (((((ext 4) . 1) ((u_x . 1) . 1)) (((
ext 3) . 1) ((u_2x . 1) . -1)) (((ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x .
1) . 1))) . 1) nil) ((ext 13) *sq (((((ext 1) . 1) ((u_x . 1) . 1))) . 1) nil) (
(ext 11) *sq (((((ext 5) . 1) . 1) (((ext 3) . 1) ((u . 1) . 1))) . 1) nil))
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
ddx(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1
ddx(1,2):=(*sq (((((ext 1) . 1) ((u_x . 1) . 1))) . 1) t)
% component of ddx w.r.t. p_x
ddx(1,3):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x
ddx(1,4):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x
ddx(1,5):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x
ddx(1,6):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x
ddx(1,7):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x
ddx(1,8):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x
ddx(1,9):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8x
ddx(1,10):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t
ddx(1,11):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_t
ddx(1,12):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x
ddx(1,13):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t
ddx(1,14):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_xt
ddx(1,15):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2t
ddx(1,16):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_xt
ddx(1,17):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_xt
ddx(1,18):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x
ddx(1,19):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t
ddx(1,20):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x2t
ddx(1,21):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2xt
ddx(1,22):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3t
ddx(1,23):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x2t
ddx(1,24):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2xt
ddx(1,25):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x2t
ddx(1,26):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2xt
ddx(1,27):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x
ddx(1,28):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t
ddx(1,29):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x3t
ddx(1,30):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x2t
ddx(1,31):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3xt
ddx(1,32):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4t
ddx(1,33):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x3t
ddx(1,34):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x2t
ddx(1,35):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3xt
ddx(1,36):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x3t
ddx(1,37):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x2t
ddx(1,38):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3xt
ddx(1,39):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x
ddx(1,40):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t
ddx(1,41):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x4t
ddx(1,42):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x3t
ddx(1,43):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x2t
ddx(1,44):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4xt
ddx(1,45):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5t
ddx(1,46):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x4t
ddx(1,47):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x3t
ddx(1,48):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x2t
ddx(1,49):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4xt
ddx(1,50):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x4t
ddx(1,51):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x3t
ddx(1,52):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x2t
ddx(1,53):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4xt
ddx(1,54):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x
ddx(1,55):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t
ddx(1,56):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x5t
ddx(1,57):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x4t
ddx(1,58):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x3t
ddx(1,59):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x2t
ddx(1,60):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5xt
ddx(1,61):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6t
ddx(1,62):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x5t
ddx(1,63):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x4t
ddx(1,64):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x3t
ddx(1,65):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x2t
ddx(1,66):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5xt
ddx(1,67):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x5t
ddx(1,68):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x4t
ddx(1,69):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x3t
ddx(1,70):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x2t
ddx(1,71):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5xt
ddx(1,72):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6x
ddx(1,73):=(*sq (((((ext 94) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7t
ddx(1,74):=(*sq (((((ext 96) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x6t
ddx(1,75):=(*sq (((((ext 97) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x5t
ddx(1,76):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x4t
ddx(1,77):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x3t
ddx(1,78):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x2t
ddx(1,79):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6xt
ddx(1,80):=(*sq (((((ext 102) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_7t
ddx(1,81):=(*sq (((((ext 104) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x6t
ddx(1,82):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x5t
ddx(1,83):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x4t
ddx(1,84):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x3t
ddx(1,85):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x2t
ddx(1,86):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6xt
ddx(1,87):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x6t
ddx(1,88):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x5t
ddx(1,89):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x4t
ddx(1,90):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x3t
ddx(1,91):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x2t
ddx(1,92):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6xt
ddx(1,93):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_7x
ddx(1,94):=(*sq (((((ext 111) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8t
ddx(1,95):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x7t
ddx(1,96):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x6t
ddx(1,97):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x5t
ddx(1,98):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x4t
ddx(1,99):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x3t
ddx(1,100):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x2t
ddx(1,101):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7xt
ddx(1,102):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_8t
ddx(1,103):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_x7t
ddx(1,104):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_2x6t
ddx(1,105):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_3x5t
ddx(1,106):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_4x4t
ddx(1,107):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_5x3t
ddx(1,108):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_6x2t
ddx(1,109):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_7xt
ddx(1,110):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r1_8x
ddx(1,111):=(*sq ((((letop . 1) . 1)) . 1) t)
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
ddt(1,1):=(*sq (((((ext 5) . 1) . 1) (((ext 3) . 1) ((u . 1) . 1))) . 1) t)
% component of ddt w.r.t. r1
ddt(1,2):=(*sq (((((ext 4) . 1) ((u_x . 1) . 1)) (((ext 3) . 1) ((u_2x . 1) . -1
)) (((ext 1) . 1) ((u . 1) ((u_x . 1) . 1)) ((u_3x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_x
ddt(1,3):=(*sq (((((ext 6) . 1) . 1) (((ext 4) . 1) ((u . 1) . 1)) (((ext 3) . 1
) ((u_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_2x
ddt(1,4):=(*sq (((((ext 7) . 1) . 1) (((ext 5) . 1) ((u . 1) . 1)) (((ext 4) . 1
) ((u_x . 1) . 2)) (((ext 3) . 1) ((u_2x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_3x
ddt(1,5):=(*sq (((((ext 8) . 1) . 1) (((ext 6) . 1) ((u . 1) . 1)) (((ext 5) . 1
) ((u_x . 1) . 3)) (((ext 4) . 1) ((u_2x . 1) . 3)) (((ext 3) . 1) ((u_3x . 1) .
1))) . 1) t)
% component of ddt w.r.t. p_4x
ddt(1,6):=(*sq (((((ext 9) . 1) . 1) (((ext 7) . 1) ((u . 1) . 1)) (((ext 6) . 1
) ((u_x . 1) . 4)) (((ext 5) . 1) ((u_2x . 1) . 6)) (((ext 4) . 1) ((u_3x . 1) .
4)) (((ext 3) . 1) ((u_4x . 1) . 1))) . 1) t)
% component of ddt w.r.t. p_5x
ddt(1,7):=(*sq (((((ext 10) . 1) . 1) (((ext 8) . 1) ((u . 1) . 1)) (((ext 7) .
1) ((u_x . 1) . 5)) (((ext 6) . 1) ((u_2x . 1) . 10)) (((ext 5) . 1) ((u_3x . 1)
. 10)) (((ext 4) . 1) ((u_4x . 1) . 5)) (((ext 3) . 1) ((u_5x . 1) . 1))) . 1) t
)
% component of ddt w.r.t. p_6x
ddt(1,8):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7x
ddt(1,9):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8x
ddt(1,10):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t
ddt(1,11):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_t
ddt(1,12):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x
ddt(1,13):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t
ddt(1,14):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_xt
ddt(1,15):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2t
ddt(1,16):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_xt
ddt(1,17):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_xt
ddt(1,18):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x
ddt(1,19):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t
ddt(1,20):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x2t
ddt(1,21):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2xt
ddt(1,22):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3t
ddt(1,23):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x2t
ddt(1,24):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2xt
ddt(1,25):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x2t
ddt(1,26):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2xt
ddt(1,27):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x
ddt(1,28):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t
ddt(1,29):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x3t
ddt(1,30):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x2t
ddt(1,31):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3xt
ddt(1,32):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4t
ddt(1,33):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x3t
ddt(1,34):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x2t
ddt(1,35):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3xt
ddt(1,36):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x3t
ddt(1,37):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x2t
ddt(1,38):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3xt
ddt(1,39):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x
ddt(1,40):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t
ddt(1,41):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x4t
ddt(1,42):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x3t
ddt(1,43):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x2t
ddt(1,44):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4xt
ddt(1,45):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5t
ddt(1,46):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x4t
ddt(1,47):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x3t
ddt(1,48):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x2t
ddt(1,49):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4xt
ddt(1,50):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x4t
ddt(1,51):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x3t
ddt(1,52):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x2t
ddt(1,53):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4xt
ddt(1,54):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x
ddt(1,55):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t
ddt(1,56):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x5t
ddt(1,57):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x4t
ddt(1,58):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x3t
ddt(1,59):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x2t
ddt(1,60):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5xt
ddt(1,61):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6t
ddt(1,62):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x5t
ddt(1,63):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x4t
ddt(1,64):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x3t
ddt(1,65):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x2t
ddt(1,66):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5xt
ddt(1,67):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x5t
ddt(1,68):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x4t
ddt(1,69):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x3t
ddt(1,70):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x2t
ddt(1,71):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5xt
ddt(1,72):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6x
ddt(1,73):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7t
ddt(1,74):=(*sq (((((ext 95) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x6t
ddt(1,75):=(*sq (((((ext 96) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x5t
ddt(1,76):=(*sq (((((ext 97) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x4t
ddt(1,77):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x3t
ddt(1,78):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x2t
ddt(1,79):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6xt
ddt(1,80):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_7t
ddt(1,81):=(*sq (((((ext 103) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x6t
ddt(1,82):=(*sq (((((ext 104) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x5t
ddt(1,83):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x4t
ddt(1,84):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x3t
ddt(1,85):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x2t
ddt(1,86):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6xt
ddt(1,87):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x6t
ddt(1,88):=(*sq (((((ext 104) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x5t
ddt(1,89):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x4t
ddt(1,90):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x3t
ddt(1,91):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x2t
ddt(1,92):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6xt
ddt(1,93):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_7x
ddt(1,94):=(*sq (((((ext 110) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8t
ddt(1,95):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x7t
ddt(1,96):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x6t
ddt(1,97):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x5t
ddt(1,98):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x4t
ddt(1,99):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x3t
ddt(1,100):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x2t
ddt(1,101):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7xt
ddt(1,102):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_8t
ddt(1,103):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_x7t
ddt(1,104):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_2x6t
ddt(1,105):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_3x5t
ddt(1,106):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_4x4t
ddt(1,107):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_5x3t
ddt(1,108):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_6x2t
ddt(1,109):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_7xt
ddt(1,110):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r1_8x
ddt(1,111):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
