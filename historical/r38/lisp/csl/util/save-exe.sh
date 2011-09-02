#! /bin/sh

dest=${r38_archive:-acn1@codemist.dyndns.org:/d/r38}
echo "Save executables to $dest [use r38_archive to override]"

case `pwd` in
*local*win32)
    echo save executables for win32
    make r38.exe
    make slowr38.exe
    make csl.exe
    make fwindemo.exe
    make termdemo.exe
    strip r38.exe
    strip slowr38.exe
    strip csl.exe
    strip fwindemo.exe
    strip termdemo.exe
    strip r38.com
    strip slowr38.com
    strip csl.com
    strip fwindemo.com
    scp r38.exe $dest/exe/win32/r38.exe
    scp slowr38.exe $dest/exe/win32/slowr38.exe
    scp csl.exe $dest/exe/win32/csl.exe
    scp fwindemo.exe $dest/exe/win32/fwindemo.exe
    scp termdemo.exe $dest/exe/win32/termdemo.exe
    scp r38.com $dest/exe/win32/r38.com
    scp slowr38.com $dest/exe/win32/slowr38.com
    scp csl.com $dest/exe/win32/csl.com
    scp fwindemo.com $dest/exe/win32/fwindemo.com
# Also gnuplot
    make r38.img
# maybe unexpectedly I have the creation of r38.img trigger re-creation
# of the gnuplot stuff.
    scp wgnuplot.exe $dest/exe/win32/wgnuplot.exe
    scp wgnuplot.hlp $dest/exe/win32/wgnuplot.hlp
    scp wgnuplot.mnu $dest/exe/win32/wgnuplot.mnu
    ;;
*local*win64)
    echo save executables for win64
    make r38.exe
    make slowr38.exe
    make csl.exe
    make fwindemo.exe
    make termdemo.exe
    scp r38.exe $dest/exe/win64/r38.exe
    scp slowr38.exe $dest/exe/win64/slowr38.exe
    scp csl.exe $dest/exe/win64/csl.exe
    scp fwindemo.exe $dest/exe/win64/fwindemo.exe
    scp termdemo.exe $dest/exe/win64/termdemo.exe
    scp r38.com $dest/exe/win64/r38.com
    scp slowr38.com $dest/exe/win64/slowr38.com
    scp csl.com $dest/exe/win64/csl.com
    scp fwindemo.com $dest/exe/win64/fwindemo.com
    ;;
*demo*win32)
    echo save executables for demo win32
    make r38.exe
    strip r38.exe
    strip r38.com
    scp r38.exe $dest/exe/demo-win32/r38.exe
    scp r38.com $dest/exe/demo-win32/r38.com
# Also gnuplot
    make r38.img
# maybe unexpectedly I have the creation of r38.img trigger re-creation
# of the gnuplot stuff.
    scp wgnuplot.exe $dest/exe/demo-win32/wgnuplot.exe
    scp wgnuplot.hlp $dest/exe/demo-win32/wgnuplot.hlp
    scp wgnuplot.mnu $dest/exe/demo-win32/wgnuplot.mnu
    ;;
*demo*win64)
    echo save executables for demo win64
    make r38.exe
    strip r38.exe
    strip r38.com
    scp r38.exe $dest/exe/demo-win64/r38.exe
    scp r38.com $dest/exe/demo-win64/r38.com
    ;;
*local*suse*64)
    echo save executables for linux64
    make r38
    make slowr38
    make csl
    make fwindemo
    make termdemo
    strip r38
    strip slowr38
    strip csl
    strip fwindemo
    strip termdemo
    scp r38 $dest/exe/linux64/r38
    scp slowr38 $dest/exe/linux64/slowr38
    scp csl $dest/exe/linux64/csl
    scp fwindemo $dest/exe/linux64/fwindemo
    scp termdemo $dest/exe/linux64/termdemo
    ;;
*demo*suse*64)
    echo save executables for demo linux64
    make r38
    make slowr38
    strip r38
    strip slowr38
    scp r38 $dest/exe/demo-linux64/r38
    ;;
*local*mac-darwin)
    echo save executables for mac-darwin
    make r38
    make slowr38
    make csl
    make fwindemo
    make termdemo
    strip r38
    strip slowr38
    strip csl
    strip fwindemo
    strip termdemo
    scp r38 $dest/exe/mac/r38
    scp slowr38 $dest/exe/mac/slowr38
    scp csl $dest/exe/mac/csl
    scp fwindemo $dest/exe/mac/fwindemo
    scp termdemo $dest/exe/mac/termdemo
# Also gnuplot ... but where it comes from is unclear to me... so I will
# omit this just for now!
#   scp gnuplot $dest/exe/mac/gnuplot
    ;;
*demo*mac-darwin)
    echo save executables for demo mac-darwin
    make r38
    make slowr38
    strip r38
    strip slowr38
    scp r38 $dest/exe/demo-mac/r38
# Also gnuplot ... but where it comes from is unclear to me... so I will
# omit this just for now!
#   scp gnuplot $dest/exe/demo-mac/gnuplot
    ;;
*)
    echo "Only win32, mac-darwin and x86-64 save executables"
    echo "This system is `pwd`"
    ;;
esac

