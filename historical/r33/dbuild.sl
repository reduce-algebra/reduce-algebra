% Build a PSL REDUCE "in core" without the use of fasl files.

(setq modules!* '(prolog rlisp rend arith alg1 rend alg2 % entry
		  matr hephys)) % util int solve ezgcd factor rcref
		  % rsltnt bfloat))

% The following three assignments are PSL dependent.

(setq *fastcar t)

(setq *usermode nil)

(setq *verboseload t)

(load compiler)

(setq !*int nil)           % prevents input buffer being saved

(setq !*msg nil)

(setq oldchan!* in!*)

(setq !*comp nil)

(flag '(eqcar) 'lose)

(dskin "symget.dat")    % For fast plist access.

(dskin "boot.sl")

% Note that the call of "rds" at the end of the boot file seems to be
% needed to make the system continue reading this input file after later
% exits from calls of rds.

(setq !*comp t)

(setq *argnochk t)

(begin2)
rds open("prolog.red",'input);
(begin2)
rds open("rlisp.red",'input);
(begin2)
rds open("rend.red",'input);
(begin2)
put('!~imports,'stat,'rlis);
for each x in cdddr modules!* do
    infile concat(string!-downcase x,".red");
end;

(load nbig)

(load init!-file)

(setq !*comp nil)

(setq !*verboseload nil)

(initreduce)

