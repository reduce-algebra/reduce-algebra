module symmetry;
%
% ----------------------------------------------------------
%                       Symmetry Package
% ----------------------------------------------------------
%
% Author : Karin Gatermann
%          Konrad-Zuse-Zentrum fuer
%          Informationstechnik Berlin
%          Heilbronner Str. 10
%          W-1000 Berlin 31
%          Germany
%          Email: Gatermann@sc.ZIB-Berlin.de
%
% Version 1.0   9. December 1991
%
% Abstract:
% ---------
% This program is an implementation of the algorithm
% for computation of symmetry adapted bases from the
% theory of linear representations of finite grous.
% Projections for the computation of block diagonal form
% of matrices are computed having the symmetry of a group.
%
%
% REDUCE 3.4 is required.
%
% References:
% -----------
% J.-P. Serre, Linear Representations of Finite Groups.
% Springer, New York (1977).
% E. Stiefel, A. F{\"a}ssler, Gruppentheoretische
%  Methoden und ihre Anwendung. Teubner, Stuttgart (1979).
%  (English translation to appear by Birkh\"auser (1992)).
%
% Keywords:
% --------
%           linear representations, symmetry adapted bases,
%           matrix with the symmetry of a group,
%           block diagonalization
%
% symmetry.red
% definition of available algebraic operators

% To build a fast loading version of this package, the following
% sequence of commands should be used:

create!-package('(symmetry symdata1 symdata2),'(contrib symmetry));

load!-package 'symaux;

endmodule;


module symdata1;  %  Data for symmetry package, part 1.

% Author: Karin Gatermann <Gatermann@sc.ZIB-Berlin.de>.

set!*elems!*group('z2,'(id sz2))$
set!*generators('z2,'(sz2))$
set!*relations('z2,'(((sz2 sz2) (id))))$
set!*grouptable('z2,'((grouptable id sz2) (id id sz2) (sz2 sz2 id)))$
set!*inverse('z2,'((id sz2) (id sz2)))$
set!*elemasgen('z2,'(((sz2) (sz2))))$
set!*group('z2,'((id) (sz2)))$
set!*representation('z2,'((id (((1 . 1)))) (sz2 (((1 . 1))))),'complex)$
set!*representation('z2,
  '((id (((1 . 1)))) (sz2 (((-1 . 1))))),'complex)$
set!*representation('z2,
  '(realtype (id (((1 . 1)))) (sz2 (((1 . 1))))),'real)$
set!*representation('z2,
  '(realtype (id (((1 . 1)))) (sz2 (((-1 . 1))))),'real)$
set!*available 'z2$

set!*elems!*group('k4,'(id s1k4 s2k4 rk4))$
set!*generators('k4,'(s1k4 s2k4))$
set!*relations('k4,
               '(((s1k4 s1k4) (id))
                 ((s2k4 s2k4) (id))
                 ((s1k4 s2k4) (s2k4 s1k4))))$
set!*grouptable('k4,
                '((grouptable id s1k4 s2k4 rk4)
                  (id id s1k4 s2k4 rk4)
                  (s1k4 s1k4 id rk4 s2k4)
                  (s2k4 s2k4 rk4 id s1k4)
                  (rk4 rk4 s2k4 s1k4 id)))$
set!*inverse('k4,'((id s1k4 s2k4 rk4) (id s1k4 s2k4 rk4)))$
set!*elemasgen('k4,
  '(((s1k4) (s1k4)) ((s2k4) (s2k4)) ((rk4) (s1k4 s2k4))))$
set!*group('k4,'((id) (s1k4) (s2k4) (rk4)))$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((1 . 1))))),'complex)$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((-1 . 1))))),'complex)$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((-1 . 1))))),'complex)$
set!*representation('k4,
                    '((id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((1 . 1))))),'complex)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((1 . 1))))),'real)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((1 . 1))))
                      (rk4 (((-1 . 1))))),'real)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((-1 . 1))))),'real)$
set!*representation('k4,
                    '(realtype
                      (id (((1 . 1))))
                      (s1k4 (((-1 . 1))))
                      (s2k4 (((-1 . 1))))
                      (rk4 (((1 . 1))))),'real)$
set!*available 'k4$

set!*elems!*group('d3,'(id rd3 rot2d3 sd3 srd3 sr2d3))$
set!*generators('d3,'(rd3 sd3))$
set!*relations('d3,
               '(((sd3 sd3) (id))
                 ((rd3 rd3 rd3) (id))
                 ((sd3 rd3 sd3) (rd3 rd3))))$
set!*grouptable('d3,
                '((grouptable id rd3 rot2d3 sd3 srd3 sr2d3)
                  (id id rd3 rot2d3 sd3 srd3 sr2d3)
                  (rd3 rd3 rot2d3 id sr2d3 sd3 srd3)
                  (rot2d3 rot2d3 id rd3 srd3 sr2d3 sd3)
                  (sd3 sd3 srd3 sr2d3 id rd3 rot2d3)
                  (srd3 srd3 sr2d3 sd3 rot2d3 id rd3)
                  (sr2d3 sr2d3 sd3 srd3 rd3 rot2d3 id)))$
set!*inverse('d3,
   '((id rd3 rot2d3 sd3 srd3 sr2d3) (id rot2d3 rd3 sd3 srd3 sr2d3)))$
set!*elemasgen('d3,
               '(((rd3) (rd3))
                 ((rot2d3) (rd3 rd3))
                 ((sd3) (sd3))
                 ((srd3) (sd3 rd3))
                 ((sr2d3) (sd3 rd3 rd3))))$
set!*group('d3,'((id) (rd3 rot2d3) (sr2d3 sd3 srd3)))$
set!*representation('d3,
                    '((id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((1 . 1))))
                      (srd3 (((1 . 1))))
                      (sr2d3 (((1 . 1))))),'complex)$
set!*representation('d3,
                    '((id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((-1 . 1))))
                      (srd3 (((-1 . 1))))
                      (sr2d3 (((-1 . 1))))),'complex)$
set!*representation('d3,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (rot2d3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sd3 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'complex)$
set!*representation('d3,
                    '(realtype
                      (id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((1 . 1))))
                      (srd3 (((1 . 1))))
                      (sr2d3 (((1 . 1))))),'real)$
set!*representation('d3,
                    '(realtype
                      (id (((1 . 1))))
                      (rd3 (((1 . 1))))
                      (rot2d3 (((1 . 1))))
                      (sd3 (((-1 . 1))))
                      (srd3 (((-1 . 1))))
                      (sr2d3 (((-1 . 1))))),'real)$
set!*representation('d3,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (rot2d3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sd3 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d3
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'real)$
set!*available 'd3$

set!*elems!*group('d4,'(id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4))$
set!*generators('d4,'(rd4 sd4))$
set!*relations('d4,
               '(((sd4 sd4) (id))
                 ((rd4 rd4 rd4 rd4) (id))
                 ((sd4 rd4 sd4) (rd4 rd4 rd4))))$
