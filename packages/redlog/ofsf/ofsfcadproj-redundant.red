asserted procedure ofsf_cadvbl(phi: Formula): List;
   % Variable-block-list. Checks if [phi] is in PNF. Returns a list of lists
   % [[xr..][..xk]..[xk..x1]] of Kernels.
   <<
      if not cl_prenexp phi then
      	 rederr "Formula is not in prenex normal form, please use rlpnf beforehand.";
      ofsf_cadvbl1 phi
   >>;

% begin advanced programming techniques

procedure foldr(fn,e,l);
   % Fold right. [fn] is a binary function of type $(a,a)->a$, [e] is
   % neutral and of type $a$, and [l] is a list of arguments, all of
   % type $a$. Returns a value of type $a$.
   % Example: foldr(function union,{},{{1,2},{2,3},{3,4}});
   if null l then e else apply(fn,{car l,foldr(fn,e,cdr l)});

procedure foldr1(fn,l);
   % Fold right with non-trivial list. Arguments as in foldr, exept l
   % is not nil. Return value as in foldr.
   % foldr1(function(lambda a,b;a+b),{1,2,3,4});
   if null cdr l then car l else apply(fn,{car l,foldr1(fn,cdr l)});

% MAP. Caveat: map(l,fn) applies fn to each cdr of l, which is
% unusual. mapc(l,fn) is what is usually known as map: fn is applied
% to each element of l. Example: mapc({1,2,3,4},function(print));
% Why does this not work: mapc({1,2,3,4},function(lambda x;x+1));

procedure mymap(fn,l);
   % map. [fn] in a function of type $a->b$, [l] is a list of type
   % $a$. Returns a list of type $b$.
   % Example: mymap(function(lambda n;n+1),{1,2,3,4});
   for each a in l collect apply(fn,{a});

% end advanced programming techniques

% begin baustelle

symbolic operator rlrorders;
procedure rlrorders(fl, yl);
   'list . for each o in
      sf_rorders!*(for each f in fl collect numr simp f, cdr yl) collect
	 'list . o;

asserted procedure sf_rorders!*(fl: List, yl: List): SF;
   begin scalar oldorder,w;
      oldorder := setkorder yl;
      w := sf_rorders(for each f in fl collect reorder f, yl);
      setkorder oldorder;
      return w
   end;

