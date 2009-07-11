#! /bin/sh

# This sets up a copy of the FOX sources ready to be hand edited, such that
# the edits can then be returned as a patch against the master copy.

. ./fox-1.6-version.sh

PAT=`pwd | sed -e 's+/[^/]*$++'`
PAT=${PAT}/fox-patches

# Create a directory within which original and patches trees will live
if test -d ${PAT}
then :
else
   mkdir ${PAT}
fi

# Copy into it some useful scripts
cp mkdiffs-1.6.sh         ${PAT}
cp installpatches-1.6.sh  ${PAT}
cp fox-1.6-version.sh     ${PAT}
chmod +x ${PAT}/*.sh

# Now select that directory as current and unpack two fresh copies of
# the FOX sources

# I remove a loadd of that autoconf-generated files from the
# unpacked archive so that my patches can re-instate them.

here=`pwd`
cd ${PAT}
tar xfz $here/fox-1.6.${FOXVER}.tar.gz
rm fox-1.6.${FOXVER}/aclocal.m4
rm fox-1.6.${FOXVER}/configure
find fox-1.6.${FOXVER} -name Makefile.in -print | xargs rm
mv fox-1.6.${FOXVER} fox-1.6.${FOXVER}-new
tar xfz $here/fox-1.6.${FOXVER}.tar.gz
rm fox-1.6.${FOXVER}/aclocal.m4
rm fox-1.6.${FOXVER}/configure
find fox-1.6.${FOXVER} -name Makefile.in -print | xargs rm

# Apply current patch-set to one copy

cd fox-1.6.${FOXVER}-new
# You will see in the main build script that I use gpatch if that is
# present. Here (in this MAINTAINER script) I assume that the system-wide
# patch command is the GNU version.

gunzip -c $here/fox-1.6.patches.gz | patch -Nlp1

# Ensure that the script that remakes autconfig stuff is executable

chmod +x autogen.sh

cd ..

echo "You may now edit files in fox-1.6.${FOXVER}-new. When you are"
echo "done you can run ./mkdiffs-1.6.sh to create a set of differences."
echo "When that is ready, run ./installpatches-1.6.sh to copy it back."

