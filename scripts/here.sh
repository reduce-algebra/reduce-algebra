# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
a="$0";while test -L "$a";do a=`ls -ld "$a" | sed 's/.*-> //'`;done
echo `cd \`dirname "$a"\`/.. ; pwd`
