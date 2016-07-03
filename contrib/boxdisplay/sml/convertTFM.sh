#!/bin/bash

# A quite grotty script for converting proper TFM files to the
# idiosyncratic format that SML-Tex expects its font metrics to be  
# in. The script requires parseTFMPL.red to be in the working directory.

# Example usage: ./convertTFM.sh cmex10.tfm EX10
#                ./convertTFM.sh cmmi8.tfm  MI8 375
# The third argument (optional) is the skewchar (in decimal).

# The output of tftopl is essentially a single sexpr
# except missing opening and closing parens, so I put them in.
echo "(" >temppl
tftopl -charcode-format=octal "$1" >>temppl
echo ")" >>temppl

# We want to invoke an RLISP function parse_tfm_file from parseTFMPL.red,
# and since I don't know how to do command-line arguments in RLISP, 
# I just append the call here to parseTFMPL.red and point Reduce at that file.
cp parseTFMPL.red tempred
echo "" >>tempred
echo -n "parse_tfm_file(\"temppl\", \"$2\", " >>tempred
if [[ -z $3 ]] 
then
  echo "nil);" >>tempred
else
  echo "$3);" >>tempred
fi
echo "end;" >>tempred

reduce -w tempred
rm tempred temppl