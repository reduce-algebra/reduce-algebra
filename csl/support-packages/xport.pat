# "csl/support-packages" The file indicates which files in the current
# directory should be exported and which should not.

# gauguin (the default) is fairly public: it is accessed as part of
# the development system. The other sites are private and only
# available to those with accounts on the relevant machines.

Master=gauguin    http://gauguin.trin.cam.ac.uk/csl/support-packages

Master=cvsgauguin scp://?@gauguin.trin.cam.ac.uk:~acn1/redcvs/r38/lisp/csl/support-packages
Master=sgauguin   scp://?@gauguin.trin.cam.ac.uk:~acn1/r38/lisp/csl/support-packages
Master=panamint   scp://?@codemist.dyndns.org:/c/projects/r38/lisp/csl/support-packages
Master=panamint1  scp://?@192.168.0.10:/c/projects/r38/lisp/csl/support-packages
Master=snout      scp://?@snout:~acn1/r38/lisp/csl/support-packages
master=west       scp://?@west.codemist.co.uk:~acn1/r38/lisp/csl/support-packages

Hostcase

Omit CVS **/CVS
Omit **.bak **.BAK **.obj **.OBJ **.res **.aux **.dvi **.alw
Omit old **.old ,** **/,** xxx* XXX*
Omit *.log

Omit TnFOX

# A user is entitled to have files or directories whose name starts
# "local..." and these will not be tampered with by this utility
Omit local* **/local*
Omit *experimental*

Binary *.exe *.img *.ico *.hlp **.gz **.zip **.tar **.tgz

# Under the cygwin shell scripts MUST be Unix-style line-end
# so to avoid CRLF-pain I treat them as binary. I try to list all
# such files I know of here. The pattern **.sh should catch "most".
Binary **.sh **configure **configure.ac **auto **aclocal.m4 **config.guess
Binary **config.sub **depcomp **install-sh **make-fox-icons **missing
Binary **mkinstalldirs **stamp **boot38 **c-code38 **checkall
Binary **checkall-personal **clash **full38 **makeall **package
Binary **profile **setexec **testall **testall-personal **testrest **testslow

Include autoconf*.tar.gz automake*.tar.gz

# end of xport.pat
