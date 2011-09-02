% module cslprolo;   % CSL dependent code for REDUCE.

% Author: Anthony C. Hearn.

% This file defines functions, variables and declarations needed to
% make REDUCE and the underlying CSL system compatible, and which need
% to be input before the system independent REDUCE source is loaded.

% Support for package creation.

symbolic procedure create!-package(u,v);
   % Make module list u into a package with path v.
   % Second argument is no longer used.
   if null idp car u then typerr(car u,"package name")
    else progn(put(car u,'package,u),
%          put(car u,'path,if null v then list car u else v),
           car u);

% create!-package('(cslprolo),nil);

symbolic procedure evload l;
% This is coded out as an explicit loop because it is processed rather
% early in the bootstrap sequence, and the nicer syntax I might prefer
% to use may not be stable...
  begin
top: if null l then return nil;
     load!-module car l;
     l := cdr l;
     go to top
  end;

%
% Well you might wonder... this is in cslprolo.red AND in cslrend.red.
% The reason is that it is needed early if rlisp is to be patchable. It
% is needed AFTER rlisp.red has been loaded because the first time in
% the bootstrap-build that RLISP is loaded no attention is given to LOSE
% properties (this is a REAL misery) so the definition must be put in
% place on top of the incorrect one builty by RLISP the first time
% around.
%

remflag('(copyd), 'lose);

symbolic procedure copyd(new,old);
% Copy the function definition from old id to new.
   begin scalar x;
      x := getd old;
% If loading with !*savedef = '!*savedef then the actual definitions
% do not get loaded, but the source forms do...
      if null x then progn(
        if not (!*savedef = '!*savedef)
          then rerror('rlisp,1,list(old,"has no definition in copyd")) )
      else progn(putd(new,car x,cdr x),
                 if flagp(old, 'lose) then flag(list new, 'lose) );
% The transfer of the saved definition is needed if the REDUCE "patch"
% mechanism is to work fully properly.
      if (x := get(old, '!*savedef)) then put(new, '!*savedef, x);
      return new
   end;

flag('(copyd), 'lose);

flag('(atsoc copy eqcar gcdn geq lastpair leq mkquote neq reversip
       rplacw),
     'lose);

!*argnochk := t;

% endmodule;

end;
