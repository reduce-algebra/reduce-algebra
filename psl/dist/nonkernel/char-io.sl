%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:CHAR-IO.SL 
% Title:        Bottom level character IO primitives 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     31-May-84 11:04:45 (Brian Beach) 
% Package:      Kernel 
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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 1-Jan-92 (Herbert Melenk)
%  Added findposition and channelfindposition (mostly for REDUCE help system)
% 20-August-90 (Winfried Neun)
%  Changed calls to noniochannelerror to be "never-return", because there is
%  no cure for that and the code is better.
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Changed declaration of in* and out* from global to fluid.
% 31-May-84 10:13:23 (Brian Beach)
%  Changed calls on IDAPPLY1, IDAPPLY2 to use IDAPPLY.
%  Assorted cleanup.
% 01-Dec-83 14:23:04 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(in* out*))

(compiletime (load io-decls))

(on fast-integers)

(de channelfindposition (channel pos mode)
  % position file pointer to absolute byte number
   (if (or (not (and (wleq 0 channel) (wleq channel maxchannels)))
           (not (eq (wgetv writefunction channel) 'readonlychannel)))
    (noniochannelerror channel "ChannelFindPosition"))
   (setf (wgetv bufferlength  channel) -1) % invalididate buffer
   (fseek (wgetv channeltable  channel) pos mode))
   
(de findposition(pos mode) (channelfindposition in* pos mode))

(de channelreadchar (channel) 

  % Read one character from CHANNEL.
  %
  % All channel input must pass through this function.  When a channel is
  % open, its read function must be set up.
  %

  (if (not (and (wleq 0 channel) (wleq channel maxchannels)))
    (noniochannelerror channel "ChannelReadChar")
  
  (let ((char (wgetv unreadbuffer channel)))
    (if (neq char (char null))
      (progn (setf (wgetv unreadbuffer channel) (char null))
	     char)
      (idapply (wgetv readfunction channel) (list channel))
      ))
  ))


(de readchar ()

  % Read single char from current input

  (channelreadchar in*)
  )


(de channelwritechar (channel char)

  % Write one characater to CHANNEL.
  %
  % All channel output must pass through this function.  When a channel is
  % open, its write function must be set up, and line position set to zero.
  %

  (if (not (and (wleq 0 channel) (wleq channel maxchannels)))
    (noniochannelerror channel "ChannelWriteChar")

  (cond
   ((equal char (char eol))
    (setf (wgetv lineposition channel) 0)
    (setf (wgetv pageposition channel) (+ (wgetv pageposition channel) 1))
    )
   ((weq char (char tab))
    (setf (wgetv lineposition channel)
      (& (+ (wgetv lineposition channel) 8) (~ 7)))
    )
   ((weq char (char ff))
    (setf (wgetv pageposition channel) 0)
    (setf (wgetv lineposition channel) 0)
    )
   (t
    (setf (wgetv lineposition channel) (+ (wgetv lineposition channel) 1))
    ))

  (idapply (wgetv writefunction channel) (list channel char))
 ))


(de writechar (ch)

  % Write single char to current output
  
  (channelwritechar out* ch)
  )


(de channelunreadchar (channel ch)

  % Input backup function
  %
  % Any channel input backup must pass through this function.  The following
  % restrictions are made on input backup:
  %     1. Backing up without first doing input should cause an error, but
  %	 will probably cause unpredictable results.
  %     2. Only one character backup is supported.
  %

  (setf (wgetv unreadbuffer channel) ch)
  )


(de unreadchar (ch)

  % Backup on current input channel
  
  (channelunreadchar in* ch)
  )


(off fast-integers)
