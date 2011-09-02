module specbess;  % Special functions package; Bessel and relatives.

% Author:  Chris Cannam, Sept-Nov 1992.
%          Winfried Neun, Nov 1992 ...
%	   contribution from various authors ...

remprop('besseli,'simpfn);
remprop('besselj,'simpfn);
remprop('bessely,'simpfn);
remprop('besseli,'simpfn);
remprop('besselk,'simpfn);
remprop('hankel1,'simpfn);
remprop('hankel2,'simpfn);
remprop('kummerM,'simpfn);
remprop('kummerU,'simpfn);
remprop('struveh,'simpfn);
remprop('struvel,'simpfn);
remprop('lommel1,'simpfn);
remprop('lommel2,'simpfn);
remprop('whittakerm,'simpfn);
remprop('whittakerw,'simpfn);
remprop('Airy_Ai,'simpfn);
remprop('Airy_Bi,'simpfn);
remprop('Airy_AiPrime,'simpfn);
remprop('Airy_biprime,'simpfn);


create!-package ('(specbess sfbes sfkummer sfother sfairy),
                 '(contrib specfn));

symbolic smacro procedure sq2bf!*(x);
   (if fixp x then i2bf!: x
      else ((if car y neq '!:rd!: then retag cdr !*rn2rd y
               else retag cdr y) where y = !*a2f x));

symbolic smacro procedure c!:prec!:;
   (if new!*bfs then lispeval '!:bprec!: else !:prec!:);

% These functions are needed in other modules.

algebraic procedure complex!*on!*switch;
   if not symbolic !*complex then
      if symbolic !*msg then
         << off msg;
            on complex;
            on msg >>
      else on complex
   else t;

algebraic procedure complex!*off!*switch;
   if symbolic !*complex then
      if symbolic !*msg then
         << off msg; off complex; on msg >>
      else off complex
   else t;

algebraic procedure complex!*restore!*switch(fl);
   if not fl then
      if symbolic !*msg then
         << off msg;
            if symbolic !*complex then
               off complex
            else on complex;
            on msg >>
      else if symbolic !*complex then
            off complex
         else on complex;

endmodule;

end;



