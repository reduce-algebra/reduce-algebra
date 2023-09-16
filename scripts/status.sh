#! /bin/sh
# This lists all files in the subversion tree that have been changed
# locally. I find it useful when I have been making a load up local
# updates and wish to be reminded where they all are.
# The "--full" or "-f" flag asks for full info - by defaul what you see
# is what scripts/commit.sh would check in.

case ${1:-nothing} in
-f | --full)
  svn status | grep -v ^?
  ;;
*)
  svn status | grep -v ^? > ${TEMP:-/tmp}/work
  cut -b 9- < ${TEMP:-/tmp}/work > ${TEMP:-/tmp}/svnfiles
  gen="aclocal.m4 compile config.guess config.sub configure depcomp Makefile.in \
  install-sh ltmain.sh missing test-driver config.h.in mdate-sh mkinstalldirs \
  py-compile texinfo.tex ylwrap ar-lib libtool.m4 ltoptions.m4 \
  ltsugar.m4 ltversion.m4 lt~obsolete.m4 crlibm_config.h.in"
  for x in $gen
  do
#   printf "Getting rid of %s\n" "$x"
    grep -v "/$x\$" < ${TEMP:-/tmp}/svnfiles | \
      grep -v "^$x\$" > ${TEMP:-/tmp}/work
    mv ${TEMP:-/tmp}/work ${TEMP:-/tmp}/svnfiles
  done
  printf "Added or modified files:\n"
  cat ${TEMP:-/tmp}/svnfiles
###  rm -f ${TEMP:-/tmp}/work /tmp/svnfiles
  ;;
esac
