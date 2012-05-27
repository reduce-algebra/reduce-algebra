%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         386-spec.sl
% Title:        misc functions for 386 PSL nonkernel
% Author:       Winfried Neun
% Created:      27 October 1990
% Status:       Experimental
% Mode:         Lisp
% Package:      Kernel
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(remd 'evlis)

(de evlis(u)
      (prog (result pointer)
	   (when (not (pairp u)) (return nil))
	   (setq pointer (setq result (cons (eval (car u)) nil)))
       loop
	   (setq u (cdr u))
	   (when (not (pairp u)) (return result))
	   (rplacd pointer (cons (eval (car u)) nil))
	   (setq pointer (cdr pointer))
	   (go loop)))

(copyd 'eval-aux 'eval)

% a simple case (alloc free) dispatch for eval

(remd 'eval)

(de eval (u)
   (prog (v)
     (case (tag u)
	((id-tag) (if (or (null u)
			(not (eq unbound-tag (tag (setq v (symval (inf u)))))))
			     (return v)
			     (return (eval-aux u))))
	((pair-tag) (return (eval-aux u)))
	((0 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16 17 18 19 20 21 22 23
	  24 25 26 27 28 29 31)   (return u))  % not id or atom
) ))


	     
