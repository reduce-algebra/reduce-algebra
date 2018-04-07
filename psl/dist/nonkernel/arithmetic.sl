%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:ARITHMETIC.SL 
% Title:        Arithmetic routines for PSL with new integer tags 
% Author:       Eric Benson 
% Created:      17 January 1982 
% Modified:     
% Package:      Kernel 
% Status:       Open Source: BSD License
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
% 25-Aug-88 (Chris Burdorf and Julian Padget)
%  Added if_system support for SPARC.
% 03-Sep-87 (Leigh Stoller & Harold Carr)
%  Replaced all generic math calls in intlshift with syslisp calls.
% 02-Sep-87 (Leigh Stoller for Russ Fish)
%  Fix Vax IntLShift to be a logical shift instead of an arithmetic shift.
%  Remove IntLShift from the InternalFunction list for access by printers.
% 26-May-87 (Leigh Stoller & Harold Carr)
%  Made floatzerop not depend on eqn so eqn can depend on floatzerop.
% 01-Apr-87 (Leigh Stoller & Harold Carr)
%  Added support for IEEE floating point negitive zero in floatzerop. This
%   change is if_system'ed for the 68000.
% 11-Oct-84 10:54:15 (Brian Beach)
%  Included Mark Swanson change to replace erroneous (wconst id) with 
%  (wconst id-tag) in error message generation.
% 23-Mar-84 13:54:24 (Brian Beach)
%  Moved defarith... to end of file so that the compile can compile it without
%  forward references.  Got rid of STUPIDPARSERFIX, since this is no longer in 
%  Rlisp.
% 26 Jan 1984 0954-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:10:02 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(**neg-zero**))

(compiletime (load sys-macros if-system))

(if_system SPARC
  (define-constant return-address-offset 8)
  (define-constant return-address-offset 0))

(commentoutcode
(compiletime
 (flag '(
	 twoargdispatch twoargdispatch1 twoargerror oneargdispatch
	 oneargdispatch1 oneargpredicatedispatch
	 oneargpredicatedispatch1 oneargerror intadd1
	 intsub1 intplus2 inttimes2 intdifference
	 intquotient intremainder intland intlor
	 intlxor intgreaterp intlessp intminus intminusp
	 intzerop intonep intlnot floatintarg floatadd1
	 floatsub1 floatplus2 floattimes2 floatquotient
	 floatremainder floatdifference floatgreaterp
	 floatlessp floatminus floatminusp floatzerop
	 floatonep staticintfloat floatfix
	 noninteger1error noninteger2error makefixnum
	 bigfloatfix returnfirstarg)
       'internalfunction))
)

(compiletime
 (dm isinum (u)
   (list '(lambda (x)
	    (eq (signedfield x
			     (isub1 infstartingbit)
			     (iadd1 infbitlength))
		x))
	 (second u))
   ))

(define-constant intfunctionentry   0)
(define-constant floatfunctionentry 1)
(define-constant functionnameentry  2)

(de twoargdispatch (firstarg secondarg)
  (twoargdispatch1 firstarg secondarg (tag firstarg) (tag secondarg)))

