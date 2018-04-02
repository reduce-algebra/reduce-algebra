%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:BINDING.SL 
% Title:        Primitives to support Lambda binding 
% Author:       Eric Benson 
% Created:      18 August 1981 
% Modified:     23-May-84 10:30:23 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
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
% 31-Jan-1990 (Winfried Neun)
% added set-bndstk-size feature
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

(global '(bndstksize))

(setq bndstksize  2000)

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
                        (wplus2 2 (quotient (difference bndstkptr bndstk)
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