set!*grouptable('d4,
                '((grouptable id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4)
                  (id id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4)
                  (rd4 rd4 rot2d4 rot3d4 id sr3d4 sd4 srd4 sr2d4)
                  (rot2d4 rot2d4 rot3d4 id rd4 sr2d4 sr3d4 sd4 srd4)
                  (rot3d4 rot3d4 id rd4 rot2d4 srd4 sr2d4 sr3d4 sd4)
                  (sd4 sd4 srd4 sr2d4 sr3d4 id rd4 rot2d4 rot3d4)
                  (srd4 srd4 sr2d4 sr3d4 sd4 rot3d4 id rd4 rot2d4)
                  (sr2d4 sr2d4 sr3d4 sd4 srd4 rot2d4 rot3d4 id rd4)
                  (sr3d4 sr3d4 sd4 srd4 sr2d4 rd4 rot2d4 rot3d4 id)))$
set!*inverse('d4,
             '((id rd4 rot2d4 rot3d4 sd4 srd4 sr2d4 sr3d4)
               (id rot3d4 rot2d4 rd4 sd4 srd4 sr2d4 sr3d4)))$
set!*elemasgen('d4,
               '(((rd4) (rd4))
                 ((rot2d4) (rd4 rd4))
                 ((rot3d4) (rd4 rd4 rd4))
                 ((sd4) (sd4))
                 ((srd4) (sd4 rd4))
                 ((sr2d4) (sd4 rd4 rd4))
                 ((sr3d4) (sd4 rd4 rd4 rd4))))$
