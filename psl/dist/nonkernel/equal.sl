%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EQUAL.SL 
% Title:        EQUAL, EQN and friends 
% Author:       Eric Benson 
% Created:      19 August 1981 
% Modified:     18-Jul-84 08:28:41 (Brian Beach) 
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
  (flag '(halfwordsequal vectorequal wordsequal) 'internalfunction))

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

(de equal (u v)
  % Structural equality
  (or (weq u v)
      (case (tag u)
	((evector-tag) (evectorequal u v))
	((vector-tag)  (and (vectorp v) (vectorequal u v)))
	((string-tag)
	 (and (stringp v) (stringequal u v)))
	((bytes-tag)
	 (and (bytesp v) (stringequal u v)))
	((pair-tag)
	 (and (pairp v)
	      (equal (car u) (car v))
	      (equal (cdr u) (cdr v))))
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
	 (and (fixnp v)
	      (weq (fixval (fixinf u)) (fixval (fixinf v)))))
	((bignum-tag) (and (bigp v) (wordsequal u v)))
	((words-tag) (and (wrdsp v) (wordsequal u v)))
	((halfwords-tag) (and (halfwordsp v) (halfwordsequal u v)))
	(nil nil))))

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


