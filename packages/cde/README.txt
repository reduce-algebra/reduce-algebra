Time-stamp: "2017-09-23 11:43:41 vitolo"

This folder contains software for the CDE package, written by Raffaele
Vitolo. It is devoted to computations for general differential equations (i.e.,
not necessarily in evolution form) with an arbitrary number of independent
variables. It can compute symmetries, conservation laws, Hamiltonian,
symplectic and recursion operators, in local and nonlocal coordinates. It is
distributed under the same free license of REDUCE. A complete user guide is
included as a chapter in the main Reduce manual. The Reduce manual can be found
in the /doc subfolder of the main folder of Reduce source code.

CDE version: 2.1 (see also the initial message, or the initial part
of the master file cde.red).

This folder contains:

A README.txt file;
 - The program file cde.red, for computations of differential consequences
of even and odd partial differential equations and of the related total
derivatives. cde.red will load the files:
   cde.red: master file, defining global variables and switches
   cde_tools.red: tools file with lisp utilities
   cde_jetspace.red: definition of the jetspace
   cde_parametric.red: splitting variables into parametric and principal
      derivatives
   cde_totalder.red: defining total derivatives
   cde_diffcon.red: calculating differential consequences of the equation
   cde_varcalc.red: calculus of variations on supermanifolds
   cde_cdiff.red: data structure of C-differential operators
   cde_superfun.red: data structure of superfunctions
   cde_cdcalc.red: calculus of C-differential operators
   cde_ansatz.red: utilities for generating ansatz for solving equations
   cde_init.red: runs all procedures that define the environment
 - A test file cde.tst, with the computation of the two local Hamiltonian
 structures for the KdV equation.
 - The file global.txt with a list of global variables used in cdi.red.
 - The folder examples, which contains all examples described in the user guide
 with results and state files.
 - The folders examples/results and examples/state contain all result and state
 files. The script cde_test.sh runs all the example files, writes results and
 states and compares them with the old results and states as a regression test
 suite.

In the folder examples a shell script `cde_test.sh' (it works only in bash, a
unix/linux shell) that runs reduce on all examples has been inserted.
There is also a script `rrr.sh' by A.M. Verbovetsky that is useful to check
if the computation must be redone on a higher jet space and automatically
reruns reduce if needed.

The authors welcomes comments and questions on CDE.
Raffaele Vitolo,
Dipartimento di Matematica e Fisica, Universita' del Salento
via per Arnesano 73100 Lecce, Italy
raffaele.vitolo@unisalento.it
http://poincare.unisalento.it/vitolo
