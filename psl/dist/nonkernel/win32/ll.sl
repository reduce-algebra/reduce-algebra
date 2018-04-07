%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         ll.sl
% Title:        lap codes for some frequently used function
% Status:       Open Source: BSD License
% Mode:         Lisp
% Package:      Kernel
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (flag '(slow_list2 slow_list3) 'internalfunction))

(lap '((*entry list2 expr 2)
          (*alloc 0)
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 4))
          (*jumpwgeq (label callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (reg 2) (memory (reg 3) (times addressingunitsperitem 2)))
          (*move (quote nil) (memory (reg 3) (times addressingunitsperitem 3)))
          (*move (reg 5) (global heaplast))
          (*move (reg 3)(reg 2))
          (*wplus2 (reg 2) (times addressingunitsperitem 2))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*wor (reg 2) (reg 5))
          (*move (reg 2) (memory (reg 3) addressingunitsperitem))
          (*move (reg 3) (reg 1))
          (*wor (reg 1) (reg 5))
          (*exit 0)
      callslow
          (*linke 0 slow_list2 expr 2)))

(de slow_list2 (u v) (cons u (ncons v)))
 
(lap '((*entry list3 expr 3)
          (*alloc 0)
          (*move (global heaplast) (reg 4))
          (*move (global heaptrapbound) (reg t1))
          (*move (reg 4) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 6))
          (*jumpwgeq (label callslow) (reg 5)  (reg t1))
          (*move (reg 1) (memory (reg 4) 0))
          (*move (reg 2) (memory (reg 4) (times addressingunitsperitem 2)))
          (*move (reg 3) (memory (reg 4) (times addressingunitsperitem 4)))
          (*move (quote nil) (memory (reg 4) (times addressingunitsperitem 5)))
          (*move (reg 5) (global heaplast))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*move (reg 4)(reg 2))
          (*wplus2 (reg 2) (times addressingunitsperitem 2))
          (*wor (reg 2) (reg 5))
          (*move (reg 2) (memory (reg 4) addressingunitsperitem))
          (*move (reg 4)(reg 2))
          (*wplus2 (reg 2) (times addressingunitsperitem 4))
          (*wor (reg 2) (reg 5))
          (*move (reg 2) (memory (reg 4) (times addressingunitsperitem 3)))
          (*move (reg 4) (reg 1))
          (*wor (reg 1) (reg 5))
          (*exit 0)
      callslow
          (*linke 0 slow_list2 expr 2)))

(de slow_list3 (u v w) (cons u (list2 v w)))

(compiletime 
  (put 'cons 'opencode '(
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (labelgen callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (reg 2) (memory (reg 3) addressingunitsperitem))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*wor (reg 1) (reg 5))
          (*jump (labelgen done))
      (labelref callslow)
          (*link !_slowcons expr 2)
      (labelref done)
       )))
 
(compiletime
  (put 'ncons 'opencode '(
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (labelgen callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (quote nil) (memory (reg 3) addressingunitsperitem))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*wor (reg 1) (reg 5))
          (*jump (labelgen done))
      (labelref callslow)
          (*move (quote nil)(reg 2))
          (*link !_slowcons expr 2)
      (labelref done)
       )))
  
(de append (u v)
  %. Combine 2 lists
  (if (not (pairp u))
    v
    (prog (u1 u2)
          (setq u1 (setq u2 (cons (car u) nil)))
          (setq u (cdr u))
          (while (pairp u)
            (rplacd u2 (cons (car u) nil))
            (setq u (cdr u))
            (setq u2 (cdr u2)))
          (rplacd u2 v)
          (return u1))))

(de reverse (u)
  %. Top-level reverse of list
  (prog (v)
        (while (pairp u)
          (setq v (cons (car u) v))
          (setq u (cdr u)))
        (return v)))

