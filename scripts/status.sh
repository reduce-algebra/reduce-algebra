#! /bin/bash
# This lists all files in the subversion tree that have been changed
# locally. I find it useful when I have been making a load up local
# updates and wish to be reminded where they all are.
svn status | grep -v ^?

