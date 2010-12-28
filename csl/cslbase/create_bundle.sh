#! /bin/bash

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
mkdir -p $1.app/Contents/Resources
mkdir -p $1.app/Contents/Resources/Fonts
F="$1.app/Contents/Resources/Fonts"
cp $srcdir/wxfonts/README                        $F/README.BaKoMa
cp $srcdir/wxfonts/BaKoMa-AMS.Fonts              $F
cp $srcdir/wxfonts/BaKoMa-CM.Fonts               $F
cp $srcdir/wxfonts/README.news                   $F/README.news.BaKoMa
cp $srcdir/wxfonts/LICENCE                       $F/LICENCE.BaKoMa
cp $srcdir/wxfonts/*.ttf                         $F
cp $srcdir/cm-unicode/LICENSE                    $F/LICENSE.cm-unicode
cp $srcdir/cm-unicode/README                     $F/README.cm-unicode
cp $srcdir/cm-unicode/cmunrm.otf                 $F
cp $srcdir/cm-unicode/cmunti.otf                 $F
cp $srcdir/cm-unicode/cmuntt.otf                 $F
# I will also use fireflysung and sazanami fonts to cover the CJK range
cp $srcdir/fireflysung-1.3.0/fireflysung.ttf     $F
cp $srcdir/fireflysung-1.3.0/AUTHORS             $F/AUTHORS.fireflysung
cp $srcdir/fireflysung-1.3.0/COPYRIGHT           $F/COPYRIGHT.fireflysung
cp -r $srcdir/fireflysung-1.3.0/license          $F/license.fireflysung
cp $srcdir/sazanami-20040629/README              $F/README.sazanami
cp $srcdir/sazanami-20040629/sazanami-gothic.ttf $F
cp $srcdir/sazanami-20040629/sazanami-mincho.ttf $F
cp -r $srcdir/sazanami-20040629/doc              $F/doc.sazanamix
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
echo "<string>$1 version 1, (C) 2010 Codemist Ltd</string>" >> $P
echo "<key>CFBundleLongVersionString</key>" >> $P
echo "<string>1, (C) 2010 Codemist Ltd</string>" >> $P
echo "<key>NSHumanReadableCopyright</key>" >> $P
echo "<string>Copyright 2010 Codemist Ltd</string>" >> $P
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
# Application frawework set up!
