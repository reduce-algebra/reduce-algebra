# !/bin/sh

# Create .ttf versions of all the STIX fonts...

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

for i in STIX*.otf
do
  "$ff" -script tottf.script $i
done

chmod a_rx *.ttf

printf "Conversion complete\n"
