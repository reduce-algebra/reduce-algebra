module rlisp88;   % Support for the RLISP '88 superset.

% Author:  Anthony C. Hearn.

fluid '(!*minusliter !*mode !*oldminusliter !*rlisp88 forbinops!*
	oldmode!*);

switch rlisp88;

create!-package('(rlisp88 for88 loops88 bquote comment rvector mstruct
		  records inspect),
		'(rlisp));

symbolic procedure rlisp88_on;
   begin
      if !*rlisp88 then return nil;
      !*rlisp88 := t;
      !*oldminusliter := !*minusliter;
      !*minusliter := t;
      deflist('((module formmodule) (global formglobalfluid)
		(fluid formglobalfluid) (procedure nformproc)),
	      'formfn);
      remprop('join,'newnam);
      put('conc,'newnam,'join);
      put('oldwhen,'infix,get('when,'infix));
      remprop('when,'infix);
      flag('(for),'nochange);   % Check on this.
      deflist(forbinops!*,'bin);
      deflist('((for forstat88) (repeat repeatstat88)
		(while whilstat88)),'stat);
      deflist('((for formfor88) (repeat formrepeat88)
		(while formwhile88)),'formfn);
      copyd('for,'for88);
      copyd('oldrepeat!*,'repeat);
      remd 'repeat;
      copyd('repeat,'repeat88);
      copyd('oldwhile!*,'while);
      remd 'while;   % To avoid messages.
      copyd('while,'while88);
      if not(!*mode eq 'symbolic)
	then <<oldmode!* := !*mode;  !*mode := 'symbolic>>;
      % The following statements, and their colloraries in rlisp88_off,
      % reveal problems with the current REDUCE model; it cannot specify
      % attributes in algebraic mode that do not apply in symbolic mode.
      % The following are representative, and by no means exhaustive.
      remprop('array,'stat);
      remprop('index,'stat);
      remprop('def,'stat);
      remprop('array,'formfn);
      remprop('add,'number!-of!-args);
      remprop('add,'smacro)
   end;

symbolic procedure rlisp88_off;
   begin
      if null !*rlisp88 then return nil
       else if null getd 'oldrepeat!*
	then rederr "Rlisp88 mode not set";
      !*minusliter := !*oldminusliter;
      remprop('module,'formfn);
      remprop('global,'formfn);
      remprop('fluid,'formfn);
      put('procedure,'formfn,'formproc);
      remprop('conc,'newnam);
      put('join,'newnam,'conc);
      put('when,'infix,get('oldwhen,'infix));
      remflag('(for),'nochange);
      for each x in '(append collect count join maximize minimize)
	  do remprop(x,'bin);
      deflist('((product times2) (sum plus2)),'bin);
      deflist('((for forstat) (repeat repeatstat) (while whilstat)),
		'stat);
      deflist('((for formfor) (repeat formrepeat) (while formwhile)),
		'formfn);
      remd 'for;
      remd 'repeat;
      remd 'while;
      copyd('repeat,'oldrepeat!*);
      copyd('while,'oldwhile!*);
      remd 'oldrepeat!*;
      remd 'oldwhile!*;
      if oldmode!* then <<!*mode := oldmode!*; oldmode!* := nil>>;
      deflist('((array rlis) (def rlis) (index rlis)),'stat);
      put('array,'formfn,'formarray);
      put('add,'number!-of!-args,2);
      put('add,'smacro,'(lambda (u v) (cons u v)))
   end;

put('rlisp88,'simpfg,'((t (rlisp88_on)) (nil (rlisp88_off))));

endmodule;

end;
