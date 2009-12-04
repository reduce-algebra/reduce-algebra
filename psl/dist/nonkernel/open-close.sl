%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:OPEN-CLOSE.SL 
% Title:        File primitives 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     31-May-84 10:46:09 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  PL:IO-DECLS.B 
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
% 31-May-84 10:44:33 (Brian Beach)
%  Calls on IDAPPLY1 --> IDAPPLY.
% 22-Mar-84 11:38:54 (Brian Beach)
%  Added compiletime load of io-decls.
% 01-Dec-83 14:56:05 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load io-decls))

(fluid '(specialreadfunction* % These must be set up for special

         specialwritefunction* % Open call

         specialclosefunction*))

(de open (filename accesstype)
  % Get access to file
  (prog (filedes)
        (cond ((weq accesstype 'input)
               (setq filedes (systemopenfileforinput filename))
               (setf (wgetv unreadbuffer filedes) (char null))
               (setf (wgetv writefunction filedes) 'readonlychannel))
              ((weq accesstype 'output)
               (setq filedes (systemopenfileforoutput filename))
               (setf (wgetv lineposition filedes) 0)
               (setf (wgetv maxline filedes) 80)
               (setf (wgetv readfunction filedes) 'writeonlychannel))
              ((weq accesstype 'special) (if (and
                                              (idp specialreadfunction*)
                                              (idp specialwritefunction*)
                                              (idp specialclosefunction*))
                 (progn (setq filedes (systemopenfilespecial filename))
                        (setf (wgetv lineposition filedes) 0)
                        (setf (wgetv maxline filedes) 80)
                        (setf (wgetv unreadbuffer filedes) (char null))
                        (setf (wgetv readfunction filedes)
                         (idinf specialreadfunction*))
                        (setf (wgetv writefunction filedes)
                         (idinf specialwritefunction*))
                        (setf (wgetv closefunction filedes)
                         (idinf specialclosefunction*)))
                 (ioerror "Improperly set-up special IO open call")))
              (t (ioerror "Unknown access type")))
        (return (mkint filedes))))

(de close (filedes)
  % End access to file
  (prog (barefiledes)
        (setq barefiledes (intinf filedes))
        (unless (and (wleq 0 barefiledes)
                     (wleq barefiledes maxchannels))
          (noniochannelerror filedes "Close"))
        (idapply (wgetv closefunction barefiledes) (list barefiledes))
        (systemmarkasclosedchannel filedes)
        (setf (wgetv readfunction barefiledes) 'channelnotopen)
        (setf (wgetv writefunction barefiledes) 'channelnotopen)
        (setf (wgetv closefunction barefiledes) 'channelnotopen)
        (return filedes)))

