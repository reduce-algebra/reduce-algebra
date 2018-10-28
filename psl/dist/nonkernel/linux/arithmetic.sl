%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:arithmetic.sl  for i386
% Description:  Generic arithmetic routines for PSL (New model, less hairy)
% Author:       Eric Benson and Martin Griss 
% Created:      9 August 1982 
% Modified:     06-Oct-87 (Robert Kessler)
% Mode:         Lisp 
% Package:      Utilities 
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 16-Oct-87 (Kessler and Stoller) - As reported by zib, (min 'a 'b) returns
%  'a.  Cause is that coerce2 should check the types of the args to verify
%  that they are some kind of number.  We added a check and error call.
% Tue Oct 06 1987, Kessler - changed zerop to call floatzerop instead of 
%  equal which caused an infinite loop.
% Sat Feb 21 08:16:22 1987, originally Mon Apr 16 12:31:08 1984 (Russ Fish)
%   Use IntLShift instead of WShift on the VAX in redefinition of LShift.
% 23-Aug-84 09:52:00 (Brian Beach)
%  Updated for use with micro-kernel.  Changed (WCONST xxx) to xxx.
% 7 May 1984 1950-PDT (M. L. Griss, on DEC-20)
%  Changed the = to EQUAL in the Zerop and Onep code, since = needed
%  numeric operators loaded.
% 07-Dec-83 13:05:57 (Nancy Kendzierski)
%   Changed occurrences of aritharg to arithargloc and staticfloat to
%   staticfloatloc, because of the removal of 'newnam stuff.
% 06-Dec-83 11:57:10 (Nancy Kendzierski)
%   Changed WEQ to = in
%     (defarithpred1entry zerop izerop (lambda (x) (weq x '0.00000E+000)) returnnil)
%     (defarithpred1entry onep ionep (lambda (x) (weq x '1.0)) returnnil)
%    This clears up the "zerop problem" temporarily, but doesn't explain what
%    to do in the general case of eqn to weq translation.
% 02-Dec-83 18:11:13 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 02-Dec-83 16:06:10  Nancy Kendzierski
%   Removed compiletime newnam stuff, since it's now lisp syntax.
%     (compiletime (progn % Some aliases
%       (put 'aritharg 'newnam '(lispvar arithargloc))
%       (put 'staticfloat 'newnam '(lispvar staticfloatloc)) nil))
% 01-Dec-83 23:23:26  Nancy Kendzierski
%   In un-rlisped file, changed posint to (wconst posint) when un-rlisp didn't.
%   In un-rlisped file, changed bign to (wconst bign) when un-rlisp didn't.
%   In un-rlisped file, changed fltn to (wconst fltn) when un-rlisp didn't.
% 01-Dec-83 13:06:57  Nancy Kendzierski                                    
%   in Syslisp section, changed "expr procedure"s to just "procedure"s.     
% Mods by MLG, 21 dec 1982                                                 
%   Take off INTERNALFUNCTION form FLOATxxx                            
%   Change names of FAKE and SFL to xxxxLOC                            
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The MODEL:                                                               
% It is assumed that there is a range of INUMs (subset) called             
% BETAnums that can be safely operated on by the Wxxx or Ixxx routines     
% without loss of precesion or overflow, and return an INUM (or at least   
% a SYSINT.                                                                
%                                                                          
% A UNARY operation (UN x) is done as:                                     
%  Procedure UN x;                                                         
%    If BetaP x then <<x:=WUN x; if IntRangeP x then x else Sys2Int x>>    
%      else UN!-HARD(x);                                                   
% A UNARY predicate  (UNP x) is done as:                                   
%  Procedure UNP x;                                                        
%    If BetaP x then WUNP x                                                
%      else UNP!-HARD(x);                                                  
% A BINARY operation (BIN x y) is done as:                                 
%  Procedure BIN(x,y);                                                     
%    If BetaP x and BetaP y                                                
%	then <<x:=WBIN(x,y);                                               
%	       if IntRangeP x then x else Sys2Int x>>                      
%     else BIN!-HARD(x,y);                                                 
% A BINARY predicate (BINP x y) is done as:                                
%  Procedure BINP(x,y);                                                    
%    If BetaP x and BetaP y then WBINP(x,y)                                
%     else BINP!-HARD(x,y);                                                
% IN some "safe" cases, BetaP can become IntP (beware of *)                
% In others, BetaP(y) may be too weak (eg, Lshift and Expt)                
% Note: Loading NBIG0 is supposed to define (or redefine)                  
%       the functions:                                                     
%		BetaP                                                      
%               Beta2P                                                     
%               BetaRangeP                                                 
%		Sys2Big                                                    
%		FloatFromBignum                                            
%		Sys2Int                                                    
%		FloatFix                                                   
% Removed IsInum and INTP in favor of BetaP                                
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(compiletime 
   (mapc ' (*wfix *wfloat 
            *fplus2 *fdifference 
            *ftimes2 *fquotient 
            *fgreaterp *flessp)
        (function(lambda(x)(remprop x 'opencode)))))


(fluid '(arithargloc staticfloatloc fpstatusloc* fp-except-mode*))

(loadtime
  (progn % Allocate Physical Space                                         
         (setq arithargloc (gtwarray 2))
         (wputv arithargloc 0 0)
         (wputv arithargloc 1 0)
         (setq staticfloatloc (gtwarray 3))
         (setq fpstatusloc* (gtwarray 1))
         (setq fp-except-mode* 1)
         nil))


(if_system IEEE

(progn	   

(compiletime (load ieee-decls))

(de float-is-finite (x)
    (and (floatp x)
	 (wlessp (ieeeexpt x) ieeemaxexp)))

(de float-is-nan (x)
    (and (floatp x)
	 (weq (ieeeexpt x) ieeemaxexp)
	 (wneq (ieeemant x) 0)))

(de float-is-infinite (x)
    (and (floatp x)
	 (weq (ieeeexpt x) ieeemaxexp)
	 (weq (ieeemant x) 0)))

(de float-is-subnormal (x)
    (and (floatp x)
	 (weq (ieeeexpt x) 0)))

(de float-is-negative (x)
    (and (floatp x)
	 (wneq (ieeesign x) 0)))
	 
)

(progn

(de float-is-finite (x) t)

(de float-is-nan (x) nil)

(de float-is-infinite (x) nil)

(de float-is-subnormal (x) nil)

(de float-is-negative (x) (floatlessp x '0.00000E+000))

)
) % if_system IEEE


(de betap (x)
  % Test tagged number is in Beta Range when BIGNUM loaded                 
  % Will redefine if NBIG loaded                                           
  (intp x))

(de betarangep (w)
  't)

% Test Word is in Beta Range when BIGNUM loaded                            
% Ie, is FIXNUM size with no NBIG                                          
% Will redefine if NBIG loaded                                             
(de beta2p (x y)
  % Test if BOTH in Beta range                                             
  % Will be redefined if NBIG loaded                                       
  (if (intp x)
    (intp y)
    nil))

(de sys2big (w)
  % Out of safe range, convert to BIGN                                     
  (continuableerror 99 
                    "Sys2Big cant convert Word to BIGNUM, no BIGNUM's loaded"
                    (sys2int w)))

(compiletime
  (progn %flag('(Coerce2 FloatPlus2 FloatDifference FloatTimes2            
         %       FloatQuotient FloatGreaterP FloatLessP IntFloat           
         %       NonInteger2Error NonNumber1Error  NonNumber2Error         
         %), 'NotYetInternalFunction);                                     
         (de namegen (name part)
           % Generate Nice specific name from Generic name                 
           (intern (concat (id2string name) (id2string part))))
         (ds nextarg nil % Just substitute in the context of U              
             (progn (setq u (cdr u))
                    (car u)))
         (ds prologue nil % Common Prologue                                 
             (progn (setq generic (nextarg))
                    (setq wgen (nextarg))
                    (setq fgen (nextarg))
                    (setq bgen (nextarg))
                    (setq hardgen (namegen generic '!-hardcase))
                    (flag1 hardgen 'notyetinternalfunction)
                    nil))
         (dm defarith2entry (u)
           (prog (generic wgen fgen bgen hardgen)
                 (prologue)
                 (return (subla 
                          (pair '(generic wgen fgen bgen hardgen) 
                           (list generic wgen fgen bgen hardgen))
                          '(progn (de generic (x y)
                                    (cond ((beta2p x y) 
                                           (progn (setq x (wgen x y))
                                                  (cond ((intp x) x)
                                                        (t (sys2int x)))))
                                          (t (hardgen x y))))
                                  (de hardgen (x y)
                                    (case (coerce2 x y 'generic) 
                                     ((posint-tag)
                                      (sys2int 
                                       (wgen (wgetv arithargloc 0) 
                                        (wgetv arithargloc 1))))
                                     %/ Beware of Overflow, WGEN maybe should test args
                                                                           
                                     %/ Coerce2 is supposed to check this case
                                                                           
                                     ((floatnum-tag) 
                                      (fgen (wgetv arithargloc 0) 
                                       (wgetv arithargloc 1)))
                                     ((bignum-tag) 
                                      (bgen (wgetv arithargloc 0) 
                                       (wgetv arithargloc 1)))))
                                  nil)))))
         (dm defarithpred2entry (u)
           (prog (generic wgen fgen bgen hardgen)
                 (prologue)
                 (return (subla 
                          (pair '(generic wgen fgen bgen hardgen) 
                           (list generic wgen fgen bgen hardgen))
                          '(progn (de generic (x y)
                                    (cond ((beta2p x y) (wgen x y))
                                          (t (hardgen x y))))
                                  (de hardgen (x y)
                                    (case (coerce2 x y 'generic) 
                                     ((posint-tag) 
                                      (wgen (wgetv arithargloc 0) 
                                       (wgetv arithargloc 1)))
                                     %/ Assumes Preds are safe against Overflow
                                                                           
                                     ((floatnum-tag) 
                                      (fgen (wgetv arithargloc 0) 
                                       (wgetv arithargloc 1)))
                                     ((bignum-tag) 
                                      (bgen (wgetv arithargloc 0) 
                                       (wgetv arithargloc 1)))))
                                  nil)))))
         (dm defint2entry (u)
           (prog (generic wgen fgen bgen hardgen)
                 (prologue)
                 (return (subla 
                          (pair '(generic wgen bgen hardgen) 
                           (list generic wgen bgen hardgen))
                          '(progn (de generic (x y)
                                    (cond ((beta2p x y) 
                                           (progn (setq x (wgen x y))
                                                  (cond ((intp x) x)
                                                        (t (sys2int x)))))
                                          (t (hardgen x y))))
                                  (de hardgen (x y)
                                    (case (coerce2 x y 'generic) 
                                     ((posint-tag) 
                                      (sys2int 
                                       (wgen (wgetv arithargloc 0) 
                                        (wgetv arithargloc 1))))
                                     ((floatnum-tag) 
                                      (noninteger2error x y 'generic))
                                     ((bignum-tag) 
                                      (bgen (wgetv arithargloc 0) 
                                       (wgetv arithargloc 1)))))
                                  nil)))))
         (dm defarith1entry (u)
           (prog (generic wgen fgen bgen hardgen)
                 (prologue)
                 (return (subla 
                          (pair '(generic wgen fgen bgen hardgen) 
                           (list generic wgen fgen bgen hardgen))
                          '(progn (de generic (x)
                                    (cond ((betap x) 
                                           (progn (setq x (wgen x))
                                                  (cond ((intp x) x)
                                                        (t (sys2int x)))))
                                          (t (hardgen x))))
                                  (de hardgen (x)
                                    (case (coerce1 x 'generic) 
                                     ((posint-tag) 
                                      (sys2int (wgen (wgetv arithargloc 0))))
                                     ((floatnum-tag)
				      (fgen (wgetv arithargloc 0))) 
                                     ((bignum-tag)
				      (bgen (wgetv arithargloc 0))) 
                                     (nil (nonnumber1error x 'generic))))
                                  nil)))))
         (dm defarithpred1entry (u)
           (prog (generic wgen fgen bgen hardgen)
                 (prologue)
                 (return (subla 
                          (pair '(generic wgen fgen bgen hardgen) 
                           (list generic wgen fgen bgen hardgen))
                          '(progn (de generic (x)
                                    (cond ((betap x) (wgen x))
                                          (t (hardgen x))))
                                  (de hardgen (x)
                                    (case (coerce1 x 'generic) 
                                     ((posint-tag)
				      (wgen (wgetv arithargloc 0))) 
                                     ((floatnum-tag)
				      (fgen (wgetv arithargloc 0))) 
                                     ((bignum-tag)
				      (bgen (wgetv arithargloc 0))) 
                                     (nil nil)))
                                  nil)))))
         (ds deffloatentry (name prim) 
             (de name (x y)
               (prog (f)
                     (setq f (gtfltn))
                     (prim (floatbase f) (floatbase (fltinf x)) 
                      (floatbase (fltinf y)))
                     (return (mkfltn f)))))
         nil))

% The support procedures for coercing types                                
(de coerce1 (x f)
  % Returns type tag of coerced X type and sets ArithArg[0] to be coerced X
  % Beware of ADD1/SUB1 cases, maybe can optimize later                    
  (prog (t1)
        (setq t1 (tag x))
        (case t1 ((negint-tag) (setq t1 posint-tag)) 
              ((fixnum-tag) 
               (progn (setq t1 posint-tag)
                      (setq x (fixval (fixinf x))))))
        (when (and (weq t1 posint-tag) (not (betarangep x)))
          (setq t1 bignum-tag)
          (setq x (sys2big x)))
        (wputv arithargloc 0 x)
        (return t1)))

(de coerce2 (x y f)
  % Returns type tag of strongest type and sets ArithArg[0] to be coerced X
  % and ArithArg[1] to coerced Y.                                          
  (prog (t1 t2 p c)
        (setq t1 (tag x))
        (case t1
	  ((negint-tag) (setq t1 posint-tag)) 
	  ((fixnum-tag) 
	   (progn (setq t1 posint-tag)
		  (setq x (fixval (fixinf x))))))
        (when (and (weq t1 posint-tag) (not (betarangep x)))
          (setq t1 bignum-tag)
          (setq x (sys2big x)))
        (setq t2 (tag y))
        (case t2
	  ((negint-tag) (setq t2 posint-tag)) 
	  ((fixnum-tag) 
	   (progn (setq t2 posint-tag)
		  (setq y (fixval (fixinf y))))))
        (when (and (weq t2 posint-tag) (not (betarangep y)))
          (setq t2 bignum-tag)
          (setq y (sys2big y)))
        %% Verify that we have some kind of number, otherwise we signal
	%% an error.
        (cond ((or (wgreaterp t1 floatnum-tag) (wgreaterp t2 floatnum-tag))
	       (return (nonnumber2error x y f))))
        (setf (wgetv arithargloc 0) x)
        (setf (wgetv arithargloc 1) y)
        (when (weq t1 t2)
          (return t1))
        % no coercion to be done                                           
        (cond ((wlessp t1 t2) % coerce first arg to second                  
               (progn (setq p (loc (wgetv arithargloc 0)))
                      % P points to first (to be coerced)                  
                      (setq c t2)
                      % swap T1 and T2                                     
                      (setq t2 t1)
                      (setq t1 c)))
              (t (setq p (loc (wgetv arithargloc 1)))))
        % P points to second                                               
        (when (wgreaterp t1 floatnum-tag)
          (return (nonnumber2error x y f)))
        % Here, since no 2 arg Arith Preds that accept 1 number, one not   
        (case t1 
              ((floatnum-tag) 
               (case t2 
                     ((posint-tag) 
                      (setf (getmem p) (staticintfloat (getmem p))))
                     ((bignum-tag) 
                      (setf (getmem p) (floatfrombignum (getmem p))))))
              ((bignum-tag) (setf (getmem p) (sys2big (getmem p)))))
        % @P must be SYSint                                                
        (return t1)))

(de staticintfloat (x)
  (!*wfloat (loc (wgetv staticfloatloc 1)) x)
  (mkfltn (loc (wgetv staticfloatloc 0))))

(de noninteger2error (x y f)
  (continuableerror 99 "Non-integer argument in arithmetic" 
                    (list f (mkquote x) (mkquote y))))

(de nonnumber1error (x f)
  (continuableerror 99 "Non-numeric argument in arithmetic" 
                    (list f (mkquote x))))

(de nonnumber2error (x y f)
  (continuableerror 99 "Non-numeric argument in arithmetic" 
                    (list f (mkquote x) (mkquote y))))

% Now generate the entries for each operator                               
(defarith2entry plus2 wplus2 floatplus2 bigplus2)

(deffloatentry floatplus2 !*fplus2)

(defarith2entry difference wdifference floatdifference bigdifference)

(deffloatentry floatdifference !*fdifference)

(defarith2entry times2 wtimes2 floattimes2 bigtimes2)

% Beware of Overflow                                                       
(deffloatentry floattimes2 !*ftimes2)

(defarith2entry quotient wquotient floatquotient bigquotient)

(deffloatentry floatquotient !*fquotient)

(defarithpred2entry greaterp wgreaterp floatgreaterp biggreaterp)

(de floatgreaterp (x y)
  (*fgreaterp (floatbase (fltinf x))(floatbase (fltinf y))))

(defarithpred2entry lessp wlessp floatlessp biglessp)

(de floatlessp (x y)
  (*flessp (floatbase (fltinf x))(floatbase (fltinf y)) t nil))

(de fdummy (x y)
  (stderror "Fdummy should never be called"))

(defint2entry remainder wremainder fdummy bigremainder)

(defint2entry land wand fdummy bigland)

(defint2entry lor wor fdummy biglor)

(defint2entry lxor wxor fdummy biglxor)

(defarith1entry lnot wnot fdummy biglnot)

% Cant DO Lshift in terms of BETA sized shifts                             
% Will totally redefine in BIG package.

(defint2entry lshift (lambda (u v) (cond ((wlessp v (minus bitsperword)) 0)
                                          (t (wshift u v))))
                                    nil  biglshift)
(commentoutcode(if_system Vax			      % Vax Wshift is arithmetic, not logical.
    (defint2entry lshift intlshift biglshift)
    (defint2entry lshift wshift biglshift)
)
)
(de lsh(x y) (lshift x y))

(defarith1entry add1 iadd1 (lambda (x)
                                   (floatplus2 x '1.0)) bigadd1)

(defarith1entry sub1 isub1 (lambda (x)
                                   (floatdifference x '1.0)) bigsub1)

(defarith1entry minus iminus floatminus bigminus)

(de floatminus (x)
  (let ((y (gtfltn)))
    (*fminus (floatbase y) (floatbase (fltinf x)))
    (mkfltn y))
)

(defarith1entry fix (lambda (x)
                            x) floatfix (lambda (x)
                                                x))

(de floatfix (x)
  (if (float-is-finite x)
      (sys2int (!*wfix (floatbase (fltinf x))))
    (continuableerror 99 "Non-finite float in fix" x)))

(de float (x)
  (case (tag x) ((posint-tag negint-tag) (intfloat x)) 
        ((fixnum-tag) (intfloat (fixval (fixinf x)))) 
        ((floatnum-tag) x)
	((bignum-tag) (floatfrombignum x)) 
        (nil (nonnumber1error x 'float))))

(de intfloat (x)
  (prog (f)
        (setq f (gtfltn))
        (!*wfloat (floatbase f) x)
        (return (mkfltn f))))

(defarithpred1entry minusp iminusp 
                    (lambda (x)
                            (floatlessp x '0.00000E+000)) bigminusp)

(defarithpred1entry zerop izerop floatzerop returnnil)

(defarithpred1entry onep ionep (lambda (x)
                                       (equal x '1.0)) returnnil)

(de floatzerop (x) (and  (eq 0 (wshift (wshift (wgetv (inf x) 1) 1) -1))
			 (eq 0 (wgetv (inf x) 2))))

(de returnnil (u)
  nil)

(de sqrt (x)
 (case (tag x)
   ((posint-tag negint-tag) (setq x (intfloat x))) 
   ((fixnum-tag) (setq x (intfloat (fixval (fixinf x)))))
   ((bignum-tag) (setq x (floatfrombignum x)))
   ((floatnum-tag) nil)
   (nil (nonnumber1error x 'sqrt)))
 (when (and (not (eq fp-except-mode* 0)) (floatlessp x '0.0))
       (continuableerror 99 "Negative argument to sqrt" (list 'sqrt x)))
 (let ((y (gtfltn)))
   (uxsqrt (floatbase y) (floatbase (fltinf x)))
   (mkfltn y))
)

% End of file.
