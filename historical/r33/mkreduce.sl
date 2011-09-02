(setq !*verboseload t)

(dskin "$reduce/src/symget.dat")        % for fast plist access
(load prolog)                           % Aliasing of ids used by PSL
(flag '(foreach repeat while) 'lose)
(load rlisp)                            % RLISP
(load rend)                             % PSL dependent code
(load arith)
(load mathlib)                          % mathematical function library
(load alg1)                             % basic algebra
(load alg2)                             % and augmentations
(load nbig)                             % PSL bignums
(remd 'crefon)                          % Since we don't use PSL version
(load entry)                            % entry points for other modules
(load init!-file)                       % allows for init file .reducerc

(setq !*verboseload nil)

(initreduce)

(setq date* "15-Jan-88")                % Official release date
