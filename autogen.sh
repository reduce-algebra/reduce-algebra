#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# when the machine being used does not have the same versions of autoconf
# and automake as the machine used by the developer.

#
# Usage:
#     autogen.sh [options as for the configure script]
#
# If no arguments are passed the script will rebuild everything. If
# --with-csl or --with-psl is specified only that section of the tree
# will be processed. In the CSL case "--with-wx", "--withoug-gui",
# "--with-boehm" and perhaps other sub-options will be checked to try
# to save reworking directories that would not be used.
#

# I want this script to be one I can launch from anywhere.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

save=`pwd`
cd $here

if ! which autoconf > /dev/null || \
   ! which automake > /dev/null || \
   ! which libtool > /dev/null
then
  printf "You need to have autoconf, automake and libtool installed.\n"
  printf "I seem not to be able to find them.\n"
  printf "Stopping...\n"
  exit 1
fi

# Here I list all the directories that might be relevant. Note that in
# some circumstances some may not be present!

# There are some directories that I have chosen not to process here:
#  ./csl/foxtests
#  ./generic/libreduce/src
#  ./generic/redfront/libedit-20140620-3.1
#  ./generic/redfront/src
# taking a view that people who wish to build those already have to take
# special steps... and so they can run autoconf etc for themselves if it
# is needed. If I did so here it would slow things down for everybody in
# a way I would view as unhelpful.

printf "autogen.sh arguments: $*\n"

if test $# -eq 0
then
  a="--with-psl --with-csl --with-fox --with-boehm"
else
  a="$*"
fi

# Here are the directories that I will always process...

L=". ./scripts libraries/crlibm"

case $a in
*--without-psl* | *with-psl=no*)
  ;;
*--with-psl*)
  L="$L ./psl"
  ;;
*)
  ;;
esac

# I want "--with-wx" to imply "--without-fox". At present I do not
# feel the need for the converse because this script does not try to
# autoreconf wxWidgets anyway.
case $a in
*--with-wx=no* | "--without-wx*")
  ;;
*--with-wx*)
  a="$a --without-fox"
  ;;
*)
  ;;
esac

case $a in
*--without-csl* | *with-csl=no*)
  ;;
*--with-csl*)
  L="$L ./csl ./csl/cslbase ./csl/cslbase/crlibm"
  case $a in
  *--without-fox* | *with-fox=no* | \
  *--without-gui* | *with-gui=no*)
    ;;
  *)
    L="$L ./csl/fox"
    ;;
  esac
  case $a in
  *--without-boehm* | *with-boehm=no*)
    ;;
  *--with-boehm*)
    L="$L ./csl/cslbase/gc-7"
    ;;
  *)
    ;;
  esac
  ;;
*)
  ;;
esac

printf "About to process $L\n"

for d in $L
do
  printf "\nautoreconf in directory '%s'\n" $d
  if test -d $d
  then
    cd $d
    printf "autoreconf -f -i -v\n"
    autoreconf -f -i -v
    cd $here
  fi
done
   
scripts/resetall.sh

cd $save
exit 0

# end of autogen.sh
