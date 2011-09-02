
if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

makemake -f makebase -o Makefile.linux   linux gcc             -d%srcdir%
makemake -f makebase -o Makefile.w32     win32 watcom          -d%srcdir%
makemake -f makebase -o Makew32.dbg      win32 watcom debug    -d%srcdir%
makemake -f makebase -o Makefile.vc      win32 microsoft       -d%srcdir%
makemake -f makebase -o Makefile.cyg     cygwin                -d%srcdir%
makemake -f makebase -o Makefile.sunos   sparc sunos gcc       -d%srcdir%
makemake -f makebase -o Makefile.solaris sparc solaris gcc     -d%srcdir%
makemake -f makebase -o Makefile.gcc     unix gcc              -d%srcdir%
makemake -f makebase -o Makefile.cc      unix cc               -d%srcdir%
makemake -f makebase -o Makefile.ultra   ultrasparc solaris cc -d%srcdir%
makemake -f makebase -o Makefile.sgi     sgi                   -d%srcdir%
makemake -f makebase -o Makefile.alpha   alpha                 -d%srcdir%

