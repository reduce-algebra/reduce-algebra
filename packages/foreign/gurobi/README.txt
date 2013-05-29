This is foreign function interface to the commercial Gurobi optimizer
(http://www.gurobi.com/). At present it works only with CSL-Reduce. It is
optionally used by Redlog for the functions pzerop(), zerop(), rltropsat(),
rlptropsat().

The Reduce part gurobi.red is automatically compiled when building Reduce. For
the C part, edit Makefile so that the variable GUROBI there yields a path to the
Gurobi sub-directory containing lib and include on your system. Then just go
"make". Aftrewards, Reduce should automatically find all relevant files.

Thomas Sturm, May 2013
