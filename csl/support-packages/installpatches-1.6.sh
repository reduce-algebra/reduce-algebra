#! /bin/sh
# After "mkdiff-1.6.sh" has been called when you are making a set of FOX
# patches, this installs them. See setup-patching-1.6.sh for explanation.
SUP=`pwd | sed -e 's+/[^/]*$++'`
SUP=${SUP}/support-packages/fox-1.6.patches
sed -e "s/-x 'autom\*'//" fox-1.6.patches > ${SUP}
gzip -f ${SUP}

