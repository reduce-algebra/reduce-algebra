#! /bin/sh

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

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

for p in *.rlg
do
  $here/scripts/install-one-new-log.sh ${p%.rlg}
done

# end of script




