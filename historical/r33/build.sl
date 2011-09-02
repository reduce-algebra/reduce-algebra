% PSL dependent file for complete rebuild of REDUCE fasl file set

% Author: Anthony C. Hearn.

(setq modules!* '(prolog rlisp rend arith mathlib alg1 alg2 entry matr
		  hephys util int solve ezgcd factor rcref rsltnt
		  algint anum gentran groebner spde mkfasl bfloat
		  excalc))
		% Note that excalc changes the meaning of various infix
		% operators, and so must be defined last.

% The following assignments are PSL dependent.

(setq *fastcar t)

(setq *usermode nil)

(setq *verboseload t)

(load compiler)

% The following is PSL dependent.

(setq !*int nil)           % prevents input buffer being saved

(setq !*msg nil)

(setq oldchan!* in!*)

%%%(setq !*comp t)    % It's faster if we compile the boot file.

(flag '(eqcar) 'lose)   % PSL dependent.

(setq *syslisp t)       % This makes a small difference to rlisp and rend.

(dskin "symget.dat")    % For fast plist access.

(dskin "boot.sl")

% Note that the call of "rds" at the end of the boot file seems to be
% needed to make the system continue reading this input file after later
% exits from calls of rds.

%%(setq !*comp t)

(setq *argnochk t)

(begin2)
rds open("prolog.red",'input);
(begin2)
rds open("rlisp.red",'input);
(begin2)
infile "rend.red"$
infile "mkfasl.red"$
end;
(initreduce)
(begin2)
on gc,msg;
ipl!* := list("util/build.sl" .  oldchan!*);   %to fool IN

!*quotenewnam := nil;   % We need to compile prolog with this off.

for each x in modules!* do 
       <<if x eq 'bfloat then load nbig
	  else if x eq 'alg2
           then eval list('load,bldmsg("%w%w",rfasl!*,"alg1"))
	  else if x eq 'solve
           then eval list('load,bldmsg("%w%w",rfasl!*,"alg2"));
     terpri(); terpri();
     semic!* := '!$;   % to fool IN
     mkfasl x;
     !*quotenewnam := t>>$

bye;
