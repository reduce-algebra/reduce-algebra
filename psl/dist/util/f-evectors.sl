%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:F-EVECTORS.SL
% Description:    
% Author:         Cris Perdue, Hewlett-Packard CRC
% Created:        8 Apr 1983
% Modified:       01 Nov 1984 (Brian Beach)
% Package:        Utilities
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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% This is a facility so the user can generate code to access
%%% evectors that runs fast.  To use this facility, LOAD (don't
%%% IMPORT) it at compiletime.  It does an (on fast-evectors),
%%% turning on the generation of faster code.  (Still, in case it
%%% is already loaded and turned off, you should turn it on
%%% explicitly.)  The feature may be turned off and on by the
%%% user.  The affected evector functions are EGetV, EPutV,
%%% EUpBV, and ESizeV.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(compiletime (load if-system))

(de esizev (v)
  (eupbv v))

(put 'egetv    'fast-function   'fast-egetv)
(put 'eputv    'fast-function   'fast-eputv)
(put 'esizev   'fast-function   'fast-esizev)
(put 'eupbv    'fast-function   'fast-esizev)

(put 'egetv    'fast-flag    '*fast-evectors)
(put 'eputv    'fast-flag    '*fast-evectors)
(put 'esizev   'fast-flag    '*fast-evectors)
(put 'eupbv    'fast-flag    '*fast-evectors)

(if_system Cray    % Tags need not to be stripped on Cray
        (progn
            (ds fast-egetv (evector index) (evecitm evector index))
            (ds fast-eputv (evector index value) (putevecitm evector
                                                             index value))
            (ds fast-esizev (evector) (eveclen evector)))

 %elsewhere    
   (progn
    (ds fast-egetv (evector index) (evecitm (evecinf evector) index))
    (ds fast-eputv (evector index value)
			(putevecitm (evecinf evector) index value))
    (ds fast-esizev (evector) (eveclen (evecinf evector)))
))

(loadtime (on fast-evectors))

% End of file.
