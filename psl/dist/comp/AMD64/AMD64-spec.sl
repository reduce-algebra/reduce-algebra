%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           pxc/AMD64-spec.SL
% Title:          Some special things for sun PSL compiler
% Author:         Winfried Neun , ZIB Berlin
% Created:        9 Feb 2005
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Compiler
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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

% This code is intended for filling the 'holes' in the frame.
% e.g. in the following function
%
%  (de hugo (x) (cond ((null x) (call-another))
%                     (t (prog (a b c) ....))
%
% a frame of length 4 will be allocated, but it will not be preset (by nil)
% completely at entering the function but the frame elements for a b and c
% will be set (to nil) if the prog is entered.
% So if the (null x) case is taken we have 3 unset frame elements on the stack
% which contain random information and this is dangerous for gc.
% to resolve that problem, the following function will work on the input
% to pass-1-lap and insert nil settings where needed.

(fluid '(&fillframeholes &frame-numbers))

(compiletime (flag '(findcmacro lookatinstruction) 'internalfunction)) 
 
(de &fillframeholes (code)
   (prog (allo cmactoextern externfound ll lll nn linearcode restcode)
      (when (not &fillframeholes) (return code))
      (setq cmactoextern
                  '(*link *linke *call *jcall *cons *xcons *fastmkfltn))
             % trivial tests whether we have to work at all
      (unless (setq allo (findcmacro code '*alloc)) (return code))
      (setq ll cmactoextern)
      (while (and (not externfound) ll)
            (setq externfound (findcmacro code (car ll))) 
            (setq ll (cdr ll)))  
      (when (not externfound) (return code))
 
            % so we have to work, starting at the *alloc 
 
      (setq nn (cadar allo))  %the frame size              
      (setq linearcode t)
      (setq restcode (cdr allo))       
 
      (setq &frame-numbers nil) 
 
      (while (and linearcode restcode)
         (setq linearcode (lookatinstruction (car restcode)))
         (setq restcode (cdr restcode))) 
 
      (when linearcode (return code))
 
      (setq lll (setq ll (cons nil nil))) 
              
             % search frame that have not been set, prepare code,
             % put into place after *alloc
 
      (for (from i 1 nn 1) (do
            (unless (memq i &frame-numbers)
                  (rplaca ll `(*move (reg t1) (frame ,i)))
                  (when (eq &fillframeholes 'verbose) 
                    (prin2 "++ in ") (prin2 name&)
                    (prin2 " presetting frame ")
                    (prin2t i))
                  (push 'nil ll)))) 
      
      (when (eq lll ll) (return code))
      (rplacd lll (cdr allo))
 
      (rplaca ll `(*move (quote nil) (reg t1)))
      (rplacd allo ll)
      (return code))) 
         
(de lookatinstruction (instr)
      (cond ((atom instr) t)
            ((and (eq (car instr) '*move) 
                  (eqcar (caddr instr) 'frame)) 
                       (push (cadr (caddr instr)) &frame-numbers) 17)
            ((memq (car instr) '(*link *call *linke *jcall *jumpintype
                 *jumpeq *jump  *JumpType *JumpNotType *JumpNotInType
                 *jumpnoteq *jumpwlessp *jumpwgreaterp *jumpwleq *jumpwgeq
                 *jumpon)) nil)
            (t t)))
 
 
(de findcmacro (list pat) 
     (cond ((atom list ) nil) 
           ((eqcar (car list) pat) list) 
           (t        (findcmacro (cdr list) pat )))) 

(setq &fillframeholes t)

% install filling of hooles in lap-to-asm too.


(fluid '(locallabels* codeout*))

(de asmoutlap (u)
  (prog (locallabels* oldout)
        (setq u (pass1lap (&fillframeholes u)))
        % Expand cmacros, quoted expressions
        (codeblockheader)
        (setq oldout (wrs codeout*))
        (foreach x in u do (asmoutlap1 x))
        (wrs oldout)
        (codeblocktrailer)))

(flag '(asmoutlap) 'lose) % should not be redefined by lap-to-asm

% fix for nbig30 bignums in faslout

(de AppendContents (ExpressionLabelPair)
  (prog (Expression UpperBound I)
        (AddCodeLabel (cdr ExpressionLabelPair))
        (setq Expression (car ExpressionLabelPair))
        (cond ((PairP Expression)
               (progn (AppendItem (car Expression))
                      (AppendItem (cdr Expression))))
              ((StringP Expression)
               (progn (AddFullWord (Size Expression))
                      (AddCode (list 'STRING Expression))))
              ((VectorP Expression)
               (progn (setq UpperBound (ISizeV Expression))
                      (AddFullWord UpperBound)
                      (setq I 0)
                      (while (ILEQ I UpperBound)
                             (progn (AppendItem (IGetV Expression I))
                                    (setq I (IAdd1 I))))))
              ((BigP Expression)
               (progn (setq UpperBound (ISizeV Expression))
                      (AddFullWord UpperBound)
                      (AppendItem (IGetV Expression 0)) % sign is an i
                      (setq I 1)
                      (while (ILEQ I UpperBound)
%                    (progn (AppendItem (IGetV Expression I))
                          (progn (AddFullWord (sys2fixn (IGetV Expression I)))
                                    (setq I (IAdd1 I))))))
              ((FixP Expression)
               (progn (AddFullWord 0)   % Header of full word fixnum.
                      (AddFullWord Expression)))
              ((FloatP Expression)
               (progn (AddFullWord 1)   % Header of float.
                      (AddCode (list 'FLOAT Expression)))))))


(put 'wquotient 'pass-1-reform 'pa1r-wquotient)
 
(de pa1r-wquotient (form)
  % Wquotient: does Power of 2 to WSHIFT conversion
  (let ((arg1    (second form))
        (arg2    (third form)))
    (cond
     ((and (constant? arg2) (powerof2p (constant-value arg2)))
      `(ashift (wplus2 ,arg1 
                    (wshift ,arg1 
                         ',(difference (powerof2p (constant-value arg2)) 64 )))
               ',(minus (powerof2p (constant-value arg2)))))
     (t form))))


