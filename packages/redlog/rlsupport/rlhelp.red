module rlhelp;

revision('rlhelp, "$Id$");

copyright('rlhelp, "(c) 2016-2017 T. Sturm");

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

global '(rlhelp_leftMargin!*);
global '(rlhelp_rightMargin!*);
global '(rlhelp_colSep!*);

rlhelp_leftMargin!* := 4;
rlhelp_rightMargin!* := 1;
rlhelp_colSep!* := 2;

% The identifier '?' is also used with the fide package (module expres). This
% breaks autoloading for me currently, which is not vital. Fide hijacks also
% other symbols including '#' (also used with the preprocessor) and '&'. In the
% great unified system some decision would have to be made. I think there are
% arguments for using '?' for a Maple-style help possible beyond Redlog instead
% of a tensor operator in a very specialized context.
put('?, 'stat, 'rl_helpstat);

flag('(!?), 'go);

flag('(rl_help), 'noform);

asserted procedure rl_helpstat(): List;
   begin scalar devp, query;
      scan();
      if cursym!* eq '!? then <<  % another one indicates extended help for developers
	 devp := t;
	 scan()
      >>;
      while cursym!* eq '!? do  % skip further ? from hyper-enthusiastic typers
	 scan();
      if flagp(cursym!*, 'delim) then  % ? or ?? w/o further argument
      	 return {'rl_help, nil, devp};
      query := cursym!*;
      % Expecting delimiter now:
      if not flagp(scan(),'delim) then
	 rederr {"expecting delimiter but found", cursym!*};
      return {'rl_help, mkquote query, devp}
   end;

asserted procedure rl_help(x: Id, devp: Boolean);
   if null x then
      rl_helpOverview devp
   else if x eq 'services then
      rl_helpOverviewServices devp
   else if x eq 'blackboxes then
      rl_helpOverviewBlackboxes devp
   else if x eq 'types then
      rl_helpOverviewTypes()
   else <<
      if eqcar(x, 'quotient) and eqn(caddr x, rl_helpTypeArity cadr x) then
	 x := cadr x;
      rl_helpDocal(x, devp);
      if rl_serviceP x then
	 rl_helpService(x, devp)
      else if rl_blackboxP x then
	 rl_helpBlackbox(x, devp)
   >>;

asserted procedure rl_helpDocal(x: Id, devp: Boolean);
   begin scalar pr, sl, brk, docal, xdtl;
      docal := get(x, 'docal);
      if not docal then
	 return;
      xdtl := for each pr in docal join
	 if listp cdr pr then
	    for each ppr in cdr pr collect
	       car ppr;
      for each rest on docal do <<
	 pr := car rest;
	 if cdr pr then <<
	    if brk then terpri() else brk := t;
	    ioto_tprin2t lto_Upcase id2string car pr;
	    if car pr = 'synopsis then <<
	       for i := 1:rlhelp_leftMargin!* do prin2 " ";
	       prin2t cdr pr
	    >> else if stringp cdr pr then
	       rl_printParagraph cdr pr
	    else  % cdr pr is an AList
	       rl_printDescriptionList(cdr pr, xdtl)
	 >>
      >>
   end;

asserted procedure rl_helpService(x: Id, devp: Boolean);
   ;

asserted procedure rl_helpBlackbox(x: Id, devp: Boolean);
   begin scalar l;
      for each y in rl_services!* do
	 for each z in rl_knownImplementations y do
	    if x memq rl_registeredBlackboxes z then
	       l := lto_insertq(lto_at2str z, l);
      if null l then
 	 return;
      terpri();
      ioto_tprin2t "DYNAMICALLY KNOWN TO BE REGISTERED FOR";
      rl_helpOverviewCSL l
   end;

asserted procedure rl_printParagraph(s: String);
   <<
      for each l in rl_stringParagraphWrapper s do prin2t l;
      nil
   >>;

asserted procedure rl_stringParagraphWrapper(s: String): List;
   lto_stringParagraph(s, rlhelp_leftMargin!*, linelength nil - rlhelp_rightMargin!*);


asserted procedure rl_printDescriptionList(al: AList, xdtl: List);
   <<
      for each l in rl_stringDescriptionListWrapper(al, xdtl) do prin2t l;
      nil
   >>;

asserted procedure rl_stringDescriptionListWrapper(al: AList, xdtl: List): List;
   lto_stringDescriptionList(al, rlhelp_leftMargin!*, rlhelp_colSep!*, linelength nil - rlhelp_rightMargin!*, xdtl);

asserted procedure rl_helpOverview(devp: Boolean);
   begin scalar sl, w, asl, ssl, bl, cl, kwl, types, keywords;
      ioto_tprin2t "REDLOG SERVICES";
      for each s in rl_services!* do <<
	 w := get(s, 'rl_amservice);
	 if w then
 	    push(lto_at2str w, asl)
	 else
	    push(lto_at2str s, ssl)
      >>;
      rl_helpOverviewCSL asl;
      terpri();
      if devp and ssl then <<
      	 ioto_tprin2t "REDLOG SM-ONLY SERVICES";
      	 rl_helpOverviewCSL ssl;
      	 terpri()
      >>;
      if devp then <<
      	 ioto_tprin2t "REDLOG BLACKBOXES";
      	 rl_helpOverviewCSL for each s in rl_blackboxes!* collect lto_at2str s;;
      	 terpri()
      >>;
      for each s in rl_typeStrings rl_services!* do <<
	 {bl, cl, kwl} := rl_helpOverviewTypesDecompose s;
	 for each x in bl do
	    types := lto_insert(x, types);
	 for each x in cl do
	    types := lto_insert(rl_helpTypeConcArity x, types);
	 for each x in kwl do
	    keywords := lto_insert(x, keywords)
      >>;
      ioto_tprin2t "REDLOG TYPES";
      rl_helpOverviewCSL types;
      terpri();
      ioto_tprin2t "REDLOG KEYWORDS";
      rl_helpOverviewCSL keywords;
      terpri();
      ioto_tprin2t "REDLOG SWITCHES";
      rl_helpOverviewCSL for each s in rl_services!* join <<
	 w := get(s, 'rl_amservice);
	 if w then
	    for each sw in cdr atsoc('switches, get(w, 'docal)) collect
 	       lto_sconcat2("rl", car sw)
      >>;
      terpri();
      ioto_tprin2t "SEE ALSO";
      rl_printDescriptionList(
	 if devp then
	    '(("??services" . "more information on services")
              ("??blackboxes" . "more information on blackboxes")
              ("??types" . "more information on types")
              ("??switches" . "more information on switches")
              ("??X" . "for a specific service, blackbox, type, or switch X"))
	 else
	    '(("?services" . "more information on services")
              ("?types" . "more information on types")
              ("?switches" . "more information on switches")
              ("?X" . "for a specific service, type, or switch X")),
 	 nil)
   end;

asserted procedure rl_helpOverviewCSL(l: List): List;
   begin scalar sl;
      for each rest on sort(l, 'rl_stringGreaterP) do <<
	 push(car rest, sl);
	 if cdr rest then
	    push(", ", sl)
      >>;
      rl_printParagraph lto_sconcat sl
   end;

asserted procedure rl_stringLeq(s1: String, s2: String): Boolean;
   ordp(intern compress explodec s1, intern compress explodec s2);

asserted procedure rl_stringGreaterP(s1: String, s2: String): Boolean;
   not rl_stringLeq(s1, s2);

asserted procedure rl_helpOverviewServices(devp: Boolean);
   begin scalar sl, w, al;
      sl := sort(rl_services!*, 'ordp);
      al := for each s in sl join <<
	 w := get(s, 'rl_amservice);
	 if w then
	    {lto_at2str w . cdr atsoc('description, get(s, 'docal))}
      >>;
      ioto_tprin2t "REDLOG SERVICES";
      rl_printDescriptionList(al, nil);
      terpri();
      if devp then <<
      	 al := for each s in sl join
	    if not get(s, 'rl_amservice) then
	       {lto_at2str s . cdr atsoc('description, get(s, 'docal))};
	 if al then <<
      	    ioto_tprin2t "REDLOG SM-ONLY SERVICES";
      	    rl_printDescriptionList(al, nil);
      	    terpri()
	 >>
      >>;
      ioto_tprin2t "SEE ALSO";
      rl_printDescriptionList('(("?X" . "for a specific service X")),
 	 for each pr in al collect car pr)
   end;

asserted procedure rl_helpOverviewBlackboxes(devp: Boolean);
   begin scalar al;
      if not devp then
	 return;
      al  := for each s in sort(rl_blackboxes!*, 'ordp) collect
	 id2string s . cdr atsoc('description, get(s, 'docal));
      ioto_tprin2t "REDLOG BLACKBOXES";
      rl_printDescriptionList(al, nil);
      terpri();
      ioto_tprin2t "SEE ALSO";
      rl_printDescriptionList('(("?X" . "for a specific blackbox X")),
 	 for each pr in al collect car pr)
   end;

asserted procedure rl_helpOverviewTypes();
   begin scalar bl,cl, bal, cal, sal, xdtl, kwl1, kwl;
      for each s in rl_typeStrings rl_services!* do <<
	 {bl, cl, kwl1} := rl_helpOverviewTypesDecompose s;
	 for each x in bl do
      	    bal := lto_insert(x . (lto_catsoc('syntax, get(lto_string2id x, 'docal)) or ""), bal);
	 for each x in cl do
      	    cal := lto_insert(rl_helpTypeConcArity x . (lto_catsoc('syntax, get(lto_string2id x, 'docal)) or ""), cal);
	 kwl := union(kwl, kwl1)
      >>;
      bal := sort(bal, function(lambda x, y; rl_stringLeq(car x, car y)));
      cal := sort(cal, function(lambda x, y; rl_stringLeq(car x, car y)));
      sal := '(("?X" . "for a specific type X"));
      xdtl := for each pr in append(sal, append(bal, cal)) collect car pr;
      ioto_tprin2t "REDLOG BASIC TYPES";
      rl_printDescriptionList(bal, xdtl);
      terpri();
      ioto_tprin2t "REDLOG COMPOUND TYPES";
      rl_printDescriptionList(cal, xdtl);
      terpri();
      ioto_tprin2t "REDLOG KEYWORDS";
      rl_helpOverviewCSL kwl;
      terpri();
      ioto_tprin2t "SEE ALSO";
      rl_printDescriptionList(sal, xdtl)
   end;

asserted procedure rl_helpOverviewTypesDecompose(s: String): List3;
   rl_helpOverviewTypesDecompose1(ioto_sxread s, nil, nil, nil) where !*lower=nil, !*raise=nil;

asserted procedure rl_helpOverviewTypesDecompose1(x: Any, bl: List, cl: List, kwl: List): List3;
   begin scalar carxs;
      if idp x then
      	 return {id2string x . bl, cl, kwl};
      carxs := id2string car x;
      push(carxs, cl);
      if carxs = "Enum" then <<
	 for each kw in cdr x do push(id2string kw, kwl);
	 return {bl, cl, kwl}
      >>;
      for each y in cdr x do
	 {bl, cl, kwl} := rl_helpOverviewTypesDecompose1(y, bl, cl, kwl);
      return {bl, cl, kwl}
   end;

asserted procedure rl_helpTypeConcArity(s: String): String;
   % We are context sensitive. [x] is a compound type as an identifier. We add
   % "/n", where n is its arity. The arity is derived from the a2s/s2a property.
   % If this fails we use "/?".
   lto_sconcat {s, "/", rl_helpTypeArity s};

asserted procedure rl_helpTypeArity(s: String): String;
   begin scalar !*lower, !*raise, lcx, ar;
      lcx := intern lto_downcase compress explodec s;
      ar :=  if lcx eq 'keyword then
	 'n
      else
	 get(get(lcx, 'a2s) or get(lcx, 's2a), 'number!-of!-args) or '!?;
      if fixp ar then ar := ar - 1;
      return ioto_smaprin ar
   end;

asserted procedure rl_typeStrings(services: List): List;
   begin scalar w;
      return lto_list2set for each s in services join <<
      	 w := get(s, 'rl_amservice);
	 if w then
      	    copy(get(w, 'outtype) . get(w, 'intypes))
      >>
   end; 

asserted procedure rl_typeIdentifiers(services: List): List;
   lto_list2set for each s in services join
      for each tp in get(s, 'outtype) . get(s, 'intypes) collect
	 lto_string2id tp;

endmodule;

end;
