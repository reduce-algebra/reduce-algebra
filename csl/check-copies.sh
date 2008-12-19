#! /bin/sh -v

# Some files are in both the cslbase and fox directories. This is because
# the FOX extensions I have made rely on them to make it a complete library,
# but the code can also be used in non-GUI mode and without any of FOX
# to provide a better command-line interface than I would otherwise have.
# To keep the BSD-licensed version visibly unencumbered I keep it in
# the CSL base directory.

# This scripts compares the two versions to help me ensure that they remain
# in track. I do not use (eg) symbolic links because I want a distribution
# of either the cslbase files or the fox files to be utterly self-contained.

diff -w cslbase/termed.h fox/include
diff -w cslbase/fwin.h   fox/include
diff -w cslbase/termed.c fox/src
diff -w cslbase/fwin.c   fox/src

# end of comparisons
