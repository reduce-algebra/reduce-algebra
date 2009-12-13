%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:USEFUL.SL 
% Description:  Load a lot of "useful" packages. 
% Author:       Nancy Kendzierski 
% Created:      11-Jan-84 
% Modified:     7 May 1984 1056-PDT (Nancy Kendzierski) 
% Package:      
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
% 6 May 1984 1619-PDT (Nancy Kendzierski)
%  Changed the file to load separately compiled modules, instead of dskin
%  source files to create one indivisible binary.  Added CHAR-MACRO to the
%  modules in USEFUL (formerly in the "kernel", i.e. bare-psl).  Changed
%  name of destructure files to defmacro.
% 26 Jan 1984 1604-PST (Brian Beach)
%  Corrected file name in header.
% 11 Jan 1984 2012-PST (Nancy Kendzierski)
%  Created this file to replace useful.build
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% NOTE:  The modules in USEFUL are structured so that they can be compiled
% (bootstapped) in the following order:
%
%   backquote, read1macros, char-macro, read2macros, read-macro,
%   defmacro1, defmacro2, defmacro, cond-macros, bind-macros,
%   set1-macros, set2-macros, set-macros, iter-macros, for-macro,
%   misc-macros, macroexpand, useful
%
% Modules with many parts (e.g. read1-macros, read2-macros, read-macros)
% were split into pieces because the second part required the first to
% already be compiled and loaded in order to compile itself.  The third
% part is merely a module to load both halves (so a user doesn't need to
% know the structure).
%
% NOTE:  Modules in USEFUL should not use the features in USEFUL, unless
% the feature is defined in a "previous" module, where "previous" is
% determined by compilation order.  This ensures that the module USEFUL
% can be rebuilt "from scratch".
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(load backquote char-macro read-macros defmacro cond-macros
      bind-macros set-macros iter-macros for-macro misc-macros
      macroexpand)

% End of file.

