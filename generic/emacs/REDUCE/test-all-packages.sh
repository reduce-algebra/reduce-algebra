#!/usr/bin/bash

# Run all Emacs REDUCE test files.

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.

# Create log directory if necessary:
if [ ! -d log ]; then mkdir log; fi

hostname > log/testall.log
date >> log/testall.log

. test-package-list.sh

for x in $packages; do echo $x >> log/testall.log; ./test-one-package.sh $x; done

date >> log/testall.log

echo 'Errors:'
cd log
grep '\*\*\*\*\*\|error[^.]' *.rlg
cd ..
