                     A fat binary scheme for Windows

The scheme here can pack several variants of Reduce into a single file.
The purpose of this is so that just one binary can be shipped but it
will be useful across a range of platform variants.

The important binaries created here are called reduce.exe and winreduce.exe.
The first is linked as a console mode application. The effect is that it
can be launched from a terminal and is capable of retaining contact with that
terminal. However the simple usage
   reduce
will in fact tend to create a GUI version with its own window. To get
console mode use
   reduce --nogui
[or for short "reduce -w"]. If something is launched from a cygwin console
and DISPLAY is set it will run cygwin code using an X11-based version of the
GUI. If a console mode version is run from a cygwin console it will use
screen character addressing in Unuix/Linux/BSD style rather than the native
Windows version. When running under cygwin will automatically detect if it
is launched from the 32 or 64-bit version of cygwin and behave appropriately.

Data compression is used to keep the resulting binaries a tolerable size.

The code stub that implements this is mostly in the file stub.c, and
the code in addresource.c is used when assembling the composite files
that are used.

                                                     A C Norman.  March 2014