%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 10-Dec 90   (Winfried Neun)
%  Adapted for IBM Rs 6000
% 05-Feb-1987 (Leigh Stoller & Harold Carr)
%  Removed load of vax-environ from pxnk-files list.
% 11-Dec-1986 (Tim Mueller)
%  Removed call to loader-main at the end of the file since loader-main
%  is called in main-start after loading the kernel.
% Tue Oct  8 05:56:55 1985 (Russ Fish)
%  Removed hardwired path to $pnkl from filenames, since the make-bare-psl
%  script cd's to $pnkl before starting bpsl.
% 16-Dec-84 08:30 (Brian Beach)
%  Added VAX-ENVIRONMENT. Removed CHAR-MACRO.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(on fast-integers)

(de setlinebuf() nil)

%(de vvm_cflush () (for (from i 0 100000 1)
%	 (do (wputv bpslowerbound i (wgetv bpslowerbound i)))))

(de ieee_handler () nil)
(fluid '(bootstrap-files pnk-files pxnk-files error-files fluid-reg-vector
         stackupperbound))

(de loader-main ()
  (suck-in-files bootstrap-files)
  (suck-in-files pnk-files)
  (suck-in-files pxnk-files)
  (suck-in-files error-files)
  (suck-in "putd-getd.b")
  (suck-in "ibmrs-nk-spec.b")
  (console-newline)
  (setf $eof$ '!)             % Must find the correct place to do this.

  (setq bootstrap-files nil
        pnk-files nil
        pxnk-files nil
        error-files nil)
  (pre-main)
  )

(de suck-in-files (file-list)
  (for (in f file-list)
       (do
    %(unixputn f) (console-print-string f)(console-newline) 
(when (stringp f)	(suck-in f))
    ))
  )

(de suck-in (file-name)
  (console-print-string "loading ")
  (console-print-string file-name)
  (console-print-string " to ")
  (unixputn nextbps)
  (console-newline)
  (faslin file-name)
  )

(de trace-message (string)
  (console-print-string "TRACE: ")
  (console-print-string string)
  (console-newline)
  )

(setf bootstrap-files
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


(setf pnk-files
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
    "printf.b"
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

(setf pxnk-files
  '(
    "dumplisp.b"
%   "fast-binder.b"
    "funct-prims.b"
    "io-data.b"
    "lap.b"
    "scan-table.b"
    "sys-date.b"
    "sys-extras.b"
    "sys-faslin.b"
  %  "sys-faslout.b"
    "sys-gc.b"
    "sys-io.b"
    "timc.b"
    "trap.b"
    "wfloat.b"
    "write-float.b"
    ))


(setf error-files
  '(
    "error-eset.b"
    "error-hand.b"
    "io-errors.b"
    "type-error.b"
    ))

(de noniderror (u v)
(unixputn u)(console-newline)
(unixputn v)(console-newline)
(console-print-string (id2string v))
(trace-message 'a)
)

(off fast-integers)
