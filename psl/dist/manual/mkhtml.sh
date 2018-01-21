#!/bin/sh

JOBNAME=$1
shift

CONFIG=manual

SECTIONINGDEPTH=3

# Remove .ind file, could be left over from latex run
rm -f ${JOBNAME}.ind

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

tex '\def\filename{{'${JOBNAME}'}{idx}{4dx}{ind}} \input idxmake.4ht'

# finally, run makeindex and latex once
test -e ${JOBNAME}.idx || touch ${JOBNAME}.idx

makeindex -o ${JOBNAME}.ind ${JOBNAME}.4dx

mk4ht htlatex ${JOBNAME} ${CONFIG},${SECTIONINGDEPTH}

#cp ${JOBNAME}.html index.html

exit 0

