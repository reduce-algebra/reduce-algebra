%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:DUMPLISP.SL
% Description:  Dump running lisp to an a.out format file.
% Author:       RAM, HP/FSD
% Created:      27-Feb-84
% Modified:     14-Jan-85 09:10:20 (Vicki O'Day)
% Package:
%
% (c) Copyright 1987, University of Utah, all rights reserved.
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
  (dumplispaux filename nextbps heaplast))

(de dumplispaux (filename data-start bss-start)
  (prog (savedstacklowerbound unexecresult savedunixargs x28)
        (setq x28 28)
        (unless (stringp filename)
          (stderror "Dumplisp requires a filename argument"))
        (reclaim)
    (if (unboundp 'gcarraylowerbound)
      (if (wgreaterp heapupperbound oldheapupperbound)
        (reclaim)))
        (setq savedstacklowerbound stacklowerbound)
    (setq savedunixargs unixargs*)    % Force each new system to get
    (setq unixargs* nil)              % its own args
        % must be 0 for a new file
        (setq gcknt* 0 gctime* 0)
        (setq unexecresult (binaryopenwrite (bldmsg "%w.img" filename)))
        (setq heaplastsave heaplast)
        
        (binarywriteblock unexecresult (datetag) 8)
        (binarywrite unexecresult 300000)
        (binarywrite unexecresult
                (Wplus2 (wdifference heaplast heaplowerbound) 12))
        (binarywrite unexecresult 36040)
        (binarywrite unexecresult (wdifference nextbps bpslowerbound))
        (binarywrite unexecresult lastbps)
        (binarywrite unexecresult (wdifference (wplus2 bpslowerbound (unexec))
                                        lastbps))
        (binarywrite unexecresult heaplowerbound)
        (binarywriteblock unexecresult SYMVAL 75000)
        (binarywriteblock unexecresult heaplowerbound
                (wshift (wplus2 (wdifference heaplast heaplowerbound) 12) -2))
        (binarywriteblock unexecresult hashtable 9010)
        (binarywriteblock unexecresult bpslowerbound
                (wquotient (wdifference nextbps bpslowerbound) 4))
        (binarywriteblock unexecresult lastbps
           (wquotient (wdifference (wplus2 bpslowerbound (unexec))
                        lastbps) 4))
        (binaryclose unexecresult)
        (setq stacklowerbound savedstacklowerbound)
))

%% End of File.
