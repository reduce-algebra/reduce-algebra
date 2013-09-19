This is foreign function interface to the Z3 SMT solver
(http://z3.codeplex.com/). At present it works only with CSL-Reduce. The Reduce
part z3.red is automatically compiled when building Reduce. For the C part, edit
Makefile so that the variable Z3 there yields a path to the Z3 sub-directory
containing lib and include on your system. Then just go "make". Afterwards,
Reduce should automatically find all relevant files.

M. Kosta, T. Sturm, September 2013
