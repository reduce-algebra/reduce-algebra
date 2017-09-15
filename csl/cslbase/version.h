// version.h                              Copyright (C) 1990-2017 Codemist

#ifndef header_version_h
#define header_version_h 1

// $Id$


/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// PACKAGE_VERSION is used to control the version number displayed when CSL
// is started up in verbose mode (command line option -v). Version numbers
// are also recorded in image files. But NOTE NOTE NOTE that the macro
// PACKAGE_VERSION gets set in config.h based on the version number
// established in "configure.ac" and so the value set here is merely a
// fall-back. Indeed this whole file is a bit of a joke! Well to prevent it
// from being a joke I make it undefine anything that config.h has set up and
// provide its own value explictly.
// This adjustment is more important than ever given that <ffi.h> on the
// Macintosh seems to (to my mind improperly!) define this symbol to reflect
// its version.

#undef PACKAGE_VERSION
#define PACKAGE_VERSION     "9.01"

// As of February 2016 I am making the file scripts/commit.sh update the
// revision number stored here...

#define REVISION 4203

#endif // header_version_h

// end of version.h
