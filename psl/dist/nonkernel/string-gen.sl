%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:STRING-GENSYM.SL
% Title:          Complement to GenSym, makes a string instead of ID
% Author:         Eric Benson
% Created:        14 January 1982
% Modified:       29-Aug-84 11:03:46 (Brian Beach)
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
% 19-Dec-86 (Leigh Stoller)
%  Added copystring to setq of stringgensym* below to make sure the string
%  in allocated in heap, not bps.
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 15:02:12 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
% Edit by Cris Perdue,  9 Feb 1983 1620-PST
% Modified to avoid using the CHAR macro in a top level form
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(stringgensym*))

% Make sure that the string ends up in heap, not bps, so we can unexec over it.
(setq stringgensym* (copystring (symnam (inf 'L0000))))

% Copy to force into heap /csp
(compiletime
  (flag '(stringgensym1) 'internalfunction))

(de stringgensym ()
  %. Generate unique string
  (stringgensym1 4))

(de stringgensym1 (n)
  %. Auxiliary function for StringGenSym
  (let (ch)
       (cond ((greaterp n 0) (if (lessp (setq ch (indx stringgensym* n))
                                  (char !9))
                (progn (setindx stringgensym* n (plus ch 1))
                       (totalcopy stringgensym*))
                (progn (setindx stringgensym* n (char !0))
                       (stringgensym1 (difference n 1)))))
             (t % Increment starting letter

                (progn (setindx stringgensym* 0
                        (plus (indx stringgensym* 0) 1))
                       (stringgensym))))))

