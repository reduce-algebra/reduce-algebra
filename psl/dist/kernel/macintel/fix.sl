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


(fluid '(bstack_exception_count bstack_exception_max))

(setq bstack_exception_count 0 )

(setq bstack_exception_max 15 )

(de bstackoverflow ()
  (setq bstack_exception_count (wplus2 1 bstack_exception_count ))
  (when (wgreaterp bstack_exception_count bstack_exception_max)
	(setq bstack_exception_count 0 )
  %      (channelprin2 errout* 
%			"***** Binding stack maximal exception terminating...")
  %      (channelterpi errout!*)
        (external_exit -1))
  (channelprin2 errout* "***** Binding stack overflow, restarting...")
  (channelwritechar errout* (char eol))
  (reset))

(de bstackunderflow ()
  (setq bstack_exception_count (wplus2 1 bstack_exception_count ))
  (when (wgreaterp bstack_exception_count bstack_exception_max)
        (setq bstack_exception_count 0 )
%        (channelprin2 errout* 
%			"***** Binding stack maximal exception terminating...")
%        (channelterpi errout!*)
        (external_exit -1))
  (channelprin2 errout* "***** Binding stack underflow, restarting...")
  (channelwritechar errout* (char eol))
  (reset))