set!*group('d4,'((id) (rd4 rot3d4) (rot2d4) (sd4 sr2d4) (sr3d4 srd4)))$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((-1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((-1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((1 . 1))))),'complex)$
set!*representation('d4,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd4 (((nil . 1) (1 . 1)) ((-1 . 1) (nil . 1))))
                 (rot2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                 (rot3d4 (((nil . 1) (-1 . 1)) ((1 . 1) (nil . 1))))
                      (sd4 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd4 (((nil . 1) (1 . 1)) ((1 . 1) (nil . 1))))
                      (sr2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                 (sr3d4 (((nil . 1) (-1 . 1)) ((-1 . 1) (nil . 1))))),
                    'complex)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((-1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((1 . 1))))
                      (srd4 (((-1 . 1))))
                      (sr2d4 (((1 . 1))))
                      (sr3d4 (((-1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1))))
                      (rd4 (((-1 . 1))))
                      (rot2d4 (((1 . 1))))
                      (rot3d4 (((-1 . 1))))
                      (sd4 (((-1 . 1))))
                      (srd4 (((1 . 1))))
                      (sr2d4 (((-1 . 1))))
                      (sr3d4 (((1 . 1))))),'real)$
set!*representation('d4,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd4 (((nil . 1) (1 . 1)) ((-1 . 1) (nil . 1))))
                  (rot2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                  (rot3d4 (((nil . 1) (-1 . 1)) ((1 . 1) (nil . 1))))
                      (sd4 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd4 (((nil . 1) (1 . 1)) ((1 . 1) (nil . 1))))
                  (sr2d4 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                  (sr3d4 (((nil . 1) (-1 . 1)) ((-1 . 1) (nil . 1))))),
                    'real)$
set!*available 'd4$

set!*elems!*group('d5,
   '(id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5))$
set!*generators('d5,'(rd5 sd5))$
set!*relations('d5,
               '(((sd5 sd5) (id))
                 ((rd5 rd5 rd5 rd5 rd5) (id))
                 ((sd5 rd5 sd5) (rd5 rd5 rd5 rd5))))$
set!*grouptable('d5,
      '((grouptable id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5)
               (id id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5)
               (rd5 rd5 r2d5 r3d5 r4d5 id sr4d5 sd5 srd5 sr2d5 sr3d5)
               (r2d5 r2d5 r3d5 r4d5 id rd5 sr3d5 sr4d5 sd5 srd5 sr2d5)
               (r3d5 r3d5 r4d5 id rd5 r2d5 sr2d5 sr3d5 sr4d5 sd5 srd5)
               (r4d5 r4d5 id rd5 r2d5 r3d5 srd5 sr2d5 sr3d5 sr4d5 sd5)
               (sd5 sd5 srd5 sr2d5 sr3d5 sr4d5 id rd5 r2d5 r3d5 r4d5)
               (srd5 srd5 sr2d5 sr3d5 sr4d5 sd5 r4d5 id rd5 r2d5 r3d5)
               (sr2d5 sr2d5 sr3d5 sr4d5 sd5 srd5 r3d5 r4d5 id rd5 r2d5)
               (sr3d5 sr3d5 sr4d5 sd5 srd5 sr2d5 r2d5 r3d5 r4d5 id rd5)
        (sr4d5 sr4d5 sd5 srd5 sr2d5 sr3d5 rd5 r2d5 r3d5 r4d5 id)))$
set!*inverse('d5,
             '((id rd5 r2d5 r3d5 r4d5 sd5 srd5 sr2d5 sr3d5 sr4d5)
               (id r4d5 r3d5 r2d5 rd5 sd5 srd5 sr2d5 sr3d5 sr4d5)))$
set!*elemasgen('d5,
               '(((rd5) (rd5))
                 ((r2d5) (rd5 rd5))
                 ((r3d5) (rd5 rd5 rd5))
                 ((r4d5) (rd5 rd5 rd5 rd5))
                 ((sd5) (sd5))
                 ((srd5) (sd5 rd5))
                 ((sr2d5) (sd5 rd5 rd5))
                 ((sr3d5) (sd5 rd5 rd5 rd5))
                 ((sr4d5) (sd5 rd5 rd5 rd5 rd5))))$
set!*group('d5,
 '((id) (rd5 r4d5) (r2d5 r3d5) (srd5 sr2d5 sd5 sr4d5 sr3d5)))$
set!*representation('d5,
                    '((id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((1 . 1))))
                      (srd5 (((1 . 1))))
                      (sr2d5 (((1 . 1))))
                      (sr3d5 (((1 . 1))))
                      (sr4d5 (((1 . 1))))),'complex)$
set!*representation('d5,
                    '((id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((-1 . 1))))
                      (srd5 (((-1 . 1))))
                      (sr2d5 (((-1 . 1))))
                      (sr3d5 (((-1 . 1))))
                      (sr4d5 (((-1 . 1))))),'complex)$
set!*representation('d5,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                  (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                  ((((((sin (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1))))
                      (r2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                    (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                    (((cos (quotient (times 2 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                      (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                     (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                     (((cos (quotient (times 2 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                     (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                        (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                  (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                  ((((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1)
               (((((cos (quotient (times 2 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -1))
                          . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . -1))
                          . 1))))),'complex)$
set!*representation('d5,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                   (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                   (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                (((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1))))
                      (r2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                 (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                 (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                 ((((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1)
                 (((((cos (quotient (times 4 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 2) . -1))
                          . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                       . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . -1))
                          . 1))))),'complex)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((1 . 1))))
                      (srd5 (((1 . 1))))
                      (sr2d5 (((1 . 1))))
                      (sr3d5 (((1 . 1))))
                      (sr4d5 (((1 . 1))))),'real)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1))))
                      (rd5 (((1 . 1))))
                      (r2d5 (((1 . 1))))
                      (r3d5 (((1 . 1))))
                      (r4d5 (((1 . 1))))
                      (sd5 (((-1 . 1))))
                      (srd5 (((-1 . 1))))
                      (sr2d5 (((-1 . 1))))
                      (sr3d5 (((-1 . 1))))
                      (sr4d5 (((-1 . 1))))),'real)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                 (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                 (((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1))))
                      (r2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 1) . 2)))
                        . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                         (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                          (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                          (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                           (((cos (quotient (times 2 pi) 5)) . 1) . -4))
                          (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                 (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                 (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                 ((((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1)
                (((((cos (quotient (times 2 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                        (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                       (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                        . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . 1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . -1))
                          . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                            (((cos (quotient (times 2 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . -1))
                          . 1))))),'real)$
set!*representation('d5,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd5
                  (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                   (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                  (((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1))))
                   (r2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                        . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                         (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                         (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                           (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                           (((cos (quotient (times 4 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))
                      (sd5 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd5
                  (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                   (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1)
               (((((cos (quotient (times 4 pi) 5)) . 1) . -1)) . 1))))
                      (sr2d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                       . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -1))
                         . 1))))
                      (sr3d5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . -1))
                          . 1))))
                      (sr4d5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                           (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                            (((cos (quotient (times 4 pi) 5)) . 2) . 6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . -1))
                          . 1))))),'real)$
set!*available 'd5$

set!*elems!*group('d6,
                  '(id
                    rd6
                    r2d6
                    r3d6
                    r4d6
                    r5d6
                    sd6
                    srd6
                    sr2d6
                    sr3d6
                    sr4d6
                    sr5d6))$
set!*generators('d6,'(rd6 sd6))$
set!*relations('d6,
               '(((sd6 sd6) (id))
                 ((rd6 rd6 rd6 rd6 rd6 rd6) (id))
                 ((sd6 rd6 sd6) (rd6 rd6 rd6 rd6 rd6))))$
set!*grouptable('d6,
                '((grouptable
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6)
                  (id
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6)
                  (rd6
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6)
                  (r2d6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6)
                  (r3d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6)
                  (r4d6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6)
                  (r5d6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6)
                  (sd6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6)
                  (srd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6
                   r4d6)
                  (sr2d6
                   sr2d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6
                   r3d6)
                  (sr3d6
                   sr3d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6
                   r2d6)
                  (sr4d6
                   sr4d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id
                   rd6)
                  (sr5d6
                   sr5d6
                   sd6
                   srd6
                   sr2d6
                   sr3d6
                   sr4d6
                   rd6
                   r2d6
                   r3d6
                   r4d6
                   r5d6
                   id)))$
set!*inverse('d6,
       '((id rd6 r2d6 r3d6 r4d6 r5d6 sd6 srd6 sr2d6 sr3d6 sr4d6 sr5d6)
       (id r5d6 r4d6 r3d6 r2d6 rd6 sd6 srd6 sr2d6 sr3d6 sr4d6 sr5d6)))$
set!*elemasgen('d6,
               '(((rd6) (rd6))
                 ((r2d6) (rd6 rd6))
                 ((r3d6) (rd6 rd6 rd6))
                 ((r4d6) (rd6 rd6 rd6 rd6))
                 ((r5d6) (rd6 rd6 rd6 rd6 rd6))
                 ((sd6) (sd6))
                 ((srd6) (sd6 rd6))
                 ((sr2d6) (sd6 rd6 rd6))
                 ((sr3d6) (sd6 rd6 rd6 rd6))
                 ((sr4d6) (sd6 rd6 rd6 rd6 rd6))
                 ((sr5d6) (sd6 rd6 rd6 rd6 rd6 rd6))))$
set!*group('d6,
           '((id)
             (rd6 r5d6)
             (r2d6 r4d6)
             (r3d6)
             (sr2d6 sd6 sr4d6)
             (srd6 sr5d6 sr3d6)))$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((-1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((-1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((1 . 1))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
                  (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (r2d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                  (r3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (r4d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r5d6
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sr2d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                   (sr3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (sr4d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (sr5d6
              (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                   ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'complex)$
set!*representation('d6,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r2d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r3d6 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (r4d6
                 (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                 ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r5d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (sr3d6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (sr4d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr5d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                (1 . 2))))),'complex)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((-1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((1 . 1))))
                      (srd6 (((-1 . 1))))
                      (sr2d6 (((1 . 1))))
                      (sr3d6 (((-1 . 1))))
                      (sr4d6 (((1 . 1))))
                      (sr5d6 (((-1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1))))
                      (rd6 (((-1 . 1))))
                      (r2d6 (((1 . 1))))
                      (r3d6 (((-1 . 1))))
                      (r4d6 (((1 . 1))))
                      (r5d6 (((-1 . 1))))
                      (sd6 (((-1 . 1))))
                      (srd6 (((1 . 1))))
                      (sr2d6 (((-1 . 1))))
                      (sr3d6 (((1 . 1))))
                      (sr4d6 (((-1 . 1))))
                      (sr5d6 (((1 . 1))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (r2d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (r4d6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r5d6
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (sr2d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                    (sr3d6 (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (sr4d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                      (sr5d6
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'real)$
set!*representation('d6,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rd6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r2d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                     (r3d6 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (r4d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r5d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
            ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                    (sd6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (srd6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr2d6
             (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
             ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2) (1 . 2))))
                   (sr3d6 (((1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (sr4d6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (sr5d6
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'real)$
set!*available 'd6$

set!*elems!*group('c3,'(id rc3 r2c3))$
set!*generators('c3,'(rc3))$
set!*relations('c3,'(((rc3 rc3 rc3) (id))))$
set!*grouptable('c3,
                '((grouptable id rc3 r2c3)
                  (id id rc3 r2c3)
                  (rc3 rc3 r2c3 id)
                  (r2c3 r2c3 id rc3)))$
set!*inverse('c3,'((id rc3 r2c3) (id r2c3 rc3)))$
set!*elemasgen('c3,'(((rc3) (rc3)) ((r2c3) (rc3 rc3))))$
set!*group('c3,'((id) (rc3) (r2c3)))$
set!*representation('c3,
             '((id (((1 . 1)))) (rc3 (((1 . 1)))) (r2c3 (((1 . 1))))),
                    'complex)$
set!*representation('c3,
                    '((id (((1 . 1))))
                      (rc3
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r2c3
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))),'complex)$
set!*representation('c3,
                    '((id (((1 . 1))))
                      (rc3
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r2c3
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))),'complex)$
set!*representation('c3,
                    '(realtype
                      (id (((1 . 1))))
                      (rc3 (((1 . 1))))
                      (r2c3 (((1 . 1))))),'real)$
set!*representation('c3,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc3
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r2c3
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'real)$
set!*available 'c3$

set!*elems!*group('c4,'(id rc4 r2c4 r3c4))$
set!*generators('c4,'(rc4))$
set!*relations('c4,'(((rc4 rc4 rc4 rc4) (id))))$
set!*grouptable('c4,
                '((grouptable id rc4 r2c4 r3c4)
                  (id id rc4 r2c4 r3c4)
                  (rc4 rc4 r2c4 r3c4 id)
                  (r2c4 r2c4 r3c4 id rc4)
                  (r3c4 r3c4 id rc4 r2c4)))$
set!*inverse('c4,'((id rc4 r2c4 r3c4) (id r3c4 r2c4 rc4)))$
set!*elemasgen('c4,
    '(((rc4) (rc4)) ((r2c4) (rc4 rc4)) ((r3c4) (rc4 rc4 rc4))))$
set!*group('c4,'((id) (rc4) (r2c4) (r3c4)))$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 (((1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((1 . 1))))),'complex)$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 (((-1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((-1 . 1))))),'complex)$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 ((((((i . 1) . 1)) . 1))))
                      (r2c4 (((-1 . 1))))
                      (r3c4 ((((((i . 1) . -1)) . 1))))),'complex)$
set!*representation('c4,
                    '((id (((1 . 1))))
                      (rc4 ((((((i . 1) . -1)) . 1))))
                      (r2c4 (((-1 . 1))))
                      (r3c4 ((((((i . 1) . 1)) . 1))))),'complex)$
set!*representation('c4,
                    '(realtype
                      (id (((1 . 1))))
                      (rc4 (((1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((1 . 1))))),'real)$
set!*representation('c4,
                    '(realtype
                      (id (((1 . 1))))
                      (rc4 (((-1 . 1))))
                      (r2c4 (((1 . 1))))
                      (r3c4 (((-1 . 1))))),'real)$
set!*representation('c4,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc4 (((nil . 1) (-1 . 1)) ((1 . 1) (nil . 1))))
                      (r2c4 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
             (r3c4 (((nil . 1) (1 . 1)) ((-1 . 1) (nil . 1))))),'real)$
set!*available 'c4$

set!*elems!*group('c5,'(id rc5 r2c5 r3c5 r4c5))$
set!*generators('c5,'(rc5))$
set!*relations('c5,'(((rc5 rc5 rc5 rc5 rc5) (id))))$
set!*grouptable('c5,
                '((grouptable id rc5 r2c5 r3c5 r4c5)
                  (id id rc5 r2c5 r3c5 r4c5)
                  (rc5 rc5 r2c5 r3c5 r4c5 id)
                  (r2c5 r2c5 r3c5 r4c5 id rc5)
                  (r3c5 r3c5 r4c5 id rc5 r2c5)
                  (r4c5 r4c5 id rc5 r2c5 r3c5)))$
set!*inverse('c5,'((id rc5 r2c5 r3c5 r4c5) (id r4c5 r3c5 r2c5 rc5)))$
set!*elemasgen('c5,
               '(((rc5) (rc5))
                 ((r2c5) (rc5 rc5))
                 ((r3c5) (rc5 rc5 rc5))
                 ((r4c5) (rc5 rc5 rc5 rc5))))$
set!*group('c5,'((id) (rc5) (r2c5) (r3c5) (r4c5)))$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5 (((1 . 1))))
                      (r2c5 (((1 . 1))))
                      (r3c5 (((1 . 1))))
                      (r4c5 (((1 . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
              (((((((sin (quotient (times 2 pi) 5)) . 1) ((i . 1) . 1))
                           (((cos (quotient (times 2 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . 2)))
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 2 pi) 5)) . 3)
                            ((i . 1) . -1))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 2)
                             ((i . 1) . 3)))
                         (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . -4)))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 3)
                             ((i . 1) . 4)))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
             (((((((sin (quotient (times 4 pi) 5)) . 1) ((i . 1) . 1))
                           (((cos (quotient (times 4 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . 2)))
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 4 pi) 5)) . 3)
                            ((i . 1) . -1))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 2)
                             ((i . 1) . 3)))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . -4)))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 3)
                             ((i . 1) . 4)))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
                       (((((((sin (quotient (times 4 pi) 5)) . 1)
                            ((i . 1) . -1))
                           (((cos (quotient (times 4 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . -2)))
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
               (((((((sin (quotient (times 4 pi) 5)) . 3) ((i . 1) . 1))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 2)
                             ((i . 1) . -3)))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1)
                             ((i . 1) . 4)))
                           (((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                            (((cos (quotient (times 4 pi) 5)) . 3)
                             ((i . 1) . -4)))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '((id (((1 . 1))))
                      (rc5
                       (((((((sin (quotient (times 2 pi) 5)) . 1)
                            ((i . 1) . -1))
                           (((cos (quotient (times 2 pi) 5)) . 1) . 1))
                          . 1))))
                      (r2c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . -2)))
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
             (((((((sin (quotient (times 2 pi) 5)) . 3) ((i . 1) . 1))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 2)
                             ((i . 1) . -3)))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1)
                             ((i . 1) . 4)))
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                            (((cos (quotient (times 2 pi) 5)) . 3)
                             ((i . 1) . -4)))
                        (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))),'complex)$
set!*representation('c5,
                    '(realtype
                      (id (((1 . 1))))
                      (rc5 (((1 . 1))))
                      (r2c5 (((1 . 1))))
                      (r3c5 (((1 . 1))))
                      (r4c5 (((1 . 1))))),'real)$
set!*representation('c5,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc5
                 (((((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                 (((((sin (quotient (times 2 pi) 5)) . 1) . -1)) . 1))
                  ((((((sin (quotient (times 2 pi) 5)) . 1) . 1)) . 1)
                (((((cos (quotient (times 2 pi) 5)) . 1) . 1)) . 1))))
                      (r2c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 2 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 2 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                          (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 3)
                            (((cos (quotient (times 2 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                          (((cos (quotient (times 2 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 2 pi) 5)) . 3)
                         (((cos (quotient (times 2 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 2 pi) 5)) . 1)
                         (((cos (quotient (times 2 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 2 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 2 pi) 5)) . 2)
                         (((cos (quotient (times 2 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 2 pi) 5)) . 4) . 1))
                          . 1))))),'real)$
set!*representation('c5,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc5
                  (((((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                  (((((sin (quotient (times 4 pi) 5)) . 1) . -1)) . 1))
                   ((((((sin (quotient (times 4 pi) 5)) . 1) . 1)) . 1)
                 (((((cos (quotient (times 4 pi) 5)) . 1) . 1)) . 1))))
                      (r2c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -2)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 1) . 2)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2) . -1)
                           (((cos (quotient (times 4 pi) 5)) . 2) . 1))
                          . 1))))
                      (r3c5
                       (((((((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . -3)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3) . -1)
                           (((sin (quotient (times 4 pi) 5)) . 1)
                         (((cos (quotient (times 4 pi) 5)) . 2) . 3)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 2)
                         (((cos (quotient (times 4 pi) 5)) . 1) . -3))
                           (((cos (quotient (times 4 pi) 5)) . 3) . 1))
                          . 1))))
                      (r4c5
                       (((((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 3)
                            (((cos (quotient (times 4 pi) 5)) . 1) . 4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                        (((cos (quotient (times 4 pi) 5)) . 3) . -4)))
                          . 1))
                        ((((((sin (quotient (times 4 pi) 5)) . 3)
                          (((cos (quotient (times 4 pi) 5)) . 1) . -4))
                           (((sin (quotient (times 4 pi) 5)) . 1)
                          (((cos (quotient (times 4 pi) 5)) . 3) . 4)))
                          . 1)
                         (((((sin (quotient (times 4 pi) 5)) . 4) . 1)
                           (((sin (quotient (times 4 pi) 5)) . 2)
                          (((cos (quotient (times 4 pi) 5)) . 2) . -6))
                           (((cos (quotient (times 4 pi) 5)) . 4) . 1))
                          . 1))))),'real)$
set!*available 'c5$

endmodule;


module symdata2; %  Symmetry data, part 2.

% Author: Karin Gatermann <Gatermann@sc.ZIB-Berlin.de>.

set!*elems!*group('c6,'(id rc6 r2c6 r3c6 r4c6 r5c6))$
set!*generators('c6,'(rc6))$
set!*relations('c6,'(((rc6 rc6 rc6 rc6 rc6 rc6) (id))))$
set!*grouptable('c6,
                '((grouptable id rc6 r2c6 r3c6 r4c6 r5c6)
                  (id id rc6 r2c6 r3c6 r4c6 r5c6)
                  (rc6 rc6 r2c6 r3c6 r4c6 r5c6 id)
                  (r2c6 r2c6 r3c6 r4c6 r5c6 id rc6)
                  (r3c6 r3c6 r4c6 r5c6 id rc6 r2c6)
                  (r4c6 r4c6 r5c6 id rc6 r2c6 r3c6)
                  (r5c6 r5c6 id rc6 r2c6 r3c6 r4c6)))$
set!*inverse('c6,
  '((id rc6 r2c6 r3c6 r4c6 r5c6) (id r5c6 r4c6 r3c6 r2c6 rc6)))$
set!*elemasgen('c6,
               '(((rc6) (rc6))
                 ((r2c6) (rc6 rc6))
                 ((r3c6) (rc6 rc6 rc6))
                 ((r4c6) (rc6 rc6 rc6 rc6))
                 ((r5c6) (rc6 rc6 rc6 rc6 rc6))))$
set!*group('c6,'((id) (rc6) (r2c6) (r3c6) (r4c6) (r5c6)))$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6 (((1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((1 . 1))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6 (((-1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((-1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((-1 . 1))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
                (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . 1)
                       . 2))))
                      (r2c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r3c6 (((-1 . 1))))
                      (r4c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r5c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . 1)
                          . 2))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r2c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r3c6 (((1 . 1))))
                      (r4c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r5c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                       . 2))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r2c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r3c6 (((1 . 1))))
                      (r4c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r5c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                        . 2))))),'complex)$
set!*representation('c6,
                    '((id (((1 . 1))))
                      (rc6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . 1)
                          . 2))))
                      (r2c6
              (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1)) . -1)
                          . 2))))
                      (r3c6 (((-1 . 1))))
                      (r4c6
               (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . -1)
                          . 2))))
                      (r5c6
                (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1)) . 1)
                          . 2))))),'complex)$
set!*representation('c6,
                    '(realtype
                      (id (((1 . 1))))
                      (rc6 (((1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((1 . 1))))),'real)$
set!*representation('c6,
                    '(realtype
                      (id (((1 . 1))))
                      (rc6 (((-1 . 1))))
                      (r2c6 (((1 . 1))))
                      (r3c6 (((-1 . 1))))
                      (r4c6 (((1 . 1))))
                      (r5c6 (((-1 . 1))))),'real)$
set!*representation('c6,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc6
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (1 . 2))))
                      (r2c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                     (r3c6 (((-1 . 1) (nil . 1)) ((nil . 1) (-1 . 1))))
                      (r4c6
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r5c6
                 (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (1 . 2))))),'real)$
set!*representation('c6,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (rc6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r2c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (r3c6 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (r4c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (r5c6
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))),'real)$
set!*available 'c6$

set!*elems!*group('s4,
                  '(id
                    bacd
                    acbd
                    abdc
                    dbca
                    cabd
                    bcad
                    dacb
                    bdca
                    dbac
                    cbda
                    adbc
                    acdb
                    badc
                    cdab
                    dcba
                    cbad
                    adcb
                    bcda
                    bdac
                    cadb
                    dabc
                    cdba
                    dcab))$
set!*generators('s4,'(bacd acbd abdc dbca))$
set!*relations('s4,
               '(((bacd bacd) (id))
                 ((acbd acbd) (id))
                 ((abdc abdc) (id))
                 ((dbca) (bacd acbd abdc acbd bacd))))$
set!*grouptable('s4,
                '((grouptable
                   dcab
                   dcba
                   dbac
                   dbca
                   dabc
                   dacb
                   cdab
                   cdba
                   cbad
                   cbda
                   cabd
                   cadb
                   bdac
                   bdca
                   bcad
                   bcda
                   bacd
                   badc
                   adbc
                   adcb
                   acbd
                   acdb
                   id
                   abdc)
                  (dcab
                   badc
                   abdc
                   cadb
                   acdb
                   cbda
                   bcda
                   bacd
                   id
                   dacb
                   adcb
                   dbca
                   bdca
                   cabd
                   acbd
                   dabc
                   adbc
                   dcba
                   cdba
                   cbad
                   bcad
                   dbac
                   bdac
                   dcab
                   cdab)
                  (dcba
                   bacd
                   id
                   cabd
                   acbd
                   cbad
                   bcad
                   badc
                   abdc
                   dabc
                   adbc
                   dbac
                   bdac
                   cadb
                   acdb
                   dacb
                   adcb
                   dcab
                   cdab
                   cbda
                   bcda
                   dbca
                   bdca
                   dcba
                   cdba)
                  (dbac
                   bcda
                   acdb
                   cbda
                   abdc
                   cadb
                   badc
                   bdca
                   adcb
                   dbca
                   id
                   dacb
                   bacd
                   cdba
                   adbc
                   dcba
                   acbd
                   dabc
                   cabd
                   cdab
                   bdac
                   dcab
                   bcad
                   dbac
                   cbad)
                  (dbca
                   bcad
                   acbd
                   cbad
                   id
                   cabd
                   bacd
                   bdac
                   adbc
                   dbac
                   abdc
                   dabc
                   badc
                   cdab
                   adcb
                   dcab
                   acdb
                   dacb
                   cadb
                   cdba
                   bdca
                   dcba
                   bcda
                   dbca
                   cbda)
                  (dabc
                   bdca
                   adcb
                   cdba
                   adbc
                   cdab
                   bdac
                   bcda
                   acdb
                   dcba
                   acbd
                   dcab
                   bcad
                   cbda
                   abdc
                   dbca
                   id
                   dbac
                   cbad
                   cadb
                   badc
                   dacb
                   bacd
                   dabc
                   cabd)
                  (dacb
                   bdac
                   adbc
                   cdab
                   adcb
                   cdba
                   bdca
                   bcad
                   acbd
                   dcab
                   acdb
                   dcba
                   bcda
                   cbad
                   id
                   dbac
                   abdc
                   dbca
                   cbda
                   cabd
                   bacd
                   dabc
                   badc
                   dacb
                   cadb)
                  (cdab
                   abdc
                   badc
                   acdb
                   cadb
                   bcda
                   cbda
                   id
                   bacd
                   adcb
                   dacb
                   bdca
                   dbca
                   acbd
                   cabd
                   adbc
                   dabc
                   cdba
                   dcba
                   bcad
                   cbad
                   bdac
                   dbac
                   cdab
                   dcab)
                  (cdba
                   id
                   bacd
                   acbd
                   cabd
                   bcad
                   cbad
                   abdc
                   badc
                   adbc
                   dabc
                   bdac
                   dbac
                   acdb
                   cadb
                   adcb
                   dacb
                   cdab
                   dcab
                   bcda
                   cbda
                   bdca
                   dbca
                   cdba
                   dcba)
                  (cbad
                   acdb
                   bcda
                   abdc
                   cbda
                   badc
                   cadb
                   adcb
                   bdca
                   id
                   dbca
                   bacd
                   dacb
                   adbc
                   cdba
                   acbd
                   dcba
                   cabd
                   dabc
                   bdac
                   cdab
                   bcad
                   dcab
                   cbad
                   dbac)
                  (cbda
                   acbd
                   bcad
                   id
                   cbad
                   bacd
                   cabd
                   adbc
                   bdac
                   abdc
                   dbac
                   badc
                   dabc
                   adcb
                   cdab
                   acdb
                   dcab
                   cadb
                   dacb
                   bdca
                   cdba
                   bcda
                   dcba
                   cbda
                   dbca)
                  (cabd
                   adcb
                   bdca
                   adbc
                   cdba
                   bdac
                   cdab
                   acdb
                   bcda
                   acbd
                   dcba
                   bcad
                   dcab
                   abdc
                   cbda
                   id
                   dbca
                   cbad
                   dbac
                   badc
                   cadb
                   bacd
                   dacb
                   cabd
                   dabc)
                  (cadb
                   adbc
                   bdac
                   adcb
                   cdab
                   bdca
                   cdba
                   acbd
                   bcad
                   acdb
                   dcab
                   bcda
                   dcba
                   id
                   cbad
                   abdc
                   dbac
                   cbda
                   dbca
                   bacd
                   cabd
                   badc
                   dabc
                   cadb
                   dacb)
                  (bdac
                   cbda
                   cadb
                   bcda
                   badc
                   acdb
                   abdc
                   dbca
                   dacb
                   bdca
                   bacd
                   adcb
                   id
                   dcba
                   dabc
                   cdba
                   cabd
                   adbc
                   acbd
                   dcab
                   dbac
                   cdab
                   cbad
                   bdac
                   bcad)
                  (bdca
                   cbad
                   cabd
                   bcad
                   bacd
                   acbd
                   id
                   dbac
                   dabc
                   bdac
                   badc
                   adbc
                   abdc
                   dcab
                   dacb
                   cdab
                   cadb
                   adcb
                   acdb
                   dcba
                   dbca
                   cdba
                   cbda
                   bdca
                   bcda)
                  (bcad
                   cadb
                   cbda
                   badc
                   bcda
                   abdc
                   acdb
                   dacb
                   dbca
                   bacd
                   bdca
                   id
                   adcb
                   dabc
                   dcba
                   cabd
                   cdba
                   acbd
                   adbc
                   dbac
                   dcab
                   cbad
                   cdab
                   bcad
                   bdac)
                  (bcda
                   cabd
                   cbad
                   bacd
                   bcad
                   id
                   acbd
                   dabc
                   dbac
                   badc
                   bdac
                   abdc
                   adbc
                   dacb
                   dcab
                   cadb
                   cdab
                   acdb
                   adcb
                   dbca
                   dcba
                   cbda
                   cdba
                   bcda
                   bdca)
                  (bacd
                   cdab
                   cdba
                   bdac
                   bdca
                   adbc
                   adcb
                   dcab
                   dcba
                   bcad
                   bcda
                   acbd
                   acdb
                   dbac
                   dbca
                   cbad
                   cbda
                   id
                   abdc
                   dabc
                   dacb
                   cabd
                   cadb
                   bacd
                   badc)
                  (badc
                   cdba
                   cdab
                   bdca
                   bdac
                   adcb
                   adbc
                   dcba
                   dcab
                   bcda
                   bcad
                   acdb
                   acbd
                   dbca
                   dbac
                   cbda
                   cbad
                   abdc
                   id
                   dacb
                   dabc
                   cadb
                   cabd
                   badc
                   bacd)
                  (adbc
                   dbca
                   dacb
                   dcba
                   dabc
                   dcab
                   dbac
                   cbda
                   cadb
                   cdba
                   cabd
                   cdab
                   cbad
                   bcda
                   badc
                   bdca
                   bacd
                   bdac
                   bcad
                   acdb
                   abdc
                   adcb
                   id
                   adbc
                   acbd)
                  (adcb
                   dbac
                   dabc
                   dcab
                   dacb
                   dcba
                   dbca
                   cbad
                   cabd
                   cdab
                   cadb
                   cdba
                   cbda
                   bcad
                   bacd
                   bdac
                   badc
                   bdca
                   bcda
                   acbd
                   id
                   adbc
                   abdc
                   adcb
                   acdb)
                  (acbd
                   dacb
                   dbca
                   dabc
                   dcba
                   dbac
                   dcab
                   cadb
                   cbda
                   cabd
                   cdba
                   cbad
                   cdab
                   badc
                   bcda
                   bacd
                   bdca
                   bcad
                   bdac
                   abdc
                   acdb
                   id
                   adcb
                   acbd
                   adbc)
                  (acdb
                   dabc
                   dbac
                   dacb
                   dcab
                   dbca
                   dcba
                   cabd
                   cbad
                   cadb
                   cdab
                   cbda
                   cdba
                   bacd
                   bcad
                   badc
                   bdac
                   bcda
                   bdca
                   id
                   acbd
                   abdc
                   adbc
                   acdb
                   adcb)
                  (id
                   dcab
                   dcba
                   dbac
                   dbca
                   dabc
                   dacb
                   cdab
                   cdba
                   cbad
                   cbda
                   cabd
                   cadb
                   bdac
                   bdca
                   bcad
                   bcda
                   bacd
                   badc
                   adbc
                   adcb
                   acbd
                   acdb
                   id
                   abdc)
                  (abdc
                   dcba
                   dcab
                   dbca
                   dbac
                   dacb
                   dabc
                   cdba
                   cdab
                   cbda
                   cbad
                   cadb
                   cabd
                   bdca
                   bdac
                   bcda
                   bcad
                   badc
                   bacd
                   adcb
                   adbc
                   acdb
                   acbd
                   abdc
                   id)))$
