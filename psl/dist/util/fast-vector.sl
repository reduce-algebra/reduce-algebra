%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:FAST-VECTOR.SL 
% Description:  IGetV, IGetS, etc. 
% Author:       
% Created:      
% Modified:     19 Oct 1984 0952-PDT (Brian Beach) 
% Package:      Utilities 
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Probably the best thing to do about obtaining needed SysLisp
% features is to make sure the compiler has them at all times.

(compiletime (load if-system))

(de IGetV (v i)
  (cond ((not (Vectorp v)) (NonVectorError v 'IGetV))
	((not (FixP i)) (NonIntegerError i 'IGetV))
	(t (indx v i))
	))

(de IPutv (v i x)
  (cond ((not (Vectorp v)) (NonVectorError v 'IPutv))
	((not (FixP i)) (NonIntegerError i 'IPutv))
	(t (setindx v i x))
	))

(de ISizeV (v)
  (cond ((not (Vectorp v)) (NonVectorError v 'ISizeV))
	(t (size v))
	))

(Put 'IGetV 'Assign!-Op 'IPutV)

(de IGetS (s i)
  (cond ((not (StringP s)) (NonStringError s 'IGetS))
	((not (FixP i)) (NonIntegerError i 'IGetS))
	(t (indx s i))
	))

(de IPutS (s i c)
  (cond ((not (StringP s)) (NonStringError s 'IPutS))
	((not (FixP i)) (NonIntegerError i 'IPutS))
	((not (FixP c)) (NonCharacterError c 'IPutS))
	(t (setindx s i c))
	))

(de ISizeS (s)
  (cond ((not (StringP s)) (NonStringError s 'ISizeS))
	(t (size s))
	))

(Put 'IGetS 'Assign!-Op 'IPutS)

% Compiler declarations for fast functions.

(put 'igetv    'fast-function   'fast-igetv)
(put 'iputv    'fast-function   'fast-iputv)
(put 'igets    'fast-function   'fast-igets)
(put 'iputs    'fast-function   'fast-iputs)
(put 'isizev   'fast-function   'fast-isizev)
(put 'isizes   'fast-function   'fast-isizes)

(put 'igetv    'fast-flag   t)
(put 'iputv    'fast-flag   t)
(put 'igets    'fast-flag   t)
(put 'iputs    'fast-flag   t)
(put 'isizev   'fast-flag   t)
(put 'isizes   'fast-flag   t)

(if_system Cray      % Tags don't need to be stripped on the Cray
           (progn
            (ds fast-igetv (vector index) (vecitm vector index))
            (ds fast-iputv (vector index value) (putvecitm vector index value))
            (ds fast-igets (string index) (strbyt string index))
            (ds fast-iputs (string index value) (putstrbyt string index value))
            (ds fast-isizev (vector) (veclen vector))
            (ds fast-isizes (string) (strlen string))
            )
 %else
                     % Tags need to be stripped almost everywhere
	   (progn
	    (ds fast-igetv (vector index) (vecitm (vecinf vector) index))
	    (ds fast-iputv (vector index value) (putvecitm (vecinf vector)
							   index value))
	    (ds fast-igets (string index) (strbyt (strinf string) index))
	    (ds fast-iputs (string index value) (putstrbyt (strinf string)
							   index value))
	    (ds fast-isizev (vector) (veclen (vecinf vector)))
	    (ds fast-isizes (string) (strlen (strinf string)))
	    )
)

% End of file.
