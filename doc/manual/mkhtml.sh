#!/bin/sh

cd `dirname $0`

JOBNAME=manual

CONFIG=reduce

SECTIONINGDEPTH=3

test "$1" = "for-sf" && CONFIG=reduce-sf

# Remove .ind file, could be left over from latex run
rm -f ${JOBNAME}.ind

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

tex '\def\filename{{'${JOBNAME}'}{idx}{4dx}{ind}} \input idxmake.4ht'

# finally, run makeindex and latex once
sed -e 's/^\(\\indexentry{[^@]*\)\\textbar/\1"|/' \
    -e 's/^\(\\indexentry{[^@]*\)\\underscore/\1_/' \
    -e 's/^\(\\indexentry{[^@]*\)\\char `\\\\/\1\\\\/' \
  <manual.4dx >manual.4dxtmp ; mv manual.4dxtmp manual.4dx

makeindex -o ${JOBNAME}.ind ${JOBNAME}.4dx

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

sed -e 's#https://reduce-_algebra\.sourceforge\.io/#https://reduce-algebra.sourceforge.io/#' ${JOBNAME}.html >index.html
cp index.html ${JOBNAME}.html

exit 0

