%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:DUMPLISP.SL
% Description:  Dump running lisp to an a.out format file.
% Author:       RAM, HP/FSD
% Created:      27-Feb-84
% Modified:     14-Jan-85 09:10:20 (Vicki O'Day)
% Status:       Open Source: BSD License
% Package:
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
% 31-Aug-88 (Julian Padget)
%  Changed second "fluid" call to "global" since there was no need of former.

(fluid '(symbolfilename* gcknt* gctime* ))

(global '(nextbps heaplast heapupperbound oldheapupperbound stacklowerbound))

(compiletime (flag '(dumplispaux ) 'internalfunction))

(de dumplisp (filename)
  (prog (savedstacklowerbound unexecresult savedunixargs x28 maxi)
     (setq maxi (wtimes2 3 maxsymbols))
        (setq x28 28)
        (unless (stringp filename)
          (stderror "Dumplisp requires a filename argument"))

    (setq mainstartinitialize t)
    (compactheap)    
    (setq savedstacklowerbound stacklowerbound)
    (setq savedunixargs unixargs*)    % Force each new system to get
    (&&symcopy old_symval symval)
    (&&symcopy old_symfnc symfnc)
    (setq mainstartinitialize t)
    (setq unixargs* nil)              % its own args
        % must be 0 for a new file
        (setq gcknt* 0 gctime* 0)
        (setq unexecresult (binaryopenwrite (bldmsg "%w.img" filename)))
        (when (eq unexecresult 0) (error 234 "Unable to open image file")
                                (return nil))
        (setq heaplastsave heaplast)
        
        (binarywriteblock unexecresult (datetag) 8)
        (binarywrite unexecresult (wtimes2 maxi addressingunitsperitem))
        (binarywrite unexecresult
                (Wplus2 (wdifference heaplast heaplowerbound) 12))
        (binarywrite unexecresult 136048)
        (binarywrite unexecresult (wdifference nextbps bpslowerbound))
        (binarywrite unexecresult lastbps)
        (binarywrite unexecresult (wdifference (wplus2 bpslowerbound (unexec))
                                        lastbps))
        (binarywrite unexecresult heaplowerbound)
        (binarywriteblock unexecresult SYMNAM maxsymbols)
        (binarywriteblock unexecresult SYMGET maxsymbols)
        (binarywriteblock unexecresult SYMVAL maxi)
        (binarywriteblock unexecresult heaplowerbound
                (wshift (wplus2 (wdifference heaplast heaplowerbound) 12) -2))
        (binarywriteblock unexecresult hashtable 34012)
        (binarywriteblock unexecresult bpslowerbound
                (wquotient (wdifference nextbps bpslowerbound) 4))
        (binarywriteblock unexecresult lastbps
           (wquotient (wdifference (wplus2 bpslowerbound (unexec))
                        lastbps) 4))
        (binaryclose unexecresult)
        (setq stacklowerbound savedstacklowerbound)
))

%% End of File.
