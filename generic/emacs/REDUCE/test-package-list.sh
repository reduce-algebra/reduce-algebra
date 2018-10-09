#!/usr/bin/bash

# List of Emacs REDUCE test files.

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

packages1='alg poly polydiv arith factor int matrix solve desir ineq modsr rsolve algint arnum assist dummy cantens atensor avector invbase boolean cali camal changevr compact dfpart lie'

# crack hangs
# rlfi turns raise off, which breaks Emacs REDUCE, and reads EOF ad infinitum.

# packages2='odesolve pf cvit physop crack liepde applysym conlaw excalc gentran fide numeric randpoly reacteqn roots rlfi sets xideal eds groebner ideals linalg ncpoly normform orthovec laplace pm qsum scope sparse spde specfn'

packages2='odesolve pf cvit physop excalc gentran fide numeric randpoly reacteqn roots sets xideal eds groebner ideals linalg ncpoly normform orthovec laplace pm qsum scope sparse spde specfn'

packages3='tps limits defint fps trigint ratint mathml mathmlom redlog cgb sum zeilberg symmetry taylor mrvlimit residue susy2 tri trigsimp xcolor wu ztrans geoprover rataprx'

packages="$packages1 $packages2 $packages3"

# echo $packages
