# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here=`dirname "$0"`
echo `cd "$here/.." ; pwd`
