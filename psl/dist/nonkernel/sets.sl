%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:SETS.SL 
% Title:        Functions acting on lists as sets 
% Author:       Eric Benson 
% Created:      12 December 1981 
% Modified:     23-Mar-84 14:58:07 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% (c) Copyright 1982, University of Utah
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 01-Dec-83 15:01:54 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de list2set (l)
  % Remove redundant elements from L
  (cond ((not (pairp l)) nil)
        ((member (car l) (cdr l)) (list2set (cdr l)))
        (t (cons (car l) (list2set (cdr l))))))

(de list2setq (l)
  % EQ version of List2Set
  (cond ((not (pairp l)) nil)
        % Don't confuse it with SetQ!
        ((memq (car l) (cdr l)) (list2set (cdr l)))
        (t (cons (car l) (list2set (cdr l))))))

(de adjoin (element aset)
  % Add Element to Set
  (if (member element aset)
    aset
    (cons element aset)))

(de adjoinq (element aset)
  % EQ version of Adjoin
  (if (memq element aset)
    aset
    (cons element aset)))

(de union (x y)
  % Set union
  (if (not (pairp x))
    y
    (union (cdr x) (if (member (car x) y)
             y
             (cons (car x) y)))))

(de unionq (x y)
  % EQ version of UNION
  (if (not (pairp x))
    y
    (unionq (cdr x) (if (memq (car x) y)
              y
              (cons (car x) y)))))

(de xn (u v)
  % Set intersection
  (cond ((not (pairp u)) nil)
        ((member (car u) v) (cons (car u) (xn (cdr u) (delete (car u) v))))
        (t (xn (cdr u) v))))

(de xnq (u v)
  % EQ version of XN
  (cond ((null (pairp u)) nil)
        ((memq (car u) v) (cons (car u) (xn (cdr u) (delq (car u) v))))
        (t (xn (cdr u) v))))

(de intersection (u v)
  (xn u v))

(de intersectionq (u v)
  (xnq u v))


