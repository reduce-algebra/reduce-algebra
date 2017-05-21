% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-2013 A. Dolzmann, T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

lisp <<
   fluid '(rl_sched_rcsid!* rl_sched_copyright!*);
   rl_sched_rcsid!* :=
      "$Id$";
   rl_sched_copyright!* := "Copyright (c) 1995-2009 A. Dolzmann and T. Sturm"
>>;

module rlsched;
% Reduce logic component scheduler. Submodule of [redlog]. Service and
% black-box scheduler possibly including AM interface construction.


%% rl_mkserv('simpl,'(rl_simp),
%%    '(rl_a2s!-atl rl_a2s!-number),'((list) -1),'rl_s2a!-simpl,t);

%% rl_mkserv('thsimpl,'(rl_a2s!-atl),nil,nil,'rl_s2a!-atl,t);

%% rl_mkserv('pnf,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('nnf,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('rnf,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('cnf,'(rl_simp),nil,nil,'rl_mk!*fof,t);
%%
%% rl_mkserv('dnf,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('ex,'(rl_simp),'(rl_a2s!-varl),'((list)),'rl_mk!*fof,t);

%% rl_mkserv('ex2,'(rl_simp),'(rl_a2s!-varl),'((list)),'rl_mk!*fof,t);

%% rl_mkserv('all,'(rl_simp),'(rl_a2s!-varl),'((list)),'rl_mk!*fof,t);

%% rl_mkserv('gqe,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
%%    (list)),'rl_s2a!-gqe,t);

%% rl_mkserv('gsc,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,t);
%%
%% rl_mkserv('gsd,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,t);
%%
%% rl_mkserv('gsn,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,t);

%% rl_mkserv('apnf,'(rl_a2s!-posf),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('qe,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-qe,t);
%%
%% rl_mkserv('posqe,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,t);


%% rl_mkserv('posgqea,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
%%    (list)),'rl_s2a!-gqea,t);

%% rl_mkserv('gqea,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
%%    (list)),'rl_s2a!-gqea,t);

%% rl_mkserv('lqe,'(rl_simp rl_a2s!-atl rl_a2s!-pt),nil,nil,'rl_s2a!-gqe,t);

%% rl_mkserv('qeg,'(rl_simp),nil,nil,'rl_s2a!-simpl,t);

%% rl_mkserv('pqe,'(rl_simp),'(rl_a2s!-sf rl_a2s!-atl),
%%    '(1 (list)),'rl_s2a!-simpl,t);

%% rl_mkserv('stex,'(rl_simp),nil,nil,'rl_s2a!-simpl,t);

%% rl_mkserv('wqe,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,t);

%% rl_mkserv('wqea,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-wqea,t);

%% rl_mkserv('zsimpl,'(rl_simp),nil,nil,'rl_s2a!-simpl,t);

%% rl_mkserv('atnum,'(rl_simp),nil,nil,'aeval,t);

%% rl_mkserv('qnum,'(rl_simp),nil,nil,'aeval,t);

%% rl_mkserv('opt,'(rl_a2s!-atl rl_a2s!-targfn),
%%    '(rl_a2s!-varl rl_a2s!-number),'((list) 8),'rl_s2a!-opt,t);

%% rl_mkserv('atl,'(rl_simp),nil,nil,'rl_s2a!-atl,t);

%% rl_mkserv('matrix,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('ifacl,'(rl_simp),nil,nil,'rl_s2a!-terml,t);

%% rl_mkserv('atml,'(rl_simp),nil,nil,
%%    function(lambda x; rl_s2a!-ml(x,'rl_mk!*fof)),t);
%%
%% rl_mkserv('termml,'(rl_simp),nil,nil,
%%    function(lambda x; rl_s2a!-ml(x,'rl_s2a!-term)),t);
%%
%% rl_mkserv('ifacml,'(rl_simp),nil,nil,
%%    function(lambda x; rl_s2a!-ml(x,'rl_s2a!-term)),t);

%% rl_mkserv('qeipo,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,t);
%%
%% rl_mkserv('qews,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,t);

%% rl_mkserv('gentheo,'(rl_a2s!-atl rl_simp),'(rl_a2s!-varl),'((list)),
%%    'rl_s2a!-gqe,t);

%% rl_mkserv('tnf,'(rl_simp rl_a2s!-terml),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('terml,'(rl_simp),nil,nil,'rl_s2a!-terml,t);

%% rl_mkserv('struct,'(rl_simp),'(rl_a2s!-id),'(v),'rl_s2a!-struct,t);
%%
%% rl_mkserv('ifstruct,'(rl_simp),'(rl_a2s!-id),'(v),'rl_s2a!-struct,t);

%% rl_mkserv('varl,'(rl_simp),nil,nil,'rl_s2a!-varl,t);
%%
%% rl_mkserv('fvarl,'(rl_simp),nil,nil,'rl_s2a!-fbvarl,t);
%%
%% rl_mkserv('bvarl,'(rl_simp),nil,nil,'rl_s2a!-fbvarl,t);
%%
%% rl_mkserv('qvarl,'(rl_simp),nil,nil,'rl_s2a!-fbvarl,t);

%% rl_mkserv('decdeg1,'(rl_simp),'(rl_a2s!-decdeg1),'(fvarl),'rl_s2a!-decdeg1,t);
%%
%% rl_mkserv('decdeg,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('explats,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('mkcanonic,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('xqe,'(rl_simp),nil,nil,'rl_mk!*fof,t);
%%
%% rl_mkserv('xqea,'(rl_simp),nil,nil,'rl_s2a!-qea,t);

%% rl_mkserv('cad,'(rl_simp),'(rl_a2s!-idlist rl_a2s!-sflist),'((list) (list)),
%%    function(lambda x; rl_mk!*fof cdr x),t);

%% rl_mkserv('gcad,'(rl_simp),'(rl_a2s!-idlist rl_a2s!-sflist),'((list) (list)),
%%    'rl_s2a!-gqe,t);

%% rl_mkserv('cadporder,'(rl_simp),nil,nil,'rl_s2a!-idlist,t);
%%
%% rl_mkserv('gcadporder,'(rl_simp),nil,nil,'rl_s2a!-idlist,t);

%% rl_mkserv('cadproj,'(rl_simp),'(rl_a2s!-idlist),'((list)),
%%    function(lambda x; rl_s2a!-sflistlist cdr x),t);

%% rl_mkserv('qsat,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('qsatdimacs,'(rl_a2s!-string),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('readdimacs,'(rl_a2s!-string),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('hqe,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('ghqe,'(rl_simp),nil,nil,'rl_s2a!-ghqe,t);

%% rl_mkserv('quine,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('resolve,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('posresolve,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('tan2,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('depth,'(rl_simp),nil,nil,'aeval,t);

%% rl_mkserv('dfgprint,'(rl_simp),'(reval),'(nil),'aeval,t);

%% rl_mkserv('smt2Print,'(rl_simp),'(reval rl_a2s!-stringl),'(nil (list)),'aeval,t);

%% rl_mkserv('smt2Read,'(rl_a2s!-string),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('dpep,'(rl_simp),'(rl_a2s!-number),'(20), 'rl_mk!*fof, t);

%% rl_mkserv('vsl,'(rl_a2s!-atl),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('sign,'(rl_simp),nil,nil,'rl_mk!*fof,t);

%% rl_mkserv('sat2pol, '(rl_simp), nil, nil, function(lambda x; mk!*sq !*f2q x), t);
%% 
%% rl_mkserv('psat2pol, '(rl_simp), nil, nil, function(lambda x; mk!*sq !*f2q x), t);

%% ibalp + tplp, undocumented
%% rl_mkserv('kapur,'(rl_simp),{function(lambda x; x)},'(nil),'rl_mk!*fof,t);

%% rl_mkserv('!1equation,'(rl_simp rl_a2s!-var),'(rl_a2s!-atl),'((list)),'rl_mk!*fof,t);  % DCFSF

%% rl_mkserv('enf,'(rl_simp rl_a2s!-var),'(rl_a2s!-atl),'((list)),'rl_mk!*fof,t);  % DCFSF

%%rl_mkserv('qsatoptions,'(rl_a2s!-qsatoptions),nil,nil,'rl_s2a!-qsatoptions,t);

% Does not work, because ofsf_cadswitches is missing.
%% rl_mkserv('cadswitches,nil,nil,nil,function(lambda x; x),t);

%% rl_mkserv('expand,'(rl_simp),nil,nil,'rl_mk!*fof,t);

% Optional argument is not yet used:
%% rl_mkserv('expanda,'(rl_simpa),'(rl_simp),'(false),'rl_s2a!-qea,t);

%% rl_mkserv('qesil,'(rl_a2s!-fl),'(rl_a2s!-atl),'((list)),'rl_s2a!-fl,t);

%% rl_mkserv('dima, '(rl_a2s!-sflist rl_a2s!-sf), nil, nil, 'rl_s2a!-formulal, t);

%% rl_mkserv('tropsat, '(rl_simp), nil, nil, 'aeval, t);
%% 
%% rl_mkserv('ptropsat, '(rl_simp), nil, nil, 'aeval, t);
%% 
% tplp, undocumented
%%rl_mkserv('miniscope,'(rl_simp),'(nil),'(nil),'rl_mk!*fof,t);

% tplp, undocumented
%% rl_mkserv('skolemize,'(rl_simp),{function(lambda x; x)},'(nil),'rl_mk!*fof,t);

% Symbolic only:
%% rl_mkserv('surep,'(dummy dummy),nil,nil,nil,nil);

%% rl_mkserv('siaddatl,'(dummy dummy),nil,nil,nil,nil);

%% rl_mkserv('subfof,'(dummy dummy),nil,nil,nil,nil);

%% rl_mkserv('identifyonoff,'(reval),nil,nil,'null,nil);

%% rl_mkserv('nnfnot,'(dummy),nil,nil,nil,nil);

%% rl_mkserv('lthsimpl,'(rl_a2s!-atl),nil,nil,'rl_s2a!-atl,t);

%% rl_mkserv('posgqe,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
%%    (list)),'rl_s2a!-gqe,t);

% experimental straight-line code, undocumented on the web:
%% rl_mkserv('straightify,'(rl_simp),nil,nil,'sl_mk!*slp,t);
%% rl_alias('sfy,'straightify);
%% 
%% sl_mkserv('atnum,'(sl_simp),nil,nil,'aeval,t);
%% 
%% sl_mkserv('simpl,'(sl_simp),nil,nil,'sl_mk!*slp,t);
%% 
%% sl_mkserv('straightify,'(sl_simp),nil,nil,'sl_mk!*slp,t);
%% sl_alias('sfy,'straightify);
%% 
%% sl_mkserv('pnf,'(sl_simp),nil,nil,'sl_mk!*slp,t);
%% 
%% sl_mkserv('unstraightify,'(sl_simp),nil,nil,'rl_mk!*fof,t);
%% sl_alias('unsfy,'unstraightify);

endmodule;  % [rlsched]

module rlbboxes;  % Black box scheduler.

%% rl_mkbb('rl_simplat1, 2);
%%
%% rl_mkbb('rl_smupdknowl, 4);

%% rl_mkbb('rl_smrmknowl, 2);
%%
%% rl_mkbb('rl_smcpknowl, 1);
%%
%% rl_mkbb('rl_smmkatl, 4);
%%
%% rl_mkbb('rl_smsimpl!-impl, 5);
%%
%% rl_mkbb('rl_smsimpl!-equiv1, 5);

%% rl_mkbb('rl_negateat, 1);

%% rl_mkbb('rl_varlat, 1);

%% rl_mkbb('rl_varsubstat, 3);

%% rl_mkbb('rl_translat, 5);

%% rl_mkbb('rl_elimset, 2);

%% rl_mkbb('rl_trygauss, 5);
%% 
%% rl_mkbb('rl_varsel, 3);
%% 
%% rl_mkbb('rl_betterp, 2);
%% 
%% rl_mkbb('rl_qemkans, 2);

%% rl_mkbb('rl_ordatp, 2);

%% rl_mkbb('rl_subsumption, 3);

%% rl_mkbb('rl_transform, 7);

%% rl_mkbb('rl_sacat, 3);
%% 
%% rl_mkbb('rl_sacatlp, 2);

%% rl_mkbb('rl_bnfsimpl, 2);

%% rl_mkbb('rl_fctrat, 1);

%% rl_mkbb('rl_tordp, 2);

%% rl_mkbb('rl_a2cdl, 1);
%% 
%% rl_mkbb('rl_t2cdl, 1);

%% rl_mkbb('rl_subat, 2);

%% rl_mkbb('rl_subalchk, 1);

%% rl_mkbb('rl_eqnrhskernels, 1);

%% rl_mkbb('rl_getineq, 2);

%% rl_mkbb('rl_qefsolset, 5);

%% rl_mkbb('rl_bettergaussp, 2);
%% 
%% rl_mkbb('rl_bestgaussp, 1);

%% rl_mkbb('rl_esetunion, 2);

%% rl_mkbb('rl_structat, 2);
%%
%% rl_mkbb('rl_ifstructat, 2);

%% rl_mkbb('rl_termmlat, 1);

%% rl_mkbb('rl_multsurep, 2);

%% rl_mkbb('rl_specelim, 5);

%% rl_mkbb('rl_susipost, 2);
%% 
%% rl_mkbb('rl_susitf, 2);
%% 
%% rl_mkbb('rl_susibin, 2);

%% rl_mkbb('rl_fbqe, 2);

%% rl_mkbb('rl_qscsaat, 1);
%%
%% rl_mkbb('rl_qssubat, 2);
%%
%% rl_mkbb('rl_qsconsens, 3);
%%
%% rl_mkbb('rl_qstrycons, 4);
%%
%% rl_mkbb('rl_qsimpltestccl, 3);
%%
%% rl_mkbb('rl_qssubsumep, 3);
%%
%% rl_mkbb('rl_qstautp, 1);
%%
%% rl_mkbb('rl_qssusuat, 3);
%%
%% rl_mkbb('rl_qssiadd, 4);
%%
%% rl_mkbb('rl_qssimpl, 3);

%% rl_mkbb('rl_b2terml, 2);

%% rl_mkbb('rl_simplb, 2);
%% 
%% rl_mkbb('rl_b2atl, 2);
%% 
%% rl_mkbb('rl_bsatp, 2);

%% rl_mkbb('rl_rxffn, 1);

%% rl_mkbb('rl_mkequation, 2);

%% rl_mkbb('rl_dfgPrintV, 1);
%% 
%% rl_mkbb('rl_dfgPrintAt, 1);

%% rl_mkbb('rl_smt2PrintLogic, 0);
%% 
%% rl_mkbb('rl_smt2PrintAt, 1);

%% rl_mkbb('rl_smt2ReadAt, 1);

%% rl_mkbb('rl_vsubalchk, 1);
%% 
%% rl_mkbb('rl_vsubat, 3);

%% rl_mkbb('rl_signat, 1);

% The following are technically not blackboxes. They would become blackboxes
% when moving rl_prepfof and rl_simp to cl and calling them via the scheduler
% (instead of a the context tag). With the current design, they should not be
% called directly. Instead rl_prepfof and rl_simp should be used.

%% rl_mkbb('rl_prepat, 1);
%% 
%% rl_mkbb('rl_simpat, 1);

endmodule;

end;

end;  % of file
