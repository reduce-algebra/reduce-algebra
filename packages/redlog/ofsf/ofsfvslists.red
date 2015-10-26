% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2015 M. Kosta, T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

lisp <<
   fluid '(ofsfvslists_rcsid!* ofsfvslists_copyright!*);
   ofsfvslists_rcsid!* :=
      "$Id$";
   ofsfvslists_copyright!* := "(c) 2015 M. Kosta, T. Sturm"
>>;

module ofsfvslists;

fluid '(rlclustering!*);
rlclustering!* := t;

fluid '(rsl!-alist!* rsl!-alist!-clustering!* guard!-fnalist!* vsub!-fnalist!*);

%%% rsl-alist %%%

rsl!-alist!* := '(
   ((1 -1 equal) (ip ((-1 . 1))))
   ((1 nil equal) (ip ((1 . 1)) ((-1 . 1))))
   ((1 1 equal) (ip ((1 . 1))))
   ((1 -1 neq) (ep ((-1 . 1))))
   ((1 nil neq) (ep ((1 . 1)) ((-1 . 1))))
   ((1 1 neq) (ep ((1 . 1))))
   ((1 -1 lessp) (slb ((-1 . 1))))
   ((1 nil lessp) (slb ((-1 . 1))) (sub ((1 . 1))))
   ((1 1 lessp) (sub ((1 . 1))))
   ((1 -1 leq) (wlb ((-1 . 1))))
   ((1 nil leq) (wlb ((-1 . 1))) (wub ((1 . 1))))
   ((1 1 leq) (wub ((1 . 1))))
   ((1 -1 geq) (wub ((-1 . 1))))
   ((1 nil geq) (wlb ((1 . 1))) (wub ((-1 . 1))))
   ((1 1 geq) (wlb ((1 . 1))))
   ((1 -1 greaterp) (sub ((-1 . 1))))
   ((1 nil greaterp) (slb ((1 . 1))) (sub ((-1 . 1))))
   ((1 1 greaterp) (slb ((1 . 1))))
   ((2 -1 equal) (ip ((-1 . 1)) ((-1 . 2)) ((-2 . 1))))
   ((2 nil equal)
      (ip ((1 . 1)) ((1 . 2)) ((2 . 1)) ((-1 . 1)) ((-1 . 2)) ((-2 . 1))))
   ((2 1 equal) (ip ((1 . 1)) ((1 . 2)) ((2 . 1))))
   ((2 -1 neq) (ep ((-1 . 1)) ((-1 . 2)) ((-2 . 1))))
   ((2 nil neq)
      (ep ((1 . 1)) ((1 . 2)) ((2 . 1)) ((-1 . 1)) ((-1 . 2)) ((-2 . 1))))
   ((2 1 neq) (ep ((1 . 1)) ((1 . 2)) ((2 . 1))))
   ((2 -1 lessp) (ep ((-2 . 1))) (slb ((-1 . 2))) (sub ((-1 . 1))))
   ((2 nil lessp)
      (ep ((-2 . 1)))
      (slb ((1 . 1)) ((-1 . 2)))
      (sub ((1 . 2)) ((-1 . 1))))
   ((2 1 lessp) (slb ((1 . 1))) (sub ((1 . 2))))
   ((2 -1 leq) (wlb ((-1 . 2))) (wub ((-1 . 1))))
   ((2 nil leq)
      (ip ((2 . 1)))
      (wlb ((1 . 1)) ((-1 . 2)))
      (wub ((1 . 2)) ((-1 . 1))))
   ((2 1 leq) (ip ((2 . 1))) (wlb ((1 . 1))) (wub ((1 . 2))))
   ((2 -1 geq) (ip ((-2 . 1))) (wlb ((-1 . 1))) (wub ((-1 . 2))))
   ((2 nil geq)
      (ip ((-2 . 1)))
      (wlb ((1 . 2)) ((-1 . 1)))
      (wub ((1 . 1)) ((-1 . 2))))
   ((2 1 geq) (wlb ((1 . 2))) (wub ((1 . 1))))
   ((2 -1 greaterp) (slb ((-1 . 1))) (sub ((-1 . 2))))
   ((2 nil greaterp)
      (ep ((2 . 1)))
      (slb ((1 . 2)) ((-1 . 1)))
      (sub ((1 . 1)) ((-1 . 2))))
   ((2 1 greaterp) (ep ((2 . 1))) (slb ((1 . 2))) (sub ((1 . 1))))
   ((3 -1 equal)
      (ip ((-1 . 1)) ((-2 . 1)) ((-2 . 2)) ((-3 . 1)) ((-3 . 2)) ((-4 . 1))
         ((-4 . 2)) ((-4 . 3))))
   ((3 nil equal)
      (ip ((1 . 1)) ((2 . 1)) ((2 . 2)) ((3 . 1)) ((3 . 2)) ((4 . 1)) ((4 . 2))
         ((4 . 3)) ((-1 . 1)) ((-2 . 1)) ((-2 . 2)) ((-3 . 1)) ((-3 . 2))
         ((-4 . 1)) ((-4 . 2)) ((-4 . 3))))
   ((3 1 equal)
      (ip ((1 . 1)) ((2 . 1)) ((2 . 2)) ((3 . 1)) ((3 . 2)) ((4 . 1)) ((4 . 2))
         ((4 . 3))))
   ((3 -1 neq)
      (ep ((-1 . 1)) ((-2 . 1)) ((-2 . 2)) ((-3 . 1)) ((-3 . 2)) ((-4 . 1))
         ((-4 . 2)) ((-4 . 3))))
   ((3 nil neq)
      (ep ((1 . 1)) ((2 . 1)) ((2 . 2)) ((3 . 1)) ((3 . 2)) ((4 . 1)) ((4 . 2))
         ((4 . 3)) ((-1 . 1)) ((-2 . 1)) ((-2 . 2)) ((-3 . 1)) ((-3 . 2))
         ((-4 . 1)) ((-4 . 2)) ((-4 . 3))))
   ((3 1 neq)
      (ep ((1 . 1)) ((2 . 1)) ((2 . 2)) ((3 . 1)) ((3 . 2)) ((4 . 1)) ((4 . 2))
         ((4 . 3))))
   ((3 -1 lessp)
      (ep ((-3 . 2)))
      (slb ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3)))
      (sub ((-4 . 2))))
   ((3 nil lessp)
      (ep ((2 . 1)) ((-3 . 2)))
      (slb ((4 . 2)) ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3)))
      (sub ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3)) ((-4 . 2))))
   ((3 1 lessp)
      (ep ((2 . 1)))
      (slb ((4 . 2)))
      (sub ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3))))
   ((3 -1 leq)
      (ip ((-2 . 1)))
      (wlb ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3)))
      (wub ((-4 . 2))))
   ((3 nil leq)
      (ip ((3 . 2)) ((-2 . 1)))
      (wlb ((4 . 2)) ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3)))
      (wub ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3)) ((-4 . 2))))
   ((3 1 leq)
      (ip ((3 . 2)))
      (wlb ((4 . 2)))
      (wub ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3))))
   ((3 -1 geq)
      (ip ((-3 . 2)))
      (wlb ((-4 . 2)))
      (wub ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3))))
   ((3 nil geq)
      (ip ((2 . 1)) ((-3 . 2)))
      (wlb ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3)) ((-4 . 2)))
      (wub ((4 . 2)) ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3))))
   ((3 1 geq)
      (ip ((2 . 1)))
      (wlb ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3)))
      (wub ((4 . 2))))
   ((3 -1 greaterp)
      (ep ((-2 . 1)))
      (slb ((-4 . 2)))
      (sub ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3))))
   ((3 nil greaterp)
      (ep ((3 . 2)) ((-2 . 1)))
      (slb ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3)) ((-4 . 2)))
      (sub ((4 . 2)) ((-1 . 1)) ((-2 . 2)) ((-3 . 1)) ((-4 . 1)) ((-4 . 3))))
   ((3 1 greaterp)
      (ep ((3 . 2)))
      (slb ((1 . 1)) ((2 . 2)) ((3 . 1)) ((4 . 1)) ((4 . 3)))
      (sub ((4 . 2)))));

