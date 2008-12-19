% dbuild.sl -- build a PSL REDUCE "in core" without use of fasl files.

% Author: Anthony C. Hearn.

(load addr2id)   % In case an error occurs.

(setq !*fastcar t)

(setq !*usermode nil)

(setq !*verboseload t)

(remprop 'cursym!* 'vartype)          % PSL declares this fluid.

% Compiler modifications.

(load compiler)
(remprop 'wplus2 'one)                % PSL compiler bug.
(remprop 'log 'no!-side!-effects!?)   % So that math can be fasled.
(remprop 'atan 'no!-side!-effects!?)  % So that math can be fasled.
(remprop '!*msg 'vartype)             % Compiler declares this global.
(load fast!-vector)                   % To use IGETV, etc.

(cond ((filep "symget.b")
       (dskin "$reduce/psl/symget.dat")))

(load zbig)                           % PSL bignums.

(errorset '(load compat) nil nil)     % Load PSL accelerators if there.

(flag '(eqcar) 'lose)                 % Already in PSL.

(setq !*init!-time!* (time))

(setq prolog_file 'pslprolo)

(setq rend_file 'pslrend)

(copyd 'rdf 'dskin)                   % CSL has a nicer name for this.

(global '(oldchan!* datchan!*))       % datchan!* needed for MS-DOS.

(setq oldchan2!*
    (rds (setq oldchan!*
	     (open "$reduce/psl/dbuild2.sl" 'input))))
				      % PSL independent code.
(close oldchan!*)

(setq !*verboseload nil)

(prog nil
   (reclaim)
   (prin2 "Time for build: ")
   (prin2 (quotient (difference (time) !*init!-time!*) 1000.0))
   (prin2t " secs")
   (prin2 "Heap left:      ")
   (prin2t (gtheap nil))
   (prin2 "BPS left:       ")
   (prin2t (free-bps)))

(initreduce)

(setq date!* (date))

(setq version!* "Bootstrapping REDUCE")

(cond (datchan!* (rds datchan!*)))    % Needed for MS-DOS systems.
