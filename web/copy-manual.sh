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
