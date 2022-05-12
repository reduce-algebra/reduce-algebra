%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PVC:FC-INDIRECT.SL
% Description:  Builds an indirect call to a function.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      24-Apr-84
% Modified:     01-May-84 10:16:11 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
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

% version for IBM RS 6000 , Winfried Neun, ZIB ,2 january 1991

(compiletime (setq *syslisp t))

(imports '(sys-consts))

(on fast-integers)

(fluid '(symfnc))

(de define-indirect-function (calling-function called-function)

  % Build a  calling function named (calling-function) that simply calls
  % another function (called-function).
  % No knowledge of the number of arguments is needed.
  % Note that the interpreter will do no error checking on number of
  % arguments for a function defined by this routine.

  (if (member 'compiler options*)
    (lap `((*entry ,calling-function expr -1)
	   (*alloc 0)
	   (*linke 0 ,called-function expr -1)
	   ))
    (*hacked-define-indirect-function calling-function
				      called-function)
    )
  calling-function   % Return the name of the defined function
  )

(de *hacked-define-indirect-function (calling-function called-function)
  
  % Builds the function linkage by hand, without use of the compiler.
  % First, some BPS is allocated, and code is placed in it to jump to
  % the called function.
  % CODE-BASE points to the start of the segment allocated by GTBPS, where
  % the argument count resides.
  % CODE-ADDRESS points to the beginning of the actual code.

  (let* ((code-base     (gtbps 5))
	 (code-address  (loc (wgetv code-base 1)))
         (sixteen 16)
         (eighteec 16#8151)
	 (called-address 
              (wand 16#FFFF (wplus2 -32000 (* 4 (idinf called-function))))))

    (wputv code-base 0 -1)      % Number of arguments = undefined

    (wputv code-base 1 (wor (wshift eighteec 16) called-address))
                    % a  l (reg t4) ...
    (wputv code-base 2 (int2sys 16#7d4903a6)) % mtspr (reg ctr) (reg t4)
    (wputv code-base 3 (wor (idinf called-function) (wshift 16#3920 sixteen)))
    (wputv code-base 4 (int2sys 16#4e800420))  % bctr 

    % Now the code is built.  Next we make a code pointer that points to
    % it and plant it in the function cell of the newly defined function:

    (flushcache code-base 32)
    (putd calling-function 'expr (mkcode code-address))
    ))

(off fast-integers)

(compiletime (setq *syslisp NIL))
