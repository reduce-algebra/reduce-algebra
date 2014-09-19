%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:BINDING.SL 
% Title:        Primitives to support Lambda binding 
% Author:       Eric Benson 
% Created:      18 August 1981 
% Modified:     23-May-84 10:30:23 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1981, University of Utah
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 31-Aug-88 (Julian Padget)
%  Bnd... declarations changed from fluid to global.
% 06-Mar-84 17:11:53 (Jim Ambras/CRC)
%  Uppded binding stack size from 4000 to 8000 for REDUCE.
% 02-Mar-84 09:29:17 (Jim Ambras/CRC)
%  Corrected file header.
% 16-Jan-84 14:11:00 (Tim Tillson)
%  Upped binding stack size from 2000 to 4000 for unknown (and possibly buggy?)
%  reasons to build NMODE successfully.
% 01-Dec-83 14:16:18 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(define-constant bndstksize 2000)

(global '(bndstk bndstkptr bndstkupperbound bndstklowerbound))

% Binding stack is initialized in the kernel.
%
%(setq bndstkptr (loc (wgetv bndstk 0)))%
%
%(setq bndstkupperbound (loc (wgetv bndstk (wdifference bndstksize 1))))
%
%(setq bndstklowerbound (loc (wgetv bndstk 0)))

% Only the macros BndStkID, BndStkVal and AdjustBndStkPtr will be used
% to access or modify the binding stack and pointer.

(de bstackoverflow ()
  (channelprin2 errout* "***** Binding stack overflow, restarting...")
  (channelwritechar errout* (char eol))
  (reset))

(de bstackunderflow ()
  (channelprin2 errout* "***** Binding stack underflow, restarting...")
  (channelwritechar errout* (char eol))
  (reset))

(de captureenvironment ()
  bndstkptr
  )

(de restoreenvironment (ptr)
  % Restore old bindings
  (if (wlessp ptr bndstklowerbound)
    (bstackunderflow)
    (while (wgreaterp bndstkptr ptr)
      (setf (symval (inf (bndstkid bndstkptr))) (bndstkval bndstkptr))
      (setq bndstkptr (adjustbndstkptr bndstkptr -1)))))

(de clearbindings ()
  %. Restore bindings to top level
  (progn (restoreenvironment bndstklowerbound)
         (!%clear-catch-stack)))

(de unbindn (n)
  %. Support for Lambda and Prog interp
  (restoreenvironment (adjustbndstkptr bndstkptr (wminus (intinf n)))))

(de lbind1 (idname valuetobind)
  %. Support for Lambda
  (cond ((not (idp idname)) (noniderror idname "binding"))
        ((or (null idname) (weq idname 't))
         (stderror '"T and NIL cannot be rebound"))
        (t (setq bndstkptr (adjustbndstkptr bndstkptr 1)) (if (wgreaterp
                                                               bndstkptr
                                                               bndstkupperbound)
             (bstackoverflow)
             (progn (setq idname (idinf idname))
                    (setf (bndstkid bndstkptr) idname)
                    (setf (bndstkval bndstkptr) (symval idname))
                    (setf (symval idname) valuetobind))))))

(de pbind1 (idname)
  %. Support for PROG
  (lbind1 idname nil))

(compiletime (progn (remprop 'bndstksize 'constant?)
                    (fluid '(bndstksize))
                    (flag '(update-catchstk) 'internalfunction)
                    (setq *syslisp t)))

(de set-bndstk-size (newsize)
  (prog (diff from to)
       (setq diff (wdifference newsize bndstksize))
       (cond ((wgreaterp diff 0)
                (setq to (gtwarray newsize))
                (setq from bndstk)
                (copywarray to from
                        (wplus2 2 (quotient (wdifference bndstkptr bndstk)
                                               addressingunitsperitem)))
                (setf bndstklowerbound to)
                (setf bndstk           to)
                (setf bndstkupperbound
                     (wplus2 to
                        (wtimes2 addressingunitsperitem (wplus2 -3 newsize)) ))
                (setf bndstkptr (wplus2 to (wdifference bndstkptr from)))
                (update-catchstk (wdifference to from) 3)
                (setq bndstksize newsize)
                (return newsize)))))

(de update-catchstk (diff posi)   % if stack or bndstk have been moved
    (prog (actcatch)      % update sp entries by diff
          (setq actcatch catchstackptr)
    lupe  (setf (wgetv actcatch posi) (wplus2 (wgetv actcatch posi)
                                               diff))
          (setq actcatch
            (wdifference actcatch (times2 4 addressingunitsperitem)))
          (cond ((wgreaterp actcatch catchstack ) (go lupe)))
          (return nil)
)   )