%%% rsl-alist-clustering %%%

rsl!-alist!-clustering!* := '(
   ((1 -1 equal) (ip ((-1 . 1))))
   ((1 nil equal) (ip ((1 . 1) (-1 . 1))))
   ((1 1 equal) (ip ((1 . 1))))
   ((1 -1 neq) (ep ((-1 . 1))))
   ((1 nil neq) (ep ((1 . 1) (-1 . 1))))
   ((1 1 neq) (ep ((1 . 1))))
   ((1 -1 lessp) (slb ((-1 . 1))))
   ((1 nil lessp) (slb ((-1 . 1))) (sub ((1 . 1))))
   ((1 1 lessp) (sub ((1 . 1))))
   ((1 -1 leq) (wlb ((-1 . 1))))
   ((1 nil leq) (wlb ((-1 . 1))) (wub ((1 . 1))))
   ((1 1 leq) (wub ((1 . 1))))
   ((1 -1 geq) (wub ((-1 . 1))))
   ((1 nil geq) (wlb ((1 . 1))) (wub ((-1 . 1))))
   ((1 1 geq) (wlb ((1 . 1))))
   ((1 -1 greaterp) (sub ((-1 . 1))))
   ((1 nil greaterp) (slb ((1 . 1))) (sub ((-1 . 1))))
   ((1 1 greaterp) (slb ((1 . 1))))
   ((2 -1 equal) (ip ((-1 . 2) (-2 . 1)) ((-1 . 1) (-2 . 1))))
   ((2 nil equal)
      (ip
         ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1))
         ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1))))
   ((2 1 equal) (ip ((1 . 1) (2 . 1)) ((1 . 2) (2 . 1))))
   ((2 -1 neq) (ep ((-1 . 2) (-2 . 1)) ((-1 . 1) (-2 . 1))))
   ((2 nil neq)
      (ep
         ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1))
         ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1))))
   ((2 1 neq) (ep ((1 . 1) (2 . 1)) ((1 . 2) (2 . 1))))
   ((2 -1 lessp) (slb ((-1 . 2) (-2 . 1))) (sub ((-1 . 1) (-2 . 1))))
   ((2 nil lessp)
      (slb ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1)))
      (sub ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1))))
   ((2 1 lessp) (slb ((1 . 1) (2 . 1))) (sub ((1 . 2) (2 . 1))))
   ((2 -1 leq) (wlb ((-1 . 2) (-2 . 1))) (wub ((-1 . 1) (-2 . 1))))
   ((2 nil leq)
      (wlb ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1)))
      (wub ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1))))
   ((2 1 leq) (wlb ((1 . 1) (2 . 1))) (wub ((1 . 2) (2 . 1))))
   ((2 -1 geq) (wlb ((-1 . 1) (-2 . 1))) (wub ((-1 . 2) (-2 . 1))))
   ((2 nil geq)
      (wlb ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1)))
      (wub ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1))))
   ((2 1 geq) (wlb ((1 . 2) (2 . 1))) (wub ((1 . 1) (2 . 1))))
   ((2 -1 greaterp) (slb ((-1 . 1) (-2 . 1))) (sub ((-1 . 2) (-2 . 1))))
   ((2 nil greaterp)
      (slb ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1)))
      (sub ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1))))
   ((2 1 greaterp) (slb ((1 . 2) (2 . 1))) (sub ((1 . 1) (2 . 1))))
   ((3 -1 equal)
      (ip
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 1) (-3 . 2) (-4 . 2))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 nil equal)
      (ip
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 1) (3 . 2) (4 . 2))
         ((2 . 2) (3 . 2) (4 . 3))
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 1) (-3 . 2) (-4 . 2))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 1 equal)
      (ip
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 1) (3 . 2) (4 . 2))
         ((2 . 2) (3 . 2) (4 . 3))))
   ((3 -1 neq)
      (ep
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 1) (-3 . 2) (-4 . 2))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 nil neq)
      (ep
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 1) (3 . 2) (4 . 2))
         ((2 . 2) (3 . 2) (4 . 3))
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 1) (-3 . 2) (-4 . 2))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 1 neq)
      (ep
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 1) (3 . 2) (4 . 2))
         ((2 . 2) (3 . 2) (4 . 3))))
   ((3 -1 lessp)
      (slb ((-1 . 1)) ((-2 . 1) (-3 . 1) (-4 . 1)) ((-2 . 2) (-3 . 2) (-4 . 3)))
      (sub ((-2 . 1) (-3 . 2) (-4 . 2))))
   ((3 nil lessp)
      (slb
         ((2 . 1) (3 . 2) (4 . 2))
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 2) (-3 . 2) (-4 . 3)))
      (sub
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 2) (3 . 2) (4 . 3))
         ((-2 . 1) (-3 . 2) (-4 . 2))))
   ((3 1 lessp)
      (slb ((2 . 1) (3 . 2) (4 . 2)))
      (sub ((1 . 1)) ((2 . 1) (3 . 1) (4 . 1)) ((2 . 2) (3 . 2) (4 . 3))))
   ((3 -1 leq)
      (wlb ((-1 . 1)) ((-2 . 1) (-3 . 1) (-4 . 1)) ((-2 . 2) (-3 . 2) (-4 . 3)))
      (wub ((-2 . 1) (-3 . 2) (-4 . 2))))
   ((3 nil leq)
      (wlb
         ((2 . 1) (3 . 2) (4 . 2))
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 2) (-3 . 2) (-4 . 3)))
      (wub
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 2) (3 . 2) (4 . 3))
         ((-2 . 1) (-3 . 2) (-4 . 2))))
   ((3 1 leq)
      (wlb ((2 . 1) (3 . 2) (4 . 2)))
      (wub ((1 . 1)) ((2 . 1) (3 . 1) (4 . 1)) ((2 . 2) (3 . 2) (4 . 3))))
   ((3 -1 geq)
      (wlb ((-2 . 1) (-3 . 2) (-4 . 2)))
      (wub
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 nil geq)
      (wlb
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 2) (3 . 2) (4 . 3))
         ((-2 . 1) (-3 . 2) (-4 . 2)))
      (wub
         ((2 . 1) (3 . 2) (4 . 2))
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 1 geq)
      (wlb ((1 . 1)) ((2 . 1) (3 . 1) (4 . 1)) ((2 . 2) (3 . 2) (4 . 3)))
      (wub ((2 . 1) (3 . 2) (4 . 2))))
   ((3 -1 greaterp)
      (slb ((-2 . 1) (-3 . 2) (-4 . 2)))
      (sub
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 nil greaterp)
      (slb
         ((1 . 1))
         ((2 . 1) (3 . 1) (4 . 1))
         ((2 . 2) (3 . 2) (4 . 3))
         ((-2 . 1) (-3 . 2) (-4 . 2)))
      (sub
         ((2 . 1) (3 . 2) (4 . 2))
         ((-1 . 1))
         ((-2 . 1) (-3 . 1) (-4 . 1))
         ((-2 . 2) (-3 . 2) (-4 . 3))))
   ((3 1 greaterp)
      (slb ((1 . 1)) ((2 . 1) (3 . 1) (4 . 1)) ((2 . 2) (3 . 2) (4 . 3)))
      (sub ((2 . 1) (3 . 2) (4 . 2)))));

