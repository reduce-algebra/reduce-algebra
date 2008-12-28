% ----------------------------------------------------------------------
% $Id: rlsched.red,v 1.74 2008/08/24 05:29:37 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-2008 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
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

% $Log: rlsched.red,v $
% Revision 1.74  2008/08/24 05:29:37  sturm
% Added services rlposgqe and rlposgqea.
%
% Revision 1.73  2008/05/23 07:58:56  sturm
% Added service rlqeg and implementation for ofsf.
%
% Revision 1.72  2008/01/23 16:57:47  sturm
% Added blackbox betterp for rlqevarseltry. Added experimental services
% skolemize and miniscope for tplp.
%
% Revision 1.71  2007/12/23 00:53:51  zengler
% Added service rl_readdimacs.
%
% Revision 1.70  2007/12/21 22:19:33  zengler
% Added service rl_qsatdimacs.
%
% Revision 1.69  2007/12/21 00:12:32  zengler
% Changed macro for qsatoptions (rl_a2s!-qsatoptions and rl_s2a!-qsatoptions added).
%
% Revision 1.68  2007/12/20 15:36:32  sturm
% Added service rl_qsatoptions.
% Moved procedures rl_a2s!-sflist and rl_s2a!-sflistlist from rlsched to rlami.
%
% Revision 1.67  2007/12/16 08:25:58  sturm
% Added services rlposqe and  rlposqea for (extended) positive QE.
%
% Revision 1.66  2007/11/27 11:19:32  kaesers
% Final check-in.
%
% Revision 1.65  2007/11/14 12:55:41  kaesers
% Removed one optional parameter for rlkapur.
%
% Revision 1.64  2007/09/10 15:24:54  sturm
% Two optional arguments for rlkapur.
%
% Revision 1.63  2007/07/10 09:14:36  lasaruk
% Added service pqea for probabilistic quantifier elimination with answers.
%
% Revision 1.62  2007/07/05 06:20:07  lasaruk
% Added a2s!-sf for rational number conversion. Added service pqe.
%
% Revision 1.61  2007/06/13 06:37:53  sturm
% Added module ibalpqsat and interface for rlqsat, which is ibalp_qsat.
%
% Revision 1.60  2007/04/29 17:39:58  sturm
% Introduced new service rlkapur, and a corresponding dummy procedure
% in ibalp.
%
% Revision 1.59  2006/08/02 08:12:38  sturm
% Added module clresolv.
%
% Revision 1.58  2006/06/18 08:52:52  sturm
% Fixed interface for rlexpanda (PASF).
%
% Revision 1.57  2006/05/15 21:45:12  sturm
% New service rlzsimpl (for pasf).
%
% Revision 1.56  2006/04/09 07:48:36  lasaruk
% Expansion service for answers added
%
% Revision 1.55  2006/03/14 19:43:49  strasser
% Changed line "rl_mkbb('rl_chsimpat,1);" to "rl_mkbb('rl_simpat,1);".
% This is needed for qqe.
%
% Revision 1.54  2006/03/13 20:29:30  lasaruk
% Weak quantifier elimination service added
%
% Revision 1.53  2006/03/10 21:57:04  lasaruk
% rlqewa renamed to rlwqea
%
% Revision 1.52  2006/03/07 07:41:02  lasaruk
% weak quantifier elimination with answers service rlqewa added
%
% Revision 1.51  2005/10/03 19:23:40  strasser
% Added blackboxes [rl_prepat] and [rl_chsimpat] which are needed for the
% communication of [qqe] and it's wrapper packages.
%
% Revision 1.50  2005/07/26 06:50:26  seidl
% Added third argument (additional projection polynomials) to rlcad.
%
% Revision 1.49  2005/04/13 15:29:49  lasaruk
% rl_bsatp is now called with 2 arguments as it should be
%
% Revision 1.48  2004/07/07 11:21:01  hoffelne
% added service rl_rnf for context talp (refined normal form)
%
% Revision 1.47  2003/10/21 15:23:47  gilch
% Added services rlhqe and rlghqe.
%
% Revision 1.46  2003/08/28 13:48:54  seidl
% Added service rlcadproj.
%
% Revision 1.45  2003/08/19 09:30:56  seidl
% Introduced blackbox "bsatp" (bound satisfiability predicate).
%
% Revision 1.44  2003/08/12 14:15:42  seidl
% Added blackbox rl_b2atl.
%
% Revision 1.43  2003/07/11 17:16:09  sturm
% New service rlqnum (number of quantifiers).
%
% Revision 1.42  2003/06/11 08:47:19  dolzmann
% Added black boxes rl_qssimpl and rl_qssiadd.
%
% Revision 1.41  2003/06/04 06:11:14  dolzmann
% Added black box rl_qssusuat.
%
% Revision 1.40  2003/06/03 11:22:37  dolzmann
% Added black boxes rl_qsconsens, rl_qstrycons, rl_qsimpltestccl,
% rl_qssubsumep, rl_qstautp used for the quine simplication.
%
% Revision 1.39  2003/06/01 14:44:19  seidl
% Added blackboxes rl_b2terml (bound to term list) and rl_simplb (simplify
% bound).
%
% Revision 1.38  2003/05/27 07:33:25  dolzmann
% Introduced new black box rl_qssub.
%
% Revision 1.37  2003/05/23 16:02:07  dolzmann
% Added black-box rl_qscsaat
%
% Revision 1.36  2003/05/21 09:05:21  dolzmann
% Added service rlquine.
%
% Revision 1.35  2003/02/02 22:19:32  seidl
% Changed interface for service cad.
%
% Revision 1.34  2003/01/29 15:24:49  sturm
% Added service rlexpand for context pasf. Had to split pasf_exprng for this.
%
% Revision 1.33  2003/01/29 10:43:43  sturm
% Built clean optional argument interface for rlcad and rlgcad. This was buggy.
%
% Revision 1.32  2003/01/25 11:49:41  sturm
% Changed return value and interface for rlcadporder/ofsf_cadporder and
% rlgcadporder/ofsf_gcadporder. They return a list of variables now.
% s2a conversion is done in the scheduler now. Adapted rlcad/ofsf_cad and
% rlgcad/ofsf_gcad accordingly.
%
% Revision 1.31  2003/01/13 10:01:10  dolzmann
% Added entry points for xopt.
%
% Revision 1.30  2003/01/11 17:58:01  sturm
% Added AM services rlcadporder, rlgcadporder for ofsf.
%
% Revision 1.29  2002/08/23 12:32:01  dolzmann
% Added local quantifier elimination.
%
% Revision 1.28  2002/05/29 11:46:35  sturm
% Provided ofsf_gcad() and corresponding AM interface.
%
% Revision 1.27  2002/05/28 13:22:00  sturm
% Added black box rl_fbqe() and corresponding switch rlqefb.
% That is, for ofsf, rlqe uses rlcad in case of failure now.
%
% Revision 1.26  2002/05/28 13:12:24  seidla
% Added switches rlcadpreponly, rlcadte and rlcadpbfvs, changed default for
% switch rlcadaproj to off.
%
% Revision 1.25  2002/01/25 12:38:53  sturm
% Removed obsolete optional argument [n] from ofsfcad().
%
% Revision 1.24  2002/01/16 13:04:02  seidla
% Imported CAD from rlprojects.
%
% Revision 1.23  1999/03/23 09:23:57  dolzmann
% Changed copyright information.
%
% Revision 1.22  1999/03/21 13:39:11  dolzmann
% Added black boxes rl_susipost, rl_susitf, and rl_susibin.
%
% Revision 1.21  1999/03/19 12:19:06  dolzmann
% Added service rlmkcanonic.
%
% Revision 1.20  1999/03/18 14:08:22  sturm
% Added new service rl_specelim!* in cl_qe for covering the "super
% quadratic special case' for ofsf. This method is toggled by switch
% rlsqsc, which is off by default. Context dvfsf uses cl_specelim which
% is constantly "false." Context acfsf does not use cl_qe at all.
%
% Revision 1.19  1999/01/17 16:32:12  dolzmann
% Added service rl_explats.
%
% Revision 1.18  1997/08/24 16:18:53  sturm
% Added service rl_surep with black box rl_multsurep.
% Added service rl_siaddatl.
%
% Revision 1.17  1997/08/14 10:10:47  sturm
% Renamed rldecdeg to rldecdeg1.
% Added service rldecdeg.
%
% Revision 1.16  1997/08/13 12:46:38  dolzmann
% Introduced service rldecdeg.
%
% Revision 1.15  1996/10/23 12:02:54  sturm
% Added "exceptionlist" paramter to rlgqe and rlgqea. Several quantifier
% blocks are treated correctly now.
%
% Revision 1.14  1996/10/21 06:13:52  dolzmann
% Changed interface for services rlstruct and rlifstruct: Second
% parameter is now optional, default is v.
%
% Revision 1.13  1996/10/17 13:52:25  sturm
% Introduced services rlvarl, rlfvarl, and rlbvarl. Renamed cl_varl to
% cl_varl1 for this.
%
% Revision 1.12  1996/10/07 12:03:57  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.11  1996/10/01 10:25:19  reiske
% Introduced new service rltnf and related code.
%
% Revision 1.10  1996/09/30 16:57:41  sturm
% Switched to new tableau code.
%
% Revision 1.9  1996/09/29 14:21:29  sturm
% Removed switch rlqeans. Introduced service rlqea instead.
% Also introduced corresponding service rlgqea.
%
% Revision 1.8  1996/09/05 11:17:19  dolzmann
% Changed interface for service rlatb.
% Introduced new services rl_ifacml, rl_struct, rl_ifstruct, rl_termml, and
% rl_terml.
% Introduced new black boxes rl_qefsolset, rl_bettergaussp!*, rl_bestgaussp,
% rl_esetunion, rl_structat, rl_ifstructat, and rl_termmlat.
%
% Revision 1.7  1996/08/01 11:46:18  reiske
% Introduced new services rl_natab, rl_nitab, rl_qeipo, and rl_gentheo.
% Introduced new black boxes rl_a2cdl and rl_getineq.
%
% Revision 1.6  1996/07/13 11:23:05  dolzmann
% Introduced new black box rl_smcpknowl.
%
% Revision 1.5  1996/07/07 14:37:22  sturm
% Introduced new service rl_nnfnot.
% Introduced new black box rl_eqnrhskernels.
%
% Revision 1.4  1996/05/21 17:32:42  sturm
% Added service rl_subfof and black boxes rl_subat, rl_subalchk.
%
% Revision 1.3  1996/05/12 08:28:38  sturm
% Introduced new services rlthsimpl and rlgqe.
%
% Revision 1.2  1996/04/18 14:32:33  sturm
% Fixed bugs in macro calls.
%
% Revision 1.1  1996/03/22 12:18:30  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(rl_sched_rcsid!* rl_sched_copyright!*);
   rl_sched_rcsid!* :=
      "$Id: rlsched.red,v 1.74 2008/08/24 05:29:37 sturm Exp $";
   rl_sched_copyright!* :=
      "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module rlsched;