asserted procedure sf_rorders(fl: List, yl: List): List;
   % Optimal orders for regularization (wrt. nom). [fl] is a List of SF. Returns
   % a non-empty LIST(LIST(ID)). This list starts with the shortest order of
   % minimal cost.
   begin scalar ords, flr, nom;
      if null yl then
	 rederr "empty regularization order invalid";
      ords := lto_powerset cdr yl;
      ords := for each o in ords collect car yl . o;
      ords := for each o in ords collect <<
	 flr := sf_regularize!*(fl, o);
	 if sf_isregular!*(flr, yl) then
	    nom := for each f in flr sum sf_nom f
	 else
	    nom := -1;
	 o . nom
      >>;
      % remove illegal orders
      ords := for each p in ords join
	 if cdr p >= 0 then {p};
      % sort by cost and length.
      ords := sort(ords, 'ofsf_rordp);
      return for each p in ords collect car p
   end;

asserted procedure ofsf_rordp(p1: DottedPair, p2: DottedPair): Boolean;
   (cdr p1 < cdr p2) or (cdr p1 = cdr p2 and length car p1 < length car p2);

% end baustelle

% begin matrix procedures

procedure mtx_1(n);
   % Unit matrix. [m] and [n] are INT. Returns a mxn-matrix MTX(SF).
   for l:=1:n collect
      for c:=1:n collect if c eq l then 1 else nil;

procedure mtx_froml(lst,n);
   % Make from list. [lst] is a LIST, [n] is an INT. Returns a MTX with
   % $n$ columns. Can be further improved.
   begin scalar mtx,m;
      m := length(lst)/n;
      if m*n neq length(lst) then error(nil,"mtx_froml: wrong list length");
      mtx := mtx_0(m,n);
      for l := 1 : m do
	 for c := 1 : n do
	    mtx_put(mtx,l,c,nth(lst,(l-1)*n+c));
	    %print((l-1)*n+c);
      return mtx;
   end;

procedure mtx_tol(mtx);
   % Matrix to list (destructive).
   for each l in mtx join l;

procedure mtx_nol(mtx);
   % Number of lines. [mtx] is a MTX. Returns an INT.
   length mtx;

procedure mtx_noc(mtx);
   % Number of lines. [mtx] is a MTX. Returns an INT.
   if null mtx then 0 else length car mtx;

procedure mtx_get(mtx,l,c);
   % Get matrix entry.
   nth(nth(mtx,l),c);

procedure mtx_print(mtx);
   % Print.
   for each l in mtx do print l;

% end matrix procedures

% begin regularity stuff

symbolic operator rlisregular;
procedure rlisregular(fl, xl);
   begin scalar tv;
      tv := sf_isregular!*(for each f in fl collect numr simp f, cdr xl);
      if tv then
	 return 'true;
      return 'false
   end;

asserted procedure sf_isregular!*(fl: List, yl: List): Boolean;
   % Regularity test. [fl] is a List of SF. [yl] is a List of Kernels.
   % Reordering is performed, so the result is correct.
   begin scalar oldorder, w;
      oldorder := setkorder yl;
      w := sf_isregular(for each f in fl collect reorder f, yl);
      setkorder oldorder;
      return w
   end;

asserted procedure sf_isregular(fl: List, yl: List): Boolean;
   % Regularity test. [fl] is a List of SF. [yl] is a List of Kernels. [f] has
   % to be ordered in a way compatible to [yl].
   if null fl then
      t
   else
      sf_tdeg(sf_lc(car fl,car yl),cdr yl)<=0 and sf_isregular(cdr fl,yl);

symbolic operator rltransreg;
procedure rltransreg(fl, yl, cl);
   begin scalar w;
      w := for each f in cdr fl collect numr simp f;
      return 'list . for each fr in sf_transreg!*(w, cdr yl, cdr cl) collect
	 prepf fr;
   end;

asserted procedure sf_transreg!*(fl: List, yl: List, cl: List): SF;
    begin scalar oldorder, w;
      oldorder := setkorder yl;
      w := sf_transreg(for each f in fl collect reorder f, yl, cl);
      setkorder oldorder;
      return reorder w
   end;

asserted procedure sf_transreg(fl: List, yl: List, cl: List): List;
   % Transformation into a regular polynomial. [fl] is a List of SF, [yl] is a
   % List of Kernels, and [cl] is a List of Integers. Returns a List of SF.
   for each f in fl collect sf_transregf(f, yl, cl);

asserted procedure sf_transregf(f: SF, yl: List, cl: List): SF;
   % Transformation into a regular polynomial. [f] is a SF, [yl] is a List of
   % Kernels, and [cl] is a List of Integers. Returns a SF.
   begin
      scalar y1, yj, cj, al;
      y1 := car yl;
      yl := cdr yl;
      while yl do <<
	 yj := pop yl;
	 cj := pop cl;
	 % al := (yj . addf(!*k2f yj,multf(cj,!*k2f y1)) . al;
	 al := (yj . {'plus, yj, {'times, cj, y1}}) . al
      >>;
      return numr subf(f, al)
   end;

symbolic operator rlregularize;
procedure rlregularize(fl, yl);
   begin scalar w;
      w := sf_regularize!*(for each f in cdr fl collect numr simp f, cdr yl);
      return 'list . for each f in w collect prepf f
   end;

asserted procedure sf_regularize!*(fl: List, yl: List): List;
    begin scalar oldorder, w;
      oldorder := setkorder yl;
      w := sf_regularize(for each f in fl collect reorder f, yl);
      setkorder oldorder;
      return for each f in w collect reorder f
   end;

asserted procedure sf_regularize(fl: List, yl: List): List;
   % Regularize. [fl] is a List of SF, [yl] is a List of Kernels. Returns a List
   % of SF.
   car sf_regularize1(fl, yl);

symbolic operator rlregularize1;
procedure rlregularize1(fl, yl);
   begin scalar w;
      w := sf_regularize1!*(for each f in cdr fl collect numr simp f, cdr yl);
      return {'list, 'list . for each f in car w collect prepf f, 'list . cdr w}
   end;

asserted procedure sf_regularize1!*(fl: List, yl: List): DottedPair;
    begin scalar oldorder,w;
      oldorder := setkorder yl;
      w := sf_regularize1(for each f in fl collect reorder f, yl);
      setkorder oldorder;
      return (for each f in car w collect reorder f) . cdr w
   end;

asserted procedure sf_regularize1(fl: List, yl: List): DottedPair;
   % Regularize. [fl] is a List of SF, [yl] is a List of Kernels. Returns a pair
   % (List of SF . List of Integers).
   begin scalar flr, cl1, cl2, cl;
      flr := fl;
      cl := for each y in cdr yl collect 1;
      cl1 := cl;
      while not sf_isregular(flr,yl) do <<
	 flr := sf_transreg(fl,yl,cl);
	 cl2 := cl;
	 cl := sf_nextcl cl;
      >>;
      if null cl2 then
	 return flr . for each y in cdr yl collect 0;
      return flr . cl2
   end;

asserted procedure sf_nextcl(cl: List): List;
   % Next constant list (Subroutine for sf_regularize). [cl] is a LIST(NUM).
   % Returns a LIST(NUM). In an ideal world this would enumerate
   % $\mathbb{N}^{|cl|}$.
   begin scalar c1;
      c1 := car cl;
      return reversip ((c1+1) . (reverse cdr cl))
   end;

% symbolic operator rlregoptordf;
% procedure rlregoptordf(f,yl);
%    'list . for each a in sf_regoptordf(numr simp f, cdr yl) collect
%       'list . a;

asserted procedure sf_regoptordf!*(f: SF, yl: List): SF;
   begin scalar oldorder, w;
      oldorder := setkorder yl;
      w := sf_regoptordf(reorder f, yl);
      setkorder oldorder;
      return reorder w
   end;

asserted procedure sf_regoptordf(f: SF, yl: List): List;
   % Optimal order for regularization (wrt. nom). Returns a LIST(LIST(ID)).
   begin scalar ords;
      ords := lto_powerset cdr yl;
      ords := for each o in ords collect car yl . o;
      ords := for each o in ords collect
	 o . sf_nom sf_regularize!*(f,o);
      ords := for each o in ords join
	 if sf_isregular!*(sf_regularize!*(f, car o), yl) then {o};
      return reversip
	 sort(for each o in ords collect car o, function length)
   end;

% end regularity stuff

% begin sf and tagged sf procedures

asserted procedure sf_rmconst(fl: List): List;
   % Remove constant. [fl] is a list of SF.
   for each f in fl join if not domainp f then {f};

asserted procedure tgdomainp(tf: DottedPair): Boolean;
   % Domain predicate, tagged version. [tf] is a tagged SF.
   domainp tag_object tf;

asserted procedure sf_tgdeg(tf: DottedPair, x: Kernel): Integer;
   % Tagged SF degree. [tf] is a tagged SF.
   sfto_vardeg(tag_object tf, x);

asserted procedure sf_tglc(tf: DottedPair, x: Kernel): DottedPair;
   % Tagged SF leading coefficient. [tf] is a tagged SF.
   tag_(sf_lc(tag_object tf, x), tag_taglist tf);

asserted procedure sf_tgred(tf: DottedPair, x: Kernel): DottedPair;
   % Tagged SF reductum. [tf] is a tagged SF. Returns a tagged SF.
   tag_(sf_red(tag_object tf, x), tag_taglist tf);

asserted procedure sf_tgdiscriminant(tf: DottedPair, x: Kernel): DottedPair;
   % Tagged SF discriminant. [tf] is a tagged SF. Returns a tagged SF.
   tag_(sf_discriminant(tag_object tf, x), tag_taglist tf);

asserted procedure tgresultant(tf1: DottedPair, tf2: DottedPair, x: Kernel): DottedPair;
   % Tagged SF resultant. [tf1] and [tf2] are tagged SF. Returns a tagged SF.
   tag_(sfto_resf(tag_object tf1,tag_object tf2,x),
      union(tag_taglist tf1,tag_taglist tf2));

asserted procedure sf_foldgcd(fl: List): SF;
   % Fold gcd. [fl] is a non-empty list of SF.
   if null cdr fl then car fl else gcdf(car fl, sf_foldgcd cdr fl);

asserted procedure sf_densecoeffs(f: SF, x: Kernel): List;
   % Dense coefficient list.
   begin scalar clred;
      if sfto_vardeg(f, x) <= 0 then
	 return {f};
      clred := sf_densecoeffs(red f, x);
      for i := (max(0, sfto_vardeg(red f, x)) + 1) : (ldeg f - 1) do
	 clred := nil . clred;
      clred := lc f . clred;
      return clred
   end;

asserted procedure sf_fromdensecoeffs(fl: List, k: Kernel): SF;
   % Standard form from dense coefficient list. [fl] is a non-empty List of SF.
   begin scalar f;
      if null cdr fl then
	 return car fl;
      if null car fl then
	 return sf_fromdensecoeffs(cdr fl, k);
      f := sfto_kexp(k, length fl - 1);
      set_l(f, car fl);
      set_red(f, sf_fromdensecoeffs(cdr fl, k));
      return f
   end;

asserted procedure sf_tdeg!*(f: SF, xl: List): Integer;
   % Total degree. Reordering is performed to obtain the correct result.
   begin scalar oldorder, w;
      oldorder := setkorder xl;
      w := sf_tdeg(reorder f, xl);
      setkorder oldorder;
      return w
   end;

asserted procedure sf_lc!*(f: SF, x: Kernel): SF;
   % Leading coefficient. Reordering is performed, so the result is correct.
   begin scalar oldorder,w;
      oldorder := setkorder {x};
      w := sf_lc(reorder f, x);
      setkorder oldorder;
      return reorder w
   end;

% end sf and tagged sf procedures

% begin lto procedures

procedure lto_last(l);
   % Last element of a list. [l] is a non-empty list.
   if cdr l then lto_last cdr l else car l;

procedure lto_take(l, n);
   % Take the first n elements of l. [l] is a LIST, [n] is a natural number.
   % Returns a LIST.
   if l and n > 0 then car l . lto_take(cdr l, n-1);

asserted procedure lto_powerset(l: List): List;
   % Powerset.
   begin scalar w;
      if null l then
	 return {{}};
      w := lto_powerset cdr l;
      return append(w, for each a in w collect car l . a)
   end;

% end lto procedures

% begin some algebraic mode services and procedures

algebraic procedure rlcadporders(phi);
   % Compute all admissible projection orders.
   ordersfromvbl rlcadvbl phi;

algebraic procedure ordersfromvbl(vbl);
   if vbl={} then {{}} else
      for each vl1 in perturbations first vbl join
	 for each vl2 in ordersfromvbl rest vbl collect
	    append(vl1, vl2);

symbolic operator rlcadpordersnum;
procedure rlcadpordersnum(phi);
   begin scalar w;
      w := for each b in ofsf_cadvbl1 rl_simp phi collect
	 length b;
      return for each n in w product
	 factorial n
   end;

symbolic operator rlcadvbl2pord;
procedure rlcadvbl2pord(vbl);
   for each vb in vbl join vb;

symbolic operator rlcadvbl;
procedure rlcadvbl(phi);
   'list . for each l in ofsf_cadvbl rl_simp phi collect
      'list . l;

algebraic procedure rlcaddefaultorder(phi);
   for each vb in rlcadvbl rlpnf phi join vb;

algebraic procedure delnth(l, n);
   % Delete the n-th element from list.
   if n = 1 then rest l else append({first l}, delnth(rest l, n-1));

algebraic procedure mynth(l, n);
   % nth lelement of a list
   if n = 1 then first l else mynth(rest l, n-1);

algebraic procedure perturbations(l);
   if l = {} then
      {{}}
   else
      for j := 1 : length l join
    	 for each p in perturbations(delnth(l, j)) collect
	    append({mynth(l, j)}, p);

symbolic operator rlstdeg;
procedure rlstdeg(f);
   sf_stdeg numr simp f;

symbolic operator rltdeg;
procedure rltdeg(f, xl);
   prepf sf_tdeg!*(numr simp f, cdr xl);

symbolic operator rllc;
procedure rllc(f, x);
   prepf sf_lc!*(numr simp f, x);

symbolic operator rlred;
procedure rlred(f, x);
   begin scalar oldorder, w;
      oldorder := setkorder {x};
      w := prepf sf_red(numr simp f, x);
      setkorder oldorder;
      return w
   end;

symbolic operator rldis;
procedure rldis(f, x);
   begin scalar oldorder, w;
      oldorder := setkorder {x};
      w := prepf sf_discriminant(numr simp f, x);
      setkorder oldorder;
      return w
   end;

symbolic operator rlres;
procedure rlres(f, g, x);
   begin scalar oldorder,w;
      oldorder := setkorder {x};
      w := prepf sfto_resf(numr simp f, numr simp g, x);
      setkorder oldorder;
      return w
   end;

symbolic operator rlnom;
procedure rlnom(f);
   sf_nom numr simp f;

symbolic operator rlchoose;
procedure rlchoose(l);
   'list . for each a in lto_powerset cdr l collect 'list . a;

symbolic operator rlpsc;
procedure rlpsc(f, g, x, j);
   begin scalar oldorder,w;
      oldorder := setkorder {x};
      w := prepf sf_psc(numr simp f, numr simp g, x, j);
      setkorder oldorder;
      return w
   end;

% end some algebraic mode services and procedures

% begin projection sets-related code

asserted procedure rlprojamat(fn, afl: List, x: Kernel): List;
   % Algebraic mode access template. [fn] is a function of type
   % (LIST(SF),ID)->(LIST(SF), [afl] is a list of algebraic forms (lisp prefix)
   % and [x] is an identifier. Returns a list of algebraic forms.
   begin scalar oldorder, w;
      oldorder := setkorder {x};
      w := apply(fn, {for each af in cdr afl collect numr simp af, x});
      w := 'list . for each f in w collect prepf f;
      setkorder oldorder;
      return w
   end;

asserted procedure rlprojamat2(fn: Any, afl: List, l: List): List;
   % Algebraic mode access template 2. [fn] is a function of type
   % (LIST(SF),LIST(ID))->(LIST(SF), [afl] is a list of algebraic forms (lisp
   % prefix) and [l] is an list of identifiers. Returns a list of algebraic
   % forms.
   begin scalar oldorder, w;
      oldorder := setkorder reverse cdr l;
      w := apply(fn, {for each af in cdr afl collect numr simp af, cdr l});
      w := 'list . for each f in w collect prepf f;
      setkorder oldorder;
      return w
   end;

asserted procedure rltgprojamat2(fn: Any, afl: List, l: List): List;
   % Algebraic mode access template 2, tagged version. [fn] is a function of
   % type (LIST(SF),LIST(ID))->(LIST(TAG(SF)), [afl] is a list of algebraic
   % forms (lisp prefix) and [l] is an list of identifiers. Returns a list of
   % lists, each list having an algebraic form as first entry.
   begin scalar oldorder, w;
      oldorder := setkorder reverse cdr l;
      w := apply(fn, {for each af in cdr afl collect numr simp af, cdr l});
      w := 'list . for each tf in w collect
	 ('list . prepf tag_object tf . tag_taglist tf);
      setkorder oldorder;
      return w
   end;

% begin algebraic procedures using rlprojamat

symbolic operator rltransfac;
procedure rltransfac(afl, x);
   rlprojamat(function ofsf_transfac, afl, x);

symbolic operator rlprojco;
procedure rlprojco(afl, x);
   rlprojamat(function ofsf_projco, afl, x);

symbolic operator rlprojcov22;
procedure rlprojcov22(afl, x);
   rlprojamat(function ofsf_projcov22, afl, x);

symbolic operator rlprojcov23;
procedure rlprojcov23(afl, x);
   rlprojamat(function ofsf_projcov23, afl, x);

symbolic operator rlprojcoho;
procedure rlprojcoho(afl, x);
   rlprojamat(function ofsf_projcoho, afl, x);

% symbolic operator rlprojcohogen;
% procedure rlprojcohogen(afl, x);
%    rlprojamat(function ofsf_projcohogen, afl, x);

symbolic operator rlprojco2v;
procedure rlprojco2v(afl, x);
   rlprojamat(function ofsf_projco2v,afl,x);

symbolic operator rlprojmc;
procedure rlprojmc(afl, x);
   rlprojamat(function ofsf_projmc, afl, x);

% symbolic operator rltgprojmc;
% procedure rltgprojmc(afl, x);
%    rlprojamat(function ofsf_tgprojmc, afl, x);

symbolic operator rlprojmcbr;
procedure rlprojmcbr(afl, x);
   rlprojamat(function ofsf_projmcbr, afl, x);

% symbolic operator rltgprojmcbr;
% procedure rltgprojmcbr(afl, x);
%    rlprojamat(function ofsf_tgprojmcbr, afl, x);

symbolic operator rlprojcobb;
procedure rlprojcobb(afl, x);
   rlprojamat(function ofsf_projcobb, afl, x);

symbolic operator rlprojcobbv2;
procedure rlprojcobbv2(afl, x);
   rlprojamat(function ofsf_projcobbv2, afl, x);

symbolic operator rlprojcoll;
procedure rlprojcoll(afl, x);
   rlprojamat(function ofsf_projlcs, afl, x);

symbolic operator rlprojmcll;
procedure rlprojmcll(afl, x);
   rlprojamat(function ofsf_projmccoeffs, afl, x);

symbolic operator rlprojcoss1;
procedure rlprojcoss1(afl, x);
   rlprojamat(function ofsf_projcoss1, afl, x);

% symbolic operator rlprojcoss1gen;
% procedure rlprojcoss1gen(afl, x);
%    rlprojamat(function ofsf_projcoss1gen, afl, x);

symbolic operator rlprojcoss2;
procedure rlprojcoss2(afl, x);
   rlprojamat(function ofsf_projcoss2, afl, x);

symbolic operator rlprojcoss2v2;
procedure rlprojcoss2v2(afl, x);
   rlprojamat(function ofsf_projcoss2v2, afl, x);

symbolic operator rlprojcoss2v3;
procedure rlprojcoss2v3(afl, x);
   rlprojamat(function ofsf_projcoss2v3, afl, x);

symbolic operator rlprojhoss2;
procedure rlprojhoss2(afl, x);
   rlprojamat(function ofsf_projhoss2, afl, x);

% end algebraic procedures using rlprojamat

% begin algebraic procedures using rlprojamat2

symbolic operator rlprojsetco;
procedure rlprojsetco(afl, l);
   rlprojamat2(function ofsf_projsetco, afl, l);

symbolic operator rlprojsetcov22;
procedure rlprojsetcov22(afl, l);
   rlprojamat2(function ofsf_projsetcov22, afl, l);

symbolic operator rlprojsetcov23;
procedure rlprojsetcov23(afl, l);
   rlprojamat2(function ofsf_projsetcov23, afl, l);

symbolic operator rlprojsetcov33;
procedure rlprojsetcov33(afl, l);
   rlprojamat2(function ofsf_projsetcov33, afl, l);

symbolic operator rlprojsetcoho;
procedure rlprojsetcoho(afl, l);
   rlprojamat2(function ofsf_projsetcoho, afl, l);

% symbolic operator rlprojsetcohogen;
% procedure rlprojsetcohogen(afl, l);
%    rlprojamat2(function ofsf_projsetcohogen, afl, l);

symbolic operator rlprojsetcolg;
procedure rlprojsetcolg(afl, l);
   rlprojamat2(function ofsf_projsetcolg, afl, l);

symbolic operator rlprojsetmc;
procedure rlprojsetmc(afl, l);
   rlprojamat2(function ofsf_projsetmc, afl, l);

symbolic operator rlprojsetmcbr;
procedure rlprojsetmcbr(afl, l);
   rlprojamat2(function ofsf_projsetmcbr, afl, l);

symbolic operator rltgprojsetmcbr;
procedure rltgprojsetmcbr(afl, l);
   rltgprojamat2(function ofsf_tgprojsetmcbr, afl, l);

symbolic operator rlprojcov33;
procedure rlprojcov33(afl, l);
   rlprojamat2(function ofsf_projcov33, afl, l);

symbolic operator rlprojcobbv3;
procedure rlprojcobbv3(afl, l);
   rlprojamat2(function ofsf_projcobbv3, afl, l);

% end algebraic procedures using rlprojamat2

procedure ofsf_projsetco(aa, varl);
   ofsf_projset('ofsf_transfac, 'ofsf_projopco, aa, varl);

procedure ofsf_projsetcov22(aa, varl);
   ofsf_projset('ofsf_transfac, 'ofsf_projopcov22, aa, varl);

procedure ofsf_projsetcov23(aa, varl);
   ofsf_projset('ofsf_transfac, 'ofsf_projopcov23, aa, varl);

procedure ofsf_projsetcov33(aa, varl);
   ofsf_projset('ofsf_transfac, 'ofsf_projopcov33, aa, varl);

procedure ofsf_projsetcolg(aa, varl);
   ofsf_projset('ofsf_transfac, 'ofsf_projopcolg, aa, varl);

procedure ofsf_projsetmc(aa,varl);
   ofsf_projset('ofsf_transfac, 'ofsf_projopmc, aa, varl);

procedure ofsf_projsetmcbr(aa,varl);
   ofsf_projset('ofsf_transfac,'ofsf_projopmcbr, aa, varl);

procedure ofsf_tgprojsetmcbr(aa, varl);
   % [aa] is a List of tagged SF. Returns a List of tagged SF.
   ofsf_tgprojset('ofsf_tgtransfac, 'ofsf_tgprojopmcbr, aa, varl);

procedure ofsf_projcobbv3(aa, l);
   for each f in aa join
      ofsf_projcobb1v3(f, l);

procedure ofsf_tgprojset(tgtransfn, tgprojopfn, aa, varl);
   % Tagged projection set. [tgtransfn] is a tagged transformation on the
   % projection set, [tgprojopfn] is a tagged combined projection operator, [aa]
   % is the list of input polynomials and [varl] the list of variables. Returns
   % a LIST(tag(SF)).
   begin scalar w;
      w := for each a in aa collect tag_(a, {'input});
      return ofsf_projset1(tgtransfn, tgprojopfn, w, varl, 'ofsf_tgpolyoflevel, 'tgunion)
   end;

procedure ofsf_tgpolyoflevel(pp, varl, j);
   % Tagged polynomials of level [j]. Returns a List of tagged SF.
   lto_select1(function(lambda p, varl, j; sf_tgdeg(p, nth(varl, j)) > 0), pp, {varl, j});

procedure ofsf_tgtransfac(tgpp, x);
   % Factorization transformation. [tgpp] is a LIST(TAG(SF)), [x] is an ID.
   % Returns a SET(TAG(SF)).
   %%% more efficient: successive tgunion
   tglist2set for each tgp in tgpp join
      for each f in sf_factors tag_object tgp collect
	 tag_(f, tag_taglist tgp);

procedure ofsf_projopco(aa, varl, j);
   % Combined Collins' projection operator.
   if eqn(j, 2) then
      ofsf_projco2v(aa, nth(varl, j))
   else
      ofsf_projco(aa, nth(varl, j));

procedure ofsf_projopcov22(aa, varl, j);
   % Combined Collins' projection operator.
   if eqn(j, 2) then
      ofsf_projco2v(aa, nth(varl, j))
   else
      ofsf_projcov22(aa, nth(varl, j));

procedure ofsf_projopcov23(aa, varl, j);
   % Combined Collins' projection operator, version 2-3.
   if eqn(j, 2) then
      ofsf_projco2v(aa, nth(varl, j))
   else
      ofsf_projcov23(aa, nth(varl, j));

procedure ofsf_projopcov33(aa, varl, j);
   % Combined Collins' projection operator, version 3-3.
   if eqn(j, 2) then
      ofsf_projco2v(aa, nth(varl, j))
   else
      ofsf_projcov33(aa, lto_take(varl, j));

procedure ofsf_projopmc(aa, varl, j);
   % Combined McCallum's projection operator.
   ofsf_projmc(aa, nth(varl, j));

procedure ofsf_projopmcbr(aa, varl, j);
   % Combined Brown's improvement to McCallum's projection operator.
   ofsf_projmcbr(aa, nth(varl, j));

procedure ofsf_tgprojopmcbr(aa, varl,j);
   % Combined tagged Brown's improvement to McCallum's projection operator.
   ofsf_tgprojmcbr(aa, nth(varl, j));

procedure ofsf_projco(aa, x);
   % Collin's projection operator, simplest version.
   begin scalar bb, ll, ss1, ss2;
      bb := ofsf_projcobb(aa, x);
      ll := ofsf_projlcs(bb, x);
      ss1 := ofsf_projcoss1(bb, x);
      ss2 := ofsf_projcoss2(bb, x);
      return list2set lto_select('notdomainp, union(union(ll, ss1), ss2))
   end;

procedure ofsf_projcov22(aa, x);
   % Collin's projection operator, B and S1 version 2.
   begin scalar bb, ll, ss1, ss2;
      bb := ofsf_projcobbv2(aa, x);
      ll := ofsf_projlcs(bb, x);
      ss1 := ofsf_projcoss1(bb, x);
      ss2 := ofsf_projcoss2v2(bb, x);
      return list2set lto_select('notdomainp, union(union(ll, ss1), ss2))
   end;

procedure ofsf_projcov23(aa, x);
   % Collin's projection operator, version 3. Returns a SET(SF) with non-domain
   % elements. Remark: union does not require the first argument to be a set.
   begin scalar bb, ll, ss1, ss2;
      bb := ofsf_projcobbv2(aa, x);
      ll := ofsf_projlcs(bb, x);
      ss1 := ofsf_projcoss1(bb, x);
      ss2 := list2set ofsf_projcoss2v3(bb, x);
      return lto_select('notdomainp, union(union(ll, ss1), ss2))
   end;

procedure ofsf_projcov33(aa, l);
   % Collin's projection operator, version 3. Returns a SET(SF) with non-domain
   % elements.
   begin scalar bb, ll, ss1, ss2, x;
      bb := ofsf_projcobbv3(aa, l);
      x := lto_last l;
      ll := ofsf_projlcs(bb, x);
      ss1 := ofsf_projcoss1(bb, x);
      ss2 := list2set ofsf_projcoss2v3(bb, x);
      return lto_select('notdomainp, union(union(ll, ss1), ss2))
   end;

procedure ofsf_tgprojmc(tgaa,x);
   % McCallum's projection operator for squarefree basis, tagged version. [tgaa]
   % is a LIST(TAG(SF)). Returns a LIST(TAG(SF)).
   begin scalar aa,tgll,tgdd,tgrr;
      % strip off all the tags
      aa := for each te in tgaa join
	 if not domainp tag_object te then {tag_object te};
      % tag the leading coefficients
      tgll := for each f in ofsf_projmccoeffs(aa,x) collect
	 tag_(sf_lc(f,x),{'lc});
      % tag the discriminants
      tgdd := for each a in aa collect tag_(sf_discriminant(a,x),{'dis});
      % tag the resultants
      tgrr := for each a1 on aa join for each a2 in cdr aa collect
	 tag_(sfto_resf(car a1,a2,x),{'res});
      return lto_remove('tgdomainp,
	 tgunion(tgll,tgunion(tgdd,tglist2set tgrr)) )
   end;

procedure ofsf_projmcbr(aa,x);
   % Brown's improvement to McCallum's projection operator for squarefree basis.
   % . Returns a LIST(SF).
   begin scalar bb,ll,dd,rr;
      bb := lto_remove('domainp,aa);
      ll := for each f in bb collect sf_lc(f,x);
      dd := for each a in bb collect sf_discriminant(a,x);
      rr := for each a1 on bb join for each a2 in cdr bb collect
	 sfto_resf(car a1,a2,x);
      return list2set lto_remove('domainp,union(union(ll,dd),rr))
   end;

procedure ofsf_tgprojmcbr(tgaa,x);
   % Brown's improvement to McCallum's projection operator for
   % squarefree basis, tagged version. [tgaa] is a LIST(TAG(SF)).
   % Returns a LIST(TAG(SF)).
   begin scalar bb,tgll,tgdd,tgrr;
      %      bb := lto_remove('tgdomainp,tgaa);
      % strip off all the tags
      bb := for each te in tgaa join
	 if not domainp tag_object te then {tag_object te};
      % tag the leading coefficients
      tgll := for each f in bb collect tag_(sf_lc(f,x),{'lc});
      % tag the discriminants
      tgdd := for each a in bb collect tag_(sf_discriminant(a,x),{'dis});
      % tag the resultants
      tgrr := for each a1 on bb join for each a2 in cdr bb collect
	 tag_(sfto_resf(car a1,a2,x),{'res});
      return lto_remove('tgdomainp,
	 tgunion(tgll,tgunion(tgdd,tglist2set tgrr)) )
   end;

procedure ofsf_projcobb(aa,x);
   % Collins' projection set of redukta R (straightforward version).
   % [aa] is a list of SF, x is an identifier. Returns a set of SF.
   % Note that the output is compliant with ofsf_projcoss1v3.
   for each f in aa join ofsf_projcobb1(f,x);

procedure ofsf_projcobb1v3(f,varl);
   % Collins' redukta (version 2) subroutine R1v3. [f] is a SF, [varl] is a list
   % of identifiers. Returns a list of SF with positive degree in [x], the list
   % is ordered such that the degrees are descending;
   begin scalar rr2,rr2p;
      rr2 := ofsf_projcobb1v2(f,nth(varl,length varl));
      if null rr2 then return rr2;
      repeat <<
	 rr2p := car rr2 . rr2p;
	 rr2 := cdr rr2;
      >> until null rr2 or sfto_zerodimp(rr2p,varl);
      return reversip rr2p;
   end;

procedure ofsf_projcoss2(bb,x);
   % Collins' projection set S1 simplest version. [bb] is a list of
   % SF, [x] is an identifier. Returns a list of SF.
   for each b1 in bb join for each b2 in cdr bb join sf_pscs(b1,b2,x);

procedure ofsf_projcoss2v2(bb,x);
   % Collins' projection set version 2. [bb] is a list of SF, [x] is an
   % identifier. Returns a list of SF.
   for each b1 on bb join for each b2 in cdr bb join sf_pscs(car b1,b2,x);

procedure ofsf_projcoss2v3(bb,x);
   % Collins' projection set S1 version 3. [bb] is a list of SF, [x]
   % is an identifier. Returns a list of SF. Note that for this to
   % work properly, the list bb of reducta has to look like
   % {f,red(f),red(red(f)),...,g,red(g),red(red(g)),...}
   begin scalar ss2,redll;
      % 1. break bb up into sets containing an imput poly and its reducta
      redll := ofsf_splitredl(bb,x);
      % 2.
      ss2 := for each ll on redll join for each l in cdr ll join
	 % car ll and l are lists of SF
	 for each b1 in car ll join for each b2 in l join sf_pscs(b1,b2,x);
      return ss2
   end;

% end projection sets-related code

symbolic operator rlzerodimp;
procedure rlzerodimp(afl,l);
   % [afl] is a list of algebraic forms (lisp prefix) and [l] is an list of
   % identifiers. Returns a natural number or the empty set {}.
   begin scalar oldorder,w;
      oldorder := setkorder reverse cdr l;
      w := apply(function(sfto_zerodimp1),
	 {for each af in cdr afl collect numr simp af});
      setkorder(oldorder);
      return if null w then '(list) else w
   end;

procedure sfto_zerodimp(l,varl);
   % Zero dimensional predicate. [l] is a list of SF, varl is a list of IDs.
   % Returns a natural number (an upper limit for the dimension) or nil (if the
   % ideal is not zero dimensional).
   begin scalar oldorder,res;
      oldorder := setkorder reverse varl;
      res := sfto_zerodimp1 l;
      setkorder oldorder;
      return res
   end;

procedure sfto_zerodimp1(l);
   % Zero dimensional predicate. [l] is a list of SF. Returns a natural number
   % (an upper bound for the dimension) or nil (if the ideal is not zero
   % dimensional).
   begin scalar svkord,oldtorder,basis,htl,minexpl;
      svkord := kord!*;
      oldtorder := cdr torder {'list . kord!*,'revgradlex}; % gb notwendig
      basis := sfto_groebnerf l;
      torder oldtorder;
      kord!* := svkord;
      htl := for each f in basis collect sfto_hterm f;
      minexpl := for each x in kord!* collect sfto_zerodimp2(x,htl);
      if memq(nil,minexpl) then return nil;
      return foldr1(function(lambda a,b;a*b),minexpl);
   end;

procedure sfto_zerodimp2(x,htl);
   % . x is an ID, [htl] is a list of SF (head terms). Returns a
   % natural number or nil.
   begin scalar expl;
      expl := nil;
      for each ht in htl do
	 if domainp ht then
	    expl := 0 . expl
	 else if (mvar ht eq x and domainp sf_lc(ht,x)) then
	    expl := sfto_vardeg(ht,x) .expl;
      if null expl then return nil else
	 return foldr1(function(lambda a,b;if a<b then a else b),expl);
   end;

procedure sfto_hterm(f);
   % Highest term. f is a SF. Returns a SF.
   if domainp f then
      f
   else
      multf(sf_lc(f,mvar f),sfto_kexp(mvar f,sfto_vardeg(f,mvar f)));

asserted procedure sf_nom(f: SF): Integer;
   % Number of monomials.
   if null f then
      0
   else if domainp f then
      1
   else
      sf_nom lc f + sf_nom red f;

asserted procedure sf_subresultant(f: SF, g: SF, x: Kernel, j: Integer): SF;
   % Subresultant.
   begin scalar summed;
      for i := 0 : j do
	 summed := addf(multf(mtx_det mtx_mmji(f,g,x,j,i),sfto_kexp(x,i)), summed);
      return summed
   end;

asserted procedure sf_fromcdl(cdl: List, x: Kernel): SF;
   % Standard form from coefficient and degree list. [cdl] is a non-empty List
   % of pairs [SF . Integer].
   begin scalar f;
      assert(not null cdl);
      if null cdr cdl then
	 return caar cdl;
      f := sfto_kexp(x, cdar cdl);
      set_lc(f, caar cdl);
      set_red(f, sf_fromcdl(cdr cdl, x));
      return f
   end;

asserted procedure mtx_resultant(f: SF, g: SF, x: Kernel): SF;
   if null f or null g then
      0
   else if eqn(sfto_vardeg(f, x) + sfto_vardeg(g, x), 0) then
      1
   else
      mtx_det mtx_sylvester(f, g, x);
