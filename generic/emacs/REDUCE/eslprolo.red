% module eslprolo;   % ESL dependent code for REDUCE.

% Author: Anthony C. Hearn.
% Revised for ESL REDUCE by Francis J. Wright.

% This file defines functions, variables and declarations needed to
% make REDUCE and the underlying ESL system compatible, and which need
% to be input before the system independent REDUCE source is loaded.

symbolic procedure seprp u;
   % Return true if U is a blank or other separator (tab, CR, etc.).
   % This definition replaces one in the BOOT file.
   or(eq(u,'! ),eq(u,'!	),eq(u,'!),eq(u,'!),eq(u,!$eol!$));


% Support for package creation.

symbolic procedure create!-package(u,v);
   % Make module list u into a package with path v.
   % Second argument is no longer used.
   if null idp car u then typerr(car u,"package name")
    else progn(put(car u,'package,u),
%          put(car u,'path,if null v then list car u else v),
           car u);

% create!-package('(eslprolo),nil);

% endmodule;

end;
