# !/bin/sh

# Arrange that glyphs present at non-Unicode addresses have copied that are
# at valid Unicode codepoints in a private use area.
# Also ensure that there are ".ttf" as well as ".otf" versions so that
# Windows is kept happy, and collect some metrics in the "metrics"
# directory.

# When I am running on my own Windows machine I have fontforge installed
# in the location shown below. On Linux (etc) I want it to be found in
# the standard way.
if which fontforge > /dev/null
then
  ff=fontforge
else
  ff="/c/Program Files (x86)/FontForgeBuilds/fontforge.bat"
fi
printf "Using %s for fontforge\n" $ff

"$ff" -script adjustfont.script

"$ff" -script toafm.script cmuntt.otf
"$ff" -script toafm.script fireflysung.ttf

chmod a+rx *.ttf
rm *.ps
mv *.afm metrics

gcc showttf.c -o showttf
for x in cmuntt cslSTIX-Regular cslSTIX-Bold cslSTIX-Italic \
                cslSTIX-BoldItalic cslSTIXMath-Regular
do
  ./showttf $x.otf > metrics/$x.tables
done
./showttf fireflysung.ttf > metrics/fireflysung.tables

printf "Conversion complete\n"
