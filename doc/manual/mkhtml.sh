#!/bin/sh

# Requires the following texlive packages:
# as for the PDF version, plus
# plain generic

cd `dirname $0`

JOBNAME=manual

CONFIG=reduce

SECTIONINGDEPTH=3

# RMS 2020-06-10: The following needed on MacOS, otherwise gsftopk doesn't work.
GS_OPTIONS=-DNOSAFER ; export GS_OPTIONS

test "$1" = "for-sf" && CONFIG=reduce-sf

# Write current svn revision number to "revision.tex":
echo $(../../scripts/revision.sh) > revision.tex

# FJW 2020-12-28 Delete previously generated HTML and PNG files:
rm -f ${JOBNAME}*.{html,png}

# Remove .ind file, could be left over from latex run
rm -f ${JOBNAME}.ind

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

tex '\def\filename{{'${JOBNAME}'}{idx}{4dx}{ind}} \input idxmake.4ht'

# finally, run makeindex and latex once
sed -e 's/^\(\\indexentry{[^@]*\)\\textbar/\1"|/' \
    -e 's/^\(\\indexentry{[^@]*\)\\underscore/\1_/' \
    -e 's/^\(\\indexentry{[^@]*\)\\char `\\\\/\1\\\\/' \
    -e 's/^\(\\indexentry{"\\\^ operator@\\texttt {\)"\\\^/\1\\textasciicircum/' \
  <manual.4dx >manual.4dxtmp ; mv manual.4dxtmp manual.4dx

makeindex -s ${JOBNAME}.ist -o ${JOBNAME}.ind ${JOBNAME}.4dx

bibtex ${JOBNAME}

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

# index.html is used locally by the CSL REDUCE GUI, so...
if [ ! "$1" = 'for-sf' ]; then cp ${JOBNAME}.html index.html; fi

rm revision.tex

exit 0
