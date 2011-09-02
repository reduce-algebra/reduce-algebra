% Build a PSL REDUCE "in core" without the use of fasl files.

% Author: Anthony C. Hearn.  Modifications by Stanley L. Kameny.

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

(load nbig30)                         % PSL bignums.

(global '(oldchan!* datchan!*))       % datchan!* needed for MS-DOS.

(setq !*argnochk t)

% (setq *ignoreeol t)      % Needed so that things like "module where" work.
			   % However, variable is no longer in use.

(setq !*int nil)           % prevents input buffer being saved

(setq !*msg nil)

(flag '(eqcar) 'lose)      % Already in PSL.

(setq !*comp t)            % It's faster if we compile the boot file.

(setq oldchan!* in!*)    % To continue reading this file after boot.sl.

(dskin "boot.sl")

(begin2)

rds(xxx := open("prolog.red",'input));

(close xxx)

(begin2)

rds(xxx := open("module.red",'input));

(close xxx)

(begin2)

rds(xxx := open("rlisp.red",'input));

(close xxx)

(begin2)

rds(xxx := open("rend.red",'input));

(close xxx)

(begin2)

rds(xxx := open("poly.red",'input));

(close xxx)

(begin2)

rds(xxx := open("alg.red",'input));

(close xxx)

% Even though ARITH isn't really necessary to compile most files, it's
% important to have it loaded when compiling itself to make sure that
% the floating point arithmetic is done at the right precision.

(begin2)

rds(xxx := open("arith.red",'input));

(close xxx)

(setq !*comp nil)

(setq !*verboseload nil)

% Necessary declaration from entry.red.

(put 'faslend 'stat 'endstat)

(initreduce)

(setq date!* "bootstrapping version")

(cond (datchan!* (rds datchan!*)))    % Needed for MS-DOS systems.
