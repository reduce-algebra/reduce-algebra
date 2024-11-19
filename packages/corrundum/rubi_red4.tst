% Test of rubi_red


% Note that "testdirectory" is expected to be set to a string that
% is the name of the current directory. It defaults a path into the
% Reduce tree if an environment variable "reduce" or "O" is set, and
% failing that to the current directory.

off int;

load_package rubi_red;
load_package specfn;
load_package sfgamma;

on errcont, ezgcd;
off precise;

lisp read_all_rubi_tests_version4();


end;