%%% guard-fnalist %%%

guard!-fnalist!* := '(
   ((1 (-1)) . guard!-1!-1m)
   ((1 (1)) . guard!-1!-1)
   ((1 (-1 1)) . guard!-1!-2)
   ((2 (-2)) . guard!-2!-2m)
   ((2 (-1)) . guard!-2!-1m)
   ((2 (1)) . guard!-2!-1)
   ((2 (2)) . guard!-2!-2)
   ((2 (-2 -1)) . guard!-2!-3m)
   ((2 (1 2)) . guard!-2!-3)
   ((2 (-2 -1 1 2)) . guard!-2!-4)
   ((3 (-4)) . guard!-3!-4m)
   ((3 (-3)) . guard!-3!-3m)
   ((3 (-2)) . guard!-3!-2m)
   ((3 (-1)) . guard!-3!-1m)
   ((3 (1)) . guard!-3!-1)
   ((3 (2)) . guard!-3!-2)
   ((3 (3)) . guard!-3!-3)
   ((3 (4)) . guard!-3!-4)
   ((3 (-4 -3 -2)) . guard!-3!-5m)
   ((3 (2 3 4)) . guard!-3!-5));

%%% vsub-fnalist %%%

vsub!-fnalist!* := '(
   ((2 1 equal ((1 . 1))) . vsub!-2!-1!-equal!-1)
   ((2 1 equal ((1 . 2))) . vsub!-2!-1!-equal!-2)
   ((2 1 equal ((2 . 1))) . vsub!-2!-1!-equal!-3)
   ((2 1 equal ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1))) . vsub!-2!-1!-equal!-4)
   ((2 1 equal ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1))) . vsub!-2!-1!-equal!-5)
   ((2 1 equal ((1 . 1) (2 . 1))) . vsub!-2!-1!-equal!-1)
   ((2 1 equal ((1 . 2) (2 . 1))) . vsub!-2!-1!-equal!-2)
   ((2 1 lessp ((1 . 1))) . vsub!-2!-1!-lessp!-1)
   ((2 1 lessp ((1 . 2))) . vsub!-2!-1!-lessp!-2)
   ((2 1 lessp ((2 . 1))) . vsub!-2!-1!-lessp!-3)
   ((2 1 lessp ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1))) . vsub!-2!-1!-lessp!-4)
   ((2 1 lessp ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1))) . vsub!-2!-1!-lessp!-5)
   ((2 1 lessp ((1 . 1) (2 . 1))) . vsub!-2!-1!-lessp!-1)
   ((2 1 lessp ((1 . 2) (2 . 1))) . vsub!-2!-1!-lessp!-2)
   ((2 1 leq ((1 . 1))) . vsub!-2!-1!-leq!-1)
   ((2 1 leq ((1 . 2))) . vsub!-2!-1!-leq!-2)
   ((2 1 leq ((2 . 1))) . vsub!-2!-1!-leq!-3)
   ((2 1 leq ((1 . 1) (2 . 1) (-1 . 2) (-2 . 1))) . vsub!-2!-1!-leq!-4)
   ((2 1 leq ((1 . 2) (2 . 1) (-1 . 1) (-2 . 1))) . vsub!-2!-1!-leq!-5)
   ((2 1 leq ((1 . 1) (2 . 1))) . vsub!-2!-1!-leq!-1)
   ((2 1 leq ((1 . 2) (2 . 1))) . vsub!-2!-1!-leq!-2)
   ((3 1 equal ((1 . 1))) . vsub!-3!-1!-equal!-1)
   ((3 1 equal ((2 . 1))) . vsub!-3!-1!-equal!-2)
   ((3 1 equal ((2 . 2))) . vsub!-3!-1!-equal!-3)
   ((3 1 equal ((3 . 1))) . vsub!-3!-1!-equal!-4)
   ((3 1 equal ((3 . 2))) . vsub!-3!-1!-equal!-5)
   ((3 1 equal ((4 . 1))) . vsub!-3!-1!-equal!-6)
   ((3 1 equal ((4 . 2))) . vsub!-3!-1!-equal!-7)
   ((3 1 equal ((4 . 3))) . vsub!-3!-1!-equal!-8)
   ((3 1 equal ((2 . 1) (3 . 1) (4 . 1))) . vsub!-3!-1!-equal!-9)
   ((3 1 equal ((2 . 1) (3 . 2) (4 . 2))) . vsub!-3!-1!-equal!-10)
   ((3 1 equal ((2 . 2) (3 . 2) (4 . 3))) . vsub!-3!-1!-equal!-11)
   ((3 1 lessp ((1 . 1))) . vsub!-3!-1!-lessp!-1)
   ((3 1 lessp ((2 . 1))) . vsub!-3!-1!-lessp!-2)
   ((3 1 lessp ((2 . 2))) . vsub!-3!-1!-lessp!-3)
   ((3 1 lessp ((3 . 1))) . vsub!-3!-1!-lessp!-4)
   ((3 1 lessp ((3 . 2))) . vsub!-3!-1!-lessp!-5)
   ((3 1 lessp ((4 . 1))) . vsub!-3!-1!-lessp!-6)
   ((3 1 lessp ((4 . 2))) . vsub!-3!-1!-lessp!-7)
   ((3 1 lessp ((4 . 3))) . vsub!-3!-1!-lessp!-8)
   ((3 1 lessp ((2 . 1) (3 . 1) (4 . 1))) . vsub!-3!-1!-lessp!-9)
   ((3 1 lessp ((2 . 1) (3 . 2) (4 . 2))) . vsub!-3!-1!-lessp!-10)
   ((3 1 lessp ((2 . 2) (3 . 2) (4 . 3))) . vsub!-3!-1!-lessp!-11)
   ((3 1 leq ((1 . 1))) . vsub!-3!-1!-leq!-1)
   ((3 1 leq ((2 . 1))) . vsub!-3!-1!-leq!-2)
   ((3 1 leq ((2 . 2))) . vsub!-3!-1!-leq!-3)
   ((3 1 leq ((3 . 1))) . vsub!-3!-1!-leq!-4)
   ((3 1 leq ((3 . 2))) . vsub!-3!-1!-leq!-5)
   ((3 1 leq ((4 . 1))) . vsub!-3!-1!-leq!-6)
   ((3 1 leq ((4 . 2))) . vsub!-3!-1!-leq!-7)
   ((3 1 leq ((4 . 3))) . vsub!-3!-1!-leq!-8)
   ((3 1 leq ((2 . 1) (3 . 1) (4 . 1))) . vsub!-3!-1!-leq!-9)
   ((3 1 leq ((2 . 1) (3 . 2) (4 . 2))) . vsub!-3!-1!-leq!-10)
   ((3 1 leq ((2 . 2) (3 . 2) (4 . 3))) . vsub!-3!-1!-leq!-11)
   ((3 2 equal ((1 . 1))) . vsub!-3!-2!-equal!-1)
   ((3 2 equal ((2 . 1))) . vsub!-3!-2!-equal!-2)
   ((3 2 equal ((2 . 2))) . vsub!-3!-2!-equal!-3)
   ((3 2 equal ((3 . 1))) . vsub!-3!-2!-equal!-4)
   ((3 2 equal ((3 . 2))) . vsub!-3!-2!-equal!-5)
   ((3 2 equal ((4 . 1))) . vsub!-3!-2!-equal!-6)
   ((3 2 equal ((4 . 2))) . vsub!-3!-2!-equal!-7)
   ((3 2 equal ((4 . 3))) . vsub!-3!-2!-equal!-8)
   ((3 2 equal ((2 . 1) (3 . 1) (4 . 1))) . vsub!-3!-2!-equal!-9)
   ((3 2 equal ((2 . 1) (3 . 2) (4 . 2))) . vsub!-3!-2!-equal!-10)
   ((3 2 equal ((2 . 2) (3 . 2) (4 . 3))) . vsub!-3!-2!-equal!-11)
   ((3 2 lessp ((1 . 1))) . vsub!-3!-2!-lessp!-1)
   ((3 2 lessp ((2 . 1))) . vsub!-3!-2!-lessp!-2)
   ((3 2 lessp ((2 . 2))) . vsub!-3!-2!-lessp!-3)
   ((3 2 lessp ((3 . 1))) . vsub!-3!-2!-lessp!-4)
   ((3 2 lessp ((3 . 2))) . vsub!-3!-2!-lessp!-5)
   ((3 2 lessp ((4 . 1))) . vsub!-3!-2!-lessp!-6)
   ((3 2 lessp ((4 . 2))) . vsub!-3!-2!-lessp!-7)
   ((3 2 lessp ((4 . 3))) . vsub!-3!-2!-lessp!-8)
   ((3 2 lessp ((2 . 1) (3 . 1) (4 . 1))) . vsub!-3!-2!-lessp!-9)
   ((3 2 lessp ((2 . 1) (3 . 2) (4 . 2))) . vsub!-3!-2!-lessp!-10)
   ((3 2 lessp ((2 . 2) (3 . 2) (4 . 3))) . vsub!-3!-2!-lessp!-11)
   ((3 2 leq ((1 . 1))) . vsub!-3!-2!-leq!-1)
   ((3 2 leq ((2 . 1))) . vsub!-3!-2!-leq!-2)
   ((3 2 leq ((2 . 2))) . vsub!-3!-2!-leq!-3)
   ((3 2 leq ((3 . 1))) . vsub!-3!-2!-leq!-4)
   ((3 2 leq ((3 . 2))) . vsub!-3!-2!-leq!-5)
   ((3 2 leq ((4 . 1))) . vsub!-3!-2!-leq!-6)
   ((3 2 leq ((4 . 2))) . vsub!-3!-2!-leq!-7)
   ((3 2 leq ((4 . 3))) . vsub!-3!-2!-leq!-8)
   ((3 2 leq ((2 . 1) (3 . 1) (4 . 1))) . vsub!-3!-2!-leq!-9)
   ((3 2 leq ((2 . 1) (3 . 2) (4 . 2))) . vsub!-3!-2!-leq!-10)
   ((3 2 leq ((2 . 2) (3 . 2) (4 . 3))) . vsub!-3!-2!-leq!-11));

