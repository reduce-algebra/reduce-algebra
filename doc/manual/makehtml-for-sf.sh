#!/bin/bash

# Use TeX4ht to build an HTML5 version of the REDUCE manual using
# MathJax by running make4ht, ONLY for use on the web site.

# FJW -- Time-stamp: <2025-06-22 16:38:46 franc>

# This script is equivalent to 'mkhtml.sh for-sf' but it runs make4ht
# once instead of mk4ht twice.  It requires the (Lua) build script
# ./manual.mk4, which calls the (Bash) script ./makehtml-index.sh to
# build the index.

# Requires non-standard software (in addition to TeX4ht):
#   make4ht (in TeX Live collection-binextra)
#   luaxml (for extensions; in TeX Live collection-luatex)

# Documentation:
#   https://tug.org/tex4ht/
#   https://www.kodymirus.cz/tex4ht-doc/tex4ht-doc.html
#   https://mirrors.ctan.org/support/make4ht/make4ht-doc.pdf

help () { echo '
Usage: makehtml.sh [-a <loglevel>] [-m <mode>]
  or   makehtml.sh -h to display help and exit

<loglevel> = debug, info, status*, warning, error, fatal;
<mode>     = draft, default*; * indicates default.'
          exit 1; }

LOGLEVEL='status'
MODE='default'
while getopts a:m:h OPTION
do
    case $OPTION in
        a) LOGLEVEL=$OPTARG;;
        m) MODE=$OPTARG;;
        h|?) help;;
    esac
done
shift $(( $OPTIND - 1 ))

cd `dirname $0`

TEX4HT_STY_OPTIONS='3,fn-in,fancylogo'
# Comma-separated options that must begin with name of configuration file if included:
# sectioning depth, inline footnotes, TeX & LaTeX logos
# index=2 is not useful

# Configuration file "reduce-sf.cfg" specifies "xhtml,mathjax".

TEX4HT_OPTIONS='" -cunihtf"'
# Space-separated options that must begin with font option or a space.
# " -cmozhtf -utf8" is the default; same as " -cunihtf -utf8" but removes ligatures.

# T4HT_OPTIONS="-cvalidate"
# Space-separated options.

# UTF-8 is the default coding system (so the -u option is now redundant).
# +common_domfilters produces warnings on a few files, which end up mangled!


# COMMAND="make4ht -a $LOGLEVEL -m $MODE -c reduce-sf manual $TEX4HT_STY_OPTIONS $TEX4HT_OPTIONS $T4HT_OPTIONS"
COMMAND="make4ht -a $LOGLEVEL -m $MODE -c reduce-sf -f html5-common_domfilters manual $TEX4HT_STY_OPTIONS $TEX4HT_OPTIONS $T4HT_OPTIONS"


if [ $MODE = 'default' ]
then
    echo 'Removing previously generated files...'
    GLOBIGNORE=$(echo manual.{bib,ist,mk4,pdf,tex,toc}) # exceptions
    GLOBIGNORE=${GLOBIGNORE// /:}
    rm -f manual*.{html,png} manual.*
fi

# Write current svn revision number to "revision.tex".  (Note that any
# version of this script used to build snapshot releases needs to use
# ../../scripts/revision.sh because the code below doesn't work, but
# it seems to be noticeably faster, so I use it here!)
rev=$(svnversion)
# Delete beginning of range if present:
rev=${rev##*:}
# Delete any trailing annotations:
rev=${rev%%[^0-9]*}
echo $rev > revision.tex

echo $COMMAND; eval $COMMAND

# See also "manual.mk4", which runs makeindex and bibtex.

rm revision.tex

exit 0
