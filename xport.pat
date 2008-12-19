# This file indicates which files in the current directory should
# be exported and which should not.

Master=gauguin  scp://acn1@gauguin.trin.cam.ac.uk:fullopenreduce/trunk
Master=panamint scp://acn1@codemist.dyndns.org:/c/projects/fullopenreduce/trunk

hostcase

Omit **/xport*
Include **/xport.pat

Omit cslbuild pslbuild csllogs psllogs
Omit openreduce-* openreduce.tar.bz2
Omit lgplfiles* rebuild.log *.dep

# Omit the following until it is clear what effect the use of the
# cygwin dll has on it. I also do not ever want to redistribute a
# libreadline binary since that code is under the GPL and I would need to
# be careful to send source too.
Omit psl/cygwin32 **/libreadline*
Binary     **/bpsl **/bpslnew packages/redfront/**/redfront
Executable **/bpsl **/bpslnew packages/redfront/**/redfront
Executable **/gnuplot **/gnuplot_x11

Omit **.bak **.aux **.dvi **.alw **~ **.old **.OLD .svn **/.svn
Omit **.BAK **.OBJ **.AUX **.DVI **.ERR **.CAR RCS rcs
Omit **.car **.uue **.Z **.err ,** **/,**
Omit **.tmp* **.TMP* **.deps **.lnk **.lineno config.log config.status
Omit **autom4te* .sconf* .scons*
Omit LGPLMANIFEST.new MANIFEST.new


# A user is entitled to have files or directories whose name starts
# "local..." and these will not be tampered with by this utility. I will
# tend to use files named xxx* for transient purposes.

Omit local* **/local* xxx*

Binary **.ico **.bmp **.exe **.class **.gz **.tar **.bz2
Binary **.jpg **.gif **.png **.b **.o **.obj **.com **.sh **.ico
Binary **.ttb **.pfb **.pfm **.ttf **.pdf **.dylib **.tgz **.weg **.bb **.img
Binary **/redfront **.so.* **/bpsl **/bpslnew **/gnuplot **/gnuplot_x11

Executable **.exe **.sh
Executable **/configure **/config.guess **/depcomp **/missing

Executable bin/*

# end of xport.pat

