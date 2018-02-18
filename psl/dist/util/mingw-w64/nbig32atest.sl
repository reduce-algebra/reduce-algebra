%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:nbig32atest.sl
% Package:
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

(compiletime (load muls32 fast-vector vfvect inum if-system double32))

(compiletime (on pcmac))

(de bharddivide (u lu v lv)
  % This is an algorithm taken from Knuth.                                 
  (prog (u1 v1 a d lcv lcv1 f f2 j k lq carry temp ll m n n1 p q qbar snu 
	    snv u2 x result s w)

	(for (from i 0 m 1) 
	      (do (prog ()
                         (setq j (idifference lu i))
                         (bigtest (print (list "===== loop i=" i)))

			 % J>K; working on U1[K:J]  in this loop.
			 (setq k (idifference j n1))
			 (setq a (igetv u1 j))
			 (setq p (filldouble a (igetv u1 (isub1 j)) box1))
                         (bigtest (print (list "p" (d2l p))))
                         (bigtest (print (list "lcv" (sys2int lcv))))
                         (bigtest (print (list "lcv1" (sys2int lcv1))))
			 (if (eq a lcv)
			   (setq qbar -1) 
			   (setq qbar (quotientDouble2word p lcv)))
                         (bigtest (print (list "qbar" (sys2int qbar))))

                     adjust
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
			 (for (from l 1 n 1) 
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
			   (for (from l 1 n 1) 
			    (do (iputv u1 aux 
                                  (+c (igetv u1 aux) (igetv v1 l)) ))  ))
			   (setq ll (+w k n))
			   (while (ilessp ll j)
			     (setq ll (1+ ll))
			     (iputv u1 ll (+c (igetv u1 ll) 0)) )
			 (iputv q (idifference lq i) qbar))))
	% End of main loop;                                                
	(return (cleanstack result))))
(compiletime (off pcmac))