(if_system sel
(lap '((*entry twoargdispatch1 expr 4)
       (*move (reg 0) (frame 2))
       (*move (reg b1) (frame 0))
       (*jumpnoteq (label notneg1) (reg 3) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 3))
       notneg1
       (*jumpnoteq (label notneg2) (reg 4) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 4))
       notneg2
       (*jumpwgreaterp (label nonnumeric) (reg 3) (wconst floatnum-tag))
       (*jumpwgreaterp (label nonnumeric) (reg 4) (wconst floatnum-tag))
       (*wshift (reg 3) (wconst 2))
       (*wplus2 (reg 4) (reg 3))
       (*jumpon (reg 4) 0 15
                ((label intint) (label intfix) (label temporarynonentry)
                 (label intfloat) (label fixint) (label fixfix)
                 (label temporarynonentry) (label fixfloat)
                 (label temporarynonentry) (label temporarynonentry)
                 (label temporarynonentry) (label temporarynonentry)
                 (label floatint) (label floatfix)
                 (label temporarynonentry) (label floatfloat)))
       temporarynonentry
       (*linke 4 twoargerror expr 0)
       fixint
       (*field (reg 1) (reg 1)
               (wconst infstartingbit) % grab the value for the fixnum
	       (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       (*jump (label intint))
       fixfix
       (*field (reg 1) (reg 1)
	       (wconst infstartingbit)  % grab the value for the fixnum
	       (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       intfix
       (*field (reg 2) (reg 2) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 2) (wconst addressingunitsperitem)) (reg 2))
       intint
       (*move (frame 2) (reg t1))
       (*move (indexed (reg t1) 1) (reg t1))
       (*wshift (reg t1) 2)
       (*move (indexed (reg symfnc_base)(reg t1) 0) (reg code_base))
       (*move (indexed (reg st) 0) (reg 0))
       (*dealloc 4)
       (*jump (indexed (reg code_base) 0))
       fixfloat
       (*field (reg 1) (reg 1) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       intfloat
       (*move (reg 3) (frame 3))
       (*move (reg 2) (frame 1))
       (*call staticintfloat)
       (*move (frame 1) (reg 2))
       (*move (frame 3) (reg 3))
       (*jump (label floatfloat))
       floatfix
       (*field (reg 2) (reg 2) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 2) (wconst addressingunitsperitem)) (reg 2))
       floatint
       (*move (reg 3) (frame 3))
       (*move (reg 1) (frame 1))
       (*move (reg 2) (reg 1))
       (*call staticintfloat)
       (*move (reg 1) (reg 2))
       (*move (frame 1) (reg 1))
       (*move (frame 3) (reg 3))
       % fall into ...
       floatfloat
       (*move (frame 2) (reg t1))
       (*move (indexed (reg t1) (plus2 1 (wconst floatfunctionentry)))
	      (reg t1))
       (*wshift (reg t1) 2)
       (*move (indexed (reg symfnc_base)(reg t1) 0) (reg code_base))
       (*move (indexed (reg st) 0) (reg 0))
       (*dealloc 4)
       (*jump (indexed (reg code_base) 0))


       nonnumeric
       (*linke 4 twoargerror expr 0)))

(lap '((*entry twoargdispatch1 expr 4)
       (*jumpnoteq (label notneg1) (reg 3) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 3))
       notneg1
       (*jumpnoteq (label notneg2) (reg 4) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 4))
       notneg2
       (*jumpwgreaterp (label nonnumeric) (reg 3) (wconst floatnum-tag))
       (*jumpwgreaterp (label nonnumeric) (reg 4) (wconst floatnum-tag))
       (*wshift (reg 3) (wconst 2))
       (*wplus2 (reg 4) (reg 3))
       (*pop (reg 3))
       (*jumpon (reg 4) 0 15
                ((label intint) (label intfix) (label temporarynonentry)
                 (label intfloat) (label fixint) (label fixfix)
                 (label temporarynonentry) (label fixfloat)
                 (label temporarynonentry) (label temporarynonentry)
                 (label temporarynonentry) (label temporarynonentry)
                 (label floatint) (label floatfix)
                 (label temporarynonentry) (label floatfloat)))
       temporarynonentry
       (*jcall twoargerror)
       fixint
       (*field (reg 1) (reg 1)
               (wconst infstartingbit) % grab the value for the fixnum
	       (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       (*jump (memory (memory (reg 3) (wconst return-address-offset))
                      (wconst 0)))
       fixfix
       (*field (reg 1) (reg 1)
	       (wconst infstartingbit)  % grab the value for the fixnum
	       (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       intfix
       (*field (reg 2) (reg 2) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 2) (wconst addressingunitsperitem)) (reg 2))
       intint
       (*jump (memory (memory (reg 3) (wconst return-address-offset))
                      (wconst 0)))
       fixfloat
       (*field (reg 1) (reg 1) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       intfloat
       (*push (reg 3))
       (*push (reg 2))
       (*call staticintfloat)
       (*pop (reg 2))
       (*pop (reg 3))
       (*jump (memory (memory (reg 3)
			      (wconst
                               (plus2 (wconst return-address-offset)
				      (times2 (wconst addressingunitsperitem)
					      (wconst floatfunctionentry)))))
		      (wconst 0)))
       floatfix
       (*field (reg 2) (reg 2) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 2) (wconst addressingunitsperitem)) (reg 2))
       floatint
       (*push (reg 3))
       (*push (reg 1))
       (*move (reg 2) (reg 1))
       (*call staticintfloat)
       (*move (reg 1) (reg 2))
       (*pop (reg 1))
       (*pop (reg 3))
       (*jump (memory (memory (reg 3)
			      (wconst
                               (plus2 (wconst return-address-offset)
				      (times2 (wconst addressingunitsperitem)
					      (wconst floatfunctionentry)))))
		      (wconst 0)))
       floatfloat
       (*jump (memory (memory (reg 3)
			      (wconst
                               (plus2 (wconst return-address-offset)
				      (times2 (wconst addressingunitsperitem)
					      (wconst floatfunctionentry)))))
		      (wconst 0)))
       nonnumeric
       (*pop (reg 3))
       (*jcall twoargerror)))
)

