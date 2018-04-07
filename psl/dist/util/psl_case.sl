%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:PSL_CASE.SL 
% Description:  Adjust native case of PSL to lower or upper case. 
% Author:       Herbert Melenk, ZIB Berlin 
% Created:      01-Nov-94 
% Package:      
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 06-Nov-94 (Herbert Melenk)
%  Enabled switching in both directions.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Adjust native case of PSL to lower or upper case. Loading of packages
% compiled in the opposite case is enabled: the strings are converted
% during fasin-intern.

(compiletime (progn
    (errorset '(load fast-integers) nil nil)
    (errorset '(load fast-int) nil nil)
    (errorset '(load inum) nil nil)))

(compiletime (load hash-decls sys-consts))

(fluid '(**low-case **faslin-adjust-case nil-t-diff* *usermode))

(setq *usermode nil)

(setq **faslin-adjust-case t)

(fluid '(*notinplace))

(setq *notinplace t)  %  SUN4 : faster

(de adjust-case-id(i)
 (prog(w n l c)
  (xxremob i)
  (setq n (id2int i))
  (when (or *notinplace
             (atom (errorset (list 'adjust-case-string-in-place (id2string i)) 
                nil nil)))
        (setq w (copystring (id2string i)))
        (adjust-case-string-in-place w)
        (setf (symnam n) w))
  (return (intern i))))

(de adjust-case-string-in-place(s)
  (if **low-case (lower-string-in-place s) (raise-string-in-place s)))

(de lower-string-in-place(s)
 (prog(w n l c)
  (setq w (strinf s))
  (setq l (strlen w))
  (ifor (from j 0 l 1)
     (do (progn
       (setf c (strbyt w j))
       (when (and (wgeq c (char !A))
                  (wleq c (char !Z)))
             (setf (strbyt w j)
                  (iplus2 c 32))))))))

(de raise-string-in-place(s)
 (prog(w n l c)
  (setq w (strinf s))
  (setq l (strlen w))
  (ifor (from j 0 l 1)
     (do (progn
       (setf c (strbyt w j))
       (when (and (wgeq c (char !a))
                  (wleq c (char !z)))
             (setf (strbyt w j)
                  (idifference c 32))))))))

(de xxremob (u)
  % REMove id from OBlist
  (if (not (idp u))
    (noniderror u 'xxremob)
    (let* ((inf   (idinf u))
           (name  (symnam inf)))
      (if (wlessp inf 128)
        (typeerror u 'xxremob '"non-char")
        (let ((slot (hash-into-table name)))
          (when (occupied-slot? slot)
            (setf (hash-table-entry slot) deleted-slot-value)
            )
          u
          )))))

(fluid '(all-ids))

(de adjust-case-all-ids()
  (adjust-case-id nil)
  (mapobl (function(lambda(x)(push x all-ids))))
  (mapc all-ids (function(lambda(x)
     (when (wgreaterp (id2int x) 255) (adjust-case-id x))))))

(when (null (getd 'old-faslin-intern))
      (copyd 'old-faslin-intern 'faslin-intern))

(de new-faslin-intern(s)
   (when **faslin-adjust-case (adjust-case-string-in-place s))
   (old!-faslin!-intern s))

(de adjust-case-t()   
(mapobl (function(lambda(x)
     (progn
           (adjust-case-t1 (get x 'pattern))
           (adjust-case-t1 (get x 'cmacropatterntable))
	   (adjust-case-t1 (get x 'anyregpatterntable))
           (adjust-case-t1 (get x 'openfn))
           (adjust-case-t1 (get x 'opencode))
           (adjust-case-t1 (get x 'exitopencode))
       )))))

(compiletime (off r2i))

(de adjust-case-t1(u)
  (when (pairp u) 
        (when (eq (car u) (int2id 84)) (rplaca u '!t))
        (when (eq (cdr u) (int2id 84)) (rplacd u '!t))
        (adjust-case-t1 (car u))
        (adjust-case-t1 (cdr u)) ))

(compiletime (on r2i))

% ONOFF

(copyd 'true-onoff* 'onoff*)

(de new-onoff*(a b)
   (if b
       (progn (true-onoff* a (int2id 84))
              (true-onoff* a '!t))
       (true-onoff* a nil)))

% Compiler patches

(fluid '(the-t* comcond-t*))

(setq comcond-t* (list 'quote (int2id 84)))

(de case-pa1f-cond(u v)
   % set !t back to T in last clause to make 
   % pa1f-cond and &comcond happy.
  (setq u (true-pa1f-cond u v))
  (case-pa1f-cond2 u))

(de case-pa1f-cond2 (u)
 (if (eqcar (car u) 'lambda)
  (cons (list 'lambda (cadar u) (case-pa1f-cond2 (caddar u)))
      (cdr u))  
  (cons 'cond
    (foreach c in (cdr u) collect
      (cons (if (member (car c) '((quote !t) (quote !T)))
                 comcond-t* 
                 (car c)) 
            (cdr c))))))

(de adjust-case-compiler()
 (let (*usermode)
  (setf (symval (id2int 'nil-t-diff*))
        (difference (inf nil)(inf (symval (inf 't)))))
  (when (null (getd 'true-pa1f-cond ))
        (copyd 'true-pa1f-cond 'pa1f-cond))
      % extract the T which the compiler likes best.
  (setq the-t* (cadr (car (lastcar 
     (true-pa1f-cond '(cond (a b)) '(a b))))))
  (remd 'pa1f-cond)
  (copyd 'pa1f-cond 'case-pa1f-cond)
  (adjust-case-t)  % adjust t in patterns
  (prin2t "#### compiler patched for new case  ####")
))

(when (null (getd 'true-load1))
      (copyd 'true-load1 'load1))

(de case-load1(u)
  (prog(w)
   (setq w (true-load1 u))
   (when (eq u 'compiler)(adjust-case-compiler))
   (return w)))

(de psl_case(m)
 (prog(sys-t)
  (setq **low-case (memq m '(low lower)))
  (if **low-case (setq sys-t '!t) (setq sys-t '!T))
  (put '!t 'constant? sys-t)
  (put '!T 'constant? sys-t)
  (setf (symval (inf '!t)) sys-t)
  (setf (symval (inf '!T)) sys-t)
  (adjust-case-all-ids)
  (remd  'faslin!-intern)
  (copyd 'faslin!-intern 'new-faslin-intern)
  (remd 'onoff*)
  (copyd 'onoff* 'new-onoff*)
  (if m
     (prin2t "#### PSL set to native lower case     ####")
     (prin2t "#### PSL set to native UPPER case     ####"))
  (if (member 'compiler options*) 
      (adjust-case-compiler)
      (progn (remd 'load1) (copyd 'load1 'case-load1)))
  (copyd (intern "QUIT") 'quit)
))

(flag '(psl_case) 'opfn)  % REDUCE support.

% switch system to lower case.

(psl_case 'low)
