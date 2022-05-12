%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% The pvm externals
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
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(off r2i)

(external-function pvm_addhosts	(hosts nhost infos))
(external-function pvm_advise	(a1 a2 a3))
(external-function pvm_barrier	(group count))
(external-function pvm_bcast	(group msgtag))
(external-function pvm_bufinfo	(bufid bytes msgtag tid))
(external-function pvm_config	(nhost narch hostp))
(external-function pvm_delhosts	(hosts nhost infos))
(external-function pvm_exit	())
(external-function pvm_freebuf	(bufid))
(external-function pvm_getinst	(group tid))
(external-function pvm_getrbuf	())
(external-function pvm_getsbuf	())
(external-function pvm_gettid	(group inum))
(external-function pvm_gsize	(group))
(external-function pvm_initsend	(encoding))
(external-function pvm_joingroup (group))
(external-function pvm_kill	(tid))
(external-function pvm_lvgroup	(group))
(external-function pvm_mcast	(tids ntask msgtag))
(external-function pvm_mkbuf	(encoding))
(external-function pvm_mstat	(host))
(external-function pvm_mytid	())
(external-function pvm_notify	(what msgtag ntask tids))
(external-function pvm_nrecv	(tid msgtag))
(external-function pvm_pkbyte 	(pointer nitem stride))
(external-function pvm_pkcplx 	(pointer nitem stride) )
(external-function pvm_pkdcplx 	(pointer nitem stride) )
(external-function pvm_pkdouble	(pointer nitem stride) )
(external-function pvm_pkfloat 	(pointer nitem stride) )
(external-function pvm_pkint 	(pointer nitem stride) )
(external-function pvm_pklong 	(pointer nitem stride) )
(external-function pvm_pkshort 	(pointer nitem stride) )
(external-function pvm_pkstr 	(pointer) )
(external-function pvm_parent	())
(external-function pvm_perror	(msg))
(external-function pvm_probe	(tid msgtag))
(external-function pvm_pstat	(tid))
(external-function pvm_recv	(tid msgtag))
(external-function pvm_recvf	(new))
(external-function pvm_send	(tid msgtag))
(external-function pvm_sendsig	(tid signum))
(external-function pvm_serror	(set))
(external-function pvm_setrbuf	(bufid))
(external-function pvm_setsbuf	(bufid))
(external-function pppvm_spawn	(vvv) ) %task argv flag where ntask tids))
(external-function pvm_tasks	(where ntask taskp))
(external-function pvm_upkbyte	(pointer nitem stride))
(external-function pvm_upkcplx	(pointer nitem stride) )
(external-function pvm_upkdcplx	(pointer nitem stride) )
(external-function pvm_upkdouble (pointer nitem stride) )
(external-function pvm_upkfloat	(pointer nitem stride) )
(external-function pvm_upkint 	(pointer nitem stride) )
(external-function pvm_upklong 	(pointer nitem stride) )
(external-function pvm_upkshort	(pointer nitem stride) )
(external-function pvm_upkstr 	(pointer) )

(on r2i)
