#! /bin/bash

# Unzip htdocs/manual.zip at SourceForge carefully to update the
# manual directory, leaving a copy as manual.old.

# Run this script at SourceForge by doing:

# ssh -t USERNAME@shell.sourceforge.net create
# /home/project-web/reduce-algebra/unzip-manual.sh

cd "$(dirname "$0")/htdocs" && \
    unzip -jq manual.zip -d manual.new && \
    rm -rf manual.old && \
    mv manual manual.old && \
    mv manual.new manual
