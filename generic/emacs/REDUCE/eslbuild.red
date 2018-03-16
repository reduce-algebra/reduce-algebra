% module build;  % Code to help with bootstrapping REDUCE from Lisp.

% Author: Anthony C. Hearn.
% Revised for ESL REDUCE by Francis J. Wright.

global '(loaded!-packages!*);

symbolic procedure mod2file(u,v);
    concat("packages/", string!-downcase v, "/", string!-downcase u, ".red");

symbolic procedure inmodule(u,v);
   begin
      u := open(mod2file(u,v),'input);
      v := rds u;
      cursym!* := '!*semicol!*;
   a: if eq(cursym!*,'end) then return progn(rds v, close u);
      prin2 eval form xread nil;
	  prin2 " ";				  % FJW: for a more readable build log
      go to a;
   end;

symbolic procedure load!-package!-sources(u,v);
   begin scalar !*int,!*echo,w;
      inmodule(u,v);
      if (w := get(u,'package)) then w := cdr w;
   a: if w then progn(inmodule(car w,v), w := cdr w, go to a);
      loaded!-packages!* := u . loaded!-packages!*;
   end;

% endmodule;

end;
