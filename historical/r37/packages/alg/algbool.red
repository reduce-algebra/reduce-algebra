module algbool; % Evaluation functions for algebraic boolean operators.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

symbolic procedure evalequal(u,v);
   begin scalar x;
      return if (x := getrtype u) neq getrtype v then nil
              else if null x
               then numberp(x := reval list('difference,u,v))
                       and zerop x
              else u=v
   end;

put('equal,'boolfn,'evalequal);

% symbolic procedure equalreval u; 'equal . revlis u;  % defined in eqn.

% put('equal,'psopfn,'equalreval);

put('equal,'rtypefn,'quoteequation);

symbolic procedure quoteequation u; 'equation;

symbolic procedure evalgreaterp(u,v);
   (lambda x;
    if not atom denr x or not domainp numr x
      then typerr(mk!*sq if minusf numr x then negsq x else x,"number")
     else numr x and !:minusp numr x)
        simp!* list('difference,v,u);

put('greaterp,'boolfn,'evalgreaterp);

symbolic procedure evalgeq(u,v); not evallessp(u,v);

put('geq,'boolfn,'evalgeq);

symbolic procedure evallessp(u,v); evalgreaterp(v,u);

put('lessp,'boolfn,'evallessp);

symbolic procedure evalleq(u,v); not evalgreaterp(u,v);

put('leq,'boolfn,'evalleq);

symbolic procedure evalneq(u,v); not evalequal(u,v);

put('neq,'boolfn,'evalneq);

symbolic procedure evalnumberp u; 
   (if atom x then numberp x
     else if not(car x eq '!*sq) or not atom denr cadr x then nil
     else (atom y or flagp(car y,'numbertag)) where y=numr cadr x)
    where x=aeval u;

put('numberp,'boolfn,'evalnumberp);

% Number tags.

flag('(!:rd!: !:cr!: !:rn!: !:crn!: !:mod!: !:gi!:),'numbertag);

symbolic procedure ratnump x;
   % Returns T iff any prefix expression x is a rational number.
   atom numr(x := simp!* x) and atom denr x;

flag ('(ratnump), 'boolean);

endmodule;

end;
