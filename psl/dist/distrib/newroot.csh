#!/bin/csh -f
#
# Script to change proot in psl-names and all the makefiles, including the
#  PCLS top level makefile, if it exists.
#
#
set newroot = $1

sed -e "s,\(setenv.*proot\) .*,\1 $newroot," $newroot/dist/psl-names > newnames
mv -f newnames $newroot/dist/psl-names

setenv MACHINE $2
source $newroot/dist/psl-names

set makefiles = ($pc/Makefile $pxc/Makefile $pnk/Makefile $pxnk/Makefile \
                 $pxk/Makefile $pu/Makefile $pxu/Makefile $psl/Makefile  \
		 $proot/pclsdist/Makefile)

foreach file ($makefiles)
    if ( -e $file ) then
	$pdist/chmakehost.csh $file
    endif
end

# End of File.