%%% guard procedures %%%

procedure guard!-1!-1m(f);
   guard!-1!-1 negf f;

procedure guard!-1!-1(f);
   begin scalar a;
      a := lc f;
      return ofsf_iparse(
      	 a > 0
	    )
   end;

procedure guard!-1!-2(f);
   begin scalar a;
      a := lc f;
      return ofsf_iparse(
      	 a <> 0
	    )
   end;

procedure guard!-2!-2m(f);
   guard!-2!-2 negf f;

procedure guard!-2!-1m(f);
   guard!-2!-1 negf f;

procedure guard!-2!-1(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and b^2 - 4*a*c > 0
	    )
   end;

procedure guard!-2!-2(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and b^2 - 4*a*c = 0
	    )
   end;

procedure guard!-2!-3m(f);
   guard!-2!-3 negf f;

procedure guard!-2!-3(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and b^2 - 4*a*c >= 0
	    )
   end;

procedure guard!-2!-4(f);
   begin scalar a, b, c;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
      	 a <> 0 and b^2 - 4*a*c >= 0
	    )
   end;

procedure guard!-3!-4m(f);
   guard!-3!-4 negf f;

procedure guard!-3!-3m(f);
   guard!-3!-3 negf f;

procedure guard!-3!-2m(f);
   guard!-3!-2 negf f;

