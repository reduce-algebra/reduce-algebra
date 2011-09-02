MODULE MKFASL --- Produce a fasl loading version of a given file;

% Author: Martin L. Griss.

% Modifications by: Anthony C. Hearn;


fluid '(rfasl!* rsrc!* !*break !*lower !*quiet!_faslout !*usermode
        !*writingfaslfile);

global '(!*echo);

symbolic procedure mkfasl u;
   % produce a FASL file for the module u;
   if errorp errorset(list('mkfasl1,mkquote u),t,!*backtrace)
     then <<if !*writingfaslfile then eval '(faslend);
            errorprintf("***** Error during mkfasl of %w%n",u)>>;

flag('(mkfasl),'opfn);

flag('(mkfasl),'noval);

symbolic procedure mkfasl1 u;
   begin scalar !*int,!*lower,!*usermode,!*quiet!_faslout,!*break,echo,
                ichan,oldichan;
      echo := !*echo;
      !*echo := nil;
      !*quiet!_faslout := t;
      terpri();
      prin2t bldmsg("*** Compiling %w ...",u);
      terpri();
      u := string!-downcase u;
      ichan := open(concat(u,".red"),'input);
      oldichan := rds ichan;
      faslout bldmsg("%w%w",rfasl!*,u);
      begin1();
      eval '(faslend);
      !*echo := echo;
      close ichan;
      rds oldichan
   end;

endmodule;

end;
