# newlogs.sh


# This expects a full set of log file sto have been created locally, and it
# copies them all into the packages directory with a ".new" suffix. This
# is expected to ba a foundation for installing a full new set of logs
# in the source tree when a major release is made.

# It is also an illustration that the packages.map file can be processed using
# shell scripts as well as Lisp code is that is useful.

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | sed -e s+./++`
    ;;
  esac
  c=`pwd`/$a
  ;;
* ) 
  for d in $PATH
  do
    if test -x $d/$a
    then
      c=$d/$a
    fi
  done
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac

here=`echo $c | sed -e 's+/[^/]*$++'`


grep csl $here/../packages/package.map | grep test | \
  sed -e 's,(,$here/installlogs-sub.sh ,;s,csl,,;s,psl,,;s,test,,;s,),,;;s,core,,;s,         , ,;s,  , ,' > $here/installlogs.sh

. $here/installlogs.sh
