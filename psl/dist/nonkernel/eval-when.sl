%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:EVAL-WHEN.SL 
% Title:        Funny business to make things happen at different times 
% Author:       Eric Benson 
% Created:      30 August 1981 
% Modified:     06-Apr-84 11:04:06 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
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
% 06-Apr-84 11:03:56 (Brian Beach)
%  Removed function STARTUPTIME.
% 21-Mar-84 15:00:04 (Jim Ambras)
%   Killed copyd of startuptime
% 01-Dec-83 14:43:05 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% Functions flagged IGNORE are evaluated immediately when invoked at the top
% level while compiling to a file.  Those flagged EVAL are evaled immediately
% and also passed to the file.  These functions are defined to make those
% actions more visible and mnemonic.
%

(dm commentoutcode (u)
  nil)

%. Comment out a single expression
(de compiletime (u)
  %. Evaluate at compile time only
  u)

% just return the already evaluated argument
(flag '(commentoutcode . (compiletime)) 'ignore)

% The functions above need only be present at compile time.  Those below must

% be present at both compile and load time to be effective.
(de bothtimes (u)
  %. Evaluate at compile and load time
  u)

(flag '(bothtimes) 'eval)

(de loadtime (u)
  %. Evaluate at load time only
  u)

(remflag '(loadtime) 'ignore)

% just to be sure it doesn't
(remflag '(loadtime) 'eval)

% happen until load time
