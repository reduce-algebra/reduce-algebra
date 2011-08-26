#! /bin/bash

# Install all new logs with names of form *.rlg in current directory
# to where they belong. This is based on the new scripts/testall.sh model
# of testing everything. It takes logs from the current directory so
# that it can be used to install either CSL or PSL versions. It will
# typically be used as
#    cd ..../trunk
#    cd csl-times                     or psl-times
#    ../scripts/install-new-logs.sh


# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

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
here=`echo $here | sed -e 's+/[^/]*$++'`


for p in *.rlg
do
$here/scripts/install-one-new-log.sh ${p%.rlg}
done

# end of script




