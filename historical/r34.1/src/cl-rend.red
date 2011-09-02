module rend; % CL REDUCE "back-end".

% Copyright (c) 1991 RAND.  All Rights Reserved.

symbolic procedure delcp u;
   % Returns true if U is a semicolon, dollar sign, or other delimiter.
   % This definition replaces one in the BOOT file.
   u eq '!; or u eq '!$;

symbolic procedure seprp u;
   % Returns true if U is a blank or other separator (eg, tab or ff).
   % This definition replaces one in the BOOT file.
     u eq '!  or u eq '!         or u eq !$eol!$;

% Common LISP specific definitions.

flag('(load),'opfn);

% The next one is added since it is a familiar name for this
% operation.

symbolic procedure prop u; symbol!-plist u;
  

% tr and untr are defined in clend.lisp.

deflist('((tr rlis) (untr rlis)),'stat);


% The FACTOR module also requires a definition for GCTIME. Since this
% is currently undefined in CL, we provide the following definition.

symbolic procedure gctime; 0;

% yesp1 is more or less equivalent to y-or-n-p.

remflag('(yesp1),'lose);

symbolic procedure yesp1; y!-or!-n!-p();

flag('(yesp1),'lose);

% The Common Lisp TOKEN function returns tokens rather than characters,
% so CEDIT must be modified.

remflag('(cedit),'lose);

symbolic procedure cedit n;
   begin scalar x,ochan;
      if null terminalp() then rederr "Edit must be from a terminal";
      ochan := wrs nil;
      if n eq 'fn then x := reversip crbuf!*
       else if null n
        then if null crbuflis!*
               then <<statcounter := statcounter-1;
                      rederr "No previous entry">>
              else x := cdar crbuflis!*
       else if (x := assoc(car n,crbuflis!*))
        then x := cedit0(cdr x,car n)
       else <<statcounter := statcounter-1;
              rederr list("Entry",car n,"not found")>>;
      crbuf!* := nil;
      % Following line changed for CL version.
      x := foreach y in x conc explodec y;
      terpri();
      editp x;
      terpri();
      x := cedit1 x;
      wrs ochan;
      if x eq 'failed then nil
      % Following changed for CL version.
      else 
        crbuf1!* := compress(append('(!") ,
                                       append(x, '(!" ))));
   end;

flag('(cedit),'lose);

% FLOOR is already defined.

flag('(floor),'lose);

% CL doesn't like '(function ...) in defautoload (module entry).

remflag('(mkfunction),'lose);

smacro procedure mkfunction u; mkquote u;

flag('(mkfunction),'lose);

endmodule;

end;
