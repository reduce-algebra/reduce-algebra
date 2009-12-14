#!/bin/csh -x
# Get rid of all those gnu backups, log files, and other junk.

pushd $proot

find bin dist pclsdist -type f \( -name '#*' -o -name '.#*' -o -name '.~*' \
-o -name '*.log' -o -name '*.aux' -o -name '*.blat' -o -name log \) \
-print -exec rm -f {} \;

popd

# End of file.
