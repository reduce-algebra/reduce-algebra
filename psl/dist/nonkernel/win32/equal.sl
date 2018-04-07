%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EQUAL.SL 
% Title:        EQUAL, EQN and friends 
% Author:       Eric Benson 
% Created:      19 August 1981 
% Modified:     18-Jul-84 08:28:41 (Brian Beach) 
% Status:       Open Source: BSD License
% Package:      Kernel 
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
% 04-Sep-91 (Herbert Melenk)
%  assembly version without alloc
% 15-Oct-90 (Russ Fish)
% Yanked out the obsolete IRIS code in equal and eqn.
% 26-May-87 (Harold Carr & Leigh Stoller)
%  Made equal and eqn aware of IEEE negative zero (via zerop).
% 24-Apr-87 (Leigh Stoller)
%  Added if-system for IRIS floating point compares in equal and eqn.
% 18-Jul-84 08:26:37 (Brian Beach)
%  Fixed bug in equal comparing bytes.
% 10-May-84 14:15:24 (Brian Beach)
%  <PSL.KERNEL>EQUAL.RED.3,  6-Feb-84 10:28:57, Edit by KESSLER
%  As per Hearn - EQUAL gives incorrect results for BIGNUMS - Changed
%  wordsequal and halfwordsequal.  Wasn't checking the last element.
%  
% 22-Mar-84 11:22:01 (Brian Beach)
%  Fixed constants, tag names.
% 01-Dec-83 14:37:31 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
  (flag '(halfwordsequal vectorequal wordsequal equal-hardcase
          pair-equal) 'internalfunction))

(compiletime (load if-system))

(de eqn (u v)
  % Eq or numeric equality.
  (or (weq u v)
      (case (tag u)
	((floatnum-tag)
	 (or (and (floatp v)
		  (weq (floathighorder (fltinf u))
		       (floathighorder (fltinf v)))
			     (weq (floatloworder (fltinf u))
				  (floatloworder (fltinf v)))
	     )
	     (and (zerop u)
		  (zerop v))))
	((fixnum-tag)
	 (and (fixnp v) (weq (fixval (fixinf u)) (fixval (fixinf v)))))
	((bignum-tag)
	 (and (bigp v) (wordsequal u v))) (nil nil))))

(compiletime (setq &fillframeholes nil))

(lap '((*entry equal expr 2)
       (*alloc 0)
       (*jumpeq (label yes) (reg 1)(reg 2))
       (*move (reg 1)(reg 3))
       (*move (reg 2)(reg 4))
       (*field (reg 3)(reg 3) (wconst tagstartingbit) (wconst tagbitlength))
       (*field (reg 4)(reg 4) (wconst tagstartingbit) (wconst tagbitlength))
       (*jumpnoteq (label no) (reg 3)(reg 4))
       (*jumpeq    (label no) (reg 4)(wconst id-tag))
       (*jumpeq    (label no) (reg 4)(wconst posint-tag))
       (*jumpeq    (label no) (reg 4)(wconst negint-tag))
       (*jumpnoteq (label hardcase) (reg 4) (wconst pair-tag))
             % both are pairs now
       (*linke 0 pair-equal expr 2)
    hardcase
       (*linke 0 equal-hardcase expr 3)
    yes
       (*move (quote T)(reg 1))
       (*exit 0)
    no
       (*move (quote nil)(reg 1))
    ex
       (*exit 0)))

(de pair-equal(u v)
   (prog()
  loop
     (setq u (inf u))
     (setq v (inf v))
     (when (not (equal (wgetv u 0)(wgetv v 0)))
           (return nil))
     (setq u (wgetv u 1))
     (setq v (wgetv v 1))
     (when (eq u v) (return t))
     (if (pairp u)
         (if (pairp v)
             (go loop)
             (return nil))
         (return (equal u v)))))

(de equal-hardcase (u v tg)
  % Structural equality for atoms other than ID's
  % here we kow that the items are not eq, but tags are equal
      (case tg
	((evector-tag) (evectorequal u v))
	((vector-tag)  (vectorequal u v))
	((string-tag)  (stringequal u v))
	((bytes-tag) (stringequal u v))
	((floatnum-tag)
	 (or (and 
		  (weq (floathighorder (fltinf u))
		       (floathighorder (fltinf v)))
		  (weq (floatloworder (fltinf u))
		       (floatloworder (fltinf v)))
	     )
	     (and (zerop u) (zerop v))))
	((fixnum-tag)
	      (weq (fixval (fixinf u)) (fixval (fixinf v))))
	((bignum-tag) (wordsequal u v))
	((words-tag)  (wordsequal u v))
	((halfwords-tag) (halfwordsequal u v))
	(nil nil)))

(de eqstr (u v)
  % Eq or string equality.
  (or (weq u v)
      (and (stringp u) (stringp v) (stringequal u v))))

(de stringequal (u v)
  % EqStr without typechecking or eq.
  (prog (len i)
        (setq u (strinf u))
        (setq v (strinf v))
        (setq len (strlen u))
        (when (wneq len (strlen v))
          (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i len)
          (return t))
        (when (wneq (strbyt u i) (strbyt v i))
          (return nil))
        (setq i (wplus2 i 1))
        (go loop)))

(de wordsequal (u v)
  (prog (s1 i)
        (setq u (wrdinf u))
        (setq v (wrdinf v))
        (unless (weq (setq s1 (wrdlen u)) (wrdlen v))
          (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i s1)
          (return t))
        (unless (weq (wrditm u i) (wrditm v i))
          (return nil))
        (setq i (wplus2 i 1))
        (go loop)))

(de halfwordsequal (u v)
  (prog (s1 i)
        (setq u (halfwordinf u))
        (setq v (halfwordinf v))
        (unless (wgreaterp (setq s1 (halfwordlen u)) (halfwordlen v))
          (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i s1)
          (return t))
        (unless (weq (halfworditm u i) (halfworditm v i))
          (return nil))
        (setq i (wplus2 i 1))
        (go loop)))

(de vectorequal (u v)
  % Vector equality without type check
  (prog (len i)
        (setq u (vecinf u))
        (setq v (vecinf v))
        (setq len (veclen u))
        (when (wneq len (veclen v))
          (return nil))
        (setq i 0)
   loop
        (when (wgreaterp i len)
          (return t))
        (unless (equal (vecitm u i) (vecitm v i))
          (return nil))
        (setq i (wplus2 i 1))
        (go loop)))

(de evectorequal (u v)
  % E-Vector equality without type check
  (prog (handler)
        (when (and (not (funboundp 'object-get-handler-quietly))
                   (setq handler (object-get-handler-quietly u 'equal)))
          (return (apply handler (list u v))))))


