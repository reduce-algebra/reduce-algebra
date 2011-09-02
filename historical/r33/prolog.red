% module prolog;   % system dependent code for REDUCE

% Author: Anthony C. Hearn

% This file defines functions, variables and declarations needed to
% make REDUCE and the underlying PSL system compatible, and which need
% to be input before the system independent REDUCE source is loaded.

% Code for resolving aliasing name conflicts.

global '(!*quotenewnam);

symbolic procedure define!-alias!-list u;
   begin scalar x;
   a: if null u then return nil;
      x := intern compress append(explode '!~,explode car u);
      put(car u,'newnam,x);
      put(car u,'quotenewnam,x);
      u := cdr u;
      go to a
   end;


% Support for module loading

symbolic procedure load!-module u;
   begin scalar x;
      if not idp u then rederr list(u,"is not a module name");
      if null (x := get(u,'module!-list)) then return evload list u;
   a: if null x then return nil;
      load!-module car x;
      x := cdr x;
      go to a
   end;

% PSL doesn't need PRINTPROMPT

remflag('(printprompt),'lose);

symbolic procedure printprompt u; nil;

flag('(printprompt),'lose);

flag('(aconc atsoc copy delasc eqcar geq lastpair leq mkquote neq prin2t
       reversip rplacw union xn putc yesp),'lose);

flag('(block foreach lprim repeat while),'user);  % permits redefinition

!*quotenewnam := nil;

define!-alias!-list
      '(arrayp do for on off logand logxor let clear flatten imports
        indx mkid copy mkvec vector editf spaces2 prettyprint);

!*quotenewnam := t;

% Resolution of non-local variable definitions.

% The following PSL variables differ from the Standard LISP Report

remprop('!*comp,'vartype);

remprop('!*echo,'vartype);

remprop('!*raise,'vartype);

% The following are not in the Standard LISP Report, but differ from
% usual REDUCE usage.

remprop('!*output,'vartype);

remprop('cursym!*,'vartype);

% endmodule;

end;
