module switch;  % Support for switches and ON and OFF statements.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

global '(!*switchcheck switchlist!*);

% No references to RPLAC-based functions in this module.

symbolic procedure on u; for each j in u do on1 j;

symbolic procedure off u; for each j in u do off1 j;

symbolic procedure off1 u; onoff(u,nil);

symbolic procedure on1 u; onoff(u,t);

symbolic procedure onoff(u,bool);
   begin scalar x,y;
      if not idp u then typerr(u,"switch")
       else if not flagp(u,'switch)
%       then if !*switchcheck
               then rerror(rlisp,25,list(u,"not defined as switch"));
%             else lpriw("*****",list(u,"not defined as switch"));
      x := intern compress append(explode '!*,explode u);
      if !*switchcheck and lispeval x eq bool then return nil
       else if y := atsoc(bool,get(u,'simpfg))
        then lispeval('progn . append(cdr y,list nil));
      if bool and x eq '!*!r!a!i!s!e then x := '!*raise; % Special case.
       set(x,bool)
   end;

symbolic procedure switch u;
   % Declare list u as switches.
   for each x in u do
      begin scalar y;
         if not idp x then typerr(x,"switch");
	 if not(x memq switchlist!*)
           then switchlist!* := x . switchlist!*;
         flag(list x,'switch);
         y := intern compress append(explode '!*,explode x);
         if not fluidp y and not globalp y then fluid list y
      end;

deflist('((switch rlis)),'stat);   % we use deflist since it's flagged
                                   % eval
flag('(switch),'eval);

put('off,'stat,'rlis);

put('on,'stat,'rlis);

flag ('(off on),'ignore);

% Symbolic mode switches:

switch backtrace,comp,defn,demo,echo,errcont,fastfor,   % eoldelimp
       int,lessspace,msg,output,pret,quotenewnam,raise,time;

put('eoldelimp,'simpfg,'((t (flag (list !$eol!$) 'delchar))
                         (nil (remflag (list !$eol!$) 'delchar))));

% Support for REDUCE 4.

switch reduce4;

put('reduce4,'simpfg,'((t (load!-package 'reduce4) (!%reduce4))));

endmodule;

end;