procedure guard!-3!-1m(f);
   guard!-3!-1 negf f;

procedure guard!-3!-1(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and (-b^2 + 3*a*c = 0 or
      	    -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d > 0)
	    )
   end;

procedure guard!-3!-2(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0
	    )
   end;

procedure guard!-3!-3(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and 2*b^3 + 27*d*a^2 - 9*a*b*c > 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d = 0
	    )
   end;

procedure guard!-3!-4(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d < 0
	    )
   end;

procedure guard!-3!-5m(f);
   guard!-3!-5 negf f;

procedure guard!-3!-5(f);
   begin scalar a, b, c, d;
      {a, b, c, d} := coeffs f;
      return ofsf_iparse(
   	 a > 0 and -b^2 + 3*a*c < 0 and
      	 -b^2*c^2 + 4*c^3*a + 4*b^3*d + 27*d^2*a^2 - 18*a*b*c*d <= 0
	    )
   end;

%%% vsub procedures %%%

% 2, 1, equal

asserted procedure vsub!-2!-1!-equal!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b >= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

asserted procedure vsub!-2!-1!-equal!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

asserted procedure vsub!-2!-1!-equal!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b = 0
	    )
   end;

asserted procedure vsub!-2!-1!-equal!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b >= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

asserted procedure vsub!-2!-1!-equal!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*aa*bb - aa**2*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb = 0
	    )
   end;

