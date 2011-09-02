REM Fetch a new copy of the patches file.
copy 0patches.red 1patches.red
copy patches.red 0patches.red
echo "About to fetch new copy of patches.red file"
xport -get http://ftp.rand.org/software_and_data/reduce/patches/patches.red patches.red
echo "done"
xport -inc

