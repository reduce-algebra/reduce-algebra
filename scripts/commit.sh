#! /bin/sh
svn status > /tmp/svnstatus
grep ^A < /tmp/svnstatus  > /tmp/svndiffs
grep ^D < /tmp/svnstatus >> /tmp/svndiffs
grep ^M < /tmp/svnstatus >> /tmp/svndiffs
cut -b 9- < /tmp/svndiffs > /tmp/svnfiles
gen="aclocal.m4 compile config.guess config.sub configure depcomp Makefile.in \
install-sh ltmain.sh missing test-driver config.h.in mdate-sh mkinstalldirs \
py-compile texinfo.tex ylwrap ar-lib"
for x in $gen
do
# printf "Getting rid of %s\n" "$x"
  grep -v ^$x\$\\\|/$x\$ < /tmp/svnfiles > /tmp/work
  mv /tmp/work /tmp/svnfiles
done
printf "Please check in the following files:\n"
cat /tmp/svnfiles

# The next line is doe snot work because svn needs a log message but when run
# froim a script it feels it can not open an editor to let you make one.
# cat /tmp/svnfiles | xargs svn ci

tmp="svn ci"
for x in `cat /tmp/svnfiles`
do
  tmp="$tmp $x"
done
echo $tmp
$tmp

