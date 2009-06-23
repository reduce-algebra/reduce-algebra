#! /bin/sh

echo "This script is a DRASTIC one that is not expected to be useful in"
echo "ordinary circumstances, and should NOT be used casually. Its job is to"
echo "bring the local copy as closely into step with the files on subversion"
echo "as possible. In doing this it will DELETE any locally-built files and"
echo "DISCARD any local changes. So if you are a developer then use of this"
echo "script really risks leading to loss of your work."
echo " "
echo "Are you certain that you wish to continue. Type YES in capitals if"
echo "you are"

read answer

if test "x$answer" != "xYES"
then
  echo "OK, not files will have been damaged."
  exit 1
fi

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

echo $here
save=`pwd`
cd $here

# Discard files that I expect to be places where thiings are built or that
# are residues of a build.

rm -rf cslbuild pslbuild generic/redlog/libedit* generic/redlog/csl generic/redlog/psl

# Discard files whose names suggest that they are not part of the
# distribution from Sourceforge.

find . \( -name config.cache -o -name \*.bak -o -name autogen.stamp \) -print | xargs rm -rf

# Unwind any local changes to files. Note that this LOSES any changes that
# you might have made intentionally, and so is not something to do casually.

svn -R revert .

# Bring in any files that have either been updated centrally or that are
# needed to replace things that you have deleted locally.

svn update

# This looks for files that you have in your directory that subversion does
# not know of as copies of things from the main repository. I set up ready to
# delete all such. This may include local log files, work in progress or
# ANYTHING that you have put anywhere in this tree, and the idea of this
# script is that it is DELETED. Please note that you have been warned!

svn status | grep "^?" | sed -e "s/^[?]/rm -rf/g" | /bin/sh

# At the end I HOPE that if you go
#     svn status
# if will not generate any reports at all. You should check that now.

cd $save
