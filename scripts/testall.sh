#! /bin/sh

# Test all package

# Usage:
#   scripts/testall.sh [--noregressions]
#                      [--csl] [--cslboot] [--installed-csl]
#                      [--csl-XXX] [--cslboot-XXX]
#                      [--csl=host-triple]
#                      [--jlisp] [[jlispboot]
#                      [--psl] [--installed-psl]
#                      [--uncached] [--install] [--keep] [--just-time]
#
# If present the argument "--noregressions" must come first and it
# causes the script to avoid running the regression tests. This may be useful
# when just checking performance of the core of Reduce.
#
# Other arguments can be given in any order. "--install" will lead to
# a fresh set of reference logs being places in the source tree based on
# testing the CSL version. "--keep" preserves some temporary files created
# during testing and may be useful when debugging this script. "--uncached"
# runs the tests with symbolic(!*uncached := t);
# --csl, --psl, --jlisp, --cslboot and --jlispboot select the variants
# of Reduce to test, and any number of those options can be given. If none
# are then "--csl --psl" is assumed. --csl-XXX stands for something like
# --csl-debug, --csl-nothrow, --csl-nothrow-debug or some other collection
# of options referring to a copy of Reduce (or bootstrareduce) in the cslbuild
# directory.
# --installed-csl and --installed-psl use versions of the redcsl and redpsl
# command present on your PATH.

# Part of the intent here is that if any further variants of Reduce get
# created it should be reasonably straightforward to extent the code here
# to support testing them. Changes will be needed in "test1.sh" too.

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives. The logs directories
# csl-times, psl-times etc are created as sub-directories of the directory
# current when this script was invoked.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

# Well I want to tidy up files relating to platforms being tested so I
# do need to scan the argument list and collect them

noregressions="no"
if test "$1" = "--noregressions"
then
  noregressions="yes"
  shift
fi

platforms=""
plist=""
base=""
extras=""
version=""
just_time="no"
for a in $*
do
  case $a
  in
  --install | --keep | --uncached)
    extras="$extras $a"
    ;;
  --csl | --csl-* | --cslboot | --cslboot-* | --csl=* | --jlisp | \
  --jlispboot | --installed-csl | --psl | --installed-psl)
# I will build up two lists of the platforms to test, plus a variable.
#    $platforms will be a sequence of names like "csl psl" etc and is used in
#       this file to deal with directories within which logs accumulate.
#    $base is the first entry on $platforms and is used as the base-system
#       against which others are evaluated.
#    $plist is a list like "--psl --csl" used to pass down to test1.sh
    sys=${a#--}
    if test "$base" = ""
    then
      plist="$a"
      platforms="$sys"
      base="$sys"
    else
      plist="$plist $a"
      platforms="$platforms $sys"
    fi
    ;;
  --just-time)
    just_time="yes"
    ;;
  *)
    printf "\"$a\" is not a valid argument to this script.\n"
    printf "Valid options are: --csl* --cslboot* --jlisp --jlispboot --psl\n"
    printf "    --noregressions --install --keep --uncached\n"
    printf "Stopping.\n"
    exit 1
    ;;
  esac
done

# Apply default if no platforms specified
if test "$base" = ""
then
  plist="--csl --psl"
  platforms="csl psl"
  base="csl"
fi

if test "$just_time" = "no"
then

#
# Remove old log files
#
  for sys in $platforms
  do
    rm -f $sys-times/*.rlg* $sys-times/showtimes \
          $base-$sys-times-comparison/*.rlg.diff
    mkdir -p $sys-times
    echo "showtimes := '(" > $sys-times/showtimes
  done

  packages=`sed -e '/^\%/d' $here/packages/package.map | \
            grep ' test ' | \
            sed -e 's/(//; s/".*//'`

  for p in $packages
  do
    echo "Test package $p"
    $here/scripts/test1.sh $extras $plist $p
  done

  if test "$noregressions" = "no"
  then
    for p1 in $here/packages/regressions/*.tst
    do
      p=${p1%.tst}
      p=${p##*/}
      echo "Test regression case $p"
      $here/scripts/test1.sh $extras $plist regressions $p
    done
  fi

  for sys in $platforms
  do
    echo ")\$ end\$" >> $sys-times/showtimes
  done
fi

printf "\nSummary of test runs for $platforms\n\n"

for sys in $platforms
do
  d=`cd $sys-times; echo *.rlg.diff`
  if test "$d" != "*.rlg.diff"
  then
    printf "\nDifferences for $sys: `echo $d | sed -e 's/\.rlg\.diff//g'`\n"
  fi
done

for sys in $platforms
do
  if test "$sys" != "$base"
  then
    d=`cd $base-$sys-times-comparison; echo *.rlg.diff`
    if test "$d" != "*.rlg.diff"
    then
      printf "\nDifferences between $base and $sys: `echo $d | sed -e 's/\.rlg\.diff//g'`\n"
    fi
  fi
done

printf "\n"

reporttime() {
  name=$1
  dir=$2
  total="0"
  opt=""
  if test "`which redcsl 2> /dev/null`" != ""
  then
    red="redcsl"
    opt="-w"
  elif test "`which redpsl 2> /dev/null`" != ""
  then
    red="redpsl"
  else
    red="$here/bin/redcsl"
    opt="-w"
  fi
  "$red" "$opt" <<XXX | grep "^$name"
symbolic <<
in "$dir/showtimes"$
total := for each r in showtimes sum cadr r;
gctotal := for each r in showtimes sum caddr r;
terpri();
prin2 "$name";
prin2 " ";
while posn() < 20 do prin2 " ";
prin2 total; prin2 " ms CPU ";
while posn() < 40 do prin2 " ";
prin2 gctotal; prin2 " ms GC";
terpri();
quit; >>$
XXX
}

for sys in $platforms
do
  case $sys in
  cslboot*)
    reporttime "CSLBOOT${sys#cslboot}" "$sys-times"
    ;;
  installed-cslboot)
    reporttime "installedCSLBOOT" "installed-cslboot-times"
    ;;
  csl*)
    reporttime "CSL${sys#csl}" "$sys-times"
    ;;
  installed-csl)
    reporttime "installedCSL" "installed-csl-times"
    ;;
  jlisp)
    reporttime "Jlisp" "jlisp-times"
    ;;
  jlispboot)
    reporttime "Jlispboot" "jlispboot-times"
    ;;
  psl)
    reporttime "PSL" "psl-times"
    ;;
  installed-psl)
    reporttime "installedPSL" "installed-psl-times"
    ;;
  esac
done

# end of script

