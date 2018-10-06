#!/usr/bin/bash

# Run one Emacs REDUCE test file.

# Author: Francis J. Wright
# Based on code by Anthony C. Hearn.

# Assume this script is run in the top-level Emacs REDUCE directory.
# This script is normally run by test-all-packages.sh.

# Create log directory if necessary:
if [ ! -d log ]; then mkdir log; fi

# Run Emacs REDUCE in batch mode:
# Need either full file name for --load (e.g. reduce.el) or --directory=.
# /cygdrive/d/emacs/emacs/bin/
emacs \
	--batch \
	--directory=. \
	--load=reduce \
	&> log/$1.rlg << EOF
on errcont;   % So that computation continues after an error.

symbolic <<linelength 80; share pkg; pkg := '$1;
	   load!-package pkg; in "package.red";
	   if get(pkg,'folder) then pkg := get(pkg,'folder);
	   pkg := string!-downcase pkg;
	   pkg := concat("packages/", pkg, "/", "$1", ".tst");
	   !*_xxx_!* := time(); !*_yyy_!* := gctime(); nil>>$

in pkg;

% The +- construct in the following is required to finesse Orthovec's
% renaming of -.

symbolic <<terpri(); terpri(); prin2 "Time for test: ";
	   prin2 (time()+-!*_xxx_!*); prin2 " ms";
	   if (!*_yyy_!* := gctime()+-!*_yyy_!*)>0
	     then <<prin2 ", plus GC time: "; prin2 !*_yyy_!*;
		    prin2 " ms"; terpri()>>>>$

bye;
EOF
