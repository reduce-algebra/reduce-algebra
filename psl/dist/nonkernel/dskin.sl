%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:DSKIN.SL
% SCCS:		%A% %G% %U%
% Title:        Read/Eval/Print from files
% Author:       Eric Benson
% Created:      24 September 1981
% Modified:     01 Nov 1984 (Brian Beach)
% Status:       Open Source: BSD License
% Mode:         Lisp
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 10 May 1996 (Winfried Neun)
%  Rebound *echo to nil in lapin again...
% 20 Oct 1986 (Russ Fish)
%  Fix dskin-file so it works for lisp syntax sources under an rlisp toploop.
% 27-Oct-84 12:11 (Brian Beach)
%  Added (ON FAST-INTEGERS) so that the + function will work.
% 02-Oct-84 09:23:37 (Alan Snyder)
%  Incompatible changes:
%    Removed processing of EVAL and IGNORE flags, which has been moved to
%    FASLOUT.SL (for proper interaction with macroexpansion); programs other
%    than the compiler that require processing of these flags now must do it
%    themselves.  Made LAPIN more like DSKIN; in particular, it no longer
%    binds *REDEFMSG and *ECHO to NIL.  The function DSKINEVAL no longer
%    exists.
%  Benign cleanup:
%    Completely restructured, using various levels of "internal" functions.
%    Now uses ERRSET instead of ERRORSET.  Removed PACKAGE attribute from the
%    file header.
%  Improved error handling:
%    Added error message for abort caused by errors.  Added unwind-protect to
%    ensure that the input stream is closed.  Added ABORT return value in case
%    dskin is aborted.
%  Support for multiple dialects:
%    Now uses the global variables TOPLOOPREAD*, TOPLOOPEVAL*, and
%    TOPLOOPPRINT* to determine which READ, EVAL, and PRINT functions to
%    invoke.  Added optional termination function argument (to DSKIN-FILE).
%    Introduce a function MODELESS-DSKIN-FILE to make redefinition by
%    DSKIN-MODE.SL easier.
% 01-Dec-83 14:29:08 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                          
%  <PSL.KERNEL>DSKIN.RED.2,  5-Oct-82 11:32:28, Edit by BENSON             
%  Changed DSKIN from FEXPR to 1 argument EXPR                             
%  <PSL.INTERP>DSKIN.RED.11,  7-May-82 06:14:27, Edit by GRISS             
%  Added XPRINT in loop to handle levels of output                         
%  <PSL.INTERP>DSKIN.RED.6, 30-Apr-82 12:49:59, Edit by BENSON             
%  Made !*DEFN call DfPrint instead of own processing                      
%  <PSL.INTERP>DSKIN.RED.3, 29-Apr-82 04:23:49, Edit by GRISS              
%  Added !*DEFN flag, cf TOPLOOP                                           
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(*defn dfprint* toploopread* toploopeval* toploopprint*))
(global '($eof$))

(on fast-integers)

(de dskin (filename)
  % Read and process a file, printing output, possibly COMPILE forms.
  (dskin-file 'DSKIN filename T NIL))

(de lapin (filename)
  % Read and process a file, no printing of output, never COMPILE forms.
  (let ((*defn NIL) (*echo nil))
    (dskin-file 'LAPIN filename NIL NIL)))

(de dskin-file (funspec filename print? terminate-fcn)
  % This is a more primitive function that might be useful.  FUNSPEC is the
  % function name used in error messages.  FILENAME is the name of the file to
  % read.  If PRINT? is false, PRINTing of results of EVAL is inhibited.
  % TERMINATE-FCN, if not NIL, is invoked with FUNSPEC and FILENAME as
  % arguments after processing the last form in the file (but before the file
  % is closed), unless the dskin is aborted.  Returns NIL if file processing
  % terminates normally; returns the symbol ABORT if the dskin is aborted.

  % Note: this function is redefined by DSKIN-MODE.SL such that it obeys the
  % Mode and Package attribute specified in the file header of the file being
  % read.
  (if (neq toploopread* 'REFORMXREAD)	% Make sure not the rlisp parser.
      (modeless-dskin-file funspec filename print? terminate-fcn)
      % Assertion: We don't EVER want to read rlisp code through dskin/lapin.
      (let ((toploopread* 'read)	% Just like in standardLisp fn.
	    (currentreadmacroindicator* 'lispreadmacro)
	    (currentscantable* lispscantable*))
	   (modeless-dskin-file funspec filename print? terminate-fcn))))

(de modeless-dskin-file (funspec filename print? terminate-fcn)
  % This is the primitive function called by the redefined DSKIN-FILE.

  (let ((testopen (errset (open filename 'input) nil)))
    (cond ((pairp testopen)
	   (dskin-stream funspec filename (car testopen) print? terminate-fcn))
	  (t (conterror 99 "Unable to read file `%w'"
			filename (dskin-file funspec filename print?)))
	  )))

(de dskin-stream (funspec filename sin print? terminate-fcn)
  (unwind-protect
   (unprotected-dskin-stream funspec filename sin print? terminate-fcn)
   % Cleanup code:
   (close sin)
   ))

(de unprotected-dskin-stream (funspec filename sin print? terminate-fcn)
  (let ((count 0)
	(in* sin) % fluid
	)
    (while T
      (let ((result (errset (dskin-step print?) T)))
	(unless (pairp result)
	  (errorprintf "%w of `%w' aborted after %w form(s)."
		       funspec filename count)
	  (exit 'ABORT))
	(setf result (car result))
	(when (eq result 'eof)
	  (when terminate-fcn (funcall terminate-fcn funspec filename))
	  (exit NIL)
	  )
	(setf count (+ count 1))
	))))

(de dskin-step (print?)
  % Process a single form.  Return EOF or OK.
  (let ((temp (funcall toploopread*)))
    (cond ((eq temp $eof$) 'EOF)
	  ((not *defn)
	   (setf temp (funcall toploopeval* temp))
	   (when (and print? (not *defn))
	     (funcall toploopprint* temp))
	   'OK
	   )
	  (dfprint* (funcall dfprint* temp) 'OK)
	  (t (prettyprint temp) 'OK)
	  )))

(flag '(dskin) 'ignore)

(off fast-integers)
