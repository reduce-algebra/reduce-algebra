#! /bin/sh

# test all modules

# main log files go in log/*.rlg

./r38 -v util/testall.red -Dno_init_file -Dwhich_module=$1 -- log/testall.log

echo "log/testall.log" is main output
echo See log/*.rlg for individual logs.
echo You can now run checkall.sh to check results.
