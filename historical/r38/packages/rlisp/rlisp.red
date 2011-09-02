% module rlisp;  % Header module for rlisp package.

% Author: Anthony C. Hearn.

global '(date!* patch!-date!* version!*);

create!-package('(rlisp module newtok rsupport slfns superv tok xread
                  lpri parser block form proc forstat loops statmisc
		  smacro io infix switch where list array inter),
                 nil);

flag('(rlisp),'core!_package);

if patch!-date!* then
    date!* := compress('!" . append(explode2 "15-Apr-2004, patched to ",
				nconc(explode2 patch!-date!*,list '!")))
 else date!* := "15-Apr-2004";

if null version!* then version!* := "REDUCE 3.8";

% Hook to Rlisp88.

put('rlisp88,'simpfg,'((t (load!-package 'rlisp88) (rlisp88!_on))));

flag('(rlisp88),'switch);

% endmodule;

end;
