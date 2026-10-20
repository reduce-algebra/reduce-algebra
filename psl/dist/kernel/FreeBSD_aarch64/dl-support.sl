%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:DL-SUPPORT.SL
% Description:  System support for dynamic loading
% Author:       Winfried Neun, ZIB
% Created:      22-Jul 2013
% Status:         Open Source: BSD License
% Mode:         Lisp
% Package:      
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% $Id: dl-support.sl 5984 2021-08-28 12:31:27Z schoepf $

(on fast-integers)
(compiletime (put 'UndefinedFunction 'symbol 'UndefinedFunction))
(compiletime (put 'UndefinedFunction 'entrypoint 'UndefinedFunction))
(define-constant RTLD_LAZY 1)
(define-constant RTLD_NOW  2)


(de psl-dlopen (filename flag)
   (prog (libbb)
   (setq libbb (dlopen (strbase (strinf filename)) 1))
   (when (eq 0 libbb)
          (return (bldmsg "**** Error opening dyn lib " filename)))        
   (return libbb)
))

(de psl-dlerror ()
   (prog (mess)
   (setq mess (gtwarray 1))
   (wputv mess 0 "dlerror")
   (return mess)
))

% this does not yet do the job !! Function is not callable

(de psl-dlsym (handle symb)
  (prog (libb libbb)

   (if (idp symb)
   (setq libbb (dlsym handle (strbase (strinf (id2string symb)) )))
   (setq libbb (dlsym handle (strbase (strinf symb)) )))

   (return libbb)
))

% calling the function  arg1 points to the address to call.

(lap '((!*entry dynloadhelper expr 1)

      (*move (reg 1) (reg t1))   % function ptr to call
      (*move (reg 2) (reg 1))
      (*move (reg 3) (reg 2))
      (*move (reg 4) (reg 3))
      (*move (reg 5) (reg 4))
      (*move (reg 6) (reg 5))
      (*move (reg 7) (reg 6))
      (*move (reg 8) (reg 7))
      (STP (reg fp) (reg lr) (preindexed (reg sp) -80))
      (MOV (reg fp) (reg sp))
      (STP (reg x21) (reg x22) (displacement (reg sp) 64))
      (STP (reg x23) (reg x24) (displacement (reg sp) 48))
      (STP (reg x25) (reg x26) (displacement (reg sp) 32))
      (STP (reg x27) (reg x28) (displacement (reg sp) 16))

       (*call (reg t1))

      (LDP (reg x27) (reg x28) (displacement (reg sp) 16))
      (LDP (reg x25) (reg x26) (displacement (reg sp) 32))
      (LDP (reg x23) (reg x24) (displacement (reg sp) 48))
      (LDP (reg x21) (reg x22) (displacement (reg sp) 64))

      (LDP (reg fp) (reg lr) (postindexed (reg sp) 80))
))

% this versions is for floating results ( provided in D0 )

(lap '((!*entry dynloadhelper_float_float expr 1)

       (*move (reg 1) (reg t1))   % function ptr to call
       (LDR (reg d0) (indirect (reg 2)))
       (*move (reg 3) (reg 2))
       (*move (reg 4) (reg 3))
       (*move (reg 5) (reg 4))
       (*move (reg 6) (reg 5))
       (*move (reg 7) (reg 6))
       (*move (reg 8) (reg 7))
       (STP (reg fp) (reg lr) (preindexed (reg sp) -80))
       (MOV (reg fp) (reg sp))
       (STP (reg x21) (reg x22) (displacement (reg sp) 64))
       (STP (reg x23) (reg x24) (displacement (reg sp) 48))
       (STP (reg x25) (reg x26) (displacement (reg sp) 32))
       (STP (reg x27) (reg x28) (displacement (reg sp) 16))

       (*call (reg t1))

       (FMOV (reg d0) (reg 1))
       (LDP (reg x27) (reg x28) (displacement (reg sp) 16))
       (LDP (reg x25) (reg x26) (displacement (reg sp) 32))
       (LDP (reg x23) (reg x24) (displacement (reg sp) 48))
       (LDP (reg x21) (reg x22) (displacement (reg sp) 64))

       (LDP (reg fp) (reg lr) (postindexed (reg sp) 80))

))

(de psl-dlclose (handle)
   (dlclose handle ))

