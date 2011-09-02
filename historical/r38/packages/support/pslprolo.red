% module pslprolo;   % PSL dependent code for REDUCE.

% Author: Anthony C. Hearn.

% This file defines functions, variables and declarations needed to
% make REDUCE and the underlying PSL system compatible, and which need
% to be input before the system independent REDUCE source is loaded.

% Support for package creation.

symbolic procedure create!-package(u,v);
   % Make module list u into a package with path v.
   % Second argument is no longer used.
   if null idp car u then typerr(car u,"package name")
    else progn(put(car u,'package,u),
%          put(car u,'path,if null v then list car u else v),
           car u);

% create!-package('(pslprolo),nil);

% Code for resolving aliasing name conflicts.

fluid '(!*quotenewnam);

symbolic procedure define!-alias!-list u;
   begin scalar x;
   a: if null u then return nil;
      x := intern compress append(explode '!~,explode car u);
      put(car u,'newnam,x);
      put(x,'oldnam,car u);
      put(car u,'quotenewnam,x);
      u := cdr u;
      go to a
   end;


% PSL doesn't need PRINTPROMPT.

remflag('(printprompt),'lose);

symbolic procedure printprompt u; nil;

flag('(printprompt),'lose);

flag('(gcdn),'lose);     % Defined in bignum package.

flag('(aconc atsoc copy delasc eqcar geq lastpair leq mkquote neq
       prin2t reversip rplacw putc yesp),'lose);

flag('(rblock foreach lprim repeat while),'user); % permits redefinition

% The following assignment is done this way for bootstrapping.

flag('(set),'eval);

set('!*quotenewnam,nil);

define!-alias!-list
      '(arrayp do for on off let clear flatten imports
        indx mkid mkvec vector editf spaces2 prettyprint);

set('!*quotenewnam,t);

remflag('(set),'eval);


% Resolution of non-local variable definitions.

% The following PSL variables differ from the Standard LISP Report

remprop('!*comp,'vartype);

remprop('!*raise,'vartype);

% The following are not in the Standard LISP Report, but differ from
% usual REDUCE usage.

remprop('cursym!*,'vartype);

% endmodule;


end;
