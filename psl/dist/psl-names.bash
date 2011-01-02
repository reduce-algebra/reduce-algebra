###############################################################################
#
# File:         PSL:PSL-NAMES
# Description:  This file has machine independent and machine specific env
#               names.  The machine specific parts all start with PX.
# Author:       Harold Carr & Leigh Stoller
# Created:      
# Modified:     
# Mode:         
# Package:      
# Status:       Experimental (Do Not Distribute)
#
# (c) Copyright 1982, University of Utah
# %
# % Redistribution and use in source and binary forms, with or without
# % modification, are permitted provided that the following conditions are met:
# %
# %    * Redistributions of source code must retain the relevant copyright
# %      notice, this list of conditions and the following disclaimer.
# %    * Redistributions in binary form must reproduce the above copyright
# %      notice, this list of conditions and the following disclaimer in the
# %      documentation and/or other materials provided with the distribution.
# %
# % THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# % AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# % THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# % PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
# % CONTRIBUTORS
# % BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# % CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# % SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# % INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# % CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# % ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# % POSSIBILITY OF SUCH DAMAGE.
#
###############################################################################
#
# Revisions:
#
# Mar 18 1987 (Harold Carr & Leigh Stoller)
#  Moved the machine-dependent names to xxx-names.
# Dec 21 1986 (Leigh Stoller)
#  cl variable should reference=$proot, not ~psl.
# Dec  6 1986 (Leigh Stoller)
#  Changed proot from /v/misc/psl3.4 to /v/misc/psl.
#
###############################################################################

# Define the variables for easy access to psl sub-directories
# This file must be edited to reflect local installation choices of
# the root of the psl directory structure, proot
# and any other directories that by local convention are moved
# from subtrees of=$proot to other locations.

# All of these variables are set in the environment, so they are accessible
# from within scripts and PSL itself as dollarsign-variables "$var".
# Since the environment is inherited, it is only necessary to source psl-names
# once in your .login file, rather than in the .cshrc for every c-shell.

export proot=/home/winfried/reduce-algebra/trunk/psl

export psl=$proot/dist          # Top of PSL tree.
# export cl=$proot/pclsdist     # Top of PCLS tree.

export psys=$proot/bin/$MACHINE # All PSL executables go here.

export pl=$psl/lap/$MACHINE     # Loadable files

export plcl=$proot/local        # Put site specific source files here.
export pll=$plcl/lap/$MACHINE  # Lap directory for local stuff.

export pk=$psl/kernel		# Machine-independent kernel sources
export pxk=$psl/kernel/$MACHINE # Machine specific kernel sources

export pnk=$psl/nonkernel	# Machine-independent non-kernel
export pxnk=$psl/nonkernel/$MACHINE  # Machine specific non-kernel
export pnkl=$psl/nonkernel/$MACHINE/lap  # Non-Kernel binaries

export pc=$psl/comp		# Machine-independent compiler sources
export pxc=$psl/comp/$MACHINE	# Machine specific compiler sources

export pu=$psl/util		# Machine-independent utility programs
export pxu=$psl/util/$MACHINE	# Machine specific utility program sources

export pdist=$psl/distrib	# Distribution support
export pxdist=$psl/distrib/$MACHINE # Distribution support, Machine specific

# End of file.
