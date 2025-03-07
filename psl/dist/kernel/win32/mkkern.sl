%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(off usermode)

(setf *writingasmfile t)
%(reload sys-consts)
(off pcmac)
(off usermode)
(on verboseload)
(load lap-to-asm)
(load winnt-asm)
(dskin "foreign.sl")
(dskin "bittable.sl")

(de fastcallablep(x) nil)

(put 'symval 'symbol '!s!y!m!v!a!l_)
(put 'putw   'symbol '__!p!u!t!w)
(put 'getw   'symbol '__!g!e!t!w)    

(setq *mainfound t)
       
(load hash-decls f-strings fasl-decls)

(de continuableerror(a b c)
   (print (list "ERROR:" a b c))
   (quit))

(asmout "main")
(dskin "../firstkernel.sl")
(dskin "main-sta.sl")  
(dskin "io.sl")
(dskin "intern.sl") 
(dskin "faslin.sl")
(dskin "alloc.sl")
(dskin "support.sl")
(dskin "external.sl")
(dskin "sys-supp.sl")
(dskin "../lastkernel.sl")

(asmend)
(exitlisp)
