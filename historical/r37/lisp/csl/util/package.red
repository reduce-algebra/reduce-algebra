% This gets a single REDUCE package compiled and uup to date

symbolic;

load!-module 'remake;

if not boundp 'target or null target then target := 'alg;

get_configuration_data();

build_reduce_modules list target;

end;

