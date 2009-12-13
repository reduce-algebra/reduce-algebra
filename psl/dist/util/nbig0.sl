%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:NBIG0.SL 
% Description:  Vector based BIGNUM package with INUM operations 
% Author:       M. L. Griss & B Morrison 
% Created:      25 June 1982 
% Modified:	
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Experimental 
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
% 15-Nov-1988 (Tony Hearn)
%  Commented out bexpt, since expt in $pnk/easy-sl.sl supersedes it.
% 25-Aug-1988 (C. Burdorf and T. Yamamoto)
%  Used MC68020 for maxfloatsize.  Set up SPARC version for bigfloathi
%   and bigfloatlow initialization.
% 22-Jan-88 (James Davenport for Will Galway)
%  floatfrombignum - don't recurse on negative numbers.
% 05-Jan-88 (James Davenport for Mark Swanson)
%  bharddivide: various additional checks on dangerous values.
% 04-Jan-88 (James Davenport for Mark Swanson)
%  bsimpledivide: set p to 0 before we might GC.
% 09-Sep-87 (Leigh Stoller for Tony Hearn)
%  Added new printing routines for bignums.
% 05-Sep-87 (Leigh Stoller)
%  Add German's reclaim fix.
% 02-Sep-87 (Leigh Stoller for Russ Fish)
%  Use IntLShift instead of WShift on the VAX in redefinition of LShift.
% 05-May-87 (Leigh Stoller)
%  Added Bob Kessler's fixes to bland lshift.
% 23-Aug-84 09:39:05 (Brian Beach)
%  Made changes for use with micro-kernel: Removed (WCONST xxx) uses and
%  changed the two WFORs to IFORs.  Removed (LOAD SYSLISP).
% 26 Mar 1984 2146-PST (Nancy Kendzierski)
%  Commented out:  (compiletime (if_system mc68000 (load c!-expr!-fix)))
%  since the file was removed when the new dreg compiler came into effect.
% 05-Dec-83 17:50:15 (Nancy Kendzierski)
%   Added contents of .BUILD file.
% 02-Dec-83 18:12:56 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 22-Jul-83 Nancy Kendzierski
%   Removed MC68000 *WTIMES2 fix, since it is now handled by hp-cmac.sl
%   [.BUILD file]
% 10 March, 1983, MLG                                                      
%   LSH in Twopower replaced by 2**n                                       
%   Fixed a bug in SYS2BIG that did not convert negative BIGNUMS correctly 
% 7 February 1983, MLG                                                     
%   Merged in NBIG1 (see its "revision history" below), plus clean-up.   
%   Revision History of old NBIG1:                                       
% 28 Dec 1982, MLG:                                                        
%   Added BigZeroP and BigOneP for NArith                              
%   Changed Name to NBIG1.RED from BIGFACE                             
% 22 Dec 1982, MLG:                                                        
%   Change way of converting from VECT to BIGN                         
%   Move Module dependency to .BUILD file                              
%   Changes for NEW-ARITH, involve name changes for MAKEFIXNUM         
%   ISINUM, etc.                                                       
% 21 December, 82: MLG                                                     
%   Change PRIN1 and PRIN2 hooks to refer to RecursiveChannelprinx     
%   which changed in PK:PRINTERS.RED for prinlevel stuff               
% November: Variety of Bug Fixes by A. Norman                          
%   Use the BIGN tag for better Interface                                
% 31 Dec 1982, MLG                                                         
%   Changed BNUM to check if arg ALREADY Big. Kludge                     
%   since new NARITH makes some things BIG earlier                       
%   since it calls the BIG funcs directly                                
% 20 Dec 1982, MLG                                                         
%   Changed TrimBigNUM to TrimBigNum1 in BhardDivide                     
% 14 Dec 1982, MLG                                                         
%   Changed to put LOAD and IMPORTS in BUILD file                        
% 31 August 1982, A. C . Norman                                            
%   Adjustments to many routines: in particular corrections to BHardDivide
%   (case D6 utterly wrong), and adjustments to BExpt (for performance) and
%   all logical operators (for treatment of negative inputs);            
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A bignum will be a VECTOR of Bigits: (digits in base BigBase):           
%  [BIGPOS b1 ... bn] or [BIGNEG b1 ... bn].  BigZero is thus [BIGPOS]     
% All numbers are positive, with BIGNEG as 0 element to indicate negatives.
% BETA.RED - some values of BETA testing                                   
% On DEC-20, Important Ranges are:                                         
%  		--------------------------------                           
% POSBETA       |    0          |    n         |                           
%  		--------------------------------                           
%                  19                17 	bits                       
%  		--------------------------------                           
% NEGBETA       |    -1         |              |                           
%  		--------------------------------                           
%                                                                          
%  		--------------------------------                           
% POSINT        |    0    | 0  |               |                           
%  		--------------------------------                           
%                 5         13       18        	bits                       
%  		--------------------------------                           
% NEGINT        |    -1   | -1 |               |                           
%  		--------------------------------                           
% Thus BETA:  2^17-1       -131072 ... 131071                              
%      INT    2^18-1       -262144 ... 262143                              
%      FIX    2^35-1  -34359738368 ... 34359738367                         
%       [Note that one bit used for sign in 36 bit word]                   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load fast-vector inum if-system))
(compiletime (remprop 'addcarry 'opencode))
(compiletime (remprop 'subcarry 'opencode))

% For Bhard-Divide Bug; only for bignums, known to be buggy for other machines.
% (compiletime (if_system mc68000 (load c!-expr!-fix)))

(fluid '(bigbetahi!* % Largest BetaNum in BIG format                        
                     bigbetalow!* % Smallest BetaNum in BIG format          
                     betahi!* % Largest BetaNum as Inum                     
                     betalow!* % Smallest BetaNum as Inum                   
                     syshi!* % Largest SYSINT in FixN format                
                     syslow!* % Smallest SYSINT in FixN format              
                     bigsyshi!* % Largest SYSINT in BIG format              
                     bigsyslow!* % Smallest SYSINT in BIG format            
                     floatsyshi!* % Largest SYSINT in Float format          
                     floatsyslow!* % Smallest SYSINT in Float format        
                     bbase!* % BETA, base of system                         
                     floatbbase!* % As a float                              
                     bigfloathi!* % Largest  Float in BIG format            
                     bigfloatlow!* % Smallest Float in BIG format           
                     staticbig!* % Warray for conversion of SYS to BIG      
                     bone!* % A one                                         
                     bzero!* % A zero                                       
                     bbits!* % Number of Bits in BBASE!*                    
                     logicalbits!* digit2letter!* carry!* outputbase!*))

% --------------------------------------------------------------------------
                                                                           
% --------------------------------------------------------------------------
                                                                           
