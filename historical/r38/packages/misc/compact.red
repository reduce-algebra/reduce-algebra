module compact;  % Header module for compact code.

% Author: Anthony C. Hearn.

% Copyright (c) 1989 The RAND Corporation.  All Rights Reserved.

create!-package('(compact mv mvmatch reddom compactf comfac),
                '(contrib compact));

% These smacros are used in more than one module.

symbolic smacro procedure mv!-!.!+(u,v); u . v;

symbolic smacro procedure mv!-!.!*(u,v); u . v;

symbolic smacro procedure mv!-lc u; cdar u;

symbolic smacro procedure mv!-lpow u; caar u;

symbolic smacro procedure mv!-lt u; car u;

symbolic smacro procedure mv!-red u; cdr u;

endmodule;

end;
