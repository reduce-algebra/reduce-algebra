%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:ONOFF.SL 
% Title:        Macros for setting/resetting flags, with SIMPFG hook 
% Author:       Martin Griss 
% Created:      21 July 1982 
% Modified:     22-Mar-84 11:38:14 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
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
% 01-Dec-83 14:55:30 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de onoff* (idlist u)
  %
  % IdList is list of variables without !* prefix, U is T or NIL
  %
  (prog (y)
        (foreach x in idlist do (if (not (idp x))
                   (noniderror x (if (null u)
                      'off
                      'on))
                   (progn (set (mkflagvar x) u)
                          (when (setq y (atsoc u (get x 'simpfg)))
                            (eval (second y))))))))

(de mkflagvar (u)
  % Should be redefined in PACKAGE.RED
  (intern (concat "*" (id2string u))))

% to lambda-bind current pkg to GLOBAL
(dm on (u)
  (list 'onoff* (mkquote (cdr u)) t))

(dm off (u)
  (list 'onoff* (mkquote (cdr u)) nil))

(flag '(on off) 'ignore)

