
Comment 
 simplog didn't completely factor its argument when expandlogs on factor was on;

on factor,expandlogs; 

off precise;

z := 1-x^2;

log(z);

% The following used to return 
%   log( - (x + 1)*(x - 1))

log(1-x^2);

end;
