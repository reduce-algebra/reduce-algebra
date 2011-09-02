#! /bin/bash

arch=$1
echo $arch
shift
echo $*
dest=${r38_archive:-acn1@codemist.dyndns.org:/d/r38}
echo "Save executables to $dest [use r38_archive to override]"

ssh ${dest%%:*} mkdir -p ${dest#*:}/objects/$arch
ssh ${dest%%:*} mkdir -p ${dest#*:}/exe/$arch
ssh ${dest%%:*} mkdir -p ${dest#*:}/images/$arch

echo About to copy objs.tar.gz
scp objs.tar.gz $dest/objects/$arch

for f in $*
do
  echo About to copy $f
  scp $f $dest/exe/$arch/$f
done

echo About to copy r38.img
scp r38.img $dest/images/$arch/r38.img
case $arch in
*demo)
  ;;
*)
  echo ABout to copy csl.img
  scp csl.img $dest/images/$arch/r38.img
  ;;
esac

echo Files copies to master site

exit

# NB you can set a shell variable r38_archive to give the location
# where files should be saved. It will need to have subdirectories
# exe, images and objects ready in it, and is given in a form like
#    acn1@codemist.dyndns.org:/d/r38
# (that is the default location used)

which=`pwd`
echo $which
which=${which##*/}
echo $which
which=${which#local-}
echo $which
which=${which#demo-}

echo which=$which

case $which in

# I save everything if I am on win32 or linux64. In particular these are the
# p[latforms on which I build and save image files and where I dare to save
# ready-built executables.
win32 | suse-64)
    echo save for win32 or linux64
    ../util/save-exe.sh
    ../util/save-image.sh
    ../util/save-objs.sh
    ;;

# On a Macintosh I will save a ready-linked executable in the hope that it is
# a single platform so there is hope that that will make sense. Actually I
# am certain it will not in that Intel and ppc-mac platforms will not agree -
# unless I arrange to create fat binaries.  At present I support just ppc-mac.
mac-darwin | win64)
    echo save for mac-darwin ow win64
    ../util/save-exe.sh
    ../util/save-objs.sh
    ;;

# In all other cases (mostly just loads of variants on Linux and Unix) I will
# save object files (only) since those are needed because of the LGPL.
*)
    echo "save in generic case (${which})"
    ../util/save-objs.sh
    ;;

esac


