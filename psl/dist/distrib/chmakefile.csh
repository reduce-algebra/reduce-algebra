#!/bin/csh -f
# Script to update a Makefile.
# Usage: chmakefile.csh <Makefile path>
#
# ex: chmakefile.csh $psl/Makefile

source ~psl/dist/psl-names

$pdist/chmakehost.csh $1

# End of File.
