% Build checkpointed version of REDUCE.

(setq !*usermode nil)

(setq !*verboseload t)

(setq !*argnochk t)             % Check argument count.

(setq prolog_file 'pslprolo)

(setq rend_file 'pslrend)

(cond ((filep "$reduce/lisp/psl/$MACHINE/psl/symget.b")
       (dskin "$reduce/packages/support/symget.dat")))

(cond ((filep "$reduce/lisp/psl/$MACHINE/psl/addr2id.b")
       (load addr2id)))         % For debugging purposes.

(cond ((filep "$reduce/lisp/psl/$MACHINE/psl/pipes.b")
       (load pipes)))           % Unix pipes.

(load zbig)                     % PSL bignums.

(errorset '(load compat) nil nil)
				% Load PSL-based functions if there.
(load module)                   % Contains definition of load-package.

(load pslprolo)                 % PSL specific code.

(load patches)

(dskin "$reduce/packages/support/mkred2.sl")

% (load init-file)              % So that .reducerc possible.
				% Now defined in pslrend.red.
(setq !*loadversion t)          % Load entry module during BEGIN.

(setq !*verboseload nil)        % Inhibit loading messages.
