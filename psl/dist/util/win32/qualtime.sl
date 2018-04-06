%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           QUALIFIED-TIMING.SL
% Description:    timing function execution
% Author:         Herbert Melenk and Winfried Neun, ZIB Berlin
% Created:        25 October 1988
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Utilities
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
 
(compiletime (flag '(qualtime1 qualtime11 print-qualtime1)
                   'internalfunction))
 
(cond ((not (getd 'priv-time-get))   (copyd 'priv-time-get 'get)))
(cond ((not (getd 'priv-time-put))   (copyd 'priv-time-put 'put)))
 
(imports '(compiler))
 
(fluid '(*allqualtime* *allqualtimetime*))
 
%%(on comp)
 
(dm qualtime (u)
  (mapc (cdr u) (function qualtime1))
  NIL)
 
(de qualtime1 (u)
  (eval (qualtime11 u))
  (setq *allqualtimetime* (cons (timc) gctime*))
  NIL)
 
(de qualtime11(u)
  (let ((name (intern (gensym)))(name2 (intern (gensym))))
  (push u *allqualtime*)
  (unless (getd u) (return nil))
  (when (eq u 'equal) (prin2t " Timing for Equal impoosible")
                      (return NIL))
  (fluid1 name)
   `(progn
       (copyd ',name ',u)
       (setq ,name t)
       (de ,name2 (x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 )
          (prog (returnvalue time1 countpos nam)
           (setq nam ,name)
           (cond( nam (setq time1 (timc))))
           (setq ,name NIL)

           (setq returnvalue
             (,name x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 ))
      
           (cond ((not nam) (return returnvalue)))
           (setq ,name T)
           (setq time1 (wdifference (timc) time1))
           (setq countpos (priv-time-get ',u 'qualtimetime))
           (cond (countpos
                    (priv-time-put ',u 'qualtimetime (wplus2 countpos time1)))
                 (t (priv-time-put ',u 'qualtimetime time1)))
           (setq countpos (priv-time-get ',u 'qualtime))
           (cond (countpos
                    (priv-time-put ',u 'qualtime (wplus2 1 countpos)))
                 (t (priv-time-put ',u 'qualtime 1)))
           (return returnvalue)
        )  )
        (compile (list ',name2))
        (copyd ',u ',name2)
) )  )
 
(de print-qualtime ()
  (prog (uu uuu)
    (setq uu (wdifference (timc)  (car *allqualtimetime*)))
    (setq uuu (wdifference gctime* (cdr *allqualtimetime*)))
    (setq *allqualtimetime* (wdifference uu uuu))
    (prin2t " *********** Qualified Timing **************")
    (prin2l (list " **** Overall Cpu time : "
                 *allqualtimetime* " *****"))
    (terpri)
    (terpri)
    (mapc *allqualtime* (function print-qualtime1))
    (reset-qualtime)))
 
(de print-qualtime1 (u)
    (prog (x)
      (prin2 " *** ")
      (prin2  u) (tab 30)
      (prin2 " * calls : ")
      (prin2 (priv-time-get u 'qualtime))
      (when  (not (priv-time-get u 'qualtime)) (terpri) (return nil))
      (tab 45)
      (prin2 " * time : ")
      (prin2 (priv-time-get u 'qualtimetime))
      (tab 60)
      (prin2 " * % ")
      (prin2t (quotient (times2 100 (priv-time-get u 'qualtimetime))
                        (wplus2 1 *allqualtimetime*)))
)   )
 
(de reset-qualtime() (mapobl (function (lambda (x)
                                           (remprop x 'qualtimetime)
                                           (remprop x 'qualtime))))
                     (setq *allqualtimetime* (cons (timc) gctime*)))
 
(prin2t "use (qualtime function function ... ), (print-qualtime)")
