
% This re-starts a bare reduce and loads in the modules compiled

% by the very first step. It then checkpoints a system that can be

% used to rebuild all other modules.


(setq symbolfilename!* "$here/psl/bpsl")

(setq loaddirectories!* (list "" (bldmsg "%w\..\red/" (getenv "here"))
                                   (bldmsg "%w\" (getenv "here")))))

 (reclaim)

(setq !*init!-stats!* (list (time) (gtheap nil) (free-bps) nextsymbol))


(setq !*usermode nil)
(setq !*verboseload t)
(setq !*argnochk t)                % Check argument count.

(setq prolog_file 'pslprolo)
(setq rend_file 'pslrend)


(cond ((filep "symget.b")
       (dskin "../../../psl/symget.dat")))


(cond ((filep "addr2id.b")
       (load addr2id)))            % For debugging purposes.


(cond ((filep "pipes.b")
       (load pipes)))              % Unix pipes.


(load zbig)                        % PSL bignums.

(errorset '(load compat) nil nil)  % Load PSL-based functions if there.

(load module)                      % Contains definition of load-package.

(load pslprolo)                    % PSL specific code.


(load!-package 'rlisp)

(load!-package rend_file)

(load!-package 'poly)

(load!-package 'arith)

(load!-package 'alg)

(load!-package 'mathpr)

(load!-package 'entry)

(setq version!* "Reduce (Free PSL version)")
 (setq date!* (date))
(initreduce)


(setq !*loadversion t)             % Load entry module during BEGIN.

(setq !*verboseload nil)           % Inhibit loading messages.


(cond ((and (memq (quote sparc) lispsystem!*)
            
(getd (quote supersparc)))
       (supersparc)))


(flag '(fancy) 'switch)


(put 'fancy 'simpfg
  '((t (load fmprint) (fmp!-switch t))

    (nil (fmp!-switch nil)) ))

% implant graphics mode switch


(setq *fancy nil)

(cond ((not (unboundp 'win-messages))

      (putv win-messages 3 '(~on '(fancy)))

      (putv win-messages 4 '(and *fancy (~off '(fancy))))))


(prog nil
   (reclaim)
   (terpri)
   (prin2 "Time for build: ")

   (prin2 (quotient (difference (time) (car !*init!-stats!*)) 1000.0))

   (prin2t " secs")
   (prin2 "Symbols used:   ")

   (prin2t (difference nextsymbol (cadddr !*init!-stats!*)))

   (prin2 "Heap used:      ")

   (prin2t (difference (cadr !*init!-stats!*) (gtheap nil)))

   (prin2 "BPS used:       ")

   (prin2t (difference (caddr !*init!-stats!*) (free-bps)))

   (prin2 "Heap left:      ")
   (prin2t (gtheap nil))

   (prin2 "BPS left:       ")
   (prin2t (free-bps))

  (setq !*init!-stats!* nil))


(savesystem "REDUCE" "../red/reduce" (quote ((read-init-file "reduce"))))

(bye)

