%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:ERROR-ERRORSET.SL 
% Title:        The most basic ERROR and ERRORSET 
% Author:       Eric Benson 
% Created:      20 August 1981 
% Modified:     22-Mar-84 11:23:05 (Brian Beach) 
% Package:      Kernel 
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
% 03-Jun-87 (Harold Carr)
%  Changed LIST to NCONS in ERRORSET to avoid error message coming from
%  CATCH in pass-1.sl (during compilation).
% 26 Jan 1984 0959-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:38:15 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(global '(emsg*))

% gets current error message
(fluid '(*backtrace % controls backtrace printing (actual)
	 *inner*backtrace % controls backtrace printing (formal)
	 *emsgp % controls message printing
	 *break % controls breaking
	 breaklevel* % nesting level of breaks
	 maxbreaklevel* % maximum permitted ...
	 *continuableerror))

% if T, inside a continuable error
(loadtime
  (progn (setq *emsgp t)
         (setq *backtrace nil)
         (setq *break t)))

(de error (number message)
  %. Throw to ErrorSet
  (prog (*continuableerror)
        (setq emsg* message)
        (when *emsgp
          (errorprintf "***** %l" message)
          % Error number is not printed
          (when (and *break (lessp breaklevel* maxbreaklevel*))
            (return (break))))
        (return (progn (when *inner*backtrace
                         (backtrace))
                       (throw '$error$ number)))))

% More useful version of ERRORSET
(dm errset (u)
  ((lambda (form flag)
           (list (list 'lambda '(*emsgp)
                       (list 'catch ''$error$ (list 'ncons form)))
                 flag))
   (cadr u)
   (if (null (cddr u))
     t
     (caddr u))))

(de errorset (form *emsgp *inner*backtrace)
  % Protected Eval
  (catch '$error$ (ncons (eval form))))

%% End of File.