(de twoargerror (firstarg secondarg dispatchtable)
  (continuableerror '99 '"Non-numeric argument in arithmetic"
                    (list (wgetv dispatchtable (wconst functionnameentry))
                     firstarg secondarg)))

(de noninteger2error (firstarg secondarg dispatchtable)
  (continuableerror '99 '"Non-integer argument in arithmetic"
                    (list (wgetv dispatchtable (wconst functionnameentry))
                     firstarg secondarg)))

(de noninteger1error (arg dispatchtable)
  (continuableerror '99 '"Non-integer argument in arithmetic"
                    (list (wgetv dispatchtable (wconst functionnameentry))
                     arg)))

(de oneargdispatch (firstarg)
  (oneargdispatch1 firstarg (tag firstarg)))

(if_system sel
(lap '((*entry oneargdispatch1 expr 2)
       (*move (reg 0) (frame 2))
       (*jumpnoteq (label notneg1) (reg 2) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 2))
       notneg1
       (*jumpon (reg 2) 0 3
                ((label oneint) (label onefix) (label temporarynonentry)
                 (label onefloat)))
       temporarynonentry
       (*linke 4 oneargerror expr 0)
       onefix
       (*field (reg 1) (reg 1) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       oneint
       (*move (frame 2) (reg t1))
       (*move (indexed (reg t1) 1) (reg t1))
       (*wshift (reg t1) 2)
       (*move (indexed (reg symfnc_base)(reg t1) 0) (reg code_base))
       (*move (indexed (reg st) 0) (reg 0))
       (*dealloc 4)
       (*jump (indexed (reg code_base) 0))
       onefloat
       (*move (frame 2) (reg t1))
       (*move (indexed (reg t1) (plus2 1 (wconst floatfunctionentry)))
	      (reg t1))
       (*wshift (reg t1) 2)
       (*move (indexed (reg symfnc_base)(reg t1) 0) (reg code_base))
       (*move (indexed (reg st) 0) (reg 0))
       (*dealloc 4)
       (*jump (indexed (reg code_base) 0))
       ))
