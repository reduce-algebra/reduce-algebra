# This file is used by Arthur Norman to help him synchronize a copy of
# his own private copy of the Reduce tree with copies in (virtual) machines
# where he is checking things. It is probably not relevant to anybody else,
# but life is made much easier for ACN if it is visible here!

Master=panamint scp://acn1@codemist.dyndns.org:/c/projects/reduce-algebra/trunk
Master=local    ftp://acn1:?@192.168.1.10/trunk

Omit cslbuild pslbuild generic temp
Omit autom4te.cache **/autom4te.cache .svn **/.svn
Omit **.bak **~ **.log

Binary **/configure configure **bpsl* **schau
Executable **/configure configure **bpsl* **schau


