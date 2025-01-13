#! /bin/bash

# Upload the local manual directory to SourceForge.

# Zip local manual directory.

cd htdocs
rm -f manual.zip
zip -rq9 manual.zip manual

# Upload manual.zip to SourceForge, then unzip there interactively.

# This assumes SSH key posted so no explicit authentication required;
# see https://sourceforge.net/p/forge/documentation/SSH%20Keys/

scp manual.zip fjwright@web.sourceforge.net:/home/project-web/reduce-algebra/htdocs

# It seems that operations at SourceForge can only be done
# interactively, so...

echo 'Finally, do the following interactively:'
echo 'ssh -t fjwright@shell.sourceforge.net create'
echo '/home/project-web/reduce-algebra/unzip-manual.sh'
