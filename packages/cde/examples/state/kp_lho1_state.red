% CDE state file -- use for debugging purposes
% even equation:
principal_der!*:=(u_2y)
de!*:=((quotient (plus (minus (times 12 u u_2x)) (minus u_4x) (times 12 u_tx) (
minus (times 12 (expt u_x 2)))) 12))
% odd equation
principal_odd!*:=(p_2y)
de_odd!*((quotient (plus (minus (times 12 p_2x u)) (minus p_4x) (times 12 p_tx))
12))
% Settings:
indep_var!*:=(t x y)
dep_var!*:=(u)
odd_var!*:=(p)
deg_indep_var!*:=(-3 -2 -1)
deg_dep_var!*:=(2)
deg_odd_var!*:=(1)
total_order:=6
id_tot_der!*:=dd
% Here starts the output of computations of the program.
% number of independent variables:
n_indep_var:=3
% all multiindexes in table format:
all_mind_table!*:=(((0 0 0) ((1 0 0) (0 1 0) (0 0 1))) ((1 0 0) ((2 0 0) (1 1 0)
(1 0 1) (1 1 0) (0 2 0) (0 1 1) (1 0 1) (0 1 1) (0 0 2))) ((0 1 0) ((1 1 0) (0 2
0) (0 1 1) (1 0 1) (0 1 1) (0 0 2))) ((0 0 1) ((1 0 1) (0 1 1) (0 0 2))) ((2 0 0
) ((3 0 0) (2 1 0) (2 0 1) (2 1 0) (1 2 0) (1 1 1) (1 2 0) (0 3 0) (0 2 1) (2 0
1) (1 1 1) (1 0 2) (1 1 1) (0 2 1) (0 1 2) (1 0 2) (0 1 2) (0 0 3))) ((1 1 0) ((
2 1 0) (1 2 0) (1 1 1) (1 2 0) (0 3 0) (0 2 1) (2 0 1) (1 1 1) (1 0 2) (1 1 1) (
0 2 1) (0 1 2) (1 0 2) (0 1 2) (0 0 3))) ((0 2 0) ((1 2 0) (0 3 0) (0 2 1) (2 0
1) (1 1 1) (1 0 2) (1 1 1) (0 2 1) (0 1 2) (1 0 2) (0 1 2) (0 0 3))) ((1 0 1) ((
2 0 1) (1 1 1) (1 0 2) (1 1 1) (0 2 1) (0 1 2) (1 0 2) (0 1 2) (0 0 3))) ((0 1 1
) ((1 1 1) (0 2 1) (0 1 2) (1 0 2) (0 1 2) (0 0 3))) ((0 0 2) ((1 0 2) (0 1 2) (
0 0 3))) ((3 0 0) ((4 0 0) (3 1 0) (3 0 1) (3 1 0) (2 2 0) (2 1 1) (2 2 0) (1 3
0) (1 2 1) (1 3 0) (0 4 0) (0 3 1) (3 0 1) (2 1 1) (2 0 2) (2 1 1) (1 2 1) (1 1
2) (1 2 1) (0 3 1) (0 2 2) (2 0 2) (1 1 2) (1 0 3) (1 1 2) (0 2 2) (0 1 3) (1 0
3) (0 1 3) (0 0 4))) ((2 1 0) ((3 1 0) (2 2 0) (2 1 1) (2 2 0) (1 3 0) (1 2 1) (
1 3 0) (0 4 0) (0 3 1) (3 0 1) (2 1 1) (2 0 2) (2 1 1) (1 2 1) (1 1 2) (1 2 1) (
0 3 1) (0 2 2) (2 0 2) (1 1 2) (1 0 3) (1 1 2) (0 2 2) (0 1 3) (1 0 3) (0 1 3) (
0 0 4))) ((1 2 0) ((2 2 0) (1 3 0) (1 2 1) (1 3 0) (0 4 0) (0 3 1) (3 0 1) (2 1
1) (2 0 2) (2 1 1) (1 2 1) (1 1 2) (1 2 1) (0 3 1) (0 2 2) (2 0 2) (1 1 2) (1 0
3) (1 1 2) (0 2 2) (0 1 3) (1 0 3) (0 1 3) (0 0 4))) ((0 3 0) ((1 3 0) (0 4 0) (
0 3 1) (3 0 1) (2 1 1) (2 0 2) (2 1 1) (1 2 1) (1 1 2) (1 2 1) (0 3 1) (0 2 2) (
2 0 2) (1 1 2) (1 0 3) (1 1 2) (0 2 2) (0 1 3) (1 0 3) (0 1 3) (0 0 4))) ((2 0 1
) ((3 0 1) (2 1 1) (2 0 2) (2 1 1) (1 2 1) (1 1 2) (1 2 1) (0 3 1) (0 2 2) (2 0
2) (1 1 2) (1 0 3) (1 1 2) (0 2 2) (0 1 3) (1 0 3) (0 1 3) (0 0 4))) ((1 1 1) ((
2 1 1) (1 2 1) (1 1 2) (1 2 1) (0 3 1) (0 2 2) (2 0 2) (1 1 2) (1 0 3) (1 1 2) (
0 2 2) (0 1 3) (1 0 3) (0 1 3) (0 0 4))) ((0 2 1) ((1 2 1) (0 3 1) (0 2 2) (2 0
2) (1 1 2) (1 0 3) (1 1 2) (0 2 2) (0 1 3) (1 0 3) (0 1 3) (0 0 4))) ((1 0 2) ((
2 0 2) (1 1 2) (1 0 3) (1 1 2) (0 2 2) (0 1 3) (1 0 3) (0 1 3) (0 0 4))) ((0 1 2
) ((1 1 2) (0 2 2) (0 1 3) (1 0 3) (0 1 3) (0 0 4))) ((0 0 3) ((1 0 3) (0 1 3) (
0 0 4))) ((4 0 0) ((5 0 0) (4 1 0) (4 0 1) (4 1 0) (3 2 0) (3 1 1) (3 2 0) (2 3
0) (2 2 1) (2 3 0) (1 4 0) (1 3 1) (1 4 0) (0 5 0) (0 4 1) (4 0 1) (3 1 1) (3 0
2) (3 1 1) (2 2 1) (2 1 2) (2 2 1) (1 3 1) (1 2 2) (1 3 1) (0 4 1) (0 3 2) (3 0
2) (2 1 2) (2 0 3) (2 1 2) (1 2 2) (1 1 3) (1 2 2) (0 3 2) (0 2 3) (2 0 3) (1 1
3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (0 0 5))) ((3 1 0) ((4 1 0) (
3 2 0) (3 1 1) (3 2 0) (2 3 0) (2 2 1) (2 3 0) (1 4 0) (1 3 1) (1 4 0) (0 5 0) (
0 4 1) (4 0 1) (3 1 1) (3 0 2) (3 1 1) (2 2 1) (2 1 2) (2 2 1) (1 3 1) (1 2 2) (
1 3 1) (0 4 1) (0 3 2) (3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2 2) (1 1 3) (1 2 2) (
0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (
0 0 5))) ((2 2 0) ((3 2 0) (2 3 0) (2 2 1) (2 3 0) (1 4 0) (1 3 1) (1 4 0) (0 5
0) (0 4 1) (4 0 1) (3 1 1) (3 0 2) (3 1 1) (2 2 1) (2 1 2) (2 2 1) (1 3 1) (1 2
2) (1 3 1) (0 4 1) (0 3 2) (3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2 2) (1 1 3) (1 2
2) (0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1
4) (0 0 5))) ((1 3 0) ((2 3 0) (1 4 0) (1 3 1) (1 4 0) (0 5 0) (0 4 1) (4 0 1) (
3 1 1) (3 0 2) (3 1 1) (2 2 1) (2 1 2) (2 2 1) (1 3 1) (1 2 2) (1 3 1) (0 4 1) (
0 3 2) (3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2 2) (1 1 3) (1 2 2) (0 3 2) (0 2 3) (
2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (0 0 5))) ((0 4 0
) ((1 4 0) (0 5 0) (0 4 1) (4 0 1) (3 1 1) (3 0 2) (3 1 1) (2 2 1) (2 1 2) (2 2
1) (1 3 1) (1 2 2) (1 3 1) (0 4 1) (0 3 2) (3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2
2) (1 1 3) (1 2 2) (0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1
4) (1 0 4) (0 1 4) (0 0 5))) ((3 0 1) ((4 0 1) (3 1 1) (3 0 2) (3 1 1) (2 2 1) (
2 1 2) (2 2 1) (1 3 1) (1 2 2) (1 3 1) (0 4 1) (0 3 2) (3 0 2) (2 1 2) (2 0 3) (
2 1 2) (1 2 2) (1 1 3) (1 2 2) (0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (
0 2 3) (0 1 4) (1 0 4) (0 1 4) (0 0 5))) ((2 1 1) ((3 1 1) (2 2 1) (2 1 2) (2 2
1) (1 3 1) (1 2 2) (1 3 1) (0 4 1) (0 3 2) (3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2
2) (1 1 3) (1 2 2) (0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1
4) (1 0 4) (0 1 4) (0 0 5))) ((1 2 1) ((2 2 1) (1 3 1) (1 2 2) (1 3 1) (0 4 1) (
0 3 2) (3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2 2) (1 1 3) (1 2 2) (0 3 2) (0 2 3) (
2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (0 0 5))) ((0 3 1
) ((1 3 1) (0 4 1) (0 3 2) (3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2 2) (1 1 3) (1 2
2) (0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1
4) (0 0 5))) ((2 0 2) ((3 0 2) (2 1 2) (2 0 3) (2 1 2) (1 2 2) (1 1 3) (1 2 2) (
0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (
0 0 5))) ((1 1 2) ((2 1 2) (1 2 2) (1 1 3) (1 2 2) (0 3 2) (0 2 3) (2 0 3) (1 1
3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (0 0 5))) ((0 2 2) ((1 2 2) (
0 3 2) (0 2 3) (2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (
0 0 5))) ((1 0 3) ((2 0 3) (1 1 3) (1 0 4) (1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1
4) (0 0 5))) ((0 1 3) ((1 1 3) (0 2 3) (0 1 4) (1 0 4) (0 1 4) (0 0 5))) ((0 0 4
) ((1 0 4) (0 1 4) (0 0 5))) ((5 0 0) ((6 0 0) (5 1 0) (5 0 1) (5 1 0) (4 2 0) (
4 1 1) (4 2 0) (3 3 0) (3 2 1) (3 3 0) (2 4 0) (2 3 1) (2 4 0) (1 5 0) (1 4 1) (
1 5 0) (0 6 0) (0 5 1) (5 0 1) (4 1 1) (4 0 2) (4 1 1) (3 2 1) (3 1 2) (3 2 1) (
2 3 1) (2 2 2) (2 3 1) (1 4 1) (1 3 2) (1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (
3 0 3) (3 1 2) (2 2 2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (
3 0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (
1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((4 1 0) ((5 1
0) (4 2 0) (4 1 1) (4 2 0) (3 3 0) (3 2 1) (3 3 0) (2 4 0) (2 3 1) (2 4 0) (1 5
0) (1 4 1) (1 5 0) (0 6 0) (0 5 1) (5 0 1) (4 1 1) (4 0 2) (4 1 1) (3 2 1) (3 1
2) (3 2 1) (2 3 1) (2 2 2) (2 3 1) (1 4 1) (1 3 2) (1 4 1) (0 5 1) (0 4 2) (4 0
2) (3 1 2) (3 0 3) (3 1 2) (2 2 2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4
2) (0 3 3) (3 0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2
4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((3
2 0) ((4 2 0) (3 3 0) (3 2 1) (3 3 0) (2 4 0) (2 3 1) (2 4 0) (1 5 0) (1 4 1) (1
5 0) (0 6 0) (0 5 1) (5 0 1) (4 1 1) (4 0 2) (4 1 1) (3 2 1) (3 1 2) (3 2 1) (2
3 1) (2 2 2) (2 3 1) (1 4 1) (1 3 2) (1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3
0 3) (3 1 2) (2 2 2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3
0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1
1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((2 3 0) ((3 3 0)
(2 4 0) (2 3 1) (2 4 0) (1 5 0) (1 4 1) (1 5 0) (0 6 0) (0 5 1) (5 0 1) (4 1 1)
(4 0 2) (4 1 1) (3 2 1) (3 1 2) (3 2 1) (2 3 1) (2 2 2) (2 3 1) (1 4 1) (1 3 2)
(1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3 0 3) (3 1 2) (2 2 2) (2 1 3) (2 2 2)
(1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3)
(1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5)
(1 0 5) (0 1 5) (0 0 6))) ((1 4 0) ((2 4 0) (1 5 0) (1 4 1) (1 5 0) (0 6 0) (0 5
1) (5 0 1) (4 1 1) (4 0 2) (4 1 1) (3 2 1) (3 1 2) (3 2 1) (2 3 1) (2 2 2) (2 3
1) (1 4 1) (1 3 2) (1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3 0 3) (3 1 2) (2 2
2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0
4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1
4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((0 5 0) ((1 5 0) (0 6 0) (0 5 1) (
5 0 1) (4 1 1) (4 0 2) (4 1 1) (3 2 1) (3 1 2) (3 2 1) (2 3 1) (2 2 2) (2 3 1) (
1 4 1) (1 3 2) (1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3 0 3) (3 1 2) (2 2 2) (
2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0 4) (
2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (
0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((4 0 1) ((5 0 1) (4 1 1) (4 0 2) (4 1
1) (3 2 1) (3 1 2) (3 2 1) (2 3 1) (2 2 2) (2 3 1) (1 4 1) (1 3 2) (1 4 1) (0 5
1) (0 4 2) (4 0 2) (3 1 2) (3 0 3) (3 1 2) (2 2 2) (2 1 3) (2 2 2) (1 3 2) (1 2
3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (1 1 4) (1 2
3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1
5) (0 0 6))) ((3 1 1) ((4 1 1) (3 2 1) (3 1 2) (3 2 1) (2 3 1) (2 2 2) (2 3 1) (
1 4 1) (1 3 2) (1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3 0 3) (3 1 2) (2 2 2) (
2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0 4) (
2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (
0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((2 2 1) ((3 2 1) (2 3 1) (2 2 2) (2 3
1) (1 4 1) (1 3 2) (1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3 0 3) (3 1 2) (2 2
2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0
4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1
4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((1 3 1) ((2 3 1) (1 4 1) (1 3 2) (
1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3 0 3) (3 1 2) (2 2 2) (2 1 3) (2 2 2) (
1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (
1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (
1 0 5) (0 1 5) (0 0 6))) ((0 4 1) ((1 4 1) (0 5 1) (0 4 2) (4 0 2) (3 1 2) (3 0
3) (3 1 2) (2 2 2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0
3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1
4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((3 0 2) ((4 0 2) (
3 1 2) (3 0 3) (3 1 2) (2 2 2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (
0 3 3) (3 0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (
2 0 4) (1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((2 1 2
) ((3 1 2) (2 2 2) (2 1 3) (2 2 2) (1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0
3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1
4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((1 2 2) ((2 2 2) (
1 3 2) (1 2 3) (1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0 4) (2 1 3) (1 2 3) (
1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (
1 0 5) (0 1 5) (0 0 6))) ((0 3 2) ((1 3 2) (0 4 2) (0 3 3) (3 0 3) (2 1 3) (2 0
4) (2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1
4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((2 0 3) ((3 0 3) (2 1 3) (2 0 4) (
2 1 3) (1 2 3) (1 1 4) (1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (
0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((1 1 3) ((2 1 3) (1 2 3) (1 1 4) (1 2
3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (0 2 4) (0 1 5) (1 0 5) (0 1
5) (0 0 6))) ((0 2 3) ((1 2 3) (0 3 3) (0 2 4) (2 0 4) (1 1 4) (1 0 5) (1 1 4) (
0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((1 0 4) ((2 0 4) (1 1 4) (1 0 5) (1 1
4) (0 2 4) (0 1 5) (1 0 5) (0 1 5) (0 0 6))) ((0 1 4) ((1 1 4) (0 2 4) (0 1 5) (
1 0 5) (0 1 5) (0 0 6))) ((0 0 5) ((1 0 5) (0 1 5) (0 0 6))) ((6 0 0) nil) ((5 1
0) nil) ((4 2 0) nil) ((3 3 0) nil) ((2 4 0) nil) ((1 5 0) nil) ((0 6 0) nil) ((
5 0 1) nil) ((4 1 1) nil) ((3 2 1) nil) ((2 3 1) nil) ((1 4 1) nil) ((0 5 1) nil
) ((4 0 2) nil) ((3 1 2) nil) ((2 2 2) nil) ((1 3 2) nil) ((0 4 2) nil) ((3 0 3)
nil) ((2 1 3) nil) ((1 2 3) nil) ((0 3 3) nil) ((2 0 4) nil) ((1 1 4) nil) ((0 2
4) nil) ((1 0 5) nil) ((0 1 5) nil) ((0 0 6) nil))
% all even derivatives in multiindex notation:
all_der_mind!*:=((u (0 0 0)) (u (1 0 0)) (u (0 1 0)) (u (0 0 1)) (u (2 0 0)) (u
(1 1 0)) (u (0 2 0)) (u (1 0 1)) (u (0 1 1)) (u (0 0 2)) (u (3 0 0)) (u (2 1 0))
(u (1 2 0)) (u (0 3 0)) (u (2 0 1)) (u (1 1 1)) (u (0 2 1)) (u (1 0 2)) (u (0 1
2)) (u (0 0 3)) (u (4 0 0)) (u (3 1 0)) (u (2 2 0)) (u (1 3 0)) (u (0 4 0)) (u (
3 0 1)) (u (2 1 1)) (u (1 2 1)) (u (0 3 1)) (u (2 0 2)) (u (1 1 2)) (u (0 2 2))
(u (1 0 3)) (u (0 1 3)) (u (0 0 4)) (u (5 0 0)) (u (4 1 0)) (u (3 2 0)) (u (2 3
0)) (u (1 4 0)) (u (0 5 0)) (u (4 0 1)) (u (3 1 1)) (u (2 2 1)) (u (1 3 1)) (u (
0 4 1)) (u (3 0 2)) (u (2 1 2)) (u (1 2 2)) (u (0 3 2)) (u (2 0 3)) (u (1 1 3))
(u (0 2 3)) (u (1 0 4)) (u (0 1 4)) (u (0 0 5)) (u (6 0 0)) (u (5 1 0)) (u (4 2
0)) (u (3 3 0)) (u (2 4 0)) (u (1 5 0)) (u (0 6 0)) (u (5 0 1)) (u (4 1 1)) (u (
3 2 1)) (u (2 3 1)) (u (1 4 1)) (u (0 5 1)) (u (4 0 2)) (u (3 1 2)) (u (2 2 2))
(u (1 3 2)) (u (0 4 2)) (u (3 0 3)) (u (2 1 3)) (u (1 2 3)) (u (0 3 3)) (u (2 0
4)) (u (1 1 4)) (u (0 2 4)) (u (1 0 5)) (u (0 1 5)) (u (0 0 6)))
% all odd derivatives in multiindex notation:
all_odd_mind!*:=((p (0 0 0)) (p (1 0 0)) (p (0 1 0)) (p (0 0 1)) (p (2 0 0)) (p
(1 1 0)) (p (0 2 0)) (p (1 0 1)) (p (0 1 1)) (p (0 0 2)) (p (3 0 0)) (p (2 1 0))
(p (1 2 0)) (p (0 3 0)) (p (2 0 1)) (p (1 1 1)) (p (0 2 1)) (p (1 0 2)) (p (0 1
2)) (p (0 0 3)) (p (4 0 0)) (p (3 1 0)) (p (2 2 0)) (p (1 3 0)) (p (0 4 0)) (p (
3 0 1)) (p (2 1 1)) (p (1 2 1)) (p (0 3 1)) (p (2 0 2)) (p (1 1 2)) (p (0 2 2))
(p (1 0 3)) (p (0 1 3)) (p (0 0 4)) (p (5 0 0)) (p (4 1 0)) (p (3 2 0)) (p (2 3
0)) (p (1 4 0)) (p (0 5 0)) (p (4 0 1)) (p (3 1 1)) (p (2 2 1)) (p (1 3 1)) (p (
0 4 1)) (p (3 0 2)) (p (2 1 2)) (p (1 2 2)) (p (0 3 2)) (p (2 0 3)) (p (1 1 3))
(p (0 2 3)) (p (1 0 4)) (p (0 1 4)) (p (0 0 5)) (p (6 0 0)) (p (5 1 0)) (p (4 2
0)) (p (3 3 0)) (p (2 4 0)) (p (1 5 0)) (p (0 6 0)) (p (5 0 1)) (p (4 1 1)) (p (
3 2 1)) (p (2 3 1)) (p (1 4 1)) (p (0 5 1)) (p (4 0 2)) (p (3 1 2)) (p (2 2 2))
(p (1 3 2)) (p (0 4 2)) (p (3 0 3)) (p (2 1 3)) (p (1 2 3)) (p (0 3 3)) (p (2 0
4)) (p (1 1 4)) (p (0 2 4)) (p (1 0 5)) (p (0 1 5)) (p (0 0 6)))
% all even derivatives in identifier notation:
all_der_id!*:=(u u_t u_x u_y u_2t u_tx u_2x u_ty u_xy u_2y u_3t u_2tx u_t2x u_3x
u_2ty u_txy u_2xy u_t2y u_x2y u_3y u_4t u_3tx u_2t2x u_t3x u_4x u_3ty u_2txy
u_t2xy u_3xy u_2t2y u_tx2y u_2x2y u_t3y u_x3y u_4y u_5t u_4tx u_3t2x u_2t3x
u_t4x u_5x u_4ty u_3txy u_2t2xy u_t3xy u_4xy u_3t2y u_2tx2y u_t2x2y u_3x2y
u_2t3y u_tx3y u_2x3y u_t4y u_x4y u_5y u_6t u_5tx u_4t2x u_3t3x u_2t4x u_t5x u_6x
u_5ty u_4txy u_3t2xy u_2t3xy u_t4xy u_5xy u_4t2y u_3tx2y u_2t2x2y u_t3x2y u_4x2y
u_3t3y u_2tx3y u_t2x3y u_3x3y u_2t4y u_tx4y u_2x4y u_t5y u_x5y u_6y)
% all odd derivatives in identifier notation:
all_odd_id!*:=(p p_t p_x p_y p_2t p_tx p_2x p_ty p_xy p_2y p_3t p_2tx p_t2x p_3x
p_2ty p_txy p_2xy p_t2y p_x2y p_3y p_4t p_3tx p_2t2x p_t3x p_4x p_3ty p_2txy
p_t2xy p_3xy p_2t2y p_tx2y p_2x2y p_t3y p_x3y p_4y p_5t p_4tx p_3t2x p_2t3x
p_t4x p_5x p_4ty p_3txy p_2t2xy p_t3xy p_4xy p_3t2y p_2tx2y p_t2x2y p_3x2y
p_2t3y p_tx3y p_2x3y p_t4y p_x4y p_5y p_6t p_5tx p_4t2x p_3t3x p_2t4x p_t5x p_6x
p_5ty p_4txy p_3t2xy p_2t3xy p_t4xy p_5xy p_4t2y p_3tx2y p_2t2x2y p_t3x2y p_4x2y
p_3t3y p_2tx3y p_t2x3y p_3x3y p_2t4y p_tx4y p_2x4y p_t5y p_x5y p_6y)
% number of all ext symbols:
n_all_ext:=84
% alist of even derivative coordinates:
i2m_jetspace!*:=((u u (0 0 0)) (u_t u (1 0 0)) (u_x u (0 1 0)) (u_y u (0 0 1)) (
u_2t u (2 0 0)) (u_tx u (1 1 0)) (u_2x u (0 2 0)) (u_ty u (1 0 1)) (u_xy u (0 1
1)) (u_2y u (0 0 2)) (u_3t u (3 0 0)) (u_2tx u (2 1 0)) (u_t2x u (1 2 0)) (u_3x
u (0 3 0)) (u_2ty u (2 0 1)) (u_txy u (1 1 1)) (u_2xy u (0 2 1)) (u_t2y u (1 0 2
)) (u_x2y u (0 1 2)) (u_3y u (0 0 3)) (u_4t u (4 0 0)) (u_3tx u (3 1 0)) (u_2t2x
u (2 2 0)) (u_t3x u (1 3 0)) (u_4x u (0 4 0)) (u_3ty u (3 0 1)) (u_2txy u (2 1 1
)) (u_t2xy u (1 2 1)) (u_3xy u (0 3 1)) (u_2t2y u (2 0 2)) (u_tx2y u (1 1 2)) (
u_2x2y u (0 2 2)) (u_t3y u (1 0 3)) (u_x3y u (0 1 3)) (u_4y u (0 0 4)) (u_5t u (
5 0 0)) (u_4tx u (4 1 0)) (u_3t2x u (3 2 0)) (u_2t3x u (2 3 0)) (u_t4x u (1 4 0)
) (u_5x u (0 5 0)) (u_4ty u (4 0 1)) (u_3txy u (3 1 1)) (u_2t2xy u (2 2 1)) (
u_t3xy u (1 3 1)) (u_4xy u (0 4 1)) (u_3t2y u (3 0 2)) (u_2tx2y u (2 1 2)) (
u_t2x2y u (1 2 2)) (u_3x2y u (0 3 2)) (u_2t3y u (2 0 3)) (u_tx3y u (1 1 3)) (
u_2x3y u (0 2 3)) (u_t4y u (1 0 4)) (u_x4y u (0 1 4)) (u_5y u (0 0 5)) (u_6t u (
6 0 0)) (u_5tx u (5 1 0)) (u_4t2x u (4 2 0)) (u_3t3x u (3 3 0)) (u_2t4x u (2 4 0
)) (u_t5x u (1 5 0)) (u_6x u (0 6 0)) (u_5ty u (5 0 1)) (u_4txy u (4 1 1)) (
u_3t2xy u (3 2 1)) (u_2t3xy u (2 3 1)) (u_t4xy u (1 4 1)) (u_5xy u (0 5 1)) (
u_4t2y u (4 0 2)) (u_3tx2y u (3 1 2)) (u_2t2x2y u (2 2 2)) (u_t3x2y u (1 3 2)) (
u_4x2y u (0 4 2)) (u_3t3y u (3 0 3)) (u_2tx3y u (2 1 3)) (u_t2x3y u (1 2 3)) (
u_3x3y u (0 3 3)) (u_2t4y u (2 0 4)) (u_tx4y u (1 1 4)) (u_2x4y u (0 2 4)) (
u_t5y u (1 0 5)) (u_x5y u (0 1 5)) (u_6y u (0 0 6)))
% alist of odd derivative coordinates:
i2m_jetspace_odd!*:=((p p (0 0 0)) (p_t p (1 0 0)) (p_x p (0 1 0)) (p_y p (0 0 1
)) (p_2t p (2 0 0)) (p_tx p (1 1 0)) (p_2x p (0 2 0)) (p_ty p (1 0 1)) (p_xy p (
0 1 1)) (p_2y p (0 0 2)) (p_3t p (3 0 0)) (p_2tx p (2 1 0)) (p_t2x p (1 2 0)) (
p_3x p (0 3 0)) (p_2ty p (2 0 1)) (p_txy p (1 1 1)) (p_2xy p (0 2 1)) (p_t2y p (
1 0 2)) (p_x2y p (0 1 2)) (p_3y p (0 0 3)) (p_4t p (4 0 0)) (p_3tx p (3 1 0)) (
p_2t2x p (2 2 0)) (p_t3x p (1 3 0)) (p_4x p (0 4 0)) (p_3ty p (3 0 1)) (p_2txy p
(2 1 1)) (p_t2xy p (1 2 1)) (p_3xy p (0 3 1)) (p_2t2y p (2 0 2)) (p_tx2y p (1 1
2)) (p_2x2y p (0 2 2)) (p_t3y p (1 0 3)) (p_x3y p (0 1 3)) (p_4y p (0 0 4)) (
p_5t p (5 0 0)) (p_4tx p (4 1 0)) (p_3t2x p (3 2 0)) (p_2t3x p (2 3 0)) (p_t4x p
(1 4 0)) (p_5x p (0 5 0)) (p_4ty p (4 0 1)) (p_3txy p (3 1 1)) (p_2t2xy p (2 2 1
)) (p_t3xy p (1 3 1)) (p_4xy p (0 4 1)) (p_3t2y p (3 0 2)) (p_2tx2y p (2 1 2)) (
p_t2x2y p (1 2 2)) (p_3x2y p (0 3 2)) (p_2t3y p (2 0 3)) (p_tx3y p (1 1 3)) (
p_2x3y p (0 2 3)) (p_t4y p (1 0 4)) (p_x4y p (0 1 4)) (p_5y p (0 0 5)) (p_6t p (
6 0 0)) (p_5tx p (5 1 0)) (p_4t2x p (4 2 0)) (p_3t3x p (3 3 0)) (p_2t4x p (2 4 0
)) (p_t5x p (1 5 0)) (p_6x p (0 6 0)) (p_5ty p (5 0 1)) (p_4txy p (4 1 1)) (
p_3t2xy p (3 2 1)) (p_2t3xy p (2 3 1)) (p_t4xy p (1 4 1)) (p_5xy p (0 5 1)) (
p_4t2y p (4 0 2)) (p_3tx2y p (3 1 2)) (p_2t2x2y p (2 2 2)) (p_t3x2y p (1 3 2)) (
p_4x2y p (0 4 2)) (p_3t3y p (3 0 3)) (p_2tx3y p (2 1 3)) (p_t2x3y p (1 2 3)) (
p_3x3y p (0 3 3)) (p_2t4y p (2 0 4)) (p_tx4y p (1 1 4)) (p_2x4y p (0 2 4)) (
p_t5y p (1 0 5)) (p_x5y p (0 1 5)) (p_6y p (0 0 6)))
% alist of even derivative coordinates - order of derivative:
i2o_jetspace!*:=((u . 0) (u_t . 1) (u_x . 1) (u_y . 1) (u_2t . 2) (u_tx . 2) (
u_2x . 2) (u_ty . 2) (u_xy . 2) (u_2y . 2) (u_3t . 3) (u_2tx . 3) (u_t2x . 3) (
u_3x . 3) (u_2ty . 3) (u_txy . 3) (u_2xy . 3) (u_t2y . 3) (u_x2y . 3) (u_3y . 3)
(u_4t . 4) (u_3tx . 4) (u_2t2x . 4) (u_t3x . 4) (u_4x . 4) (u_3ty . 4) (u_2txy .
4) (u_t2xy . 4) (u_3xy . 4) (u_2t2y . 4) (u_tx2y . 4) (u_2x2y . 4) (u_t3y . 4) (
u_x3y . 4) (u_4y . 4) (u_5t . 5) (u_4tx . 5) (u_3t2x . 5) (u_2t3x . 5) (u_t4x .
5) (u_5x . 5) (u_4ty . 5) (u_3txy . 5) (u_2t2xy . 5) (u_t3xy . 5) (u_4xy . 5) (
u_3t2y . 5) (u_2tx2y . 5) (u_t2x2y . 5) (u_3x2y . 5) (u_2t3y . 5) (u_tx3y . 5) (
u_2x3y . 5) (u_t4y . 5) (u_x4y . 5) (u_5y . 5) (u_6t . 6) (u_5tx . 6) (u_4t2x .
6) (u_3t3x . 6) (u_2t4x . 6) (u_t5x . 6) (u_6x . 6) (u_5ty . 6) (u_4txy . 6) (
u_3t2xy . 6) (u_2t3xy . 6) (u_t4xy . 6) (u_5xy . 6) (u_4t2y . 6) (u_3tx2y . 6) (
u_2t2x2y . 6) (u_t3x2y . 6) (u_4x2y . 6) (u_3t3y . 6) (u_2tx3y . 6) (u_t2x3y . 6
) (u_3x3y . 6) (u_2t4y . 6) (u_tx4y . 6) (u_2x4y . 6) (u_t5y . 6) (u_x5y . 6) (
u_6y . 6))
% alist of odd derivative coordinates - order of derivative:
i2o_jetspace_odd!*:=((p . 0) (p_t . 1) (p_x . 1) (p_y . 1) (p_2t . 2) (p_tx . 2)
(p_2x . 2) (p_ty . 2) (p_xy . 2) (p_2y . 2) (p_3t . 3) (p_2tx . 3) (p_t2x . 3) (
p_3x . 3) (p_2ty . 3) (p_txy . 3) (p_2xy . 3) (p_t2y . 3) (p_x2y . 3) (p_3y . 3)
(p_4t . 4) (p_3tx . 4) (p_2t2x . 4) (p_t3x . 4) (p_4x . 4) (p_3ty . 4) (p_2txy .
4) (p_t2xy . 4) (p_3xy . 4) (p_2t2y . 4) (p_tx2y . 4) (p_2x2y . 4) (p_t3y . 4) (
p_x3y . 4) (p_4y . 4) (p_5t . 5) (p_4tx . 5) (p_3t2x . 5) (p_2t3x . 5) (p_t4x .
5) (p_5x . 5) (p_4ty . 5) (p_3txy . 5) (p_2t2xy . 5) (p_t3xy . 5) (p_4xy . 5) (
p_3t2y . 5) (p_2tx2y . 5) (p_t2x2y . 5) (p_3x2y . 5) (p_2t3y . 5) (p_tx3y . 5) (
p_2x3y . 5) (p_t4y . 5) (p_x4y . 5) (p_5y . 5) (p_6t . 6) (p_5tx . 6) (p_4t2x .
6) (p_3t3x . 6) (p_2t4x . 6) (p_t5x . 6) (p_6x . 6) (p_5ty . 6) (p_4txy . 6) (
p_3t2xy . 6) (p_2t3xy . 6) (p_t4xy . 6) (p_5xy . 6) (p_4t2y . 6) (p_3tx2y . 6) (
p_2t2x2y . 6) (p_t3x2y . 6) (p_4x2y . 6) (p_3t3y . 6) (p_2tx3y . 6) (p_t2x3y . 6
) (p_3x3y . 6) (p_2t4y . 6) (p_tx4y . 6) (p_2x4y . 6) (p_t5y . 6) (p_x5y . 6) (
p_6y . 6))
% list of even principal derivatives:
all_principal_der!*:=(u_2y u_3y u_x2y u_t2y u_4y u_x3y u_t3y u_2x2y u_tx2y
u_2t2y u_5y u_x4y u_t4y u_2x3y u_tx3y u_2t3y u_3x2y u_t2x2y u_2tx2y u_3t2y u_6y
u_x5y u_t5y u_2x4y u_tx4y u_2t4y u_3x3y u_t2x3y u_2tx3y u_3t3y u_4x2y u_t3x2y
u_2t2x2y u_3tx2y u_4t2y)
% list of even parametric derivatives:
all_parametric_der!*:=(u u_t u_x u_y u_2t u_tx u_2x u_ty u_xy u_3t u_2tx u_t2x
u_3x u_2ty u_txy u_2xy u_4t u_3tx u_2t2x u_t3x u_4x u_3ty u_2txy u_t2xy u_3xy
u_5t u_4tx u_3t2x u_2t3x u_t4x u_5x u_4ty u_3txy u_2t2xy u_t3xy u_4xy u_6t u_5tx
u_4t2x u_3t3x u_2t4x u_t5x u_6x u_5ty u_4txy u_3t2xy u_2t3xy u_t4xy u_5xy)
% list of odd principal derivatives:
all_principal_odd!*:=(p_2y p_3y p_x2y p_t2y p_4y p_x3y p_t3y p_2x2y p_tx2y
p_2t2y p_5y p_x4y p_t4y p_2x3y p_tx3y p_2t3y p_3x2y p_t2x2y p_2tx2y p_3t2y p_6y
p_x5y p_t5y p_2x4y p_tx4y p_2t4y p_3x3y p_t2x3y p_2tx3y p_3t3y p_4x2y p_t3x2y
p_2t2x2y p_3tx2y p_4t2y)
p_2y = (ext 50)
p_3y = (ext 51)
p_x2y = (ext 52)
p_t2y = (ext 53)
p_4y = (ext 54)
p_x3y = (ext 55)
p_t3y = (ext 56)
p_2x2y = (ext 57)
p_tx2y = (ext 58)
p_2t2y = (ext 59)
p_5y = (ext 60)
p_x4y = (ext 61)
p_t4y = (ext 62)
p_2x3y = (ext 63)
p_tx3y = (ext 64)
p_2t3y = (ext 65)
p_3x2y = (ext 66)
p_t2x2y = (ext 67)
p_2tx2y = (ext 68)
p_3t2y = (ext 69)
p_6y = (ext 70)
p_x5y = (ext 71)
p_t5y = (ext 72)
p_2x4y = (ext 73)
p_tx4y = (ext 74)
p_2t4y = (ext 75)
p_3x3y = (ext 76)
p_t2x3y = (ext 77)
p_2tx3y = (ext 78)
p_3t3y = (ext 79)
p_4x2y = (ext 80)
p_t3x2y = (ext 81)
p_2t2x2y = (ext 82)
p_3tx2y = (ext 83)
p_4t2y = (ext 84)
% list of odd parametric derivatives:
all_parametric_odd!*:=(p p_t p_x p_y p_2t p_tx p_2x p_ty p_xy p_3t p_2tx p_t2x
p_3x p_2ty p_txy p_2xy p_4t p_3tx p_2t2x p_t3x p_4x p_3ty p_2txy p_t2xy p_3xy
p_5t p_4tx p_3t2x p_2t3x p_t4x p_5x p_4ty p_3txy p_2t2xy p_t3xy p_4xy p_6t p_5tx
p_4t2x p_3t3x p_2t4x p_t5x p_6x p_5ty p_4txy p_3t2xy p_2t3xy p_t4xy p_5xy)
p = (ext 1)
p_t = (ext 2)
p_x = (ext 3)
p_y = (ext 4)
p_2t = (ext 5)
p_tx = (ext 6)
p_2x = (ext 7)
p_ty = (ext 8)
p_xy = (ext 9)
p_3t = (ext 10)
p_2tx = (ext 11)
p_t2x = (ext 12)
p_3x = (ext 13)
p_2ty = (ext 14)
p_txy = (ext 15)
p_2xy = (ext 16)
p_4t = (ext 17)
p_3tx = (ext 18)
p_2t2x = (ext 19)
p_t3x = (ext 20)
p_4x = (ext 21)
p_3ty = (ext 22)
p_2txy = (ext 23)
p_t2xy = (ext 24)
p_3xy = (ext 25)
p_5t = (ext 26)
p_4tx = (ext 27)
p_3t2x = (ext 28)
p_2t3x = (ext 29)
p_t4x = (ext 30)
p_5x = (ext 31)
p_4ty = (ext 32)
p_3txy = (ext 33)
p_2t2xy = (ext 34)
p_t3xy = (ext 35)
p_4xy = (ext 36)
p_6t = (ext 37)
p_5tx = (ext 38)
p_4t2x = (ext 39)
p_3t3x = (ext 40)
p_2t4x = (ext 41)
p_t5x = (ext 42)
p_6x = (ext 43)
p_5ty = (ext 44)
p_4txy = (ext 45)
p_3t2xy = (ext 46)
p_2t3xy = (ext 47)
p_t4xy = (ext 48)
p_5xy = (ext 49)
% number of ext principal derivatives:
n_all_principal_ext:=35
% number of ext parametric derivatives:
n_all_parametric_ext:=49
% set of identifiers for total derivatives:
tot_der!*:=(ddt ddx ddy)
% set up the auxiliary variable `letop'
for each el in indep_var do depend letop,el;
% Characterization of primary differential consequences:
primary_diffcon_der_tot!*:=((ddy 0 7 u_2y) (ddy 0 11 u_t2y) (ddy 0 12 u_x2y) (
ddy 0 17 u_2t2y) (ddy 0 18 u_tx2y) (ddy 0 19 u_2x2y) (ddy 0 25 u_3t2y) (ddy 0 26
u_2tx2y) (ddy 0 27 u_t2x2y) (ddy 0 28 u_3x2y) (ddy 0 35 u_4t2y) (ddy 0 36
u_3tx2y) (ddy 0 37 u_2t2x2y) (ddy 0 38 u_t3x2y) (ddy 0 39 u_4x2y))
primary_diffcon_odd_tot!*:=((ddy 1 4 p_2y) (ddy 1 8 p_t2y) (ddy 1 9 p_x2y) (ddy
1 14 p_2t2y) (ddy 1 15 p_tx2y) (ddy 1 16 p_2x2y) (ddy 1 22 p_3t2y) (ddy 1 23
p_2tx2y) (ddy 1 24 p_t2x2y) (ddy 1 25 p_3x2y) (ddy 1 32 p_4t2y) (ddy 1 33
p_3tx2y) (ddy 1 34 p_2t2x2y) (ddy 1 35 p_t3x2y) (ddy 1 36 p_4x2y))
primary_diffcon_der!*:=(u_t2y u_x2y u_2t2y u_tx2y u_2x2y u_3t2y u_2tx2y u_t2x2y
u_3x2y u_4t2y u_3tx2y u_2t2x2y u_t3x2y u_4x2y)
primary_diffcon_odd!*:=(p_t2y p_x2y p_2t2y p_tx2y p_2x2y p_3t2y p_2tx2y p_t2x2y
p_3x2y p_4t2y p_3tx2y p_2t2x2y p_t3x2y p_4x2y)
% Alists of differential conseq. needed in total derivatives:
diffcon_der!*:=((u_4x2y (*sq ((((letop . 1) . 1)) . 1) nil)) (u_t3x2y (*sq ((((
letop . 1) . 1)) . 1) nil)) (u_2t2x2y (*sq ((((letop . 1) . 1)) . 1) nil)) (
u_3tx2y (*sq ((((letop . 1) . 1)) . 1) nil)) (u_4t2y (*sq ((((letop . 1) . 1)) .
1) nil)) (u_3x2y (*sq ((((letop . 1) . 1)) . 1) nil)) (u_t2x2y (*sq ((((letop .
1) . 1)) . 1) nil)) (u_2tx2y (*sq ((((letop . 1) . 1)) . 1) nil)) (u_3t2y (*sq (
(((letop . 1) . 1)) . 1) nil)) (u_2x2y (*sq ((((u . 1) ((u_4x . 1) . -12)) ((
u_2x . 2) . -36) ((u_3x . 1) ((u_x . 1) . -48)) ((u_6x . 1) . -1) ((u_t3x . 1) .
12)) . 12) nil)) (u_tx2y (*sq ((((u . 1) ((u_t3x . 1) . -12)) ((u_2t2x . 1) . 12
) ((u_2x . 1) ((u_tx . 1) . -36)) ((u_3x . 1) ((u_t . 1) . -12)) ((u_t2x . 1) ((
u_x . 1) . -36)) ((u_t5x . 1) . -1)) . 12) nil)) (u_2t2y (*sq ((((u . 1) ((
u_2t2x . 1) . -12)) ((u_2t . 1) ((u_2x . 1) . -12)) ((u_2t4x . 1) . -1) ((u_2tx
. 1) ((u_x . 1) . -24)) ((u_3tx . 1) . 12) ((u_t . 1) ((u_t2x . 1) . -24)) ((
u_tx . 2) . -24)) . 12) nil)) (u_x2y (*sq ((((u . 1) ((u_3x . 1) . -12)) ((u_2x
. 1) ((u_x . 1) . -36)) ((u_5x . 1) . -1) ((u_t2x . 1) . 12)) . 12) nil)) (u_t2y
(*sq ((((u . 1) ((u_t2x . 1) . -12)) ((u_2tx . 1) . 12) ((u_2x . 1) ((u_t . 1) .
-12)) ((u_t4x . 1) . -1) ((u_tx . 1) ((u_x . 1) . -24))) . 12) nil)) (u_2y (
quotient (plus (minus (times 12 u u_2x)) (minus u_4x) (times 12 u_tx) (minus (
times 12 (expt u_x 2)))) 12)))
diffcon_odd!*:=((p_4x2y (*sq ((((letop . 1) . 1)) . 1) nil)) (p_t3x2y (*sq ((((
letop . 1) . 1)) . 1) nil)) (p_2t2x2y (*sq ((((letop . 1) . 1)) . 1) nil)) (
p_3tx2y (*sq ((((letop . 1) . 1)) . 1) nil)) (p_4t2y (*sq ((((letop . 1) . 1)) .
1) nil)) (p_3x2y (*sq ((((letop . 1) . 1)) . 1) nil)) (p_t2x2y (*sq ((((letop .
1) . 1)) . 1) nil)) (p_2tx2y (*sq ((((letop . 1) . 1)) . 1) nil)) (p_3t2y (*sq (
(((letop . 1) . 1)) . 1) nil)) (p_2x2y (*sq (((((ext 43) . 1) . -1) (((ext 21) .
1) ((u . 1) . -12)) (((ext 20) . 1) . 12) (((ext 13) . 1) ((u_x . 1) . -24)) (((
ext 7) . 1) ((u_2x . 1) . -12))) . 12) nil)) (p_tx2y (*sq (((((ext 42) . 1) . -1
) (((ext 20) . 1) ((u . 1) . -12)) (((ext 19) . 1) . 12) (((ext 13) . 1) ((u_t .
1) . -12)) (((ext 12) . 1) ((u_x . 1) . -12)) (((ext 7) . 1) ((u_tx . 1) . -12))
) . 12) nil)) (p_2t2y (*sq (((((ext 41) . 1) . -1) (((ext 19) . 1) ((u . 1) .
-12)) (((ext 18) . 1) . 12) (((ext 12) . 1) ((u_t . 1) . -24)) (((ext 7) . 1) ((
u_2t . 1) . -12))) . 12) nil)) (p_x2y (*sq (((((ext 31) . 1) . -1) (((ext 13) .
1) ((u . 1) . -12)) (((ext 12) . 1) . 12) (((ext 7) . 1) ((u_x . 1) . -12))) .
12) nil)) (p_t2y (*sq (((((ext 30) . 1) . -1) (((ext 12) . 1) ((u . 1) . -12)) (
((ext 11) . 1) . 12) (((ext 7) . 1) ((u_t . 1) . -12))) . 12) nil)) (p_2y (*sq (
((((ext 21) . 1) . -1) (((ext 7) . 1) ((u . 1) . -12)) (((ext 6) . 1) . 12)) .
12) nil)))
% Principal derivatives computed:
diffcon_comp_der!*:=(u_4x2y u_t3x2y u_2t2x2y u_3tx2y u_4t2y u_3x2y u_t2x2y
u_2tx2y u_3t2y u_2x2y u_tx2y u_2t2y u_x2y u_t2y u_2y)
diffcon_comp_odd!*:=(p_4x2y p_t3x2y p_2t2x2y p_3tx2y p_4t2y p_3x2y p_t2x2y
p_2tx2y p_3t2y p_2x2y p_tx2y p_2t2y p_x2y p_t2y p_2y)
diffcon_comp_ext!*:=((ext 80) (ext 81) (ext 82) (ext 83) (ext 84) (ext 66) (ext
67) (ext 68) (ext 69) (ext 57) (ext 58) (ext 59) (ext 52) (ext 53) (ext 50))
% Alists of principal derivatives in terms of parametric expr.:
diffcon_param_der!*:=((u_4x2y *sq ((((letop . 1) . 1)) . 1) nil) (u_t3x2y *sq ((
((letop . 1) . 1)) . 1) nil) (u_2t2x2y *sq ((((letop . 1) . 1)) . 1) nil) (
u_3tx2y *sq ((((letop . 1) . 1)) . 1) nil) (u_4t2y *sq ((((letop . 1) . 1)) . 1)
nil) (u_3x2y *sq ((((letop . 1) . 1)) . 1) nil) (u_t2x2y *sq ((((letop . 1) . 1)
) . 1) nil) (u_2tx2y *sq ((((letop . 1) . 1)) . 1) nil) (u_3t2y *sq ((((letop .
1) . 1)) . 1) nil) (u_2x2y *sq ((((u . 1) ((u_4x . 1) . -12)) ((u_2x . 2) . -36)
((u_3x . 1) ((u_x . 1) . -48)) ((u_6x . 1) . -1) ((u_t3x . 1) . 12)) . 12) nil)
(u_tx2y *sq ((((u . 1) ((u_t3x . 1) . -12)) ((u_2t2x . 1) . 12) ((u_2x . 1) ((
u_tx . 1) . -36)) ((u_3x . 1) ((u_t . 1) . -12)) ((u_t2x . 1) ((u_x . 1) . -36))
((u_t5x . 1) . -1)) . 12) nil) (u_2t2y *sq ((((u . 1) ((u_2t2x . 1) . -12)) ((
u_2t . 1) ((u_2x . 1) . -12)) ((u_2t4x . 1) . -1) ((u_2tx . 1) ((u_x . 1) . -24)
) ((u_3tx . 1) . 12) ((u_t . 1) ((u_t2x . 1) . -24)) ((u_tx . 2) . -24)) . 12)
nil) (u_x2y *sq ((((u . 1) ((u_3x . 1) . -12)) ((u_2x . 1) ((u_x . 1) . -36)) ((
u_5x . 1) . -1) ((u_t2x . 1) . 12)) . 12) nil) (u_t2y *sq ((((u . 1) ((u_t2x . 1
) . -12)) ((u_2tx . 1) . 12) ((u_2x . 1) ((u_t . 1) . -12)) ((u_t4x . 1) . -1) (
(u_tx . 1) ((u_x . 1) . -24))) . 12) nil) (u_2y *sq ((((u . 1) ((u_2x . 1) . -12
)) ((u_4x . 1) . -1) ((u_tx . 1) . 12) ((u_x . 2) . -12)) . 12) nil))
diffcon_param_ext!*:=(((ext 80) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 81) *sq
((((letop . 1) . 1)) . 1) nil) ((ext 82) *sq ((((letop . 1) . 1)) . 1) nil) ((
ext 83) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 84) *sq ((((letop . 1) . 1)) .
1) nil) ((ext 66) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 67) *sq ((((letop . 1
) . 1)) . 1) nil) ((ext 68) *sq ((((letop . 1) . 1)) . 1) nil) ((ext 69) *sq (((
(letop . 1) . 1)) . 1) nil) ((ext 57) *sq (((((ext 43) . 1) . -1) (((ext 21) . 1
) ((u . 1) . -12)) (((ext 20) . 1) . 12) (((ext 13) . 1) ((u_x . 1) . -24)) (((
ext 7) . 1) ((u_2x . 1) . -12))) . 12) nil) ((ext 58) *sq (((((ext 42) . 1) . -1
) (((ext 20) . 1) ((u . 1) . -12)) (((ext 19) . 1) . 12) (((ext 13) . 1) ((u_t .
1) . -12)) (((ext 12) . 1) ((u_x . 1) . -12)) (((ext 7) . 1) ((u_tx . 1) . -12))
) . 12) nil) ((ext 59) *sq (((((ext 41) . 1) . -1) (((ext 19) . 1) ((u . 1) .
-12)) (((ext 18) . 1) . 12) (((ext 12) . 1) ((u_t . 1) . -24)) (((ext 7) . 1) ((
u_2t . 1) . -12))) . 12) nil) ((ext 52) *sq (((((ext 31) . 1) . -1) (((ext 13) .
1) ((u . 1) . -12)) (((ext 12) . 1) . 12) (((ext 7) . 1) ((u_x . 1) . -12))) .
12) nil) ((ext 53) *sq (((((ext 30) . 1) . -1) (((ext 12) . 1) ((u . 1) . -12))
(((ext 11) . 1) . 12) (((ext 7) . 1) ((u_t . 1) . -12))) . 12) nil) ((ext 50)
*sq (((((ext 21) . 1) . -1) (((ext 7) . 1) ((u . 1) . -12)) (((ext 6) . 1) . 12)
) . 12) nil))
% Coefficients of total derivatives:
% component of ddt w.r.t. t
ddt(0,1):=1
% component of ddt w.r.t. x
ddt(0,2):=0
% component of ddt w.r.t. y
ddt(0,3):=0
% component of ddt w.r.t. u
ddt(0,4):=(*sq ((((u_t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t
ddt(0,5):=(*sq ((((u_2t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x
ddt(0,6):=(*sq ((((u_tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_y
ddt(0,7):=(*sq ((((u_ty . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t
ddt(0,8):=(*sq ((((u_3t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_tx
ddt(0,9):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x
ddt(0,10):=(*sq ((((u_t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_ty
ddt(0,11):=(*sq ((((u_2ty . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_xy
ddt(0,12):=(*sq ((((u_txy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t
ddt(0,13):=(*sq ((((u_4t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2tx
ddt(0,14):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2x
ddt(0,15):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x
ddt(0,16):=(*sq ((((u_t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2ty
ddt(0,17):=(*sq ((((u_3ty . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_txy
ddt(0,18):=(*sq ((((u_2txy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2xy
ddt(0,19):=(*sq ((((u_t2xy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t
ddt(0,20):=(*sq ((((u_5t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3tx
ddt(0,21):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t2x
ddt(0,22):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t3x
ddt(0,23):=(*sq ((((u_2t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x
ddt(0,24):=(*sq ((((u_t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3ty
ddt(0,25):=(*sq ((((u_4ty . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2txy
ddt(0,26):=(*sq ((((u_3txy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2xy
ddt(0,27):=(*sq ((((u_2t2xy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3xy
ddt(0,28):=(*sq ((((u_t3xy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5t
ddt(0,29):=(*sq ((((u_6t . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4tx
ddt(0,30):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t2x
ddt(0,31):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t3x
ddt(0,32):=(*sq ((((u_3t3x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t4x
ddt(0,33):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5x
ddt(0,34):=(*sq ((((u_t5x . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4ty
ddt(0,35):=(*sq ((((u_5ty . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3txy
ddt(0,36):=(*sq ((((u_4txy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t2xy
ddt(0,37):=(*sq ((((u_3t2xy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t3xy
ddt(0,38):=(*sq ((((u_2t3xy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4xy
ddt(0,39):=(*sq ((((u_t4xy . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6t
ddt(0,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5tx
ddt(0,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t2x
ddt(0,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t3x
ddt(0,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t4x
ddt(0,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t5x
ddt(0,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6x
ddt(0,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5ty
ddt(0,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4txy
ddt(0,48):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t2xy
ddt(0,49):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t3xy
ddt(0,50):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t4xy
ddt(0,51):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5xy
ddt(0,52):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2y
ddt(0,53):=(*sq ((((u_t2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3y
ddt(0,54):=(*sq ((((u_t3y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x2y
ddt(0,55):=(*sq ((((u_tx2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2y
ddt(0,56):=(*sq ((((u_2t2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4y
ddt(0,57):=(*sq ((((u_t4y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x3y
ddt(0,58):=(*sq ((((u_tx3y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t3y
ddt(0,59):=(*sq ((((u_2t3y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x2y
ddt(0,60):=(*sq ((((u_t2x2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_tx2y
ddt(0,61):=(*sq ((((u_2tx2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t2y
ddt(0,62):=(*sq ((((u_3t2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_5y
ddt(0,63):=(*sq ((((u_t5y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x4y
ddt(0,64):=(*sq ((((u_tx4y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t4y
ddt(0,65):=(*sq ((((u_2t4y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x3y
ddt(0,66):=(*sq ((((u_t2x3y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_tx3y
ddt(0,67):=(*sq ((((u_2tx3y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t3y
ddt(0,68):=(*sq ((((u_3t3y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x2y
ddt(0,69):=(*sq ((((u_t3x2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2x2y
ddt(0,70):=(*sq ((((u_2t2x2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2tx2y
ddt(0,71):=(*sq ((((u_3tx2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t2y
ddt(0,72):=(*sq ((((u_4t2y . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_6y
ddt(0,73):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_x5y
ddt(0,74):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t5y
ddt(0,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2x4y
ddt(0,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_tx4y
ddt(0,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t4y
ddt(0,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3x3y
ddt(0,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t2x3y
ddt(0,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2tx3y
ddt(0,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3t3y
ddt(0,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4x2y
ddt(0,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_t3x2y
ddt(0,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_2t2x2y
ddt(0,85):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_3tx2y
ddt(0,86):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. u_4t2y
ddt(0,87):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p
ddt(1,1):=(*sq (((((ext 2) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t
ddt(1,2):=(*sq (((((ext 5) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x
ddt(1,3):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_y
ddt(1,4):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t
ddt(1,5):=(*sq (((((ext 10) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_tx
ddt(1,6):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x
ddt(1,7):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_ty
ddt(1,8):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_xy
ddt(1,9):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t
ddt(1,10):=(*sq (((((ext 17) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2tx
ddt(1,11):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t2x
ddt(1,12):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x
ddt(1,13):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2ty
ddt(1,14):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_txy
ddt(1,15):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2xy
ddt(1,16):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t
ddt(1,17):=(*sq (((((ext 26) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3tx
ddt(1,18):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t2x
ddt(1,19):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t3x
ddt(1,20):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x
ddt(1,21):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3ty
ddt(1,22):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2txy
ddt(1,23):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t2xy
ddt(1,24):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3xy
ddt(1,25):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5t
ddt(1,26):=(*sq (((((ext 37) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4tx
ddt(1,27):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t2x
ddt(1,28):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t3x
ddt(1,29):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t4x
ddt(1,30):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5x
ddt(1,31):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4ty
ddt(1,32):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3txy
ddt(1,33):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t2xy
ddt(1,34):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t3xy
ddt(1,35):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4xy
ddt(1,36):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6t
ddt(1,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5tx
ddt(1,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t2x
ddt(1,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t3x
ddt(1,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t4x
ddt(1,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t5x
ddt(1,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6x
ddt(1,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5ty
ddt(1,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4txy
ddt(1,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t2xy
ddt(1,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t3xy
ddt(1,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t4xy
ddt(1,48):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5xy
ddt(1,49):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2y
ddt(1,50):=(*sq (((((ext 53) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3y
ddt(1,51):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x2y
ddt(1,52):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t2y
ddt(1,53):=(*sq (((((ext 59) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4y
ddt(1,54):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x3y
ddt(1,55):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t3y
ddt(1,56):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x2y
ddt(1,57):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_tx2y
ddt(1,58):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t2y
ddt(1,59):=(*sq (((((ext 69) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_5y
ddt(1,60):=(*sq (((((ext 72) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x4y
ddt(1,61):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t4y
ddt(1,62):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x3y
ddt(1,63):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_tx3y
ddt(1,64):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t3y
ddt(1,65):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x2y
ddt(1,66):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t2x2y
ddt(1,67):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2tx2y
ddt(1,68):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t2y
ddt(1,69):=(*sq (((((ext 84) . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_6y
ddt(1,70):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_x5y
ddt(1,71):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t5y
ddt(1,72):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2x4y
ddt(1,73):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_tx4y
ddt(1,74):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t4y
ddt(1,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3x3y
ddt(1,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t2x3y
ddt(1,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2tx3y
ddt(1,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3t3y
ddt(1,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4x2y
ddt(1,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_t3x2y
ddt(1,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_2t2x2y
ddt(1,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_3tx2y
ddt(1,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddt w.r.t. p_4t2y
ddt(1,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. t
ddx(0,1):=0
% component of ddx w.r.t. x
ddx(0,2):=1
% component of ddx w.r.t. y
ddx(0,3):=0
% component of ddx w.r.t. u
ddx(0,4):=(*sq ((((u_x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t
ddx(0,5):=(*sq ((((u_tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x
ddx(0,6):=(*sq ((((u_2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_y
ddx(0,7):=(*sq ((((u_xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t
ddx(0,8):=(*sq ((((u_2tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_tx
ddx(0,9):=(*sq ((((u_t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x
ddx(0,10):=(*sq ((((u_3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_ty
ddx(0,11):=(*sq ((((u_txy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_xy
ddx(0,12):=(*sq ((((u_2xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t
ddx(0,13):=(*sq ((((u_3tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2tx
ddx(0,14):=(*sq ((((u_2t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2x
ddx(0,15):=(*sq ((((u_t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x
ddx(0,16):=(*sq ((((u_4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2ty
ddx(0,17):=(*sq ((((u_2txy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_txy
ddx(0,18):=(*sq ((((u_t2xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2xy
ddx(0,19):=(*sq ((((u_3xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t
ddx(0,20):=(*sq ((((u_4tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3tx
ddx(0,21):=(*sq ((((u_3t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t2x
ddx(0,22):=(*sq ((((u_2t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t3x
ddx(0,23):=(*sq ((((u_t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x
ddx(0,24):=(*sq ((((u_5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3ty
ddx(0,25):=(*sq ((((u_3txy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2txy
ddx(0,26):=(*sq ((((u_2t2xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2xy
ddx(0,27):=(*sq ((((u_t3xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3xy
ddx(0,28):=(*sq ((((u_4xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5t
ddx(0,29):=(*sq ((((u_5tx . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4tx
ddx(0,30):=(*sq ((((u_4t2x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t2x
ddx(0,31):=(*sq ((((u_3t3x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t3x
ddx(0,32):=(*sq ((((u_2t4x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t4x
ddx(0,33):=(*sq ((((u_t5x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5x
ddx(0,34):=(*sq ((((u_6x . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4ty
ddx(0,35):=(*sq ((((u_4txy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3txy
ddx(0,36):=(*sq ((((u_3t2xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t2xy
ddx(0,37):=(*sq ((((u_2t3xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t3xy
ddx(0,38):=(*sq ((((u_t4xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4xy
ddx(0,39):=(*sq ((((u_5xy . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6t
ddx(0,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5tx
ddx(0,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t2x
ddx(0,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t3x
ddx(0,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t4x
ddx(0,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t5x
ddx(0,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6x
ddx(0,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5ty
ddx(0,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4txy
ddx(0,48):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t2xy
ddx(0,49):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t3xy
ddx(0,50):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t4xy
ddx(0,51):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5xy
ddx(0,52):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2y
ddx(0,53):=(*sq ((((u_x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3y
ddx(0,54):=(*sq ((((u_x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x2y
ddx(0,55):=(*sq ((((u_2x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2y
ddx(0,56):=(*sq ((((u_tx2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4y
ddx(0,57):=(*sq ((((u_x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x3y
ddx(0,58):=(*sq ((((u_2x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t3y
ddx(0,59):=(*sq ((((u_tx3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x2y
ddx(0,60):=(*sq ((((u_3x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_tx2y
ddx(0,61):=(*sq ((((u_t2x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t2y
ddx(0,62):=(*sq ((((u_2tx2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_5y
ddx(0,63):=(*sq ((((u_x5y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x4y
ddx(0,64):=(*sq ((((u_2x4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t4y
ddx(0,65):=(*sq ((((u_tx4y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x3y
ddx(0,66):=(*sq ((((u_3x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_tx3y
ddx(0,67):=(*sq ((((u_t2x3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t3y
ddx(0,68):=(*sq ((((u_2tx3y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x2y
ddx(0,69):=(*sq ((((u_4x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2x2y
ddx(0,70):=(*sq ((((u_t3x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2tx2y
ddx(0,71):=(*sq ((((u_2t2x2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t2y
ddx(0,72):=(*sq ((((u_3tx2y . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_6y
ddx(0,73):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_x5y
ddx(0,74):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t5y
ddx(0,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2x4y
ddx(0,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_tx4y
ddx(0,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t4y
ddx(0,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3x3y
ddx(0,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t2x3y
ddx(0,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2tx3y
ddx(0,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3t3y
ddx(0,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4x2y
ddx(0,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_t3x2y
ddx(0,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_2t2x2y
ddx(0,85):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_3tx2y
ddx(0,86):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. u_4t2y
ddx(0,87):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p
ddx(1,1):=(*sq (((((ext 3) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t
ddx(1,2):=(*sq (((((ext 6) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x
ddx(1,3):=(*sq (((((ext 7) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_y
ddx(1,4):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t
ddx(1,5):=(*sq (((((ext 11) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_tx
ddx(1,6):=(*sq (((((ext 12) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x
ddx(1,7):=(*sq (((((ext 13) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_ty
ddx(1,8):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_xy
ddx(1,9):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t
ddx(1,10):=(*sq (((((ext 18) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2tx
ddx(1,11):=(*sq (((((ext 19) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t2x
ddx(1,12):=(*sq (((((ext 20) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x
ddx(1,13):=(*sq (((((ext 21) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2ty
ddx(1,14):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_txy
ddx(1,15):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2xy
ddx(1,16):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t
ddx(1,17):=(*sq (((((ext 27) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3tx
ddx(1,18):=(*sq (((((ext 28) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t2x
ddx(1,19):=(*sq (((((ext 29) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t3x
ddx(1,20):=(*sq (((((ext 30) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x
ddx(1,21):=(*sq (((((ext 31) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3ty
ddx(1,22):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2txy
ddx(1,23):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t2xy
ddx(1,24):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3xy
ddx(1,25):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5t
ddx(1,26):=(*sq (((((ext 38) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4tx
ddx(1,27):=(*sq (((((ext 39) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t2x
ddx(1,28):=(*sq (((((ext 40) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t3x
ddx(1,29):=(*sq (((((ext 41) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t4x
ddx(1,30):=(*sq (((((ext 42) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5x
ddx(1,31):=(*sq (((((ext 43) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4ty
ddx(1,32):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3txy
ddx(1,33):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t2xy
ddx(1,34):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t3xy
ddx(1,35):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4xy
ddx(1,36):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6t
ddx(1,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5tx
ddx(1,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t2x
ddx(1,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t3x
ddx(1,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t4x
ddx(1,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t5x
ddx(1,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6x
ddx(1,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5ty
ddx(1,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4txy
ddx(1,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t2xy
ddx(1,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t3xy
ddx(1,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t4xy
ddx(1,48):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5xy
ddx(1,49):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2y
ddx(1,50):=(*sq (((((ext 52) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3y
ddx(1,51):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x2y
ddx(1,52):=(*sq (((((ext 57) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t2y
ddx(1,53):=(*sq (((((ext 58) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4y
ddx(1,54):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x3y
ddx(1,55):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t3y
ddx(1,56):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x2y
ddx(1,57):=(*sq (((((ext 66) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_tx2y
ddx(1,58):=(*sq (((((ext 67) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t2y
ddx(1,59):=(*sq (((((ext 68) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_5y
ddx(1,60):=(*sq (((((ext 71) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x4y
ddx(1,61):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t4y
ddx(1,62):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x3y
ddx(1,63):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_tx3y
ddx(1,64):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t3y
ddx(1,65):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x2y
ddx(1,66):=(*sq (((((ext 80) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t2x2y
ddx(1,67):=(*sq (((((ext 81) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2tx2y
ddx(1,68):=(*sq (((((ext 82) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t2y
ddx(1,69):=(*sq (((((ext 83) . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_6y
ddx(1,70):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_x5y
ddx(1,71):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t5y
ddx(1,72):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2x4y
ddx(1,73):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_tx4y
ddx(1,74):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t4y
ddx(1,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3x3y
ddx(1,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t2x3y
ddx(1,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2tx3y
ddx(1,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3t3y
ddx(1,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4x2y
ddx(1,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_t3x2y
ddx(1,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_2t2x2y
ddx(1,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_3tx2y
ddx(1,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddx w.r.t. p_4t2y
ddx(1,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. t
ddy(0,1):=0
% component of ddy w.r.t. x
ddy(0,2):=0
% component of ddy w.r.t. y
ddy(0,3):=1
% component of ddy w.r.t. u
ddy(0,4):=(*sq ((((u_y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t
ddy(0,5):=(*sq ((((u_ty . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x
ddy(0,6):=(*sq ((((u_xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_y
ddy(0,7):=(*sq ((((u . 1) ((u_2x . 1) . -12)) ((u_4x . 1) . -1) ((u_tx . 1) . 12
) ((u_x . 2) . -12)) . 12) t)
% component of ddy w.r.t. u_2t
ddy(0,8):=(*sq ((((u_2ty . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_tx
ddy(0,9):=(*sq ((((u_txy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x
ddy(0,10):=(*sq ((((u_2xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_ty
ddy(0,11):=(*sq ((((u . 1) ((u_t2x . 1) . -12)) ((u_2tx . 1) . 12) ((u_2x . 1) (
(u_t . 1) . -12)) ((u_t4x . 1) . -1) ((u_tx . 1) ((u_x . 1) . -24))) . 12) t)
% component of ddy w.r.t. u_xy
ddy(0,12):=(*sq ((((u . 1) ((u_3x . 1) . -12)) ((u_2x . 1) ((u_x . 1) . -36)) ((
u_5x . 1) . -1) ((u_t2x . 1) . 12)) . 12) t)
% component of ddy w.r.t. u_3t
ddy(0,13):=(*sq ((((u_3ty . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2tx
ddy(0,14):=(*sq ((((u_2txy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t2x
ddy(0,15):=(*sq ((((u_t2xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x
ddy(0,16):=(*sq ((((u_3xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2ty
ddy(0,17):=(*sq ((((u . 1) ((u_2t2x . 1) . -12)) ((u_2t . 1) ((u_2x . 1) . -12))
((u_2t4x . 1) . -1) ((u_2tx . 1) ((u_x . 1) . -24)) ((u_3tx . 1) . 12) ((u_t . 1
) ((u_t2x . 1) . -24)) ((u_tx . 2) . -24)) . 12) t)
% component of ddy w.r.t. u_txy
ddy(0,18):=(*sq ((((u . 1) ((u_t3x . 1) . -12)) ((u_2t2x . 1) . 12) ((u_2x . 1)
((u_tx . 1) . -36)) ((u_3x . 1) ((u_t . 1) . -12)) ((u_t2x . 1) ((u_x . 1) . -36
)) ((u_t5x . 1) . -1)) . 12) t)
% component of ddy w.r.t. u_2xy
ddy(0,19):=(*sq ((((u . 1) ((u_4x . 1) . -12)) ((u_2x . 2) . -36) ((u_3x . 1) ((
u_x . 1) . -48)) ((u_6x . 1) . -1) ((u_t3x . 1) . 12)) . 12) t)
% component of ddy w.r.t. u_4t
ddy(0,20):=(*sq ((((u_4ty . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3tx
ddy(0,21):=(*sq ((((u_3txy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t2x
ddy(0,22):=(*sq ((((u_2t2xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t3x
ddy(0,23):=(*sq ((((u_t3xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x
ddy(0,24):=(*sq ((((u_4xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3ty
ddy(0,25):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2txy
ddy(0,26):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t2xy
ddy(0,27):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3xy
ddy(0,28):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5t
ddy(0,29):=(*sq ((((u_5ty . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4tx
ddy(0,30):=(*sq ((((u_4txy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3t2x
ddy(0,31):=(*sq ((((u_3t2xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t3x
ddy(0,32):=(*sq ((((u_2t3xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t4x
ddy(0,33):=(*sq ((((u_t4xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5x
ddy(0,34):=(*sq ((((u_5xy . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4ty
ddy(0,35):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3txy
ddy(0,36):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t2xy
ddy(0,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t3xy
ddy(0,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4xy
ddy(0,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6t
ddy(0,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5tx
ddy(0,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4t2x
ddy(0,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3t3x
ddy(0,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t4x
ddy(0,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t5x
ddy(0,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6x
ddy(0,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5ty
ddy(0,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4txy
ddy(0,48):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3t2xy
ddy(0,49):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t3xy
ddy(0,50):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t4xy
ddy(0,51):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5xy
ddy(0,52):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2y
ddy(0,53):=(*sq ((((u_3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3y
ddy(0,54):=(*sq ((((u_4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x2y
ddy(0,55):=(*sq ((((u_x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t2y
ddy(0,56):=(*sq ((((u_t3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4y
ddy(0,57):=(*sq ((((u_5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x3y
ddy(0,58):=(*sq ((((u_x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t3y
ddy(0,59):=(*sq ((((u_t4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x2y
ddy(0,60):=(*sq ((((u_2x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_tx2y
ddy(0,61):=(*sq ((((u_tx3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t2y
ddy(0,62):=(*sq ((((u_2t3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_5y
ddy(0,63):=(*sq ((((u_6y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x4y
ddy(0,64):=(*sq ((((u_x5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t4y
ddy(0,65):=(*sq ((((u_t5y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x3y
ddy(0,66):=(*sq ((((u_2x4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_tx3y
ddy(0,67):=(*sq ((((u_tx4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t3y
ddy(0,68):=(*sq ((((u_2t4y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x2y
ddy(0,69):=(*sq ((((u_3x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t2x2y
ddy(0,70):=(*sq ((((u_t2x3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2tx2y
ddy(0,71):=(*sq ((((u_2tx3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3t2y
ddy(0,72):=(*sq ((((u_3t3y . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_6y
ddy(0,73):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_x5y
ddy(0,74):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t5y
ddy(0,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2x4y
ddy(0,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_tx4y
ddy(0,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t4y
ddy(0,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3x3y
ddy(0,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t2x3y
ddy(0,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2tx3y
ddy(0,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3t3y
ddy(0,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4x2y
ddy(0,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_t3x2y
ddy(0,84):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_2t2x2y
ddy(0,85):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_3tx2y
ddy(0,86):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. u_4t2y
ddy(0,87):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p
ddy(1,1):=(*sq (((((ext 4) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t
ddy(1,2):=(*sq (((((ext 8) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_x
ddy(1,3):=(*sq (((((ext 9) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_y
ddy(1,4):=(*sq (((((ext 21) . 1) . -1) (((ext 7) . 1) ((u . 1) . -12)) (((ext 6)
. 1) . 12)) . 12) t)
% component of ddy w.r.t. p_2t
ddy(1,5):=(*sq (((((ext 14) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_tx
ddy(1,6):=(*sq (((((ext 15) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2x
ddy(1,7):=(*sq (((((ext 16) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_ty
ddy(1,8):=(*sq (((((ext 30) . 1) . -1) (((ext 12) . 1) ((u . 1) . -12)) (((ext
11) . 1) . 12) (((ext 7) . 1) ((u_t . 1) . -12))) . 12) t)
% component of ddy w.r.t. p_xy
ddy(1,9):=(*sq (((((ext 31) . 1) . -1) (((ext 13) . 1) ((u . 1) . -12)) (((ext
12) . 1) . 12) (((ext 7) . 1) ((u_x . 1) . -12))) . 12) t)
% component of ddy w.r.t. p_3t
ddy(1,10):=(*sq (((((ext 22) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2tx
ddy(1,11):=(*sq (((((ext 23) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t2x
ddy(1,12):=(*sq (((((ext 24) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3x
ddy(1,13):=(*sq (((((ext 25) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2ty
ddy(1,14):=(*sq (((((ext 41) . 1) . -1) (((ext 19) . 1) ((u . 1) . -12)) (((ext
18) . 1) . 12) (((ext 12) . 1) ((u_t . 1) . -24)) (((ext 7) . 1) ((u_2t . 1) .
-12))) . 12) t)
% component of ddy w.r.t. p_txy
ddy(1,15):=(*sq (((((ext 42) . 1) . -1) (((ext 20) . 1) ((u . 1) . -12)) (((ext
19) . 1) . 12) (((ext 13) . 1) ((u_t . 1) . -12)) (((ext 12) . 1) ((u_x . 1) .
-12)) (((ext 7) . 1) ((u_tx . 1) . -12))) . 12) t)
% component of ddy w.r.t. p_2xy
ddy(1,16):=(*sq (((((ext 43) . 1) . -1) (((ext 21) . 1) ((u . 1) . -12)) (((ext
20) . 1) . 12) (((ext 13) . 1) ((u_x . 1) . -24)) (((ext 7) . 1) ((u_2x . 1) .
-12))) . 12) t)
% component of ddy w.r.t. p_4t
ddy(1,17):=(*sq (((((ext 32) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3tx
ddy(1,18):=(*sq (((((ext 33) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t2x
ddy(1,19):=(*sq (((((ext 34) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t3x
ddy(1,20):=(*sq (((((ext 35) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4x
ddy(1,21):=(*sq (((((ext 36) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3ty
ddy(1,22):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2txy
ddy(1,23):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t2xy
ddy(1,24):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3xy
ddy(1,25):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_5t
ddy(1,26):=(*sq (((((ext 44) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4tx
ddy(1,27):=(*sq (((((ext 45) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3t2x
ddy(1,28):=(*sq (((((ext 46) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t3x
ddy(1,29):=(*sq (((((ext 47) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t4x
ddy(1,30):=(*sq (((((ext 48) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_5x
ddy(1,31):=(*sq (((((ext 49) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4ty
ddy(1,32):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3txy
ddy(1,33):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t2xy
ddy(1,34):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t3xy
ddy(1,35):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4xy
ddy(1,36):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_6t
ddy(1,37):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_5tx
ddy(1,38):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4t2x
ddy(1,39):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3t3x
ddy(1,40):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t4x
ddy(1,41):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t5x
ddy(1,42):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_6x
ddy(1,43):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_5ty
ddy(1,44):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4txy
ddy(1,45):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3t2xy
ddy(1,46):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t3xy
ddy(1,47):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t4xy
ddy(1,48):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_5xy
ddy(1,49):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2y
ddy(1,50):=(*sq (((((ext 51) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3y
ddy(1,51):=(*sq (((((ext 54) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_x2y
ddy(1,52):=(*sq (((((ext 55) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t2y
ddy(1,53):=(*sq (((((ext 56) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4y
ddy(1,54):=(*sq (((((ext 60) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_x3y
ddy(1,55):=(*sq (((((ext 61) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t3y
ddy(1,56):=(*sq (((((ext 62) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2x2y
ddy(1,57):=(*sq (((((ext 63) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_tx2y
ddy(1,58):=(*sq (((((ext 64) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t2y
ddy(1,59):=(*sq (((((ext 65) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_5y
ddy(1,60):=(*sq (((((ext 70) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_x4y
ddy(1,61):=(*sq (((((ext 71) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t4y
ddy(1,62):=(*sq (((((ext 72) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2x3y
ddy(1,63):=(*sq (((((ext 73) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_tx3y
ddy(1,64):=(*sq (((((ext 74) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t3y
ddy(1,65):=(*sq (((((ext 75) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3x2y
ddy(1,66):=(*sq (((((ext 76) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t2x2y
ddy(1,67):=(*sq (((((ext 77) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2tx2y
ddy(1,68):=(*sq (((((ext 78) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3t2y
ddy(1,69):=(*sq (((((ext 79) . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_6y
ddy(1,70):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_x5y
ddy(1,71):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t5y
ddy(1,72):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2x4y
ddy(1,73):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_tx4y
ddy(1,74):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t4y
ddy(1,75):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3x3y
ddy(1,76):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t2x3y
ddy(1,77):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2tx3y
ddy(1,78):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3t3y
ddy(1,79):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4x2y
ddy(1,80):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_t3x2y
ddy(1,81):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_2t2x2y
ddy(1,82):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_3tx2y
ddy(1,83):=(*sq ((((letop . 1) . 1)) . 1) t)
% component of ddy w.r.t. p_4t2y
ddy(1,84):=(*sq ((((letop . 1) . 1)) . 1) t)
;end;
