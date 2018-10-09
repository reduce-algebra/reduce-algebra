#!/usr/bin/bash

# Check all Emacs REDUCE test files against exemplary logs.

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.

rm -f log/checkall.log

. test-package-list.sh

for x in $packages; do ./check-one-test.sh $x >> log/checkall.log; done
