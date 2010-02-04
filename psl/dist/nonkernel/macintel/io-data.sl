%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:IO-DATA.SL
% Description:  Data structures used by input and output
% Author:       Eric Benson
% Created:      4-May-84
% Modified:     26-Jun-84 15:17:39
% Package:
%
% (c) Copyright 1987, University of Utah, all rights reserved.
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

