%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:SYMBOL-VALUES.SL
% Title:          ValueCell, UnboundP, MakeUnbound and Set
% Author:         Eric Benson
% Created:        20 August 1981
% Modified:       29-Aug-84 11:02:05 (Brian Beach)
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
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
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 15:02:42 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de unboundp (u)
  % Does U not have a value?
  (if (idp u)
    (if (weq (tag (symval (idinf u))) unbound-tag)
      t
      nil)
    (noniderror u 'unboundp)))

(de makeunbound (u)
  % Make U an unbound ID
  (if (idp u)
    (setf (symval (idinf u)) (mkitem unbound-tag (idinf u)))
    (noniderror u 'makeunbound)))

(de valuecell (u)
  % Safe access to SymVal entry
  (prog (v)
        % This guy is called from Eval
        (return (if (idp u)
                  (progn (setq v (symval (idinf u)))
                         (if (weq (tag v) unbound-tag)
                           (continuableerror '99
                            (bldmsg '"%r is an unbound ID" u) u)
                           v))
                  (noniderror u 'valuecell)))))

% This version of SET differs from the Standard Lisp report in that Exp is
% not declared fluid, in order to maintain compatibility between compiled
% and interpreted code.
(de set (exp val)
  % Assign Val to ID Exp
  (if (idp exp)
    (if (not (or (null exp) (weq exp 't)))
      (progn (setf (symval (idinf exp)) val)
             val)
      (stderror '"T and NIL cannot be SET"))
    (noniderror exp 'set)))

