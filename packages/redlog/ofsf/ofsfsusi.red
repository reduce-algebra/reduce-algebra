module ofsfsusi;
% Orderd field standard form "super simplifier" black boxes

revision('ofsfsusi, "$Id$");

copyright('ofsfsusi, "(c) 1995-2021 A. Dolzmann, T. Sturm");

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

procedure ofsf_susirmknowl(knowl,v);
   % Ordered field susi remove knowledge. [knowl] is a KNOWL; [v] is a
   % variable. Returns a KNOWL. Remove all information about [v] from
   % [knowl].
   for each p in knowl join
      if v memq ofsf_varlat car p then nil else {p};

procedure ofsf_susibin(old,new);
   % Orderd field standard form susi binary smart simplification.
   % [old] and [new] are LAT's. Returns ['false] or a SUSIPRG. We
   % assume that [old] is a part of a already existence KNOWL and new
   % has to be added to this KNOWL.
   begin scalar w,x;
      if !*rlsusiadd then <<
      	 w := ofsf_susibinad(old,new);
      	 if w eq 'false then
	    return 'false
      >>;
      if !*rlsusimult then <<
      	 x := ofsf_susibinmult(old,new);
      	 if x eq 'false then
	    return 'false;
	 w := nconc(w,x)
      >>;
      return w
   end;

procedure ofsf_susibinmult(old,new);
   % Ordered field standard forms susi binary smart simplification
   % multiplicative case. [old] and [new] are LAT's. Returns ['false]
   % or a SUSIPRG. We assume that [old] is a part of a already
   % existence KNOWL and new has to be added to this KNOWL.
   begin scalar w,ot,nt,orel,nrel,olevel,nlevel;
      ot := ofsf_arg2l car old;
      nt := ofsf_arg2l car new;
      orel := ofsf_op car old;
      nrel := ofsf_op car new;
      olevel := cdr old;
      nlevel := cdr new;
      w := quotf(ot,nt);
      if w = 1 then  % [ot] = [nt]
	 return nil;
      if w then  % [nt] | [ot]
	 return ofsf_susibinmult1(orel,nrel,ot,nt,w,olevel,nlevel,t);
      w := quotf(nt,ot);
      if w then
	 return ofsf_susibinmult1(nrel,orel,nt,ot,w,nlevel,olevel,nil);
      return nil
   end;

