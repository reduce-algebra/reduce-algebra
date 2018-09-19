#!/usr/bin/bash

# Compile all Emacs REDUCE packages (older than their source files).

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.

# Create log directory if necessary:
if [ ! -d log ]; then mkdir log; fi

date > log/remake.log

# Build core system

# $reduce/util/remake2

# Build packages in "packages" directory:

packages='support rlisp alg poly polydiv arith mathpr ezgcd factor hephys int matrix rlisp88 rprint fmprint pretty solve desir ineq modsr rsolve algint arnum assist dummy cantens atensor avector invbase misc boolean cedit rcref ftr reset cali camal changevr compact dfpart lie tmprint'

for x in $packages; do echo $x >> log/remake.log; ./remake-one-package.sh $x; done

packages='odesolve pf cvit noncom2 physop crack liepde applysym conlaw excalc gentran fide1 fide numeric randpoly reacteqn roots rlfi roots2 sets xideal eds dipoly groebner groebnr2 ideals linalg ncpoly normform orthovec plot gnuplot laplace pm qsum scope sparse spde specfn'

for x in $packages; do echo $x >> log/remake.log; ./remake-one-package.sh $x; done

packages='specfn2 specfaux specbess sfgamma tps limits defint fps trigint ratint mathml mathmlom redlog rltools cl cgb ofsf dvfsf acfsf sum zeilberg symaux symmetry taylor mrvlimit residue susy2 tri trigsimp xcolor wu ztrans geoprover rataprx rtrace'

for x in $packages; do echo $x >> log/remake.log; ./remake-one-package.sh $x; done

date >> log/remake.log
