#! /bin/bash
#
# Install REDUCE in a dircetory that the user specifies
#
echo "This will install REDUCE. Please specify a directory"
echo "that you would like the REDUCE files put in. This"
echo "directory will end up containing several files and"
echo "subdirectories..."
echo ""

# I use "bash" not just plain "sh" since I want to use "read" with
# a "-p" (prompt) parameter... Also this is mostly for Linux so I
# feel happy assuming "bash" is installed.

read -p "Directory: " dest
# What the user types is not processed at all by "read", but a user may feel
# entitled to enter things like "~/dir" or "$MYDIR/path" and certainly for
# the letter to work I need the next line here.
dest=`eval echo $dest`

if test -a $dest; then
  if test -d $dest; then
  echo "Will install in $dest"
  else
    echo "$dest exists but is not a directory."
    echo "Unable to proceed."
    exit 1
  fi
else
echo "Directory $dest does not exist."
read -p "Shall I create it? (yes/no): " response
if test "x$response" != "xyes"; then
echo "Abandoning installation attempt."
exit 1
fi
# Here I need to try to create the directory
echo "Creating $dest for you..."
mkdir -p $dest
fi

cp -pr ./r38.img ./r38.doc ./tests ./util ./testall.sh ./checkall.sh $dest


./relink.sh $dest

echo "Reduce should now be available in $dest"
echo "You may wish to add that directory to your PATH"

exit 0


