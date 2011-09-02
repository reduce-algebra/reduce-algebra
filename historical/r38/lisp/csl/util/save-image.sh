#! /bin/sh

dest=${r38_archive:-acn1@codemist.dyndns.org:/d/r38}
echo "Save images to $dest [use r38_archive to override]"

case `pwd` in
*local*64)
    echo save image for linux64
    make r38.img
    make slowr38.img
    make csl.img
    scp r38.img $dest/images/r38-64.img
    scp slowr38.img $dest/images/slowr38-64.img
    scp csl.img $dest/images/csl-64.img
    ;;
*demo*64)
    echo save image for demo linux64
    make r38.img
    scp r38.img $dest/images/demo-r38-64.img
    ;;
*local*)
    echo save image for 32-bit systems
    make r38.img
    make slowr38.img
    make csl.img
    scp r38.img $dest/images/r38-32.img
    scp slowr38.img $dest/images/slowr38-32.img
    scp csl.img $dest/images/csl-32.img
    ;;
*demo*)
    echo save demo image for 32-bit systems
    make r38.img
    scp r38.img $dest/images/demo-r38-32.img
    ;;
*)
    echo request to save image for `pwd` not recognized.
    ;;

esac

