#!/bin/sh

JOBNAME=$1

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
# If I go "exit 1" that tends to disrupt higher level scripts, so even though
# looping here is bad I will exit cleanly. The consequence could be that some
# cross-references will end up incorrect.
#     exit 1
      exit 0
   fi
#   checksum ${JOBNAME}.aux
done

# finally, run makeindex and latex once
if test -f ${JOBNAME}.idx ; then
  makeindex ${JOBNAME}
  pdflatex ${JOBNAME}
fi

exit 0

