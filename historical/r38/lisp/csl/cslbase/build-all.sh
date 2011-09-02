#! /bin/sh

#
# This script builds all of REDUCE... I would rather distinctly
# suggest that rather than just launching this script that you
# run each step of it so you can verify good behaviour stage by stage.
#
# This script expects to be launched in a directory such that the
# source directory "r38/lisp/csl/cslbase" can be reached as "../cslbase".
#
# A convention I use is to make a directory called "local-build" to run in.
#

# NB I would quite like to use "pushd" and "popd" but they are not part
# of plain "sh" so I do things another way.

buildloc=`pwd`
echo "Building in $buildloc"

# Find location of this "build-all.sh" script
a=$0; c="unknown"; case $a in
/* ) c=$a ;  ;;
*/* ) case $a in ./* ) a=`echo $a | sed -e 's/\.\///'`; ;; esac
c=`pwd`/$a; ;;
* ) for d in $PATH; do if test -x $d/$a; then c=$d/$a; fi; done
if test $c = "unknown";then
echo "Unable to find full path for script. Please re-try"
echo "launching it using a fully rooted path."
exit 1
fi; ;; esac
here=`echo $c | sed -e 's/\/[^/]*$//'`
echo "CSL source code is in $here/../cslbase"

#
# First build the FOX library. The installed headers and libraries
# will be put in ../fox/<architecture>
#

chmod +x $here/../support-packages/*.sh
/bin/sh $here/../support-packages/build-all.sh $*

#
# Ensure some files are executable when they need to be.
# This is in case the file-transfer scheme used has not done
# so already for you. Get date-stamps on some key files in the
# correct sequence. All these file permissions etc ought to be
# correct in the Reduce archive but re-setting them here adds a level
# of safety in case somebody has copied files in a way that loses
# attributes.
#

cd $here/../cslbase
chmod +x *.sh configure; ./stamp.sh
cd $here/../util; . ./setexec.sh
cd $buildloc

# Configure it, using the support packages built above

$here/../cslbase/configure --with-fox=$here/../fox

# I will need to do something different on Windows to allow for
# the fact that executables get an ".exe" extension.

# Compile REDUCE and build its image file. If this script
# is given an argument "bootstrap" it does a great deal more
# work (and the extra work is in general unnecessary).

if test "x$1" = "xbootstrap"
then

echo "Doing a full expensive bootstrap"

# Build a bootstrap version of REDUCE not needed apart from when
# doing a full-scale bootstrap reconstruction of everything. First
# build the executable and then its image file.
make slowr38
make slowr38.img

# Run all the test scripts to collect statistics that will be used
# to identify hot-spots in the REDUCE code.

make profile

# Install the file "profile.dat" just created, and based upon it
# select a collection of REDUCE functions and compile them into C code.

make prof-inst
make c-code

fi

# Build the CSL Lisp system. Not needed for REDUCE but here for completeness

make csl
make csl.img

# Build REDUCE and its image file. 

make r38
make r38.img

# Run all tests scripts and compare with reference output

make testall
make checkall

# Admire the speed of your computer
if test -x /usr/bin/less
then
  MORE=/usr/bin/less
else
  MORE=more
fi

$MORE log/times.log

# end of build-all.sh


