#!/bin/sh

JOBNAME=manual-pdf

MAXRUNS=10
SUCCESS=0
RUNS=0

# Remove .ind file, could be left over from tex4ht run
rm -f ${JOBNAME}.ind

# Run latex until it no longer complains about cross references
until [ ${SUCCESS} = 1 ] ; do
   pdflatex ${JOBNAME}
   fgrep -q "Rerun to get cross-references right." ${JOBNAME}.log || SUCCESS=1
   RUNS=`expr ${RUNS} + 1`
   if [ ${RUNS} -gt ${MAXRUNS} ] ; then
      echo >&2 Maximum number of runs reached. Stop.
      exit 1
   fi
#   checksum ${JOBNAME}.aux
done

# finally, run makeindex and latex once
makeindex ${JOBNAME}
pdflatex ${JOBNAME}

exit 0

