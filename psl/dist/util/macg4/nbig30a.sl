%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:NBIG30a.SL 
% Description:  Vector based BIGNUM package with INUM operations 
% Author:       M. L. Griss & B Morrison 
% Created:      25 June 1982 
% Modified:	
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Experimental 
%
% (c) Copyright 1987, University of Utah, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 10-Oct-1991  (Winfried Neun)
%  Following a suggestion of Tony Hearn, the big predicates return T instead
%  of the number
% 20-June-1989 (Winfried Neun)
%  changed bread so that long numbers can be read with less bignum overhead
% 24-Jan-89 (Herbert Melenk)
%  enlarged bigit length up to wordsize - 2
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A bignum will be a VECTOR of Bigits: (digits in base BigBase):           
%  [BIGPOS b1 ... bn] or [BIGNEG b1 ... bn].  BigZero is thus [BIGPOS]     
% All numbers are positive, with BIGNEG as 0 element to indicate negatives.
%
% The base is set to wordsize-2; for multiplication and division a
% double length integer arithmetic is required.
%
% NOTE that bbase* is no longer an inum! So we use open coded functions
% to access the values of bbase* and logicalbits*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load muls fast-vector vfvect inum if-system double))


%------------------------- control of debug output ------------------------

(compiletime
 (progn

  (setq bigtest nil)

  (dm bigtest(u)
    (if bigtest
        (cons 'progn (cdr u))
        '(nullum)))

  (put 'nullum 'opencode '((*move (reg 1)(reg 1))))

))

%------------------------- arithmetic macros -----------------------------

(compiletime (progn

  (ds +w(a b)(wplus2 a b))            % add words

  (ds +x(a b)                         % add extended (set carry*)
      ((lambda(p)
        (setq carry* (quotient-bbase p))
        (remainder-bbase p))
       (wplus2 a b)))

  (ds +c(a b)(addcarry (wplus2 a b))) % add with carry and set carry*

% (ds +x+c(a b) (addAndAddCarry a b)) % add a and b and add carry to
%                                     %  *second-value*

  (ds /i(a b)(wquotient a b))

  (ds -c(a b)(subcarry (wdifference a b))) % subtract with borrow

  (ds >i(a b)(igreaterp a b))        

  (remd '1+)

  (ds 1+(x) (iadd1 x))
))

%------------------------- variables -------------------------------------

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
                     digit2letter!* carry!* outputbase!*
                     bigitsPerMantissa* % bigits needed for float conversion
                     *Karatsubabound*  % number of bigits for Karatsuba start
                     *second-value*))

(compiletime
   (flag '(setbits trimbignum1 big2sysaux btwopower bexpt blor
           blxor bland blnot blshift blrshift bllshift bminus
           bplus2 bplusa2 bdifference bdifference2
           btimes2 bdigittimes2 bsmalltimes2 bkaratsuba bwords
           bwordsshiftleft bshiftandaddinto bdifference2inplace
           bquotient bremainder bdivide bdivide-trivialtest
           bsimpledivide bharddivide bhardbug
           bgreaterp blessp bgeq bleq bunsignedgreaterp bunsignedgeq
           badd1 bsub1 bdivide1000000ip bread breadadd bsmalladd
           bnum bnumaux bsmalldiff biggcdn1) 'internalfunction)
)

(setq *Karatsubabound* 39)

% --------------------------------------------------------------------------
% the bignum routines handle bit patterns which exceed the inf field.   
% If these items sleep in the stack when a garbage collection occurs,
% the heap management will fail. Therefore we 
%  - do all heap activities before the bigit operations start,
%  - clean up the stack when leaving a routine with bigit operations.
% The macro "Cleanstack" does this job if included in a return expression:
% it overwrites all stack positions and is transparent with respect to
% the result lying in register 1. The macro code should be machine independent.
% It will work correctly only if Nalloc* is set properly!
% That is the case for 68020 e.g. with frames > 2

(compiletime (load if-system))
(compiletime (ds Cleanstack(r) r))
                                                                           
% --------------------------------------------------------------------------


% Support functions:                                                       
%                                                                          
% U, V, V1, V2 for arguments are Bignums.  Other arguments are usually     
% fix/i-nums.                                                              

(de setbits (x)
  % This function sets the globals for big bignum package.                 
  % "x" should be total # of bits per word.                                
  (prog (y)
        (setq bbits!* (idifference x 2))
        % Total number of bits per word used.                              
        (setq bbase!* (twopower bbits!*))
        % "Beta", where n=A0 + A1*beta + A2*(beta^2).                      
        (setq floatbbase!* (float-expt 2.000 bbits!*))
           % calculate the number of bigits needed for float conversion
        (setq bigitsPerMantissa* 1)
        (setq y floatbbase!*)
        (while (not (eqn  y (floatplus2 y floatbbase!*)))
               (setq bigitsPerMantissa* (iadd1 bigitsPerMantissa*))
               (setq y (floattimes2 y  floatbbase!*)))
        %  the general beta range is next integer below half word size
        (setq betahi!* (isub1 (expt 2 (isub1 (quotient bitsperword 2)))))
        (setq betalow!* (iminus betahi!*))
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
  (if (bigp v) (veclen (vecinf v)) 0))

(compiletime (ds bbsize (v) (veclen (vecinf v))))

(compiletime (ds bbminusp (v1) (eq (igetv v1 0) 'bigneg)))

(de gtpos (n)
  % Allocate [BIGPOS a1 ... an]                                            
  (prog nil
        (setq n (gtwrds n))
        (iputv n 0 'bigpos)
        (return (mkbign (vecinf n)))))

(de gtneg (n)
  % Allocate [BIGNEG a1 ... an]                                            
  (prog nil
        (setq n (gtwrds n))
        (iputv n 0 'bigneg)
        (return (mkbign (vecinf n)))))

(de trimbignum (v3)
  % truncate trailing 0                                                    
  (if (not (bigp v3))
    (nonbignumerror v3 'trimbignum)
    (trimbignum1 v3 (bbsize v3))))

(compiletime (ds bigaswrds (b) (mkwrds (inf b))))

(de trimbignum1 (b l3)
  (prog (v3)
        (setq v3 (bigaswrds b))
        (while (and (igreaterp l3 0) (izerop (igetv v3 l3)))
          (setq l3 (isub1 l3)))
        (if (izerop (upbw (truncatewords v3 l3)))
          (return bzero!*)
          (return b))))

(de big2sys (u)
  % Convert a BIG to SYS, if in range                                      
  (if (or (blessp u bigsyslow!*) (bgreaterp u bigsyshi!*))
    (continuableerror 99 "BIGNUM too large to convert to SYS" u)
    (big2sysaux u)))

(de big2sysaux (u)
  % Convert a BIGN that is in range to a SYSINT                            
  (prog (l sn res)
        (when (not (bigp u)) (return 0))
        (setq l (bbsize u))
        (when (izerop l) (return 0))
        (setq res (igetv u l))
        (setq l (isub1 l))
        (if (bbminusp u)
          (progn (setq res (iminus res))
                 (while (neq l 0)
                   (setq res (itimes2 res (bbase**)))
                   (setq res (idifference res (igetv u l)))
                   (setq l (isub1 l)))
                 nil)
          (while (neq l 0)
            (setq res (itimes2 res(bbase**)))
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
          (vfor (from i 1 quot 1) (do (iputv v i 0)))
          (iputv v (iadd1 quot) (twopower rem))
          (return (trimbignum1 v (iadd1 quot))))))

(compiletime
 (progn 
   (ds bzerop (v1) (and (izerop (bbsize v1)) (not (bbminusp v1))))
   (ds bonep (v1) (and (not (bbminusp v1)) (ionep (bbsize v1)) (ionep (igetv v1 1))))
   (ds babs (v1) (if (bbminusp v1) (bminus v1) v1))
   (ds bmax (v1 v2) (if (bgreaterp v2 v1) v2 v1))
   (ds bmin (v1 v2) (if (blessp v2 v1) v2 v1))
))

(de bexpt (v1 n)
  % V1 is Bignum, N is fix/i-num                                           
  (cond ((not (fixp n)) (nonintegererror n 'bexpt))
        ((izerop n) bone!*)
        ((ionep n) v1)
        ((iminusp n) (bquotient bone!* (bexpt v1 (iminus n))))
        (t (prog (v2)
                 (setq v2 (bexpt v1 (iquotient n 2)))
                 (if (izerop (iremainder n 2))
                   (return (btimes2 v2 v2))
                   (return (btimes2 (btimes2 v2 v1) v2)))))))

% ---------------------------------------                                  
% Logical Operations                                                       
%                                                                          
% All take Bignum arguments                                                
(de blor (v1 v2)
  % The main body of the OR code is only obeyed when both arguments        
  % are positive, and so the result will be positive;                      
  (if (or (bbminusp v1) (bbminusp v2))
    (blnot (bland (blnot v1) (blnot v2)))
    (prog (l1 l2 l3 v3)
          (setq l1 (bbsize v1))
          (setq l2 (bbsize v2))
          (when (greaterp l2 l1) (setq l3 l2) (setq l2 l1) (setq l1 l3)
            (setq v3 v2) (setq v2 v1) (setq v1 v3))
          (setq v3 (gtpos l1))
          (vfor (from i 1 l2 1) 
                (do (iputv v3 i (ilor (igetv v1 i) (igetv v2 i)))))
          (vfor (from i (iadd1 l2) l1 1) (do (iputv v3 i (igetv v1 i))))
          (return (cleanstack v3)))))

(de blxor (v1 v2)
  % negative arguments are coped with using the identity                   
  % LXor(a,b) = LNot LXor(Lnot a,b) = LNor LXor(a,Lnot b);                 
  (prog (l1 l2 l3 v3 s)
        (when (bbminusp v1) (setq v1 (blnot v1)) (setq s t))
        (when (bbminusp v2) (setq v2 (blnot v2)) (setq s (not s)))
        (setq l1 (bbsize v1))
        (setq l2 (bbsize v2))
        (when (igreaterp l2 l1) (setq l3 l2) (setq l2 l1) (setq l1 l3)
          (setq v3 v2) (setq v2 v1) (setq v1 v3))
        (setq v3 (gtpos l1))
        (vfor (from i 1 l2 1) 
              (do (iputv v3 i (ilxor (igetv v1 i) (igetv v2 i)))))
        (vfor (from i (iadd1 l2) l1 1) (do (iputv v3 i (igetv v1 i))))
        (setq v1 (trimbignum1 v3 l1))
        (when s (setq v1 (blnot v1)))
        (return (cleanstack v1))))

(de bland (v1 v2)
  % If both args are -ve the result will be too. Otherwise result will     
  % be positive;                                                           
  (if (and (bbminusp v1) (bbminusp v2))
    (blnot (blor (blnot v1) (blnot v2)))
    (prog (l1 l2 l3 v3)
          (setq l1 (bbsize v1)) (setq l2 (bbsize v2)) (setq l3 (min l1 l2))
          (cond ((bbminusp v1) 
		 % When one is negative, we have expand out to the
		 % size of the other one.  Therefore, we use l2 as the
		 % size, not l3.  When we exceed the size of the
		 % negative number, then we just use (logicalbits**).
		 (setq v3 (gtpos l2)) (setq l3 l2)
                 (vfor (from i 1 l2 1) 
                       (do 
			(iputv v3 i
			     (iland (cond ((igreaterp i l1) (logicalbits**))
					    (t (ilxor (isub1 (igetv v1 i))
						      (logicalbits**))))
				      (igetv v2 i))))))
                ((bbminusp v2)
		 (setq v3 (gtpos l1)) (setq l3 l1)
                 (vfor (from i 1 l1 1) 
                       (do
			(iputv v3 i
			       (iland (igetv v1 i)
				      (cond ((igreaterp i l2)(logicalbits**))
					    (t (ilxor (isub1 (igetv v2 i))
						      (logicalbits**)))))))))

		(t (setq v3 (gtpos l3))
		   (vfor (from i 1 l3 1) 
                         (do 
                          (iputv v3 i (iland (igetv v1 i) (igetv v2 i)))))))
          (return(cleanstack  (trimbignum1 v3 l3))))))

(de blnot (v1) (bminus (bsmalladd v1 1)))

(de blshift(v1 n)
  (if (iminusp n) (blrshift v1 (iminus n)) (bllshift v1 n)))

(de blrshift(v1 n)
  % shift right n places
   (prog (nw nb nr carry l1 v2 l2 x)
      % split n into words and bits
      (setq nw (iquotient n bbits*) nb (iminus (iremainder n bbits*))
            nr (iplus2 bbits* nb))
      (setq l1 (bbsize v1))
      (setq l2 (idifference l1 nw))
      (when (ilessp l2 1) (return bzero*))
      (setq v2 (if (bbminusp v1)(gtneg l2)(gtpos l2)))
      (setq carry 0)
      (vfor (from i l2 1 -1)
            (let j (iplus2 i nw))
            (do 
              (progn
                 (setq x (igetv v1 j))
                 (iputv v2 i(wor carry (wshift x nb)))
                 (setq carry(wand (logicalbits**) (wshift x nr))))))
      (return (cleanstack (trimbignum1 v2 l2)))))
 
(de bllshift(v1 n) 
  % shift left n places
   (prog (nw nb nr carry l1 v2 l2 x) 
      % split n into words and bits 
      (setq nw (iquotient n bbits*) nb (iremainder n bbits*)
            nr (idifference nb bbits*)) % nr is <=0 !!
      (setq l1 (bbsize v1)) 
      (setq l2 (iplus2 l1 (iadd1 nw))) 
      (setq v2 (if (bbminusp v1)(gtneg l2)(gtpos l2))) 
      (setq carry 0) 
             % clear the trailing words
      (vfor (from i 1 nw 1) (do (iputv v2 i 0)))
      (vfor (from i (iadd1 nw) (isub1 l2) 1) 
            (let j (idifference i nw)) 
            (do 
              (progn 
                 (setq x (igetv v1 j)) 
                 (iputv v2 i(wor carry (wand (logicalbits**)(wshift x nb))))
                 (setq carry (wshift x nr))))) 
      (iputv v2 l2 carry)
      (return (cleanstack (trimbignum1 v2 l2)))) )
  
      
% -----------------------------------------                                
% Arithmetic Functions:                                                    
% U, V, V1, V2 are Bignum arguments.                                       

% --------------------------------- MINUS ------------------------------

(de bminus (v1) % Negates V1. 
  (if (bzerop v1) v1
    (prog (l1 v2)
          (setq l1 (bbsize v1))
          (if (bbminusp v1)
            (setq v2 (gtpos l1))
            (setq v2 (gtneg l1)))
          (vfor (from i 1 l1 1) (do (iputv v2 i (igetv v1 i))))
          (return (cleanstack v2)))))

% --------------------------------- MINUSP -----------------------------

% Returns V1 if V1 is strictly less than 0, NIL otherwise.                 
(de bminusp (v1) (if (eq (igetv v1 0) 'bigneg) v1 nil))

% ---------------------------------- PLUS -----------------------------

%(de addcarry (a)   % now opencode
% (prog (s)
%       (setq s (iplus2 a carry!*))
%       (if (igeq s (bbase!*!*))
%         (progn (setq carry!* 1) (setq s (idifference s (bbase!*!*))))
%         (setq carry!* 0))
%       (return s)))

(de bplus2 (v1 v2)
  (prog (sn1 sn2)
        (setq sn1 (bbminusp v1)) (setq sn2 (bbminusp v2))
        (when (and sn1 (not sn2)) (return (bdifference2 v2 (bminus v1) nil)))
        (when (and sn2 (not sn1)) (return (bdifference2 v1 (bminus v2) nil)))
        (return (bplusa2 v1 v2 sn1))))

(de bplusa2 (v1 v2 sn1)
  % Plus with signs pre-checked and                                        
  (prog (l1 l2 l3 v3 temp)
        % identical.                                                       
        (setq l1 (bbsize v1)) (setq l2 (bbsize v2))
        (when (igreaterp l2 l1) (setq l3 l2) (setq l2 l1) (setq l1 l3)
          (setq v3 v2) (setq v2 v1) (setq v1 v3))
        (setq l3 (iadd1 l1))
        (if sn1 (setq v3 (gtneg l3)) (setq v3 (gtpos l3)))
        (setq carry!* 0)
        (vfor (from i 1 l2 1) 
              (do (progn (setq temp (iplus2 (igetv v1 i) (igetv v2 i)))
                         (iputv v3 i (addcarry temp)))))
        (setq temp (iadd1 l2))
        (vfor (from i temp l1 1) (do (iputv v3 i (addcarry (igetv v1 i)))))
        (iputv v3 l3 carry!*)
        (setq carry!* 0)   % clear bigit
        (return (cleanstack (trimbignum1 v3 l3)))))

(de bdifference (v1 v2)
  (cond ((bzerop v2) v1)
        ((bzerop v1) (bminus v2))
        (t (prog (sn1 sn2)
                 (setq sn1 (bbminusp v1))
                 (setq sn2 (bbminusp v2))
                 (when (or (and sn1 (not sn2)) (and sn2 (not sn1)))
                   (return (bplusa2 v1 (bminus v2) sn1)))
                 (return (bdifference2 v1 v2 sn1))))))

% ------------------------------ DIFFERENCE ----------------------------
    % now opencode:
%(de subcarry (a)
% (prog (s)
%       (setq s (idifference a carry!*))
%       (if (ilessp s 0)
%         (progn (setq carry!* 1) (setq s (iplus2 (bbase**)s)))
%         (setq carry!* 0))
%       (return s)))



(de bdifference2 (v1 v2 sn1)
  % Signs pre-checked and identical.                                       
  (prog (i l1 l2 l3 v3)
        (setq l1 (bbsize v1))
        (setq l2 (bbsize v2))
        (cond ((igreaterp l2 l1) (setq l3 l1) (setq l1 l2) (setq l2 l3) 
               (setq v3 v1) (setq v1 v2) (setq v2 v3) (setq sn1 (not sn1)))
              ((eq l1 l2) 
               (setq i l1) 
               (while (and (eq (igetv v2 i) (igetv v1 i)) (igeq i 1))
                                 (setq i (isub1 i)))
               (when (eq i 0)(return (cleanstack bzero*))) % fast return
               (when (>i (igetv v2 i) (igetv v1 i))
                 (setq l3 l1) (setq l1 l2) (setq l2 l3) (setq v3 v1)
                 (setq v1 v2) (setq v2 v3) (setq sn1 (not sn1)))))
        (if sn1 (setq v3 (gtneg l1)) (setq v3 (gtpos l1)))
        (setq carry!* 0)
        (vfor (from i 1 l2 1) 
              (do (iputv v3 i 
                         (-c (igetv v1 i) (igetv v2 i)))))
        (vfor (from i (1+ l2) l1 1) 
              (do (iputv v3 i (-c (igetv v1 i) 0))))
        (setq carry!* 0)   % clear bigit
        (return (cleanstack (trimbignum1 v3 l1)))))

% ------------------------------ TIMES ---------------------------------

(de btimes2 (v1 v2)
  (prog (l1 l2 l3 sn1 sn2 v3)
        (setq l1 (bbsize v1)) (setq l2 (bbsize v2))
        (when (and(igreaterp l1 *Karatsubabound*)
                  (igreaterp l2 *Karatsubabound*))
                  (return (bkaratsuba v1 l1 v2 l2)))
        (when (igreaterp l2 l1) (setq v3 v1) (setq v1 v2) (setq v2 v3)
                                (setq l3 l1) (setq l1 l2) (setq l2 l3))
        % iterations of BDigitTimes2.                                      
        (setq l3 (iplus2 l1 l2))
        (setq sn1 (bbminusp v1))
        (setq sn2 (bbminusp v2))
        (if (or (and sn1 sn2) (not (or sn1 sn2)))
          (setq v3 (gtpos l3)) (setq v3 (gtneg l3)))
        (vfor (from i 1 l3 1) (do (iputv v3 i 0)))
        (vfor (from i 1 l2 1) (do (bdigittimes2 v1 (igetv v2 i) l1 i v3)))
        (return (cleanstack (trimbignum1 v3 l3)))))

(de bdigittimes2 (v1 v2 l1 i v3)
  % V1 is a bignum, V2 a fixnum, L1=BSize L1, I=position of V2 in a bignum,
  % and V3 is bignum receiving result.  I affects where in V3 the result of
  % a calculation goes; the relationship is that positions I:I+(L1-1)      
  % of V3 receive the products of V2 and positions 1:L1 of V1.             
  % V3 is changed as a side effect here.                                   
  (if (izerop v2) v3
   (prog (j carry temp1 temp2)
         (setq carry 0)
         (vfor (from h 1 l1 1) 
               (let temp2 (iplus2 h (isub1 i)))
               (do 
                 (progn (setq temp1 (wtimesdouble (igetv v1 h) v2))
                       (setq j (wplus2 (wplus2 temp1 (igetv v3 temp2)) carry))
                       (iputv v3 temp2 (remainder-bbase j))
                       (setq carry (iplus2 *second-value*
                                           (quotient-bbase j) )))))
         (iputv v3 (iplus2 l1 i) carry)
        % carry should be < BBase!* here                                   
         (setq *second-value* 0) % clear carry
         (return (cleanstack v3)))))

(de bsmalltimes2 (v1 c cc)
  % V1 is a BigNum, C a fixnum.                                            
  % Assume C positive, ignore sign(V1)                                     
  % also assume V1 neq 0.                                                  
  (cond ((and (izerop c)(izerop cc)) (return (gtpos 0)))
        (t % Only used from BHardDivide, BReadAdd.                          
           (prog (j carry l1 l2 l3 v3)
                 (setq l1 (bbsize v1))
                 (setq l2 (iplus2 (quotient-bbase c) l1))
                 (setq l3 (iadd1 l2))
                 (setq v3 (gtpos l3))
                 (if (not(izerop cc)) % rejoin splitted word
                     (setq c (iplus2 c (itimes2 cc betahi!*))))
                 (setq carry 0)
                 (vfor (from h 1 l1 1) 
                       (do 
                        (progn (setq j 
                                (iplus2 (wtimesdouble (igetv v1 h) c) carry))
                               (iputv v3 h (remainder-bbase j))
                               (setq carry(iplus2 *second-value*
                                                  (quotient-bbase j))))))
                 (vfor (from h (iadd1 l1) l3 1) 
                       (do 
                        (progn (iputv v3 h 
                                (remainder-bbase (setq j carry) ))
                               (setq carry (quotient-bbase j)))))
                 (setq *second-value* 0) % clear carry
                 (return (cleanstack (trimbignum1 v3 l3)))))))

% Karatsuba method for multiplication of very large bignums
% (e.g. from 350 decimal digits upwards)
 
(de bkaratsuba(u lu v lv)
     (prog (su sv n U0 V0 U1 V1 p1 p2 p3 uv)
           % setq n to max(lu,lv)/2, rounded up
         (setq n (if (igreaterp lu lv) lu lv))
         (setq n (if (izerop (wand n 1)) (wshift n -1)(iadd1(wshift n -1))))
         (setq U0 (bwords u lu 1 n) U1 (bwords u lu (iadd1 n) lu))
         (setq V0 (bwords v lv 1 n) V1 (bwords v lv (iadd1 n) lv))
          % the basic formula is
          % uv := (2**2n + 2**n) U1 V1 +
          %        2**n (U1 - U0)(V0 - V1) +
          %        (2**n + 1) U0 V0
         (setq p1 (btimes2 U1 V1))
         (setq p3 (btimes2 U0 V0))
                % noo we can destory U0,..,V1
         (setq p2 (btimes2 (bdifference2inPlace U1 U0 nil)
                           (bdifference2inPlace V0 V1 nil)))
         (setq uv (bwordsshiftleft p1 (iplus2 n n)))  % the biggest part
         (setq uv (bshiftAndAddInto p1 n uv))
         (setq uv (bshiftAndAddInto p2 n uv))
         (setq uv (bshiftAndAddInto p3 n uv))
         (setq uv (bshiftAndAddInto p3 0 uv))
         (when (not (eq (igetv u 0)(igetv v 0)))
               (iputv uv 0 'bigneg))
         (return uv)))

% auxiliary routines for Karatsuba

(de bwords (u lu ilo ihi)
   % select words ilo to ihi from bignum u with length lu
   % result is a psitive bignum in any case
     (prog (v lv x)
         (when (igreaterp ihi lu)(setq ihi lu))
         (setq lv (iadd1(idifference ihi ilo)))
         (when (ilessp lv 1) (return bzero*))
         (setq v (gtpos lv))
         (setq ilo(isub1 ilo))
         (vfor (from i 1 lv 1)
               (let tmp (iplus2 i ilo))
               (do (progn
                      (setq x (igetv u tmp))
                      (iputv v i x))))
         (return (cleanstack (trimbignum1 v lv)))))


(de bwordsshiftleft(u n)
     (prog (lu v lv x)
         (setq lu (bsize u))
         (setq lv (iplus2 lu n))
         (setq v (if (bminusp u)(gtneg lv)(gtpos lv)))
         (vfor (from i 1 n 1) (do (iputv v i 0)))
         (vfor (from i (iadd1 n) lv 1)
               (let tmp (idifference i n))
               (do (progn
                      (setq x (igetv u tmp))
                      (iputv v i x))))
         (return (cleanstack (trimbignum1 v lv)))))
 
 
(de bshiftAndAddInto (v2 n v1)
  % v1 :=  v2*2**(n*bbits) + v1
  % v1 is overwritten if it is large enough
  (prog (l1 l2 l3 v3 temp)
        (setq l1 (bbsize v1)) (setq l2 (bbsize v2))
        (when (and (bbminusp v2)(not(bbminusp v1)))
              (setq v2 (bwordsshiftleft v2 n))    % v2 new
              (iputv v2 0 'bigpos) % invert sign
              (return (bdifference2inPlace v1 v2 nil)))
        (when (and (bbminusp v1) (not (bminusp v2))) 
              (setq v2 (bwordsshiftleft v2 n))    % v2 new
              (iputv v1 0 'bigpos)                % destroys v1 here
              (return (bdifference2inPlace v2 v1 nil)))
        (when (igreaterp (iplus2 l2 n) l1)
              (return (bshiftAndAddInto v1 0 (bwordsshiftleft v2 n) )))
              % now signs are equal and v1 is long enough
        (setq carry!* 0)
        (setq l3(iplus2 l2 n))
        (vfor (from i (iadd1 n) l3 1)
              (let tmp (idifference i n))
              (do (progn (setq temp (iplus2 (igetv v1 i) (igetv v2 tmp)))
                         (iputv v1 i (addcarry temp)))))
        (setq temp (iadd1 l3))
        (vfor (from i temp l1 1) (do (iputv v1 i (addcarry (igetv v1 i)))))
              % if there is a carry left we have to create a larger box
        (when (not (izerop carry!*))
              (setq v3 (gtpos (iadd1 l1)))
              (vfor (from i 1 l1 1)
                    (do (iputv v3 i (igetv v1 i))))
              (setq l1 (iadd1 l1))
              (iputv v3 l1 carry!*)
              (setq v1 v3))
        (return (cleanstack v1))))
 
 

 
(de bdifference2inPlace (v1 v2 sn1)
  % same as bdifference2, but v1 or v2 are overwritten by the result
  % Signs pre-checked and identical.
  (prog (i l1 l2 l3 v3)
        (setq l1 (bbsize v1))
        (setq l2 (bbsize v2))
        (cond ((igreaterp l2 l1) (setq l3 l1) (setq l1 l2) (setq l2 l3)
               (setq v3 v1) (setq v1 v2) (setq v2 v3) (setq sn1 (not sn1)))
              ((eq l1 l2) (setq i l1)
                          (while (and (eq (igetv v2 i) (igetv v1 i))
                                      (igreaterp i 1))
                                 (setq i (isub1 i)))
               (when (igreaterp (igetv v2 i) (igetv v1 i))
                 (setq l3 l1) (setq l1 l2) (setq l2 l3) (setq v3 v1)
                 (setq v1 v2) (setq v2 v3) (setq sn1 (not sn1)))))
        (setq v3 v1) % overwriting!
        (iputv v3 0 (if sn1 'bigneg 'bigpos))
        (setq carry!* 0)
        (vfor (from i 1 l2 1)
              (do (iputv v3 i
                         (subcarry (idifference (igetv v1 i) (igetv v2 i))))))
        (vfor (from i (iadd1 l2) l1 1)
              (do (iputv v3 i (subcarry (igetv v1 i)))))
        (return (cleanstack (trimbignum1 v3 l1)))))
 
 


% ------------------------ DIVISION ------------------------------------

(de bquotient (v1 v2) (car (bdivide v1 v2)))
(de bremainder (v1 v2) (cdr (bdivide v1 v2)))

% BDivide returns a dotted pair, (Q . R).  Q is the quotient and R is      
% the remainder.  Both are bignums.  R is of the same sign as V1.          
                                                                         
(de bdivide (v1 v2)
  (prog (l1 l2 q r v3)
        (setq l2 (bbsize v2))
        (when (izerop l2)
          (error 99 "Attempt to divide by 0 in BDIVIDE"))
        (setq l1 (bbsize v1))
        (cond ((or (ilessp l1 l2) 
                   (and (eq l1 l2) (bdivide-trivialtest v1 l1 v2 l2)))
               (return (cons bzero* v1))))
        (when (ionep l2)
          (return (bsimpledivide v1 l1 v2 (bbminusp v2))))
        (return (bharddivide v1 l1 v2 l2))))
 
(de bdivide-trivialtest(v1 l1 v2 l2)
         (ilessp (igetv v1 l1) (igetv v2 l2)))

% C is a fixnum (inum?); V1 is a bignum and L1 is its length.              
% SnC is T if C (which is positive) should be considered negative.         
% Returns quotient . remainder; each is a bignum.                          
%                                                                          
(de bsimpledivide (v1 l1 c snc)
  (prog (i p r rr sn1 v2 p)
        (setq sn1 (bbminusp v1))
        (if (or (and sn1 snc) (not (or sn1 snc)))
          (setq v2 (gtpos l1)) (setq v2 (gtneg l1)))
        (if sn1 (setq rr (gtneg 1)) (setq rr (gtpos 1)))
        (setq p (cons nil nil)) % do all heap requests before bigits come up
        (when (bigp c)(setq c (igetv c 1))) % now no more gc can occur
        (setq r 0)
        (setq i l1)
        (while (not (izerop i))
          (iputv v2 i (wquotientdouble r (igetv v1 i) c))
          (setq r *second-value*)
          (setq i (isub1 i)))
        (iputv rr 1 r)
        (setq *second-value* 0) % clear carry
        (rplaca p (trimbignum1 v2 l1)) (rplacd p (trimbignum1 rr 1)) % the pair
        (return (cleanstack p)))) 

% boxes for double precision integer arithmetic
(fluid '(box1 box2 box3 box4 box5 box6 box7))
(setq box1 (mkdouble)) (setq box2 (mkdouble)) (setq box3 (mkdouble))
(setq box4 (mkdouble)) (setq box5 (mkdouble)) (setq box6 (mkdouble))
(setq box7 (mkdouble))


(de bharddivide (u lu v lv)
  % This is an algorithm taken from Knuth.                                 
  (prog (u1 v1 a d lcv lcv1 f f2 j k lq carry temp ll m n n1 p q qbar snu 
            snv u2 x w s result)
        (setq n lv)
        (setq n1 (1+ n))
        (setq m (idifference lu lv))
        (setq lq (1+ m))
        % Deal with signs of inputs;                                       
        (setq snu (bbminusp u))
        (setq snv (bbminusp v))
        % Note that these are not extra-boolean, i.e.                      
        % for positive numbers MBinusP returns nil, for                    
        % negative it returns its argument. Thus the                       
        % test (SnU=SnV) does not reliably compare the signs of            
        % U and V;                                                         
        (cond (snu (if snv (setq q (gtpos lq)) (setq q (gtneg lq))))
              (snv (setq q (gtneg lq)))
              (t (setq q (gtpos lq))))
        (setq u1 (gtpos (1+ lu)))
        (setq result (cons nil nil))
        % U is ALWAYS stored as if one digit longer;                       
        % Compute a scale factor to normalize the long division;           
        (setq d (/i (bbase!*!*) (1+ (igetv v lv))))
        (bigtest (print (list "leading digit" (sys2int d))))
        (bigtest (print (list "scale factor " (sys2int d))))
        % Now, at the same time, I remove the sign information from U and V
        % and scale them so that the leading coefficeint in V is fairly large;
           % protect possible gc in bsmalltimes2 from bigits in the stack
        (setq x (/i d betahi!*) d (iremainder d betahi!*))
        (setq *second-value* 0)
        (setq v1 (bsmalltimes2 v d x))
        (setq d (+w d (itimes2 x betahi!*)))
                                                                           
        (setq carry 0)
        (vfor (from i 1 lu 1)
              (do (progn (setq temp (+w (wtimesdouble (igetv u i) d)
                                     carry))
                         (iputv u1 i (remainder-bbase temp))
                         (setq carry (+w *second-value*
                                             (quotient-bbase temp)))
         )))
        (setq lu (1+ lu))
        (iputv u1 lu carry)
        (bigtest (print (list "scaled u" (big2l u1))))
        (bigtest (print (list "scaled v" (big2l v1))))


        % So far all variables contain safe values,                        
        % i.e. numbers < BBase!*;                                          
        (iputv v1 0 'bigpos)
        (when (ilessp lv 2) (nonbignumerror v 'bharddivide))
        % To be safe;                                                      
        (setq lcv (igetv v1 lv))
        (setq lcv1 (igetv v1 (isub1 lv)))
        % Top two digits of the scaled V accessed once                     
        % here outside the main loop;                                      
        % Now perform the main long division loop;                         
        (ifor (from i 0 m 1) 
              (do (prog()
                        (setq j (idifference lu i))
                        (bigtest (print (list "===== loop i=" i)))

                        % J>K; working on U1[K:J] in this loop.
                        (setq k (idifference j n1))
                        (setq a (igetv u1 j))
                        (setq p (filldouble a (igetv u1 (isub1 j)) box1))
                        (bigtest (print (list "p" (d2l p))))
                        (bigtest (print (list "lcv" (sys2int lcv))))
                        (bigtest (print (list "lcv1" (sys2int lcv1))))
                        (if (eq a lcv)
                          (setq qbar (isub1 (bbase**)))
                          (setq qbar (quotientDouble2word p lcv)))
                        (bigtest (print (list "qbar" (sys2int qbar))))

                    adjust
                        % approximate next digit;                         
                         % approximate by next digit;
                              % p = u(j)*b + u(j-1)
                              % lcv = v(1)
                              % lcv1 = v(2)
                              % f = q*v(2)
                              % f2 = [u(j)*b + u(j-1) - q*v(1)]*b + u(j-2)
                              %       |----------------------| = w
                        (setq f (timesword2double qbar lcv1 box2))
                        (bigtest (print (list "f" (d2l f))))
                        (setq w (differenceDouble p
                                 (timesword2double qbar lcv box3) box4 ))
                        (bigtest (print (list "w"  (d2l w))))
                        (when (not (eq 0 (doublehigh w)))
                              (go subtract)) % f2 > b^2 > f
                        (setq f2 (filldouble
                              (doublelow w)
                              (igetv u1 (idifference j 2)) box3))
                        (bigtest (print (list "f2" (d2l f2))))

                           % Correct most overshoots in Qbar;
                        (when  (doublegreaterp f f2)
                           (setq qbar (isub1 qbar))
                           (bigtest(print(list "qbar adusted" (sys2int qbar))))
                           (go adjust))


                      subtract
                         % Ready to subtract QBar*V1 from U1;
                         % in this loop "carry" stores locally the
                         % borrow of the subtract part.
                         (setq carry 0 s 0)
                         (vfor (from l 1 n 1)
                          (let aux (+w k l))
                          (do (progn
                                 (setq w (wtimesdouble (igetv v1 l) qbar))
                                 (setq w (+x w s))
                                 (setq s (+w *second-value* carry*))
                                 (setq carry* carry)
                                 (iputv u1 aux (-c (igetv u1 aux) w))
                                 (setq carry carry*)
                          )))

                         % propagate borrows up as far as they go;
                         (setq ll (+w k n))
                         (while (and (or (not (izerop carry*))
                                         (not (izerop s)))
                                     (ilessp ll j))
                           (setq ll (1+ ll))
                           (iputv u1 ll (-c (igetv u1 ll) s))
                           (setq s 0))


                        (unless (izerop carry*)
                           % QBar was still wrong - correction step needed.
                           % This should not happen very often;
                           (bigtest (prin2t "2nd correction needed"))
                           (setq qbar (isub1 qbar))
                           % Add V1 back into U1;
                           (setq carry* 0)
                           (vfor (from l 1 n 1)
                            (let aux (+w k l))
                            (do (iputv u1 aux
                                  (+c (igetv u1 aux) (igetv v1 l)) ))  ))
                           (setq ll (+w k n))
                           (while (ilessp ll j)
                             (setq ll (1+ ll))
                             (iputv u1 ll (+c (igetv u1 ll) 0)) )
                         (iputv q (idifference lq i) qbar))))
        % End of main loop;                                                
        (setq u1 (trimbignum1 u1 (idifference lu m)))
        (setq f 0)
        (setq f2 0)
        (setq q (trimbignum1 q lq))
        % Clean up potentially wild values;                                
        (unless (bzerop u1)
               (when snu (iputv u1 0 'bigneg))
               (unless (ionep d)
                  (setq lu (bbsize u1))
                  (setq carry 0)
                  (vfor (from l lu 1 -1)
                        (do (progn
                             (setq temp(wquotientdouble carry (igetv u1 l) d))
                             (iputv u1 l temp)
                             (setq carry *second-value*))))
                  (setq u1(trimbignum1 u1 lu))   % mk 
                  (unless (izerop carry)
                      (bhardbug "remainder when unscaling" u v v1 q u1))))
        (setq *second-value* 0) % clear carry
        (rplaca result q)(rplacd result u1)
        (return (cleanstack result))))

(de bhardbug (msg u v v1 r q)
  % Because the inputs to BHardDivide are probably rather large, I am not  
  % going to rely on BldMsg to display them;                               
  (progn (prin2t "***** Internal error in BHardDivide")
         (prin2 "arg1=") (prin2t u)
         (prin2 "arg2=") (prin2t v)
         (prin2 "scaled arg2=") (prin2t v1)
         (prin2 "computed quotient=") (prin2t q)
         (prin2 "computed remainder=") (prin2t r)
         (stderror msg)))

% ------------------------------ comparisons ----------------------

(de bgreaterp (u v)
  (cond ((bbminusp u) (if (bbminusp v) (bunsignedgreaterp v u) nil))
        ((bbminusp v) u)
        (t (bunsignedgreaterp u v))))

(de blessp (u v)
  (cond ((bbminusp u) (if (bbminusp v) (bunsignedgreaterp u v) u))
        ((bbminusp v) nil)
        (t (bunsignedgreaterp v u))))

(de bgeq (u v)
  (cond ((bbminusp u) (if (bbminusp v) (bunsignedgeq v u) nil))
        ((bbminusp v) u)
        (t (bunsignedgeq u v))))

(de bleq (u v)
  (cond ((bbminusp u) (if (bbminusp v) (bunsignedgeq u v) u))
        ((bbminusp v) nil)
        (t (bunsignedgeq v u))))

(de bunsignedgreaterp (u v)
  % Compare magnitudes of two bignums;                                     
  (prog (lu lv i)
        (setq lu (bbsize u)) (setq lv (bbsize v))
        (unless (eq lu lv) (if (igreaterp lu lv) (return u) (return nil)))
        (while (and (eq (igetv u lv) (igetv v lv)) (igreaterp lv 1))
          (setq lv (isub1 lv)))
        (if (igreaterp (igetv u lv) (igetv v lv)) 
                  (return(cleanstack  u)) (return (cleanstack nil)))))

(de bunsignedgeq (u v)
  % Compare magnitudes of two unsigned bignums;                            
  (prog (lu lv)
        (setq lu (bbsize u)) (setq lv (bbsize v))
        (unless (eq lu lv)
          (if (igreaterp lu lv) (return u) (return nil)))
        (while (and (eq (igetv u lv) (igetv v lv)) (igreaterp lv 1))
          (setq lv (isub1 lv)))
        (if (igreaterp (igetv v lv) (igetv u lv))
                 (return (cleanstack nil)) (return (cleanstack u)))))

(de badd1 (v) (bsmalladd v 1))

(de bsub1 (u) (bsmalldiff u 1))

% ------------------------BIG<->FLOAT conversions -----------------

(de floatfrombignum (v)
  (cond ((bzerop v) 0.00000E+000)
        ((or (bgreaterp v bigfloathi!*) (blessp v bigfloatlow!*))
         (error 99 (list "Argument, " v " to FLOAT is too large")))
        (t (prog (res sn i j base)
                 (setq i (bbsize v))
                 (setq j (idifference i bigitsPerMantissa*))
                 (when (ilessp j 1) (setq j 1))
                 (setq base (float-expt floatbbase!* (isub1 j)))
                 (setq sn (bbminusp v))
                 (setq res  (floattimes2 (intfloat (igetv v j)) base))
                 (setq j(iadd1 j))
                 (while (not(igreaterp j i))
                     (setq base (floattimes2 base floatbbase!*))
                     (setq res (floatplus2 res
                                (floattimes2 (intfloat (igetv v j)) base))) 
                     (setq j(iadd1 j)))
                 (when sn (setq res (floattimes2 -1.0 res)))
                 (return (cleanstack res))))))

 
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
            (if (lessp x floatbbase*)
              (progn (setq bigpart (bplus2 bigpart (bnumaux (int2sys (fix x)))))
                     (setq x 0))
              (progn (setq floatpart x)
                     (setq power 0)
                     (while (geq floatpart floatbbase*)
                       % get high end of number.
                       (progn (setq floatpart (quotient floatpart floatbbase*))
                              (setq power (plus power bbits!*))))
                     (setq thispart
                      (btimes2 (btwopower power)
                                  (bnumaux (int2sys (fix floatpart)))))
                     (setq x (difference x (floatfrombignum thispart)))
                     (setq bigpart (bplus2 bigpart thispart)))))
          (when (minusp sign)
            (setq bigpart (bminus bigpart)))
          (return bigpart))))
 

(de float-expt (v1 n)
  % V1 is float, N is positive i-num
  (cond ((izerop n) 1.0000)
        ((ionep n) v1)
        (t (prog (v2)
                 (setq v2 (float-expt v1 (wshift n -1))) % quotient n 2
                 (if (izerop (wand n 1))                 % remainder n 2
                   (return (floattimes2 v2 v2))
                   (return (floattimes2 (floattimes2 v2 v1) v2)))))))
 


% -------------------------------- Input and Output ---------------- 

(setq digit2letter!* 
      '[48 49 50 51 52 53 54 55 56 57 65 66 67 68 69 70 71 72 73 74 75 76 
        77 78 79 80 81 82 83 84 85 86 87 88 89 90])


(de bchannelprin2 (channel v1)
  ((lambda (v2 myobase i ob sn)
     (while (not (izerop i))
       (progn (iputv v2 i (igetv v1 i)) (setq i (isub1 i))))
     (setq sn (bbminusp v1))

     (cond (sn (channelwritechar channel (char !-))))
     (cond
       ((neq myobase 10)
        (channelwritesysinteger channel myobase 10)
        (channelwritechar channel (char !#))))
     (setq ob (if (eq ob 10) 1000000
               (progn
                (setq ob (itimes2 ob ob))  % ob should be < 6 bits
                (setq ob (itimes2 (itimes2 ob ob) ob)))))
     (bprin channel v2 ob)
     (setq outputbase!* myobase ))

   (gtpos (bbsize v1))
    outputbase* (bbsize v1) outputbase* 0))


% divide v by 10**6, if the quotient is zero the recursion is terminated
% and the most siginifcant digit is printed (and so on down the stack)
% otherwise save the big digit (=remainder) and recurse
(de bprin (channel v ob)
  ((lambda (digit)
     (cond
       ((bzerop v) (channelwritesysinteger channel digit outputbase!*))
       (t (bprin channel v ob) (printdigit channel digit))))
   (bdivide1000000ip v ob)))
 
% print a base 10**6 digit

(de printdigit (channel d)
  (prog (d1 d2 d3 d4 d5 d6 digl ob)
 
    (setq digl digit2letter!* ob outputbase*) %local copy
 
    (setq d  (wdivide d ob)) (setq d1 *second-value*)
    (setq d  (wdivide d ob)) (setq d2 *second-value*)
    (setq d  (wdivide d ob)) (setq d3 *second-value*)
    (setq d  (wdivide d ob)) (setq d4 *second-value*)
    (setq d  (wdivide d ob)) (setq d5 *second-value*)
    (setq d  (wdivide d ob)) (setq d6 *second-value*)

    (channelwritechar channel (igetv digl d6))
    (channelwritechar channel (igetv digl d5))
    (channelwritechar channel (igetv digl d4))
    (channelwritechar channel (igetv digl d3))
    (channelwritechar channel (igetv digl d2))
    (return (channelwritechar channel (igetv digl d1)))))
 
% divide the bignum v1 (of length l1) by 100000, except the quotient is
% accumulated in the same place, the remainder, of course, ripples
% down to the bottom.  Because the argument is modified there is no need
% to CONS up a result, but simply return the remainder.
 
(de bdivide1000000ip (v1 c)
  (prog (i r l1 q)
        (setq l1 (bbsize v1))
        (setq *second-value* 0)
        (setq i l1)
        (setq q (loc (igetv v1 i)))
        (while (not (izerop i))
          (putmem q (wquotientdouble *second-value* (getmem q) c))
            % remainder still in *second-value*
          (setq q (wdifference q addressingunitsperitem))
          (setq i (isub1 i)))
        (setq r *second-value*)
        (setq *second-value* 0) % clear carry
        (trimbignum1 v1 l1)
        (when (bbminusp v1) (setq r (iminus r)))
        (return (cleanstack r))))


(de bread (s radix sn)
  % radix is < Bbase!*                                                     
  %s=string of digits, radix=base, sn=1 or -1                              
  (prog (sz accu res ch j million shortstring)
        (setq shortstring t)
        (setq j 2)
        (setq million 1)
        (setq sz (size s))
        (setq res (gtpos 1))
        (setq ch (indx s 0))
        (when (and (igeq ch (char !a)) (ileq ch (char !z)))
          (setq ch (+w (idifference ch (char !a)) 10)))
        (when (and (igeq ch (char !A)) (ileq ch (char !Z)))
          (setq ch (+w (idifference ch (char !A)) 10)))
        (when (and (igeq ch (char 0)) (ileq ch (char 9)))
          (setq ch (idifference ch (char 0))))
        (iputv res 1 0)
        (setq accu ch)
        (ifor (from i 1 sz 1)
              (do (progn (setq ch (indx s i))
                         (when (and (igeq ch (char !a)) (ileq ch (char !z)))
                           (setq ch
                            (idifference ch (idifference (char !a) 10))))
                         (when (and (igeq ch (char !A)) (ileq ch (char !Z)))
                           (setq ch
                            (idifference ch (idifference (char !A) 10))))
                         (when (and (igeq ch (char 0)) (ileq ch (char 9)))
                           (setq ch (idifference ch (char 0))))
                         (setq accu (iplus2 (itimes2 radix accu) ch ))
                         (if (eq j 6) % do breadadd in larger portions
                              (progn
                               (setq shortstring nil)
                               (setq j 1)
                               (setq res (breadadd res
                                                (itimes2 radix million) accu))
                               (setq million 1)
                               (setq accu 0))
                              (setq j (iadd1 j ))
                              (setq million (itimes2 million radix))))))
 
        (when shortstring (when (iminusp sn) (setq accu (iminus accu)))
			  (return (bnum accu)))
        (setq res (breadadd res million accu))
        (when (iminusp sn) (setq res (bminus res)))
        (return res)))


(de breadadd (v radix ch)
  (setq v (bsmalltimes2 v radix 0))
  (setq v (bsmalladd v ch)))

(de bsmalladd (v c)
  %V big, C fix.                                                           
  (cond ((izerop c) (return v))
        ((bzerop v) (return (int2big c)))
        ((bbminusp v) (bminus (bsmalldiff (bminus v) c)))
        ((iminusp c) (bsmalldiff v (iminus c)))
        (t (prog (v1 l1)
                 (setq carry!* c)
                 (setq l1 (bbsize v))
                 (setq v1 (gtpos (iadd1 l1)))
                 (vfor (from i 1 l1 1) 
                       (do (iputv v1 i (addcarry (igetv v i)))))
                 (if (ionep carry!*)
                   (iputv v1 (iadd1 l1) 1)
                   (return (cleanstack (trimbignum1 v1 l1))))
                 (return (cleanstack v1))))))

(de bnum (n)
  % Creates a Bignum of one BETA digit, value N.                           
  % N is POS or NEG                                                        
  (if (bigp n) n (bnumaux n)))

(de bnumaux (n)
  % Creates a Bignum of one BIGIT value N.
  % N is POS or NEG
  (prog (b tagn sgn)
        (when (izerop n) (return (gtpos 0)))
        (setq sgn (iminusp n))
        (setq tagn (tag n)) % bnumaux must be save at gc time!
        (setq n (inf n))
        (cond (sgn (setq b (gtneg 1))) % e.g. here
              (t (setq b (gtpos 1))))
        (setq n (mkitem tagn n))
        (when sgn (setq n (iminus n)))
        (iputv b 1 n)
        (return b)))

(de bsmalldiff (v c)
  %V big, C fix                                                            
  (cond ((izerop c) v)
        ((bzerop v) (int2big (iminus c)))
        ((bbminusp v) (bminus (bsmalladd (bminus v) c)))
        ((iminusp c) (bsmalladd v (iminus c)))
        (t (prog (v1 l1)
                 (setq carry!* c)
                 (setq l1 (bbsize v))
                 (setq v1 (gtpos l1))
                 (vfor (from i 1 l1 1) 
                       (do (iputv v1 i (subcarry (igetv v i)))))
                 (unless (izerop carry!*)
                   (stderror (bldmsg " BSmallDiff V<C %p %p%n" v c)))
                 (setq carry!* 0)   % clear bigit
                 (return (cleanstack (trimbignum1 v1 l1)))))))

(de int2big (n)
  % Creates BigNum of value N.                                             
  % From any N, BETA,INUM,FIXNUM or BIGNUM                                 
  (case (tag n) ((negint-tag posint-tag) (sys2big n)) 
        ((fixnum-tag) (sys2big (fixval (fixinf n)))) 
        ((bignum-tag) n)
	(nil (nonintegererror n 'int2big))))

% ------------------------- INSTALL ---------------------------------

% Now Install Interfacing                                                  
  (prin2t '"SetupGlobals")
  (setbits bitsperword)
  (prin2t '" ... done")

% ------------------------- input / output ---------------------------

(loadtime (progn (setq staticbig!* (gtwarray 10))))

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

% ------------------------ interface -------------------------------


% simple conventions for integer types in nbig30:

% 1) there is no legal bignum with less than two bigits.
% 2) there is no legal fixnum with more than 30 significant.

% integers with less than 28 significant bits are sysints, and
% 28 .. 30 bits are fixnums.

(compiletime
 (progn
  (ds checkifreallybig (uu)
     ((lambda (UUU) (if (igreaterp (bbsize UUU) 1) UUU
                              (sys2int (big2sysaux UUU)))) uu))
  (ds checkifreallybigornil (uu)
     ((lambda (UUU) (cond ((null UUU) NIL)
                          ((igreaterp (bbsize UUU) 1) T)
                          (t (sys2int (big2sysaux uuu))))) uu))
  (ds checkifreallybigpair (uu)
     ((lambda (UUU) (rplaca UUU (checkifreallybig (car UUU)))
                    (rplacd UUU (checkifreallybig (cdr UUU)))) uu))
))
 
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

(de bigplus2 (u v) (checkifreallybig (bplus2 u v)))
(de bigdifference (u v) (checkifreallybig (bdifference u v)))
(de bigtimes2 (u v) (checkifreallybig (btimes2 u v)))
(de bigdivide (u v) (checkifreallybigpair (bdivide u v)))
(de bigquotient (u v) (checkifreallybig (bquotient u v)))
(de bigremainder (u v) (checkifreallybig (bremainder u v)))
(de bigland (u v) (checkifreallybig (bland u v)))
(de biglor (u v) (checkifreallybig (blor u v)))
(de biglxor (u v) (checkifreallybig (blxor u v)))
(de biglshift (u v) (checkifreallybig (blshift u v)))

(de lshift (u v)
  (setq v (int2sys v))  % bigger numbers make no sense as shift amount
  (if (betap u) 
    (cond ((wlessp v (plus2 1 (minus bitsperword))) 0)
          ((wlessp v 0) (sys2int (wshift u v)))
          ((wlessp v (iquotient bitsperword 2)) (sys2int (wshift u v)))
          (t (biglshift (sys2big u) v)))
    % Use int2big, not sys2big, since we might have fixnums.
    (biglshift (int2big u) v)))

(copyd 'lsh 'lshift)

(de biggreaterp (u v) (checkifreallybigornil (bgreaterp u v)))
(de biglessp (u v) (checkifreallybigornil (blessp u v)))
(de bigadd1 (u) (checkifreallybig (badd1 u)))
(de bigsub1 (u) (checkifreallybig (bsub1 u)))
(de biglnot (u) (checkifreallybig (blnot u)))
(de bigminus (u) (checkifreallybig (bminus u)))
(de bigminusp (u) (checkifreallybigornil (bminusp u)))
(de bigonep (u) (checkifreallybigornil (bonep u)))
(de bigzerop (u) (checkifreallybigornil (bzerop u)))

% ---------------------------- GCDN -------------------------------
%
% Lehmers algorithm for numerical gcd 
% Knuth Vol 2 (2nd ed.) page 329
 

(de biggcdn (u v)
     % We are sure that both, u and v are "true" bignums with at least
     % two bigits. 
   (prog(u^ v^ A B C D TT q ttt w lu lv)
         (when (bbminusp u)(setq u (bminus u)))
         (when (bbminusp v)(setq v (bminus v)))
   L1    (when (or (not(bigp u))  (not (bigp v)))
               (return (cleanstack (biggcdn1 u v))))
         (setq lu (bbsize u) lv (bbsize v))
         (cond ((igreaterp lu lv)  (setq tt(remainder u v))
                                   (setq u v v tt)
                                   (go L1))
               ((ilessp    lu lv)  (setq v (remainder v u)) 
                                   (go L1)))
             % now u and v have equal length (first bigit of same order)
         (setq u^ (igetv u lu) v^ (igetv v lv))
         (setq A 1 B 0 C 0 D 1)
   L2    (when (or (izerop (iplus2 v^ C)) (izerop (iplus2 v^ D)))
               (go L4))
         (setq q (iquotient(iplus2 u^ A)(iplus2 v^ C)))  
         (when (not(weq q (iquotient(iplus2 u^ B)(iplus2 v^ D))))
               (go L4))
   L3    (setq TT (if (weq C 0) A (idifference A(itimes2 q C)))
               A  C
               C  TT
               TT (if (weq D 0) B (idifference B(itimes2 q D)))
               B  D
               D  TT
               TT (idifference u^ (itimes2 q v^))
               u^ v^
               v^ TT)
         (go L2)    
   L4    (if (weq B 0)
             (if (weq 0 (setq TT (remainder u v))) (return (cleanstack v))
                        (setq u v v TT))
             (progn
               (setq u^ (setq v^ (setq q 0)))
               (setq TT (cond((eq A 0) 0)
                             ((eq A 1) u)
                             (t (times A u))))
               (setq TT (cond((eq B 0) TT)
                             ((eq B 1) (plus TT v))
                             (t (plus TT (times B v)))))
               (setq w (cond((eq C 0) 0) 
                             ((eq C 1) u) 
                             (t (times C u))))
               (setq w (cond ((eq D 0) w) 
                             ((eq D 1) (plus w v))
                             (t (plus w (times D v)))))
               (setq u Tt v w)))
         (go L1)))
 
 
(de biggcdn1(u v)   % handles simple cases: at  least one number not big
                    % gcdn and wgcdn are defined in the arithmetic
     (cond((izerop v) u)
          ((and (intp u)(intp v))(wgcdn u v))
          ((not(bigp u)) 
           (cond((not (bigp v)) (gcdn u v)) 
                (T(setq v (remainder v u)) 
                  (if (izerop v) u (gcdn u v) ))))
          (t   %(not (bigp v))  
           (setq u (remainder u v)) 
           (if (izerop u) v (gcdn v u v))))) 
 
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
        (when (weq n 0) (return bzero!*))
        (when (wlessp n 0) (setq sn t))
        % Careful handling of -N in case have largest NEG, not just        
        % flip sign                                                        
        (when  sn (if (izerop (wshift n 1)) (return bigsyslow!*) 
                                            (setq n (iminus n))))
        (setq a staticbig!*) % Grab the base
        (iputv a 1 (remainder-bbase n))
        (setq n (quotient-bbase n))
        (setq b (if (izerop n) 1 2))
        (setq b (if sn (gtneg b) (gtpos b)))
        (when (not(izerop n)) (iputv b 2 n))
        (iputv b 1 (igetv a 1))
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
  (if (intp x) (and (wleq x betahi!*) (wgeq x betalow!*)) nil))

(de betarangep (x)
  % Test if SYSINT in reduced INUM range                                   
  (if (wleq x betahi!*) (wgeq x betalow!*) nil))

(de beta2p (x y)
  % Check for 2 argument arithmetic functions                              
  (when (betap x) (betap y)))

% Also from .BUILD file
% Now install the important globals for this machine
 
% Largest representable float.

(if_system VAX
  (progn
   (setq BigFloatHi!* (btimes2 (bdifference (btwopower 67) (btwopower 11))
			       (btwopower 60)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(if_system MC68000
  (progn
   % HP9836 sizes, range 10^-308 .. 10 ^308
   % I guess:  10^308 = 2 ^1025   //  15.8 digits, IEEE double ~56 bits
   % Largest representable float.
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 56)) (btwopower 961)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(if_system PDP10
  (progn
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 62)) (btwopower 65)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))
 
(if_system MIPS
  (progn % IEEE double arithmetic                   
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 53)) (btwopower 971)))
   (setq BigFloatLow!* (bminus BigFloatHi!*))))

(progn % IEEE double arithmetic
   (setq BigFloatHi!* (btimes2 (bsub1 (btwopower 53)) (btwopower 971)))
   (setq BigFloatLow!* (bminus BigFloatHi!*)))

(setq FloatSysHi!* (float SysHi!*))
(setq FloatSysLow!* (float SysLow!*))
