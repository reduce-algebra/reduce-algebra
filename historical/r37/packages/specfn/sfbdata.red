module sfbdata;  % Generate necessary data for Bernoulli computation.

% Author:  Winfried Neun.

fluid '(compute!-bernoulli);

global '(!*force);

flag('(force),'switch);

flag('(on),'eval);

on force;

symbolic macro procedure mk!-bernoulli u;
   <<for i := 1:300 do retrieve!*bern i;
     list('quote, bernoulli!-alist) >>;

% When I read in save!-bernoulli the macro mk!-bernoulli() will get
% expanded.  This is because of the RLISP flag "*force".  The effect
% will be that the definition of save!-bernoulli() is in effect
% just   bernoulli!-alist := '((....))

symbolic procedure save!-bernoulli();
   bernoulli!-alist := mk!-bernoulli();

% I want to execute save!-bernoulli() just once to initialize the
% table.  That way even if I am running interpreted the painfully
% slow initial calculation of the table gets done only once when
% I first process this chunk of code.

save!-bernoulli()$

compute!-bernoulli := t;

off force;

remflag('(on),'eval);

endmodule;

end;

