% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_10x)
de!*:=(letop)
% odd equation
principal_odd!*:=(q_10x)
de_odd!*(letop)
% Settings:
indep_var!*:=(x y)
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
all_der_id!*:=(u u_x u_y u_2x u_xy u_2y u_3x u_2xy u_x2y u_3y u_4x u_3xy u_2x2y
u_x3y u_4y u_5x u_4xy u_3x2y u_2x3y u_x4y u_5y u_6x u_5xy u_4x2y u_3x3y u_2x4y
u_x5y u_6y u_7x u_6xy u_5x2y u_4x3y u_3x4y u_2x5y u_x6y u_7y u_8x u_7xy u_6x2y
u_5x3y u_4x4y u_3x5y u_2x6y u_x7y u_8y u_9x u_8xy u_7x2y u_6x3y u_5x4y u_4x5y
u_3x6y u_2x7y u_x8y u_9y u_10x u_9xy u_8x2y u_7x3y u_6x4y u_5x5y u_4x6y u_3x7y
u_2x8y u_x9y u_10y)
% all odd derivatives in identifier notation:
all_odd_id!*:=(q q_x q_y q_2x q_xy q_2y q_3x q_2xy q_x2y q_3y q_4x q_3xy q_2x2y
q_x3y q_4y q_5x q_4xy q_3x2y q_2x3y q_x4y q_5y q_6x q_5xy q_4x2y q_3x3y q_2x4y
q_x5y q_6y q_7x q_6xy q_5x2y q_4x3y q_3x4y q_2x5y q_x6y q_7y q_8x q_7xy q_6x2y
q_5x3y q_4x4y q_3x5y q_2x6y q_x7y q_8y q_9x q_8xy q_7x2y q_6x3y q_5x4y q_4x5y
q_3x6y q_2x7y q_x8y q_9y q_10x q_9xy q_8x2y q_7x3y q_6x4y q_5x5y q_4x6y q_3x7y
q_2x8y q_x9y q_10y)
% number of all ext symbols:
n_all_ext:=66
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0)) (u_x u (1 0)) (u_y u (0 1)) (u_2x u (2 0)) (u_xy u
(1 1)) (u_2y u (0 2)) (u_3x u (3 0)) (u_2xy u (2 1)) (u_x2y u (1 2)) (u_3y u (0
3)) (u_4x u (4 0)) (u_3xy u (3 1)) (u_2x2y u (2 2)) (u_x3y u (1 3)) (u_4y u (0 4
)) (u_5x u (5 0)) (u_4xy u (4 1)) (u_3x2y u (3 2)) (u_2x3y u (2 3)) (u_x4y u (1
4)) (u_5y u (0 5)) (u_6x u (6 0)) (u_5xy u (5 1)) (u_4x2y u (4 2)) (u_3x3y u (3
3)) (u_2x4y u (2 4)) (u_x5y u (1 5)) (u_6y u (0 6)) (u_7x u (7 0)) (u_6xy u (6 1
)) (u_5x2y u (5 2)) (u_4x3y u (4 3)) (u_3x4y u (3 4)) (u_2x5y u (2 5)) (u_x6y u
(1 6)) (u_7y u (0 7)) (u_8x u (8 0)) (u_7xy u (7 1)) (u_6x2y u (6 2)) (u_5x3y u
(5 3)) (u_4x4y u (4 4)) (u_3x5y u (3 5)) (u_2x6y u (2 6)) (u_x7y u (1 7)) (u_8y
u (0 8)) (u_9x u (9 0)) (u_8xy u (8 1)) (u_7x2y u (7 2)) (u_6x3y u (6 3)) (
u_5x4y u (5 4)) (u_4x5y u (4 5)) (u_3x6y u (3 6)) (u_2x7y u (2 7)) (u_x8y u (1 8
)) (u_9y u (0 9)) (u_10x u (10 0)) (u_9xy u (9 1)) (u_8x2y u (8 2)) (u_7x3y u (7
3)) (u_6x4y u (6 4)) (u_5x5y u (5 5)) (u_4x6y u (4 6)) (u_3x7y u (3 7)) (u_2x8y
u (2 8)) (u_x9y u (1 9)) (u_10y u (0 10)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((q q (0 0)) (q_x q (1 0)) (q_y q (0 1)) (q_2x q (2 0)) (
q_xy q (1 1)) (q_2y q (0 2)) (q_3x q (3 0)) (q_2xy q (2 1)) (q_x2y q (1 2)) (
q_3y q (0 3)) (q_4x q (4 0)) (q_3xy q (3 1)) (q_2x2y q (2 2)) (q_x3y q (1 3)) (
q_4y q (0 4)) (q_5x q (5 0)) (q_4xy q (4 1)) (q_3x2y q (3 2)) (q_2x3y q (2 3)) (
q_x4y q (1 4)) (q_5y q (0 5)) (q_6x q (6 0)) (q_5xy q (5 1)) (q_4x2y q (4 2)) (
q_3x3y q (3 3)) (q_2x4y q (2 4)) (q_x5y q (1 5)) (q_6y q (0 6)) (q_7x q (7 0)) (
q_6xy q (6 1)) (q_5x2y q (5 2)) (q_4x3y q (4 3)) (q_3x4y q (3 4)) (q_2x5y q (2 5
)) (q_x6y q (1 6)) (q_7y q (0 7)) (q_8x q (8 0)) (q_7xy q (7 1)) (q_6x2y q (6 2)
) (q_5x3y q (5 3)) (q_4x4y q (4 4)) (q_3x5y q (3 5)) (q_2x6y q (2 6)) (q_x7y q (
1 7)) (q_8y q (0 8)) (q_9x q (9 0)) (q_8xy q (8 1)) (q_7x2y q (7 2)) (q_6x3y q (
6 3)) (q_5x4y q (5 4)) (q_4x5y q (4 5)) (q_3x6y q (3 6)) (q_2x7y q (2 7)) (q_x8y
q (1 8)) (q_9y q (0 9)) (q_10x q (10 0)) (q_9xy q (9 1)) (q_8x2y q (8 2)) (
q_7x3y q (7 3)) (q_6x4y q (6 4)) (q_5x5y q (5 5)) (q_4x6y q (4 6)) (q_3x7y q (3
7)) (q_2x8y q (2 8)) (q_x9y q (1 9)) (q_10y q (0 10)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (u_x . 1) (u_y . 1) (u_2x . 2) (u_xy . 2) (u_2y . 2) (
u_3x . 3) (u_2xy . 3) (u_x2y . 3) (u_3y . 3) (u_4x . 4) (u_3xy . 4) (u_2x2y . 4)
(u_x3y . 4) (u_4y . 4) (u_5x . 5) (u_4xy . 5) (u_3x2y . 5) (u_2x3y . 5) (u_x4y .
5) (u_5y . 5) (u_6x . 6) (u_5xy . 6) (u_4x2y . 6) (u_3x3y . 6) (u_2x4y . 6) (
u_x5y . 6) (u_6y . 6) (u_7x . 7) (u_6xy . 7) (u_5x2y . 7) (u_4x3y . 7) (u_3x4y .
7) (u_2x5y . 7) (u_x6y . 7) (u_7y . 7) (u_8x . 8) (u_7xy . 8) (u_6x2y . 8) (
u_5x3y . 8) (u_4x4y . 8) (u_3x5y . 8) (u_2x6y . 8) (u_x7y . 8) (u_8y . 8) (u_9x
. 9) (u_8xy . 9) (u_7x2y . 9) (u_6x3y . 9) (u_5x4y . 9) (u_4x5y . 9) (u_3x6y . 9
) (u_2x7y . 9) (u_x8y . 9) (u_9y . 9) (u_10x . 10) (u_9xy . 10) (u_8x2y . 10) (
u_7x3y . 10) (u_6x4y . 10) (u_5x5y . 10) (u_4x6y . 10) (u_3x7y . 10) (u_2x8y .
10) (u_x9y . 10) (u_10y . 10))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((q . 0) (q_x . 1) (q_y . 1) (q_2x . 2) (q_xy . 2) (q_2y . 2
) (q_3x . 3) (q_2xy . 3) (q_x2y . 3) (q_3y . 3) (q_4x . 4) (q_3xy . 4) (q_2x2y .
4) (q_x3y . 4) (q_4y . 4) (q_5x . 5) (q_4xy . 5) (q_3x2y . 5) (q_2x3y . 5) (
q_x4y . 5) (q_5y . 5) (q_6x . 6) (q_5xy . 6) (q_4x2y . 6) (q_3x3y . 6) (q_2x4y .
6) (q_x5y . 6) (q_6y . 6) (q_7x . 7) (q_6xy . 7) (q_5x2y . 7) (q_4x3y . 7) (
q_3x4y . 7) (q_2x5y . 7) (q_x6y . 7) (q_7y . 7) (q_8x . 8) (q_7xy . 8) (q_6x2y .
8) (q_5x3y . 8) (q_4x4y . 8) (q_3x5y . 8) (q_2x6y . 8) (q_x7y . 8) (q_8y . 8) (
q_9x . 9) (q_8xy . 9) (q_7x2y . 9) (q_6x3y . 9) (q_5x4y . 9) (q_4x5y . 9) (
q_3x6y . 9) (q_2x7y . 9) (q_x8y . 9) (q_9y . 9) (q_10x . 10) (q_9xy . 10) (
q_8x2y . 10) (q_7x3y . 10) (q_6x4y . 10) (q_5x5y . 10) (q_4x6y . 10) (q_3x7y .
10) (q_2x8y . 10) (q_x9y . 10) (q_10y . 10))
% list of even principal derivatives:
all_principal_der!*:=(u_10x)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_x u_y u_2x u_xy u_2y u_3x u_2xy u_x2y u_3y u_4x u_3xy
u_2x2y u_x3y u_4y u_5x u_4xy u_3x2y u_2x3y u_x4y u_5y u_6x u_5xy u_4x2y u_3x3y
u_2x4y u_x5y u_6y u_7x u_6xy u_5x2y u_4x3y u_3x4y u_2x5y u_x6y u_7y u_8x u_7xy
u_6x2y u_5x3y u_4x4y u_3x5y u_2x6y u_x7y u_8y u_9x u_8xy u_7x2y u_6x3y u_5x4y
u_4x5y u_3x6y u_2x7y u_x8y u_9y u_9xy u_8x2y u_7x3y u_6x4y u_5x5y u_4x6y u_3x7y
u_2x8y u_x9y u_10y)
% list of odd principal derivatives:
all_principal_odd!*:=(q_10x)
q_10x = (ext 66)
% list of odd parametric derivatives:
all_parametric_odd!*:=(q q_x q_y q_2x q_xy q_2y q_3x q_2xy q_x2y q_3y q_4x q_3xy
q_2x2y q_x3y q_4y q_5x q_4xy q_3x2y q_2x3y q_x4y q_5y q_6x q_5xy q_4x2y q_3x3y
q_2x4y q_x5y q_6y q_7x q_6xy q_5x2y q_4x3y q_3x4y q_2x5y q_x6y q_7y q_8x q_7xy
q_6x2y q_5x3y q_4x4y q_3x5y q_2x6y q_x7y q_8y q_9x q_8xy q_7x2y q_6x3y q_5x4y
q_4x5y q_3x6y q_2x7y q_x8y q_9y q_9xy q_8x2y q_7x3y q_6x4y q_5x5y q_4x6y q_3x7y
q_2x8y q_x9y q_10y)
q = (ext 1)
q_x = (ext 2)
q_y = (ext 3)
q_2x = (ext 4)
q_xy = (ext 5)
q_2y = (ext 6)
q_3x = (ext 7)
q_2xy = (ext 8)
q_x2y = (ext 9)
q_3y = (ext 10)
q_4x = (ext 11)
q_3xy = (ext 12)
q_2x2y = (ext 13)
q_x3y = (ext 14)
q_4y = (ext 15)
q_5x = (ext 16)
q_4xy = (ext 17)
q_3x2y = (ext 18)
q_2x3y = (ext 19)
q_x4y = (ext 20)
q_5y = (ext 21)
q_6x = (ext 22)
q_5xy = (ext 23)
q_4x2y = (ext 24)
q_3x3y = (ext 25)
q_2x4y = (ext 26)
q_x5y = (ext 27)
q_6y = (ext 28)
q_7x = (ext 29)
q_6xy = (ext 30)
q_5x2y = (ext 31)
q_4x3y = (ext 32)
q_3x4y = (ext 33)
q_2x5y = (ext 34)
q_x6y = (ext 35)
q_7y = (ext 36)
q_8x = (ext 37)
q_7xy = (ext 38)
q_6x2y = (ext 39)
q_5x3y = (ext 40)
q_4x4y = (ext 41)
q_3x5y = (ext 42)
q_2x6y = (ext 43)
q_x7y = (ext 44)
q_8y = (ext 45)
q_9x = (ext 46)
q_8xy = (ext 47)
q_7x2y = (ext 48)
q_6x3y = (ext 49)
q_5x4y = (ext 50)
q_4x5y = (ext 51)
q_3x6y = (ext 52)
q_2x7y = (ext 53)
q_x8y = (ext 54)
q_9y = (ext 55)
q_9xy = (ext 56)
q_8x2y = (ext 57)
q_7x3y = (ext 58)
q_6x4y = (ext 59)
q_5x5y = (ext 60)
q_4x6y = (ext 61)
q_3x7y = (ext 62)
q_2x8y = (ext 63)
q_x9y = (ext 64)
q_10y = (ext 65)
% number of ext principal derivatives:
n_all_principal_ext:=1
% number of ext parametric derivatives:
n_all_parametric_ext:=65
% set of identifiers for total derivatives:
tot_der!*:=(ddx ddy)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddx 0 48 u_10x))
primary_diffcon_odd_tot!*:=((ddx 1 46 q_10x))
primary_diffcon_der!*:=nil
primary_diffcon_odd!*:=nil
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_10x letop))
diffcon_odd!*:=((q_10x letop))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_10x)
diffcon_comp_odd!*:=(q_10x)
diffcon_comp_ext!*:=((ext 66))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_10x *sq ((((letop . 1) . 1)) . 1) nil))
diffcon_param_ext!*:=(((ext 66) *sq ((((letop . 1) . 1)) . 1) t))
% Coefficients of total derivatives:
% component of ddx w.r.t. x
ddx(0,1):=1
% component of ddx w.r.t. y
ddx(0,2):=0
% component of ddx w.r.t. u
ddx(0,3):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x
ddx(0,4):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_y
ddx(0,5):=(*sq ((((u_xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x
ddx(0,6):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_xy
ddx(0,7):=(*sq ((((u_2xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2y
ddx(0,8):=(*sq ((((u_x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x
ddx(0,9):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2xy
ddx(0,10):=(*sq ((((u_3xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x2y
ddx(0,11):=(*sq ((((u_2x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3y
ddx(0,12):=(*sq ((((u_x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x
ddx(0,13):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3xy
ddx(0,14):=(*sq ((((u_4xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x2y
ddx(0,15):=(*sq ((((u_3x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x3y
ddx(0,16):=(*sq ((((u_2x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4y
ddx(0,17):=(*sq ((((u_x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x
ddx(0,18):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4xy
ddx(0,19):=(*sq ((((u_5xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x2y
ddx(0,20):=(*sq ((((u_4x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x3y
ddx(0,21):=(*sq ((((u_3x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x4y
ddx(0,22):=(*sq ((((u_2x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5y
ddx(0,23):=(*sq ((((u_x5y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x
ddx(0,24):=(*sq ((((u_7x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5xy
ddx(0,25):=(*sq ((((u_6xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x2y
ddx(0,26):=(*sq ((((u_5x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x3y
ddx(0,27):=(*sq ((((u_4x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x4y
ddx(0,28):=(*sq ((((u_3x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x5y
ddx(0,29):=(*sq ((((u_2x5y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6y
ddx(0,30):=(*sq ((((u_x6y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x
ddx(0,31):=(*sq ((((u_8x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6xy
ddx(0,32):=(*sq ((((u_7xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x2y
ddx(0,33):=(*sq ((((u_6x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x3y
ddx(0,34):=(*sq ((((u_5x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x4y
ddx(0,35):=(*sq ((((u_4x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x5y
ddx(0,36):=(*sq ((((u_3x5y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x6y
ddx(0,37):=(*sq ((((u_2x6y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7y
ddx(0,38):=(*sq ((((u_x7y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x
ddx(0,39):=(*sq ((((u_9x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7xy
ddx(0,40):=(*sq ((((u_8xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x2y
ddx(0,41):=(*sq ((((u_7x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x3y
ddx(0,42):=(*sq ((((u_6x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x4y
ddx(0,43):=(*sq ((((u_5x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x5y
ddx(0,44):=(*sq ((((u_4x5y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x6y
ddx(0,45):=(*sq ((((u_3x6y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x7y
ddx(0,46):=(*sq ((((u_2x7y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8y
ddx(0,47):=(*sq ((((u_x8y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9x
ddx(0,48):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8xy
ddx(0,49):=(*sq ((((u_9xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x2y
ddx(0,50):=(*sq ((((u_8x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x3y
ddx(0,51):=(*sq ((((u_7x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x4y
ddx(0,52):=(*sq ((((u_6x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x5y
ddx(0,53):=(*sq ((((u_5x5y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x6y
ddx(0,54):=(*sq ((((u_4x6y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x7y
ddx(0,55):=(*sq ((((u_3x7y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x8y
ddx(0,56):=(*sq ((((u_2x8y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9y
ddx(0,57):=(*sq ((((u_x9y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_9xy
ddx(0,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_8x2y
ddx(0,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_7x3y
ddx(0,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x4y
ddx(0,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x5y
ddx(0,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x6y
ddx(0,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x7y
ddx(0,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x8y
ddx(0,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x9y
ddx(0,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_10y
ddx(0,67):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_10x
ddx(0,68):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q
ddx(1,1):=(*sq (((((ext 2) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x
ddx(1,2):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_y
ddx(1,3):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x
ddx(1,4):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_xy
ddx(1,5):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2y
ddx(1,6):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x
ddx(1,7):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2xy
ddx(1,8):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x2y
ddx(1,9):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3y
ddx(1,10):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x
ddx(1,11):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3xy
ddx(1,12):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x2y
ddx(1,13):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x3y
ddx(1,14):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4y
ddx(1,15):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x
ddx(1,16):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4xy
ddx(1,17):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x2y
ddx(1,18):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x3y
ddx(1,19):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x4y
ddx(1,20):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5y
ddx(1,21):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x
ddx(1,22):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5xy
ddx(1,23):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x2y
ddx(1,24):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x3y
ddx(1,25):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x4y
ddx(1,26):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x5y
ddx(1,27):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6y
ddx(1,28):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x
ddx(1,29):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6xy
ddx(1,30):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x2y
ddx(1,31):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x3y
ddx(1,32):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x4y
ddx(1,33):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x5y
ddx(1,34):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x6y
ddx(1,35):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7y
ddx(1,36):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x
ddx(1,37):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7xy
ddx(1,38):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x2y
ddx(1,39):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x3y
ddx(1,40):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x4y
ddx(1,41):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x5y
ddx(1,42):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x6y
ddx(1,43):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x7y
ddx(1,44):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8y
ddx(1,45):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9x
ddx(1,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8xy
ddx(1,47):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x2y
ddx(1,48):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x3y
ddx(1,49):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x4y
ddx(1,50):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x5y
ddx(1,51):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x6y
ddx(1,52):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x7y
ddx(1,53):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x8y
ddx(1,54):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9y
ddx(1,55):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_9xy
ddx(1,56):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_8x2y
ddx(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_7x3y
ddx(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_6x4y
ddx(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_5x5y
ddx(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_4x6y
ddx(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_3x7y
ddx(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_2x8y
ddx(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_x9y
ddx(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_10y
ddx(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. q_10x
ddx(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. x
ddy(0,1):=0
% component of ddy w.r.t. y
ddy(0,2):=1
% component of ddy w.r.t. u
ddy(0,3):=(*sq ((((u_y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x
ddy(0,4):=(*sq ((((u_xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_y
ddy(0,5):=(*sq ((((u_2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x
ddy(0,6):=(*sq ((((u_2xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_xy
ddy(0,7):=(*sq ((((u_x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2y
ddy(0,8):=(*sq ((((u_3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x
ddy(0,9):=(*sq ((((u_3xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2xy
ddy(0,10):=(*sq ((((u_2x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x2y
ddy(0,11):=(*sq ((((u_x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3y
ddy(0,12):=(*sq ((((u_4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x
ddy(0,13):=(*sq ((((u_4xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3xy
ddy(0,14):=(*sq ((((u_3x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x2y
ddy(0,15):=(*sq ((((u_2x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x3y
ddy(0,16):=(*sq ((((u_x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4y
ddy(0,17):=(*sq ((((u_5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5x
ddy(0,18):=(*sq ((((u_5xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4xy
ddy(0,19):=(*sq ((((u_4x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x2y
ddy(0,20):=(*sq ((((u_3x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x3y
ddy(0,21):=(*sq ((((u_2x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x4y
ddy(0,22):=(*sq ((((u_x5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5y
ddy(0,23):=(*sq ((((u_6y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6x
ddy(0,24):=(*sq ((((u_6xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5xy
ddy(0,25):=(*sq ((((u_5x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x2y
ddy(0,26):=(*sq ((((u_4x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x3y
ddy(0,27):=(*sq ((((u_3x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x4y
ddy(0,28):=(*sq ((((u_2x5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x5y
ddy(0,29):=(*sq ((((u_x6y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6y
ddy(0,30):=(*sq ((((u_7y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_7x
ddy(0,31):=(*sq ((((u_7xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6xy
ddy(0,32):=(*sq ((((u_6x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5x2y
ddy(0,33):=(*sq ((((u_5x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x3y
ddy(0,34):=(*sq ((((u_4x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x4y
ddy(0,35):=(*sq ((((u_3x5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x5y
ddy(0,36):=(*sq ((((u_2x6y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x6y
ddy(0,37):=(*sq ((((u_x7y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_7y
ddy(0,38):=(*sq ((((u_8y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_8x
ddy(0,39):=(*sq ((((u_8xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_7xy
ddy(0,40):=(*sq ((((u_7x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6x2y
ddy(0,41):=(*sq ((((u_6x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5x3y
ddy(0,42):=(*sq ((((u_5x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x4y
ddy(0,43):=(*sq ((((u_4x5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x5y
ddy(0,44):=(*sq ((((u_3x6y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x6y
ddy(0,45):=(*sq ((((u_2x7y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x7y
ddy(0,46):=(*sq ((((u_x8y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_8y
ddy(0,47):=(*sq ((((u_9y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_9x
ddy(0,48):=(*sq ((((u_9xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_8xy
ddy(0,49):=(*sq ((((u_8x2y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_7x2y
ddy(0,50):=(*sq ((((u_7x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6x3y
ddy(0,51):=(*sq ((((u_6x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5x4y
ddy(0,52):=(*sq ((((u_5x5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x5y
ddy(0,53):=(*sq ((((u_4x6y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x6y
ddy(0,54):=(*sq ((((u_3x7y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x7y
ddy(0,55):=(*sq ((((u_2x8y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x8y
ddy(0,56):=(*sq ((((u_x9y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_9y
ddy(0,57):=(*sq ((((u_10y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_9xy
ddy(0,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_8x2y
ddy(0,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_7x3y
ddy(0,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6x4y
ddy(0,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5x5y
ddy(0,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x6y
ddy(0,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x7y
ddy(0,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x8y
ddy(0,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x9y
ddy(0,66):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_10y
ddy(0,67):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_10x
ddy(0,68):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q
ddy(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x
ddy(1,2):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_y
ddy(1,3):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x
ddy(1,4):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_xy
ddy(1,5):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2y
ddy(1,6):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3x
ddy(1,7):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2xy
ddy(1,8):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x2y
ddy(1,9):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3y
ddy(1,10):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4x
ddy(1,11):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3xy
ddy(1,12):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x2y
ddy(1,13):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x3y
ddy(1,14):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4y
ddy(1,15):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_5x
ddy(1,16):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4xy
ddy(1,17):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3x2y
ddy(1,18):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x3y
ddy(1,19):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x4y
ddy(1,20):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_5y
ddy(1,21):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_6x
ddy(1,22):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_5xy
ddy(1,23):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4x2y
ddy(1,24):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3x3y
ddy(1,25):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x4y
ddy(1,26):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x5y
ddy(1,27):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_6y
ddy(1,28):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_7x
ddy(1,29):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_6xy
ddy(1,30):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_5x2y
ddy(1,31):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4x3y
ddy(1,32):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3x4y
ddy(1,33):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x5y
ddy(1,34):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x6y
ddy(1,35):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_7y
ddy(1,36):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_8x
ddy(1,37):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_7xy
ddy(1,38):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_6x2y
ddy(1,39):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_5x3y
ddy(1,40):=(*sq (((((ext 50) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4x4y
ddy(1,41):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3x5y
ddy(1,42):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x6y
ddy(1,43):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x7y
ddy(1,44):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_8y
ddy(1,45):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_9x
ddy(1,46):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_8xy
ddy(1,47):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_7x2y
ddy(1,48):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_6x3y
ddy(1,49):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_5x4y
ddy(1,50):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4x5y
ddy(1,51):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3x6y
ddy(1,52):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x7y
ddy(1,53):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x8y
ddy(1,54):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_9y
ddy(1,55):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_9xy
ddy(1,56):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_8x2y
ddy(1,57):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_7x3y
ddy(1,58):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_6x4y
ddy(1,59):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_5x5y
ddy(1,60):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_4x6y
ddy(1,61):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_3x7y
ddy(1,62):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_2x8y
ddy(1,63):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_x9y
ddy(1,64):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_10y
ddy(1,65):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. q_10x
ddy(1,66):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
