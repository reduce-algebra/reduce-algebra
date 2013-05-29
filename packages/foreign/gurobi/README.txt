This is foreign function interface to the commercial Gurobi optimizer
(http://www.gurobi.com/). At present it works only with CSL-Reduce. For
optionally using it with Redlog for the functions pzerop(), zerop(),
rltropsat(), rlptropsat() go

on rlgurobi, rlffi;

The Reduce part gurobi.red is automatically compiled when building Reduce. For
the C part, edit Makefile so that the variable GUROBI there yields a path to the
Gurobi sub-directory containing lib and include on your system. Then just go
"make". Afterwards, Reduce should automatically find all relevant files.

Thomas Sturm, May 2013
