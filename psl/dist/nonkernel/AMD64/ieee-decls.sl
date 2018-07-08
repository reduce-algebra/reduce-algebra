%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:ieee-decls.sl for x86_64
% Description:  IEEE 754 specific declarations for PSL, 64 bit variant
% Author:       Rainer Schöpf
% Created:      8 July 2018 
% Mode:         Lisp 
% Package:      nonkernel
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(define-constant ieeeshift (difference 12 bitsperword))
(define-constant signshift (difference 1 bitsperword))
(define-constant ieeebias 1023)
(define-constant ieeemask 2047)
(define-constant ieeemaxexp 1024)
(define-constant ieeeminexp -1023)

(ds floathiword (x) (floathighorder (inf x)))
(ds floatloword (x) (floatloworder (inf x)))

(ds ieeezerop(u)
    % ieee zero may have the sign bit set to indicate -0.0,
    % so shift the leftmost bit off the machine word before comparing with 0
    (or (weq (wshift (floathiword u) 1) 0)))

%(ds ieeemant (f) (wand (floathiword f) 16#fffffffffffff))
(ds ieeemant (f) (wshift (wshift (floathiword f) 12) -12))

(ds ieeeexpt(u)
    (wdifference (wand ieeemask 
		       (wshift (floathiword u) ieeeshift))
		 ieeebias))

(ds ieeesign (u) (wshift (floathiword u) signshift))

(ds floatequal (u v)
    (and
     (weq (floathighorder (fltinf u))
	  (floathighorder (fltinf v)))
     (weq (floatloworder (fltinf u))
	  (floatloworder (fltinf v)))
     (not (and (weq (ieeeexpt u) ieeemaxexp) (wneq (ieeemant u) 0)))
     (not (and (weq (ieeeexpt v) ieeemaxexp) (wneq (ieeemant v) 0)))
     )
)


