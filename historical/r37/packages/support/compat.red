MODULE COMPAT;

% Author: Anthony C. Hearn;

FLUID '(!*USERMODE);

GLOBAL '(SPARE!*);

SPARE!* := 10;

% This file defines functions and variables that are needed to 
% make REDUCE and the underlying PSL system compatible. It should
% be loaded as the first file whenever REDUCE services are required.

% Definitions of functions already defined in PSL

% PSL doesn't need PRINTPROMPT

REMFLAG('(PRINTPROMPT),'LOSE);

symbolic procedure printprompt u; nil;

flag('(printprompt),'lose);

% The following are all supported by PSL:

flag('(atsoc eqcar delasc mkquote aconc prin2t reversip union geq leq
        neq putc yesp),
      'lose);

flag('(rblock for foreach lprim repeat while),'user);  % to permit redef

symbolic procedure !*s2i u; u;

% These are needed until the PSL syslisp and trace modules are changed:

symbolic procedure definebop u; u;

symbolic procedure definerop u; u;

endmodule;

end;


