module sfgamma;   % Gamma function procedures and rules for REDUCE.

% Author: Chris Cannam, Sept/Oct '92.

remprop('gamma,'simpfn);
remprop('igamma,'simpfn);
remprop('beta,'simpfn);
remprop('polygamma,'simpfn);
remprop('ibeta,'simpfn);
remprop('zeta,'simpfn);
remprop('pochhammer,'simpfn);
remprop('psi,'simpfn);

create!-package ('(sfgamma sfgamm sfpsi sfigamma),'(contrib specfn));

fluid '(bernoulli!-alist new!*bfs bf!*base sf!-alist !*savefs);

bf!*base := (if new!*bfs then 2 else 10) ;

symbolic smacro procedure sq2bf!*(x);
   (if fixp x then i2bf!: x
      else ((if car y neq '!:rd!: then retag cdr !*rn2rd y
               else retag cdr y) where y = !*a2f x));

symbolic smacro procedure c!:prec!:;
   (if new!*bfs then lispeval '!:bprec!: else !:prec!:);

endmodule;

end;