set!*inverse('s4,
             '((dcab
                dcba
                dbac
                dbca
                dabc
                dacb
                cdab
                cdba
                cbad
                cbda
                cabd
                cadb
                bdac
                bdca
                bcad
                bcda
                bacd
                badc
                adbc
                adcb
                acbd
                acdb
                id
                abdc)
               (cdba
                dcba
                cbda
                dbca
                bcda
                bdca
                cdab
                dcab
                cbad
                dbac
                bcad
                bdac
                cadb
                dacb
                cabd
                dabc
                bacd
                badc
                acdb
                adcb
                acbd
                adbc
                id
                abdc)))$
set!*elemasgen('s4,
               '(((bacd) (bacd))
                 ((acbd) (acbd))
                 ((abdc) (abdc))
                 ((dbca) (dbca))
                 ((cabd) (bacd acbd))
                 ((bcad) (acbd bacd))
                 ((dacb) (dbca bacd))
                 ((bdca) (bacd dbca))
                 ((dbac) (abdc dbca))
                 ((cbda) (dbca abdc))
                 ((adbc) (acbd abdc))
                 ((acdb) (abdc acbd))
                 ((badc) (bacd abdc))
                 ((cdab) (abdc bacd acbd dbca))
                 ((dcba) (acbd dbca))
                 ((cbad) (bacd acbd bacd))
                 ((adcb) (dbca bacd dbca))
                 ((bcda) (abdc acbd bacd))
                 ((bdac) (acbd bacd abdc))
                 ((cadb) (abdc bacd acbd))
                 ((dabc) (bacd acbd abdc))
                 ((cdba) (bacd acbd dbca))
                 ((dcab) (abdc acbd dbca))))$