% 2, 1, lessp

asserted procedure vsub!-2!-1!-lessp!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b < 0 and a*bb**2 + aa**2*c - aa*b*bb > 0 or
      	 aa >= 0 and (2*a*bb - aa*b < 0 or a*bb**2 + aa**2*c - aa*b*bb < 0)
	    )
   end;

asserted procedure vsub!-2!-1!-lessp!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b < 0 and a*bb**2 + aa**2*c - aa*b*bb > 0 or
      	 aa <= 0 and (2*a*bb - aa*b < 0 or a*bb**2 + aa**2*c - aa*b*bb < 0)
	    )
   end;

asserted procedure vsub!-2!-1!-lessp!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b < 0
	    )
   end;

asserted procedure vsub!-2!-1!-lessp!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b < 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb > 0 or
      	 a*aa >= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 + a*aa**2*c - a*aa*b*bb < 0)
	    )
   end;

asserted procedure vsub!-2!-1!-lessp!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b < 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb > 0 or
      	 a*aa <= 0 and (2*a**2*bb - a*aa*b < 0 or a**2*bb**2 + a*aa**2*c - a*aa*b*bb < 0)
	    )
   end;

% 2, 1, leq

asserted procedure vsub!-2!-1!-leq!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0 or
      	 aa >= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0
	    )
   end;

asserted procedure vsub!-2!-1!-leq!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a*bb**2 + aa**2*c - aa*b*bb >= 0 or
      	 aa <= 0 and a*bb**2 + aa**2*c - aa*b*bb <= 0
	    )
   end;

asserted procedure vsub!-2!-1!-leq!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a*bb - aa*b <= 0
	    )
   end;

asserted procedure vsub!-2!-1!-leq!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb >= 0 or
      	 a*aa >= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb <= 0
	    )
   end;

asserted procedure vsub!-2!-1!-leq!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, aa, bb, a, b, c;
      g := rl_arg2l at;
      f := vspr_f pr;
      {aa, bb} := coeffs g;
      {a, b, c} := coeffs f;
      return ofsf_iparse(
   	 2*a**2*bb - a*aa*b <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb >= 0 or
      	 a*aa <= 0 and a**2*bb**2 + a*aa**2*c - a*aa*b*bb <= 0
	    )
   end;

% 3, 1, equal

asserted procedure vsub!-3!-1!-equal!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-1p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-1p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-1p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo)
   end;

asserted procedure vsub!-3!-1!-equal!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-2p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-2p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-2p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha1;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), alpha1, theo)
   end;

asserted procedure vsub!-3!-1!-equal!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-3p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-3p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-3p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-4p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-4p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-4p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-5p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-5p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-5p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), alpha2, theo)
   end;

asserted procedure vsub!-3!-1!-equal!-6(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-6p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-6p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-6p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-7(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-7p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-7p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-7p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, alpha2, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2 and w3
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-8(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-8p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-8p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-8p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-9(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-9p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-9p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-9p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-10(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-10p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-10p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-10p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), beta, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-11(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-equal!-11p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-1!-equal!-11p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-equal!-11p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta, theo);
      return ofsf_iparse(
	 w1 and w2 and w3
	    )
   end;

% 3, 1, lessp

asserted procedure vsub!-3!-1!-lessp!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-1p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-1p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-1p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta, theo)
   end;

asserted procedure vsub!-3!-1!-lessp!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-2p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-2p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-2p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha1;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha1, theo)
   end;

asserted procedure vsub!-3!-1!-lessp!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-3p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-3p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-3p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta, theo)
   end;

asserted procedure vsub!-3!-1!-lessp!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-4p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-4p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-4p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), alpha2, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-5p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-5p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-5p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha2, theo)
   end;

