%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:DOUBLE.SL 
% Description:  support for BIGNUM package with double INUM operations 
% Author:       H. Melenk                
% Created:      25 January 1989 
% Modified:	
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Open Source: BSD License
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
% 
%   Subpackage for double length integer arithmetic; a double length 
%   integer is stored in a two word vector; the digits are compatible 
%   with the bignum digits 
%   Only those routines, wich are needed in the bignum package, are 
%   defined here. 
%
%   The boxes for the results of the operations are preallocated as  
%   warrays in order to reduce the dynamic heap consumption.        
%
%   This code is machine independent; however, it uses word arithmetic
%   of full length (e.g. 32 bits).
%
%   The machine dependent parts are defined in MULSL
 
(compiletime (load if-system))
 
(compiletime
(if_system SPARC
(progn
   (defCmacro *CleanStack)
   (de *CleanStack()
       (prog (u)
         (for (from i 1 nalloc* 1)
              (do (setq u (cons `(*MOVE (reg 2) (FRAME ,i)) u))))
         (return (cons '(*MOVE (quote NIL) (reg 2)) u))))
   (put 'CleanStack1 'OpenCode
          '((*CleanStack)))
   (put 'CleanStack2 'OpenCode '((*MOVE (reg 1)(reg 1)))) % this is a dummy
   (ds Cleanstack(r)(Cleanstack2 (Cleanstack1 r)))
 )
 (progn
   (defCmacro *CleanStack)
   (de *CleanStack()
       (prog (u)
         (for (from i 1 nalloc* 1)
              (do (setq u (cons `(*MOVE (reg 2) (FRAME ,i)) u))))
         (return (cons '(*MOVE (quote NIL) (reg 2)) u))))
   (put 'CleanStack1 'OpenCode
          '((*CleanStack)))
   (put 'CleanStack2 'OpenCode '((*MOVE (reg 1)(reg 1)))) % this is a dummy
   (ds Cleanstack(r)(Cleanstack2 (Cleanstack1 r)))
 )))


(compiletime (load muls)) 
 
(ds mkdouble()
  % make a box for a double number <a b> 
   (gtwarray 2))
 

(ds doublehigh(q) (wgetv q 0)) 
(ds doublelow (q) (wgetv q 1)) 
 

(ds fillDouble (a b r)
  % fill Values into a double box.
    (progn (setf (doublehigh r) a (doublelow r) b) r))

(de quotientdouble2word(r c) 
  % divide r=<a b> by c , result is w 
    (wquotientdouble (doublehigh r)(doublelow r) c)) 
 
(de timesword2double (a b r) 
  % multiply 2 integers a b, giving a double
   (prog (u) (setq u (wtimesdouble a b))   
             (filldouble *second-value* u r)    
             (setq *second-value* 0)
             (return (cleanstack r))))
 
(de differenceDouble (q r u) 
  % subtract 2 double values
  (cleanstack
    (plus2doubleaux (doublehigh q)(doublelow q)
             (iminus (doublehigh r))(iminus (doublelow r)) u)))
  
(de plus2double (q r u)  
  % add 2 double values 
  (cleanstack
    (plus2doubleaux (doublehigh q)(doublelow q)(doublehigh r)(doublelow r) u)))

(de plus2doubleaux(q1 q2 r1 r2 u)
 (prog (b test) 
   (setq b (bbase**))  
   (setq q1 (iplus2 q1 r1)) (setq q2 (iplus2 q2 r2))
   (cond  
     ((and (ilessp q1 0) (igreaterp q2 0))  
           (setq q1 (iadd1 q1) q2 (idifference q2 b)))  
     ((and (igreaterp q1 0) (ilessp q2 0))   
           (setq q1 (isub1 q1) q2 (iplus2 q2 b) ))  
     ((igreaterp q2 b) (setq q1 (iplus2 q1 1)     
                             q2 (idifference q2 b)))  
     ((ilessp q2 (iminus b))   
                       (setq q1 (idifference q1 1)    
                             q2 (iplus2 q2 b))))  
   (fillDouble q1 q2 u)
   (return (cleanstack u)))) 
 
(de doublegreaterp (q r)
     (or (igreaterp (doublehigh q)(doublehigh r))
         (and (weq (doublehigh q)(doublehigh r))
              (igreaterp (doublelow q)(doublelow r)))))

(de double2word (q)
  % convert a double to a single value (word);
  % here a "tiny" overflow is allowed (at most one bit)
   (prog(q1 q2 b)
      (setq q1 (doublehigh q)) (setq q2 (doublelow q))
      (setq b (bbase**))
      (return (cleanstack
       (cond((izerop q1) q2)
            ((or (ilessp q1 -1) (igreaterp q1 1))
                (prin2t "****** double value not convertible to int")
                (prin2 (doublehigh (sys2int q)))(prin2"==")
                       (print (doublelow (sys2int q)))
                (error 99))
            (T (iplus2 (itimes2 b q1) q2)))))))
 

