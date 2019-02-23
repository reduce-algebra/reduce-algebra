%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:QUALIFIED-COUNTING.SL
% Description:    counting function execution with callers ref.
% Author:         Herbert Melenk and Winfried Neun, ZIB Berlin
% Created:        5 September 1986
% Mode:           Lisp
% Package:        Utilities
% Status:         Open Source: BSD License
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
 
(cond ((not (getd 'priv-equal)) (copyd 'priv-equal 'equal)))
(cond ((not (getd 'priv-get))   (copyd 'priv-get 'get)))
(cond ((not (getd 'priv-put))   (copyd 'priv-put 'put)))

(de priv-assoc (u v)
  %. Return first (U . xxx) in V, or NIL
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (priv-equal u (caar v))) (car v))
        (t (priv-assoc u (cdr v)))))
 
(imports '(compiler addr2id))
 
(on comp)
 
(dm qualcount (u)
  (mapc (cdr u) (function qualcount1)))

(de qualcount1 (u)
  (let ((name (intern (gensym)))
        (name2 (intern (gensym)))
        (args (qualcount-args (getd u) u))
        )
   (when (not (numberp args)) 

    (put  'quallap 'opencode
     `((*move (frame ,(plus 3 (length args)))(reg 1)))
    )

    (eval
     `(progn
       (copyd ',name ',u)
       (de ,name2 ,args
          (prog (retadr countpos)
           (setq retadr (quallap))
           (setq countpos (priv-assoc retadr (priv-get ',u 'qualcount)))
           (cond (countpos
                    (rplacd countpos (wplus2 1 (cdr countpos))))
                 (t (priv-put ',u 'qualcount
                         (cons (cons retadr 1)
                            (priv-get ',u 'qualcount)))))
           (return (,name . ,args))
        )  )
        (compile (list ',name2))
        (copyd ',u ',name2)
) ))))
 
(de qualcount-args(type name)
   (let ((u '(x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15)))
    (cond ((null type) nil)
          ((not (eqcar type 'expr))
           (printf "cannot qualcount undef or non-expr function %w" name)
           0)
          ((pairp (setq type (cdr type))) % is a lambda
           (cadr type))
          (t  (setq type (getmem (wdifference (inf type)
                                       addressingunitsperitem)))
              (while (wgreaterp (length u) type)
                     (setq u (cdr u)))
              u) 
)))
   
   
(fluid '(*bordervalue*))
 
(setq *bordervalue* 20)
 
(dm print-qualcount (u) (mapobl (function print-qualcount1)))

(de print-qualcount1 (r)

    (if (not (priv-get r 'qualcount))
	nil
    (prog (x)
      (prin2 "************* calls for function ")
      (prin2  r)
      (prin2t " ************* ")
      (setq x (priv-get r 'qualcount))
   aa
      (when ( null x) (return (terpri)))
      (when (wgreaterp (cdar x) *bordervalue*)
        (terpri)
        (prin2 "number of calls : ") (prin2 (cdar x))
        (prin2 " from ")
        (prin2t (code-address-to-symbol (caar x))))
      (setq x (cdr x))
      (go aa)
      )
    )
    )
 
(de reset-qualcount() (mapobl (function (lambda (x)
					(remprop x 'qualcount)))))
 
(prin2t "use (qualcount function function ...), (print-qualcount)")
(prin2t "and (reset-qualcount)")
(prin2t "use *bordervalue* as level for printing")
