%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:DUMPLISP.SL
% Description:  Dump running lisp to an a.out format file.
% Author:       RAM, HP/FSD
% Created:      27-Feb-84
% Modified:     14-Jan-85 09:10:20 (Vicki O'Day)
% Status:       Open Source: BSD License
% Mode:         Lisp
% Package:
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
% 31-Aug-88 (Julian Padget)
%  Changed second "fluid" call to "global" since there was no need of former.
% 01-Jun-87 (Leigh Stoller & Harold Carr)
%  Unbundled dumplisp.
% 19-Dec-86 (Leigh Stoller)
%  Unexec now moves the text/data boundary. See bps.c in the $pb directory
%   for a full explanation.
% 09-Dec-86 (Leigh Stoller)
%  Removed calls to expand_file_name and put them into c-code. Problems with
%   malloc. Commentted out seconf reclaim calls for copying-gc. This needs to
%   be looked at. Should be an easier way to switch.
% 24-Nov-86 (Leigh Stoller)
%  Added calls to expand_file_name so that ~ and $ variables can be used in
%   .sl scripts to build bare-psl.
% 28-Dec-84 (Vicki O'Day)
%  Decided not to use nextbps; we may want to use shared Nmode
%  executables, and this would be very dangerous with some bps
%  in text area.
% 17-Oct-84 12:18:31 (RAM)
%  Now use NEXTBPS and HEAPLAST.  This works now that setupbpsandheap does
%  an initial malloc and free for some scratch space for library calls.
% 27-Feb-84 16:11:36 (RAM)
%  Print error messages from here, not from the foreign function unexec.
%  Don't call unexec with NEXTBPS and HEAPLAST (use 0's).  There seem to be
%  bugs when these are used.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(fluid '(symbolfilename* gcknt* gctime* ))
 
(setq symbolfilename* "$pxk/bpsl")

(global '(nextbps heaplast heapupperbound oldheapupperbound stacklowerbound))
 
(compiletime (flag '(dumplispaux ) 'internalfunction))

(de dumplisp (filename)
%  (move-regs-to-mem)
  (dumplispaux filename nextbps heaplast))
 
(de dumplispaux (filename data-start bss-start)
  (prog (savedstacklowerbound unexecresult savedunixargs x28
         bpslowerbound bpssize bpscontrol)
        (setq bpscontrol (unexec)) % read vector from C routines
        (setq bpslowerbound (getmem bpscontrol))
        (setq bpssize (getmem (wplus2 bpscontrol addressingunitsperitem)))
        (setq x28 28)
        (unless (stringp filename)
          (stderror "Dumplisp requires a filename argument"))
        (reclaim)
    (if (greaterp oldheaplowerbound 0)
      (progn
         (reclaim)
         (when (greaterp heapupperbound oldheapupperbound) 
               (reclaim)))
) %%	 (compactheap))
    (setq savedunixargs unixargs*)    % Force each new system to get
    (setq unixargs* nil)              % its own args
        % must be 0 for a new file
        (setq gcknt* 0 gctime* 0)
        (setq unexecresult (binaryopenwrite (bldmsg "%w.img" filename)))
	(binarywriteblock unexecresult bpscontrol 2)
        (binarywrite unexecresult (times 8 5 maxsymbols))
        (binarywrite unexecresult (wplus2 (wdifference heaplast heaplowerbound) 24))
        (binarywrite unexecresult (times (quotient (plus2 3 hash-table-size) 4) 16))
        (binarywrite unexecresult bpssize)
        (binarywriteblock unexecresult SYMVAL (times 5 maxsymbols))
        (binarywriteblock unexecresult heaplowerbound 
		(wshift (wplus2 (wdifference heaplast heaplowerbound) 24) -3))
        (binarywriteblock unexecresult hashtable
                         (times 2 (quotient (plus2 3 hash-table-size) 4)))
        (binarywriteblock unexecresult bpslowerbound 
                (wshift bpssize -3)) 
        (binaryclose unexecresult)
))

%% End of File.
 
 
 