(lap '((*entry oneargdispatch1 expr 2)
       (*jumpnoteq (label notneg1) (reg 2) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 2))
       notneg1
       (*pop (reg 3))
       (*jumpon (reg 2) 0 3
                ((label oneint) (label onefix) (label temporarynonentry)
                 (label onefloat)))
       temporarynonentry
       (*jcall oneargerror)
       onefix
       (*field (reg 1) (reg 1) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       oneint
       (*jump (memory (memory (reg 3) (wconst return-address-offset))
                      (wconst 0)))
       onefloat
       (*jump (memory (memory (reg 3)
                       (wconst
			(plus2 (wconst return-address-offset)
                        (times2 (wconst addressingunitsperitem)
                         (wconst floatfunctionentry)))))
                      (wconst 0)))))
)

(de oneargerror (firstarg dummy dispatchtable)
  (continuableerror '99 '"Non-numeric argument in arithmetic"
                    (list (wgetv dispatchtable (wconst functionnameentry))
                     firstarg)))

(de oneargpredicatedispatch (firstarg)
  (oneargpredicatedispatch1 firstarg (tag firstarg)))

(if_system sel
(lap '((*entry oneargpredicatedispatch1 expr 2)
       (*move (reg 0) (frame 2))
       (*jumpnoteq (label notneg1) (reg 2) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 2))
       notneg1
       (*jumpon (reg 2) 0 3
                ((label oneint) (label onefix) (label temporarynonentry)
                 (label onefloat)))
       temporarynonentry
       (*move 'nil (reg 1))
       (*exit 4)
       onefix
       (*field (reg 1) (reg 1) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       oneint
       (*move (frame 2) (reg t1))
       (*move (indexed (reg t1) (plus2 1 (wconst intfunctionentry)))
	      (reg t1))
       (*wshift (reg t1) 2)
       (*move (indexed (reg symfnc_base)(reg t1) 0) (reg code_base))
       (*move (indexed (reg st) 0) (reg 0))
       (*dealloc 4)
       (*jump (indexed (reg code_base) 0))
       onefloat
       (*move (frame 2) (reg t1))
       (*move (indexed (reg t1) (plus2 1 (wconst floatfunctionentry)))
	      (reg t1))
       (*wshift (reg t1) 2)
       (*move (indexed (reg symfnc_base)(reg t1) 0) (reg code_base))
       (*move (indexed (reg st) 0) (reg 0))
       (*dealloc 4)
       (*jump (indexed (reg code_base) 0))
       ))
(lap '((*entry oneargpredicatedispatch1 expr 2)
       (*jumpnoteq (label notneg1) (reg 2) (wconst negint-tag))
       (*move (wconst posint-tag) (reg 2))
       notneg1
       (*pop (reg 3))
       (*jumpon (reg 2) 0 3
                ((label oneint) (label onefix) (label temporarynonentry)
                 (label onefloat)))
       temporarynonentry
       (*move 'nil (reg 1))
       (*exit 0)
       onefix
       (*field (reg 1) (reg 1) (wconst infstartingbit) (wconst infbitlength))
       (*move (memory (reg 1) (wconst addressingunitsperitem)) (reg 1))
       oneint
       (*jump (memory (memory (reg 3) (wconst return-address-offset))
                      (wconst 0)))
       onefloat
       (*jump (memory (memory (reg 3)
			      (wconst
			       (plus2 (wconst return-address-offset)
				      (times2 (wconst addressingunitsperitem)
					      (wconst floatfunctionentry)))))
			      (wconst 0))))
))

(de makefixnum (n)
  (prog (f)
        (setq f (gtfixn))
        (setf (fixval f) n)
        (return (mkfixn f))))