% Reduce logic component scheduler. Submodule of [redlog]. Service and
% black-box scheduler possibly including AM interface construction.

rl_mkserv('subfof,'(dummy dummy),nil,nil,nil,nil);

rl_mkserv('identifyonoff,'(reval),nil,nil,'null,nil);

rl_mkserv('simpl,'(rl_simp),
   '(rl_a2s!-atl rl_a2s!-number),'((list) -1),'rl_s2a!-simpl,T);

rl_mkserv('thsimpl,'(rl_a2s!-atl),nil,nil,'rl_s2a!-atl,T);

rl_mkserv('lthsimpl,'(rl_a2s!-atl),nil,nil,'rl_s2a!-atl,nil);

rl_mkserv('pnf,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('apnf,'(rl_a2s!-posf),nil,nil,'rl_mk!*fof,T);

rl_mkserv('nnf,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('nnfnot,'(dummy),nil,nil,nil,nil);

rl_mkserv('rnf,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('cnf,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('dnf,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('ex,'(rl_simp),'(rl_a2s!-varl),'((list)),'rl_mk!*fof,T);

rl_mkserv('all,'(rl_simp),'(rl_a2s!-varl),'((list)),'rl_mk!*fof,T);

rl_mkserv('posgqe,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
   (list)),'rl_s2a!-gqe,T);

rl_mkserv('gqe,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
   (list)),'rl_s2a!-gqe,T);

rl_mkserv('posgqea,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
   (list)),'rl_s2a!-gqea,T);

rl_mkserv('gqea,'(rl_simp),'(rl_a2s!-atl rl_a2s!-varl),'((list)
   (list)),'rl_s2a!-gqea,T);

rl_mkserv('lqe,'(rl_simp rl_a2s!-atl rl_a2s!-pt),nil,nil,'rl_s2a!-gqe,T);

rl_mkserv('qe,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('posqe,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('qeg,'(rl_simp),nil,nil,'rl_s2a!-simpl,T);

rl_mkserv('pqe,'(rl_simp),'(rl_a2s!-sf rl_a2s!-atl),
   '(1 (list)),'rl_s2a!-simpl,T);

rl_mkserv('wqe,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('qea,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-qea,T);

rl_mkserv('posqea,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-qea,T);

rl_mkserv('pqea,'(rl_simp),'(rl_a2s!-sf rl_a2s!-atl),
   '(1 (list)),'rl_s2a!-qea,T);

rl_mkserv('wqea,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-wqea,T);

rl_mkserv('zsimpl,'(rl_simp),nil,nil,'rl_s2a!-simpl,T);

rl_mkserv('atnum,'(rl_simp),nil,nil,'aeval,T);

rl_mkserv('qnum,'(rl_simp),nil,nil,'aeval,T);

rl_mkserv('gsc,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('gsd,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('gsn,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('opt,'(rl_a2s!-atl rl_a2s!-targfn),
   '(rl_a2s!-varl rl_a2s!-number),'((list) 8),'rl_s2a!-opt,T);

rl_mkserv('atl,'(rl_simp),nil,nil,'rl_s2a!-atl,T);

rl_mkserv('atml,'(rl_simp),nil,nil,
   function(lambda x; rl_s2a!-ml(x,'rl_mk!*fof)),T);

rl_mkserv('matrix,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('ifacl,'(rl_simp),nil,nil,'rl_s2a!-terml,T);

rl_mkserv('ifacml,'(rl_simp),nil,nil,
   function(lambda x; rl_s2a!-ml(x,'rl_s2a!-term)),T);

rl_mkserv('tab,'(rl_simp rl_a2s!-atl),nil,nil,'rl_mk!*fof,T);

rl_mkserv('atab,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('itab,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('qeipo,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('qews,'(rl_simp),'(rl_a2s!-atl),'((list)),'rl_s2a!-simpl,T);

rl_mkserv('gentheo,'(rl_a2s!-atl rl_simp),'(rl_a2s!-varl),'((list)),
   'rl_s2a!-gqe,T);

rl_mkserv('tnf,'(rl_simp rl_a2s!-terml),nil,nil,'rl_mk!*fof,T);

rl_mkserv('terml,'(rl_simp),nil,nil,'rl_s2a!-terml,T);

rl_mkserv('termml,'(rl_simp),nil,nil,
   function(lambda x; rl_s2a!-ml(x,'rl_s2a!-term)),T);

rl_mkserv('struct,'(rl_simp),'(rl_a2s!-id),'(v),'rl_s2a!-struct,T);

rl_mkserv('ifstruct,'(rl_simp),'(rl_a2s!-id),'(v),'rl_s2a!-struct,T);

rl_mkserv('varl,'(rl_simp),nil,nil,'rl_s2a!-varl,T);

rl_mkserv('fvarl,'(rl_simp),nil,nil,'rl_s2a!-fbvarl,T);

rl_mkserv('bvarl,'(rl_simp),nil,nil,'rl_s2a!-fbvarl,T);

rl_mkserv('decdeg1,'(rl_simp),'(rl_a2s!-decdeg1),'(fvarl),'rl_s2a!-decdeg1,T);

rl_mkserv('decdeg,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('explats,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('mkcanonic,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('surep,'(dummy dummy),nil,nil,nil,nil);

rl_mkserv('siaddatl,'(dummy dummy),nil,nil,nil,nil);

rl_mkserv('xqe,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('xqea,'(rl_simp),nil,nil,'rl_s2a!-qea,T);

rl_mkserv('cad,'(rl_simp),'(rl_a2s!-idlist rl_a2s!-sflist),'((list) (list)),
   function(lambda x; rl_mk!*fof cdr x),T);

rl_mkserv('gcad,'(rl_simp),'(rl_a2s!-idlist rl_a2s!-sflist),'((list) (list)),
   'rl_s2a!-gqe,T);

rl_mkserv('cadporder,'(rl_simp),nil,nil,'rl_s2a!-idlist,T);

rl_mkserv('gcadporder,'(rl_simp),nil,nil,'rl_s2a!-idlist,T);

rl_mkserv('cadproj,'(rl_simp),'(rl_a2s!-idlist),'((list)),
   function(lambda x; rl_s2a!-sflistlist cdr x),T);

rl_mkserv('kapur,'(rl_simp),{function(lambda x; x)},'(nil),'rl_mk!*fof,T);

rl_mkserv('miniscope,'(rl_simp),'(nil),'(nil),'rl_mk!*fof,T);

rl_mkserv('skolemize,'(rl_simp),{function(lambda x; x)},'(nil),'rl_mk!*fof,T);

rl_mkserv('qsat,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('qsatoptions,'(rl_a2s!-qsatoptions),nil,nil,'rl_s2a!-qsatoptions,T);

rl_mkserv('qsatdimacs,'(rl_a2s!-string),nil,nil,'rl_mk!*fof,T);

rl_mkserv('readdimacs,'(rl_a2s!-string),nil,nil,'rl_mk!*fof,T);

rl_mkserv('cadswitches,nil,nil,nil,function(lambda x; x),T);

rl_mkserv('expand,'(rl_simp),nil,nil,'rl_mk!*fof,T);

% Optional argument is not yet used:
rl_mkserv('expanda,'(rl_simpa),'(rl_simp),'(false),'rl_s2a!-qea,T);

rl_mkserv('hqe,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('ghqe,'(rl_simp),nil,nil,'rl_s2a!-ghqe,T);

rl_mkserv('quine,'(rl_simp),nil,nil,'rl_mk!*fof,T);

rl_mkserv('resolve,'(rl_simp),nil,nil,'rl_mk!*fof,T);

% Black box scheduler.

rl_mkbb('rl_simplat1,2);

rl_mkbb('rl_smupdknowl,4);

rl_mkbb('rl_smrmknowl,2);

rl_mkbb('rl_smcpknowl,1);

rl_mkbb('rl_smmkatl,4);

rl_mkbb('rl_smsimpl!-impl,5);

rl_mkbb('rl_smsimpl!-equiv1,5);

rl_mkbb('rl_negateat,1);

rl_mkbb('rl_varlat,1);

rl_mkbb('rl_varsubstat,3);

rl_mkbb('rl_translat,5);

rl_mkbb('rl_elimset,2);

rl_mkbb('rl_trygauss,5);

rl_mkbb('rl_varsel,3);

rl_mkbb('rl_betterp,2);

rl_mkbb('rl_qemkans,2);

rl_mkbb('rl_ordatp,2);

rl_mkbb('rl_subsumption,3);

rl_mkbb('rl_transform,2);

rl_mkbb('rl_updatr,2);

rl_mkbb('rl_sacat,3);

rl_mkbb('rl_sacatlp,2);

rl_mkbb('rl_bnfsimpl,2);

rl_mkbb('rl_fctrat,1);

rl_mkbb('rl_tordp,2);

rl_mkbb('rl_a2cdl,1);

rl_mkbb('rl_t2cdl,1);

rl_mkbb('rl_subat,2);

rl_mkbb('rl_subalchk,1);

rl_mkbb('rl_eqnrhskernels,1);

rl_mkbb('rl_getineq,2);

rl_mkbb('rl_qefsolset,5);

rl_mkbb('rl_bettergaussp,2);

rl_mkbb('rl_bestgaussp,1);

rl_mkbb('rl_esetunion,2);

rl_mkbb('rl_structat,2);

rl_mkbb('rl_ifstructat,2);

rl_mkbb('rl_termmlat,1);

rl_mkbb('rl_multsurep,2);

rl_mkbb('rl_specelim,5);

rl_mkbb('rl_susipost,2);

rl_mkbb('rl_susitf,2);

rl_mkbb('rl_susibin,2);

rl_mkbb('rl_fbqe,1);

rl_mkbb('rl_qscsaat,1);

rl_mkbb('rl_qssubat,2);

rl_mkbb('rl_qsconsens,3);

rl_mkbb('rl_qstrycons,4);

rl_mkbb('rl_qsimpltestccl,3);

rl_mkbb('rl_qssubsumep,3);

rl_mkbb('rl_qstautp,1);

rl_mkbb('rl_qssusuat,3);

rl_mkbb('rl_qssiadd,4);

rl_mkbb('rl_qssimpl,3);

rl_mkbb('rl_b2terml,2);

rl_mkbb('rl_simplb,2);

rl_mkbb('rl_b2atl,2);

rl_mkbb('rl_bsatp,2);

rl_mkbb('rl_prepat,1);

rl_mkbb('rl_simpat,1);

rl_mkbb('rl_rxffn,1);

endmodule;  % [rlsched]

end;  % of file