set!*group('s4,
           '((dcab dabc cadb bdac bcda cdba)
             (dcba badc cdab)
             (dbac dacb cabd adbc acdb bcad bdca cbda)
             (dbca adcb abdc acbd bacd cbad)
             (id)))$
set!*representation('s4,
                    '((id (((1 . 1))))
                      (bacd (((1 . 1))))
                      (acbd (((1 . 1))))
                      (abdc (((1 . 1))))
                      (dbca (((1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((1 . 1))))
                      (adcb (((1 . 1))))
                      (bcda (((1 . 1))))
                      (bdac (((1 . 1))))
                      (cadb (((1 . 1))))
                      (dabc (((1 . 1))))
                      (cdba (((1 . 1))))
                      (dcab (((1 . 1))))),'complex)$
set!*representation('s4,
                    '((id (((1 . 1))))
                      (bacd (((-1 . 1))))
                      (acbd (((-1 . 1))))
                      (abdc (((-1 . 1))))
                      (dbca (((-1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((-1 . 1))))
                      (adcb (((-1 . 1))))
                      (bcda (((-1 . 1))))
                      (bdac (((-1 . 1))))
                      (cadb (((-1 . 1))))
                      (dabc (((-1 . 1))))
                      (cdba (((-1 . 1))))
                      (dcab (((-1 . 1))))),'complex)$
set!*representation('s4,
                    '((id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bacd
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (acbd
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (abdc
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbca
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cabd
              (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (bcad
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                    ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dacb
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (bdca
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbac
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (cbda
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (adbc
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (acdb
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (badc (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdab (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (dcba (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cbad (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (adcb (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bcda (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bdac
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cadb
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                      ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dabc (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdba
                  (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dcab
                  (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))),'complex)$
set!*representation('s4,
                    '((id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (adcb
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bcda
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cadb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dabc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))),'complex)$
set!*representation('s4,
                    '((id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (adcb
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcda
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cadb
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (dabc
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'complex)$
set!*representation('s4,
                    '(realtype
                      (id (((1 . 1))))
                      (bacd (((1 . 1))))
                      (acbd (((1 . 1))))
                      (abdc (((1 . 1))))
                      (dbca (((1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((1 . 1))))
                      (adcb (((1 . 1))))
                      (bcda (((1 . 1))))
                      (bdac (((1 . 1))))
                      (cadb (((1 . 1))))
                      (dabc (((1 . 1))))
                      (cdba (((1 . 1))))
                      (dcab (((1 . 1))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id (((1 . 1))))
                      (bacd (((-1 . 1))))
                      (acbd (((-1 . 1))))
                      (abdc (((-1 . 1))))
                      (dbca (((-1 . 1))))
                      (cabd (((1 . 1))))
                      (bcad (((1 . 1))))
                      (dacb (((1 . 1))))
                      (bdca (((1 . 1))))
                      (dbac (((1 . 1))))
                      (cbda (((1 . 1))))
                      (adbc (((1 . 1))))
                      (acdb (((1 . 1))))
                      (badc (((1 . 1))))
                      (cdab (((1 . 1))))
                      (dcba (((1 . 1))))
                      (cbad (((-1 . 1))))
                      (adcb (((-1 . 1))))
                      (bcda (((-1 . 1))))
                      (bdac (((-1 . 1))))
                      (cadb (((-1 . 1))))
                      (dabc (((-1 . 1))))
                      (cdba (((-1 . 1))))
                      (dcab (((-1 . 1))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bacd
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (acbd
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (abdc
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
              ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbca
               (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cabd
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (bcad
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                      ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dacb
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (bdca
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dbac
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (cbda
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (adbc
                (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (acdb
               (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
               ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (badc (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdab (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (dcba (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cbad (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (adcb (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bcda (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (bdac
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (cadb
                (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . -1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (dabc (((-1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (cdba
                 (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2) (-1 . 2))))
                      (dcab
                 (((1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1)) . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (adcb
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bcda
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cadb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dabc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))),'real)$
set!*representation('s4,
                    '(realtype
                      (id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (bacd
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acbd
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (abdc
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dbca
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cabd
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcad
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dacb
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (bdca
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (dbac
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (cbda
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (adbc
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (acdb
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (badc
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (cdab
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (dcba
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cbad
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (adcb
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bcda
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (bdac
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (cadb
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (dabc
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (cdba
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (dcab
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'real)$
set!*available 's4$

set!*elems!*group('a4,
                  '(id ta4 t2a4 xa4 ya4 za4 txa4 tya4 tza4 t2xa4 t2ya4
                       t2za4))$
set!*generators('a4,'(ta4 xa4 ya4 za4))$
set!*relations('a4,
               '(((za4) (ta4 xa4 ta4 ta4))
                 ((ya4) (ta4 za4 ta4 ta4))
                 ((xa4) (ta4 ya4 ta4 ta4))
                 ((ta4 ta4 ta4) (id))
                 ((xa4 xa4) (id))
                 ((ya4 ya4) (id))
                 ((za4 za4) (id))
                 ((xa4 ya4) (za4))))$
set!*grouptable('a4,
                '((grouptable
                   id
                   ta4
                   t2a4
                   xa4
                   ya4
                   za4
                   txa4
                   tya4
                   tza4
                   t2xa4
                   t2ya4
                   t2za4)
                  (id id ta4 t2a4 xa4 ya4 za4 txa4 tya4 tza4 t2xa4
                      t2ya4 t2za4)
                  (ta4 ta4 t2a4 id txa4 tya4 tza4 t2xa4 t2ya4 t2za4 xa4
                       ya4 za4)
                  (t2a4
                   t2a4
                   id
                   ta4
                   t2xa4
                   t2ya4
                   t2za4
                   xa4
                   ya4
                   za4
                   txa4
                   tya4
                   tza4)
                  (xa4 xa4 tya4 t2za4 id za4 ya4 tza4 ta4 txa4 t2ya4
                       t2xa4 t2a4)
                  (ya4 ya4 tza4 t2xa4 za4 id xa4 tya4 txa4 ta4 t2a4
                       t2za4 t2ya4)
                  (za4 za4 txa4 t2ya4 ya4 xa4 id ta4 tza4 tya4 t2za4
                       t2a4 t2xa4)
                  (txa4
                   txa4
                   t2ya4
                   za4
                   ta4
                   tza4
                   tya4
                   t2za4
                   t2a4
                   t2xa4
                   ya4
                   xa4
                   id)
                  (tya4
                   tya4
                   t2za4
                   xa4
                   tza4
                   ta4
                   txa4
                   t2ya4
                   t2xa4
                   t2a4
                   id
                   za4
                   ya4)
                  (tza4
                   tza4
                   t2xa4
                   ya4
                   tya4
                   txa4
                   ta4
                   t2a4
                   t2za4
                   t2ya4
                   za4
                   id
                   xa4)
                  (t2xa4
                   t2xa4
                   ya4
                   tza4
                   t2a4
                   t2za4
                   t2ya4
                   za4
                   id
                   xa4
                   tya4
                   txa4
                   ta4)
                  (t2ya4
                   t2ya4
                   za4
                   txa4
                   t2za4
                   t2a4
                   t2xa4
                   ya4
                   xa4
                   id
                   ta4
                   tza4
                   tya4)
                  (t2za4
                   t2za4
                   xa4
                   tya4
                   t2ya4
                   t2xa4
                   t2a4
                   id
                   za4
                   ya4
                   tza4
                   ta4
                   txa4)))$
set!*inverse('a4,
            '((id ta4 t2a4 xa4 ya4 za4 txa4 tya4 tza4 t2xa4 t2ya4 t2za4)
              (id t2a4 ta4 xa4 ya4 za4 t2za4 t2xa4 t2ya4 tya4 tza4 txa4)
            ))$
set!*elemasgen('a4,
               '(((ta4) (ta4))
                 ((t2a4) (ta4 ta4))
                 ((xa4) (xa4))
                 ((ya4) (ya4))
                 ((za4) (za4))
                 ((txa4) (ta4 xa4))
                 ((tya4) (ta4 ya4))
                 ((tza4) (ta4 za4))
                 ((t2xa4) (ta4 ta4 xa4))
                 ((t2ya4) (ta4 ta4 ya4))
                 ((t2za4) (ta4 ta4 za4))))$
set!*group('a4,
           '((id) (txa4 ta4 tza4 tya4) (t2za4 t2a4 t2ya4 t2xa4)
                  (ya4 xa4 za4)))$
set!*representation('a4,
                    '((id (((1 . 1))))
                      (ta4 (((1 . 1))))
                      (t2a4 (((1 . 1))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4 (((1 . 1))))
                      (tya4 (((1 . 1))))
                      (tza4 (((1 . 1))))
                      (t2xa4 (((1 . 1))))
                      (t2ya4 (((1 . 1))))
                      (t2za4 (((1 . 1))))),'complex)$
set!*representation('a4,
                    '((id (((1 . 1))))
                      (ta4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2a4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (tya4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (tza4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2xa4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2ya4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2za4
                      (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . -1))
                               . -1)
                          . 2))))),'complex)$
set!*representation('a4,
                    '((id (((1 . 1))))
                      (ta4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2a4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (tya4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (tza4
                       (((((((expt 3 (quotient 1 2)) . 1)((i . 1) . -1))
                               . -1)
                          . 2))))
                      (t2xa4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2ya4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))
                      (t2za4
                       (((((((expt 3 (quotient 1 2)) . 1) ((i . 1) . 1))
                               . -1)
                          . 2))))),'complex)$
set!*representation('a4,
                    '((id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (ta4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (t2a4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (xa4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (ya4
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (za4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (txa4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (tya4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (tza4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (t2xa4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (t2ya4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (t2za4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'complex)$
set!*representation('a4,
                    '(realtype
                      (id (((1 . 1))))
                      (ta4 (((1 . 1))))
                      (t2a4 (((1 . 1))))
                      (xa4 (((1 . 1))))
                      (ya4 (((1 . 1))))
                      (za4 (((1 . 1))))
                      (txa4 (((1 . 1))))
                      (tya4 (((1 . 1))))
                      (tza4 (((1 . 1))))
                      (t2xa4 (((1 . 1))))
                      (t2ya4 (((1 . 1))))
                      (t2za4 (((1 . 1))))),'real)$
set!*representation('a4,
                    '(complextype
                      (id (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (ta4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (t2a4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))
                      (xa4 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (ya4 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (za4 (((1 . 1) (nil . 1)) ((nil . 1) (1 . 1))))
                      (txa4
                       (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (tya4
                       (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (tza4
                       (((-1 . 2) (((((expt 3 (quotient 1 2)) . 1) . 1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . -1)) . 2)
                         (-1 . 2))))
                      (t2xa4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))
                      (t2ya4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))
                      (t2za4
                       (((-1 . 2)(((((expt 3 (quotient 1 2)) . 1) . -1))
                                     . 2))
                        ((((((expt 3 (quotient 1 2)) . 1) . 1)) . 2)
                         (-1 . 2))))),'real)$
set!*representation('a4,
                    '(realtype
                      (id
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (ta4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (t2a4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (xa4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (ya4
                       (((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))))
                      (za4
                       (((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))))
                      (txa4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (1 . 1) (nil . 1))))
                      (tya4
                       (((nil . 1) (nil . 1) (1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (tza4
                       (((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))
                        ((nil . 1) (-1 . 1) (nil . 1))))
                      (t2xa4
                       (((nil . 1) (-1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))
                      (t2ya4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (-1 . 1))
                        ((-1 . 1) (nil . 1) (nil . 1))))
                      (t2za4
                       (((nil . 1) (1 . 1) (nil . 1))
                        ((nil . 1) (nil . 1) (1 . 1))
                        ((1 . 1) (nil . 1) (nil . 1))))),'real)$
set!*available 'a4$

endmodule;


end;
