Time-stamp: "2020-04-16 11:23:31 vitolo"

This folder contains software for the CDE package, written by Raffaele
Vitolo. It is devoted to computations for general differential equations (i.e.,
not necessarily in evolution form) with an arbitrary number of independent
variables. It can compute symmetries, conservation laws, Hamiltonian,
symplectic and recursion operators, in local and nonlocal coordinates. It is
distributed under the same free license of REDUCE. A complete user guide is
included as a chapter in the main Reduce manual. The Reduce manual can be found
in the /doc subfolder of the main folder of Reduce source code.

CDE version: 3.0 (see also the initial message, or the initial part
of the master file cde.red).

This folder contains:

A README.txt file;
 - The program file cde.red, for computations of differential consequences
of even and odd partial differential equations and of the related total
derivatives. The master file cde.red defines global variables and switches
and loads the files:
1   cde_ansatz.red: utilities for generating ansatz for solving equations
2  cde_cdcalc.red: calculus with C-differential operators
3   cde_cdiff.red: data structure of C-differential operators
4   cde_diffcon.red: calculating differential consequences of
      a differential equation
5   cde_init.red: runs all procedures that define the environment
6   cde_jetspace.red: definition of the jetspace
7   cde_parametric.red: splitting variables into parametric
      and principal derivatives
8   cde_superfun.red: data structure of superfunctions
9   cde_tools.red: lisp utilities used throughout the package
10  cde_totalder.red: defining total derivatives
11  cde_varcalc.red: calculus of variations on supermanifolds
12  cde_vectorfield.red: data structure and calculus with
      evolutionary vector fields
13  cde_weaklynl.red: Schouten bracket of nonlocal C-differential operators
      CLV algorithm
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
