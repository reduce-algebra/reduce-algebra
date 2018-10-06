#!/usr/bin/bash

# Build a core Emacs REDUCE system.  This can then be used to build
# the rest of REDUCE, i.e. the remaining packages.

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.

# Create log & fasl directories if necessary:
if [ ! -d log ]; then mkdir log; fi
if [ ! -d fasl ]; then mkdir fasl; fi

# Run Emacs REDUCE in batch mode:
# Need either full file name for --load (e.g. build.el) or --directory=.
# /cygdrive/d/emacs/emacs/bin/
emacs \
	--batch \
	--directory=. \
	--eval='(setq debug-on-error t)' \
	--load=build \
	<< EOF
(DSKIN "dbuild.el")
symbolic infile "eslremakecore.red";
bye;
EOF
