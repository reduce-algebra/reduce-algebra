#! /bin/bash

# Copy the manual HTML and PDF files from the documentation
# directory to the web directory.

source='../doc/manual'
target='htdocs/manual'

if [ -d $target ]; then
    rm $target/*
else
    mkdir $target
fi

cp $source/{manual*.{css,html,pdf,png},header.png} $target

# Zip resulting manual directory.

cd htdocs
rm -f manual.zip
zip -rq9 manual.zip manual

# Copy manual.zip to SourceForge, then unzip there interactively.

# This assumes SSH key posted so no explicit authentication required;
# see https://sourceforge.net/p/forge/documentation/SSH%20Keys/

scp manual.zip fjwright@web.sourceforge.net:/home/project-web/reduce-algebra/htdocs

# It seems that operations at SourceForge can only be done
# interactively, so do:

# ssh -t fjwright@shell.sourceforge.net create
# /home/project-web/reduce-algebra/unzip-manual
