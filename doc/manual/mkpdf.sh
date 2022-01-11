#!/bin/sh

cd `dirname $0`

JOBNAME=manual

MAXRUNS=6
SUCCESS=0
RUNS=0
NEED_BIBTEX=0

# Remove .ind file and .aux files that could be left over from a
# TeX4ht build and may cause obscure complaints from a PDF build, but
# add an new skeleton .ind file to get a correct Index entry in the
# PDF Table of Contents:
rm -f *.aux
cat > ${JOBNAME}.ind <<EOF
\begin{theindex}
\end{theindex}
EOF

# Run latex until it no longer complains about cross references
until [ ${SUCCESS} = 1 ] ; do
   rm -f ${JOBNAME}.log
   pdflatex ${JOBNAME}
   grep -q "^No file ${JOBNAME}\.bbl" ${JOBNAME}.log && NEED_BIBTEX=1
   grep -q '\\bibdata' ${JOBNAME}.aux && NEED_BIBTEX=1
   if [ "${NEED_BIBTEX}" = 1 ] ; then
      bibtex ${JOBNAME}
      rm -f ${JOBNAME}.log
      pdflatex ${JOBNAME}
   fi
   fgrep -q "Rerun to get cross-references right." ${JOBNAME}.log || SUCCESS=1
   RUNS=`expr ${RUNS} + 1`
   if [ ${RUNS} -gt ${MAXRUNS} ] ; then
      echo >&2 Maximum number of runs reached. Stop.
# The code here USED to go "exit 1" but that stopped higher level scripts.
# I will now merely pretend that I had achieved convergence. The result may
# be that some cross-references end up incorrect in the generated file.
#     exit 1
      SUCCESS=1
   fi
#   checksum ${JOBNAME}.aux
done

if test -f ${JOBNAME}.idx ; then
  # finally, run makeindex and latex once
  # replace symbolic representation of | _ \ by the characters themselves,
  # for correct sorting
  sed -e 's/^\(\\indexentry{[^@]*\)\\textbar/\1"|/' \
      -e 's/^\(\\indexentry{[^@]*\)\\underscore/\1_/' \
      -e 's/^\(\\indexentry{[^@]*\)\\char `\\\\/\1\\\\/' \
    <manual.idx >manual.idxtmp ; mv manual.idxtmp manual.idx

  makeindex -s ${JOBNAME}.ist ${JOBNAME}
  pdflatex ${JOBNAME}
fi

echo 'RUNS =' $RUNS

exit 0
