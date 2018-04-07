%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC: BIG-FASLEND.SL
% Title:          Patch to FASLEND for huge files
% Author:         Eric Benson
% Created:        7 May 1982
% Modified:       06-Dec-83 10:00 (Brian Beach)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Compiler
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 06-Dec-83 10:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  <PSL.COMP>BIG-FASLEND.RED.4, 10-Jun-82 10:39:32, Edit by GRISS          
%  Added InitCodeMax!* for testing                                         
%                                                                          
(de compileuncompiledexpressions ()
  (errorprintf "%n*** Init code length is %w%n" 
               (length (car uncompiledexpressions!*)))
  (compileinitcode '!*!*fasl!*!*initcode!*!* (car uncompiledexpressions!*)))

(fluid '(initcodemax!*))

(loadtime
  (progn (setq initcodemax!* 350)))

(de compileinitcode (name initcodelist)
  (prog (x len lasthalf)
        (return (if (ilessp (setq len (length initcodelist)) initcodemax!*)
                  (dfprintfasl 
                   (list 'de name 'nil (cons 'progn initcodelist)))
                  (progn (errorprintf 
                          "*** Initcode length %w too large, splitting into smaller pieces"
                          len)
                         (errorprintf 
                          "*** Please use smaller files in FASL")
                         (setq x (pnth initcodelist (iquotient len 2)))
                         (setq lasthalf (cdr x))
                         (rplacd x nil)
                         % tricky, split the code in 2                     
                         (setq x 
                          (intern (concat (id2string name) (stringgensym))))
                         (flag1 x 'internalfunction)
                         % has to be internal to get called!               
                         (compileinitcode x initcodelist)
                         (compileinitcode name (cons (list x) lasthalf)))))))

% call previous                                                            
