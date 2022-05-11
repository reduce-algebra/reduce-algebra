%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:SYS-CONSTS.SL
% Description:  HPUX PSL constants needed in the compiler
% Author:       Cris Perdue
% Created:      24-Feb-84
% Modified:     27-Jun-84 09:31:48
% Mode:         Lisp
% Package:      
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

(imports '(tags))

(fluid '(system_list*))

(setq system_list* '(Darwin sixty!-four x86_64 Intel386 i386 Mac!/OS macOS unix ieee))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MACHINE DEPENDENT CONSTANTS FOR THE x86_64                           %
% Eight BYTES per LONGWORD (64 bits).                                    %
% Eight CHARACTERs per LONGWORD (64 bits).                               %
% Stack grows down, rather than UP, used to control Stack Scan loops.   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(define-constant faslin-magic  399)
(define-constant faslout-magic 399)


(define-constant tagstartingbit                 0) 
(define-constant tagbitlength                   8)
(define-constant infstartingbit                 8)
(define-constant infbitlength                   56) 
(define-constant addressingunitsperitem         8)
(define-constant charactersperword              8) 
(makeunbound 'bitsperword) % avoid ugly message in REDUCE
(define-constant bitsperword                    64)
(define-constant bitsperword2                   16)
(define-constant addressingunitsperfunctioncell 8) 
(define-constant stackdirection                 -1)

(define-constant maxargs     15)  
 
(define-constant maxrealregs     5)

% At present this is the single machine-dependent character
% (for ASCII machines).  Defined here in case cross-compilation
% is being done.  Defined for the kernel in php:scan-table.sl. /csp

(put 'eof 'charconst (char (control d)))

(define-constant maxtokensize          5000)
(define-constant bndstksize            20000)
(define-constant catchstacksize        4000)
(define-constant hash-table-size       393241)
(define-constant savesize              4)
(define-constant maxargblock           15)
(define-constant stacksize             20000)
(define-constant maxsymbols            300000)
(define-constant compressedbinaryradix 16)
