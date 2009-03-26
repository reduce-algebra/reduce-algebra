#!/bin/bash

# Look at what has been 'save'd by gnuplot, and write out only differencies.
# Author: Petr Mikulik
# History:
#	1999 gpsavediff.cmd: REXX version
#	2003 gpsavediff.sh:  bash version
# License: public domain


Usage ()
{
    echo "Script to strip default values from a given gnuplot input file; usually"
    echo "used to a file created by gnuplot's \"save\" command."
    echo "Usage:"
    echo "    gpsavediff [gnuplot_save_file]"
    echo "If no file given, then take standard input."
    echo "Result is printed on standard output."
    echo "Example 1: ~/work\$ gpsavediff sinc.gp >new_sinc.gp"
    echo "Example 2: gnuplot> save \"|gpsavediff >sinc.gp\""
    exit
}

# Require none or one argument.
if [ ! -z "$2" ] ; then
    Usage
fi
if [ "$1" == "--help" -o "$1" == "-?" ] ; then
    Usage
fi


# Note -- these two command chains are equivalent:
#	sed "/^[^>]/d;s/^> //;/^#    	/d"
#	grep ">" | sed "s/^> //" | grep -v "#    	" |

# One input file given an input.

if [ ! -z "$1" ] ; then
    if [ ! -f "$1" ] ; then
	echo "Input file \"$1\" does not exist."
	exit
    fi
    echo "reset; save \"-\"" | gnuplot | \
	diff -w - $1 | sed "/^[^>]/d;s/^> //;/^#    	/d"
#	diff -w - $1 | grep ">" | sed "s/^> //" | grep -v "#    	" |
    exit
fi

# Data come from standard input, thus must use a temporary file for gnuplot
# default values.
if [ -z "$1" ] ; then
    TMP="/tmp/$USER_save_tmp.gp"
    echo "reset; save \"-\"" | gnuplot >"$TMP"
    diff -w "$TMP" - | sed "/^[^>]/d;s/^> //;/^#    	/d"
#    diff -w "$TMP" - | grep ">" | grep -v "#    	" | sed "s/^> //"
    rm -f "$TMP"
    exit
fi

Usage()

# eof gpsavediff
