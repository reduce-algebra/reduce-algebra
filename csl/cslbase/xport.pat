# The file indicates which files in the current directory should
# be exported and which should not. I will include some patterns here
# that relate to both Unix and DOS filenames (eg .o and .obj).

# note that a URL can be like
#   scp://user@host=port:path

Master=home  scp://acn1@codemist.dynu.com:/y/projects/reduce-algebra/trunk/csl/cslbase
Master=gauguin  scp://acn1@gauguin.trin.cam.ac.uk:reduce-algebra/trunk/csl/cslbase

Master=hometest  scp://acn1@codemist.dynu.com:/y/projects/testing-reduce/csl/cslbase
Master=gauguintest  scp://acn1@gauguin.trin.cam.ac.uk:testing-reduce/csl/cslbase


hostcase

Omit *
Include *.h *.cpp configure.ac Makefile.am *.red *.lsp

# end of xport.pat

