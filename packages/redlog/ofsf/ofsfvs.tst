load_package redlog;
rlset r;

% lisp;
% load_package debug;
% trprinter!* := 'mytrprint;

% procedure mytrprint(s);
%    if VStrP s then
%       vstr_printSummary s
%    else if VSndLP s and s then
%       vsndl_printLength s
%    else if VSndP s then
%       vsnd_printSummary s
%    else
%       printx s;

% compile '(mytrprint);
% algebraic;

on ofsfvs;
off rlqefb;
on rlverbose;

on assert;
assert_install_all;

hugo := m*x + b >= 0 and x^2 - 3 < 0;

rlqe ex(x, hugo);

end;
