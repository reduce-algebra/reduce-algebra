#! /usr/bin/env bash

# Usage:
#   $srcdir/create_bundle.sh name srcdir ?icon
#
# Sets up name.app with a proper Info.plist etc for use with MacOSX.
# This copies in an icon, and arg2 (if present) specifies its identity
# as an .icns file in $srcdir

echo TRACE: create_bundle.sh $*

P=$1.app/Contents/Info.plist
srcdir=$2
IC=${3:-fwin}

SetFile -t APPL $1
mkdir -p $1.app/Contents
mkdir -p $1.app/Contents/MacOS
mkdir -p $1.app/Contents/MacOS/reduce.doc
mkdir -p $1.app/Contents/Resources
mkdir -p $1.app/Contents/Resources/Fonts
D="$1.app/Contents/MacOS/reduce.doc"
cp $srcdir/../reduce.doc/*.txt                   $D
cp $srcdir/../reduce.doc/*.tex                   $D
cp $srcdir/../reduce.doc/*.html                  $D
F="$1.app/Contents/Resources/Fonts"
cp $srcdir/wxfonts/STIX*.pdf                     $F
cp $srcdir/wxfonts/*.ttf                         $F
cp $srcdir/cm-unicode/LICENSE                    $F/LICENSE.cm-unicode
cp $srcdir/cm-unicode/README                     $F/README.cm-unicode
cp $srcdir/cm-unicode/cmuntt.otf                 $F
# The DejaVu Sans Mono font covers a range of characters that CMTT does not..
cp $srcdir/dejavu-fonts-ttf-2.32/LICENSE          $F/LICENSE.dejavu-fonts-ttf-2.32
cp $srcdir/dejavu-fonts-ttf-2.32/README           $F/README.dejavu-fonts-ttf-2.32
cp $srcdir/dejavu-fonts-ttf-2.32/AUTHORS          $F/AUTHORS.dejavu-fonts-ttf-2.32
cp $srcdir/dejavu-fonts-ttf-2.32/ttf/DejaVuSansMono.ttf $F
# I will use fireflysung fonts to cover the CJK range. I hope that at some
# time I may be able to move to use of SourceHanSans/Noto... but that time
# has not yet come.
cp $srcdir/fireflysung-1.3.0/fireflysung.ttf      $F
cp $srcdir/fireflysung-1.3.0/AUTHORS              $F/AUTHORS.fireflysung
cp $srcdir/fireflysung-1.3.0/COPYRIGHT            $F/COPYRIGHT.fireflysung
mkdir -p $F/license.fireflysung
mkdir -p $F/license.fireflysung/big5
mkdir -p $F/license.fireflysung/english
mkdir -p $F/license.fireflysung/gb
cp $srcdir/fireflysung-1.3.0/license/big5/ARPHICPL.TXT    $F/license.fireflysung/big5
cp $srcdir/fireflysung-1.3.0/license/english/ARPHICPL.TXT $F/license.fireflysung/english
cp $srcdir/fireflysung-1.3.0/license/gb/ARPHICPL.TXT      $F/license.fireflysung/gb
mkdir -p $1.app/Contents/Resources/reduce.resources
AA="$1.app/Contents/Resources/reduce.resources"
cp $srcdir/../../packages/redlog/ofsf/mma.awk          $AA
cp $srcdir/../../packages/redlog/ofsf/qepcad.awk    $AA
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
