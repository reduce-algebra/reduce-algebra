#! /bin/sh -v

# "rebuild.sh"
#
# This does a simple but complete build of both the CSL and PSL versions
# of REDUCE. It leaves a log from these builds in a suitably simple top-level
# file rebuild.log. If you want to ensure that the rebuild is clean just
# remove the cslbuild and pslbuild directories before running this script.

./configure --with-csl
./configure --with-psl

make 2>&1 | tee rebuild.log

# end of rebuild.sh
