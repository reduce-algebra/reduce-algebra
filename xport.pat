# This file is used by Arthur Norman to help him synchronize a copy of
# his own private copy of the Reduce tree with copies in (virtual) machines
# where he is checking things. It is probably not relevant to anybody else,
# but life is made much easier for ACN if it is visible here!

Master=panamint scp://acn1@codemist.dyndns.org:/d/projects/reduce-algebra/trunk
Master=gauguin  scp://acn1@gauguin.trin.cam.ac.uk:reduce-algebra/trunk

Omit cslbuild pslbuild generic temp
Omit autom4te.cache **/autom4te.cache .svn **/.svn
Omit **.bak **~ **.log

Omit psl displaytex
Omit csl/embedded/*.o csl/embedded/reduce csl/embedded/reduce.exe

Binary  **/configure configure **bpsl* **schau **.pl **.parser **.properties
Executable **/configure configure **bpsl* **schau **.pl **.parser

Binary **/bst2groovy **/exbib **/exbibutil **/exindex **/showfmt

