
%
% This script is normally run as
%     r37 ../util/testall.red -Dwhich_module=XXX
% where XXX is the name of a module that is to be tested. If XXX is left
% empty then the script will test all known modules.
%

symbolic;

load!-module 'remake;

get_configuration_data();

report_incomplete_tests r37_test_cases;

if boundp 'which_module and which_module and not (which_module = "") then <<
   mods := compress explodec which_module;
   if member(mods, r37_test_cases) then complete_tests list mods
   else error(0, list("unknown module to test", which_module)) >>
else complete_tests r37_test_cases;

end;