asserted procedure vsub!-3!-1!-lessp!-6(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-6p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-6p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-6p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-7(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-7p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-7p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-7p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, alpha2, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or (w2 and w3)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-8(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-8p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-8p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-8p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-9(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-9p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-9p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-9p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-10(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-10p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-10p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-10p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, alpha2, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha2, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or (w2 and w3)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-11(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-lessp!-11p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-leq!-11p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-lessp!-11p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

% 3, 1, leq

asserted procedure vsub!-3!-1!-leq!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-1p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-1p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-1p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta, theo)
   end;

asserted procedure vsub!-3!-1!-leq!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-2p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-2p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-2p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha1;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo)
   end;

asserted procedure vsub!-3!-1!-leq!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-3p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-3p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-3p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-4p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-4p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-4p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta, theo)
   end;

asserted procedure vsub!-3!-1!-leq!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-5p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-5p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-5p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo)
   end;

asserted procedure vsub!-3!-1!-leq!-6(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-6p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-6p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-6p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-7(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-7p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-7p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-7p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, alpha2, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or (w2 and w3)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-8(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-8p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-8p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-8p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-9(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-9p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-9p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-9p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or w2
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-10(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-10p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-10p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-10p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha1, alpha2, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 w1 or (w2 and w3)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-11(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-1!-leq!-11p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-1!-lessp!-11p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-1!-leq!-11p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta, alpha2, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta := vspr_mk(g, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 w1 and w2
	    )
   end;

% 3, 2, equal

asserted procedure vsub!-3!-2!-equal!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-1p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-1p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-1p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta1, beta2, guard, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-2p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-2p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-2p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha1;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), alpha1, theo)
   end;

asserted procedure vsub!-3!-2!-equal!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-3p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-3p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-3p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, ddf, beta1, beta2, guard, w1, w2, w3, w4;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      ddf := diff(diff(f, x), x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or (w3 and w4))
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-4p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-4p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-4p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, ddf, beta1, beta2, guard, w1, w2, w3, w4;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      ddf := diff(diff(f, x), x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or (w3 and w4))
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-5p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-5p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-5p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, g), alpha2, theo)
   end;

asserted procedure vsub!-3!-2!-equal!-6(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-6p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-6p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-6p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, guard, w1, w2, w3, w4, w5, w6;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w6 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2 and w3) or (w4 and w5 and w6))
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-7(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-7p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-7p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-7p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, guard, w1, w2, w3, w4;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or (w3 and w4))
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-8(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-8p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-8p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-8p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, guard, w1, w2, w3, w4, w5, w6;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w6 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2 and w3) or (w4 and w5 and w6))
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-9(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-9p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-9p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-9p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, guard, w1, w2, w3, w4, w5, w6;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w6 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2 and w3) or (w4 and w5 and w6))
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-10(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-10p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-10p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-10p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, guard, w1, w2, w3, w4;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or (w3 and w4))
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-11(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-equal!-11p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := vsub!-3!-2!-equal!-11p(ofsf_0mk2('equal, negf g), pr, ofsf_0mk2('lessp, lcg) . theo);
      wnull := vsub_vsub(ofsf_0mk2('equal, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-equal!-11p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, guard, w1, w2, w3, w4, w5, w6;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w6 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2 and w3) or (w4 and w5 and w6))
	    )
   end;

% 3, 2, lessp

asserted procedure vsub!-3!-2!-lessp!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-1p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-1p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-1p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta1, beta2, guard, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-2p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-2p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-2p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha1;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha1, theo)
   end;

asserted procedure vsub!-3!-2!-lessp!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-3p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-3p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-3p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, guard, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and w3
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-4p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-4p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-4p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, guard, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('equal, df), beta2, theo);
      return ofsf_iparse(
	 guard and w1 and (w2 or w3)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-5p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-5p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-5p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha2, theo)
   end;

asserted procedure vsub!-3!-2!-lessp!-6(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-6p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-6p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-6p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha1, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3 and (w4 or w5)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-7(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-7p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-7p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-7p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, alpha1, alpha2, guard, w1, w2, w3, w4;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and (w3 or w4)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-8(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-8p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-8p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-8p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha2, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and (w3 and w4 and w5)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-9(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-9p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-9p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-9p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha1, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha1, theo);
      return ofsf_iparse(
	 guard and (w1 and w2 and w3) and (w4 or w5)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-10(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-10p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-10p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-10p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, alpha1, alpha2, guard, w1, w2, w3, w4;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and (w3 or w4)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-11(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-lessp!-11p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-leq!-11p(ofsf_0mk2('leq, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('lessp, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-lessp!-11p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha2, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('lessp, g), alpha2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('greaterp, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and (w3 and w4 and w5)
	    )
   end;

% 3, 2, leq

asserted procedure vsub!-3!-2!-leq!-1(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-1p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-1p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-1p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, beta1, beta2, guard, w1, w2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-2(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-2p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-2p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-2p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha1;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo)
   end;

asserted procedure vsub!-3!-2!-leq!-3(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-3p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-3p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-3p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, guard, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-4(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-4p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-4p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-4p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, ddf, beta1, beta2, guard, w1, w2, w3;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      ddf := diff(diff(f, x), x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta2, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-5(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-5p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-5p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-5p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, alpha2;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      return vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo)
   end;

asserted procedure vsub!-3!-2!-leq!-6(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-6p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-6p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-6p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha1, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3 and (w4 or w5)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-7(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-7p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-7p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-7p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, alpha1, alpha2, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or w3) and (w4 or w5)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-8(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-8p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-8p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-8p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha2, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and w3 and w4 and w5
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-9(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-9p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-9p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-9p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha1, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, ddf), beta1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      return ofsf_iparse(
	 guard and w1 and w2 and w3 and (w4 or w5)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-10(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-10p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-10p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-10p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, beta1, beta2, alpha1, alpha2, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      alpha1 := vspr_mk(df, x, {1 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, df), beta1, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha1, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      return ofsf_iparse(
	 guard and ((w1 and w2) or w3) and (w4 or w5)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-11(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, lcg, wpos, wneg, wnull;
      g := ofsf_arg2l at;
      lcg := lc g;
      wpos := vsub!-3!-2!-leq!-11p(at, pr, ofsf_0mk2('greaterp, lcg) . theo);
      wneg := rl_mk1('not, vsub!-3!-2!-lessp!-11p(ofsf_0mk2('lessp, negf g), pr, ofsf_0mk2('lessp, lcg) . theo));
      wnull := vsub_vsub(ofsf_0mk2('leq, red g), pr, ofsf_0mk2('equal, lcg) . theo);
      return ofsf_iparse(
	 (lcg > 0 and wpos) or (lcg < 0 and wneg) or (lcg = 0 and wnull)
	    )
   end;

asserted procedure vsub!-3!-2!-leq!-11p(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   begin scalar g, f, x, df, ddf, beta1, beta2, alpha2, guard, w1, w2, w3, w4, w5;
      g := rl_arg2l at;
      f := vspr_f pr;
      x := vspr_v pr;
      df := diff(f, x);
      ddf := diff(df, x);
      beta1 := vspr_mk(g, x, {1 . 1, 2 . 1}, 'true);
      beta2 := vspr_mk(g, x, {1 . 2, 2 . 1}, 'true);
      alpha2 := vspr_mk(df, x, {1 . 2}, 'true);
      guard := vsub_guard beta1;
      w1 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, f), beta1, theo);
      w2 := vsds_applyvsts!-at!-pr(ofsf_0mk2('leq, g), alpha2, theo);
      w3 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, f), beta2, theo);
      w4 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, df), beta2, theo);
      w5 := vsds_applyvsts!-at!-pr(ofsf_0mk2('geq, ddf), beta2, theo);
      return ofsf_iparse(
	 guard and (w1 or w2) and w3 and w4 and w5
	    )
   end;

asserted procedure vsub_nrsl(rsl: List): List;
   % Negate rsl.
   for each rs in rsl collect
      (- car rs) . cdr rs;

asserted procedure ofsf_negateop(op: Id): Id;
   % Ordered field standard negate operator. Returns [op] after
   % negation.
   if op eq 'equal then
      'neq
   else if op eq 'neq then
      'equal
   else if op eq 'lessp then
      'geq
   else if op eq 'leq then
      'greaterp
   else if op eq 'geq then
      'lessp
   else if op eq 'greaterp then
      'leq;

asserted procedure vsub_compute!-rsl(op: Id, f: SF, x: Kernel, s: Any): Any;
   % Compute root specification list. [op] is an operator, [x] is
   % [mvar f], [s] is the sign of [lc f]. Returns either ['fail] or an
   % AList [al] containing elements [pr] such that [car pr] is one of
   % ['(ip ep slb wlb sub wub)] and [cdr pr] is a list of root
   % specification lists.
   begin scalar w;
      assert(sfto_mvartest(f, x));
      w := if rlclustering!* then
	 assoc({ldeg f, s, op}, rsl!-alist!-clustering!*)
      else
      	 assoc({ldeg f, s, op}, rsl!-alist!*);
      if w then
      	 return cdr w;
      return 'failed
   end;

asserted procedure vsub_guard(pr: VSpr): QfFormula;
   % Guard. Returns a guard of [pr].
   begin scalar f, rtl, w;
      f := vspr_f pr;
      assert(sfto_mvartest(f, vspr_v pr));
      rtl := vspr_rtl pr;
      w := assoc({ldeg f, rtl}, guard!-fnalist!*);
      if w then
      	 return apply(cdr w, {f});
      rederr "no appropriate entry in guard!-fnalist!*"
   end;

asserted procedure vsub_vsub(at: QfFormula, pr: VSpr, theo: Theory): QfFormula;
   % Virtual substitution. [op] is an operator. Returns an equivalent
   % of (g op 0)[x // (f, S)], where (f, S) is a parametric root
   % description described by [pr].
   begin scalar g, x, f, op, rsl, w;
      g := rl_arg2l at;
      x := vspr_v pr;
      if not sfto_mvartest(g, x) then
	 return at;
      f := vspr_f pr;
      op := rl_op at;
      rsl := vspr_rsl pr;
      % case 1
      w := assoc({ldeg f, ldeg g, op, rsl}, vsub!-fnalist!*);
      if w then
      	 return cl_nnf apply(cdr w, {at, pr, theo});
      % case 2
      w := assoc({ldeg f, ldeg g, op, vsub_nrsl rsl}, vsub!-fnalist!*);
      if w then <<
	 pr := vspr_mk(negf vspr_f pr, vspr_v pr, vsub_nrsl rsl, vspr_c pr);
      	 return cl_nnf apply(cdr w, {at, pr, theo})
      >>;
      % case 3
      w := assoc({ldeg f, ldeg g, ofsf_negateop op, rsl}, vsub!-fnalist!*);
      if w then <<
	 at := ofsf_0mk2(ofsf_negateop op, g);
	 return cl_nnf rl_mk1('not, apply(cdr w, {at, pr, theo}))
      >>;
      % case 4
      w := assoc({ldeg f, ldeg g, ofsf_negateop op, vsub_nrsl rsl}, vsub!-fnalist!*);
      if w then <<
	 at := ofsf_0mk2(ofsf_negateop op, g);
	 pr := vspr_mk(negf vspr_f pr, vspr_v pr, vsub_nrsl rsl, vspr_c pr);
	 return cl_nnf rl_mk1('not, apply(cdr w, {at, pr, theo}))
      >>;
      rederr "no appropriate entry in vsub!-fnalist!*"
   end;

endmodule;  % [ofsfvslists]

end;  % of file
