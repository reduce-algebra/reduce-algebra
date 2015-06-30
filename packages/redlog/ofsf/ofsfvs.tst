load_package redlog;
rlset r;

on ofsfvs;
off rlqefb;
on rlverbose;

% lisp;
% load_package debug;
% trprinter!* := 'mytrprint;

% procedure mytrprint(s);
%    if s and VStrP s then
%       vstr_printSummary s
%    else if s and VSndP s then
%       vsnd_printSummary s
%    else if s and VSndLP s then
%       vsndl_printLength s
%    else if s and VSsuP s then
%       vssu_printSummary s
%    else if s and (car s eq 'or or car s eq 'and) then
%       mathprint rl_prepfof s
%    else
%       printx s;

% compile '(mytrprint);
% algebraic;

on assert;
assert_install_all;

hugo := m*x + b >= 0 and x^2 - 3 < 0;
rlqe ex(x, hugo);

hugo := m*x^2 + b >= 0 and x^4 - 3 < 0;
rlqe ex(x, hugo);

hugo := m*x^3 + b >= 0 and x^6 - 3 < 0;
rlqe ex(x, hugo);

end;
