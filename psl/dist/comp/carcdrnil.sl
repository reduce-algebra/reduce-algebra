%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PC:carcdrnil.sl 
% Title:        support of (car NIL) -> NIL, (cdr NIL) -> NIL
% Author:       Herbert Melenk, ZIB-Berlin
% Created:      21-Dec 1990
% Status:       Experimental (Do Not Distribute) 
% Mode:         Lisp 
% Package:      Compiler 
%
% Copyright (c) 1990 Konrad-Zuse-Zentrum Berlin, all rights reserved
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
%  Revisions:
%
%  Fastcar logic added by Russ Fish, U of U, 04-Jan 1990

(fluid '(*fastcar))
(setf *fastcar nil)

(de pa1r-car(form)
      `(,(if !*FastCar
           (first form)
           `(lambda(($local &&&x))
              (cond((eq ($local &&&x)(quote nil)) (quote nil))
                   ((quote t) (car ($local &&&x))))))
        ,(second form)))

(put 'car 'pass-1-reform 'pa1r-car)

(de pa1r-cdr(form)
      `(,(if !*FastCar
           (first form)
           `(lambda(($local &&&x))
              (cond((eq ($local &&&x)(quote nil)) (quote nil))
                   ((quote t) (cdr ($local &&&x))))))
        ,(second form)))

(put 'cdr 'pass-1-reform 'pa1r-cdr)

