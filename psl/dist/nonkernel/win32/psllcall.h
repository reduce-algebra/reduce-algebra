
/* include file for the LISP - PSLLW communication */
/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         bps.c
% Description:  Declare bps space as a static array.
% Author:       Leigh Stoller
% Created:      18-Dec-86
% Package:      
% Status:       Open Source: BSD License
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%
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
% 
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#define    YIELD             0
#define    PUTS              1
#define    PUTINT            2
#define    PUTOCT            3
#define    NEWLINE           4
#define    PUTC              5
#define    BINARYOPENREAD    6
#define    BINARYOPENWRITE   7
#define    BINARYCLOSE       8
#define    BINARYREADBLOCK   9
#define    BINARYWRITEBLOCK 10
#define    GETDATE          12
#define    TIMC             13
#define    SIGNAL           14
#define    CD               15
#define    FGETS            16
#define    SYSTEM           17
#define    YESP             18
#define    GETTIME          19
#define    LINELENGTH       20
#define    ASKUSER          21
#define    LSEEK            22
#define    HELP             23
#define    CONNECT_OPEN     24
#define    CONNECT_CLOSE    25
#define    CONNECT_FETCH    26
#define    CONNECT_SEND     27
#define    CONNECT_ASK      28
#define    CONNECT_BLOCK    29
#define    SLEEP            30
#define    PSLL_RESET       31
#define    EXIT_WITH_STATUS 32
#define    PIPE_OPEN        33
#define    PIPE_CLOSE       34
#define    PAGE             35
#define    MENU             36
#define    WIN_PAR          37
#define    FILE_TREE        38
#define    PIPE_WRITE       39


/* functions for callback */


#define PSLCALL_TERMINAL_INTERRUPT  0
#define PSLCALL_RESIZE              1 
#define PSLCALL_GRAPHICS_MODE       3
#define PSLCALL_GRAPHICS_MODE_ON    3
#define PSLCALL_GRAPHICS_MODE_OFF   4
#define PSLCALL_MENU                5
