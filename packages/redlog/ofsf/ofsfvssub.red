% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2015 M. Kosta, T. Sturm
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
   fluid '(ofsfvssub_rcsid!* ofsfvssub_copyright!*);
   ofsfvssub_rcsid!* :=
      "$Id$";
   ofsfvssub_copyright!* := "(c) 2015 M. Kosta, T. Sturm"
>>;

module ofsfvssub;

%%% VS %%%
% constructors and access functions

asserted procedure vssu_arp(vs: VSsu): Boolean;
   % VS arbitrary predicate.
   pairp vs and car vs eq 'vsar;

asserted procedure vssu_dgp(vs: VSsu): Boolean;
   % VS degree shift predicate.
   pairp vs and car vs eq 'vsdg;

asserted procedure vssu_vpp(vs: VSsu): Boolean;
   % VS test point substitution predicate.
   pairp vs and car vs eq 'vsvs;

asserted procedure vsar_mk(v: Kernel): VSsu;
   % VS arbitrary make.
   {'vsar, v};

asserted procedure vsar_v(vs: VSar): Kernel;
   % VS arbitrary variable.
   nth(vs, 2);

asserted procedure vsdg_mk(v: Kernel, g: Integer, sv: Kernel): VSsu;
   % VS degree shift make.
   {'vsdg, v, g, sv};

asserted procedure vsdg_v(vs: VSdg): Kernel;
   % VS degree shift variable.
   nth(vs, 2);

asserted procedure vsdg_g(vs: VSdg): Integer;
   % VS degree shift gcd.
   nth(vs, 3);

asserted procedure vsdg_sv(vs: VSdg): Kernel;
   % VS degree shift shadow variable.
   nth(vs, 4);

asserted procedure vsvs_mk(v: Kernel, tp: VStp): VSsu;
   % VS test point substitution make.
   {'vsvs, v, tp};

asserted procedure vsvs_v(vs: VSvs): Kernel;
   % VS test point substitution variable.
   nth(vs, 2);

asserted procedure vsvs_tp(vs: VSvs): VStp;
   % VS test point substitution test point.
   nth(vs, 3);

%%% VS data for virtual subsitution %%%
% constructors and access functions

asserted procedure vsds_new(): VSds;
   % VS data for virtual substitution new.
   begin scalar ds;
      ds := mkvect(6);
      putv(ds, 0, 'vsds);
      putv(ds, 1, 'undefined);        % [vs]: virtual substitution
      putv(ds, 2, 'undefined);        % [f]: quantifier-free formula
      putv(ds, 3, 'undefined);        % [bvl]: do not make assumptions on variables in [bvl]
      putv(ds, 4, 'undefined);        % [ptheo]: persistent theory
      putv(ds, 5, 'undefined);        % [ttheo]: temporary theory
      putv(ds, 6, 'undefined);        % [data]: CollectedData
      return ds
   end;

%DS
% CollectedData ::= QfFormula

procedure vsds_vs(ds);                          getv(ds, 1);
procedure vsds_f(ds);                           getv(ds, 2);
procedure vsds_bvl(ds);                         getv(ds, 3);
procedure vsds_ptheo(ds);                       getv(ds, 4);
procedure vsds_ttheo(ds);                       getv(ds, 5);
procedure vsds_data(ds);                        getv(ds, 6);

procedure vsds_putvs(ds, vs);                   putv(ds, 1, vs);
procedure vsds_putf(ds, f);                     putv(ds, 2, f);
procedure vsds_putbvl(ds, bvl);                 putv(ds, 3, bvl);
procedure vsds_putptheo(ds, ptheo);             putv(ds, 4, ptheo);
procedure vsds_putttheo(ds, ttheo);             putv(ds, 5, ttheo);
procedure vsds_putdata(ds, data);               putv(ds, 6, data);

asserted procedure vsds_mk(vs: VSsu, f: QfFormula, bvl: KernelL, ptheo: Theory, ttheo: Theory): VSds;
   begin scalar ds;
      ds := vsds_new();
      vsds_putvs(ds, vs);
      vsds_putf(ds, f);
      vsds_putbvl(ds, bvl);
      vsds_putptheo(ds, ptheo);
      vsds_putttheo(ds, ttheo);
      vsds_putdata(ds, nil);
      return ds
   end;

asserted procedure vsds_mkfrom(ds: VSds): VSds;
   begin scalar nds;
      nds := vsds_new();
      vsds_putvs(nds, vsds_vs ds);
      vsds_putf(nds, vsds_f ds);
      vsds_putbvl(nds, vsds_bvl ds);
      vsds_putptheo(nds, vsds_ptheo ds);
      vsds_putttheo(nds, vsds_ttheo ds);
      vsds_putdata(nds, vsds_data ds);
      return nds
   end;

%%% "real" procedures %%%

asserted procedure qff_applysub(vs: VSsu, f: QfFormula, bvl: KernelL, theo: Theory): QfFormulaL;
   % This is the usual entry point.
   % wrapper
   begin scalar ds, ff;
      ds := vsds_mk(vs, f, bvl, theo, nil);
      vsds_apply ds;
      ff := vsds_data ds;
      % TODO: Simplify [f] here!
      return vs_splitor ff
   end;

asserted procedure vsds_apply(ds: VSds);
   begin scalar vs, f, ff;
      vs := vsds_vs ds;
      f := vsds_f ds;
      ff := if vssu_arp vs then
      	 vsar_apply(vs, f)
      else if vssu_dgp vs then
      	 vsdg_apply(vs, f)
      else if vssu_vpp vs then
      	 vsvs_apply(vs, f);
      vsds_putdata(ds, ff)
   end;

asserted procedure vsar_apply(vs: VSar, f: QfFormula): QfFormula;
   % VS arbitrary apply. It should be never needed to apply this VS.
   <<
      assert(nil);
      f
   >>;

asserted procedure vsdg_apply(vs: VSdg, f: QfFormula): QfFormula;
   % VS degree shift apply.
   begin
      f := cl_apply2ats1(f, 'vsdg_decdeg, {vsdg_v vs, vsdg_g vs, vsdg_sv vs});
      if not evenp vsdg_g vs then
	 return f;
      return rl_mk2('and, ofsf_0mk2('geq, vsdg_sv vs), f)
   end;

asserted procedure vsvs_apply(vs: VSvs, f: QfFormula): QfFormula;
   % VS test point substitution apply.
   % TEMPORARY! Using old code to have something runnable.
   begin scalar v, tp;
      v := vsvs_v vs;
      tp := vsvs_tp vs;
      return cdr apply(car tp, nil . nil . f . v . cdr tp)
   end;

asserted procedure vsdg_decdeg(at: QfFormula, v: Kernel, g: Integer, sv: Kernel): QfFormula;
   % Decrement degree of atomic formula. Replace each occurence of
   % [v^n] by [sv^(n/g)].
   begin scalar f;
      % assert(at is atomic);
      f := rl_arg2l at;
      f := sfto_decdegf(f, v, g);
      return ofsf_0mk2(rl_op at, sfto_renamef(f, v, sv))
   end;

% TODO: Move the following procedure to cl.
asserted procedure vs_splitor(f: QfFormula): QfFormulaL;
   if rl_op f eq 'or then
      rl_argn f
   else
      {f};

% functions mainly for debugging purposes

asserted procedure vssu_printSummary(vs: VSsu);
   <<
      ioto_prin2 {"VS: "};
      if vssu_vpp vs then
      	 ioto_prin2t {vsvs_v vs, " = test point"}
      else if vssu_dgp vs then
      	 ioto_prin2t {vsdg_v vs, " = ", vsdg_g vs, "-th root of ", vsdg_sv vs}
      else if vssu_arp vs then
      	 ioto_prin2t {vsar_v vs, " = arbitrary"}
   >>;

endmodule;  % [ofsfvssub]

end;  % of file
