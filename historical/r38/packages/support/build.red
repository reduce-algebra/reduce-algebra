% module build;  % Code to help with bootstrapping REDUCE from Lisp.

% Author: Anthony C. Hearn.

% The baroque syntax in this file is a consequence of the bootstrapping
% process.

global '(loaded!-packages!* oldchan!*);

% Since some of the early modules may have tabs in them, we must redefine
% seprp.

symbolic procedure seprp u; 
    or(eq(u,'! ),eq(u,'!	),eq(u,!$eol!$));

symbolic procedure concat2(u,v);
   % This would be better supported at a lower level.
   compress('!" . append(explode2 u,nconc(explode2 v,list '!")));

symbolic procedure string!-downcase u;
   % This definition is designed to overcome bootstrapping difficulties
   % in the various Lisps used.
   begin scalar y,z;
      if null stringp u then u := '!" . append(explode2 u,'(!"))
       else u := explode u;
   a: if null u then return compress reverse z;
      y := atsoc(car u,
	 '((A . "a") (B . "b") (C . "c") (D . "d") (E . "e") (F . "f")
	   (G . "g") (H . "h") (I . "i") (J . "j") (K . "k") (L . "l")
	   (M . "m") (N . "n") (O . "o") (P . "p") (Q . "q") (R . "r")
	   (S . "s") (T . "t") (U . "u") (V . "v") (W . "w") (X . "x")
	   (Y . "y") (Z . "z")));
      if y then z := car explode2 cdr y . z else z := car u . z;
      u := cdr u;
      go to a
   end;

symbolic procedure mod2file(u,v);
    concat2("$reduce/packages/",concat2(string!-downcase v,
      concat2("/",concat2(string!-downcase u,".red"))));

symbolic procedure inmodule(u,v);
   begin
      u := open(mod2file(u,v),'input);
      v := rds u;
      cursym!* := '!*semicol!*;
   a: if eq(cursym!*,'end) then return progn(rds v, close u);
      prin2 eval form xread nil;
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
