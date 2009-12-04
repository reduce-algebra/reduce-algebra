%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:RDS-WRS.SL 
% Title:        Switch the current input or output channel 
% Author:       Eric Benson 
% Created:      28 August 1981 
% Modified:     22-Mar-84 11:54:15 (Brian Beach) 
% Package:      Kernel 
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
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% 22-Mar-84 11:54:08 (Brian Beach)
%  Added compile time load of io-decls.
% 01-Dec-83 15:00:39 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load io-decls))

(global '(specialrdsaction*   % possibly apply to old and new channel
          specialwrsaction*)) % ditto

(fluid '(in* out*))

(fluid '(stdin* % Standard input - may be rebound
	 stdout*))

% Standard output - may be rebound
(de rds (channel)
  % Switch input channels, return old
  (prog (oldin readfn)
        (when specialrdsaction*
          (apply specialrdsaction* (list in* channel)))
        (setq oldin in*)
        (when (null channel)
          (setq channel stdin*))
        (setq readfn (wgetv readfunction (intinf channel)))
        (when (or (weq readfn 'channelnotopen)
                  (weq readfn 'writeonlychannel))
          (return (channelerror channel
                   "Channel not open for input in RDS")))
        (setf in* channel)
        (return oldin)))

(de wrs (channel)
  % Switch output channels, return old
  (prog (oldout writefn)
        (when specialwrsaction*
          (apply specialwrsaction* (list out* channel)))
        (setq oldout out*)
        (when (null channel)
          (setq channel stdout*))
        (setq writefn (wgetv writefunction (intinf channel)))
        (when (or (weq writefn 'channelnotopen)
                  (weq writefn 'readonlychannel))
          (return (channelerror channel
                   "Channel not open for output in WRS")))
        (setf out* channel)
        (return oldout)))

