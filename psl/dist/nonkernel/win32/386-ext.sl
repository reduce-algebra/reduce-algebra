%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         386-spec.sl
% Title:        misc functions for 386 PSL nonkernel
% Author:       Winfried Neun
% Created:      27 October 1990
% Status:       Open Source: BSD License
% Mode:         Lisp
% Package:      Kernel
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(remd 'evlis)

(de evlis(u)
      (prog (result pointer)
	   (when (not (pairp u)) (return nil))
	   (setq pointer (setq result (cons (eval (car u)) nil)))
       loop
	   (setq u (cdr u))
	   (when (not (pairp u)) (return result))
	   (rplacd pointer (cons (eval (car u)) nil))
	   (setq pointer (cdr pointer))
	   (go loop)))

(copyd 'eval-aux 'eval)

% a simple case (alloc free) dispatch for eval

(remd 'eval)

(de eval (u)
   (prog (v)
     (case (tag u)
	((id-tag) (if (or (null u)
			(not (eq unbound-tag (tag (setq v (symval (inf u)))))))
			     (return v)
			     (return (eval-aux u))))
	((pair-tag) (return (eval-aux u)))
	((0 1 2 3 4 5 6 7 8 10 11 12 13 14 15 16 17 18 19 20 21 22 23
	  24 25 26 27 28 29 31)   (return u))  % not id or atom
) ))


	     
