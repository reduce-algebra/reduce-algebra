#! /bin/sh

# check log files for all modules

# main log files go in log/*.rlg
# reference logs are in tests/*.rlg

./r38 -Dno_init_file util/checkall.red -- log/checkall.log

echo "log/checkall.log" is the main comparison log. A number of
echo least-significant-digit numerical differences shown there are
echo expected and do not represent problems.
echo "log/times.log" gives a summary of the performance on your machine
echo compared with a reference system which is an Athlon-64 3200+