% Support functions:                                                       
%                                                                          
% U, V, V1, V2 for arguments are Bignums.  Other arguments are usually     
% fix/i-nums.                                                              
(ds putbig (b i val) % Access elements of a BIGNUM                          
    (iputv b i val))

(ds getbig (b i) % Access elements of a BIGNUM                              
    (igetv b i))

(de setbits (x)
  %                                                                        
  % This function sets the globals for big bignum package.                 
  % "x" should be total # of bits per word.                                
  (prog (y)
        (setq bbits!* (iquotient (isub1 x) 2))
        % Total number of bits per word used.                              
        (setq bbase!* (twopower bbits!*))
        % "Beta", where n=A0 + A1*beta + A2*(beta^2).                      
        (setq floatbbase!* (intfloat bbase!*))
        (setq logicalbits!* (isub1 bbase!*))
        % Used in LAnd,Lor, etc.                                           
        (setq betahi!* (isub1 bbase!*))
        (setq betalow!* (iminus bbase!*))
        (setq bone!* (bnum 1))
        (setq bzero!* (bnum 0))
        (setq bigbetahi!* (bnum betahi!*))
        % Highest value of Ai                                              
        (setq bigbetalow!* (bminus bigbetahi!*))
        % Lowest value of Ai                                               
        % here assume 2's complement                                       
        (setq y (twopower (idifference x 2)))
        % eg, 36 bits, 2^35-1=2^34+2^34-1                                  
        (setq syshi!* (plus y (difference y 1)))
        (setq y (minus y))
        (setq syslow!* (plus y y))
        (setq bigsyshi!* (bdifference (btwopower (isub1 x)) bone!*))
        % Largest representable Syslisp integer.                           
        % Note that SYSPOS has leading 0, ie only x-1 active bits          
        (setq bigsyslow!* (bminus (bplus2 bone!* bigsyshi!*)))))

% Smallest representable Syslisp integer.                                  
(de nonbignumerror (v l)
  (stderror (bldmsg " Expect a BIGNUM in %r, given %p%n" l v)))

(de bsize (v)
  % Upper Limit of [BIGxxx a1 ... An]                                      
  (if (bigp v)
    (veclen (vecinf v))
    0))

