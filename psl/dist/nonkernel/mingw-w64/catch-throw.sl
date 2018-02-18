%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:CATCH-THROW.SL 
% Title:        Common Lisp dynamic non-local exits 
% Author:       Eric Benson 
% Created:      12 October 1982 
% Modified:     22-Mar-84 09:39:42 (Brian Beach) 
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 22 Oct 1984 2101-PDT (Brian Beach)
%  At the suggestion of Alan Snyder, changed throw so that throwing to
%  an uncaught tag does not produce a continuable error.  It is thought that
%  a throw should NEVER return.  Also, removed internal functions.
% 22-Mar-84 09:39:39 (Brian Beach)
%  Fixed constants.
% 01-Dec-83 14:22:26 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(fluid '(throwsignal* throwtag*))

(global '(emsg*))

(dm catch-all (u)
  ((lambda (fn forms)
           (list (list 'lambda '(&&value&&)
                       (list 'cond
                        (list 'throwsignal*
                         (list 'apply fn '(list throwtag* &&value&&)))
                        '(t &&value&&)))
                 (cons 'catch (cons nil forms))))
   (cadr u)
   (cddr u)))

(dm unwind-all (u)
  ((lambda (fn forms)
           (list (list 'lambda '(&&value&&)
                       (list 'apply fn
                        '(list (and throwsignal* throwtag*) &&value&&)))
                 (cons 'catch (cons nil forms))))
   (cadr u)
   (cddr u)))

(dm unwind-protect (u)
  ((lambda (protected_form cleanup_forms)
           (list (list 'lambda '(&&value&&)
                       (cons
                        (list 'lambda '(&&thrown&& &&tag&&)
                         (cons 'progn cleanup_forms)
                         '(cond (&&thrown&& (!%throw &&tag&& &&value&&))
                                (t &&value&&)))
                        '(throwsignal* throwtag*)))
                 (list 'catch ''$unwind-protect$ protected_form)))
   (cadr u)
   (cddr u)))

(off r2i)

% This funny definition is due to a PA1FN for CATCH
(df catch (u)
  ((lambda (tag forms)
           (catch (eval tag) (evprogn forms)))
   (car u)
   (cdr u)))

(on r2i)

% Temporary compatibility package.
(dm *catch (u)
  (cons 'catch (cdr u)))

(de *throw (x y)
  (throw x y))

% Size is in terms of number of frames
(define-constant catchstacksize 4000)

(fluid '(catchstack))

(fluid '(catchstackptr))

(setq catchstackptr (loc (wgetv catchstack 0)))

(compiletime
 (ds catchpop ()
   (setq catchstackptr (loc (wgetv catchstackptr -4)))
   ))

(compiletime
 (ds catchstackdecrement (x) 
   (loc (wgetv x -4))
   ))

(compiletime
 % Rather large for a smacro, used only from CatchSetupAux /csp
 % Tests structured for fast usual execution /csp
 % Random constant 5 for "reserve" catch stack frames /csp
 (ds catchpush (tag pc sp env)
   (setq catchstackptr (loc (wgetv catchstackptr 4))) 
   (when (wgeq catchstackptr
	       (loc (wgetv catchstack 
			   (wtimes2 (wdifference catchstacksize 5) 4))))
     (when (weq catchstackptr
		(loc (wgetv catchstack
			    (wtimes2 (wdifference catchstacksize 5) 4))))
       (continuableerror 99 "Catch-throw stack overflow (warning)" nil))
     (when (wgeq catchstackptr
		 (loc (wgetv catchstack (wtimes2 catchstacksize 4))))
       (setf emsg* "Catch stack overflow")
       (reset)))
   (setf (wgetv catchstackptr 0) tag)
   (setf (wgetv catchstackptr 1) pc)
   (setf (wgetv catchstackptr 2) sp)
   (setf (wgetv catchstackptr 3) env)
   ))

(compiletime
 (progn
  (ds catchtoptag nil (wgetv catchstackptr 0))
  (ds catchtagat (x) (wgetv x 0))
  (ds catchtoppc nil (wgetv catchstackptr 1))
  (ds catchtopsp nil (wgetv catchstackptr 2))
  (ds catchtopenv nil (wgetv catchstackptr 3))
  ))

% CatchSetup puts the return address in reg 2, the stack pointer in reg 3
% and calls CatchSetupAux
(if_system sel
(lap '((*entry catchsetup expr 1) % CatchSetup(Tag)
       (*move (reg 0) (reg 2))
       (*move (reg st) (reg 3))
       (*jcall catchsetupaux)))

(lap '((*entry catchsetup expr 1) % CatchSetup(Tag)
       (*move (memory (reg st) (wconst 0)) (reg 2))
       (*move (reg st) (reg 3))
       (*jcall catchsetupaux)))
)

(de catchsetupaux (tag pc sp)
  (prog (previous)
        (setq previous catchstackptr)
        (catchpush tag pc sp (captureenvironment))
        (setf throwsignal* nil)
        (return previous)))

(de !%uncatch (previous)
  (setq catchstackptr previous)
  (setf throwsignal* nil))

(de !%clear-catch-stack ()
  (setq catchstackptr (loc (wgetv catchstack 0))))

(de !%throw (tag value)
  (prog (toptag)
        (setq toptag (catchtoptag))
        (return (if (not (or (null toptag) (weq toptag '$unwind-protect$)
                          (weq tag toptag)))
                  (progn (catchpop)
                         (!%throw tag value))
                  (prog (pc sp)
                        (setq pc (catchtoppc))
                        (setq sp (catchtopsp))
                        (restoreenvironment (catchtopenv))
                        (catchpop)
                        (setf throwsignal* t)
                        (setf throwtag* tag)
                        (return (throwaux value pc sp)))))))

(if_system sel
(lap '((*entry throwaux expr 3)
       (*move (reg 3) (reg st))
       (*move (indexed (reg st) 1) (reg code_base))
       (*jump (indexed (reg 2) 0))))

(lap '((*entry throwaux expr 3)
       (*move (reg 3) (reg st))
       (*move (reg 2) (memory (reg st) (wconst 0)))
       (*exit 0)))
)

(de throw (tag value)
  (findcatchmarkandthrow tag value catchstackptr))

% Throw to $Error$ that doesn't have a catch can't cause a normal error
% else an infinite loop will result.  Changed to use FatalError instead.
(de findcatchmarkandthrow (tag value p)
  (cond ((weq p (loc (wgetv catchstack 0)))
	 (if (not (weq tag '$error$))
           (stderror (bldmsg "Catch tag %r not found in Throw" tag))
           (fatalerror "Error not within ErrorSet")))
        ((or (null (catchtagat p))
	     (weq tag (catchtagat p)))
         (!%throw tag value))
        (t
	 (findcatchmarkandthrow tag value (catchstackdecrement p)))))

