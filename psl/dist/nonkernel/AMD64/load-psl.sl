%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:LOAD-PSL.SL
% Description:  Load in the files comprising BARE-PSL
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      11-May-84
% Modified:     20-Jun-84 13:29:01
% Mode:         Lisp
% Package:
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 24-Oct-88 (Tony Hearn)
%  Reorganized file to remove fluids and superfluous functions.
% Tue Oct  8 05:56:55 1985 (Russ Fish)
%  Removed hardwired path to $pnkl from filenames, since the make-bare-psl
%  script cd's to $pnkl before starting bpsl.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 
(on fast-integers)
 
(de loader-main ()
  (suck-in-files           % bootstrap files
  '(
    "constants.b"
    "compsupport.b"
    "cons-mkvect.b"
    "prop-list.b"
    "symbol-vals.b"
    "type-conver.b"
    "easy-sl.b"
    "funct-prims.b"
    "fluid-globl.b"
    ))
  (suck-in-files                % pnk files
  '(
    "allocators.b"
    "apply-lap.b"
    "arithmetic.b"
    "autoload.b"
    "autoload-tr.b"
    "backtrace.b"
    "base-io.b"
    "binding.b"
    "break.b"
    "carcdr.b"
    "catch-throw.b"
    "char-io.b"
%   "compact-gc.b"
    "cons-mkvect.b"
    "cont-error.b"
    "copiers.b"
    "copying-gc.b"
%    "static-gc.b"
    "defconst.b"
    "def-smacro.b"
    "dskin.b"
    "easy-non-sl.b"
    "equal.b"
    "eval-apply.b"
    "eval-when.b"
    "explode-com.b"
    "io-extens.b"
    "knowntocomp.b"
    "lisp-macros.b"
    "load.b"
    "loop-macros.b"
    "oblist.b"
    "onoff.b"
    "open-close.b"
    "other-io.b"
    "others-sl.b"
    "printers.b"
%   "printf.b"
    "prog-friend.b"
    "rds-wrs.b"
    "read.b"
    "sequence.b"
    "sets.b"
    "string-gen.b"
    "token-scan.b"
    "top-loop.b"
    "vectors.b"
 
    ))
  (suck-in-files           %  pxnk files
  '(
    "dumplisp.b"
%   "fast-binder.b"
    "io-data.b"
    "lap.b"
%   "funct-prims.b"
    "printf.b"
    "scan-table.b"
    "sys-date.b"
    "sys-extras.b"
    "sys-faslin.b"
%   "sys-faslout.b"
    "sys-gc.b"
    "sys-io.b"
    "timc.b"
    "trap.b"
%   "fixup.b"
    "wfloat.b"
    "write-float.b"
    ))
  (suck-in-files            % error files
  '(
    "error-eset.b"
    "error-hand.b"
    "io-errors.b"
    "type-error.b"
    ))
  (suck-in-files '(
    "putd-getd.b"
    "386-ext.b"
  ))
  (setf $eof$ '!)             % Must find the correct place to do this.
  (pre-main)
  )
 
(de suck-in-files (file-list)
  (for (in f file-list)
       (do (console-print-string "loading ")
       (console-print-string f)
       (console-print-string " to ")
       (unixputn nextbps)
       (console-newline)
       (faslin f))))
 
(off fast-integers)

