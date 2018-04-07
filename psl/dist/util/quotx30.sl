%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:quotx30.SL 
% Description:  Exact division for 30 bit bignum arithmetic 
% Author:       Herbert Melenk
% Created:      18 Nov 1994 
% Modified:     
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Open Source: BSD License
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
(compiletime (load muls fast-vector vfvect inum if-system double))

%------------------------- arithmetic macros -----------------------------

(compiletime (progn

  (ds +w(a b)(iplus2 a b))            % add words
  (ds +x(a b)                         % add extended (set carry*)
      (progn (setq carry* 0)(addcarry (iplus2 a b))))    
  (ds +c(a b)(addcarry (iplus2 a b))) % add with carry and set carry*
  (ds -c(a b)(subcarry (idifference a b)))

  (ds +a(x) (iplus2 x addressingunitsperitem))

  (remd '1+)
  (ds 1+(x) (iadd1 x))

  (remd '1-)
  (ds 1-(x) (isub1 x))

  (ds *m(x y)                 % (x*y) mod beta
      (wand (wtimes2 x y)(logicalbits**)))

))
%------------------------- variables -------------------------------------

(fluid '(            
		     betahi!* % Largest BetaNum as Inum                     
		     betalow!* % Smallest BetaNum as Inum                   
	 	     bigsyslow!* % Smallest SYSINT in BIG format            
		     floatsyshi!* % Largest SYSINT in Float format          
		     floatsyslow!* % Smallest SYSINT in Float format        
		     floatbbase!* % bbase as a float 
                     floatbbase-2* % 2.0 ** (bbits - 2)
		     bigfloathi!* % Largest  Float in BIG format            
		     bigfloatlow!* % Smallest Float in BIG format           
		     staticbig!* % Warray for conversion of SYS to BIG      
		     bone!* % A one                                         
		     bzero!* % A zero                                       
		     bbits!* % Number of Bits in BBASE!*                    
		     digit2letter!* carry!* outputbase!*
		     bigitsPerMantissa* % bigits needed for float conversion
		     *Karatsubabound*  % number of bigits for Karatsuba start
                     float-shift*      % for conversion bigit -> float
                     ieee-hidden-bit*
		     *second-value*))


(compiletime (ds bbsize (v) (veclen (vecinf v))))

(compiletime (ds bbminusp (v1) (eq (igetv v1 0) 'bigneg)))

(compiletime
 (ds btrailing-zeros(b)
  % b is the address of the last digit in a bignum of length n.
  % return the number of trailing zeros.
 (btrailing-zeros1 (+w (vecinf b) 
                       (wtimes2 2 addressingunitsperitem)) 
                   (bbsize b) 
                   0))) 

(de btrailing-zeros1(b n c)
 (if (wlessp n 0)
  c
  (let ((d (getmem b)))
    (if (eq d 0)
        (btrailing-zeros1 
            (+w b addressingunitsperitem) 
            (1- n)
            (+w c bbits!*))
        (progn
          (while (eq (wand d 1) 0)
                 (setq c (1+ c))
                 (setq d (wshift d -1)))
          c)))))

(compiletime
  (ds big-mod-inv(u)(big-mod-inv1 (bbase**) u 0 1))
)

(de big-mod-inv1(a b x y)
   (cond ((weq b 0) (stderror "big-mod-inv failed"))
         ((weq b 1) y)
         (t (let((w (wquotient a b)))
           (big-mod-inv1
                b
                (wdifference a (wtimes2 b w))
                y
                (wdifference x (wtimes2 y w))  )))))


(de big-quotientx(c a)
  (prog(b d x y l s w la lb lc pa ppa pb pc ppc k ai carry)
     % Skip common trailing zeroes.
    (setq x (btrailing-zeros c))
    (setq y (btrailing-zeros a))
    (when (wgreaterp y x)(return nil))
    (setq c (biglshift c (setq y (wminus y))))
    (setq a (biglshift a y))
    (when (or (not(bigp a))(not(bigp c)))
          (return (quotientx c a)))

     % Allocate result vector.
    (setq la (bbsize a) lc (bbsize c))
    (setq k (setq lb (1+ (wdifference lc la))))
    (setq x (bbminusp c) y (bbminusp a))
    (setq b (if (or (and x y)(and (not x)(not y)))
                (gtpos lb)
                (gtneg lb)))

     % set pointers.
    (setq pb (loc (igetv b 1))  
          pa (loc (igetv a 1))
          pc (loc (igetv c 1)))
    (setq ai (big-mod-inv (getmem pa))) 

       %% (dumpo pc k)

 main-loop
    (when (ilessp k 1) (go done))
    (setq d (*m ai (getmem pc)))
       %% (druck "ziffer " d)
    (putmem pb d)
    (when (eq k 1) (go done)) % dont need last subtract
    (setq pb (+a pb))
      % C <- (C - d*A) / beta
    (setq ppc pc ppa pa l 1 s 0 carry 0)
 inner-loop
    (when (wgreaterp l k) (go next))
      (setq w 
        (if (wleq l la)
            (wtimesdouble (getmem ppa) d)
            (setq *second-value* 0)))
      (setq w (+x w s))
      (setq s (+w *second-value* carry*))
      (setq carry* carry)
      (putmem ppc (-c (getmem ppc) w))
      (setq carry carry*)
      (setq l (1+ l))
      (setq ppa (+a ppa))
      (setq ppc (+a ppc))
      (go inner-loop)
      
 next
       %% (dumpo pc k)
    (setq pc (+a pc))  % equivalent to C := C/beta
    (setq k (1- k))
    (go main-loop)
done
    (return (checkifreallybig (trimbignum b)))
))

(de druck(a b)
  (console-print-string a)
  (unixputn b)
  (console-newline))

% Main entry

(de quotientx(u v)
  (if (and (bigp u)(bigp v))
      (big-quotientx u v)
      (quotient u v)))

