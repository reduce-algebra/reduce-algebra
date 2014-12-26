# !/bin/sh

# Create .afm file of all my fonts,

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

for i in STIX*.otf cmuntt.otf fireflysung.ttf
do
  "$ff" -script toafm.script $i
done

# I do not really want the ".ps" files - just the .afm ones
rm *.ps
mv *.afm tfm

printf "Conversion complete\n"
