#!/bin/csh -f
# Script to change the PROOT variable in a specified Makefile
# Usage: chmakehost.csh <Makefile path>
#
# ex: chmakehost.csh $psl/Makefile

set file = $1

set proot   = `echo $proot`

echo "Changing PROOT for $file"

sed -e "s,\(PROOT.*=\) .*,\1 $proot,g" $file > $file.munge

mv -f $file.munge $file

# End of File.
