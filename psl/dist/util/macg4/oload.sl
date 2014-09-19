%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:OLOAD.SL
% Description:  Load Unix object files into running PSL.
% Author:       Brian Beach
% Created:      May 3, 1982
% Modified:     May 23, 1988 (Chris Burdorf)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 23-May-1988 (Chris Burdorf)
%  Newforeign calls makeforeigncode instead of makefcode to simplify
%  foreign function interface for sparc.
% 06-Feb-87 8:14 (Harold Carr)
%  Changed call (gtbps nil) to (free-bps).
%  Changed oload prog variables NEXTBPS and LASTBPS to OLOAD-NEXTBPS
%  and OLOAD-LASTBPS, since in 3.4 they are fluids (in 3.2 they were
%  built into the kernel, and the prog binding (to nil) interferes with
%  gtbps.
%  Put call to makefcode back in NEWFOREIGNFN so that the addresses get
%  installed, (why would anyone remove it?).
% 27-Oct-84 8:14 (Brian Beach)
%  Updated for micro-kernel:  Removed load of SYSLISP, changed (ON SYSLISP)
%  to (ON FAST-INTEGERS).
% 13-Jan-84 10:23:25 (Brian Beach)
%  Added standard header.  Translated from Rlisp to Lisp.
%
%   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Symbols passed back from the oload script in .oload.syms.sl .
(fluid '(oload_header_size oload_text_segment_size oload_text_gap_size 
         oload_text_origin oload_text_size oload_data_gap_size 
         oload_data_origin oload_data_seg_size oload_data_size))

(ds wordcount (bytes) % Convert words to bytes.
    (quotient (plus bytes (difference charactersperword 1)) 
              charactersperword))

(fluid '(!*chattyoload))

% Controls debug printing.
(setq !*chattyoload nil)

% Off by default now.
% oload - invokes the loader, making a number of .oload.* files on the
% connected directory, then pulls a successful result into the BPS area of
% the PSL.  Argument is a string containing a list of one or more .o and
% .a filename paths and flags to "ld", such as -l flags specifying libraries
% to search.  If the argument string is NIL, the oload script is
% skipped, and it is assumed that you are going to perform the same load
% over again.  This requires that the BPS and WARRRAY base addresses are
% the same as when the original oload was done.
%
% Return value is NIL if the oload failed, T if it worked.
%
(de oload (files)
  (prog (oload-nextbps oload-lastbps
         cmd chnl textsz datasegsz datasz bssbgn bssend)
        (setq oload-nextbps (land (plus (gtbps 0) 3) -4))
        % OLOAD-NEXTBPS, up to a word boundary.
        (setq oload-lastbps (land (gtwarray 0) -4))
        % OLOAD-LASTBPS, down to a word boundary.
        (when !*chattyoload
          (printf " NextBPS %p(%p), LastBPS %p(%p)%n" oload-nextbps (gtbps 0) 
                  oload-lastbps (gtwarray 0)))
        % Load files into an a.out file.
        (when files
          (setq cmd 
                (concat % Avoid terpri in bldMsg if long Files string.
                        (bldmsg "oload %w %p %p " symbolfilename!* oload-nextbps 
                         oload-lastbps)
                        files))
          (print cmd)
          (system cmd))
        % Get sizes and check for successful completion.
        (lapin ".oload.size.sl")
        (when (and (eq oload_text_size 0) (eq oload_data_seg_size 0))
          (printf "oload: nothing to load.%n")
          (return nil))
        % Do some checking rather than blindly repeating a load.
        (setq bssend (plus oload_data_origin oload_data_seg_size))
        (when (and (not files) 
                   (or (neq oload_text_origin oload-nextbps) 
                       (neq bssend oload-lastbps)))
          (printf "oload: can't repeat load, file addresses don't match core.%n")
          (printf "  Start (file %p, core %p), end (file %p, core %p).%n" 
                  oload_text_origin oload-nextbps bssend oload-lastbps)
          (return nil))
        % Open the a.out file.
        (setq chnl (binaryopenread ".oload.out"))
        % Position incremental load file past the header and text gap.
        (binarypositionfile chnl 
         (plus oload_header_size oload_text_gap_size))
        % Allocate storage space and read the text.
        (when !*chattyoload
          (printf "bps %p, NextBPS %p, LastBPS %p%n" (free-bps) (gtbps 0) 
                  (gtwarray 0)))
        (gtbps (plus 1 (setq textsz (wordcount oload_text_size))))
        (when !*chattyoload
          (printf "text %pw %pb %pa%n" textsz (times textsz 4) 
                  oload_text_origin)
          (printf "bps %pw, NextBPS %p, LastBPS %p%n" (free-bps) 
                  (gtbps 0) (gtwarray 0)))
        (binaryreadblock chnl oload_text_origin textsz)
        % Position past the whole text segment and the gap at the start of data.
        (binarypositionfile chnl 
         (plus oload_header_size oload_text_segment_size 
               oload_data_gap_size))
        % Allocate storage space for data and bss.
        (when !*chattyoload
          (printf "bps %pw%n" (free-bps)))
        (setq datasegsz (wordcount oload_data_seg_size))
        % Data + Bss
        (when !*chattyoload
          (printf "data segment  %pw %pb%n" datasegsz (times datasegsz 4)))
        (gtwarray (plus 1 datasegsz))
        % Allocate for data and bss.
        (when !*chattyoload
          (printf "bps %pw, NextBPS %p, LastBPS %p%n" (free-bps) 
                  (gtbps 0) (gtwarray 0)))
        % Clear bss to zeros and read data.
        (setq bssbgn (plus oload_data_origin oload_data_size))
        (when !*chattyoload
          (printf "bss start %p, end %p%n" bssbgn bssend))
        (clearblock bssbgn bssend)
        (setq datasz (wordcount oload_data_size))
        % Initialized data.
        (when !*chattyoload
          (printf "data init  %pw %pb %pa%n" datasz (times datasz 4) 
                  oload_data_origin))
        (binaryreadblock chnl oload_data_origin datasz)
        % Load symbol definitions for the code and data just loaded.
        (lapin ".oload.syms.sl")
        % Arrange that the symbol table for UnExec will come from the load file.
        (setq symbolfilename!* ".oload.out")
        (return t)))

% It worked.
% ClearBlock - Clears allocated storage (for the BSS part of the oloaded pgm.)

(on fast-integers)

(de clearblock (bgnaddr endaddr)
  (for (from i bgnaddr (wdifference endaddr 4) 4) 
        (do (setf (getmem i) 0))))

(off fast-integers)

% NewForeignFn - Called by .oload.syms.sl to define function entries.
(de newforeignfn (name loc)
  (put name 'foreignentry loc)
  (makeforeigncode name (mkcode loc))
  (flag1 name 'foreignfunction))

% NewForeignData - Called by .oload.syms.sl to define data entities.
(de newforeigndata (name loc sz)
  (put name 'foreigndata (cons loc sz)))

% End of file.


