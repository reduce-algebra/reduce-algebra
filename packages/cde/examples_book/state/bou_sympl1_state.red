% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_t v_t w_t)
de!*:=((plus v_x (times w w_x)) (plus (minus (times u w_x)) (minus (times 3 u_x
w))) u_x)
% odd equation
principal_odd!*:=(p_t q_t r_t o1_t o1_x o2_t o2_x o3_t o3_x)
de_odd!*((plus q_x (times r w_x) (times r_x w)) (plus (minus (times p w_x)) (
minus (times 3 p_x w)) (minus (times 3 r u_x)) (minus (times r_x u))) p_x p r (
plus q (times r w)) p (plus (minus (times p w)) (minus (times r u))) (plus q (
times 2 r w)))
% Settings:
indep_var!*:=(x t)
dep_var!*:=(u v w)
odd_var!*:=(p q r o1 o2 o3)
deg_indep_var!*:=(-1 -2)
deg_dep_var!*:=(3 4 2)
deg_odd_var!*:=(2 3 1 1 2 3)
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
all_der_mind!*:=((u (0 0)) (v (0 0)) (w (0 0)) (u (1 0)) (v (1 0)) (w (1 0)) (u
(0 1)) (v (0 1)) (w (0 1)) (u (2 0)) (v (2 0)) (w (2 0)) (u (1 1)) (v (1 1)) (w
(1 1)) (u (0 2)) (v (0 2)) (w (0 2)) (u (3 0)) (v (3 0)) (w (3 0)) (u (2 1)) (v
(2 1)) (w (2 1)) (u (1 2)) (v (1 2)) (w (1 2)) (u (0 3)) (v (0 3)) (w (0 3)) (u
(4 0)) (v (4 0)) (w (4 0)) (u (3 1)) (v (3 1)) (w (3 1)) (u (2 2)) (v (2 2)) (w
(2 2)) (u (1 3)) (v (1 3)) (w (1 3)) (u (0 4)) (v (0 4)) (w (0 4)) (u (5 0)) (v
(5 0)) (w (5 0)) (u (4 1)) (v (4 1)) (w (4 1)) (u (3 2)) (v (3 2)) (w (3 2)) (u
(2 3)) (v (2 3)) (w (2 3)) (u (1 4)) (v (1 4)) (w (1 4)) (u (0 5)) (v (0 5)) (w
(0 5)) (u (6 0)) (v (6 0)) (w (6 0)) (u (5 1)) (v (5 1)) (w (5 1)) (u (4 2)) (v
(4 2)) (w (4 2)) (u (3 3)) (v (3 3)) (w (3 3)) (u (2 4)) (v (2 4)) (w (2 4)) (u
(1 5)) (v (1 5)) (w (1 5)) (u (0 6)) (v (0 6)) (w (0 6)) (u (7 0)) (v (7 0)) (w
(7 0)) (u (6 1)) (v (6 1)) (w (6 1)) (u (5 2)) (v (5 2)) (w (5 2)) (u (4 3)) (v
(4 3)) (w (4 3)) (u (3 4)) (v (3 4)) (w (3 4)) (u (2 5)) (v (2 5)) (w (2 5)) (u
(1 6)) (v (1 6)) (w (1 6)) (u (0 7)) (v (0 7)) (w (0 7)) (u (8 0)) (v (8 0)) (w
(8 0)) (u (7 1)) (v (7 1)) (w (7 1)) (u (6 2)) (v (6 2)) (w (6 2)) (u (5 3)) (v
(5 3)) (w (5 3)) (u (4 4)) (v (4 4)) (w (4 4)) (u (3 5)) (v (3 5)) (w (3 5)) (u
(2 6)) (v (2 6)) (w (2 6)) (u (1 7)) (v (1 7)) (w (1 7)) (u (0 8)) (v (0 8)) (w
(0 8)))
% all odd derivatives in multiindex notation:
all_odd_mind!*:=((p (0 0)) (q (0 0)) (r (0 0)) (o1 (0 0)) (o2 (0 0)) (o3 (0 0))
(p (1 0)) (q (1 0)) (r (1 0)) (o1 (1 0)) (o2 (1 0)) (o3 (1 0)) (p (0 1)) (q (0 1
)) (r (0 1)) (o1 (0 1)) (o2 (0 1)) (o3 (0 1)) (p (2 0)) (q (2 0)) (r (2 0)) (o1
(2 0)) (o2 (2 0)) (o3 (2 0)) (p (1 1)) (q (1 1)) (r (1 1)) (o1 (1 1)) (o2 (1 1))
(o3 (1 1)) (p (0 2)) (q (0 2)) (r (0 2)) (o1 (0 2)) (o2 (0 2)) (o3 (0 2)) (p (3
0)) (q (3 0)) (r (3 0)) (o1 (3 0)) (o2 (3 0)) (o3 (3 0)) (p (2 1)) (q (2 1)) (r
(2 1)) (o1 (2 1)) (o2 (2 1)) (o3 (2 1)) (p (1 2)) (q (1 2)) (r (1 2)) (o1 (1 2))
(o2 (1 2)) (o3 (1 2)) (p (0 3)) (q (0 3)) (r (0 3)) (o1 (0 3)) (o2 (0 3)) (o3 (0
3)) (p (4 0)) (q (4 0)) (r (4 0)) (o1 (4 0)) (o2 (4 0)) (o3 (4 0)) (p (3 1)) (q
(3 1)) (r (3 1)) (o1 (3 1)) (o2 (3 1)) (o3 (3 1)) (p (2 2)) (q (2 2)) (r (2 2))
(o1 (2 2)) (o2 (2 2)) (o3 (2 2)) (p (1 3)) (q (1 3)) (r (1 3)) (o1 (1 3)) (o2 (1
3)) (o3 (1 3)) (p (0 4)) (q (0 4)) (r (0 4)) (o1 (0 4)) (o2 (0 4)) (o3 (0 4)) (p
(5 0)) (q (5 0)) (r (5 0)) (o1 (5 0)) (o2 (5 0)) (o3 (5 0)) (p (4 1)) (q (4 1))
(r (4 1)) (o1 (4 1)) (o2 (4 1)) (o3 (4 1)) (p (3 2)) (q (3 2)) (r (3 2)) (o1 (3
2)) (o2 (3 2)) (o3 (3 2)) (p (2 3)) (q (2 3)) (r (2 3)) (o1 (2 3)) (o2 (2 3)) (
o3 (2 3)) (p (1 4)) (q (1 4)) (r (1 4)) (o1 (1 4)) (o2 (1 4)) (o3 (1 4)) (p (0 5
)) (q (0 5)) (r (0 5)) (o1 (0 5)) (o2 (0 5)) (o3 (0 5)) (p (6 0)) (q (6 0)) (r (
6 0)) (o1 (6 0)) (o2 (6 0)) (o3 (6 0)) (p (5 1)) (q (5 1)) (r (5 1)) (o1 (5 1))
(o2 (5 1)) (o3 (5 1)) (p (4 2)) (q (4 2)) (r (4 2)) (o1 (4 2)) (o2 (4 2)) (o3 (4
2)) (p (3 3)) (q (3 3)) (r (3 3)) (o1 (3 3)) (o2 (3 3)) (o3 (3 3)) (p (2 4)) (q
(2 4)) (r (2 4)) (o1 (2 4)) (o2 (2 4)) (o3 (2 4)) (p (1 5)) (q (1 5)) (r (1 5))
(o1 (1 5)) (o2 (1 5)) (o3 (1 5)) (p (0 6)) (q (0 6)) (r (0 6)) (o1 (0 6)) (o2 (0
6)) (o3 (0 6)) (p (7 0)) (q (7 0)) (r (7 0)) (o1 (7 0)) (o2 (7 0)) (o3 (7 0)) (p
(6 1)) (q (6 1)) (r (6 1)) (o1 (6 1)) (o2 (6 1)) (o3 (6 1)) (p (5 2)) (q (5 2))
(r (5 2)) (o1 (5 2)) (o2 (5 2)) (o3 (5 2)) (p (4 3)) (q (4 3)) (r (4 3)) (o1 (4
3)) (o2 (4 3)) (o3 (4 3)) (p (3 4)) (q (3 4)) (r (3 4)) (o1 (3 4)) (o2 (3 4)) (
o3 (3 4)) (p (2 5)) (q (2 5)) (r (2 5)) (o1 (2 5)) (o2 (2 5)) (o3 (2 5)) (p (1 6
)) (q (1 6)) (r (1 6)) (o1 (1 6)) (o2 (1 6)) (o3 (1 6)) (p (0 7)) (q (0 7)) (r (
0 7)) (o1 (0 7)) (o2 (0 7)) (o3 (0 7)) (p (8 0)) (q (8 0)) (r (8 0)) (o1 (8 0))
(o2 (8 0)) (o3 (8 0)) (p (7 1)) (q (7 1)) (r (7 1)) (o1 (7 1)) (o2 (7 1)) (o3 (7
1)) (p (6 2)) (q (6 2)) (r (6 2)) (o1 (6 2)) (o2 (6 2)) (o3 (6 2)) (p (5 3)) (q
(5 3)) (r (5 3)) (o1 (5 3)) (o2 (5 3)) (o3 (5 3)) (p (4 4)) (q (4 4)) (r (4 4))
(o1 (4 4)) (o2 (4 4)) (o3 (4 4)) (p (3 5)) (q (3 5)) (r (3 5)) (o1 (3 5)) (o2 (3
5)) (o3 (3 5)) (p (2 6)) (q (2 6)) (r (2 6)) (o1 (2 6)) (o2 (2 6)) (o3 (2 6)) (p
(1 7)) (q (1 7)) (r (1 7)) (o1 (1 7)) (o2 (1 7)) (o3 (1 7)) (p (0 8)) (q (0 8))
(r (0 8)) (o1 (0 8)) (o2 (0 8)) (o3 (0 8)))
% all even derivatives in identifier notation:
all_der_id!*:=(u v w u_x v_x w_x u_t v_t w_t u_2x v_2x w_2x u_xt v_xt w_xt u_2t
v_2t w_2t u_3x v_3x w_3x u_2xt v_2xt w_2xt u_x2t v_x2t w_x2t u_3t v_3t w_3t u_4x
v_4x w_4x u_3xt v_3xt w_3xt u_2x2t v_2x2t w_2x2t u_x3t v_x3t w_x3t u_4t v_4t
w_4t u_5x v_5x w_5x u_4xt v_4xt w_4xt u_3x2t v_3x2t w_3x2t u_2x3t v_2x3t w_2x3t
u_x4t v_x4t w_x4t u_5t v_5t w_5t u_6x v_6x w_6x u_5xt v_5xt w_5xt u_4x2t v_4x2t
w_4x2t u_3x3t v_3x3t w_3x3t u_2x4t v_2x4t w_2x4t u_x5t v_x5t w_x5t u_6t v_6t
w_6t u_7x v_7x w_7x u_6xt v_6xt w_6xt u_5x2t v_5x2t w_5x2t u_4x3t v_4x3t w_4x3t
u_3x4t v_3x4t w_3x4t u_2x5t v_2x5t w_2x5t u_x6t v_x6t w_x6t u_7t v_7t w_7t u_8x
v_8x w_8x u_7xt v_7xt w_7xt u_6x2t v_6x2t w_6x2t u_5x3t v_5x3t w_5x3t u_4x4t
v_4x4t w_4x4t u_3x5t v_3x5t w_3x5t u_2x6t v_2x6t w_2x6t u_x7t v_x7t w_x7t u_8t
v_8t w_8t)
% all odd derivatives in identifier notation:
all_odd_id!*:=(p q r o1 o2 o3 p_x q_x r_x o1_x o2_x o3_x p_t q_t r_t o1_t o2_t
o3_t p_2x q_2x r_2x o1_2x o2_2x o3_2x p_xt q_xt r_xt o1_xt o2_xt o3_xt p_2t q_2t
r_2t o1_2t o2_2t o3_2t p_3x q_3x r_3x o1_3x o2_3x o3_3x p_2xt q_2xt r_2xt o1_2xt
o2_2xt o3_2xt p_x2t q_x2t r_x2t o1_x2t o2_x2t o3_x2t p_3t q_3t r_3t o1_3t o2_3t
o3_3t p_4x q_4x r_4x o1_4x o2_4x o3_4x p_3xt q_3xt r_3xt o1_3xt o2_3xt o3_3xt
p_2x2t q_2x2t r_2x2t o1_2x2t o2_2x2t o3_2x2t p_x3t q_x3t r_x3t o1_x3t o2_x3t
o3_x3t p_4t q_4t r_4t o1_4t o2_4t o3_4t p_5x q_5x r_5x o1_5x o2_5x o3_5x p_4xt
q_4xt r_4xt o1_4xt o2_4xt o3_4xt p_3x2t q_3x2t r_3x2t o1_3x2t o2_3x2t o3_3x2t
p_2x3t q_2x3t r_2x3t o1_2x3t o2_2x3t o3_2x3t p_x4t q_x4t r_x4t o1_x4t o2_x4t
o3_x4t p_5t q_5t r_5t o1_5t o2_5t o3_5t p_6x q_6x r_6x o1_6x o2_6x o3_6x p_5xt
q_5xt r_5xt o1_5xt o2_5xt o3_5xt p_4x2t q_4x2t r_4x2t o1_4x2t o2_4x2t o3_4x2t
p_3x3t q_3x3t r_3x3t o1_3x3t o2_3x3t o3_3x3t p_2x4t q_2x4t r_2x4t o1_2x4t
o2_2x4t o3_2x4t p_x5t q_x5t r_x5t o1_x5t o2_x5t o3_x5t p_6t q_6t r_6t o1_6t
o2_6t o3_6t p_7x q_7x r_7x o1_7x o2_7x o3_7x p_6xt q_6xt r_6xt o1_6xt o2_6xt
o3_6xt p_5x2t q_5x2t r_5x2t o1_5x2t o2_5x2t o3_5x2t p_4x3t q_4x3t r_4x3t o1_4x3t
o2_4x3t o3_4x3t p_3x4t q_3x4t r_3x4t o1_3x4t o2_3x4t o3_3x4t p_2x5t q_2x5t
r_2x5t o1_2x5t o2_2x5t o3_2x5t p_x6t q_x6t r_x6t o1_x6t o2_x6t o3_x6t p_7t q_7t
r_7t o1_7t o2_7t o3_7t p_8x q_8x r_8x o1_8x o2_8x o3_8x p_7xt q_7xt r_7xt o1_7xt
o2_7xt o3_7xt p_6x2t q_6x2t r_6x2t o1_6x2t o2_6x2t o3_6x2t p_5x3t q_5x3t r_5x3t
o1_5x3t o2_5x3t o3_5x3t p_4x4t q_4x4t r_4x4t o1_4x4t o2_4x4t o3_4x4t p_3x5t
q_3x5t r_3x5t o1_3x5t o2_3x5t o3_3x5t p_2x6t q_2x6t r_2x6t o1_2x6t o2_2x6t
o3_2x6t p_x7t q_x7t r_x7t o1_x7t o2_x7t o3_x7t p_8t q_8t r_8t o1_8t o2_8t o3_8t)
% number of all ext symbols:
n_all_ext:=333
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0)) (v v (0 0)) (w w (0 0)) (u_x u (1 0)) (v_x v (1 0))
(w_x w (1 0)) (u_t u (0 1)) (v_t v (0 1)) (w_t w (0 1)) (u_2x u (2 0)) (v_2x v (
2 0)) (w_2x w (2 0)) (u_xt u (1 1)) (v_xt v (1 1)) (w_xt w (1 1)) (u_2t u (0 2))
(v_2t v (0 2)) (w_2t w (0 2)) (u_3x u (3 0)) (v_3x v (3 0)) (w_3x w (3 0)) (
u_2xt u (2 1)) (v_2xt v (2 1)) (w_2xt w (2 1)) (u_x2t u (1 2)) (v_x2t v (1 2)) (
w_x2t w (1 2)) (u_3t u (0 3)) (v_3t v (0 3)) (w_3t w (0 3)) (u_4x u (4 0)) (v_4x
v (4 0)) (w_4x w (4 0)) (u_3xt u (3 1)) (v_3xt v (3 1)) (w_3xt w (3 1)) (u_2x2t
u (2 2)) (v_2x2t v (2 2)) (w_2x2t w (2 2)) (u_x3t u (1 3)) (v_x3t v (1 3)) (
w_x3t w (1 3)) (u_4t u (0 4)) (v_4t v (0 4)) (w_4t w (0 4)) (u_5x u (5 0)) (v_5x
v (5 0)) (w_5x w (5 0)) (u_4xt u (4 1)) (v_4xt v (4 1)) (w_4xt w (4 1)) (u_3x2t
u (3 2)) (v_3x2t v (3 2)) (w_3x2t w (3 2)) (u_2x3t u (2 3)) (v_2x3t v (2 3)) (
w_2x3t w (2 3)) (u_x4t u (1 4)) (v_x4t v (1 4)) (w_x4t w (1 4)) (u_5t u (0 5)) (
v_5t v (0 5)) (w_5t w (0 5)) (u_6x u (6 0)) (v_6x v (6 0)) (w_6x w (6 0)) (u_5xt
u (5 1)) (v_5xt v (5 1)) (w_5xt w (5 1)) (u_4x2t u (4 2)) (v_4x2t v (4 2)) (
w_4x2t w (4 2)) (u_3x3t u (3 3)) (v_3x3t v (3 3)) (w_3x3t w (3 3)) (u_2x4t u (2
4)) (v_2x4t v (2 4)) (w_2x4t w (2 4)) (u_x5t u (1 5)) (v_x5t v (1 5)) (w_x5t w (
1 5)) (u_6t u (0 6)) (v_6t v (0 6)) (w_6t w (0 6)) (u_7x u (7 0)) (v_7x v (7 0))
(w_7x w (7 0)) (u_6xt u (6 1)) (v_6xt v (6 1)) (w_6xt w (6 1)) (u_5x2t u (5 2))
(v_5x2t v (5 2)) (w_5x2t w (5 2)) (u_4x3t u (4 3)) (v_4x3t v (4 3)) (w_4x3t w (4
3)) (u_3x4t u (3 4)) (v_3x4t v (3 4)) (w_3x4t w (3 4)) (u_2x5t u (2 5)) (v_2x5t
v (2 5)) (w_2x5t w (2 5)) (u_x6t u (1 6)) (v_x6t v (1 6)) (w_x6t w (1 6)) (u_7t
u (0 7)) (v_7t v (0 7)) (w_7t w (0 7)) (u_8x u (8 0)) (v_8x v (8 0)) (w_8x w (8
0)) (u_7xt u (7 1)) (v_7xt v (7 1)) (w_7xt w (7 1)) (u_6x2t u (6 2)) (v_6x2t v (
6 2)) (w_6x2t w (6 2)) (u_5x3t u (5 3)) (v_5x3t v (5 3)) (w_5x3t w (5 3)) (
u_4x4t u (4 4)) (v_4x4t v (4 4)) (w_4x4t w (4 4)) (u_3x5t u (3 5)) (v_3x5t v (3
5)) (w_3x5t w (3 5)) (u_2x6t u (2 6)) (v_2x6t v (2 6)) (w_2x6t w (2 6)) (u_x7t u
(1 7)) (v_x7t v (1 7)) (w_x7t w (1 7)) (u_8t u (0 8)) (v_8t v (0 8)) (w_8t w (0
8)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((p p (0 0)) (q q (0 0)) (r r (0 0)) (o1 o1 (0 0)) (o2 o2 (0
0)) (o3 o3 (0 0)) (p_x p (1 0)) (q_x q (1 0)) (r_x r (1 0)) (o1_x o1 (1 0)) (
o2_x o2 (1 0)) (o3_x o3 (1 0)) (p_t p (0 1)) (q_t q (0 1)) (r_t r (0 1)) (o1_t
o1 (0 1)) (o2_t o2 (0 1)) (o3_t o3 (0 1)) (p_2x p (2 0)) (q_2x q (2 0)) (r_2x r
(2 0)) (o1_2x o1 (2 0)) (o2_2x o2 (2 0)) (o3_2x o3 (2 0)) (p_xt p (1 1)) (q_xt q
(1 1)) (r_xt r (1 1)) (o1_xt o1 (1 1)) (o2_xt o2 (1 1)) (o3_xt o3 (1 1)) (p_2t p
(0 2)) (q_2t q (0 2)) (r_2t r (0 2)) (o1_2t o1 (0 2)) (o2_2t o2 (0 2)) (o3_2t o3
(0 2)) (p_3x p (3 0)) (q_3x q (3 0)) (r_3x r (3 0)) (o1_3x o1 (3 0)) (o2_3x o2 (
3 0)) (o3_3x o3 (3 0)) (p_2xt p (2 1)) (q_2xt q (2 1)) (r_2xt r (2 1)) (o1_2xt
o1 (2 1)) (o2_2xt o2 (2 1)) (o3_2xt o3 (2 1)) (p_x2t p (1 2)) (q_x2t q (1 2)) (
r_x2t r (1 2)) (o1_x2t o1 (1 2)) (o2_x2t o2 (1 2)) (o3_x2t o3 (1 2)) (p_3t p (0
3)) (q_3t q (0 3)) (r_3t r (0 3)) (o1_3t o1 (0 3)) (o2_3t o2 (0 3)) (o3_3t o3 (0
3)) (p_4x p (4 0)) (q_4x q (4 0)) (r_4x r (4 0)) (o1_4x o1 (4 0)) (o2_4x o2 (4 0
)) (o3_4x o3 (4 0)) (p_3xt p (3 1)) (q_3xt q (3 1)) (r_3xt r (3 1)) (o1_3xt o1 (
3 1)) (o2_3xt o2 (3 1)) (o3_3xt o3 (3 1)) (p_2x2t p (2 2)) (q_2x2t q (2 2)) (
r_2x2t r (2 2)) (o1_2x2t o1 (2 2)) (o2_2x2t o2 (2 2)) (o3_2x2t o3 (2 2)) (p_x3t
p (1 3)) (q_x3t q (1 3)) (r_x3t r (1 3)) (o1_x3t o1 (1 3)) (o2_x3t o2 (1 3)) (
o3_x3t o3 (1 3)) (p_4t p (0 4)) (q_4t q (0 4)) (r_4t r (0 4)) (o1_4t o1 (0 4)) (
o2_4t o2 (0 4)) (o3_4t o3 (0 4)) (p_5x p (5 0)) (q_5x q (5 0)) (r_5x r (5 0)) (
o1_5x o1 (5 0)) (o2_5x o2 (5 0)) (o3_5x o3 (5 0)) (p_4xt p (4 1)) (q_4xt q (4 1)
) (r_4xt r (4 1)) (o1_4xt o1 (4 1)) (o2_4xt o2 (4 1)) (o3_4xt o3 (4 1)) (p_3x2t
p (3 2)) (q_3x2t q (3 2)) (r_3x2t r (3 2)) (o1_3x2t o1 (3 2)) (o2_3x2t o2 (3 2))
(o3_3x2t o3 (3 2)) (p_2x3t p (2 3)) (q_2x3t q (2 3)) (r_2x3t r (2 3)) (o1_2x3t
o1 (2 3)) (o2_2x3t o2 (2 3)) (o3_2x3t o3 (2 3)) (p_x4t p (1 4)) (q_x4t q (1 4))
(r_x4t r (1 4)) (o1_x4t o1 (1 4)) (o2_x4t o2 (1 4)) (o3_x4t o3 (1 4)) (p_5t p (0
5)) (q_5t q (0 5)) (r_5t r (0 5)) (o1_5t o1 (0 5)) (o2_5t o2 (0 5)) (o3_5t o3 (0
5)) (p_6x p (6 0)) (q_6x q (6 0)) (r_6x r (6 0)) (o1_6x o1 (6 0)) (o2_6x o2 (6 0
)) (o3_6x o3 (6 0)) (p_5xt p (5 1)) (q_5xt q (5 1)) (r_5xt r (5 1)) (o1_5xt o1 (
5 1)) (o2_5xt o2 (5 1)) (o3_5xt o3 (5 1)) (p_4x2t p (4 2)) (q_4x2t q (4 2)) (
r_4x2t r (4 2)) (o1_4x2t o1 (4 2)) (o2_4x2t o2 (4 2)) (o3_4x2t o3 (4 2)) (p_3x3t
p (3 3)) (q_3x3t q (3 3)) (r_3x3t r (3 3)) (o1_3x3t o1 (3 3)) (o2_3x3t o2 (3 3))
(o3_3x3t o3 (3 3)) (p_2x4t p (2 4)) (q_2x4t q (2 4)) (r_2x4t r (2 4)) (o1_2x4t
o1 (2 4)) (o2_2x4t o2 (2 4)) (o3_2x4t o3 (2 4)) (p_x5t p (1 5)) (q_x5t q (1 5))
(r_x5t r (1 5)) (o1_x5t o1 (1 5)) (o2_x5t o2 (1 5)) (o3_x5t o3 (1 5)) (p_6t p (0
6)) (q_6t q (0 6)) (r_6t r (0 6)) (o1_6t o1 (0 6)) (o2_6t o2 (0 6)) (o3_6t o3 (0
6)) (p_7x p (7 0)) (q_7x q (7 0)) (r_7x r (7 0)) (o1_7x o1 (7 0)) (o2_7x o2 (7 0
)) (o3_7x o3 (7 0)) (p_6xt p (6 1)) (q_6xt q (6 1)) (r_6xt r (6 1)) (o1_6xt o1 (
6 1)) (o2_6xt o2 (6 1)) (o3_6xt o3 (6 1)) (p_5x2t p (5 2)) (q_5x2t q (5 2)) (
r_5x2t r (5 2)) (o1_5x2t o1 (5 2)) (o2_5x2t o2 (5 2)) (o3_5x2t o3 (5 2)) (p_4x3t
p (4 3)) (q_4x3t q (4 3)) (r_4x3t r (4 3)) (o1_4x3t o1 (4 3)) (o2_4x3t o2 (4 3))
(o3_4x3t o3 (4 3)) (p_3x4t p (3 4)) (q_3x4t q (3 4)) (r_3x4t r (3 4)) (o1_3x4t
o1 (3 4)) (o2_3x4t o2 (3 4)) (o3_3x4t o3 (3 4)) (p_2x5t p (2 5)) (q_2x5t q (2 5)
) (r_2x5t r (2 5)) (o1_2x5t o1 (2 5)) (o2_2x5t o2 (2 5)) (o3_2x5t o3 (2 5)) (
p_x6t p (1 6)) (q_x6t q (1 6)) (r_x6t r (1 6)) (o1_x6t o1 (1 6)) (o2_x6t o2 (1 6
)) (o3_x6t o3 (1 6)) (p_7t p (0 7)) (q_7t q (0 7)) (r_7t r (0 7)) (o1_7t o1 (0 7
)) (o2_7t o2 (0 7)) (o3_7t o3 (0 7)) (p_8x p (8 0)) (q_8x q (8 0)) (r_8x r (8 0)
) (o1_8x o1 (8 0)) (o2_8x o2 (8 0)) (o3_8x o3 (8 0)) (p_7xt p (7 1)) (q_7xt q (7
1)) (r_7xt r (7 1)) (o1_7xt o1 (7 1)) (o2_7xt o2 (7 1)) (o3_7xt o3 (7 1)) (
p_6x2t p (6 2)) (q_6x2t q (6 2)) (r_6x2t r (6 2)) (o1_6x2t o1 (6 2)) (o2_6x2t o2
(6 2)) (o3_6x2t o3 (6 2)) (p_5x3t p (5 3)) (q_5x3t q (5 3)) (r_5x3t r (5 3)) (
o1_5x3t o1 (5 3)) (o2_5x3t o2 (5 3)) (o3_5x3t o3 (5 3)) (p_4x4t p (4 4)) (q_4x4t
q (4 4)) (r_4x4t r (4 4)) (o1_4x4t o1 (4 4)) (o2_4x4t o2 (4 4)) (o3_4x4t o3 (4 4
)) (p_3x5t p (3 5)) (q_3x5t q (3 5)) (r_3x5t r (3 5)) (o1_3x5t o1 (3 5)) (
o2_3x5t o2 (3 5)) (o3_3x5t o3 (3 5)) (p_2x6t p (2 6)) (q_2x6t q (2 6)) (r_2x6t r
(2 6)) (o1_2x6t o1 (2 6)) (o2_2x6t o2 (2 6)) (o3_2x6t o3 (2 6)) (p_x7t p (1 7))
(q_x7t q (1 7)) (r_x7t r (1 7)) (o1_x7t o1 (1 7)) (o2_x7t o2 (1 7)) (o3_x7t o3 (
1 7)) (p_8t p (0 8)) (q_8t q (0 8)) (r_8t r (0 8)) (o1_8t o1 (0 8)) (o2_8t o2 (0
8)) (o3_8t o3 (0 8)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (v . 0) (w . 0) (u_x . 1) (v_x . 1) (w_x . 1) (u_t . 1)
(v_t . 1) (w_t . 1) (u_2x . 2) (v_2x . 2) (w_2x . 2) (u_xt . 2) (v_xt . 2) (w_xt
. 2) (u_2t . 2) (v_2t . 2) (w_2t . 2) (u_3x . 3) (v_3x . 3) (w_3x . 3) (u_2xt .
3) (v_2xt . 3) (w_2xt . 3) (u_x2t . 3) (v_x2t . 3) (w_x2t . 3) (u_3t . 3) (v_3t
. 3) (w_3t . 3) (u_4x . 4) (v_4x . 4) (w_4x . 4) (u_3xt . 4) (v_3xt . 4) (w_3xt
. 4) (u_2x2t . 4) (v_2x2t . 4) (w_2x2t . 4) (u_x3t . 4) (v_x3t . 4) (w_x3t . 4)
(u_4t . 4) (v_4t . 4) (w_4t . 4) (u_5x . 5) (v_5x . 5) (w_5x . 5) (u_4xt . 5) (
v_4xt . 5) (w_4xt . 5) (u_3x2t . 5) (v_3x2t . 5) (w_3x2t . 5) (u_2x3t . 5) (
v_2x3t . 5) (w_2x3t . 5) (u_x4t . 5) (v_x4t . 5) (w_x4t . 5) (u_5t . 5) (v_5t .
5) (w_5t . 5) (u_6x . 6) (v_6x . 6) (w_6x . 6) (u_5xt . 6) (v_5xt . 6) (w_5xt .
6) (u_4x2t . 6) (v_4x2t . 6) (w_4x2t . 6) (u_3x3t . 6) (v_3x3t . 6) (w_3x3t . 6)
(u_2x4t . 6) (v_2x4t . 6) (w_2x4t . 6) (u_x5t . 6) (v_x5t . 6) (w_x5t . 6) (u_6t
. 6) (v_6t . 6) (w_6t . 6) (u_7x . 7) (v_7x . 7) (w_7x . 7) (u_6xt . 7) (v_6xt .
7) (w_6xt . 7) (u_5x2t . 7) (v_5x2t . 7) (w_5x2t . 7) (u_4x3t . 7) (v_4x3t . 7)
(w_4x3t . 7) (u_3x4t . 7) (v_3x4t . 7) (w_3x4t . 7) (u_2x5t . 7) (v_2x5t . 7) (
w_2x5t . 7) (u_x6t . 7) (v_x6t . 7) (w_x6t . 7) (u_7t . 7) (v_7t . 7) (w_7t . 7)
(u_8x . 8) (v_8x . 8) (w_8x . 8) (u_7xt . 8) (v_7xt . 8) (w_7xt . 8) (u_6x2t . 8
) (v_6x2t . 8) (w_6x2t . 8) (u_5x3t . 8) (v_5x3t . 8) (w_5x3t . 8) (u_4x4t . 8)
(v_4x4t . 8) (w_4x4t . 8) (u_3x5t . 8) (v_3x5t . 8) (w_3x5t . 8) (u_2x6t . 8) (
v_2x6t . 8) (w_2x6t . 8) (u_x7t . 8) (v_x7t . 8) (w_x7t . 8) (u_8t . 8) (v_8t .
8) (w_8t . 8))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((p . 0) (q . 0) (r . 0) (o1 . 0) (o2 . 0) (o3 . 0) (p_x . 1
) (q_x . 1) (r_x . 1) (o1_x . 1) (o2_x . 1) (o3_x . 1) (p_t . 1) (q_t . 1) (r_t
. 1) (o1_t . 1) (o2_t . 1) (o3_t . 1) (p_2x . 2) (q_2x . 2) (r_2x . 2) (o1_2x .
2) (o2_2x . 2) (o3_2x . 2) (p_xt . 2) (q_xt . 2) (r_xt . 2) (o1_xt . 2) (o2_xt .
2) (o3_xt . 2) (p_2t . 2) (q_2t . 2) (r_2t . 2) (o1_2t . 2) (o2_2t . 2) (o3_2t .
2) (p_3x . 3) (q_3x . 3) (r_3x . 3) (o1_3x . 3) (o2_3x . 3) (o3_3x . 3) (p_2xt .
3) (q_2xt . 3) (r_2xt . 3) (o1_2xt . 3) (o2_2xt . 3) (o3_2xt . 3) (p_x2t . 3) (
q_x2t . 3) (r_x2t . 3) (o1_x2t . 3) (o2_x2t . 3) (o3_x2t . 3) (p_3t . 3) (q_3t .
3) (r_3t . 3) (o1_3t . 3) (o2_3t . 3) (o3_3t . 3) (p_4x . 4) (q_4x . 4) (r_4x .
4) (o1_4x . 4) (o2_4x . 4) (o3_4x . 4) (p_3xt . 4) (q_3xt . 4) (r_3xt . 4) (
o1_3xt . 4) (o2_3xt . 4) (o3_3xt . 4) (p_2x2t . 4) (q_2x2t . 4) (r_2x2t . 4) (
o1_2x2t . 4) (o2_2x2t . 4) (o3_2x2t . 4) (p_x3t . 4) (q_x3t . 4) (r_x3t . 4) (
o1_x3t . 4) (o2_x3t . 4) (o3_x3t . 4) (p_4t . 4) (q_4t . 4) (r_4t . 4) (o1_4t .
4) (o2_4t . 4) (o3_4t . 4) (p_5x . 5) (q_5x . 5) (r_5x . 5) (o1_5x . 5) (o2_5x .
5) (o3_5x . 5) (p_4xt . 5) (q_4xt . 5) (r_4xt . 5) (o1_4xt . 5) (o2_4xt . 5) (
o3_4xt . 5) (p_3x2t . 5) (q_3x2t . 5) (r_3x2t . 5) (o1_3x2t . 5) (o2_3x2t . 5) (
o3_3x2t . 5) (p_2x3t . 5) (q_2x3t . 5) (r_2x3t . 5) (o1_2x3t . 5) (o2_2x3t . 5)
(o3_2x3t . 5) (p_x4t . 5) (q_x4t . 5) (r_x4t . 5) (o1_x4t . 5) (o2_x4t . 5) (
o3_x4t . 5) (p_5t . 5) (q_5t . 5) (r_5t . 5) (o1_5t . 5) (o2_5t . 5) (o3_5t . 5)
(p_6x . 6) (q_6x . 6) (r_6x . 6) (o1_6x . 6) (o2_6x . 6) (o3_6x . 6) (p_5xt . 6)
(q_5xt . 6) (r_5xt . 6) (o1_5xt . 6) (o2_5xt . 6) (o3_5xt . 6) (p_4x2t . 6) (
q_4x2t . 6) (r_4x2t . 6) (o1_4x2t . 6) (o2_4x2t . 6) (o3_4x2t . 6) (p_3x3t . 6)
(q_3x3t . 6) (r_3x3t . 6) (o1_3x3t . 6) (o2_3x3t . 6) (o3_3x3t . 6) (p_2x4t . 6)
(q_2x4t . 6) (r_2x4t . 6) (o1_2x4t . 6) (o2_2x4t . 6) (o3_2x4t . 6) (p_x5t . 6)
(q_x5t . 6) (r_x5t . 6) (o1_x5t . 6) (o2_x5t . 6) (o3_x5t . 6) (p_6t . 6) (q_6t
. 6) (r_6t . 6) (o1_6t . 6) (o2_6t . 6) (o3_6t . 6) (p_7x . 7) (q_7x . 7) (r_7x
. 7) (o1_7x . 7) (o2_7x . 7) (o3_7x . 7) (p_6xt . 7) (q_6xt . 7) (r_6xt . 7) (
o1_6xt . 7) (o2_6xt . 7) (o3_6xt . 7) (p_5x2t . 7) (q_5x2t . 7) (r_5x2t . 7) (
o1_5x2t . 7) (o2_5x2t . 7) (o3_5x2t . 7) (p_4x3t . 7) (q_4x3t . 7) (r_4x3t . 7)
(o1_4x3t . 7) (o2_4x3t . 7) (o3_4x3t . 7) (p_3x4t . 7) (q_3x4t . 7) (r_3x4t . 7)
(o1_3x4t . 7) (o2_3x4t . 7) (o3_3x4t . 7) (p_2x5t . 7) (q_2x5t . 7) (r_2x5t . 7)
(o1_2x5t . 7) (o2_2x5t . 7) (o3_2x5t . 7) (p_x6t . 7) (q_x6t . 7) (r_x6t . 7) (
o1_x6t . 7) (o2_x6t . 7) (o3_x6t . 7) (p_7t . 7) (q_7t . 7) (r_7t . 7) (o1_7t .
7) (o2_7t . 7) (o3_7t . 7) (p_8x . 8) (q_8x . 8) (r_8x . 8) (o1_8x . 8) (o2_8x .
8) (o3_8x . 8) (p_7xt . 8) (q_7xt . 8) (r_7xt . 8) (o1_7xt . 8) (o2_7xt . 8) (
o3_7xt . 8) (p_6x2t . 8) (q_6x2t . 8) (r_6x2t . 8) (o1_6x2t . 8) (o2_6x2t . 8) (
o3_6x2t . 8) (p_5x3t . 8) (q_5x3t . 8) (r_5x3t . 8) (o1_5x3t . 8) (o2_5x3t . 8)
(o3_5x3t . 8) (p_4x4t . 8) (q_4x4t . 8) (r_4x4t . 8) (o1_4x4t . 8) (o2_4x4t . 8)
(o3_4x4t . 8) (p_3x5t . 8) (q_3x5t . 8) (r_3x5t . 8) (o1_3x5t . 8) (o2_3x5t . 8)
(o3_3x5t . 8) (p_2x6t . 8) (q_2x6t . 8) (r_2x6t . 8) (o1_2x6t . 8) (o2_2x6t . 8)
(o3_2x6t . 8) (p_x7t . 8) (q_x7t . 8) (r_x7t . 8) (o1_x7t . 8) (o2_x7t . 8) (
o3_x7t . 8) (p_8t . 8) (q_8t . 8) (r_8t . 8) (o1_8t . 8) (o2_8t . 8) (o3_8t . 8)
)
% list of even principal derivatives:
all_principal_der!*:=(u_t v_t w_t u_2t u_xt v_2t v_xt w_2t w_xt u_3t u_x2t u_2xt
v_3t v_x2t v_2xt w_3t w_x2t w_2xt u_4t u_x3t u_2x2t u_3xt v_4t v_x3t v_2x2t
v_3xt w_4t w_x3t w_2x2t w_3xt u_5t u_x4t u_2x3t u_3x2t u_4xt v_5t v_x4t v_2x3t
v_3x2t v_4xt w_5t w_x4t w_2x3t w_3x2t w_4xt u_6t u_x5t u_2x4t u_3x3t u_4x2t
u_5xt v_6t v_x5t v_2x4t v_3x3t v_4x2t v_5xt w_6t w_x5t w_2x4t w_3x3t w_4x2t
w_5xt u_7t u_x6t u_2x5t u_3x4t u_4x3t u_5x2t u_6xt v_7t v_x6t v_2x5t v_3x4t
v_4x3t v_5x2t v_6xt w_7t w_x6t w_2x5t w_3x4t w_4x3t w_5x2t w_6xt u_8t u_x7t
u_2x6t u_3x5t u_4x4t u_5x3t u_6x2t u_7xt v_8t v_x7t v_2x6t v_3x5t v_4x4t v_5x3t
v_6x2t v_7xt w_8t w_x7t w_2x6t w_3x5t w_4x4t w_5x3t w_6x2t w_7xt)
% list of even parametric derivatives:
all_parametric_der!*:=(u v w u_x v_x w_x u_2x v_2x w_2x u_3x v_3x w_3x u_4x v_4x
w_4x u_5x v_5x w_5x u_6x v_6x w_6x u_7x v_7x w_7x u_8x v_8x w_8x)
% list of odd principal derivatives:
all_principal_odd!*:=(p_t q_t r_t o1_x o1_t o2_x o2_t o3_x o3_t p_2t p_xt q_2t
q_xt r_2t r_xt o1_xt o1_2x o1_2t o1_xt o2_xt o2_2x o2_2t o2_xt o3_xt o3_2x o3_2t
o3_xt p_3t p_x2t p_2xt q_3t q_x2t q_2xt r_3t r_x2t r_2xt o1_x2t o1_2xt o1_3x
o1_3t o1_x2t o1_2xt o2_x2t o2_2xt o2_3x o2_3t o2_x2t o2_2xt o3_x2t o3_2xt o3_3x
o3_3t o3_x2t o3_2xt p_4t p_x3t p_2x2t p_3xt q_4t q_x3t q_2x2t q_3xt r_4t r_x3t
r_2x2t r_3xt o1_x3t o1_2x2t o1_3xt o1_4x o1_4t o1_x3t o1_2x2t o1_3xt o2_x3t
o2_2x2t o2_3xt o2_4x o2_4t o2_x3t o2_2x2t o2_3xt o3_x3t o3_2x2t o3_3xt o3_4x
o3_4t o3_x3t o3_2x2t o3_3xt p_5t p_x4t p_2x3t p_3x2t p_4xt q_5t q_x4t q_2x3t
q_3x2t q_4xt r_5t r_x4t r_2x3t r_3x2t r_4xt o1_x4t o1_2x3t o1_3x2t o1_4xt o1_5x
o1_5t o1_x4t o1_2x3t o1_3x2t o1_4xt o2_x4t o2_2x3t o2_3x2t o2_4xt o2_5x o2_5t
o2_x4t o2_2x3t o2_3x2t o2_4xt o3_x4t o3_2x3t o3_3x2t o3_4xt o3_5x o3_5t o3_x4t
o3_2x3t o3_3x2t o3_4xt p_6t p_x5t p_2x4t p_3x3t p_4x2t p_5xt q_6t q_x5t q_2x4t
q_3x3t q_4x2t q_5xt r_6t r_x5t r_2x4t r_3x3t r_4x2t r_5xt o1_x5t o1_2x4t o1_3x3t
o1_4x2t o1_5xt o1_6x o1_6t o1_x5t o1_2x4t o1_3x3t o1_4x2t o1_5xt o2_x5t o2_2x4t
o2_3x3t o2_4x2t o2_5xt o2_6x o2_6t o2_x5t o2_2x4t o2_3x3t o2_4x2t o2_5xt o3_x5t
o3_2x4t o3_3x3t o3_4x2t o3_5xt o3_6x o3_6t o3_x5t o3_2x4t o3_3x3t o3_4x2t o3_5xt
p_7t p_x6t p_2x5t p_3x4t p_4x3t p_5x2t p_6xt q_7t q_x6t q_2x5t q_3x4t q_4x3t
q_5x2t q_6xt r_7t r_x6t r_2x5t r_3x4t r_4x3t r_5x2t r_6xt o1_x6t o1_2x5t o1_3x4t
o1_4x3t o1_5x2t o1_6xt o1_7x o1_7t o1_x6t o1_2x5t o1_3x4t o1_4x3t o1_5x2t o1_6xt
o2_x6t o2_2x5t o2_3x4t o2_4x3t o2_5x2t o2_6xt o2_7x o2_7t o2_x6t o2_2x5t o2_3x4t
o2_4x3t o2_5x2t o2_6xt o3_x6t o3_2x5t o3_3x4t o3_4x3t o3_5x2t o3_6xt o3_7x o3_7t
o3_x6t o3_2x5t o3_3x4t o3_4x3t o3_5x2t o3_6xt p_8t p_x7t p_2x6t p_3x5t p_4x4t
p_5x3t p_6x2t p_7xt q_8t q_x7t q_2x6t q_3x5t q_4x4t q_5x3t q_6x2t q_7xt r_8t
r_x7t r_2x6t r_3x5t r_4x4t r_5x3t r_6x2t r_7xt o1_x7t o1_2x6t o1_3x5t o1_4x4t
o1_5x3t o1_6x2t o1_7xt o1_8x o1_8t o2_x7t o2_2x6t o2_3x5t o2_4x4t o2_5x3t
o2_6x2t o2_7xt o2_8x o2_8t o3_x7t o3_2x6t o3_3x5t o3_4x4t o3_5x3t o3_6x2t o3_7xt
o3_8x o3_8t)
p_t = (ext 31)
q_t = (ext 32)
r_t = (ext 33)
o1_x = (ext 34)
o1_t = (ext 35)
o2_x = (ext 36)
o2_t = (ext 37)
o3_x = (ext 38)
o3_t = (ext 39)
p_2t = (ext 40)
p_xt = (ext 41)
q_2t = (ext 42)
q_xt = (ext 43)
r_2t = (ext 44)
r_xt = (ext 45)
o1_xt = (ext 46)
o1_2x = (ext 47)
o1_2t = (ext 48)
o1_xt = (ext 46)
o2_xt = (ext 50)
o2_2x = (ext 51)
o2_2t = (ext 52)
o2_xt = (ext 50)
o3_xt = (ext 54)
o3_2x = (ext 55)
o3_2t = (ext 56)
o3_xt = (ext 54)
p_3t = (ext 58)
p_x2t = (ext 59)
p_2xt = (ext 60)
q_3t = (ext 61)
q_x2t = (ext 62)
q_2xt = (ext 63)
r_3t = (ext 64)
r_x2t = (ext 65)
r_2xt = (ext 66)
o1_x2t = (ext 67)
o1_2xt = (ext 68)
o1_3x = (ext 69)
o1_3t = (ext 70)
o1_x2t = (ext 67)
o1_2xt = (ext 68)
o2_x2t = (ext 73)
o2_2xt = (ext 74)
o2_3x = (ext 75)
o2_3t = (ext 76)
o2_x2t = (ext 73)
o2_2xt = (ext 74)
o3_x2t = (ext 79)
o3_2xt = (ext 80)
o3_3x = (ext 81)
o3_3t = (ext 82)
o3_x2t = (ext 79)
o3_2xt = (ext 80)
p_4t = (ext 85)
p_x3t = (ext 86)
p_2x2t = (ext 87)
p_3xt = (ext 88)
q_4t = (ext 89)
q_x3t = (ext 90)
q_2x2t = (ext 91)
q_3xt = (ext 92)
r_4t = (ext 93)
r_x3t = (ext 94)
r_2x2t = (ext 95)
r_3xt = (ext 96)
o1_x3t = (ext 97)
o1_2x2t = (ext 98)
o1_3xt = (ext 99)
o1_4x = (ext 100)
o1_4t = (ext 101)
o1_x3t = (ext 97)
o1_2x2t = (ext 98)
o1_3xt = (ext 99)
o2_x3t = (ext 105)
o2_2x2t = (ext 106)
o2_3xt = (ext 107)
o2_4x = (ext 108)
o2_4t = (ext 109)
o2_x3t = (ext 105)
o2_2x2t = (ext 106)
o2_3xt = (ext 107)
o3_x3t = (ext 113)
o3_2x2t = (ext 114)
o3_3xt = (ext 115)
o3_4x = (ext 116)
o3_4t = (ext 117)
o3_x3t = (ext 113)
o3_2x2t = (ext 114)
o3_3xt = (ext 115)
p_5t = (ext 121)
p_x4t = (ext 122)
p_2x3t = (ext 123)
p_3x2t = (ext 124)
p_4xt = (ext 125)
q_5t = (ext 126)
q_x4t = (ext 127)
q_2x3t = (ext 128)
q_3x2t = (ext 129)
q_4xt = (ext 130)
r_5t = (ext 131)
r_x4t = (ext 132)
r_2x3t = (ext 133)
r_3x2t = (ext 134)
r_4xt = (ext 135)
o1_x4t = (ext 136)
o1_2x3t = (ext 137)
o1_3x2t = (ext 138)
o1_4xt = (ext 139)
o1_5x = (ext 140)
o1_5t = (ext 141)
o1_x4t = (ext 136)
o1_2x3t = (ext 137)
o1_3x2t = (ext 138)
o1_4xt = (ext 139)
o2_x4t = (ext 146)
o2_2x3t = (ext 147)
o2_3x2t = (ext 148)
o2_4xt = (ext 149)
o2_5x = (ext 150)
o2_5t = (ext 151)
o2_x4t = (ext 146)
o2_2x3t = (ext 147)
o2_3x2t = (ext 148)
o2_4xt = (ext 149)
o3_x4t = (ext 156)
o3_2x3t = (ext 157)
o3_3x2t = (ext 158)
o3_4xt = (ext 159)
o3_5x = (ext 160)
o3_5t = (ext 161)
o3_x4t = (ext 156)
o3_2x3t = (ext 157)
o3_3x2t = (ext 158)
o3_4xt = (ext 159)
p_6t = (ext 166)
p_x5t = (ext 167)
p_2x4t = (ext 168)
p_3x3t = (ext 169)
p_4x2t = (ext 170)
p_5xt = (ext 171)
q_6t = (ext 172)
q_x5t = (ext 173)
q_2x4t = (ext 174)
q_3x3t = (ext 175)
q_4x2t = (ext 176)
q_5xt = (ext 177)
r_6t = (ext 178)
r_x5t = (ext 179)
r_2x4t = (ext 180)
r_3x3t = (ext 181)
r_4x2t = (ext 182)
r_5xt = (ext 183)
o1_x5t = (ext 184)
o1_2x4t = (ext 185)
o1_3x3t = (ext 186)
o1_4x2t = (ext 187)
o1_5xt = (ext 188)
o1_6x = (ext 189)
o1_6t = (ext 190)
o1_x5t = (ext 184)
o1_2x4t = (ext 185)
o1_3x3t = (ext 186)
o1_4x2t = (ext 187)
o1_5xt = (ext 188)
o2_x5t = (ext 196)
o2_2x4t = (ext 197)
o2_3x3t = (ext 198)
o2_4x2t = (ext 199)
o2_5xt = (ext 200)
o2_6x = (ext 201)
o2_6t = (ext 202)
o2_x5t = (ext 196)
o2_2x4t = (ext 197)
o2_3x3t = (ext 198)
o2_4x2t = (ext 199)
o2_5xt = (ext 200)
o3_x5t = (ext 208)
o3_2x4t = (ext 209)
o3_3x3t = (ext 210)
o3_4x2t = (ext 211)
o3_5xt = (ext 212)
o3_6x = (ext 213)
o3_6t = (ext 214)
o3_x5t = (ext 208)
o3_2x4t = (ext 209)
o3_3x3t = (ext 210)
o3_4x2t = (ext 211)
o3_5xt = (ext 212)
p_7t = (ext 220)
p_x6t = (ext 221)
p_2x5t = (ext 222)
p_3x4t = (ext 223)
p_4x3t = (ext 224)
p_5x2t = (ext 225)
p_6xt = (ext 226)
q_7t = (ext 227)
q_x6t = (ext 228)
q_2x5t = (ext 229)
q_3x4t = (ext 230)
q_4x3t = (ext 231)
q_5x2t = (ext 232)
q_6xt = (ext 233)
r_7t = (ext 234)
r_x6t = (ext 235)
r_2x5t = (ext 236)
r_3x4t = (ext 237)
r_4x3t = (ext 238)
r_5x2t = (ext 239)
r_6xt = (ext 240)
o1_x6t = (ext 241)
o1_2x5t = (ext 242)
o1_3x4t = (ext 243)
o1_4x3t = (ext 244)
o1_5x2t = (ext 245)
o1_6xt = (ext 246)
o1_7x = (ext 247)
o1_7t = (ext 248)
o1_x6t = (ext 241)
o1_2x5t = (ext 242)
o1_3x4t = (ext 243)
o1_4x3t = (ext 244)
o1_5x2t = (ext 245)
o1_6xt = (ext 246)
o2_x6t = (ext 255)
o2_2x5t = (ext 256)
o2_3x4t = (ext 257)
o2_4x3t = (ext 258)
o2_5x2t = (ext 259)
o2_6xt = (ext 260)
o2_7x = (ext 261)
o2_7t = (ext 262)
o2_x6t = (ext 255)
o2_2x5t = (ext 256)
o2_3x4t = (ext 257)
o2_4x3t = (ext 258)
o2_5x2t = (ext 259)
o2_6xt = (ext 260)
o3_x6t = (ext 269)
o3_2x5t = (ext 270)
o3_3x4t = (ext 271)
o3_4x3t = (ext 272)
o3_5x2t = (ext 273)
o3_6xt = (ext 274)
o3_7x = (ext 275)
o3_7t = (ext 276)
o3_x6t = (ext 269)
o3_2x5t = (ext 270)
o3_3x4t = (ext 271)
o3_4x3t = (ext 272)
o3_5x2t = (ext 273)
o3_6xt = (ext 274)
p_8t = (ext 283)
p_x7t = (ext 284)
p_2x6t = (ext 285)
p_3x5t = (ext 286)
p_4x4t = (ext 287)
p_5x3t = (ext 288)
p_6x2t = (ext 289)
p_7xt = (ext 290)
q_8t = (ext 291)
q_x7t = (ext 292)
q_2x6t = (ext 293)
q_3x5t = (ext 294)
q_4x4t = (ext 295)
q_5x3t = (ext 296)
q_6x2t = (ext 297)
q_7xt = (ext 298)
r_8t = (ext 299)
r_x7t = (ext 300)
r_2x6t = (ext 301)
r_3x5t = (ext 302)
r_4x4t = (ext 303)
r_5x3t = (ext 304)
r_6x2t = (ext 305)
r_7xt = (ext 306)
o1_x7t = (ext 307)
o1_2x6t = (ext 308)
o1_3x5t = (ext 309)
o1_4x4t = (ext 310)
o1_5x3t = (ext 311)
o1_6x2t = (ext 312)
o1_7xt = (ext 313)
o1_8x = (ext 314)
o1_8t = (ext 315)
o2_x7t = (ext 316)
o2_2x6t = (ext 317)
o2_3x5t = (ext 318)
o2_4x4t = (ext 319)
o2_5x3t = (ext 320)
o2_6x2t = (ext 321)
o2_7xt = (ext 322)
o2_8x = (ext 323)
o2_8t = (ext 324)
o3_x7t = (ext 325)
o3_2x6t = (ext 326)
o3_3x5t = (ext 327)
o3_4x4t = (ext 328)
o3_5x3t = (ext 329)
o3_6x2t = (ext 330)
o3_7xt = (ext 331)
o3_8x = (ext 332)
o3_8t = (ext 333)
% list of odd parametric derivatives:
all_parametric_odd!*:=(p q r o1 o2 o3 p_x q_x r_x p_2x q_2x r_2x p_3x q_3x r_3x
p_4x q_4x r_4x p_5x q_5x r_5x p_6x q_6x r_6x p_7x q_7x r_7x p_8x q_8x r_8x)
p = (ext 1)
q = (ext 2)
r = (ext 3)
o1 = (ext 4)
o2 = (ext 5)
o3 = (ext 6)
p_x = (ext 7)
q_x = (ext 8)
r_x = (ext 9)
p_2x = (ext 10)
q_2x = (ext 11)
r_2x = (ext 12)
p_3x = (ext 13)
q_3x = (ext 14)
r_3x = (ext 15)
p_4x = (ext 16)
q_4x = (ext 17)
r_4x = (ext 18)
p_5x = (ext 19)
q_5x = (ext 20)
r_5x = (ext 21)
p_6x = (ext 22)
q_6x = (ext 23)
r_6x = (ext 24)
p_7x = (ext 25)
q_7x = (ext 26)
r_7x = (ext 27)
p_8x = (ext 28)
q_8x = (ext 29)
r_8x = (ext 30)
% number of ext principal derivatives:
n_all_principal_ext:=303
% number of ext parametric derivatives:
n_all_parametric_ext:=30
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddt)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddt 0 3 u_t) (ddt 0 4 v_t) (ddt 0 5 w_t) (ddt 0 6
u_xt) (ddt 0 7 v_xt) (ddt 0 8 w_xt) (ddt 0 9 u_2xt) (ddt 0 10 v_2xt) (ddt 0 11
w_2xt) (ddt 0 12 u_3xt) (ddt 0 13 v_3xt) (ddt 0 14 w_3xt) (ddt 0 15 u_4xt) (ddt
0 16 v_4xt) (ddt 0 17 w_4xt) (ddt 0 18 u_5xt) (ddt 0 19 v_5xt) (ddt 0 20 w_5xt)
(ddt 0 21 u_6xt) (ddt 0 22 v_6xt) (ddt 0 23 w_6xt) (ddt 0 24 u_7xt) (ddt 0 25
v_7xt) (ddt 0 26 w_7xt))
primary_diffcon_odd_tot!*:=((ddx 1 4 o1_x) (ddx 1 5 o2_x) (ddx 1 6 o3_x) (ddt 1
1 p_t) (ddt 1 2 q_t) (ddt 1 3 r_t) (ddt 1 4 o1_t) (ddt 1 5 o2_t) (ddt 1 6 o3_t)
(ddt 1 7 p_xt) (ddt 1 8 q_xt) (ddt 1 9 r_xt) (ddt 1 10 p_2xt) (ddt 1 11 q_2xt) (
ddt 1 12 r_2xt) (ddt 1 13 p_3xt) (ddt 1 14 q_3xt) (ddt 1 15 r_3xt) (ddt 1 16
p_4xt) (ddt 1 17 q_4xt) (ddt 1 18 r_4xt) (ddt 1 19 p_5xt) (ddt 1 20 q_5xt) (ddt
1 21 r_5xt) (ddt 1 22 p_6xt) (ddt 1 23 q_6xt) (ddt 1 24 r_6xt) (ddt 1 25 p_7xt)
(ddt 1 26 q_7xt) (ddt 1 27 r_7xt))
primary_diffcon_der!*:=(u_xt v_xt w_xt u_2xt v_2xt w_2xt u_3xt v_3xt w_3xt u_4xt
v_4xt w_4xt u_5xt v_5xt w_5xt u_6xt v_6xt w_6xt u_7xt v_7xt w_7xt)
primary_diffcon_odd!*:=(p_xt q_xt r_xt p_2xt q_2xt r_2xt p_3xt q_3xt r_3xt p_4xt
q_4xt r_4xt p_5xt q_5xt r_5xt p_6xt q_6xt r_6xt p_7xt q_7xt r_7xt)
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((w_7xt (*sq ((((u_8x . 1) . 1)) . 1) nil)) (v_7xt (*sq ((((u . 1
) ((w_8x . 1) . -1)) ((u_2x . 1) ((w_6x . 1) . -42)) ((u_3x . 1) ((w_5x . 1) .
-98)) ((u_4x . 1) ((w_4x . 1) . -140)) ((u_5x . 1) ((w_3x . 1) . -126)) ((u_6x .
1) ((w_2x . 1) . -70)) ((u_7x . 1) ((w_x . 1) . -22)) ((u_8x . 1) ((w . 1) . -3)
) ((u_x . 1) ((w_7x . 1) . -10))) . 1) nil)) (u_7xt (*sq ((((v_8x . 1) . 1) ((w
. 1) ((w_8x . 1) . 1)) ((w_2x . 1) ((w_6x . 1) . 28)) ((w_3x . 1) ((w_5x . 1) .
56)) ((w_4x . 2) . 35) ((w_7x . 1) ((w_x . 1) . 8))) . 1) nil)) (w_6xt (*sq ((((
u_7x . 1) . 1)) . 1) nil)) (v_6xt (*sq ((((u . 1) ((w_7x . 1) . -1)) ((u_2x . 1)
((w_5x . 1) . -33)) ((u_3x . 1) ((w_4x . 1) . -65)) ((u_4x . 1) ((w_3x . 1) .
-75)) ((u_5x . 1) ((w_2x . 1) . -51)) ((u_6x . 1) ((w_x . 1) . -19)) ((u_7x . 1)
((w . 1) . -3)) ((u_x . 1) ((w_6x . 1) . -9))) . 1) nil)) (u_6xt (*sq ((((v_7x .
1) . 1) ((w . 1) ((w_7x . 1) . 1)) ((w_2x . 1) ((w_5x . 1) . 21)) ((w_3x . 1) ((
w_4x . 1) . 35)) ((w_6x . 1) ((w_x . 1) . 7))) . 1) nil)) (w_5xt (*sq ((((u_6x .
1) . 1)) . 1) nil)) (v_5xt (*sq ((((u . 1) ((w_6x . 1) . -1)) ((u_2x . 1) ((w_4x
. 1) . -25)) ((u_3x . 1) ((w_3x . 1) . -40)) ((u_4x . 1) ((w_2x . 1) . -35)) ((
u_5x . 1) ((w_x . 1) . -16)) ((u_6x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_5x . 1)
. -8))) . 1) nil)) (u_5xt (*sq ((((v_6x . 1) . 1) ((w . 1) ((w_6x . 1) . 1)) ((
w_2x . 1) ((w_4x . 1) . 15)) ((w_3x . 2) . 10) ((w_5x . 1) ((w_x . 1) . 6))) . 1
) nil)) (w_4xt (*sq ((((u_5x . 1) . 1)) . 1) nil)) (v_4xt (*sq ((((u . 1) ((w_5x
. 1) . -1)) ((u_2x . 1) ((w_3x . 1) . -18)) ((u_3x . 1) ((w_2x . 1) . -22)) ((
u_4x . 1) ((w_x . 1) . -13)) ((u_5x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_4x . 1)
. -7))) . 1) nil)) (u_4xt (*sq ((((v_5x . 1) . 1) ((w . 1) ((w_5x . 1) . 1)) ((
w_2x . 1) ((w_3x . 1) . 10)) ((w_4x . 1) ((w_x . 1) . 5))) . 1) nil)) (w_3xt (
*sq ((((u_4x . 1) . 1)) . 1) nil)) (v_3xt (*sq ((((u . 1) ((w_4x . 1) . -1)) ((
u_2x . 1) ((w_2x . 1) . -12)) ((u_3x . 1) ((w_x . 1) . -10)) ((u_4x . 1) ((w . 1
) . -3)) ((u_x . 1) ((w_3x . 1) . -6))) . 1) nil)) (u_3xt (*sq ((((v_4x . 1) . 1
) ((w . 1) ((w_4x . 1) . 1)) ((w_2x . 2) . 3) ((w_3x . 1) ((w_x . 1) . 4))) . 1)
nil)) (w_2xt (*sq ((((u_3x . 1) . 1)) . 1) nil)) (v_2xt (*sq ((((u . 1) ((w_3x .
1) . -1)) ((u_2x . 1) ((w_x . 1) . -7)) ((u_3x . 1) ((w . 1) . -3)) ((u_x . 1) (
(w_2x . 1) . -5))) . 1) nil)) (u_2xt (*sq ((((v_3x . 1) . 1) ((w . 1) ((w_3x . 1
) . 1)) ((w_2x . 1) ((w_x . 1) . 3))) . 1) nil)) (w_xt (*sq ((((u_2x . 1) . 1))
. 1) nil)) (v_xt (*sq ((((u . 1) ((w_2x . 1) . -1)) ((u_2x . 1) ((w . 1) . -3))
((u_x . 1) ((w_x . 1) . -4))) . 1) nil)) (u_xt (*sq ((((v_2x . 1) . 1) ((w . 1)
((w_2x . 1) . 1)) ((w_x . 2) . 1)) . 1) nil)) (w_t u_x) (v_t (plus (minus (times
u w_x)) (minus (times 3 u_x w)))) (u_t (plus v_x (times w w_x))))
diffcon_odd!*:=((r_7xt (*sq (((((ext 28) . 1) . 1)) . 1) nil)) (q_7xt (*sq (((((
ext 30) . 1) ((u . 1) . -1)) (((ext 28) . 1) ((w . 1) . -3)) (((ext 27) . 1) ((
u_x . 1) . -10)) (((ext 25) . 1) ((w_x . 1) . -22)) (((ext 24) . 1) ((u_2x . 1)
. -42)) (((ext 22) . 1) ((w_2x . 1) . -70)) (((ext 21) . 1) ((u_3x . 1) . -98))
(((ext 19) . 1) ((w_3x . 1) . -126)) (((ext 18) . 1) ((u_4x . 1) . -140)) (((ext
16) . 1) ((w_4x . 1) . -140)) (((ext 15) . 1) ((u_5x . 1) . -126)) (((ext 13) .
1) ((w_5x . 1) . -98)) (((ext 12) . 1) ((u_6x . 1) . -70)) (((ext 10) . 1) ((
w_6x . 1) . -42)) (((ext 9) . 1) ((u_7x . 1) . -22)) (((ext 7) . 1) ((w_7x . 1)
. -10)) (((ext 3) . 1) ((u_8x . 1) . -3)) (((ext 1) . 1) ((w_8x . 1) . -1))) . 1
) nil)) (p_7xt (*sq (((((ext 30) . 1) ((w . 1) . 1)) (((ext 29) . 1) . 1) (((ext
27) . 1) ((w_x . 1) . 8)) (((ext 24) . 1) ((w_2x . 1) . 28)) (((ext 21) . 1) ((
w_3x . 1) . 56)) (((ext 18) . 1) ((w_4x . 1) . 70)) (((ext 15) . 1) ((w_5x . 1)
. 56)) (((ext 12) . 1) ((w_6x . 1) . 28)) (((ext 9) . 1) ((w_7x . 1) . 8)) (((
ext 3) . 1) ((w_8x . 1) . 1))) . 1) nil)) (r_6xt (*sq (((((ext 25) . 1) . 1)) .
1) nil)) (q_6xt (*sq (((((ext 27) . 1) ((u . 1) . -1)) (((ext 25) . 1) ((w . 1)
. -3)) (((ext 24) . 1) ((u_x . 1) . -9)) (((ext 22) . 1) ((w_x . 1) . -19)) (((
ext 21) . 1) ((u_2x . 1) . -33)) (((ext 19) . 1) ((w_2x . 1) . -51)) (((ext 18)
. 1) ((u_3x . 1) . -65)) (((ext 16) . 1) ((w_3x . 1) . -75)) (((ext 15) . 1) ((
u_4x . 1) . -75)) (((ext 13) . 1) ((w_4x . 1) . -65)) (((ext 12) . 1) ((u_5x . 1
) . -51)) (((ext 10) . 1) ((w_5x . 1) . -33)) (((ext 9) . 1) ((u_6x . 1) . -19))
(((ext 7) . 1) ((w_6x . 1) . -9)) (((ext 3) . 1) ((u_7x . 1) . -3)) (((ext 1) .
1) ((w_7x . 1) . -1))) . 1) nil)) (p_6xt (*sq (((((ext 27) . 1) ((w . 1) . 1)) (
((ext 26) . 1) . 1) (((ext 24) . 1) ((w_x . 1) . 7)) (((ext 21) . 1) ((w_2x . 1)
. 21)) (((ext 18) . 1) ((w_3x . 1) . 35)) (((ext 15) . 1) ((w_4x . 1) . 35)) (((
ext 12) . 1) ((w_5x . 1) . 21)) (((ext 9) . 1) ((w_6x . 1) . 7)) (((ext 3) . 1)
((w_7x . 1) . 1))) . 1) nil)) (r_5xt (*sq (((((ext 22) . 1) . 1)) . 1) nil)) (
q_5xt (*sq (((((ext 24) . 1) ((u . 1) . -1)) (((ext 22) . 1) ((w . 1) . -3)) (((
ext 21) . 1) ((u_x . 1) . -8)) (((ext 19) . 1) ((w_x . 1) . -16)) (((ext 18) . 1
) ((u_2x . 1) . -25)) (((ext 16) . 1) ((w_2x . 1) . -35)) (((ext 15) . 1) ((u_3x
. 1) . -40)) (((ext 13) . 1) ((w_3x . 1) . -40)) (((ext 12) . 1) ((u_4x . 1) .
-35)) (((ext 10) . 1) ((w_4x . 1) . -25)) (((ext 9) . 1) ((u_5x . 1) . -16)) (((
ext 7) . 1) ((w_5x . 1) . -8)) (((ext 3) . 1) ((u_6x . 1) . -3)) (((ext 1) . 1)
((w_6x . 1) . -1))) . 1) nil)) (p_5xt (*sq (((((ext 24) . 1) ((w . 1) . 1)) (((
ext 23) . 1) . 1) (((ext 21) . 1) ((w_x . 1) . 6)) (((ext 18) . 1) ((w_2x . 1) .
15)) (((ext 15) . 1) ((w_3x . 1) . 20)) (((ext 12) . 1) ((w_4x . 1) . 15)) (((
ext 9) . 1) ((w_5x . 1) . 6)) (((ext 3) . 1) ((w_6x . 1) . 1))) . 1) nil)) (
r_4xt (*sq (((((ext 19) . 1) . 1)) . 1) nil)) (q_4xt (*sq (((((ext 21) . 1) ((u
. 1) . -1)) (((ext 19) . 1) ((w . 1) . -3)) (((ext 18) . 1) ((u_x . 1) . -7)) ((
(ext 16) . 1) ((w_x . 1) . -13)) (((ext 15) . 1) ((u_2x . 1) . -18)) (((ext 13)
. 1) ((w_2x . 1) . -22)) (((ext 12) . 1) ((u_3x . 1) . -22)) (((ext 10) . 1) ((
w_3x . 1) . -18)) (((ext 9) . 1) ((u_4x . 1) . -13)) (((ext 7) . 1) ((w_4x . 1)
. -7)) (((ext 3) . 1) ((u_5x . 1) . -3)) (((ext 1) . 1) ((w_5x . 1) . -1))) . 1)
nil)) (p_4xt (*sq (((((ext 21) . 1) ((w . 1) . 1)) (((ext 20) . 1) . 1) (((ext
18) . 1) ((w_x . 1) . 5)) (((ext 15) . 1) ((w_2x . 1) . 10)) (((ext 12) . 1) ((
w_3x . 1) . 10)) (((ext 9) . 1) ((w_4x . 1) . 5)) (((ext 3) . 1) ((w_5x . 1) . 1
))) . 1) nil)) (r_3xt (*sq (((((ext 16) . 1) . 1)) . 1) nil)) (q_3xt (*sq (((((
ext 18) . 1) ((u . 1) . -1)) (((ext 16) . 1) ((w . 1) . -3)) (((ext 15) . 1) ((
u_x . 1) . -6)) (((ext 13) . 1) ((w_x . 1) . -10)) (((ext 12) . 1) ((u_2x . 1) .
-12)) (((ext 10) . 1) ((w_2x . 1) . -12)) (((ext 9) . 1) ((u_3x . 1) . -10)) (((
ext 7) . 1) ((w_3x . 1) . -6)) (((ext 3) . 1) ((u_4x . 1) . -3)) (((ext 1) . 1)
((w_4x . 1) . -1))) . 1) nil)) (p_3xt (*sq (((((ext 18) . 1) ((w . 1) . 1)) (((
ext 17) . 1) . 1) (((ext 15) . 1) ((w_x . 1) . 4)) (((ext 12) . 1) ((w_2x . 1) .
6)) (((ext 9) . 1) ((w_3x . 1) . 4)) (((ext 3) . 1) ((w_4x . 1) . 1))) . 1) nil)
) (r_2xt (*sq (((((ext 13) . 1) . 1)) . 1) nil)) (q_2xt (*sq (((((ext 15) . 1) (
(u . 1) . -1)) (((ext 13) . 1) ((w . 1) . -3)) (((ext 12) . 1) ((u_x . 1) . -5))
(((ext 10) . 1) ((w_x . 1) . -7)) (((ext 9) . 1) ((u_2x . 1) . -7)) (((ext 7) .
1) ((w_2x . 1) . -5)) (((ext 3) . 1) ((u_3x . 1) . -3)) (((ext 1) . 1) ((w_3x .
1) . -1))) . 1) nil)) (p_2xt (*sq (((((ext 15) . 1) ((w . 1) . 1)) (((ext 14) .
1) . 1) (((ext 12) . 1) ((w_x . 1) . 3)) (((ext 9) . 1) ((w_2x . 1) . 3)) (((ext
3) . 1) ((w_3x . 1) . 1))) . 1) nil)) (r_xt (*sq (((((ext 10) . 1) . 1)) . 1)
nil)) (q_xt (*sq (((((ext 12) . 1) ((u . 1) . -1)) (((ext 10) . 1) ((w . 1) . -3
)) (((ext 9) . 1) ((u_x . 1) . -4)) (((ext 7) . 1) ((w_x . 1) . -4)) (((ext 3) .
1) ((u_2x . 1) . -3)) (((ext 1) . 1) ((w_2x . 1) . -1))) . 1) nil)) (p_xt (*sq (
((((ext 12) . 1) ((w . 1) . 1)) (((ext 11) . 1) . 1) (((ext 9) . 1) ((w_x . 1) .
2)) (((ext 3) . 1) ((w_2x . 1) . 1))) . 1) nil)) (o3_x (*sq (((((ext 3) . 1) ((w
. 1) . 2)) (((ext 2) . 1) . 1)) . 1) nil)) (o3_t (*sq (((((ext 3) . 1) ((u . 1)
. -1)) (((ext 1) . 1) ((w . 1) . -1))) . 1) nil)) (o2_x (*sq (((((ext 1) . 1) .
1)) . 1) nil)) (o2_t (*sq (((((ext 3) . 1) ((w . 1) . 1)) (((ext 2) . 1) . 1)) .
1) nil)) (o1_x (*sq (((((ext 3) . 1) . 1)) . 1) nil)) (o1_t (*sq (((((ext 1) . 1
) . 1)) . 1) nil)) (r_t (*sq (((((ext 7) . 1) . 1)) . 1) nil)) (q_t (*sq (((((
ext 9) . 1) ((u . 1) . -1)) (((ext 7) . 1) ((w . 1) . -3)) (((ext 3) . 1) ((u_x
. 1) . -3)) (((ext 1) . 1) ((w_x . 1) . -1))) . 1) nil)) (p_t (*sq (((((ext 9) .
1) ((w . 1) . 1)) (((ext 8) . 1) . 1) (((ext 3) . 1) ((w_x . 1) . 1))) . 1) nil)
))
% Principal derivatives computed:
diffcon_comp_der!*:=(w_7xt v_7xt u_7xt w_6xt v_6xt u_6xt w_5xt v_5xt u_5xt w_4xt
v_4xt u_4xt w_3xt v_3xt u_3xt w_2xt v_2xt u_2xt w_xt v_xt u_xt w_t v_t u_t)
diffcon_comp_odd!*:=(r_7xt q_7xt p_7xt r_6xt q_6xt p_6xt r_5xt q_5xt p_5xt r_4xt
q_4xt p_4xt r_3xt q_3xt p_3xt r_2xt q_2xt p_2xt r_xt q_xt p_xt o3_x o3_t o2_x
o2_t o1_x o1_t r_t q_t p_t)
diffcon_comp_ext!*:=((ext 306) (ext 298) (ext 290) (ext 240) (ext 233) (ext 226)
(ext 183) (ext 177) (ext 171) (ext 135) (ext 130) (ext 125) (ext 96) (ext 92) (
ext 88) (ext 66) (ext 63) (ext 60) (ext 45) (ext 43) (ext 41) (ext 38) (ext 39)
(ext 36) (ext 37) (ext 34) (ext 35) (ext 33) (ext 32) (ext 31))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((w_7xt *sq ((((u_8x . 1) . 1)) . 1) nil) (v_7xt *sq ((((u
. 1) ((w_8x . 1) . -1)) ((u_2x . 1) ((w_6x . 1) . -42)) ((u_3x . 1) ((w_5x . 1)
. -98)) ((u_4x . 1) ((w_4x . 1) . -140)) ((u_5x . 1) ((w_3x . 1) . -126)) ((u_6x
. 1) ((w_2x . 1) . -70)) ((u_7x . 1) ((w_x . 1) . -22)) ((u_8x . 1) ((w . 1) .
-3)) ((u_x . 1) ((w_7x . 1) . -10))) . 1) nil) (u_7xt *sq ((((v_8x . 1) . 1) ((w
. 1) ((w_8x . 1) . 1)) ((w_2x . 1) ((w_6x . 1) . 28)) ((w_3x . 1) ((w_5x . 1) .
56)) ((w_4x . 2) . 35) ((w_7x . 1) ((w_x . 1) . 8))) . 1) nil) (w_6xt *sq ((((
u_7x . 1) . 1)) . 1) nil) (v_6xt *sq ((((u . 1) ((w_7x . 1) . -1)) ((u_2x . 1) (
(w_5x . 1) . -33)) ((u_3x . 1) ((w_4x . 1) . -65)) ((u_4x . 1) ((w_3x . 1) . -75
)) ((u_5x . 1) ((w_2x . 1) . -51)) ((u_6x . 1) ((w_x . 1) . -19)) ((u_7x . 1) ((
w . 1) . -3)) ((u_x . 1) ((w_6x . 1) . -9))) . 1) nil) (u_6xt *sq ((((v_7x . 1)
. 1) ((w . 1) ((w_7x . 1) . 1)) ((w_2x . 1) ((w_5x . 1) . 21)) ((w_3x . 1) ((
w_4x . 1) . 35)) ((w_6x . 1) ((w_x . 1) . 7))) . 1) nil) (w_5xt *sq ((((u_6x . 1
) . 1)) . 1) nil) (v_5xt *sq ((((u . 1) ((w_6x . 1) . -1)) ((u_2x . 1) ((w_4x .
1) . -25)) ((u_3x . 1) ((w_3x . 1) . -40)) ((u_4x . 1) ((w_2x . 1) . -35)) ((
u_5x . 1) ((w_x . 1) . -16)) ((u_6x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_5x . 1)
. -8))) . 1) nil) (u_5xt *sq ((((v_6x . 1) . 1) ((w . 1) ((w_6x . 1) . 1)) ((
w_2x . 1) ((w_4x . 1) . 15)) ((w_3x . 2) . 10) ((w_5x . 1) ((w_x . 1) . 6))) . 1
) nil) (w_4xt *sq ((((u_5x . 1) . 1)) . 1) nil) (v_4xt *sq ((((u . 1) ((w_5x . 1
) . -1)) ((u_2x . 1) ((w_3x . 1) . -18)) ((u_3x . 1) ((w_2x . 1) . -22)) ((u_4x
. 1) ((w_x . 1) . -13)) ((u_5x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_4x . 1) . -7)
)) . 1) nil) (u_4xt *sq ((((v_5x . 1) . 1) ((w . 1) ((w_5x . 1) . 1)) ((w_2x . 1
) ((w_3x . 1) . 10)) ((w_4x . 1) ((w_x . 1) . 5))) . 1) nil) (w_3xt *sq ((((u_4x
. 1) . 1)) . 1) nil) (v_3xt *sq ((((u . 1) ((w_4x . 1) . -1)) ((u_2x . 1) ((w_2x
. 1) . -12)) ((u_3x . 1) ((w_x . 1) . -10)) ((u_4x . 1) ((w . 1) . -3)) ((u_x .
1) ((w_3x . 1) . -6))) . 1) nil) (u_3xt *sq ((((v_4x . 1) . 1) ((w . 1) ((w_4x .
1) . 1)) ((w_2x . 2) . 3) ((w_3x . 1) ((w_x . 1) . 4))) . 1) nil) (w_2xt *sq (((
(u_3x . 1) . 1)) . 1) nil) (v_2xt *sq ((((u . 1) ((w_3x . 1) . -1)) ((u_2x . 1)
((w_x . 1) . -7)) ((u_3x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_2x . 1) . -5))) . 1
) nil) (u_2xt *sq ((((v_3x . 1) . 1) ((w . 1) ((w_3x . 1) . 1)) ((w_2x . 1) ((
w_x . 1) . 3))) . 1) nil) (w_xt *sq ((((u_2x . 1) . 1)) . 1) nil) (v_xt *sq ((((
u . 1) ((w_2x . 1) . -1)) ((u_2x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_x . 1) . -4
))) . 1) nil) (u_xt *sq ((((v_2x . 1) . 1) ((w . 1) ((w_2x . 1) . 1)) ((w_x . 2)
. 1)) . 1) nil) (w_t *sq ((((u_x . 1) . 1)) . 1) nil) (v_t *sq ((((u . 1) ((w_x
. 1) . -1)) ((u_x . 1) ((w . 1) . -3))) . 1) nil) (u_t *sq ((((v_x . 1) . 1) ((w
. 1) ((w_x . 1) . 1))) . 1) nil))
diffcon_param_ext!*:=(((ext 306) *sq (((((ext 28) . 1) . 1)) . 1) nil) ((ext 298
) *sq (((((ext 30) . 1) ((u . 1) . -1)) (((ext 28) . 1) ((w . 1) . -3)) (((ext
27) . 1) ((u_x . 1) . -10)) (((ext 25) . 1) ((w_x . 1) . -22)) (((ext 24) . 1) (
(u_2x . 1) . -42)) (((ext 22) . 1) ((w_2x . 1) . -70)) (((ext 21) . 1) ((u_3x .
1) . -98)) (((ext 19) . 1) ((w_3x . 1) . -126)) (((ext 18) . 1) ((u_4x . 1) .
-140)) (((ext 16) . 1) ((w_4x . 1) . -140)) (((ext 15) . 1) ((u_5x . 1) . -126))
(((ext 13) . 1) ((w_5x . 1) . -98)) (((ext 12) . 1) ((u_6x . 1) . -70)) (((ext
10) . 1) ((w_6x . 1) . -42)) (((ext 9) . 1) ((u_7x . 1) . -22)) (((ext 7) . 1) (
(w_7x . 1) . -10)) (((ext 3) . 1) ((u_8x . 1) . -3)) (((ext 1) . 1) ((w_8x . 1)
. -1))) . 1) nil) ((ext 290) *sq (((((ext 30) . 1) ((w . 1) . 1)) (((ext 29) . 1
) . 1) (((ext 27) . 1) ((w_x . 1) . 8)) (((ext 24) . 1) ((w_2x . 1) . 28)) (((
ext 21) . 1) ((w_3x . 1) . 56)) (((ext 18) . 1) ((w_4x . 1) . 70)) (((ext 15) .
1) ((w_5x . 1) . 56)) (((ext 12) . 1) ((w_6x . 1) . 28)) (((ext 9) . 1) ((w_7x .
1) . 8)) (((ext 3) . 1) ((w_8x . 1) . 1))) . 1) nil) ((ext 240) *sq (((((ext 25)
. 1) . 1)) . 1) nil) ((ext 233) *sq (((((ext 27) . 1) ((u . 1) . -1)) (((ext 25)
. 1) ((w . 1) . -3)) (((ext 24) . 1) ((u_x . 1) . -9)) (((ext 22) . 1) ((w_x . 1
) . -19)) (((ext 21) . 1) ((u_2x . 1) . -33)) (((ext 19) . 1) ((w_2x . 1) . -51)
) (((ext 18) . 1) ((u_3x . 1) . -65)) (((ext 16) . 1) ((w_3x . 1) . -75)) (((ext
15) . 1) ((u_4x . 1) . -75)) (((ext 13) . 1) ((w_4x . 1) . -65)) (((ext 12) . 1)
((u_5x . 1) . -51)) (((ext 10) . 1) ((w_5x . 1) . -33)) (((ext 9) . 1) ((u_6x .
1) . -19)) (((ext 7) . 1) ((w_6x . 1) . -9)) (((ext 3) . 1) ((u_7x . 1) . -3)) (
((ext 1) . 1) ((w_7x . 1) . -1))) . 1) nil) ((ext 226) *sq (((((ext 27) . 1) ((w
. 1) . 1)) (((ext 26) . 1) . 1) (((ext 24) . 1) ((w_x . 1) . 7)) (((ext 21) . 1)
((w_2x . 1) . 21)) (((ext 18) . 1) ((w_3x . 1) . 35)) (((ext 15) . 1) ((w_4x . 1
) . 35)) (((ext 12) . 1) ((w_5x . 1) . 21)) (((ext 9) . 1) ((w_6x . 1) . 7)) (((
ext 3) . 1) ((w_7x . 1) . 1))) . 1) nil) ((ext 183) *sq (((((ext 22) . 1) . 1))
. 1) nil) ((ext 177) *sq (((((ext 24) . 1) ((u . 1) . -1)) (((ext 22) . 1) ((w .
1) . -3)) (((ext 21) . 1) ((u_x . 1) . -8)) (((ext 19) . 1) ((w_x . 1) . -16)) (
((ext 18) . 1) ((u_2x . 1) . -25)) (((ext 16) . 1) ((w_2x . 1) . -35)) (((ext 15
) . 1) ((u_3x . 1) . -40)) (((ext 13) . 1) ((w_3x . 1) . -40)) (((ext 12) . 1) (
(u_4x . 1) . -35)) (((ext 10) . 1) ((w_4x . 1) . -25)) (((ext 9) . 1) ((u_5x . 1
) . -16)) (((ext 7) . 1) ((w_5x . 1) . -8)) (((ext 3) . 1) ((u_6x . 1) . -3)) ((
(ext 1) . 1) ((w_6x . 1) . -1))) . 1) nil) ((ext 171) *sq (((((ext 24) . 1) ((w
. 1) . 1)) (((ext 23) . 1) . 1) (((ext 21) . 1) ((w_x . 1) . 6)) (((ext 18) . 1)
((w_2x . 1) . 15)) (((ext 15) . 1) ((w_3x . 1) . 20)) (((ext 12) . 1) ((w_4x . 1
) . 15)) (((ext 9) . 1) ((w_5x . 1) . 6)) (((ext 3) . 1) ((w_6x . 1) . 1))) . 1)
nil) ((ext 135) *sq (((((ext 19) . 1) . 1)) . 1) nil) ((ext 130) *sq (((((ext 21
) . 1) ((u . 1) . -1)) (((ext 19) . 1) ((w . 1) . -3)) (((ext 18) . 1) ((u_x . 1
) . -7)) (((ext 16) . 1) ((w_x . 1) . -13)) (((ext 15) . 1) ((u_2x . 1) . -18))
(((ext 13) . 1) ((w_2x . 1) . -22)) (((ext 12) . 1) ((u_3x . 1) . -22)) (((ext
10) . 1) ((w_3x . 1) . -18)) (((ext 9) . 1) ((u_4x . 1) . -13)) (((ext 7) . 1) (
(w_4x . 1) . -7)) (((ext 3) . 1) ((u_5x . 1) . -3)) (((ext 1) . 1) ((w_5x . 1) .
-1))) . 1) nil) ((ext 125) *sq (((((ext 21) . 1) ((w . 1) . 1)) (((ext 20) . 1)
. 1) (((ext 18) . 1) ((w_x . 1) . 5)) (((ext 15) . 1) ((w_2x . 1) . 10)) (((ext
12) . 1) ((w_3x . 1) . 10)) (((ext 9) . 1) ((w_4x . 1) . 5)) (((ext 3) . 1) ((
w_5x . 1) . 1))) . 1) nil) ((ext 96) *sq (((((ext 16) . 1) . 1)) . 1) nil) ((ext
92) *sq (((((ext 18) . 1) ((u . 1) . -1)) (((ext 16) . 1) ((w . 1) . -3)) (((ext
15) . 1) ((u_x . 1) . -6)) (((ext 13) . 1) ((w_x . 1) . -10)) (((ext 12) . 1) ((
u_2x . 1) . -12)) (((ext 10) . 1) ((w_2x . 1) . -12)) (((ext 9) . 1) ((u_3x . 1)
. -10)) (((ext 7) . 1) ((w_3x . 1) . -6)) (((ext 3) . 1) ((u_4x . 1) . -3)) (((
ext 1) . 1) ((w_4x . 1) . -1))) . 1) nil) ((ext 88) *sq (((((ext 18) . 1) ((w .
1) . 1)) (((ext 17) . 1) . 1) (((ext 15) . 1) ((w_x . 1) . 4)) (((ext 12) . 1) (
(w_2x . 1) . 6)) (((ext 9) . 1) ((w_3x . 1) . 4)) (((ext 3) . 1) ((w_4x . 1) . 1
))) . 1) nil) ((ext 66) *sq (((((ext 13) . 1) . 1)) . 1) nil) ((ext 63) *sq ((((
(ext 15) . 1) ((u . 1) . -1)) (((ext 13) . 1) ((w . 1) . -3)) (((ext 12) . 1) ((
u_x . 1) . -5)) (((ext 10) . 1) ((w_x . 1) . -7)) (((ext 9) . 1) ((u_2x . 1) .
-7)) (((ext 7) . 1) ((w_2x . 1) . -5)) (((ext 3) . 1) ((u_3x . 1) . -3)) (((ext
1) . 1) ((w_3x . 1) . -1))) . 1) nil) ((ext 60) *sq (((((ext 15) . 1) ((w . 1) .
1)) (((ext 14) . 1) . 1) (((ext 12) . 1) ((w_x . 1) . 3)) (((ext 9) . 1) ((w_2x
. 1) . 3)) (((ext 3) . 1) ((w_3x . 1) . 1))) . 1) nil) ((ext 45) *sq (((((ext 10
) . 1) . 1)) . 1) nil) ((ext 43) *sq (((((ext 12) . 1) ((u . 1) . -1)) (((ext 10
) . 1) ((w . 1) . -3)) (((ext 9) . 1) ((u_x . 1) . -4)) (((ext 7) . 1) ((w_x . 1
) . -4)) (((ext 3) . 1) ((u_2x . 1) . -3)) (((ext 1) . 1) ((w_2x . 1) . -1))) .
1) nil) ((ext 41) *sq (((((ext 12) . 1) ((w . 1) . 1)) (((ext 11) . 1) . 1) (((
ext 9) . 1) ((w_x . 1) . 2)) (((ext 3) . 1) ((w_2x . 1) . 1))) . 1) nil) ((ext
38) *sq (((((ext 3) . 1) ((w . 1) . 2)) (((ext 2) . 1) . 1)) . 1) nil) ((ext 39)
*sq (((((ext 3) . 1) ((u . 1) . -1)) (((ext 1) . 1) ((w . 1) . -1))) . 1) nil) (
(ext 36) *sq (((((ext 1) . 1) . 1)) . 1) nil) ((ext 37) *sq (((((ext 3) . 1) ((w
. 1) . 1)) (((ext 2) . 1) . 1)) . 1) nil) ((ext 34) *sq (((((ext 3) . 1) . 1)) .
1) nil) ((ext 35) *sq (((((ext 1) . 1) . 1)) . 1) nil) ((ext 33) *sq (((((ext 7)
. 1) . 1)) . 1) nil) ((ext 32) *sq (((((ext 9) . 1) ((u . 1) . -1)) (((ext 7) .
1) ((w . 1) . -3)) (((ext 3) . 1) ((u_x . 1) . -3)) (((ext 1) . 1) ((w_x . 1) .
-1))) . 1) nil) ((ext 31) *sq (((((ext 9) . 1) ((w . 1) . 1)) (((ext 8) . 1) . 1
) (((ext 3) . 1) ((w_x . 1) . 1))) . 1) nil))
% Coefficients of total derivatives:
% component of ddx w.r.t. x
ddx(0,1):=1
% component of ddx w.r.t. t
ddx(0,2):=0
% component of ddx w.r.t. u
ddx(0,3):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v
ddx(0,4):=(*sq ((((v_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w
ddx(0,5):=(*sq ((((w_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x
ddx(0,6):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x
ddx(0,7):=(*sq ((((v_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_x
ddx(0,8):=(*sq ((((w_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x
ddx(0,9):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x
ddx(0,10):=(*sq ((((v_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2x
ddx(0,11):=(*sq ((((w_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x
ddx(0,12):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x
ddx(0,13):=(*sq ((((v_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_3x
ddx(0,14):=(*sq ((((w_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x
ddx(0,15):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x
ddx(0,16):=(*sq ((((v_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_4x
ddx(0,17):=(*sq ((((w_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x
ddx(0,18):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5x
ddx(0,19):=(*sq ((((v_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_5x
ddx(0,20):=(*sq ((((w_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x
ddx(0,21):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6x
ddx(0,22):=(*sq ((((v_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_6x
ddx(0,23):=(*sq ((((w_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x
ddx(0,24):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_7x
ddx(0,25):=(*sq ((((v_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_7x
ddx(0,26):=(*sq ((((w_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x
ddx(0,27):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_8x
ddx(0,28):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_8x
ddx(0,29):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t
ddx(0,30):=(*sq ((((u_xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_t
ddx(0,31):=(*sq ((((v_xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_t
ddx(0,32):=(*sq ((((w_xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,33):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_xt
ddx(0,34):=(*sq ((((u_2xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2t
ddx(0,35):=(*sq ((((v_x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_xt
ddx(0,36):=(*sq ((((v_2xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2t
ddx(0,37):=(*sq ((((w_x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_xt
ddx(0,38):=(*sq ((((w_2xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t
ddx(0,39):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x2t
ddx(0,40):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2xt
ddx(0,41):=(*sq ((((u_3xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3t
ddx(0,42):=(*sq ((((v_x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x2t
ddx(0,43):=(*sq ((((v_2x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2xt
ddx(0,44):=(*sq ((((v_3xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_3t
ddx(0,45):=(*sq ((((w_x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_x2t
ddx(0,46):=(*sq ((((w_2x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2xt
ddx(0,47):=(*sq ((((w_3xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t
ddx(0,48):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x3t
ddx(0,49):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x2t
ddx(0,50):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3xt
ddx(0,51):=(*sq ((((u_4xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4t
ddx(0,52):=(*sq ((((v_x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x3t
ddx(0,53):=(*sq ((((v_2x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x2t
ddx(0,54):=(*sq ((((v_3x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3xt
ddx(0,55):=(*sq ((((v_4xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_4t
ddx(0,56):=(*sq ((((w_x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_x3t
ddx(0,57):=(*sq ((((w_2x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2x2t
ddx(0,58):=(*sq ((((w_3x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_3xt
ddx(0,59):=(*sq ((((w_4xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t
ddx(0,60):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x4t
ddx(0,61):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x3t
ddx(0,62):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x2t
ddx(0,63):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4xt
ddx(0,64):=(*sq ((((u_5xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5t
ddx(0,65):=(*sq ((((v_x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x4t
ddx(0,66):=(*sq ((((v_2x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x3t
ddx(0,67):=(*sq ((((v_3x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x2t
ddx(0,68):=(*sq ((((v_4x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4xt
ddx(0,69):=(*sq ((((v_5xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_5t
ddx(0,70):=(*sq ((((w_x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_x4t
ddx(0,71):=(*sq ((((w_2x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2x3t
ddx(0,72):=(*sq ((((w_3x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_3x2t
ddx(0,73):=(*sq ((((w_4x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_4xt
ddx(0,74):=(*sq ((((w_5xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t
ddx(0,75):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x5t
ddx(0,76):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x4t
ddx(0,77):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x3t
ddx(0,78):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x2t
ddx(0,79):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5xt
ddx(0,80):=(*sq ((((u_6xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6t
ddx(0,81):=(*sq ((((v_x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x5t
ddx(0,82):=(*sq ((((v_2x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x4t
ddx(0,83):=(*sq ((((v_3x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x3t
ddx(0,84):=(*sq ((((v_4x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x2t
ddx(0,85):=(*sq ((((v_5x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5xt
ddx(0,86):=(*sq ((((v_6xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_6t
ddx(0,87):=(*sq ((((w_x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_x5t
ddx(0,88):=(*sq ((((w_2x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2x4t
ddx(0,89):=(*sq ((((w_3x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_3x3t
ddx(0,90):=(*sq ((((w_4x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_4x2t
ddx(0,91):=(*sq ((((w_5x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_5xt
ddx(0,92):=(*sq ((((w_6xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7t
ddx(0,93):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x6t
ddx(0,94):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x5t
ddx(0,95):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x4t
ddx(0,96):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x3t
ddx(0,97):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x2t
ddx(0,98):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6xt
ddx(0,99):=(*sq ((((u_7xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_7t
ddx(0,100):=(*sq ((((v_x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x6t
ddx(0,101):=(*sq ((((v_2x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x5t
ddx(0,102):=(*sq ((((v_3x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x4t
ddx(0,103):=(*sq ((((v_4x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x3t
ddx(0,104):=(*sq ((((v_5x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5x2t
ddx(0,105):=(*sq ((((v_6x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6xt
ddx(0,106):=(*sq ((((v_7xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_7t
ddx(0,107):=(*sq ((((w_x7t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_x6t
ddx(0,108):=(*sq ((((w_2x6t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2x5t
ddx(0,109):=(*sq ((((w_3x5t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_3x4t
ddx(0,110):=(*sq ((((w_4x4t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_4x3t
ddx(0,111):=(*sq ((((w_5x3t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_5x2t
ddx(0,112):=(*sq ((((w_6x2t . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_6xt
ddx(0,113):=(*sq ((((w_7xt . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8t
ddx(0,114):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x7t
ddx(0,115):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x6t
ddx(0,116):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x5t
ddx(0,117):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x4t
ddx(0,118):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x3t
ddx(0,119):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x2t
ddx(0,120):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7xt
ddx(0,121):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_8t
ddx(0,122):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_x7t
ddx(0,123):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_2x6t
ddx(0,124):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_3x5t
ddx(0,125):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_4x4t
ddx(0,126):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_5x3t
ddx(0,127):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_6x2t
ddx(0,128):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. v_7xt
ddx(0,129):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_8t
ddx(0,130):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_x7t
ddx(0,131):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_2x6t
ddx(0,132):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_3x5t
ddx(0,133):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_4x4t
ddx(0,134):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_5x3t
ddx(0,135):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_6x2t
ddx(0,136):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. w_7xt
ddx(0,137):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p
ddx(1,1):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q
ddx(1,2):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r
ddx(1,3):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1
ddx(1,4):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2
ddx(1,5):=(*sq (((((ext 1) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3
ddx(1,6):=(*sq (((((ext 3) . 1) ((w . 1) . 2)) (((ext 2) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x
ddx(1,7):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x
ddx(1,8):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x
ddx(1,9):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x
ddx(1,10):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x
ddx(1,11):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x
ddx(1,12):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x
ddx(1,13):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x
ddx(1,14):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x
ddx(1,15):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x
ddx(1,16):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x
ddx(1,17):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x
ddx(1,18):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x
ddx(1,19):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x
ddx(1,20):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x
ddx(1,21):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x
ddx(1,22):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x
ddx(1,23):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x
ddx(1,24):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7x
ddx(1,25):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x
ddx(1,26):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7x
ddx(1,27):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8x
ddx(1,28):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x
ddx(1,29):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_8x
ddx(1,30):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t
ddx(1,31):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_t
ddx(1,32):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_t
ddx(1,33):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x
ddx(1,34):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_t
ddx(1,35):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x
ddx(1,36):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_t
ddx(1,37):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x
ddx(1,38):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_t
ddx(1,39):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t
ddx(1,40):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_xt
ddx(1,41):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2t
ddx(1,42):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_xt
ddx(1,43):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2t
ddx(1,44):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_xt
ddx(1,45):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_xt
ddx(1,46):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x
ddx(1,47):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2t
ddx(1,48):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_xt
ddx(1,49):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_xt
ddx(1,50):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x
ddx(1,51):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2t
ddx(1,52):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_xt
ddx(1,53):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_xt
ddx(1,54):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x
ddx(1,55):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2t
ddx(1,56):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_xt
ddx(1,57):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t
ddx(1,58):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x2t
ddx(1,59):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2xt
ddx(1,60):=(*sq (((((ext 88) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3t
ddx(1,61):=(*sq (((((ext 90) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x2t
ddx(1,62):=(*sq (((((ext 91) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2xt
ddx(1,63):=(*sq (((((ext 92) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3t
ddx(1,64):=(*sq (((((ext 94) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x2t
ddx(1,65):=(*sq (((((ext 95) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2xt
ddx(1,66):=(*sq (((((ext 96) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x2t
ddx(1,67):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2xt
ddx(1,68):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x
ddx(1,69):=(*sq (((((ext 100) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3t
ddx(1,70):=(*sq (((((ext 97) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x2t
ddx(1,71):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2xt
ddx(1,72):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x2t
ddx(1,73):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2xt
ddx(1,74):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x
ddx(1,75):=(*sq (((((ext 108) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3t
ddx(1,76):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x2t
ddx(1,77):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2xt
ddx(1,78):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x2t
ddx(1,79):=(*sq (((((ext 114) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2xt
ddx(1,80):=(*sq (((((ext 115) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x
ddx(1,81):=(*sq (((((ext 116) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3t
ddx(1,82):=(*sq (((((ext 113) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x2t
ddx(1,83):=(*sq (((((ext 114) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2xt
ddx(1,84):=(*sq (((((ext 115) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t
ddx(1,85):=(*sq (((((ext 122) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x3t
ddx(1,86):=(*sq (((((ext 123) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x2t
ddx(1,87):=(*sq (((((ext 124) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3xt
ddx(1,88):=(*sq (((((ext 125) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4t
ddx(1,89):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x3t
ddx(1,90):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x2t
ddx(1,91):=(*sq (((((ext 129) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3xt
ddx(1,92):=(*sq (((((ext 130) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4t
ddx(1,93):=(*sq (((((ext 132) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x3t
ddx(1,94):=(*sq (((((ext 133) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x2t
ddx(1,95):=(*sq (((((ext 134) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3xt
ddx(1,96):=(*sq (((((ext 135) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x3t
ddx(1,97):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x2t
ddx(1,98):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3xt
ddx(1,99):=(*sq (((((ext 139) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4x
ddx(1,100):=(*sq (((((ext 140) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4t
ddx(1,101):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x3t
ddx(1,102):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x2t
ddx(1,103):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3xt
ddx(1,104):=(*sq (((((ext 139) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x3t
ddx(1,105):=(*sq (((((ext 147) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x2t
ddx(1,106):=(*sq (((((ext 148) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3xt
ddx(1,107):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4x
ddx(1,108):=(*sq (((((ext 150) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4t
ddx(1,109):=(*sq (((((ext 146) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x3t
ddx(1,110):=(*sq (((((ext 147) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x2t
ddx(1,111):=(*sq (((((ext 148) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3xt
ddx(1,112):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x3t
ddx(1,113):=(*sq (((((ext 157) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x2t
ddx(1,114):=(*sq (((((ext 158) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3xt
ddx(1,115):=(*sq (((((ext 159) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4x
ddx(1,116):=(*sq (((((ext 160) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4t
ddx(1,117):=(*sq (((((ext 156) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x3t
ddx(1,118):=(*sq (((((ext 157) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x2t
ddx(1,119):=(*sq (((((ext 158) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3xt
ddx(1,120):=(*sq (((((ext 159) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t
ddx(1,121):=(*sq (((((ext 167) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x4t
ddx(1,122):=(*sq (((((ext 168) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x3t
ddx(1,123):=(*sq (((((ext 169) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x2t
ddx(1,124):=(*sq (((((ext 170) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4xt
ddx(1,125):=(*sq (((((ext 171) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5t
ddx(1,126):=(*sq (((((ext 173) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x4t
ddx(1,127):=(*sq (((((ext 174) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x3t
ddx(1,128):=(*sq (((((ext 175) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x2t
ddx(1,129):=(*sq (((((ext 176) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4xt
ddx(1,130):=(*sq (((((ext 177) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5t
ddx(1,131):=(*sq (((((ext 179) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x4t
ddx(1,132):=(*sq (((((ext 180) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x3t
ddx(1,133):=(*sq (((((ext 181) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x2t
ddx(1,134):=(*sq (((((ext 182) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4xt
ddx(1,135):=(*sq (((((ext 183) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x4t
ddx(1,136):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x3t
ddx(1,137):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x2t
ddx(1,138):=(*sq (((((ext 187) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4xt
ddx(1,139):=(*sq (((((ext 188) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_5x
ddx(1,140):=(*sq (((((ext 189) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_5t
ddx(1,141):=(*sq (((((ext 184) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x4t
ddx(1,142):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x3t
ddx(1,143):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x2t
ddx(1,144):=(*sq (((((ext 187) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4xt
ddx(1,145):=(*sq (((((ext 188) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x4t
ddx(1,146):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x3t
ddx(1,147):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x2t
ddx(1,148):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4xt
ddx(1,149):=(*sq (((((ext 200) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_5x
ddx(1,150):=(*sq (((((ext 201) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_5t
ddx(1,151):=(*sq (((((ext 196) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x4t
ddx(1,152):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x3t
ddx(1,153):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x2t
ddx(1,154):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4xt
ddx(1,155):=(*sq (((((ext 200) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x4t
ddx(1,156):=(*sq (((((ext 209) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x3t
ddx(1,157):=(*sq (((((ext 210) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x2t
ddx(1,158):=(*sq (((((ext 211) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4xt
ddx(1,159):=(*sq (((((ext 212) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_5x
ddx(1,160):=(*sq (((((ext 213) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_5t
ddx(1,161):=(*sq (((((ext 208) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x4t
ddx(1,162):=(*sq (((((ext 209) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x3t
ddx(1,163):=(*sq (((((ext 210) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x2t
ddx(1,164):=(*sq (((((ext 211) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4xt
ddx(1,165):=(*sq (((((ext 212) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t
ddx(1,166):=(*sq (((((ext 221) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x5t
ddx(1,167):=(*sq (((((ext 222) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x4t
ddx(1,168):=(*sq (((((ext 223) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x3t
ddx(1,169):=(*sq (((((ext 224) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x2t
ddx(1,170):=(*sq (((((ext 225) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5xt
ddx(1,171):=(*sq (((((ext 226) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6t
ddx(1,172):=(*sq (((((ext 228) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x5t
ddx(1,173):=(*sq (((((ext 229) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x4t
ddx(1,174):=(*sq (((((ext 230) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x3t
ddx(1,175):=(*sq (((((ext 231) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x2t
ddx(1,176):=(*sq (((((ext 232) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5xt
ddx(1,177):=(*sq (((((ext 233) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6t
ddx(1,178):=(*sq (((((ext 235) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x5t
ddx(1,179):=(*sq (((((ext 236) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x4t
ddx(1,180):=(*sq (((((ext 237) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x3t
ddx(1,181):=(*sq (((((ext 238) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x2t
ddx(1,182):=(*sq (((((ext 239) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5xt
ddx(1,183):=(*sq (((((ext 240) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x5t
ddx(1,184):=(*sq (((((ext 242) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x4t
ddx(1,185):=(*sq (((((ext 243) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x3t
ddx(1,186):=(*sq (((((ext 244) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4x2t
ddx(1,187):=(*sq (((((ext 245) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_5xt
ddx(1,188):=(*sq (((((ext 246) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_6x
ddx(1,189):=(*sq (((((ext 247) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_6t
ddx(1,190):=(*sq (((((ext 241) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x5t
ddx(1,191):=(*sq (((((ext 242) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x4t
ddx(1,192):=(*sq (((((ext 243) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x3t
ddx(1,193):=(*sq (((((ext 244) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4x2t
ddx(1,194):=(*sq (((((ext 245) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_5xt
ddx(1,195):=(*sq (((((ext 246) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x5t
ddx(1,196):=(*sq (((((ext 256) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x4t
ddx(1,197):=(*sq (((((ext 257) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x3t
ddx(1,198):=(*sq (((((ext 258) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4x2t
ddx(1,199):=(*sq (((((ext 259) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_5xt
ddx(1,200):=(*sq (((((ext 260) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_6x
ddx(1,201):=(*sq (((((ext 261) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_6t
ddx(1,202):=(*sq (((((ext 255) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x5t
ddx(1,203):=(*sq (((((ext 256) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x4t
ddx(1,204):=(*sq (((((ext 257) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x3t
ddx(1,205):=(*sq (((((ext 258) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4x2t
ddx(1,206):=(*sq (((((ext 259) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_5xt
ddx(1,207):=(*sq (((((ext 260) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x5t
ddx(1,208):=(*sq (((((ext 270) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x4t
ddx(1,209):=(*sq (((((ext 271) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x3t
ddx(1,210):=(*sq (((((ext 272) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4x2t
ddx(1,211):=(*sq (((((ext 273) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_5xt
ddx(1,212):=(*sq (((((ext 274) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_6x
ddx(1,213):=(*sq (((((ext 275) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_6t
ddx(1,214):=(*sq (((((ext 269) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x5t
ddx(1,215):=(*sq (((((ext 270) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x4t
ddx(1,216):=(*sq (((((ext 271) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x3t
ddx(1,217):=(*sq (((((ext 272) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4x2t
ddx(1,218):=(*sq (((((ext 273) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_5xt
ddx(1,219):=(*sq (((((ext 274) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7t
ddx(1,220):=(*sq (((((ext 284) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x6t
ddx(1,221):=(*sq (((((ext 285) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x5t
ddx(1,222):=(*sq (((((ext 286) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x4t
ddx(1,223):=(*sq (((((ext 287) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x3t
ddx(1,224):=(*sq (((((ext 288) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x2t
ddx(1,225):=(*sq (((((ext 289) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6xt
ddx(1,226):=(*sq (((((ext 290) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7t
ddx(1,227):=(*sq (((((ext 292) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x6t
ddx(1,228):=(*sq (((((ext 293) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x5t
ddx(1,229):=(*sq (((((ext 294) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x4t
ddx(1,230):=(*sq (((((ext 295) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x3t
ddx(1,231):=(*sq (((((ext 296) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x2t
ddx(1,232):=(*sq (((((ext 297) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6xt
ddx(1,233):=(*sq (((((ext 298) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7t
ddx(1,234):=(*sq (((((ext 300) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x6t
ddx(1,235):=(*sq (((((ext 301) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x5t
ddx(1,236):=(*sq (((((ext 302) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x4t
ddx(1,237):=(*sq (((((ext 303) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x3t
ddx(1,238):=(*sq (((((ext 304) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x2t
ddx(1,239):=(*sq (((((ext 305) . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6xt
ddx(1,240):=(*sq (((((ext 306) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x6t
ddx(1,241):=(*sq (((((ext 308) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x5t
ddx(1,242):=(*sq (((((ext 309) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x4t
ddx(1,243):=(*sq (((((ext 310) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4x3t
ddx(1,244):=(*sq (((((ext 311) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_5x2t
ddx(1,245):=(*sq (((((ext 312) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_6xt
ddx(1,246):=(*sq (((((ext 313) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_7x
ddx(1,247):=(*sq (((((ext 314) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_7t
ddx(1,248):=(*sq (((((ext 307) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x6t
ddx(1,249):=(*sq (((((ext 308) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x5t
ddx(1,250):=(*sq (((((ext 309) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x4t
ddx(1,251):=(*sq (((((ext 310) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4x3t
ddx(1,252):=(*sq (((((ext 311) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_5x2t
ddx(1,253):=(*sq (((((ext 312) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_6xt
ddx(1,254):=(*sq (((((ext 313) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x6t
ddx(1,255):=(*sq (((((ext 317) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x5t
ddx(1,256):=(*sq (((((ext 318) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x4t
ddx(1,257):=(*sq (((((ext 319) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4x3t
ddx(1,258):=(*sq (((((ext 320) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_5x2t
ddx(1,259):=(*sq (((((ext 321) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_6xt
ddx(1,260):=(*sq (((((ext 322) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_7x
ddx(1,261):=(*sq (((((ext 323) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_7t
ddx(1,262):=(*sq (((((ext 316) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x6t
ddx(1,263):=(*sq (((((ext 317) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x5t
ddx(1,264):=(*sq (((((ext 318) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x4t
ddx(1,265):=(*sq (((((ext 319) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4x3t
ddx(1,266):=(*sq (((((ext 320) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_5x2t
ddx(1,267):=(*sq (((((ext 321) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_6xt
ddx(1,268):=(*sq (((((ext 322) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x6t
ddx(1,269):=(*sq (((((ext 326) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x5t
ddx(1,270):=(*sq (((((ext 327) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x4t
ddx(1,271):=(*sq (((((ext 328) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4x3t
ddx(1,272):=(*sq (((((ext 329) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_5x2t
ddx(1,273):=(*sq (((((ext 330) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_6xt
ddx(1,274):=(*sq (((((ext 331) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_7x
ddx(1,275):=(*sq (((((ext 332) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_7t
ddx(1,276):=(*sq (((((ext 325) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x6t
ddx(1,277):=(*sq (((((ext 326) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x5t
ddx(1,278):=(*sq (((((ext 327) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x4t
ddx(1,279):=(*sq (((((ext 328) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4x3t
ddx(1,280):=(*sq (((((ext 329) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_5x2t
ddx(1,281):=(*sq (((((ext 330) . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_6xt
ddx(1,282):=(*sq (((((ext 331) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_8t
ddx(1,283):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x7t
ddx(1,284):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x6t
ddx(1,285):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x5t
ddx(1,286):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x4t
ddx(1,287):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x3t
ddx(1,288):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x2t
ddx(1,289):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_7xt
ddx(1,290):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8t
ddx(1,291):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x7t
ddx(1,292):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x6t
ddx(1,293):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x5t
ddx(1,294):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x4t
ddx(1,295):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x3t
ddx(1,296):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x2t
ddx(1,297):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7xt
ddx(1,298):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_8t
ddx(1,299):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_x7t
ddx(1,300):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_2x6t
ddx(1,301):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_3x5t
ddx(1,302):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_4x4t
ddx(1,303):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_5x3t
ddx(1,304):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_6x2t
ddx(1,305):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. r_7xt
ddx(1,306):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_x7t
ddx(1,307):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_2x6t
ddx(1,308):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_3x5t
ddx(1,309):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_4x4t
ddx(1,310):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_5x3t
ddx(1,311):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_6x2t
ddx(1,312):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_7xt
ddx(1,313):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_8x
ddx(1,314):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o1_8t
ddx(1,315):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_x7t
ddx(1,316):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_2x6t
ddx(1,317):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_3x5t
ddx(1,318):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_4x4t
ddx(1,319):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_5x3t
ddx(1,320):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_6x2t
ddx(1,321):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_7xt
ddx(1,322):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_8x
ddx(1,323):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o2_8t
ddx(1,324):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_x7t
ddx(1,325):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_2x6t
ddx(1,326):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_3x5t
ddx(1,327):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_4x4t
ddx(1,328):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_5x3t
ddx(1,329):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_6x2t
ddx(1,330):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_7xt
ddx(1,331):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_8x
ddx(1,332):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. o3_8t
ddx(1,333):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. x
ddt(0,1):=0
% component of ddt w.r.t. t
ddt(0,2):=1
% component of ddt w.r.t. u
ddt(0,3):=(*sq ((((v_x . 1) . 1) ((w . 1) ((w_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. v
ddt(0,4):=(*sq ((((u . 1) ((w_x . 1) . -1)) ((u_x . 1) ((w . 1) . -3))) . 1) t)
% component of ddt w.r.t. w
ddt(0,5):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,6):=(*sq ((((v_2x . 1) . 1) ((w . 1) ((w_2x . 1) . 1)) ((w_x . 2) . 1)) .
1) t)
% component of ddt w.r.t. v_x
ddt(0,7):=(*sq ((((u . 1) ((w_2x . 1) . -1)) ((u_2x . 1) ((w . 1) . -3)) ((u_x .
1) ((w_x . 1) . -4))) . 1) t)
% component of ddt w.r.t. w_x
ddt(0,8):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x
ddt(0,9):=(*sq ((((v_3x . 1) . 1) ((w . 1) ((w_3x . 1) . 1)) ((w_2x . 1) ((w_x .
1) . 3))) . 1) t)
% component of ddt w.r.t. v_2x
ddt(0,10):=(*sq ((((u . 1) ((w_3x . 1) . -1)) ((u_2x . 1) ((w_x . 1) . -7)) ((
u_3x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_2x . 1) . -5))) . 1) t)
% component of ddt w.r.t. w_2x
ddt(0,11):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,12):=(*sq ((((v_4x . 1) . 1) ((w . 1) ((w_4x . 1) . 1)) ((w_2x . 2) . 3) (
(w_3x . 1) ((w_x . 1) . 4))) . 1) t)
% component of ddt w.r.t. v_3x
ddt(0,13):=(*sq ((((u . 1) ((w_4x . 1) . -1)) ((u_2x . 1) ((w_2x . 1) . -12)) ((
u_3x . 1) ((w_x . 1) . -10)) ((u_4x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_3x . 1)
. -6))) . 1) t)
% component of ddt w.r.t. w_3x
ddt(0,14):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,15):=(*sq ((((v_5x . 1) . 1) ((w . 1) ((w_5x . 1) . 1)) ((w_2x . 1) ((w_3x
. 1) . 10)) ((w_4x . 1) ((w_x . 1) . 5))) . 1) t)
% component of ddt w.r.t. v_4x
ddt(0,16):=(*sq ((((u . 1) ((w_5x . 1) . -1)) ((u_2x . 1) ((w_3x . 1) . -18)) ((
u_3x . 1) ((w_2x . 1) . -22)) ((u_4x . 1) ((w_x . 1) . -13)) ((u_5x . 1) ((w . 1
) . -3)) ((u_x . 1) ((w_4x . 1) . -7))) . 1) t)
% component of ddt w.r.t. w_4x
ddt(0,17):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,18):=(*sq ((((v_6x . 1) . 1) ((w . 1) ((w_6x . 1) . 1)) ((w_2x . 1) ((w_4x
. 1) . 15)) ((w_3x . 2) . 10) ((w_5x . 1) ((w_x . 1) . 6))) . 1) t)
% component of ddt w.r.t. v_5x
ddt(0,19):=(*sq ((((u . 1) ((w_6x . 1) . -1)) ((u_2x . 1) ((w_4x . 1) . -25)) ((
u_3x . 1) ((w_3x . 1) . -40)) ((u_4x . 1) ((w_2x . 1) . -35)) ((u_5x . 1) ((w_x
. 1) . -16)) ((u_6x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_5x . 1) . -8))) . 1) t)
% component of ddt w.r.t. w_5x
ddt(0,20):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,21):=(*sq ((((v_7x . 1) . 1) ((w . 1) ((w_7x . 1) . 1)) ((w_2x . 1) ((w_5x
. 1) . 21)) ((w_3x . 1) ((w_4x . 1) . 35)) ((w_6x . 1) ((w_x . 1) . 7))) . 1) t)
% component of ddt w.r.t. v_6x
ddt(0,22):=(*sq ((((u . 1) ((w_7x . 1) . -1)) ((u_2x . 1) ((w_5x . 1) . -33)) ((
u_3x . 1) ((w_4x . 1) . -65)) ((u_4x . 1) ((w_3x . 1) . -75)) ((u_5x . 1) ((w_2x
. 1) . -51)) ((u_6x . 1) ((w_x . 1) . -19)) ((u_7x . 1) ((w . 1) . -3)) ((u_x .
1) ((w_6x . 1) . -9))) . 1) t)
% component of ddt w.r.t. w_6x
ddt(0,23):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7x
ddt(0,24):=(*sq ((((v_8x . 1) . 1) ((w . 1) ((w_8x . 1) . 1)) ((w_2x . 1) ((w_6x
. 1) . 28)) ((w_3x . 1) ((w_5x . 1) . 56)) ((w_4x . 2) . 35) ((w_7x . 1) ((w_x .
1) . 8))) . 1) t)
% component of ddt w.r.t. v_7x
ddt(0,25):=(*sq ((((u . 1) ((w_8x . 1) . -1)) ((u_2x . 1) ((w_6x . 1) . -42)) ((
u_3x . 1) ((w_5x . 1) . -98)) ((u_4x . 1) ((w_4x . 1) . -140)) ((u_5x . 1) ((
w_3x . 1) . -126)) ((u_6x . 1) ((w_2x . 1) . -70)) ((u_7x . 1) ((w_x . 1) . -22)
) ((u_8x . 1) ((w . 1) . -3)) ((u_x . 1) ((w_7x . 1) . -10))) . 1) t)
% component of ddt w.r.t. w_7x
ddt(0,26):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8x
ddt(0,27):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_8x
ddt(0,28):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_8x
ddt(0,29):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,30):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_t
ddt(0,31):=(*sq ((((v_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_t
ddt(0,32):=(*sq ((((w_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,33):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_xt
ddt(0,34):=(*sq ((((u_x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2t
ddt(0,35):=(*sq ((((v_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_xt
ddt(0,36):=(*sq ((((v_x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_2t
ddt(0,37):=(*sq ((((w_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_xt
ddt(0,38):=(*sq ((((w_x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,39):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x2t
ddt(0,40):=(*sq ((((u_x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2xt
ddt(0,41):=(*sq ((((u_2x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3t
ddt(0,42):=(*sq ((((v_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x2t
ddt(0,43):=(*sq ((((v_x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2xt
ddt(0,44):=(*sq ((((v_2x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_3t
ddt(0,45):=(*sq ((((w_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_x2t
ddt(0,46):=(*sq ((((w_x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_2xt
ddt(0,47):=(*sq ((((w_2x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,48):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x3t
ddt(0,49):=(*sq ((((u_x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x2t
ddt(0,50):=(*sq ((((u_2x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3xt
ddt(0,51):=(*sq ((((u_3x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4t
ddt(0,52):=(*sq ((((v_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x3t
ddt(0,53):=(*sq ((((v_x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x2t
ddt(0,54):=(*sq ((((v_2x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3xt
ddt(0,55):=(*sq ((((v_3x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_4t
ddt(0,56):=(*sq ((((w_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_x3t
ddt(0,57):=(*sq ((((w_x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_2x2t
ddt(0,58):=(*sq ((((w_2x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_3xt
ddt(0,59):=(*sq ((((w_3x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,60):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x4t
ddt(0,61):=(*sq ((((u_x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x3t
ddt(0,62):=(*sq ((((u_2x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x2t
ddt(0,63):=(*sq ((((u_3x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4xt
ddt(0,64):=(*sq ((((u_4x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5t
ddt(0,65):=(*sq ((((v_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x4t
ddt(0,66):=(*sq ((((v_x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x3t
ddt(0,67):=(*sq ((((v_2x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x2t
ddt(0,68):=(*sq ((((v_3x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4xt
ddt(0,69):=(*sq ((((v_4x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_5t
ddt(0,70):=(*sq ((((w_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_x4t
ddt(0,71):=(*sq ((((w_x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_2x3t
ddt(0,72):=(*sq ((((w_2x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_3x2t
ddt(0,73):=(*sq ((((w_3x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_4xt
ddt(0,74):=(*sq ((((w_4x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,75):=(*sq ((((u_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x5t
ddt(0,76):=(*sq ((((u_x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x4t
ddt(0,77):=(*sq ((((u_2x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x3t
ddt(0,78):=(*sq ((((u_3x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x2t
ddt(0,79):=(*sq ((((u_4x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5xt
ddt(0,80):=(*sq ((((u_5x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_6t
ddt(0,81):=(*sq ((((v_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x5t
ddt(0,82):=(*sq ((((v_x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x4t
ddt(0,83):=(*sq ((((v_2x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x3t
ddt(0,84):=(*sq ((((v_3x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4x2t
ddt(0,85):=(*sq ((((v_4x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5xt
ddt(0,86):=(*sq ((((v_5x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_6t
ddt(0,87):=(*sq ((((w_7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_x5t
ddt(0,88):=(*sq ((((w_x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_2x4t
ddt(0,89):=(*sq ((((w_2x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_3x3t
ddt(0,90):=(*sq ((((w_3x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_4x2t
ddt(0,91):=(*sq ((((w_4x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_5xt
ddt(0,92):=(*sq ((((w_5x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7t
ddt(0,93):=(*sq ((((u_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x6t
ddt(0,94):=(*sq ((((u_x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x5t
ddt(0,95):=(*sq ((((u_2x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x4t
ddt(0,96):=(*sq ((((u_3x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x3t
ddt(0,97):=(*sq ((((u_4x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x2t
ddt(0,98):=(*sq ((((u_5x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6xt
ddt(0,99):=(*sq ((((u_6x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_7t
ddt(0,100):=(*sq ((((v_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x6t
ddt(0,101):=(*sq ((((v_x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x5t
ddt(0,102):=(*sq ((((v_2x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x4t
ddt(0,103):=(*sq ((((v_3x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4x3t
ddt(0,104):=(*sq ((((v_4x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5x2t
ddt(0,105):=(*sq ((((v_5x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_6xt
ddt(0,106):=(*sq ((((v_6x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_7t
ddt(0,107):=(*sq ((((w_8t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_x6t
ddt(0,108):=(*sq ((((w_x7t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_2x5t
ddt(0,109):=(*sq ((((w_2x6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_3x4t
ddt(0,110):=(*sq ((((w_3x5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_4x3t
ddt(0,111):=(*sq ((((w_4x4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_5x2t
ddt(0,112):=(*sq ((((w_5x3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_6xt
ddt(0,113):=(*sq ((((w_6x2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_8t
ddt(0,114):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x7t
ddt(0,115):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x6t
ddt(0,116):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x5t
ddt(0,117):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x4t
ddt(0,118):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x3t
ddt(0,119):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x2t
ddt(0,120):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_7xt
ddt(0,121):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_8t
ddt(0,122):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_x7t
ddt(0,123):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_2x6t
ddt(0,124):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_3x5t
ddt(0,125):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_4x4t
ddt(0,126):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_5x3t
ddt(0,127):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_6x2t
ddt(0,128):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. v_7xt
ddt(0,129):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_8t
ddt(0,130):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_x7t
ddt(0,131):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_2x6t
ddt(0,132):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_3x5t
ddt(0,133):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_4x4t
ddt(0,134):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_5x3t
ddt(0,135):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_6x2t
ddt(0,136):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. w_7xt
ddt(0,137):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p
ddt(1,1):=(*sq (((((ext 9) . 1) ((w . 1) . 1)) (((ext 8) . 1) . 1) (((ext 3) . 1
) ((w_x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q
ddt(1,2):=(*sq (((((ext 9) . 1) ((u . 1) . -1)) (((ext 7) . 1) ((w . 1) . -3)) (
((ext 3) . 1) ((u_x . 1) . -3)) (((ext 1) . 1) ((w_x . 1) . -1))) . 1) t)
% component of ddt w.r.t. r
ddt(1,3):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1
ddt(1,4):=(*sq (((((ext 1) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2
ddt(1,5):=(*sq (((((ext 3) . 1) ((w . 1) . 1)) (((ext 2) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3
ddt(1,6):=(*sq (((((ext 3) . 1) ((u . 1) . -1)) (((ext 1) . 1) ((w . 1) . -1)))
. 1) t)
% component of ddt w.r.t. p_x
ddt(1,7):=(*sq (((((ext 12) . 1) ((w . 1) . 1)) (((ext 11) . 1) . 1) (((ext 9) .
1) ((w_x . 1) . 2)) (((ext 3) . 1) ((w_2x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_x
ddt(1,8):=(*sq (((((ext 12) . 1) ((u . 1) . -1)) (((ext 10) . 1) ((w . 1) . -3))
(((ext 9) . 1) ((u_x . 1) . -4)) (((ext 7) . 1) ((w_x . 1) . -4)) (((ext 3) . 1)
((u_2x . 1) . -3)) (((ext 1) . 1) ((w_2x . 1) . -1))) . 1) t)
% component of ddt w.r.t. r_x
ddt(1,9):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x
ddt(1,10):=(*sq (((((ext 15) . 1) ((w . 1) . 1)) (((ext 14) . 1) . 1) (((ext 12)
. 1) ((w_x . 1) . 3)) (((ext 9) . 1) ((w_2x . 1) . 3)) (((ext 3) . 1) ((w_3x . 1
) . 1))) . 1) t)
% component of ddt w.r.t. q_2x
ddt(1,11):=(*sq (((((ext 15) . 1) ((u . 1) . -1)) (((ext 13) . 1) ((w . 1) . -3)
) (((ext 12) . 1) ((u_x . 1) . -5)) (((ext 10) . 1) ((w_x . 1) . -7)) (((ext 9)
. 1) ((u_2x . 1) . -7)) (((ext 7) . 1) ((w_2x . 1) . -5)) (((ext 3) . 1) ((u_3x
. 1) . -3)) (((ext 1) . 1) ((w_3x . 1) . -1))) . 1) t)
% component of ddt w.r.t. r_2x
ddt(1,12):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x
ddt(1,13):=(*sq (((((ext 18) . 1) ((w . 1) . 1)) (((ext 17) . 1) . 1) (((ext 15)
. 1) ((w_x . 1) . 4)) (((ext 12) . 1) ((w_2x . 1) . 6)) (((ext 9) . 1) ((w_3x .
1) . 4)) (((ext 3) . 1) ((w_4x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_3x
ddt(1,14):=(*sq (((((ext 18) . 1) ((u . 1) . -1)) (((ext 16) . 1) ((w . 1) . -3)
) (((ext 15) . 1) ((u_x . 1) . -6)) (((ext 13) . 1) ((w_x . 1) . -10)) (((ext 12
) . 1) ((u_2x . 1) . -12)) (((ext 10) . 1) ((w_2x . 1) . -12)) (((ext 9) . 1) ((
u_3x . 1) . -10)) (((ext 7) . 1) ((w_3x . 1) . -6)) (((ext 3) . 1) ((u_4x . 1) .
-3)) (((ext 1) . 1) ((w_4x . 1) . -1))) . 1) t)
% component of ddt w.r.t. r_3x
ddt(1,15):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x
ddt(1,16):=(*sq (((((ext 21) . 1) ((w . 1) . 1)) (((ext 20) . 1) . 1) (((ext 18)
. 1) ((w_x . 1) . 5)) (((ext 15) . 1) ((w_2x . 1) . 10)) (((ext 12) . 1) ((w_3x
. 1) . 10)) (((ext 9) . 1) ((w_4x . 1) . 5)) (((ext 3) . 1) ((w_5x . 1) . 1))) .
1) t)
% component of ddt w.r.t. q_4x
ddt(1,17):=(*sq (((((ext 21) . 1) ((u . 1) . -1)) (((ext 19) . 1) ((w . 1) . -3)
) (((ext 18) . 1) ((u_x . 1) . -7)) (((ext 16) . 1) ((w_x . 1) . -13)) (((ext 15
) . 1) ((u_2x . 1) . -18)) (((ext 13) . 1) ((w_2x . 1) . -22)) (((ext 12) . 1) (
(u_3x . 1) . -22)) (((ext 10) . 1) ((w_3x . 1) . -18)) (((ext 9) . 1) ((u_4x . 1
) . -13)) (((ext 7) . 1) ((w_4x . 1) . -7)) (((ext 3) . 1) ((u_5x . 1) . -3)) ((
(ext 1) . 1) ((w_5x . 1) . -1))) . 1) t)
% component of ddt w.r.t. r_4x
ddt(1,18):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x
ddt(1,19):=(*sq (((((ext 24) . 1) ((w . 1) . 1)) (((ext 23) . 1) . 1) (((ext 21)
. 1) ((w_x . 1) . 6)) (((ext 18) . 1) ((w_2x . 1) . 15)) (((ext 15) . 1) ((w_3x
. 1) . 20)) (((ext 12) . 1) ((w_4x . 1) . 15)) (((ext 9) . 1) ((w_5x . 1) . 6))
(((ext 3) . 1) ((w_6x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_5x
ddt(1,20):=(*sq (((((ext 24) . 1) ((u . 1) . -1)) (((ext 22) . 1) ((w . 1) . -3)
) (((ext 21) . 1) ((u_x . 1) . -8)) (((ext 19) . 1) ((w_x . 1) . -16)) (((ext 18
) . 1) ((u_2x . 1) . -25)) (((ext 16) . 1) ((w_2x . 1) . -35)) (((ext 15) . 1) (
(u_3x . 1) . -40)) (((ext 13) . 1) ((w_3x . 1) . -40)) (((ext 12) . 1) ((u_4x .
1) . -35)) (((ext 10) . 1) ((w_4x . 1) . -25)) (((ext 9) . 1) ((u_5x . 1) . -16)
) (((ext 7) . 1) ((w_5x . 1) . -8)) (((ext 3) . 1) ((u_6x . 1) . -3)) (((ext 1)
. 1) ((w_6x . 1) . -1))) . 1) t)
% component of ddt w.r.t. r_5x
ddt(1,21):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x
ddt(1,22):=(*sq (((((ext 27) . 1) ((w . 1) . 1)) (((ext 26) . 1) . 1) (((ext 24)
. 1) ((w_x . 1) . 7)) (((ext 21) . 1) ((w_2x . 1) . 21)) (((ext 18) . 1) ((w_3x
. 1) . 35)) (((ext 15) . 1) ((w_4x . 1) . 35)) (((ext 12) . 1) ((w_5x . 1) . 21)
) (((ext 9) . 1) ((w_6x . 1) . 7)) (((ext 3) . 1) ((w_7x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_6x
ddt(1,23):=(*sq (((((ext 27) . 1) ((u . 1) . -1)) (((ext 25) . 1) ((w . 1) . -3)
) (((ext 24) . 1) ((u_x . 1) . -9)) (((ext 22) . 1) ((w_x . 1) . -19)) (((ext 21
) . 1) ((u_2x . 1) . -33)) (((ext 19) . 1) ((w_2x . 1) . -51)) (((ext 18) . 1) (
(u_3x . 1) . -65)) (((ext 16) . 1) ((w_3x . 1) . -75)) (((ext 15) . 1) ((u_4x .
1) . -75)) (((ext 13) . 1) ((w_4x . 1) . -65)) (((ext 12) . 1) ((u_5x . 1) . -51
)) (((ext 10) . 1) ((w_5x . 1) . -33)) (((ext 9) . 1) ((u_6x . 1) . -19)) (((ext
7) . 1) ((w_6x . 1) . -9)) (((ext 3) . 1) ((u_7x . 1) . -3)) (((ext 1) . 1) ((
w_7x . 1) . -1))) . 1) t)
% component of ddt w.r.t. r_6x
ddt(1,24):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7x
ddt(1,25):=(*sq (((((ext 30) . 1) ((w . 1) . 1)) (((ext 29) . 1) . 1) (((ext 27)
. 1) ((w_x . 1) . 8)) (((ext 24) . 1) ((w_2x . 1) . 28)) (((ext 21) . 1) ((w_3x
. 1) . 56)) (((ext 18) . 1) ((w_4x . 1) . 70)) (((ext 15) . 1) ((w_5x . 1) . 56)
) (((ext 12) . 1) ((w_6x . 1) . 28)) (((ext 9) . 1) ((w_7x . 1) . 8)) (((ext 3)
. 1) ((w_8x . 1) . 1))) . 1) t)
% component of ddt w.r.t. q_7x
ddt(1,26):=(*sq (((((ext 30) . 1) ((u . 1) . -1)) (((ext 28) . 1) ((w . 1) . -3)
) (((ext 27) . 1) ((u_x . 1) . -10)) (((ext 25) . 1) ((w_x . 1) . -22)) (((ext
24) . 1) ((u_2x . 1) . -42)) (((ext 22) . 1) ((w_2x . 1) . -70)) (((ext 21) . 1)
((u_3x . 1) . -98)) (((ext 19) . 1) ((w_3x . 1) . -126)) (((ext 18) . 1) ((u_4x
. 1) . -140)) (((ext 16) . 1) ((w_4x . 1) . -140)) (((ext 15) . 1) ((u_5x . 1) .
-126)) (((ext 13) . 1) ((w_5x . 1) . -98)) (((ext 12) . 1) ((u_6x . 1) . -70)) (
((ext 10) . 1) ((w_6x . 1) . -42)) (((ext 9) . 1) ((u_7x . 1) . -22)) (((ext 7)
. 1) ((w_7x . 1) . -10)) (((ext 3) . 1) ((u_8x . 1) . -3)) (((ext 1) . 1) ((w_8x
. 1) . -1))) . 1) t)
% component of ddt w.r.t. r_7x
ddt(1,27):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8x
ddt(1,28):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8x
ddt(1,29):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_8x
ddt(1,30):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t
ddt(1,31):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_t
ddt(1,32):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_t
ddt(1,33):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x
ddt(1,34):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_t
ddt(1,35):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x
ddt(1,36):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_t
ddt(1,37):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x
ddt(1,38):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_t
ddt(1,39):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t
ddt(1,40):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_xt
ddt(1,41):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2t
ddt(1,42):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_xt
ddt(1,43):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2t
ddt(1,44):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_xt
ddt(1,45):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_xt
ddt(1,46):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x
ddt(1,47):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2t
ddt(1,48):=(*sq (((((ext 70) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_xt
ddt(1,49):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_xt
ddt(1,50):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x
ddt(1,51):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2t
ddt(1,52):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_xt
ddt(1,53):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_xt
ddt(1,54):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x
ddt(1,55):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2t
ddt(1,56):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_xt
ddt(1,57):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t
ddt(1,58):=(*sq (((((ext 85) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x2t
ddt(1,59):=(*sq (((((ext 86) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2xt
ddt(1,60):=(*sq (((((ext 87) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3t
ddt(1,61):=(*sq (((((ext 89) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x2t
ddt(1,62):=(*sq (((((ext 90) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2xt
ddt(1,63):=(*sq (((((ext 91) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3t
ddt(1,64):=(*sq (((((ext 93) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x2t
ddt(1,65):=(*sq (((((ext 94) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2xt
ddt(1,66):=(*sq (((((ext 95) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x2t
ddt(1,67):=(*sq (((((ext 97) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2xt
ddt(1,68):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x
ddt(1,69):=(*sq (((((ext 99) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3t
ddt(1,70):=(*sq (((((ext 101) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x2t
ddt(1,71):=(*sq (((((ext 97) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2xt
ddt(1,72):=(*sq (((((ext 98) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x2t
ddt(1,73):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2xt
ddt(1,74):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x
ddt(1,75):=(*sq (((((ext 107) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3t
ddt(1,76):=(*sq (((((ext 109) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x2t
ddt(1,77):=(*sq (((((ext 105) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2xt
ddt(1,78):=(*sq (((((ext 106) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x2t
ddt(1,79):=(*sq (((((ext 113) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2xt
ddt(1,80):=(*sq (((((ext 114) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x
ddt(1,81):=(*sq (((((ext 115) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3t
ddt(1,82):=(*sq (((((ext 117) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x2t
ddt(1,83):=(*sq (((((ext 113) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2xt
ddt(1,84):=(*sq (((((ext 114) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t
ddt(1,85):=(*sq (((((ext 121) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x3t
ddt(1,86):=(*sq (((((ext 122) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x2t
ddt(1,87):=(*sq (((((ext 123) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3xt
ddt(1,88):=(*sq (((((ext 124) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4t
ddt(1,89):=(*sq (((((ext 126) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x3t
ddt(1,90):=(*sq (((((ext 127) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x2t
ddt(1,91):=(*sq (((((ext 128) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3xt
ddt(1,92):=(*sq (((((ext 129) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4t
ddt(1,93):=(*sq (((((ext 131) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x3t
ddt(1,94):=(*sq (((((ext 132) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x2t
ddt(1,95):=(*sq (((((ext 133) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3xt
ddt(1,96):=(*sq (((((ext 134) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x3t
ddt(1,97):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x2t
ddt(1,98):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3xt
ddt(1,99):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4x
ddt(1,100):=(*sq (((((ext 139) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4t
ddt(1,101):=(*sq (((((ext 141) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x3t
ddt(1,102):=(*sq (((((ext 136) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x2t
ddt(1,103):=(*sq (((((ext 137) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3xt
ddt(1,104):=(*sq (((((ext 138) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x3t
ddt(1,105):=(*sq (((((ext 146) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x2t
ddt(1,106):=(*sq (((((ext 147) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3xt
ddt(1,107):=(*sq (((((ext 148) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4x
ddt(1,108):=(*sq (((((ext 149) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4t
ddt(1,109):=(*sq (((((ext 151) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x3t
ddt(1,110):=(*sq (((((ext 146) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x2t
ddt(1,111):=(*sq (((((ext 147) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3xt
ddt(1,112):=(*sq (((((ext 148) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x3t
ddt(1,113):=(*sq (((((ext 156) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x2t
ddt(1,114):=(*sq (((((ext 157) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3xt
ddt(1,115):=(*sq (((((ext 158) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4x
ddt(1,116):=(*sq (((((ext 159) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4t
ddt(1,117):=(*sq (((((ext 161) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x3t
ddt(1,118):=(*sq (((((ext 156) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x2t
ddt(1,119):=(*sq (((((ext 157) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3xt
ddt(1,120):=(*sq (((((ext 158) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t
ddt(1,121):=(*sq (((((ext 166) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x4t
ddt(1,122):=(*sq (((((ext 167) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x3t
ddt(1,123):=(*sq (((((ext 168) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x2t
ddt(1,124):=(*sq (((((ext 169) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4xt
ddt(1,125):=(*sq (((((ext 170) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5t
ddt(1,126):=(*sq (((((ext 172) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x4t
ddt(1,127):=(*sq (((((ext 173) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x3t
ddt(1,128):=(*sq (((((ext 174) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x2t
ddt(1,129):=(*sq (((((ext 175) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4xt
ddt(1,130):=(*sq (((((ext 176) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5t
ddt(1,131):=(*sq (((((ext 178) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x4t
ddt(1,132):=(*sq (((((ext 179) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x3t
ddt(1,133):=(*sq (((((ext 180) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x2t
ddt(1,134):=(*sq (((((ext 181) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4xt
ddt(1,135):=(*sq (((((ext 182) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x4t
ddt(1,136):=(*sq (((((ext 184) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x3t
ddt(1,137):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x2t
ddt(1,138):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4xt
ddt(1,139):=(*sq (((((ext 187) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_5x
ddt(1,140):=(*sq (((((ext 188) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_5t
ddt(1,141):=(*sq (((((ext 190) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x4t
ddt(1,142):=(*sq (((((ext 184) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x3t
ddt(1,143):=(*sq (((((ext 185) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x2t
ddt(1,144):=(*sq (((((ext 186) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4xt
ddt(1,145):=(*sq (((((ext 187) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x4t
ddt(1,146):=(*sq (((((ext 196) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x3t
ddt(1,147):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x2t
ddt(1,148):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4xt
ddt(1,149):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_5x
ddt(1,150):=(*sq (((((ext 200) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_5t
ddt(1,151):=(*sq (((((ext 202) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x4t
ddt(1,152):=(*sq (((((ext 196) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x3t
ddt(1,153):=(*sq (((((ext 197) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x2t
ddt(1,154):=(*sq (((((ext 198) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4xt
ddt(1,155):=(*sq (((((ext 199) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x4t
ddt(1,156):=(*sq (((((ext 208) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x3t
ddt(1,157):=(*sq (((((ext 209) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x2t
ddt(1,158):=(*sq (((((ext 210) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4xt
ddt(1,159):=(*sq (((((ext 211) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_5x
ddt(1,160):=(*sq (((((ext 212) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_5t
ddt(1,161):=(*sq (((((ext 214) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x4t
ddt(1,162):=(*sq (((((ext 208) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x3t
ddt(1,163):=(*sq (((((ext 209) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x2t
ddt(1,164):=(*sq (((((ext 210) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4xt
ddt(1,165):=(*sq (((((ext 211) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t
ddt(1,166):=(*sq (((((ext 220) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x5t
ddt(1,167):=(*sq (((((ext 221) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x4t
ddt(1,168):=(*sq (((((ext 222) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x3t
ddt(1,169):=(*sq (((((ext 223) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x2t
ddt(1,170):=(*sq (((((ext 224) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5xt
ddt(1,171):=(*sq (((((ext 225) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6t
ddt(1,172):=(*sq (((((ext 227) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x5t
ddt(1,173):=(*sq (((((ext 228) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x4t
ddt(1,174):=(*sq (((((ext 229) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x3t
ddt(1,175):=(*sq (((((ext 230) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x2t
ddt(1,176):=(*sq (((((ext 231) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5xt
ddt(1,177):=(*sq (((((ext 232) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6t
ddt(1,178):=(*sq (((((ext 234) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x5t
ddt(1,179):=(*sq (((((ext 235) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x4t
ddt(1,180):=(*sq (((((ext 236) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x3t
ddt(1,181):=(*sq (((((ext 237) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x2t
ddt(1,182):=(*sq (((((ext 238) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5xt
ddt(1,183):=(*sq (((((ext 239) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x5t
ddt(1,184):=(*sq (((((ext 241) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x4t
ddt(1,185):=(*sq (((((ext 242) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x3t
ddt(1,186):=(*sq (((((ext 243) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4x2t
ddt(1,187):=(*sq (((((ext 244) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_5xt
ddt(1,188):=(*sq (((((ext 245) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_6x
ddt(1,189):=(*sq (((((ext 246) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_6t
ddt(1,190):=(*sq (((((ext 248) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x5t
ddt(1,191):=(*sq (((((ext 241) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x4t
ddt(1,192):=(*sq (((((ext 242) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x3t
ddt(1,193):=(*sq (((((ext 243) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4x2t
ddt(1,194):=(*sq (((((ext 244) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_5xt
ddt(1,195):=(*sq (((((ext 245) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x5t
ddt(1,196):=(*sq (((((ext 255) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x4t
ddt(1,197):=(*sq (((((ext 256) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x3t
ddt(1,198):=(*sq (((((ext 257) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4x2t
ddt(1,199):=(*sq (((((ext 258) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_5xt
ddt(1,200):=(*sq (((((ext 259) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_6x
ddt(1,201):=(*sq (((((ext 260) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_6t
ddt(1,202):=(*sq (((((ext 262) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x5t
ddt(1,203):=(*sq (((((ext 255) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x4t
ddt(1,204):=(*sq (((((ext 256) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x3t
ddt(1,205):=(*sq (((((ext 257) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4x2t
ddt(1,206):=(*sq (((((ext 258) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_5xt
ddt(1,207):=(*sq (((((ext 259) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x5t
ddt(1,208):=(*sq (((((ext 269) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x4t
ddt(1,209):=(*sq (((((ext 270) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x3t
ddt(1,210):=(*sq (((((ext 271) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4x2t
ddt(1,211):=(*sq (((((ext 272) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_5xt
ddt(1,212):=(*sq (((((ext 273) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_6x
ddt(1,213):=(*sq (((((ext 274) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_6t
ddt(1,214):=(*sq (((((ext 276) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x5t
ddt(1,215):=(*sq (((((ext 269) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x4t
ddt(1,216):=(*sq (((((ext 270) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x3t
ddt(1,217):=(*sq (((((ext 271) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4x2t
ddt(1,218):=(*sq (((((ext 272) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_5xt
ddt(1,219):=(*sq (((((ext 273) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7t
ddt(1,220):=(*sq (((((ext 283) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x6t
ddt(1,221):=(*sq (((((ext 284) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x5t
ddt(1,222):=(*sq (((((ext 285) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x4t
ddt(1,223):=(*sq (((((ext 286) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x3t
ddt(1,224):=(*sq (((((ext 287) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x2t
ddt(1,225):=(*sq (((((ext 288) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6xt
ddt(1,226):=(*sq (((((ext 289) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7t
ddt(1,227):=(*sq (((((ext 291) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x6t
ddt(1,228):=(*sq (((((ext 292) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x5t
ddt(1,229):=(*sq (((((ext 293) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x4t
ddt(1,230):=(*sq (((((ext 294) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x3t
ddt(1,231):=(*sq (((((ext 295) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x2t
ddt(1,232):=(*sq (((((ext 296) . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6xt
ddt(1,233):=(*sq (((((ext 297) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7t
ddt(1,234):=(*sq (((((ext 299) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x6t
ddt(1,235):=(*sq (((((ext 300) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x5t
ddt(1,236):=(*sq (((((ext 301) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x4t
ddt(1,237):=(*sq (((((ext 302) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x3t
ddt(1,238):=(*sq (((((ext 303) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x2t
ddt(1,239):=(*sq (((((ext 304) . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6xt
ddt(1,240):=(*sq (((((ext 305) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x6t
ddt(1,241):=(*sq (((((ext 307) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x5t
ddt(1,242):=(*sq (((((ext 308) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x4t
ddt(1,243):=(*sq (((((ext 309) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4x3t
ddt(1,244):=(*sq (((((ext 310) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_5x2t
ddt(1,245):=(*sq (((((ext 311) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_6xt
ddt(1,246):=(*sq (((((ext 312) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_7x
ddt(1,247):=(*sq (((((ext 313) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_7t
ddt(1,248):=(*sq (((((ext 315) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x6t
ddt(1,249):=(*sq (((((ext 307) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x5t
ddt(1,250):=(*sq (((((ext 308) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x4t
ddt(1,251):=(*sq (((((ext 309) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4x3t
ddt(1,252):=(*sq (((((ext 310) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_5x2t
ddt(1,253):=(*sq (((((ext 311) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_6xt
ddt(1,254):=(*sq (((((ext 312) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x6t
ddt(1,255):=(*sq (((((ext 316) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x5t
ddt(1,256):=(*sq (((((ext 317) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x4t
ddt(1,257):=(*sq (((((ext 318) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4x3t
ddt(1,258):=(*sq (((((ext 319) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_5x2t
ddt(1,259):=(*sq (((((ext 320) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_6xt
ddt(1,260):=(*sq (((((ext 321) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_7x
ddt(1,261):=(*sq (((((ext 322) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_7t
ddt(1,262):=(*sq (((((ext 324) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x6t
ddt(1,263):=(*sq (((((ext 316) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x5t
ddt(1,264):=(*sq (((((ext 317) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x4t
ddt(1,265):=(*sq (((((ext 318) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4x3t
ddt(1,266):=(*sq (((((ext 319) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_5x2t
ddt(1,267):=(*sq (((((ext 320) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_6xt
ddt(1,268):=(*sq (((((ext 321) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x6t
ddt(1,269):=(*sq (((((ext 325) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x5t
ddt(1,270):=(*sq (((((ext 326) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x4t
ddt(1,271):=(*sq (((((ext 327) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4x3t
ddt(1,272):=(*sq (((((ext 328) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_5x2t
ddt(1,273):=(*sq (((((ext 329) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_6xt
ddt(1,274):=(*sq (((((ext 330) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_7x
ddt(1,275):=(*sq (((((ext 331) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_7t
ddt(1,276):=(*sq (((((ext 333) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x6t
ddt(1,277):=(*sq (((((ext 325) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x5t
ddt(1,278):=(*sq (((((ext 326) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x4t
ddt(1,279):=(*sq (((((ext 327) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4x3t
ddt(1,280):=(*sq (((((ext 328) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_5x2t
ddt(1,281):=(*sq (((((ext 329) . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_6xt
ddt(1,282):=(*sq (((((ext 330) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_8t
ddt(1,283):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x7t
ddt(1,284):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x6t
ddt(1,285):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x5t
ddt(1,286):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x4t
ddt(1,287):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x3t
ddt(1,288):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x2t
ddt(1,289):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_7xt
ddt(1,290):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_8t
ddt(1,291):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_x7t
ddt(1,292):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_2x6t
ddt(1,293):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_3x5t
ddt(1,294):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_4x4t
ddt(1,295):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_5x3t
ddt(1,296):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_6x2t
ddt(1,297):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. q_7xt
ddt(1,298):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_8t
ddt(1,299):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_x7t
ddt(1,300):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_2x6t
ddt(1,301):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_3x5t
ddt(1,302):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_4x4t
ddt(1,303):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_5x3t
ddt(1,304):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_6x2t
ddt(1,305):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. r_7xt
ddt(1,306):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_x7t
ddt(1,307):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_2x6t
ddt(1,308):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_3x5t
ddt(1,309):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_4x4t
ddt(1,310):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_5x3t
ddt(1,311):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_6x2t
ddt(1,312):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_7xt
ddt(1,313):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_8x
ddt(1,314):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o1_8t
ddt(1,315):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_x7t
ddt(1,316):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_2x6t
ddt(1,317):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_3x5t
ddt(1,318):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_4x4t
ddt(1,319):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_5x3t
ddt(1,320):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_6x2t
ddt(1,321):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_7xt
ddt(1,322):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_8x
ddt(1,323):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o2_8t
ddt(1,324):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_x7t
ddt(1,325):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_2x6t
ddt(1,326):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_3x5t
ddt(1,327):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_4x4t
ddt(1,328):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_5x3t
ddt(1,329):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_6x2t
ddt(1,330):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_7xt
ddt(1,331):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_8x
ddt(1,332):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. o3_8t
ddt(1,333):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
