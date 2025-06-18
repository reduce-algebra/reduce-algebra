#!/bin/bash

tex '\def\filename{{manual}{idx}{4dx}{ind}} \input idxmake.4ht'

# Edit manual.4dx "in-place":
sed -e 's/^\(\\indexentry{[^@]*\)\\textbar/\1"|/' \
    -e 's/^\(\\indexentry{[^@]*\)\\underscore/\1_/' \
    -e 's/^\(\\indexentry{[^@]*\)\\char `\\\\/\1\\\\/' \
    -e 's/^\(\\indexentry{"\\\^ operator@\\texttt {\)"\\\^/\1\\textasciicircum/' \
    -i manual.4dx

makeindex -s manual.ist manual.4dx

exit 0
