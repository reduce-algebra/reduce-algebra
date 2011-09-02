% Source for building REDUCE executable.

(reclaim)

(setq !*init!-stats!* (list (time) (gtheap nil) (free-bps) nextsymbol))

(load addr2id)                          % For debugging purposes

(setq !*verboseload t)                  % For debugging purposes

(setq !*argnochk t)                     % For argument no. checking

% Load REDUCE code

(load nbig30)                           % PSL bignums
(load module)                           % Definition of module etc.
(load prolog)                           % PSL-specific code
(flag '(foreach repeat while) 'lose)
(load rlisp)                            % RLISP
(load rend)                             % PSL dependent code
(load poly)
(load alg)                              % basic algebra
(load arith)
(load mathpr)
(remd 'crefon)                          % Since we don't use PSL version
(load entry)                            % entry points for other modules
(load init!-file)                       % allows for init file .reducerc

(setq !*verboseload nil)        % Inhibit loading messages.

(initreduce)

(setq date* "15-Jul-91")                % Official release date

% Print some statistics.

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

