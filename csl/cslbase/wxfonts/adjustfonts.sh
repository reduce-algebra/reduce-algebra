# !/bin/sh

# Arrange that glyphs present at non-Unicode addresses have copied that are
# at valid Unicode codepoints in a private use area.
# Also ensure that there are ".ttf" as well as ".otf" versions so that
# Windows is kept happy, and collect some metrics in the "metrics"
# directory.

# When I am running on my own Windows machine I have fontforge installed
# in the location shown below. On Linux (etc) I want it to be found in
# the standard way. If your system is set up differently you will need
# to edit this!

case "x$1"
in
*keep*)
  keeptemp="yes"
  ;;
*)
  keeptemp="no"
  ;;
esac

if which fontforge > /dev/null 2> /dev/null
then
  ff=fontforge
else
  ff="/c/Program Files (x86)/FontForgeBuilds/run_fontforge.exe"
fi
printf "Using %s for fontforge\n" "$ff"

# Now run the main adjustments.

"$ff" -script adjustfonts.script
"$ff" -script toafm.script cmuntt.otf
"$ff" -script toafm.script odokai.ttf

# At least on Windows I seem to find that fontforge leaves some
# files open when I had hoped it had quit. This may be purely a timing
# issue, so I sleep for a bit here...

sleep 10

chmod a+rx *.ttf
rm *.ps

# The .afm files made by fontforge seem not to give a codepoint to
# things beyond the basic multilingual plane. Beyond that the character
# metric information often reads something like
#    C -1 ; W xxx ; N uyyyyy ; B ...
# where xxx is the character width/advance and yyyyy may be the codepoint.
# If the character had an alternative Unicode name properly recorded for
# it that will appear in place of uyyyyy (or uyyyyyy). My utility fixafm
# will detect lines that start "C -1 ;" and if "uyyyyy" is found will replace
# the -1 with the decimal value of yyyyy, otherwise it will delete the
# line. The program I use to do this is not robust, but it should only need
# to be run once!

# For the STIXMath font I need to extract some maths tables. I will
# arrange that fixafm merges the information into the .afm file in this
# case.

gcc showttf.c -o showttf
./showttf STIXMath-Regular.otf > STIXMath.tables

gcc fixafm.c -o fixafm

for x in *.afm
do
  ./fixafm $x metrics/$x
done

if test "$keeptemp" = "no"
then
  rm fixafm showttf *.afm STIXMath.tables
fi

printf "Conversion complete\n"
