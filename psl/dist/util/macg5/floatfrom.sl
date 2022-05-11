%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Status:         Open Source: BSD License
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
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (ds bbsize (v) (veclen (vecinf v))))

(compiletime (ds bbminusp (v1) (eq (igetv v1 0) 'bigneg)))

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
