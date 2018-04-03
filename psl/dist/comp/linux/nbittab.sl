%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:NBITTAB.SL
% Description:  New bit table format.
% Author:       Herbert Melenk
% Created:
% Package:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load inum fasl-decls))

(de compact-bittable(base max)
 (let ((i 0) (d 0) bl b l s sb)
    (ifor (from i 0 (isub1 max) 1) 
     (do
      (progn
       (setq b (bittable base i))
       (if (or (not (eq b 0))  % nonzero entry
               (eq d 16#3f)    % maximum offset
           )
           (progn
               (push (wor (wshift b 6) d) bl)
               (setq d 1)
           )
           (setq d (iadd1 d))
       )
    )))
    (setq bl (cons 0 bl))
    (setq bl (reversip bl))
    (setq l (length bl))
    (setq s (mkstring (isub1 l) 0))
    (setq sb (strbase (strinf s))) 
    (setq b (isub1 l))
    (ifor (from i 0 b 1) (do (setf (byte sb i) (pop bl))))
    (cons l s)))

(fluid '(*compact-bittable))

(setq *compact-bittable t)

(de codefileheader ()
 (let((m (compiler-constant 'faslout-magic)))
  (when *compact-bittable (setq m (wplus2 m 16#10000)))
  (binarywrite codeout* m)
  (allocatefaslspaces)))

(de codefiletrailer ()
  (prog (s)
        (systemfaslfixup)
        (binarywrite codeout* (idifference (isub1 nextidnumber*) 
					   first-local-id-number))
        % Number of local IDs
        (foreach x in (car orderedidlist*) do
                 (progn (remprop x fasl-idnumber-property*)
                        (setq x (strinf (faslid2string x)))
                        (setq s (strlen x))
			(binarywrite codeout* s)
                        (binarywriteblock codeout* (strbase x)
					  (strpack s))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 currentoffset*
                        (isub1 addressingunitsperitem))
		       addressingunitsperitem)))
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* codebase* s)
        (if *compact-bittable
         (let((b (compact-bittable bittablebase* bittableoffset*))
              (bpw (quotient bitsperword 8)))
           (binarywrite codeout*
            (setq s (iquotient
                       (iplus2 (car b)
                        (isub1 bpw))
                       bpw)))
           (binarywriteblock codeout* (strbase(strinf (cdr b))) s)
         )
         (progn
          (binarywrite codeout*
                     (setq s
                      (iquotient
                       (iplus2 bittableoffset*
                        (isub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
          (binarywriteblock codeout* bittablebase* s)
        ))
	(deallocatefaslspaces)))
