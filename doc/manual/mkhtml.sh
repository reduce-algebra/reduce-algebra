#!/bin/sh

JOBNAME=manual

CONFIG=reduce

SECTIONINGDEPTH=3
test "$1" = "for-sf" && CONFIG=reduce-sf

# Remove .ind file, could be left over from latex run
rm -f ${JOBNAME}.ind

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

tex '\def\filename{{'${JOBNAME}'}{idx}{4dx}{ind}} \input idxmake.4ht'

# finally, run makeindex and latex once
makeindex -o ${JOBNAME}.ind ${JOBNAME}.4dx

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

cp ${JOBNAME}.html index.html

exit 0