(de gtpos (n)
  % Allocate [BIGPOS a1 ... an]                                            
  (prog nil
        (setq n (mkvect n))
        (iputv n 0 'bigpos)
        (return (mkbign (vecinf n)))))

(de gtneg (n)
  % Allocate [BIGNEG a1 ... an]                                            
  (prog nil
        (setq n (mkvect n))
        (iputv n 0 'bigneg)
        (return (mkbign (vecinf n)))))

(de trimbignum (v3)
  % truncate trailing 0                                                    
  (if (not (bigp v3))
    (nonbignumerror v3 'trimbignum)
    (trimbignum1 v3 (bsize v3))))

(de trimbignum1 (b l3)
  (prog (v3)
        (setq v3 (bigasvec b))
        (while (and (igreaterp l3 0) (izerop (igetv v3 l3)))
          (setq l3 (isub1 l3)))
        (if (izerop (upbv (truncatevector v3 l3)))
          (return (gtpos 0))
          (return b))))

(de bigasvec (b)
  % In order to see BIGITS                                                 
  (mkvec (inf b)))

(de vecasbig (v)
  (mkbign (vecinf v)))

(de big2sys (u)
  % Convert a BIG to SYS, if in range                                      
  (if (or (blessp u bigsyslow!*) (bgreaterp u bigsyshi!*))
    (continuableerror 99 "BIGNUM too large to convert to SYS" u)
    (big2sysaux u)))

(de big2sysaux (u)
  % Convert a BIGN that is in range to a SYSINT                            
  (prog (l sn res)
        (setq l (bsize u))
        (when (izerop l)
          (return 0))
        (setq res (igetv u l))
        (setq l (isub1 l))
        (if (bminusp u)
          (progn (setq res (minus res))
                 (while (neq l 0)
                   (setq res (itimes2 res bbase!*))
                   (setq res (idifference res (igetv u l)))
                   (setq l (isub1 l)))
                 nil)
          (while (neq l 0)
            (setq res (itimes2 res bbase!*))
            (setq res (iplus2 res (igetv u l)))
            (setq l (isub1 l))))
        (return res)))

(de twopower (n)
  %fix/i-num 2**n                                                          
  (expt 2 n))

(de btwopower (n)
  % gives 2**n; n is fix/i-num; result BigNum                              
  (if (not (or (fixp n) (bigp n)))
    (nonintegererror n 'btwopower)
    (prog (quot rem v)
          (when (bigp n)
            (setq n (big2sys n)))
          (setq quot (quotient n bbits!*))
          (setq rem (remainder n bbits!*))
          (setq v (gtpos (iadd1 quot)))
          (ifor (from i 1 quot 1) (do (iputv v i 0)))
          (iputv v (iadd1 quot) (twopower rem))
          (return (trimbignum1 v (iadd1 quot))))))

(de bzerop (v1)
  (and (izerop (bsize v1)) (not (bminusp v1))))

(de bonep (v1)
  (and (not (bminusp v1)) (ionep (bsize v1)) (ionep (igetv v1 1))))

(de babs (v1)
  (if (bminusp v1)
    (bminus v1)
    v1))

(de bmax (v1 v2)
  (if (bgreaterp v2 v1)
    v2
    v1))

(de bmin (v1 v2)
  (if (blessp v2 v1)
    v2
    v1))

% (de bexpt (v1 n)
%   % V1 is Bignum, N is fix/i-num
%   (cond ((not (fixp n)) (nonintegererror n 'bexpt))
%         ((izerop n) bone!*)
%         ((ionep n) v1)
%         ((iminusp n) (bquotient bone!* (bexpt v1 (iminus n))))
%         (t (prog (v2)
%                  (setq v2 (bexpt v1 (iquotient n 2)))
%                  (if (izerop (iremainder n 2))
%                    (return (btimes2 v2 v2))
%                    (return (btimes2 (btimes2 v2 v1) v2)))))))

% ---------------------------------------                                  
% Logical Operations                                                       
%                                                                          
% All take Bignum arguments                                                
(de blor (v1 v2)
  % The main body of the OR code is only obeyed when both arguments        
  % are positive, and so the result will be positive;                      
  (if (or (bminusp v1) (bminusp v2))
    (blnot (bland (blnot v1) (blnot v2)))
    (prog (l1 l2 l3 v3)
          (setq l1 (bsize v1))
          (setq l2 (bsize v2))
          (when (greaterp l2 l1)
            (setq l3 l2)
            (setq l2 l1)
            (setq l1 l3)
            (setq v3 v2)
            (setq v2 v1)
            (setq v1 v3))
          (setq v3 (gtpos l1))
          (ifor (from i 1 l2 1) 
                (do (iputv v3 i (ilor (igetv v1 i) (igetv v2 i)))))
          (ifor (from i (iadd1 l2) l1 1) (do (iputv v3 i (igetv v1 i))))
          (return v3))))

(de blxor (v1 v2)
  % negative arguments are coped with using the identity                   
  % LXor(a,b) = LNot LXor(Lnot a,b) = LNor LXor(a,Lnot b);                 
  (prog (l1 l2 l3 v3 s)
        (when (bminusp v1)
          (setq v1 (blnot v1))
          (setq s t))
        (when (bminusp v2)
          (setq v2 (blnot v2))
          (setq s (not s)))
        (setq l1 (bsize v1))
        (setq l2 (bsize v2))
        (when (greaterp l2 l1)
          (setq l3 l2)
          (setq l2 l1)
          (setq l1 l3)
          (setq v3 v2)
          (setq v2 v1)
          (setq v1 v3))
        (setq v3 (gtpos l1))
        (ifor (from i 1 l2 1) 
              (do (iputv v3 i (ilxor (igetv v1 i) (igetv v2 i)))))
        (ifor (from i (iadd1 l2) l1 1) (do (iputv v3 i (igetv v1 i))))
        (setq v1 (trimbignum1 v3 l1))
        (when s
          (setq v1 (blnot v1)))
        (return v1)))

% Not Used Currently:                                                      
%                                                                          
% procedure BLDiff(V1,V2);	                                           
% ***** STILL NEEDS ADJUSTING WRT -VE ARGS *****                           
%  begin scalar V3,L1,L2;                                                  
%    L1:=BSize V1;                                                         
%    L2:=BSize V2;                                                         
%    V3:=GtPOS(max(L1,L2));                                                
%    IFor i:=1:min(L1,L2) do                                               
% 	IPutV(V3,i,ILAnd(IGetV(V1,i),ILXor(LogicalBits!*,IGetV(V2,i))));   
%    if IGreaterP(L1,L2) then IFor i:=(IAdd1 L2):L1 do IPutV(V3,i,IGetV(V1,i));
                                                                           
%    if IGreaterP(L2,L1) then IFor i:=(IAdd1 L1):L2 do IPutV(V3,i,0);      
%    return TrimBigNum1(V3,max(L1,L2));                                    
%  end;                                                                    
(de bland (v1 v2)
  % If both args are -ve the result will be too. Otherwise result will     
  % be positive;                                                           
  (if (and (bminusp v1) (bminusp v2))
    (blnot (blor (blnot v1) (blnot v2)))
    (prog (l1 l2 l3 v3)
          (setq l1 (bsize v1))
          (setq l2 (bsize v2))
          (setq l3 (min l1 l2))
          (cond ((bminusp v1) 
		 % When one is negative, we have expand out to the
		 % size of the other one.  Therefore, we use l2 as the
		 % size, not l3.  When we exceed the size of the
		 % negative number, then we just use logicalbits*.
		 (setq v3 (gtpos l2))
		 (setq l3 l2)
                 (ifor (from i 1 l2 1) 
                       (do 
			(iputv v3 i
			       (iland (cond ((igreaterp i l1) logicalbits*)
					    (t (ilxor (isub1 (igetv v1 i))
						      logicalbits*)))
				      (igetv v2 i))))))
                ((bminusp v2)
		 (setq v3 (gtpos l1))
		 (setq l3 l1)
                 (ifor (from i 1 l1 1) 
                       (do
			(iputv v3 i
			       (iland (igetv v1 i)
				      (cond ((igreaterp i l2) logicalbits*)
					    (t (ilxor (isub1 (igetv v2 i))
						      logicalbits*))))))))

		(t (setq v3 (gtpos l3))
		   (ifor (from i 1 l3 1) 
                         (do 
                          (iputv v3 i (iland (igetv v1 i) (igetv v2 i)))))))
          (return (trimbignum1 v3 l3)))))

(de blnot (v1)
  (bminus (bsmalladd v1 1)))

(de blshift (v1 v2)
  % This seems a grimly inefficient way of doing things given that         
  % the representation of big numbers uses a base that is a power of 2.    
  % However it will do for now;                                            
  (if (bminusp v2)
    (bquotient v1 (btwopower (bminus v2)))
    (btimes2 v1 (btwopower v2))))

% -----------------------------------------                                
% Arithmetic Functions:                                                    
%                                                                          
% U, V, V1, V2 are Bignum arguments.                                       
(de bminus (v1)
  % Negates V1.                                                            
  (if (bzerop v1)
    v1
    (prog (l1 v2)
          (setq l1 (bsize v1))
          (if (bminusp v1)
            (setq v2 (gtpos l1))
            (setq v2 (gtneg l1)))
          (ifor (from i 1 l1 1) (do (iputv v2 i (igetv v1 i))))
          (return v2))))

% Returns V1 if V1 is strictly less than 0, NIL otherwise.                 
%                                                                          
(de bminusp (v1)
  (if (eq (igetv v1 0) 'bigneg)
    v1
    nil))

% To provide a conveninent ADD with CARRY.                                 
(de addcarry (a)
  (prog (s)
        (setq s (iplus2 a carry!*))
        (if (igeq s bbase!*)
          (progn (setq carry!* 1)
                 (setq s (idifference s bbase!*)))
          (setq carry!* 0))
        (return s)))

(de bplus2 (v1 v2)
  (prog (sn1 sn2)
        (setq sn1 (bminusp v1))
        (setq sn2 (bminusp v2))
        (when (and sn1 (not sn2))
          (return (bdifference2 v2 (bminus v1) nil)))
        (when (and sn2 (not sn1))
          (return (bdifference2 v1 (bminus v2) nil)))
        (return (bplusa2 v1 v2 sn1))))

(de bplusa2 (v1 v2 sn1)
  % Plus with signs pre-checked and                                        
  (prog (l1 l2 l3 v3 temp)
        % identical.                                                       
        (setq l1 (bsize v1))
        (setq l2 (bsize v2))
        (when (igreaterp l2 l1)
          (setq l3 l2)
          (setq l2 l1)
          (setq l1 l3)
          (setq v3 v2)
          (setq v2 v1)
          (setq v1 v3))
        (setq l3 (iadd1 l1))
        (if sn1
          (setq v3 (gtneg l3))
          (setq v3 (gtpos l3)))
        (setq carry!* 0)
        (ifor (from i 1 l2 1) 
              (do (progn (setq temp (iplus2 (igetv v1 i) (igetv v2 i)))
                         (iputv v3 i (addcarry temp)))))
        (setq temp (iadd1 l2))
        (ifor (from i temp l1 1) (do (iputv v3 i (addcarry (igetv v1 i)))))
        (iputv v3 l3 carry!*)
        % Carry Out                                                        
        (return (trimbignum1 v3 l3))))

(de bdifference (v1 v2)
  (cond ((bzerop v2) v1)
        ((bzerop v1) (bminus v2))
        (t (prog (sn1 sn2)
                 (setq sn1 (bminusp v1))
                 (setq sn2 (bminusp v2))
                 (when (or (and sn1 (not sn2)) (and sn2 (not sn1)))
                   (return (bplusa2 v1 (bminus v2) sn1)))
                 (return (bdifference2 v1 v2 sn1))))))

(de subcarry (a)
  (prog (s)
        (setq s (idifference a carry!*))
        (if (ilessp s 0)
          (progn (setq carry!* 1)
                 (setq s (iplus2 bbase!* s)))
          (setq carry!* 0))
        (return s)))

(de bdifference2 (v1 v2 sn1)
  % Signs pre-checked and identical.                                       
  (prog (i l1 l2 l3 v3)
        (setq l1 (bsize v1))
        (setq l2 (bsize v2))
        (cond ((igreaterp l2 l1) (setq l3 l1) (setq l1 l2) (setq l2 l3) 
               (setq v3 v1) (setq v1 v2) (setq v2 v3) (setq sn1 (not sn1)))
              ((eq l1 l2) (setq i l1) (while (and 
                                              (eq (igetv v2 i) 
                                               (igetv v1 i))
                                              (igreaterp i 1))
                 (setq i (isub1 i)))
               (when (igreaterp (igetv v2 i) (igetv v1 i))
                 (setq l3 l1)
                 (setq l1 l2)
                 (setq l2 l3)
                 (setq v3 v1)
                 (setq v1 v2)
                 (setq v2 v3)
                 (setq sn1 (not sn1)))))
        (if sn1
          (setq v3 (gtneg l1))
          (setq v3 (gtpos l1)))
        (setq carry!* 0)
        (ifor (from i 1 l2 1) 
              (do (iputv v3 i 
                         (subcarry (idifference (igetv v1 i) (igetv v2 i))))))
        (ifor (from i (iadd1 l2) l1 1) 
              (do (iputv v3 i (subcarry (igetv v1 i)))))
        (return (trimbignum1 v3 l1))))

(de btimes2 (v1 v2)
  (prog (l1 l2 l3 sn1 sn2 v3)
        (setq l1 (bsize v1))
        (setq l2 (bsize v2))
        (when (igreaterp l2 l1)
          (setq v3 v1)
          (setq v1 v2)
          (setq v2 v3)
          % If V1 is larger, will be fewer                                 
          (setq l3 l1)
          (setq l1 l2)
          (setq l2 l3))
        % iterations of BDigitTimes2.                                      
        (setq l3 (iplus2 l1 l2))
        (setq sn1 (bminusp v1))
        (setq sn2 (bminusp v2))
        (if (or (and sn1 sn2) (not (or sn1 sn2)))
          (setq v3 (gtpos l3))
          (setq v3 (gtneg l3)))
        (ifor (from i 1 l3 1) (do (iputv v3 i 0)))
        (ifor (from i 1 l2 1) (do (bdigittimes2 v1 (igetv v2 i) l1 i v3)))
        (return (trimbignum1 v3 l3))))

(de bdigittimes2 (v1 v2 l1 i v3)
  % V1 is a bignum, V2 a fixnum, L1=BSize L1, I=position of V2 in a bignum,
  % and V3 is bignum receiving result.  I affects where in V3 the result of
  % a calculation goes; the relationship is that positions I:I+(L1-1)      
  % of V3 receive the products of V2 and positions 1:L1 of V1.             
  % V3 is changed as a side effect here.                                   
  (prog (j carry temp1 temp2)
        (if (zerop v2)
          (return v3)
          (progn (setq carry 0)
                 (ifor (from h 1 l1 1) 
                       (do 
                        (progn (setq temp1 (itimes2 (igetv v1 h) v2))
                               (setq temp2 (iplus2 h (isub1 i)))
                               (setq j 
                                (iplus2 (iplus2 temp1 (igetv v3 temp2)) 
                                 carry))
                               (iputv v3 temp2 (iremainder j bbase!*))
                               (setq carry (iquotient j bbase!*)))))
                 (iputv v3 (iplus2 l1 i) carry)))
        % carry should be < BBase!* here                                   
        (return v3)))

(de bsmalltimes2 (v1 c)
  % V1 is a BigNum, C a fixnum.                                            
  % Assume C positive, ignore sign(V1)                                     
  % also assume V1 neq 0.                                                  
  (cond ((zerop c) (return (gtpos 0)))
        (t % Only used from BHardDivide, BReadAdd.                          
           (prog (j carry l1 l2 l3 v3)
                 (setq l1 (bsize v1))
                 (setq l2 (iplus2 (iquotient c bbase!*) l1))
                 (setq l3 (iadd1 l2))
                 (setq v3 (gtpos l3))
                 (setq carry 0)
                 (ifor (from h 1 l1 1) 
                       (do 
                        (progn (setq j 
                                (iplus2 (itimes2 (igetv v1 h) c) carry))
                               (iputv v3 h (iremainder j bbase!*))
                               (setq carry (iquotient j bbase!*)))))
                 (ifor (from h (iadd1 l1) l3 1) 
                       (do 
                        (progn (iputv v3 h 
                                (iremainder (setq j carry) bbase!*))
                               (setq carry (iquotient j bbase!*)))))
                 (return (trimbignum1 v3 l3))))))

(de bquotient (v1 v2)
  (car (bdivide v1 v2)))

(de bremainder (v1 v2)
  (cdr (bdivide v1 v2)))

% BDivide returns a dotted pair, (Q . R).  Q is the quotient and R is      
% the remainder.  Both are bignums.  R is of the same sign as V1.          
%;                                                                         
(ds bsimplequotient (v1 l1 c snc) (car (bsimpledivide v1 l1 c snc)))

(ds bsimpleremainder (v1 l1 c snc) (cdr (bsimpledivide v1 l1 c snc)))

(de bdivide (v1 v2)
  (prog (l1 l2 q r v3)
        (setq l2 (bsize v2))
        (when (izerop l2)
          (error 99 "Attempt to divide by 0 in BDIVIDE"))
        (setq l1 (bsize v1))
        (cond ((or (ilessp l1 l2) 
                   (and (eq l1 l2) (ilessp (igetv v1 l1) (igetv v2 l2))))
               % This also takes care of case                               
               (return (cons (gtpos 0) v1))))
        % when V1=0.                                                       
        (when (ionep l2)
          (return (bsimpledivide v1 l1 (igetv v2 1) (bminusp v2))))
        (return (bharddivide v1 l1 v2 l2))))

% C is a fixnum (inum?); V1 is a bignum and L1 is its length.              
% SnC is T if C (which is positive) should be considered negative.         
% Returns quotient . remainder; each is a bignum.                          
%                                                                          
(de bsimpledivide (v1 l1 c snc)
  (prog (i p r rr sn1 v2)
        (setq sn1 (bminusp v1))
        (if (or (and sn1 snc) (not (or sn1 snc)))
          (setq v2 (gtpos l1))
          (setq v2 (gtneg l1)))
        (setq r 0)
        (setq i l1)
        (while (not (izerop i))
          (setq p (iplus2 (itimes2 r bbase!*) (igetv v1 i)))
          % Overflow.                                                      
          (iputv v2 i (iquotient p c))
          (setq r (iremainder p c))
          (setq i (isub1 i)))
        (setq p 0) % In case we have to GC. JHD on advice from Mark Swanson
        (if sn1
          (setq rr (gtneg 1))
          (setq rr (gtpos 1)))
        (iputv rr 1 r)
        (return (cons (trimbignum1 v2 l1) (trimbignum1 rr 1)))))

(de bharddivide (u lu v lv)
  % This is an algorithm taken from Knuth.                                 
  (prog (u1 v1 a d lcv lcv1 f f2 j k lq carry temp ll m n n1 p q qbar snu 
            snv u2)
        (setq n lv)
        (setq n1 (iadd1 n))
        (setq m (idifference lu lv))
        (setq lq (iadd1 m))
        % Deal with signs of inputs;                                       
        (setq snu (bminusp u))
        (setq snv (bminusp v))
        % Note that these are not extra-boolean, i.e.                      
        % for positive numbers MBinusP returns nil, for                    
        % negative it returns its argument. Thus the                       
        % test (SnU=SnV) does not reliably compare the signs of            
        % U and V;                                                         
        (cond (snu (if snv
                     (setq q (gtpos lq))
                     (setq q (gtneg lq))))
              (snv (setq q (gtneg lq)))
              (t (setq q (gtpos lq))))
        (setq u1 (gtpos (iadd1 lu)))
        % U is ALWAYS stored as if one digit longer;                       
        % Compute a scale factor to normalize the long division;           
        (setq d (iquotient bbase!* (iadd1 (igetv v lv))))
        % Now, at the same time, I remove the sign information from U and V
        % and scale them so that the leading coefficeint in V is fairly large;
                                                                           
        (setq carry 0)
        (ifor (from i 1 lu 1) 
              (do (progn (setq temp (iplus2 (itimes2 (igetv u i) d) carry))
                         (iputv u1 i (iremainder temp bbase!*))
                         (setq carry (iquotient temp bbase!*)))))
        (setq lu (iadd1 lu))
        (iputv u1 lu carry)
        % temp can have a >24 bit value, which is dangerous on 68000's
        (setq temp 0)  
        (setq v1 (bsmalltimes2 v d))
        % So far all variables contain safe values,                        
        % i.e. numbers < BBase!*;                                          
        (iputv v1 0 'bigpos)
        (when (ilessp lv 2)
          (nonbignumerror v 'bharddivide))
        % To be safe;                                                      
        (setq lcv (igetv v1 lv))
        (setq lcv1 (igetv v1 (isub1 lv)))
        % Top two digits of the scaled V accessed once                     
        % here outside the main loop;                                      
        % Now perform the main long division loop;                         
        (ifor (from i 0 m 1) 
              (do (progn (setq j (idifference lu i))
                         % J>K; working on U1[K:J]                         
                         (setq k (idifference j n1))
                         % in this loop.                                   
                         (setq a (igetv u1 j))
                         (setq p 
                          (iplus2 (itimes2 a bbase!*) (igetv u1 (isub1 j))))
                         % N.B. P is up to 30 bits long. Take care! ;      
                         (if (eq a lcv)
                           (setq qbar (isub1 bbase!*))
                           (setq qbar (iquotient p lcv)))
                         % approximate next digit;                         
                         (setq f (itimes2 qbar lcv1))
                         (setq f2 
                          (iplus2 
                           (itimes2 (idifference p (itimes2 qbar lcv)) 
                            bbase!*)
                           (igetv u1 (idifference j 2))))
                         (while (igreaterp f f2)
                           % Correct most overshoots in Qbar;              
                           (setq qbar (isub1 qbar))
                           (setq f (idifference f lcv1))
                           nil
                           (setq f2 (iplus2 f2 (itimes2 lcv bbase!*))))
                         (setq carry 0)
                         % Ready to subtract QBar*V1 from U1;              
                         (ifor (from l 1 n 1) 
                          (do 
                           (progn (setq temp 
                                   (iplus2 
                                    (idifference (igetv u1 (iplus2 k l)) 
                                     (itimes2 qbar (igetv v1 l)))
                                    carry))
                                  (setq carry (iquotient temp bbase!*))
                                  (setq temp (iremainder temp bbase!*))
                                  (when (iminusp temp)
                                    (setq carry (isub1 carry))
                                    (setq temp (iplus2 temp bbase!*)))
                                  (iputv u1 (iplus2 k l) temp))))
                         % Now propagate borrows up as far as they go;     
                         (setq ll (iplus2 k n))
                         (while (and (not (izerop carry)) (ilessp ll j))
                           (setq ll (iadd1 ll))
                           (setq temp (iplus2 (igetv u1 ll) carry))
                           (setq carry (iquotient temp bbase!*))
                           (setq temp (iremainder temp bbase!*))
                           (when (iminusp temp)
                             (setq carry (isub1 carry))
                             (setq temp (iplus2 temp bbase!*)))
                           (iputv u1 ll temp))
                         (unless (izerop carry)
                           % QBar was still wrong - correction step needed.
                           % This should not happen very often;            
                           (setq qbar (isub1 qbar))
                           % Add V1 back into U1;                          
                           (setq carry 0)
                           (ifor (from l 1 n 1) 
                            (do 
                             (progn (setq carry 
                                     (iplus2 
                                      (iplus2 (igetv u1 (iplus2 k l)) 
                                       (igetv v1 l))
                                      carry))
                                    (iputv u1 (iplus2 k l) 
                                     (iremainder carry bbase!*))
                                    (setq carry (iquotient carry bbase!*)))))
                           (setq ll (iplus2 k n))
                           (while (ilessp ll j)
                             (setq ll (iadd1 ll))
                             (setq carry (iplus2 (igetv u1 ll) carry))
                             (iputv u1 ll (iremainder carry bbase!*))
                             (setq carry (iquotient carry bbase!*))))
                         (iputv q (idifference lq i) qbar))))
        % End of main loop;                                                
        % zero out potentially dangerous values
        (setq p 0)  
        (setq f 0)
        (setq f2 0)
        (setq u1 (trimbignum1 u1 (idifference lu m)))
        % Clean up potentially wild values;                                
        (unless (bzerop u1)
          % Unnormalize the remainder by dividing by D                     
          (when snu
            (iputv u1 0 'bigneg))
          (unless (ionep d)
            (setq lu (bsize u1))
            (setq carry 0)
            (ifor (from l lu 1 -1) 
                  (do (progn (setq p 
                              (iplus2 (itimes2 carry bbase!*) (igetv u1 l)))
                             (iputv u1 l (iquotient p d))
                             (setq carry (iremainder p d)))))
            (setq p 0)
            (unless (izerop carry)
              (bhardbug "remainder when unscaling" u v (trimbignum1 u1 lu) 
                        (trimbignum1 q lq)))
            (setq u1 (trimbignum1 u1 lu))))
        (setq q (trimbignum1 q lq))
        % In case leading digit happened to be zero;                       
        (setq p 0)
        % flush out a 30 bit number;                                       
        % Here, for debugging purposes, I will try to validate the results I
                                                                           
        % have obtained by testing if Q*V+U1=U and 0<=U1<V. I Know this slows things
                                                                           
        % down, but I will remove it when my confidence has improved somewhat;
                                                                           
        %    if not BZerop U1 then <<                                      
        %       if (BMinusP U and not BMinusP U1) or                       
        %           (BMinusP U1 and not BMinusP U) then                    
        %                  BHardBug("remainder has wrong sign",U,V,U1,Q) >>;
                                                                           
        %    if not BAbs U1<BAbs V then BHardBug("remainder out of range",U,V,U1,Q)
                                                                           
        %    else if not BZerop(BDifference(BPlus2(BTimes2(Q,V),U1),U)) then 
                                                                           
        %         BHardBug("quotient or remainder incorrect",U,V,U1,Q);    
        (return (cons q u1))))

(de bhardbug (msg u v r q)
  % Because the inputs to BHardDivide are probably rather large, I am not  
  % going to rely on BldMsg to display them;                               
  (progn (prin2t "***** Internal error in BHardDivide")
         (prin2 "arg1=")
         (prin2t u)
         (prin2 "arg2=")
         (prin2t v)
         (prin2 "computed quotient=")
         (prin2t q)
         (prin2 "computed remainder=")
         (prin2t r)
         (stderror msg)))

(de bgreaterp (u v)
  (cond ((bminusp u) (if (bminusp v)
           (bunsignedgreaterp v u)
           nil))
        ((bminusp v) u)
        (t (bunsignedgreaterp u v))))

(de blessp (u v)
  (cond ((bminusp u) (if (bminusp v)
           (bunsignedgreaterp u v)
           u))
        ((bminusp v) nil)
        (t (bunsignedgreaterp v u))))

(de bgeq (u v)
  (cond ((bminusp u) (if (bminusp v)
           (bunsignedgeq v u)
           nil))
        ((bminusp v) u)
        (t (bunsignedgeq u v))))

(de bleq (u v)
  (cond ((bminusp u) (if (bminusp v)
           (bunsignedgeq u v)
           u))
        ((bminusp v) nil)
        (t (bunsignedgeq v u))))

(de bunsignedgreaterp (u v)
  % Compare magnitudes of two bignums;                                     
  (prog (lu lv i)
        (setq lu (bsize u))
        (setq lv (bsize v))
        (unless (eq lu lv)
          (if (igreaterp lu lv)
            (return u)
            (return nil)))
        (while (and (eq (igetv u lv) (igetv v lv)) (igreaterp lv 1))
          (setq lv (isub1 lv)))
        (if (igreaterp (igetv u lv) (igetv v lv))
          (return u)
          (return nil))))

(de bunsignedgeq (u v)
  % Compare magnitudes of two unsigned bignums;                            
  (prog (lu lv)
        (setq lu (bsize u))
        (setq lv (bsize v))
        (unless (eq lu lv)
          (if (igreaterp lu lv)
            (return u)
            (return nil)))
        (while (and (eq (igetv u lv) (igetv v lv)) (igreaterp lv 1))
          (setq lv (isub1 lv)))
        (if (igreaterp (igetv v lv) (igetv u lv))
          (return nil)
          (return u))))

(de badd1 (v)
  (bsmalladd v 1))

(de bsub1 (u)
  (bsmalldiff u 1))

% ------------------------------------------------                         
% Conversion to Float:                                                     
(de floatfrombignum (v)
  (cond ((bzerop v) 0.00000E+000)
        ((or (bgreaterp v bigfloathi!*) (blessp v bigfloatlow!*)) 
         (error 99 (list "Argument, " v " to FLOAT is too large")))
        (t (prog (l res sn i)
                 % Careful, do not want to call itself recursively         
                 (setq l (bsize v))
                 (setq sn (bminusp v))
                 (setq res (intfloat (igetv v l)))
                 (setq i (isub1 l))
                 (while (not (izerop i))
                   (setq res (floattimes2 res floatbbase!*))
                   (setq res (floatplus2 res (intfloat (igetv v i))))
                   (setq i (isub1 i)))
                 (when sn
                   % used to be minus instead of floatdifference:
                   % that causes a recursion
                   (setq res (floatdifference 0.0 res)))
                 (return res)))))

% ------------------------------------------------                         
% Input and Output:                                                        
(setq digit2letter!* 
      '[48 49 50 51 52 53 54 55 56 57 65 66 67 68 69 70 71 72 73 74 75 76 
        77 78 79 80 81 82 83 84 85 86 87 88 89 90])

% a new routine for printing bignums
%
% bchannelprin2 is still the entry point of course, but not much else
%
% first make a copy of v1 (the number to be printed), output any
% necessary base information then call bprin which actually does the work

(de bchannelprin2 (channel v1)
  ((lambda (v2 myobase i)
     (while (not (izerop i))
       (progn (iputv v2 i (igetv v1 i)) (setq i (isub1 i))))
     (cond ((bminusp v1) (channelwritechar channel (char !-))))
     (cond
       ((neq myobase 10)
        (channelwritesysinteger channel myobase 10)
        (channelwritechar channel (char !#))))
     (bprin channel v2)
     (setq outputbase!* myobase))
     (gtpos (bsize v1)) %JAP 870802
   outputbase!*
   (bsize v1)))

% divide v by 10**4, if the quotient is zero the recursion is terminated
% and the most significant digit is printed (and so on down the stack)
% otherwise save the big digit (=remainder) and recurse
(de bprin (channel v)
  ((lambda (digit)
     (cond
       ((bzerop v) (channelwritesysinteger channel digit outputbase!*))
       (t (bprin channel v) (printdigit channel digit))))
   (bdivide10000ip v)))

% print a base 10**4 digit
(de printdigit (channel d)
  (prog (d1 d2 d3)
    (setq d1 (iremainder d 10)) (setq d (iquotient d 10))
    (setq d2 (iremainder d 10)) (setq d (iquotient d 10))
    (setq d3 (iremainder d 10)) (setq d (iquotient d 10))
    (channelwritechar channel (igetv digit2letter!* (iremainder d 10)))
    (channelwritechar channel (igetv digit2letter!* d3))
    (channelwritechar channel (igetv digit2letter!* d2))
    (return (channelwritechar channel (igetv digit2letter!* d1)))))

% divide the bignum v1 (of length l1) by 10000, except the quotient is
% accumulated in the same place, the remainder, of course, ripples
% down to the bottom.  Because the argument is modified there is no need
% to CONS up a result, but simply return the remainder.
(de bdivide10000ip (v1)
  ((lambda (p r i)
     (while (not (izerop i))
       (progn
         (setq p (iplus2 (itimes2 r bbase!*) (igetv v1 i)))
         (iputv v1 i (iquotient p 10000))
         (setq r (iremainder p 10000))
         (setq i (isub1 i))))
     (trimbignum1 v1 (bsize v1))
     (cond ((bminusp v1) (iminus r)) (t r)))
   nil
   0
   (bsize v1)))

(de bread (s radix sn)
  % radix is < Bbase!*                                                     
  %s=string of digits, radix=base, sn=1 or -1                              
  (prog (sz res ch)
        (setq sz (size s))
        (setq res (gtpos 1))
        (setq ch (indx s 0))
        (when (and (igeq ch (char a)) (ileq ch (char z)))
          (setq ch (iplus2 (idifference ch (char a)) 10)))
        (when (and (igeq ch (char 0)) (ileq ch (char 9)))
          (setq ch (idifference ch (char 0))))
        (iputv res 1 ch)
        (ifor (from i 1 sz 1) 
              (do (progn (setq ch (indx s i))
                         (when (and (igeq ch (char a)) (ileq ch (char z)))
                           (setq ch 
                            (idifference ch (idifference (char a) 10))))
                         (when (and (igeq ch (char 0)) (ileq ch (char 9)))
                           (setq ch (idifference ch (char 0))))
                         (setq res (breadadd res radix ch)))))
        (when (iminusp sn)
          (setq res (bminus res)))
        (return res)))

(de breadadd (v radix ch)
  (setq v (bsmalltimes2 v radix))
  (setq v (bsmalladd v ch)))

(de bsmalladd (v c)
  %V big, C fix.                                                           
  (cond ((izerop c) (return v))
        ((bzerop v) (return (int2big c)))
        ((bminusp v) (bminus (bsmalldiff (bminus v) c)))
        ((iminusp c) (bsmalldiff v (iminus c)))
        (t (prog (v1 l1)
                 (setq carry!* c)
                 (setq l1 (bsize v))
                 (setq v1 (gtpos (iadd1 l1)))
                 (ifor (from i 1 l1 1) 
                       (do (iputv v1 i (addcarry (igetv v i)))))
                 (if (ionep carry!*)
                   (iputv v1 (iadd1 l1) 1)
                   (return (trimbignum1 v1 l1)))
                 (return v1)))))

(de bnum (n)
  % Creates a Bignum of one BETA digit, value N.                           
  % N is POS or NEG                                                        
  (if (bigp n)
    n
    (bnumaux n)))

(de bnumaux (n)
  % Creates a Bignum of one BIGIT value N.                                 
  % N is POS or NEG                                                        
  (prog (b)
        (cond ((izerop n) (return (gtpos 0)))
              ((iminusp n) (setq b (gtneg 1)) (setq n (iminus n)))
              (t (setq b (gtpos 1))))
        (iputv b 1 n)
        (return b)))

(de bsmalldiff (v c)
  %V big, C fix                                                            
  (cond ((izerop c) v)
        ((bzerop v) (int2big (iminus c)))
        ((bminusp v) (bminus (bsmalladd (bminus v) c)))
        ((iminusp c) (bsmalladd v (iminus c)))
        (t (prog (v1 l1)
                 (setq carry!* c)
                 (setq l1 (bsize v))
                 (setq v1 (gtpos l1))
                 (ifor (from i 1 l1 1) 
                       (do (iputv v1 i (subcarry (igetv v i)))))
                 (unless (izerop carry!*)
                   (stderror (bldmsg " BSmallDiff V<C %p %p%n" v c)))
                 (return (trimbignum1 v1 l1))))))

(de int2big (n)
  % Creates BigNum of value N.                                             
  % From any N, BETA,INUM,FIXNUM or BIGNUM                                 
  (case (tag n) ((negint-tag posint-tag) (sys2big n)) 
        ((fixnum-tag) (sys2big (fixval (fixinf n)))) 
        ((bignum-tag) n)
	(nil (nonintegererror n 'int2big))))

% Convert BIGNUMs to FLOAT                                                 
(de bigfromfloat (x)
  (if (or (fixp x) (bigp x))
    x
    (prog (bigpart floatpart power sign thispart)
          (if (minusp x)
            (progn (setq sign -1)
                   (setq x (minus x)))
            (setq sign 1))
          (setq bigpart bzero!*)
          (while (and (neq x 0) (neq x 0.00000E+000))
            (if (lessp x bbase!*)
              (progn (setq bigpart (bplus2 bigpart (bnum (fix x))))
                     (setq x 0))
              (progn (setq floatpart x)
                     (setq power 0)
                     (while (geq floatpart bbase!*)
                       % get high end of number.                           
                       (progn (setq floatpart (quotient floatpart bbase!*))
                              (setq power (plus power bbits!*))))
                     (setq thispart 
                      (btimes2 (btwopower power) (bnum (fix floatpart))))
                     (setq x (difference x (floatfrombignum thispart)))
                     (setq bigpart (bplus2 bigpart thispart)))))
          (when (minusp sign)
            (setq bigpart (bminus bigpart)))
          (return bigpart))))

% Now Install Interfacing                                                  
(de setupglobals ()
  (prin2t '"SetupGlobals")
  (setbits bitsperword)
  (prin2t '" ... done")
  nil)

(setupglobals)

(loadtime
  (progn (setq staticbig!* (gtwarray 10))))

% Assume dont need more than 10 slots to represent a BigNum                
% Version of SYSint                                                        
% -- Output---                                                             
% MLG Change to interface to Recursive hooks, added for                    
%  Prinlevel stuff                                                         
(copyd 'oldchannelprin1 'recursivechannelprin1)

(copyd 'oldchannelprin2 'recursivechannelprin2)

(de recursivechannelprin1 (channel u level)
  (if (bigp u)
    (bchannelprin2 channel u)
    (oldchannelprin1 channel u level))
  u)

(de recursivechannelprin2 (channel u level)
  (if (bigp u)
    (bchannelprin2 channel u)
    (oldchannelprin2 channel u level))
  u)

(de checkifreallybig (uu)
  % If BIGNUM result is in older FIXNUM or INUM range                      
  % Convert Back.                                                          
  %/ Need a faster test                                                    
  (if (or (blessp uu bigsyslow!*) (bgreaterp uu bigsyshi!*))
    uu
    (sys2int (big2sysaux uu))))

(de checkifreallybigpair (vv)
  % Used to process DIVIDE                                                 
  (cons (checkifreallybig (car vv)) (checkifreallybig (cdr vv))))

(de checkifreallybigornil (uu)
  % Used for EXTRA-boolean tests                                           
  (if (or (null uu) (blessp uu bigsyslow!*) (bgreaterp uu bigsyshi!*))
    uu
    (sys2int (big2sysaux uu))))

(de bigplus2 (u v)
  (checkifreallybig (bplus2 u v)))

(de bigdifference (u v)
  (checkifreallybig (bdifference u v)))

(de bigtimes2 (u v)
  (checkifreallybig (btimes2 u v)))

(de bigdivide (u v)
  (checkifreallybigpair (bdivide u v)))

(de bigquotient (u v)
  (checkifreallybig (bquotient u v)))

(de bigremainder (u v)
  (checkifreallybig (bremainder u v)))

(de bigland (u v)
  (checkifreallybig (bland u v)))

(de biglor (u v)
  (checkifreallybig (blor u v)))

(de biglxor (u v)
  (checkifreallybig (blxor u v)))

(de biglshift (u v)
  (checkifreallybig (blshift u v)))

(de lshift (u v)
  (if (and (betap u) (betap v))
    (cond ((wlessp v 0)
	   (sys2int (if_system VAX (intlshift u v) (wshift u v))))
          ((wlessp v bbits!*)
	   (sys2int (if_system VAX (intlshift u v) (wshift u v))))
          (t (biglshift (sys2big u) (sys2big v))))
    % Use int2big, not sys2big, since we might have fixnums.
    (biglshift (int2big u) (int2big v))))

(copyd 'lsh 'lshift)

(de biggreaterp (u v)
  (checkifreallybigornil (bgreaterp u v)))

(de biglessp (u v)
  (checkifreallybigornil (blessp u v)))

(de bigadd1 (u)
  (checkifreallybig (badd1 u)))

(de bigsub1 (u)
  (checkifreallybig (bsub1 u)))

(de biglnot (u)
  (checkifreallybig (blnot u)))

(de bigminus (u)
  (checkifreallybig (bminus u)))

(de bigminusp (u)
  (checkifreallybigornil (bminusp u)))

(de bigonep (u)
  (checkifreallybigornil (bonep u)))

(de bigzerop (u)
  (checkifreallybigornil (bzerop u)))

% ---- Input ----                                                          
(de makestringintolispinteger (s radix sn)
  (checkifreallybig (bread s radix sn)))

(de int2sys (n)
  % Convert a random FIXed number to WORD Integer                          
  (case (tag n) ((posint-tag negint-tag) n) 
        ((fixnum-tag) (fixval (fixinf n))) 
        ((bignum-tag) (big2sysaux n)) 
        (nil (nonnumber1error n 'int2sys))))

(de sys2big (n)
  % Convert a SYSint to a BIG                                              
  % Must NOT use generic arith here                                        
  % Careful that no GC if this BIGger than INUM                            
  (prog (sn a b)
        (when (weq n 0)
          (return (gtpos 0)))
        (setq a staticbig!*)
        % Grab the base                                                    
        (when (wlessp n 0)
          (setq sn t))
        (setf (wgetv a 1) n)
        % Plant number                                                     
        (setq n 1)
        % now use N as counter                                             
        % Careful handling of -N in case have largest NEG, not just        
        % flip sign                                                        
        (if sn
          (progn (setq b (wminus bbase!*))
                 (while (wleq (wgetv a n) b)
                   (setq n (wplus2 n 1))
                   (setf (wgetv a n) 
                         (wquotient (wgetv a (wdifference n 1)) bbase!*))
                   (setf (wgetv a (wdifference n 1)) 
                         (wdifference (wgetv a (wdifference n 1)) 
                          (wtimes2 (wgetv a n) bbase!*))))
                 (setq b (gtneg n))
                 (ifor (from i 1 n 1) 
                       (do (iputv b i (wminus (wgetv a i))))))
          (progn (while (wgeq (wgetv a n) bbase!*)
                   (setq n (wplus2 n 1))
                   (setf (wgetv a n) 
                         (wquotient (wgetv a (wdifference n 1)) bbase!*))
                   (setf (wgetv a (wdifference n 1)) 
                         (wdifference (wgetv a (wdifference n 1)) 
                          (wtimes2 (wgetv a n) bbase!*))))
                 (setq b (gtpos n))
                 (ifor (from i 1 n 1) (do (iputv b i (wgetv a i))))))
        (return b)))

% Coercion/Transfer Functions                                              
(copyd 'oldfloatfix 'floatfix)

(de floatfix (u)
  % Careful of sign and range                                              
  (if (and (leq floatsyslow!* u) (leq u floatsyshi!*))
    (oldfloatfix u)
    (bigfromfloat u)))

(de betap (x)
  % test if NUMBER in reduced INUM range                                   
  (if (intp x)
    (and (wleq x betahi!*) (wgeq x betalow!*))
    nil))

(de betarangep (x)
  % Test if SYSINT in reduced INUM range                                   
  (if (wleq x betahi!*)
    (wgeq x betalow!*)
    nil))

(de beta2p (x y)
  % Check for 2 argument arithmetic functions                              
  (when (betap x)
    (betap y)))

% Also from .BUILD file
% Now install the important globals for this machine

(if_system VAX
  (progn
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bdifference (btwopower 67) (btwopower 11))
			       (btwopower 60)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(if_system SPARC
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56))
			       (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(if_system MC68000
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56))
			       (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(if_system MC88000
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56))
                               (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))
 
(if_system Convex
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56))
                               (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))
 
(if_system Mips
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56))
                               (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))
 
(if_system IBMRS
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56))
                               (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(if_system HP-RISC
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56))
                               (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(if_system PDP10
  (progn
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 62)) (btwopower 65)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(setq FloatSysHi!* (float SysHi!*))
(setq FloatSysLow!* (float SysLow!*))

% The following patch supplied by Herbert Melenk and Winfried Neun of
% the Konrad-Zuse Zentrum, Berlin, corrects a serious bug in the
% garbage collector that occurs when bignums are loaded.  The patch
% must be used in compiled form.  

(copyd '!%!%reclaim '!%reclaim)

(fluid '(gcvar1!* gcvar2!* arithargloc))

(de !%reclaim ()
  (setq gcvar1!* (wgetv arithargloc 0))
  (setq gcvar2!* (wgetv arithargloc 1))
  (!%!%reclaim)
  (wputv arithargloc 0 gcvar1!*)
  (wputv arithargloc 1 gcvar2!*)
  nil)


