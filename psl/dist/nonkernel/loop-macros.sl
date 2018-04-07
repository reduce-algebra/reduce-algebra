%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:LOOP-MACROS.SL 
% Title:        Various macros to make pure Lisp more tolerable 
% Author:       Eric Benson and M. Griss 
% Created:      5 October 1981 
% Modified:     22-Mar-84 11:35:33 (Brian Beach) 
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
% 01-Dec-83 14:51:56 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(dm foreach (u)
  %. Macro for MAP functions
  %
  % From RLISP
  %
  % Possible forms are:
  % (foreach x in u do (foo x))	   --> (mapc u (function (lambda (x) (foo x))))

  % (foreach x in u collect (foo x)) --> (mapcar u ...)
  % (foreach x in u conc (foo x))	   --> (mapcan u ...)
  % (foreach x in u join (foo x))	   --> (mapcan u ...)
  % (foreach x on u do (foo x))	   --> (map u ...)
  % (foreach x on u collect (foo u)) --> (maplist u ...)
  % (foreach x on u conc (foo x))	   --> (mapcon u ...)
  % (foreach x on u join (foo x))	   --> (mapcon u ...)
  %
  (prog (action body fn lst mod var)
        (setq var (cadr u))
        (setq u (cddr u))
        (setq mod (car u))
        (setq u (cdr u))
        (setq lst (car u))
        (setq u (cdr u))
        (setq action (car u))
        (setq body (cdr u))
        (setq fn
              (cond ((eq action 'do) (if (eq mod 'in)
                       'mapc
                       'map))
                    ((or (eq action 'conc) (eq action 'join)) (if (eq mod
                                                                   'in)
                       'mapcan
                       'mapcon))
                    ((eq action 'collect) (if (eq mod 'in)
                       'mapcar
                       'maplist))
                    (t (stderror
                        (bldmsg "%r is an illegal action in ForEach"
                         action)))))
        (return (list fn lst
                      (list 'function
                       (cons 'lambda (cons (list var) body)))))))

(dm exit (u)
  %. To leave current Iteration
  (cond ((null (cdr u)) '(return nil))
        ((cddr u) (list 'return (cons 'progn (cdr u))))
        (t (cons 'return (cdr u)))))

(dm next (u)
  %. Continue Loop
  '(go $loop$))

% no named DO's yet (no DO at all)
(dm while (u)
  %. Iteration macro
  %
  % From RLISP
  %
  % Form is (while bool exp1 ... expN)
  %
  (cons 'prog
        (cons 'nil
              (cons '$loop$
                    (cons
                     (list 'cond (list (list 'not (cadr u)) '(return nil)))
                     (append (cddr u) '((go $loop$))))))))

(dm repeat (u)
  %
  % From RLISP
  % Form is (repeat exp1 ... expN bool)
  % Repeat until bool is true, similar to Pascal, etc.
  %
  (cons 'prog
        (cons 'nil
              (cons '$loop$
                    (foreach x on (cdr u) collect (if (null (cdr x))
                       (list 'cond (list (list 'not (car x)) '(go $loop$)))
                       (car x)))))))

(dm for (u)
  %
  % From RLISP
  %
  % Form is (FOR (FROM var init final step) (key form))
  %/ Limited right now to key=DO
  (prog (action body exp incr result tail var x)
        (setq var (second (second u)))
        (setq incr (cddr (second u)))
        %(init final step)
        (setq action (first (third u)))
        (setq body (second (third u)))
        (setq result (list (list 'setq var (car incr))))
        (setq incr (cdr incr))
        (setq x (list 'difference (first incr) var))
        (when (neq (second incr) 1)
          (setq x (list 'times (second incr) x)))
        (setq tail '(return nil))
        (unless (eq action 'do)
          (setq action (get action 'bin))
          (setq exp (gensym))
          (setq body
                (list 'setq exp (list (car action) (list 'simp body) exp)))
          (setq result
                (cons (list 'setq exp (mkquote (cdr action))) result))
          (setq tail (list 'return (list 'mk*sq exp)))
          (setq exp (list exp)))
        (return (cons 'prog
                      (cons (cons var exp)
                       (nconc result
                        (cons '$loop$
                         (cons (list 'cond (list (list 'minusp x) tail))
                          (cons body
                           (cons
                            (list 'setq var
                             (list 'plus2 var (second incr)))
                            '((go $loop$))))))))))))

