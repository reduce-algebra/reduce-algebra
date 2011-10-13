.PU
.TH SPARSIFY 1 local
.SH NAME
sparsify \- sparsify files with blocks of zeros in them
.SH SYNOPSIS
.ll +8
.B sparsify
[
.I "name"
]
.SH DESCRIPTION
.I Sparsify
reduces the size of the named file using the "sparse file" feature of
the Unix file system. The file will read identically after it has been
processed by sparsify. 
This process is useful on files containing a large number of contiguous
zeros, such as PSL images, TeX dumped images and so on.
Sparsifyed files can be restored to their original form using
.I cp
or
.I tar.
Sparsify is normally used after these operations (or
.I compress/uncompress) 
have destroyed the sparse nature of a file.
Major savings can be made by using this on PSL images, bps.o and
dmain.o files, and indeed on any .o file which allocates a large
static area filled with zeros.
It preserves access and modification times, and modes.
If run by the super-user, it also preserves ownership and group information.
.SH "SEE ALSO"
pack(1), compact(1)
.SH "DIAGNOSTICS"
Usage: sparsify file 
.in +8
No file name was specified
.in -8
.SH "AUTHOR"
J.H. Davenport, University of Bath, UK.
Modifications by
J.H. Davenport at the RAND Corporation, Santa Monica, USA.
.SH "BUGS"
Does not recover very gracefully if the directories are not writable.