(de bigfloatfix (n)
  (stderror '"Bignums not yet supported"))

(de returnnil ()
  nil)

(de returnfirstarg (arg)
  arg)

(if_system sel
(declare-warray staticfloatbuffer initially (1 1 0 0))
(declare-warray staticfloatbuffer initially (1 0 0))
)

(fluid '(staticfloatitem))
(setq staticfloatitem (mkitem (wconst floatnum-tag) staticfloatbuffer))

(de staticintfloat (arg)
  (*wfloat (loc (wgetv staticfloatbuffer 1)) arg)
  staticfloatitem)

(de intplus2 (firstarg secondarg)
  (if (isinum (setq firstarg (wplus2 firstarg secondarg)))
    firstarg
    (makefixnum firstarg)))

(de floatplus2 (firstarg secondarg)
  (prog (f)
        (setq f (gtfltn))
        (*fplus2 (floatbase f) (floatbase (fltinf firstarg))
                 (floatbase (fltinf secondarg)))
        (return (mkfltn f))))

(de intdifference (firstarg secondarg)
  (if (isinum (setq firstarg (wdifference firstarg secondarg)))
    firstarg
    (makefixnum firstarg)))

(de floatdifference (firstarg secondarg)
  (prog (f)
        (setq f (gtfltn))
        (*fdifference (floatbase f) (floatbase (fltinf firstarg))
                      (floatbase (fltinf secondarg)))
        (return (mkfltn f))))

% What about overflow?
(de inttimes2 (firstarg secondarg)
  (prog (result)
        (setq result (wtimes2 firstarg secondarg))
        (return (if (not (isinum result))
                  (makefixnum result)
                  result))))

(de floattimes2 (firstarg secondarg)
  (prog (f)
        (setq f (gtfltn))
        (*ftimes2 (floatbase f) (floatbase (fltinf firstarg))
                  (floatbase (fltinf secondarg)))
        (return (mkfltn f))))

(de intquotient (firstarg secondarg)
  (prog (result)
        (when (eq secondarg 0)
          (return (conterror 99 "Attempt to divide by zero in Quotient"
                   (quotient firstarg secondarg))))
        (setq result (wquotient firstarg secondarg))
        (return (if (not (isinum result))
                  (makefixnum result)
                  result))))

(de floatquotient (firstarg secondarg)
  (prog (f)
        (when (floatzerop secondarg)
          (return (conterror 99 "Attempt to divide by zero in Quotient"
                   (quotient firstarg secondarg))))
        (setq f (gtfltn))
        (*fquotient (floatbase f) (floatbase (fltinf firstarg))
                    (floatbase (fltinf secondarg)))
        (return (mkfltn f))))

(de intremainder (firstarg secondarg)
  (prog (result)
        (when (eq secondarg 0)
          (return (conterror 99 "Attempt to divide by zero in Remainder"
                   (remainder firstarg secondarg))))
        (setq result (wremainder firstarg secondarg))
        (return (if (not (isinum result))
                  (makefixnum result)
                  result))))

(de floatremainder (firstarg secondarg)
  (prog (f)
        % This is pretty silly
        (setq f (gtfltn))
        % might be better to signal an error
        (*fquotient (floatbase f) (floatbase (fltinf firstarg))
                    (floatbase (fltinf secondarg)))
        (*ftimes2 (floatbase f) (floatbase f)
                  (floatbase (fltinf secondarg)))
        (*fdifference (floatbase f) (floatbase (fltinf firstarg))
                      (floatbase f))
        (return (mkfltn f))))

(de intland (firstarg secondarg)
  (if (isinum (setq firstarg (wand firstarg secondarg)))
    firstarg
    (makefixnum firstarg)))

(de intlor (firstarg secondarg)
  (if (isinum (setq firstarg (wor firstarg secondarg)))
    firstarg
    (makefixnum firstarg)))

(de intlxor (firstarg secondarg)
  (if (isinum (setq firstarg (wxor firstarg secondarg)))
    firstarg
    (makefixnum firstarg)))

(de lsh (a b)
  (lshift a b))

(de intlshift (firstarg secondarg)
  (prog (result)
        (setq result (wshift firstarg secondarg))
	(if_system VAX
	   % Implement logical shift, mandated by the manual.  Wshift is
	   % an arithmetic shift because the Vax hasn't got a logical
	   % shift opcode.  Only time there is a problem is when there is
	   % a sign extension of a negative number on a right shift, so
	   % mask the extraneous 1 bits in that case.
	   (if (and (intminusp secondarg)
		    (intminusp firstarg))
	     (setq result (wand result
				(wshift (fixval (fixinf 16#7fffffff))
					(intadd1 secondarg)))))
           NIL
	)
	(return (if (not (isinum result))
                  (makefixnum result)
                  result))))

(de intgreaterp (firstarg secondarg)
  (wgreaterp firstarg secondarg))

(de floatgreaterp (firstarg secondarg)
  (and (*fgreaterp (floatbase (fltinf firstarg))
                   (floatbase (fltinf secondarg)))
       t))

(de intlessp (firstarg secondarg)
  (wlessp firstarg secondarg))

(de floatlessp (firstarg secondarg)
  (and (*flessp (floatbase (fltinf firstarg))
                (floatbase (fltinf secondarg)))
       t))

(de intadd1 (firstarg)
  (if (isinum (setq firstarg (wplus2 firstarg 1)))
    firstarg
    (makefixnum firstarg)))

(de floatadd1 (firstarg)
  (floatplus2 firstarg 1.0))

(de intsub1 (firstarg)
  (if (isinum (setq firstarg (wdifference firstarg 1)))
    firstarg
    (makefixnum firstarg)))

(de floatsub1 (firstarg)
  (floatdifference firstarg 1.0))

(de intlnot (x)
  (if (isinum (setq x (wnot x)))
    x
    (makefixnum x)))

(de intminus (firstarg)
  (if (isinum (setq firstarg (wminus firstarg)))
    firstarg
    (makefixnum firstarg)))

(de floatminus (firstarg)
  (floatdifference 0.00000E+000 firstarg))

(de floatfix (arg)
  (let (r)
       (if (isinum (setq r (*wfix (floatbase (fltinf arg)))))
         r
         (makefixnum r))))

(de floatintarg (arg)
  (prog (f)
        (setq f (gtfltn))
        (*wfloat (floatbase f) arg)
        (return (mkfltn f))))

(de intminusp (firstarg)
  (wlessp firstarg 0))

(de floatminusp (firstarg)
  (floatlessp firstarg 0.00000E+000))

(de intzerop (firstarg)
  (equal firstarg 0))

(de floatzerop (firstarg)
  (let ((pos-zero 0.00000E+000))    
    (and (weq (floathighorder (fltinf firstarg))
	      (floathighorder (fltinf pos-zero)))
	 (weq (floatloworder (fltinf firstarg))
	      (floatloworder (fltinf pos-zero))))))
    
(if_system mc68000
(de floatzerop (firstarg)
  (let ((pos-zero 0.00000E+000))
    (or (and (weq (floathighorder (fltinf firstarg))
		  (floathighorder (fltinf pos-zero)))
	     (if_system IRIS
			t
			(weq (floatloworder (fltinf firstarg))
			     (floatloworder (fltinf pos-zero)))
	     ))
	(and (weq (floathighorder (fltinf firstarg))
		  (floathighorder (fltinf **neg-zero**)))
	     (if_system IRIS
			t
			(weq (floatloworder (fltinf firstarg))
			     (floatloworder (fltinf **neg-zero**)))
	     )
	))))
)

(if_system SPARC
(de floatzerop (firstarg)
  (let ((pos-zero 0.00000E+000))
    (or (and (weq (floathighorder (fltinf firstarg))
		  (floathighorder (fltinf pos-zero)))
	     (if_system IRIS
			t
			(weq (floatloworder (fltinf firstarg))
			     (floatloworder (fltinf pos-zero)))
	     ))
	(and (weq (floathighorder (fltinf firstarg))
		  (floathighorder (fltinf **neg-zero**)))
	     (if_system IRIS
			t
			(weq (floatloworder (fltinf firstarg))
			     (floatloworder (fltinf **neg-zero**)))
	     )
	))))
)

(de intonep (firstarg)
  (equal firstarg 1))

(de floatonep (firstarg)
  (eqn firstarg 1.0))


(compiletime
 (defmacro defarith2entry (function int-fcn big-fcn float-fcn)
   (defarithentry 2 'twoargdispatch function
		  int-fcn big-fcn float-fcn)
   ))

(compiletime
 (defmacro defarith1entry (function int-fcn big-fcn float-fcn)
   (defarithentry 1 'oneargdispatch function
		  int-fcn big-fcn float-fcn)
   ))

(compiletime
 (defmacro defarith1predicateentry (function int-fcn big-fcn float-fcn)
   (defarithentry 1 'oneargpredicatedispatch function
		  int-fcn big-fcn float-fcn)
   ))

(if_system sel
(compiletime
 (de defarithentry (numberofarguments dispatchroutine nameoffunction
		    intfunction bigfunction floatfunction)
   `(lap '((*entry ,nameoffunction expr ,numberofarguments)
	   % this is really an (*Alloc 4)
	   (suabr (indexed (reg b0) 6) (reg st))
	   (*move (reg 0) (indexed (reg st) 0))
	   (*call ,dispatchroutine)
	   (fullword (mkitem (wconst id-tag) (idloc ,intfunction)))
	   % (fullword (internalentry ,bigfunction))
	   (fullword (mkitem (wconst id-tag) (idloc ,floatfunction)))
	   (fullword (mkitem (wconst id-tag) (idloc ,nameoffunction)))
	   ))))
(compiletime
 (de defarithentry (numberofarguments dispatchroutine nameoffunction
		    intfunction bigfunction floatfunction)
   `(lap '((*entry ,nameoffunction expr ,numberofarguments)
	   (*call ,dispatchroutine)
	   ,(if (internallycallablep `,intfunction)
	      `(fullword (internalentry ,intfunction))
	      `(fullword (entry ,intfunction)))
	   % (fullword (internalentry ,bigfunction))
	   ,(if (internallycallablep `,floatfunction)
	      `(fullword (internalentry ,floatfunction))
	      `(fullword (entry ,floatfunction)))
	   (fullword (mkitem (wconst id-tag) (idloc ,nameoffunction)))
	   ))))
)

(defarith2entry plus2 intplus2 bigplus2 floatplus2)

(defarith2entry difference intdifference bigdifference floatdifference)

(defarith2entry times2 inttimes2 bigtimes2 floattimes2)

(defarith2entry quotient intquotient bigquotient floatquotient)

(defarith2entry remainder intremainder bigremainder floatremainder)

(defarith2entry land intland bigland noninteger2error)

(defarith2entry lor intlor biglor noninteger2error)

(defarith2entry lxor intlxor biglxor noninteger2error)

(defarith2entry lshift intlshift biglshift noninteger2error)

(defarith2entry greaterp intgreaterp biggreaterp floatgreaterp)

(defarith2entry lessp intlessp biglessp floatlessp)

(defarith1entry add1 intadd1 bigadd1 floatadd1)

(defarith1entry sub1 intsub1 bigsub1 floatsub1)

(defarith1entry lnot intlnot biglnot noninteger1error)

(defarith1entry minus intminus bigminus floatminus)

(defarith1entry fix returnfirstarg returnfirstarg floatfix)

(defarith1entry float floatintarg floatbigarg returnfirstarg)

(defarith1predicateentry minusp intminusp bigminusp floatminusp)

(defarith1predicateentry zerop intzerop returnnil floatzerop)

(defarith1predicateentry onep intonep returnnil floatonep)

% because of gould code, this needs to occur after remainder is defined!
(if_system sel
(setq staticfloatitem
      (cond ((neq 4 (remainder (loc (wgetv staticfloatbuffer 0)) 8))	
	     (mkitem (wconst floatnum-tag) (wplus2 staticfloatbuffer 1)))
	    (T (mkitem (wconst floatnum-tag) staticfloatbuffer))))

(setq staticfloatitem (mkitem (wconst floatnum-tag) staticfloatbuffer))
)
% End of File.

