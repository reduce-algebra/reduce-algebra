/* ---------------------------------------------------------------------
   $Id$
   ---------------------------------------------------------------------
   (c) 2016 Arthur Norman
   ---------------------------------------------------------------------
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
  
      * Redistributions of source code must retain the relevant
        copyright notice, this list of conditions and the following
        disclaimer.
      * Redistributions in binary form must reproduce the above
        copyright notice, this list of conditions and the following
        disclaimer in the documentation and/or other materials provided
        with the distribution.
  
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#if defined WIN32 && ! defined __CYGWIN__
#define NATIVE_WINDOWS 1
#endif


/* call passing argv[0] to set the strings listed below */
extern int find_program_directory(const char *argv0);

#define LONGEST_LEGAL_FILENAME 1000

/*
 * Will be set non-zero of the program is a windows executable with suffix
 * of the form ".com"
 */
extern int programNameDotCom;

/*
 * Absolute path of the directory that the code is in, and this should
 * not have a trailing "/". For sor instance for a system-installed
 * program it might be "/usr/bin".
 */
extern const char *programDir;

/*
 * Name of the program, without any ".exe" (etc) suffix. So this will
 * typically be "rfcsl" or "rfpsl" in this case.
 */
extern const char *programName;

/*
 * Full name of executable, formed from concatenation of the above two.
 */
extern const char *fullProgramName;

/* end of findself.h */

