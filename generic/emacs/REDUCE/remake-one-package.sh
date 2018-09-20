#!/usr/bin/bash
# -*- coding: utf-8; -*-

# Compile one Emacs REDUCE package (older than its source file).

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.
# This script is normally run by remake-all-packages.sh.

# Create log & fasl directories if necessary:
if [ ! -d log ]; then mkdir log; fi
if [ ! -d fasl ]; then mkdir fasl; fi

# Run Emacs REDUCE in batch mode:
# Need either full file name for --load (e.g. reduce.el) or --directory=.

# NB: Currently end-of-line is ignored when the REDUCE code in the
# here document below is read, so the leading spaces are essential
# and % comments may not work correctly!
/cygdrive/d/emacs/emacs/bin/emacs \
	--eval='(setq debug-on-error t)' \
	--batch \
	--directory=. \
	--load=reduce \
	>& log/$1.blg << EOF
symbolic;

if '$1 eq 'fps
 then load_package limits,factor,specfn,sfgamma
 else if '$1 eq 'mrvlimit then load_package taylor
 else if '$1 eq 'conlaw then !¦max!-specpdl!-size := 2000;

Comment: The default Emacs Lisp variable binding depth of 1300 is too
small for conlaw, but 2000 seems to work.;

load!-package 'eslremake;

!*argnochk := t;

infile "package.red"\$

package!-remake '$1;

bye;
EOF
