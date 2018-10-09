#!/usr/bin/bash

# Check one Emacs REDUCE test file against the exemplary log.

# Author: Francis J. Wright
# Based (loosely) on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.

exelog=`find -L packages -name $1.rlg`

echo $'\nChecking' $1 $'...\n'

diff --strip-trailing-cr log/$1.rlg $exelog
