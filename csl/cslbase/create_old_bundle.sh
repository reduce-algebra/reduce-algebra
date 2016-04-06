#! /bin/bash

# Usage:
#   $srcdir/create_old_bundle.sh name srcdir ?icon
#
# Sets up name.app with a proper Info.plist etc for use with MacOSX.
# This copies in an icon, and arg2 (if present) specifies its identity
# as an .icns file in $srcdir
#
# This is for the older FOX-based version of Reduce
#

echo TRACE: create_old_bundle.sh $*

P=$1.app/Contents/Info.plist
srcdir=$2
IC=${3:-fwin}

SetFile -t APPL $1
mkdir -p $1.app/Contents
mkdir -p $1.app/Contents/MacOS
mkdir -p $1.app/Contents/MacOS/reduce.fonts
mkdir -p $1.app/Contents/Resources
F="$1.app/Contents/MacOS/reduce.fonts"
# Copy everything from my source tree. This makes sense if the tree is
# clean and does not contain any local extras!
cp -r $srcdir/fonts/*READ*                            $F
cp -r $srcdir/fonts/*.pfb                             $F
#cp -r $srcdir/fonts/*.ttf                             $F
mkdir -p $1.app/Contents/Resources/reduce.resources
AA="$1.app/Contents/Resources/reduce.resources"
cp $srcdir/../../packages/redlog/mma/mma.awk          $AA
cp $srcdir/../../packages/redlog/qepcad/qepcad.awk    $AA
echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > $P
echo "<!DOCTYPE plist SYSTEM \"file://localhost/System/Library/DTDs/PropertyList.dtd\">" >> $P
echo "<plist version=\"0.9\">" >> $P
echo "<dict>" >> $P
echo "<key>CFBundleInfoDictionaryVersion</key>" >> $P
echo "<string>6.0</string>" >> $P
echo "<key>CFBundleIdentifier</key>" >> $P
echo "<string>com.codemist.reduce.$1</string>" >> $P
echo "<key>CFBundleDevelopmentRegion</key>" >> $P
echo "<string>English</string>" >> $P
echo "<key>CFBundleLocalizations</key>" >> $P
echo "<array> <string>en</string> </array>" >> $P
echo "<key>CFBundleExecutable</key>" >> $P
echo "<string>$1</string>" >> $P
echo "<key>CFBundleIconFile</key>" >> $P
echo "<string>$IC.icns</string>" >> $P
echo "<key>CFBundleName</key>" >> $P
echo "<string>$1</string>" >> $P
echo "<key>CFBundlePackageType</key>" >> $P
echo "<string>APPDVI</string>" >> $P
echo "<key>CFBundleSignature</key>" >> $P
echo "<string>????</string>" >> $P
echo "<key>CFBundleVersion</key>" >> $P
echo "<string>1</string>" >> $P
echo "<key>CFBundleShortVersionString</key>" >> $P
echo "<string>1</string>" >> $P
echo "<key>CFBundleGetInfoString</key>" >> $P
echo "<string>$1 version 1, (C) 2016 Codemist</string>" >> $P
echo "<key>CFBundleLongVersionString</key>" >> $P
echo "<string>1, (C) 2016 Codemist</string>" >> $P
echo "<key>NSHumanReadableCopyright</key>" >> $P
echo "<string>Copyright 2016 Codemist</string>" >> $P
echo "<key>LSRequiresCarbon</key>" >> $P
echo "<true/>" >> $P
echo "<key>CSResourcesFileMapped</key>" >> $P
echo "<true/>" >> $P
echo "<key>ATSApplicationFontsPath</key>" >> $P
echo "<string>Fonts</string>" >> $P
echo "</dict>" >> $P
echo "</plist>" >> $P
echo -n "APPL????" >$1.app/Contents/PkgInfo
ln -f $1 $1.app/Contents/MacOS/$1
cp -f $srcdir/$IC.icns $1.app/Contents/Resources/$IC.icns
# Application framework set up!
