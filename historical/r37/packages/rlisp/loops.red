module loops;  % Looping forms other than the FOR statement.
                
% Author: Anthony C. Hearn

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*blockp);

global '(cursym!*);


% ***** REPEAT STATEMENT *****

symbolic procedure repeatstat;
  begin scalar !*blockp,body,bool;
	if flagp('until,'delim) then bool := t
	 else flag('(until),'delim);
	body:= xread t;
	if not bool then remflag('(until),'delim);
	if not(cursym!* eq 'until) then symerr('repeat,t);
	return list('repeat,body,xread t);
   end;

symbolic macro procedure repeat u;
   begin scalar body,bool,lab;
        body := cadr u; bool := caddr u;
        lab := gensym();
        return mkprog(nil,list(lab,body,
                list('cond,list(list('not,bool),list('go,lab)))))
   end;

put('repeat,'stat,'repeatstat);

flag('(repeat),'nochange);

symbolic procedure formrepeat(u,vars,mode);
   begin scalar !*!*a2sfn;
      !*!*a2sfn := 'aeval!*;
      return list('repeat,formc(cadr u,vars,mode),
		  formbool(caddr u,vars,mode))
   end;

put('repeat,'formfn,'formrepeat);


% ***** WHILE STATEMENT *****

symbolic procedure whilstat;
   begin scalar !*blockp,bool,bool2;
	if flagp('do,'delim) then bool2 := t else flag('(do),'delim);
	bool := xread t;
	if not bool2 then remflag('(do),'delim);
	if not(cursym!* eq 'do) then symerr('while,t);
	return list('while,bool,xread t)
   end;

symbolic macro procedure while u;
   begin scalar body,bool,lab;
        bool := cadr u; body := caddr u;
        lab := gensym();
        return mkprog(nil,list(lab,list('cond,list(list('not,bool),
                list('return,nil))),body,list('go,lab)))
   end;

put('while,'stat,'whilstat);

flag('(while),'nochange);

symbolic procedure formwhile(u,vars,mode);
   begin scalar !*!*a2sfn;
      !*!*a2sfn := 'aeval!*;
      return list('while,formbool(cadr u,vars,mode),
		  formc(caddr u,vars,mode))
   end;

put('while,'formfn,'formwhile);

endmodule;

end;



