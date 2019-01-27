%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:WFLOAT.SL
% Description:  Interface to foreign floating point functions.             
% Author:       RAM, HP/FSD                                                
% Created:      27-Feb-84                                                  
% Modified:     29-Oct-84 09:06:40 (Vicki O'Day)
% Mode:         Lisp                                                       
% Package:                                                                 
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions
%
% 04-Apr-87 (Leigh Stoller)
%  Added support for 68020 IEEE negitive zero test. See $pnk/arithmetic.sl.
% 29-Oct-86 (Leigh Stoller)
%  Removed definition of writefloat. It has been returned to write-float.sl.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(**neg-zero** **neg-one**))

(off echo)

(de *wfloat (x y)
  (uxfloat (mkitem fixnum-tag x) y))

(de *fplus2 (x y z)
  (uxplus2 (mkitem fixnum-tag x) (mkitem fixnum-tag y)
	(mkitem fixnum-tag z)))

(de *fdifference (x y z)
  (uxdifference (mkitem fixnum-tag x) (mkitem fixnum-tag y)
        (mkitem fixnum-tag z)))

(de *ftimes2 (x y z)
  (uxtimes2 (mkitem fixnum-tag x) (mkitem fixnum-tag y)
        (mkitem fixnum-tag z)))

(de *fquotient (x y z)
  (uxquotient (mkitem fixnum-tag x) (mkitem fixnum-tag y)
        (mkitem fixnum-tag z)))

(de *fminus (x y)
  (uxminus (mkitem fixnum-tag x) (mkitem fixnum-tag y)))

(de *fgreaterp (x y)
  (uxgreaterp (mkitem fixnum-tag x) (mkitem fixnum-tag y) 't 'nil))

(de *flessp (x y)
  (uxlessp (mkitem fixnum-tag x) (mkitem fixnum-tag y) 't 'nil))

(de *wfix (x)
  (uxfix (mkitem fixnum-tag x)))

(de *fassign (x y)
  (uxassign (mkitem fixnum-tag x) (mkitem fixnum-tag y)))

(de *doubletofloat (x y)
  (uxdoubletofloat (mkitem fixnum-tag x) (mkitem fixnum-tag y)))

% These two statements must be at the end of the file because times2, and
% thus *ftimes2, must be defined before it is used.

(loadtime (progn
	    (setq **neg-one** -1.0)
	    (setq **neg-zero** (times2 **neg-one** 0.0))))

(de *floattodouble (x y)
  (uxfloattodouble (mkitem fixnum-tag x) (mkitem fixnum-tag y)))

(de uxsin (r x) (uuxsin (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxcos (r x) (uuxcos (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxtan (r x)(uuxtan (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxasin (r x)(uuxasin (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxacos (r x)(uuxacos (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxatan (r x)(uuxatan (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxsqrt (r x)(uuxsqrt (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxexp (r x)(uuxexp (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxlog (r x)(uuxlog (mkitem fixnum-tag r) (mkitem fixnum-tag x)))
(de uxatan2 (r y x)(uuxatan2 (mkitem fixnum-tag r) (mkitem fixnum-tag y)(mkitem fixnum-tag x)))

