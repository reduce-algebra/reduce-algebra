% Collect profile information about all REDUCE modules that have
% associated test scripts.  The information is put in "profile.dat"
% in the current directory but you then probably want to move it up
% to the place it really lives. This step is not automated here at
% present.

symbolic;

if boundp 'cpulimit and
   numberp (cpulimit := compress explodec cpulimit) and
   cpulimit > 0 then !*cpulimit := cpulimit;

if boundp 'conslimit and
   numberp (conslimit := compress explodec conslimit) and
   conslimit > 0 then !*conslimit := conslimit;


load!-module 'remake;

get_configuration_data();

delete!-file "profile.dat";
delete!-file "buildlogs/flaguse.log";

% I do not think that profiling the regresison tests is a useful idea.

for each x in reduce_regression_tests do
   reduce_test_cases := delete(x, reduce_test_cases);

profile_a_package reduce_test_cases;

bye;



