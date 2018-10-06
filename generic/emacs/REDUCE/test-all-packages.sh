#!/usr/bin/bash

# Run all Emacs REDUCE test files.

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.

# Create log directory if necessary:
if [ ! -d log ]; then mkdir log; fi

hostname > log/testall.log
date >> log/testall.log

# xpackages='alg poly polydiv arith factor int matrix solve desir ineq modsr rsolve algint arnum assist dummy cantens atensor avector invbase boolean cali camal changevr compact dfpart lie odesolve pf cvit physop crack liepde applysym conlaw excalc gentran fide numeric randpoly reacteqn roots rlfi sets xideal eds groebner ideals linalg ncpoly normform orthovec laplace pm qsum scope sparse spde specfn tps limits defint fps trigint ratint mathml mathmlom redlog cgb sum zeilberg symmetry taylor mrvlimit residue susy2 tri trigsimp xcolor wu ztrans geoprover rataprx'

# crack hangs so comment out crack etc. for now

xpackages='alg poly polydiv arith factor int matrix solve desir ineq modsr rsolve algint arnum assist dummy cantens atensor avector invbase boolean cali camal changevr compact dfpart lie odesolve pf cvit physop excalc gentran fide numeric randpoly reacteqn roots rlfi sets xideal eds groebner ideals linalg ncpoly normform orthovec laplace pm qsum scope sparse spde specfn tps limits defint fps trigint ratint mathml mathmlom redlog cgb sum zeilberg symmetry taylor mrvlimit residue susy2 tri trigsimp xcolor wu ztrans geoprover rataprx'

for x in $xpackages; do echo $x >> log/testall.log; ./test-one-package.sh $x; done

date >> log/testall.log

echo 'Errors:'
cd log
grep '\*\*\*\*\*\|error[^.]' *.rlg
cd ..
