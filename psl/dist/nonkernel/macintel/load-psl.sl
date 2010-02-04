%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:LOAD-PSL.SL
% Description:  Load in the files comprising BARE-PSL
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      11-May-84
% Modified:     20-Jun-84 13:29:01
% Mode:         Lisp
% Package:
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
%
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
%   "copying-gc.b"
    "static-gc.b"
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

