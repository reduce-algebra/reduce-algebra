%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:IO-DATA.SL
% Description:  Data structures used by input and output
% Author:       Eric Benson
% Created:      4-May-84
% Modified:     26-Jun-84 15:17:39
% Package:
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
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added global declaration of $eol$.
% 11-Aug-84 (Brian Beach)
%  Changed linelength of channel 2 (bldmsg channel) to 0 (infinity).  This
%  Prevents the insertion of extraneous linefeeds in built messages.
% 4-May-84 11:20:48 (Brian Beach)
%  Translated from RLISP to LISP.
% Edit by Russ Fish, Mon Feb 27 21:02:56 1984
%  Converted to system-independent I/O package, constants to io-const.red .
% MLGriss, 9 July 1983
%       Added TerminalWriteChar as "standard" function
%       Renamed TerminalOutputHandler to TerminalWriteChar
%       Added PAGEPOSITION warray
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load io-decls sys-macros))

(global '($eol$))

(declare-wstring tokenbuffer size maxtokensize)


% All of these Channel WArrays have MaxChannels+1 (32) entries.

(declare-warray readfunction initially
                ('terminalinputhandler    % 0: StdIn!*
                 'writeonlychannel        % 1: StdOut!*, StdErr!*, PromptOut!*
                 'writeonlychannel        % 2: BldMsg()
                 'compressreadchar        % 3: Compress()
                 'writeonlychannel        % 4: FlatSize()
                 'writeonlychannel        % 5: Unix!-StdErr!*
                 'terminalinputhandler    % 6: Unix!-TTY!*
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen 'channelnotopen 'channelnotopen
                 'channelnotopen))

(declare-warray writefunction initially
                 ('readonlychannel        % 0: StdIn!*
                  'independentwritechar   % 1: StdOut!*, StdErr!*, PromptOut!*
                  'tostringwritechar      % 2: BldMsg()
                  'explodewritechar       % 3: Explode()
                  'flatsizewritechar      % 4: FlatSize()
                  'independentwritechar   % 5: Unix!-StdErr!*
                  'readonlychannel        % 6: Unix!-TTY!*
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen))

(declare-warray closefunction initially
                 ('illegalstandardchannelclose % 0: StdIn!*
                  'illegalstandardchannelclose % 1: StdOut!*, StdErr!*, PromptOut!*
                  'illegalstandardchannelclose % 2: BldMsg()
                  'illegalstandardchannelclose % 3: Compress()/Expand()
                  'illegalstandardchannelclose % 4: FlatSize()
                  'illegalstandardchannelclose % 5: Unix!-StdErr!*
                  'illegalstandardchannelclose % 6: Unix!-TTY!*
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen 'channelnotopen 'channelnotopen
                  'channelnotopen))

(declare-warray unreadbuffer size maxchannels)
(declare-warray lineposition size maxchannels)
(declare-warray pageposition size maxchannels)
(declare-warray maxline initially
           (0 80 0 0 0 80 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
              0 0 0 0 0 0))
  % 0: StdIn!*
  % 1: StdOut!*, StdErr!*, PromptOut!*
  % 2: BldMsg()
  % 3: Compress()/Explode()
  % 4: FlatSize()
  % 5: Unix!-StdErr!*
  % 6: Unix!-TTY!*

(declare-warray channelstatus initially
                 (channelopenread       % 0: StdIn!*
                  channelopenwrite      % 1: StdOut!*, StdErr!*, PromptOut!*
                  channelopenspecial    % 2: BldMsg()
                  channelopenspecial    % 3: Compress()/Explode()
                  channelopenspecial    % 4: FlatSize()
                  channelopenwrite      % 5: Unix!-StdErr!*
                  channelopenread       % 6: Unix!-TTY!*
                  channelclosed channelclosed channelclosed channelclosed
                  channelclosed channelclosed channelclosed channelclosed
                  channelclosed channelclosed channelclosed channelclosed
                  channelclosed channelclosed channelclosed channelclosed
                  channelclosed channelclosed channelclosed channelclosed
                  channelclosed channelclosed channelclosed channelclosed
                  channelclosed))

(declare-warray maxbuffer size maxchannels)
(declare-warray channeltable size maxchannels)
(declare-warray nextposition size maxchannels)
(declare-warray bufferlength size maxchannels)

(loadtime
  (setq $eol$ '!
))