procedure ofsf_susibinmult1(pr,fr,prod,af,cf,plevel,flevel,flg);
   % Ordered field standard form susi binary smart simplification
   % multiplicative part subroutine. [pr] is the relation of the
   % product; [fr] is the realtion of the factor; [prod] is the
   % product; [af] and [cf] are factors of [prod]; [flg] is boolean.
   % If [flg] is [nil] then the factor is contained in the theory,
   % otherwise the product is contained in the theory.
   begin scalar w;
      w := ofsf_susibinmulttab(fr,pr);
      if not w then return nil;
      w := cdr w;
      if not w then return nil;
      if atom w then <<
	 if w eq 'false then
	    return 'false;
      	 if w eq 'ign1 then  % The factor can be ignored
	    return  { ('ignore . flg) };
	 if w eq 'ign2 then  % The product can be ignored
	    return { ('ignore . not flg) }
      >>;
      if ofsf_wop fr then
      	 return { '(ignore . t), '(ignore . nil),
	    ('add . (ofsf_0mk2(car w,af) . cl_susiminlevel(plevel,flevel))),
	    ('add . (ofsf_0mk2(cdr w,cf) . plevel))}
      else % The factor is necessary
	 return { ('ignore . not flg),
	    ('add . (ofsf_0mk2(cdr w,cf) . plevel))}
   end;

procedure ofsf_wop(rel);
   rel memq '(leq geq);

procedure ofsf_susibinmulttab(u,uv);
   begin scalar al;
      al := '(
	 (equal . ( (equal . ign2) (leq . ign2) (geq . ign2)
	            (neq . false) (greaterp . false) (lessp . false)))
         (leq   . ( (equal . nil) (leq . nil) (geq . nil) (neq . (lessp . neq))
                    (greaterp . (lessp . lessp)) (lessp . (lessp . greaterp))))
         (geq .   ( (equal . nil) (leq . nil) (geq . nil)
                    (neq . (greaterp . neq)) (greaterp . (greaterp . greaterp))
                    (lessp . (greaterp . lessp))))
         (neq .   ( (equal . (neq . equal)) (leq . nil) (geq . nil)
                    (neq . (neq . neq)) (greaterp . ign1) (lessp . ign1)))
         (lessp . ( (equal . (lessp . equal)) (leq . (lessp . geq))
                    (geq . (lessp . leq)) (neq . (lessp . neq))
                    (lessp . (lessp . greaterp)) (greaterp . (lessp . lessp))))
         (greaterp . ( (equal . (greaterp . equal)) (leq . (greaterp . leq))
                    (geq . (greaterp . geq)) (neq . (greaterp . neq))
                    (lessp . (greaterp . lessp))
                    (greaterp . (greaterp . greaterp)))));
      return atsoc(uv,atsoc(u,al))
   end;

procedure ofsf_susibinad(old,new);
   begin scalar od,nd,level;
      level := cl_susiminlevel(cdr old,cdr new);
      old := car old;
      new := car new;
      if ofsf_arg2l old = ofsf_arg2l new then
	 return ofsf_susibineq(ofsf_arg2l old,ofsf_op old,ofsf_op new,level);
      od := ofsf_susidec(ofsf_arg2l old);
      nd := ofsf_susidec(ofsf_arg2l new);
      if car od = car nd then
	 return ofsf_susibinord(ofsf_op old,ofsf_arg2l old,cdr od,
	    ofsf_op new,ofsf_arg2l new,cdr nd,level);
      return nil;
   end;

procedure ofsf_susibineq(u,oop,nop,level);
   begin scalar w;
      w := ofsf_smeqtable(oop,nop);
      if w eq 'false then
	 return 'false
      else if w eq oop then
	 return '((delete . t))
      else if w eq nop then
	 return {'(delete . nil)}
      else
	 return {'(delete . nil), '(delete . t),
	    'add . (ofsf_0mk2(w,u) . level)};
   end;

procedure ofsf_susidec(u);
   % Decompose. [u] is a SF. Returns a pair $(p . a)$, where $p$ is a
   % SF, and $a$ is SQ. $p$ is the parametric part of [u] and $a$ is
   % the absolut part of [u].
   begin scalar par,absv,c;
      absv := u;
      while not domainp absv do absv := red absv;
      par := addf(u,negf absv);
      c := sfto_dcontentf(par);
      par := quotf(par,c);
      absv := quotsq(!*f2q absv,!*f2q c);
      return par . absv;
   end;

procedure ofsf_susibinord(orel,ot,oabs,nrel,nt,nabs,level);
   begin scalar w,diff;
      diff := numr subtrsq(oabs,nabs);
      if minusf diff then <<
      	 w := ofsf_smordtable(orel,nrel);
	 if atom w then return w;
      	 if eqcar(w,orel) and cdr w then return '((ignore . t));
	 if cdr w then
	    return {'(ignore . nil),
	       'add . (ofsf_0mk2(car w,ot) . level)}
	 else
	    return {'(ignore . nil)}
      >>;
      w := ofsf_smordtable(nrel,orel);
      if atom w then return w;
      if eqcar(w,orel) and null cdr w then return '((ignore . t));
      if cdr w then
      	 return {'(ignore . nil)}
      else
	 return {'(ignore . nil),
	    'add . (ofsf_0mk2(car w,ot) . level)}
   end;

procedure ofsf_susipost(atl,knowl);
   % Ordered field standad form susi post simplification. [atl] is a
   % list of atomic formulas. [knowl] is a KNOWL. Returns a list
   % $\lambda$ of atomic formulas, such that
   % $\bigwedge[knowl]\land\bigwedge\lambda$ is equivalent to
   % $\bigwedge[knowl]\and\bigwedge[atl]$
   if !*rlsusigs then
      ofsf_susigs(atl,knowl)
   else atl;

procedure ofsf_susigs(atl,knowl);
   % Ordered field standard form susi Groebner simplification. [atl]
   % is a list of atomic formulas; [knowl] is a KNOWL. Returns a list
   % of atomic formulas. The conjunction over [atl] is simplified wrt.
   % the theory [knowl] with the Groebner simplifier.
   begin scalar w,theo,!*rlsiexpla,!*rlsiexpl;
      atl := for each at in atl collect rl_negateat(at);
      w := rl_smkn('or,atl);
      theo := for each x in knowl collect car x;
      w := ofsf_gssimplify0(w,theo);
      if w eq 'inctheo then
	 return 'inctheo;
      if rl_tvalp w then
	 return cl_flip w;
      if cl_atfp w then
	 return {rl_negateat w};
      w := for each at in rl_argn w collect rl_negateat(at);
      return w
   end;

procedure ofsf_susitf(at,knowl);
   % Orderd field standard form susi transform. [at] is an atomic
   % formula, [knowl] is a knowledge. Returns an atomic formula
   % $\alpha$ such that $\alpha\land\bigwedge[knowl]$ is equivalent to
   % $[at]\land\bigwedge[knowl]$. $\alpha$ has possibly a more
   % convenient relation than [at].
   begin scalar r,s;
      r := ofsf_op at;
      s := ofsf_arg2l at;
      if (r eq 'geq and assoc(ofsf_0mk2('leq,s),knowl)) or
	 (r eq 'leq and assoc(ofsf_0mk2('geq,s),knowl))
      then
	 return ofsf_0mk2('equal,s);
      if not (r eq 'lessp or r eq 'greaterp) then
	 return at;
      if !*rlsipw and assoc(ofsf_0mk2('neq,s),knowl) then
	 return ofsf_0mk2(ofsf_canegrel('leq,r eq 'lessp),s);
      if !*rlsipo then
	 return at;
      if (r eq 'lessp and assoc(ofsf_0mk2('leq,s),knowl)) or
	 (r eq 'greaterp and assoc(ofsf_0mk2('geq,s),knowl))
      then
	 return ofsf_0mk2('neq,s);
      return at
   end;

endmodule;

end;
