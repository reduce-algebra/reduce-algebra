% Collect profile information about all REDUCE modules that have
% associated test scripts.  The information is put in "profile.dat"
% in the current directory but you then probably want to move it up
% into "../csl-c/profile.dat".  This last step is not automated because
% some people may want to tune the list of functions that will get
% compiled into C for themselves...

symbolic;

load!-module 'remake;

get_configuration_data();

delete!-file "profile.dat";

profile_a_package r37_test_cases;

bye;



