makemake -f makebase -o Makefile.linux   linux gcc             -d../cslbase
makemake -f makebase -o Makefile.w32     win32 watcom          -d../cslbase
makemake -f makebase -o Makew32.dbg      win32 watcom debug    -d../cslbase
makemake -f makebase -o Makefile.vc      win32 microsoft       -d../cslbase
makemake -f makebase -o Makefile.cyg     cygwin                -d../cslbase
makemake -f makebase -o Makefile.sunos   sparc sunos gcc       -d../cslbase
makemake -f makebase -o Makefile.solaris sparc solaris gcc     -d../cslbase
makemake -f makebase -o Makefile.gcc     unix gcc              -d../cslbase
makemake -f makebase -o Makefile.cc      unix cc               -d../cslbase
makemake -f makebase -o Makefile.sgi     sgi                   -d../cslbase
makemake -f makebase -o Makefile.alpha   alpha                 -d../cslbase

