% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-2009 A. Dolzmann, T. Sturm, 2010 T. Sturm
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
   fluid '(lto_rcsid!* lto_copyright!*);
   lto_rcsid!* := "$Id$";
   lto_copyright!* := "(c) 1995-2009 A. Dolzmann, T. Sturm, 2010 T. Sturm"
>>;

module lto;
% List tools.

operator setminus;

procedure lto_insert(x,l);
   % List tools insert. [x] is any S-expression, [l] is a list. Conses
   % [x] to [l] if [x] is not already member of [l].
   if x member l then l else x . l;

procedure lto_insertq(x,l);
   % List tools insert testing with memq. [x] is any S-expression, [l]
   % is a list. Conses [x] to [l] if [x] is not already [memq].
   if x memq l then l else x . l;

procedure lto_quicksort(l,sortp);
   % List tools quick sort. [l] is a list; [sortp] is a function that
   % implements an ordering. Returns a list. [l] is sorted such that
   % [sortp] holds between each two adjacent elements.
   begin scalar crit,s1,s2;
      % Empty and one-element lists are already sorted.
      if null l or null cdr l then return l;
      % Construct two sets by comparing all others with the first one.
      crit := car l;
      for each entry in cdr l do
    	 if apply(sortp,{entry,crit}) then
 	    s1 := entry . s1
 	 else
 	    s2 := entry . s2;
      % sort the two lists recursively and place crit in between
      return nconc(lto_quicksort(s1,sortp),crit . lto_quicksort(s2,sortp))
   end;

procedure lto_mergesort(l,sortp);
   % List tools merge sort. [l] is a list; [sortp] is a function that
   % implements an ordering. Returns a list. [l] is sorted such that
   % [sortp] holds between each two adjacent elements.
   begin scalar s1,s2,w,rslt;
      % Empty and one-element lists are already sorted.
      if null l or null cdr l then return l;
      % split l into two lists
      for each entry in l do
         if (w := null w) then s1 := entry . s1 else s2 := entry . s2;
      s1 := lto_mergesort(s1,sortp);
      s2 := lto_mergesort(s2,sortp);
      % combine the two sorted lists into one sorted list
      rslt := nil . nil;
      w := rslt;
      while s1 and s2 do <<
         if apply(sortp,{car s1,car s2}) then <<
            cdr w := car s1 . nil;
            s1 := cdr s1
         >> else <<
            cdr w := car s2 . nil;
            s2 := cdr s2
         >>;
         w := cdr w
      >>;
      cdr w := if s1 then s1 else s2;
      return cdr rslt
   end;

procedure lto_listend(l);
   % List tools list end. [l] is a non-empty list. Returns the last pair
   % of [l].
   if cdr l then lto_listend cdr l else l;

procedure lto_sublistp(l1,l2);
   % List tools sublist predicate. [l1] and [l2] are lists. Returns non-nil if
   % all elements of [l2] are in [l1] and in the same order.
   if l1 and l2 then
      if car l1 = car l2 then
         lto_sublistp(cdr l1,cdr l2)
      else
         lto_sublistp(cdr l1,l2)
   else
      null l2;

procedure lto_alinsert(key,val,al);
   % List tools alist insert. [key] is non-nil, [val] is any and [al] is
   % an alist having lists as values. Returns an alist where [val] is inserted
   % into the list belonging to [key].
   begin scalar w;
      w := assoc(key,al);
      if null w then return ((key . {val}) . al);
      cdr w := val . cdr w;
      return al
   end;

procedure lto_lengthp(l,n,compp);
   % List tools length predicate. [l] is a list, [n] is a number and [compp]
   % is a function comparing two numbers. Returns [compp](length [l],[n]).
   if null l then
      apply(compp,{0,n})
   else if eqn(n,0) then
      apply(compp,{1,0})
   else
      lto_lengthp(cdr l,n-1,compp);

procedure lto_catsoc(key,al);
   % List tools conditional atsoc. [key] is an identifier; [al] is an
   % alist $((k_1 . e_1),...,(k_n . e_n))$. Returns $e_i$ if [key] is
   % [eq] to $k_i$, [nil] else.
   (if x then cdr x) where x=atsoc(key,al);

procedure lto_natsoc(key,al);
   % List tools conditional number atsoc. [key] is an identifier; [al]
   % is an alist $((k_1 . e_1),...,(k_n . e_n))$. Returns $e_i$ if
   % $[key]=k_i$, 0 else.
   (if w then cdr w else 0) where w=atsoc(key,al);

procedure lto_cassoc(key,al);
   % List tools conditional assoc. [key] is an identifier; [al] is an
   % alist $((k_1 . e_1),...,(k_n . e_n))$. Returns $e_i$ if
   % $[key]=k_i$, [nil] else.
   (if x then cdr x) where x=assoc(key,al);

asserted procedure lto_eatsoc(key: Id, al: Alist, emsg: List);
   (if x then cdr x else rederr emsg) where x=assoc(key,al);

procedure lto_appendn(l);
   for each x in l join append(x,nil);

procedure lto_nconcn(l);
   % List tools non-constructive concatenate n-ary. [l] is a list of
   % lists. Returns a list. The returned list is the concatenation of
   % all lists in [l]. The lists in [l] are possibly modyfied.
   if cdr l then nconc(car l,lto_nconcn cdr l) else car l;

procedure lto_alunion(all);
   % List tools assoc list union. [all] is a list of alists $((k1 .
   % e1) ... (kn . en))$, where all ki are unique and all ei are
   % lists. Merges all alists in [all] into one alist, where the keys
   % are the union of all ki appearing in the members of [all], and
   % the entry to each key is the union of the lists that are entries
   % to the key within the members of [all]. All members of [all] are
   % modified by this function.
   lto_almerge(all,'union);

procedure lto_almerge(all,merge);
   % List tools assoc list merge. [all] is a list of alists $((k1 . e1)
   % ... (kn . en))$, where all ki are unique and all ei are entries,
   % which are any; [merge] is a function that maps two entries to
   % another entry. Merges all alists in [all] into one alist, where the
   % keys are the union of all ki appearing in the members of [all], and
   % the entry to each key is obtained from the entries in [all] by
   % applying [merge]. All members of [all] are modified by this
   % function.
   begin scalar l2,a;
      if null all then return nil;
      if null cdr all then return car all;
      if null cddr all then <<
	 l2 := cadr all;
    	 for each pair in car all do <<
      	    a := assoc(car pair,l2);
      	    if a then
 	       cdr a := apply(merge,{cdr pair,cdr a})
      	    else
 	       l2 := pair . l2
    	 >>;
    	 return l2
      >>;
      return lto_almerge({car all,lto_almerge(cdr all,merge)},merge)
   end;

procedure lto_idconcat2(id1,id2);
   % List tools identifier concatenation 2. [id1] and [id2] are
   % identifiers. Returns an identifier. The returned identifier is
   % the concatenation [s1][s2]. The result is not interned if you are
   % using PSL.
   compress nconc(explode id1,explode id2);

procedure lto_idconcat(l);
   % List tools identifier concatenation. [l] is a list of
   % identifiers. Returns an identifier. The returned identifier is
   % the concatenation of all identifiers in [l]. The result is not
   % interned if you are using PSL.
   compress for each id in l join explode id;

procedure lto_sconcat2(s1,s2);
   % List tools string concatenation 2. [s1] and [s2] are strings.
   % Returns a string. The returned string is the concatenation
   % [s1][s2].
   compress append(reversip cdr reversip explode s1,cdr explode s2);

asserted procedure lto_sconcat(l: List): String;
   % List tools string concatenation. [l] is a list of strings.
   % Returns a string. The returned string is the concatenation of all
   % strings in [l].
   if l then
      if cdr l then
 	 lto_sconcat2(car l,lto_sconcat cdr l)
      else
	 car l
   else
      "";

asserted procedure lto_substr(s: String, n: Integer, m: Integer): ExtraBoolean;
   % Return the n character substring starting at m, or nil.
   begin scalar l, res;
      if eqn(m, 0) then
	 return nil;
      l := cdr explode s;
      while not eqn(m, 1) and l do <<
	 m := m - 1;
	 pop l
      >>;
      if not l then
 	 return nil;
      res := '!" . nil;
      while not eqn(n, 0) and l do <<
	 n := n - 1;
	 res := pop l . res
      >>;
      if not l then
 	 return nil;
      return compress reversip('!" . res)
   end;

asserted procedure lto_string2id(s: String): Id;
   intern compress explodec s;

procedure lto_max(l);
   if null l then '(minus infinity) else lto_max1 l;

procedure lto_max1(l);
   % List tools maximum of a list. [l] is a list of integers. Returns
   % the maximum of [l].
   if null cdr l then car l else max(car l,lto_max1 cdr l);

procedure lto_min(l);
   if null l then 'infinity else lto_min1 l;

procedure lto_min1(l);
   % List tools minimum of a list. [l] is a list of integers. Returns
   % the maximum of [l].
   if null cdr l then car l else min(car l,lto_min1 cdr l);

procedure lto_ravg(l);
   % Rounded arithmetic mean of a list. [l] is a list of integers. Returns a
   % float.
   begin integer s, n;
      if null l then
	 rederr "lto_ravg: empty list";
      s := for each x in l sum <<
	 n := n + 1;
	 x
      >>;
      return float s / float n
   end;

procedure lto_rmedian(l);
   % Rounded median of a list. [l] is a list of integers. Returns a float.
   begin integer n, n2;
      if null l then
	 rederr "lto_rmedian: empty list";
      l := sort(l, 'leq);
      n := length l;
      n2 := n/2;
      if evenp n then
      	 return (float nth(l, n2) + float nth(l, n2+1)) / 2.0;
      return float nth(l, n2+1)
   end;

procedure lto_sgnchg(l);
   % List tools number of sign changes of a list. [l] is a list of integers.
   % Returns the number of sign changes when all zeroes are left out.
   lto_sgnchg1(for each n in l join if sgn n = 0 then nil else {n});

procedure lto_sgnchg1(l);
   % List tools number of sign changes of a list 1. [l] is a list of non-zero
   % integers. Returns the number of sign changes.
   if null l or null cdr l then
      0
   else if sgn car l eq sgn cadr l then
      lto_sgnchg1 cdr l
   else
      lto_sgnchg1 cdr l + 1;

procedure setminus(l1,l2);
   'list . lto_setminus(cdr l1,cdr l2);

procedure lto_setminus(l1,l2);
   for each x in l1 join if not member(x,l2) then {x};

procedure lto_unionn(l);
   if null l then nil else union(car l, lto_unionn cdr l);

switch rlsetequalqhash;  % keep it local because it is temporary --TS
on1 'rlsetequalqhash;

procedure lto_setequalq(s1,s2);
   % s1 and s2 are lists of identifiers not containing any duplicates.
   begin scalar c,a1,a2,svs1,svs2,w; integer n1,n2;
      w := if !*rlsetequalqhash then
 	 lto_hashequalq(s1,s2)
      else
	 lto_equallengthp(s1,s2);
      if not w then
	 return nil;
      c := t; while c and s1 do <<
	 a1 := car s1;
	 if a1 memq s2 then
	    s1 := cdr s1
	 else
	    c := nil
      >>;
      return c
   end;

procedure lto_hashequalq(s1,s2);
   % s1 and s2 are lists of identifiers.
   begin scalar a1,a2; integer n1,n2;
      while s1 and s2 do <<
	 a1 := car s1;
	 a2 := car s2;
	 s1 := cdr s1;
	 s2 := cdr s2;
	 n1 := n1 #+ lto_hashid a1;
	 n2 := n2 #+ lto_hashid a2
      >>;
      return null s1 and null s2 and (n1 #= n2)
   end;

procedure lto_equallengthp(s1,s2);
   <<
      while s1 and s2 do <<
	 s1 := cdr s1;
	 s2 := cdr s2
      >>;
      null s1 and null s2
   >>;

procedure lto_lengthgeq(l,n);
   % Length greater than or equal. [l] is a list; [n] is a non-negative
   % number. Returns bool.
   eqn(n,0) or (l and lto_lengthgeq(cdr l,n-1));

procedure lto_cartprod(s);
   % Cartesian product. [s] is a list $(s_1,...,s_n)$ of lists. Returns
   % $s_1 \times ... \times s_n$ as a list of $n$-element lists. The
   % empty set and singletons are their own cartesian product.
   if null s or null cdr s then s else lto_cartprod1 s;

procedure lto_cartprod1(s);
   % Cartesian product. [s] is a list $(s_1,...,s_n)$ of lists with $n
   % \geq 2$. Returns $s_1 \times ... \times s_n$ as a list of
   % $n$-element lists.
   begin scalar w;
      if null cdr s then
      	 return for each m in car s collect {m};
      w := lto_cartprod1 cdr s;
      return for each m in car s join
      	 for each y in w collect m . y
   end;

procedure lto_hmember(item,hl,hfn);
   lto_hmember1(item,hl,apply(hfn,{item}));

procedure lto_hmember1(item,hl,keyl);
   begin scalar w;
      if not keyl then
	 return member(item,hl);
      w := assoc(car keyl,hl);
      if not w then
	 return nil;
      return lto_hmember1(item,cdr w,cdr keyl)
   end;

procedure lto_hinsert(item,hl,hfn);
   lto_hinsert1(item,hl,apply(hfn,{item}));

procedure lto_hinsert1(item,hl,keyl);
   begin scalar key,w;
      if not keyl then
	 return item . hl;
      key := car keyl;
      w := assoc(key,hl);
      if not w then
	 return lto_hentry(key,cdr keyl,item) . hl;
      cdr w := lto_hinsert1(item,cdr w,cdr keyl);
      return hl
   end;

procedure lto_hentry(key,keyl,item);
   if not keyl then
      key . {item}
   else
      key . {lto_hentry(car keyl,cdr keyl,item)};

procedure lto_hdelete(item,hl,hfn);
   lto_hdelete1(item,hl,apply(hfn,{item}));

procedure lto_hdelete1(item,hl,keyl);
   begin scalar w,key;
      if not keyl then
      	 return deletip(item,hl);
      key := car keyl;
      w := assoc(key,hl);
      if w then
	 cdr w := lto_hdelete1(item,cdr w,cdr keyl);
      return hl
   end;

procedure lto_subset(s1, s2);
   null s1 or car s1 member s2 and lto_subset(cdr s1, s2);

procedure lto_subsetq(s1, s2);
   null s1 or car s1 memq s2 and lto_subsetq(cdr s1, s2);

procedure lto_zip(l1, l2, f);
   if l1 and l2 then
      apply(f, {car l1, car l2}) . lto_zip(cdr l1, cdr l2, f);

procedure lto_partition(l, f);
   begin scalar goodl, badl;
      for each x in l do if apply(f, {x}) then
	 goodl := x . goodl
      else
	 badl := x . badl;
      return reversip goodl . reversip badl
   end;

procedure lto_delnthip(l, n);
   % Delete the nth member of l in place.
   begin scalar scl;
      if null l then
	 rederr {"index", n, "out of range for in lto_delnthip"};
      if n < 1 then
 	 return l;
      if eqn(n, 1) then
      	 return cdr l;
      scl := l;
      for i := 1 : n-2 do
	 if cdr scl then
 	    scl := cdr scl
	 else
	    rederr {"index", n, "out of range in lto_delnthip"};
      if cdr scl then
      	 cdr scl := cddr scl
      else
	 rederr {"index", n, "out of range in lto_delnthip"};
      return l
   end;

procedure lto_apply2nthip(l, n, fun, xargl);
   begin scalar scl;
      if n < 1 then
	 rederr {"index", n, "out of range in lto_apply2nthip"};
      scl := l;
      for i := 1 : n-1 do
	 if cdr scl then
	    scl := cdr scl
	 else
	    rederr {"index", n, "out of range in lto_apply2nthip"};
      car scl := apply(fun, car scl . xargl);
      return l
   end;

#if (memq 'csl lispsystem!*)
   procedure lto_hashid(id);
      sxhash id;
#endif

#if (memq 'psl lispsystem!*)
   procedure lto_hashid(id);
      id2int id;
#endif

#if (not (memq 'psl lispsystem!*))
   procedure delq(x,l);
      % Delete with memq. [x] is ANY; [l] is a list. Returns a list.
      % The first occurence of an element identical to [x] in [l] is
      % deleted.
      if l then if car l eq x then cdr l else car l . delq(x,cdr l);
#endif

#if (not (memq 'psl lispsystem!*))
   procedure delqip(u,v);
      % Delete with memq in place. [u] is ANY; [v] is a list. Returns
      % a list. The first occurence of an element identical to [u] in
      % [v] is deleted [v] is possibly modified.
      if not pairp v then
	 v
      else if u eq car v then
	 cdr v
      else <<
	 delqip1(u,v);
	 v
      >>;
#endif

#if (not (memq 'psl lispsystem!*))
   procedure delqip1(u,v);
      % Delete with memq in place subroutine. [u] is ANY; [v] is a
      % list, such that [not(car v eq u)]. Returns a list. The first
      % occurence of an element identical to [u] in [v] is deleted [v]
      % is possibly modified.
      if not pairp cdr v then
	 nil
      else if u eq cadr v then
	 rplacd(v,cddr v)
      else
	 delqip1(u,cdr v);
#endif

#if (not (memq 'psl lispsystem!*))
   procedure adjoin(x,l);
      % Adjoin. [x] is any S-expression, [l] is a list. Conses [x] to
      % [l] if [x] is not already member of [l].
      if x member l then l else x . l;
#endif

#if (not (memq 'psl lispsystem!*))
   procedure list2set(l);
      % Remove redundant elements from L.
     if not pairp l then
 	 nil
      else if car l member cdr l then
 	 list2set cdr l
      else
 	 car l . list2set cdr l;
#endif

#if (not (memq 'psl lispsystem!*))
   procedure list2vector(l);
      % Create a vector and store the list l into it.
      begin integer i; scalar v;
      	 v := mkvect sub1 length l;
      	 i := 0;
      	 for each vl in l do <<
	    putv(v,i,vl);
 	    i := i+1
	 >>;
      	 return v
      end;
#endif

#if (not (memq 'csl lispsystem!*))
   procedure symbol!-name(s);
      % List tools atom to string. [s] is an atom. Returns the print name
      % of the atom [s] as a string. This is not quite correct: e.g. lto_at2str
      % '!" would fail.
      compress('!" . reversip('!" . reversip explode s));
#endif

procedure lto_at2str(s);
   if idp s then
      symbol!-name s
   else
      compress('!" . reversip('!" . reversip explode s));

inline procedure lto_fastgensym();
   <<
      if !*rlgensymintern then intern w else remob w;
      w
   >> where w = compress('!! . '!_ . 'k . explode(cdr rlgensymfast!* := cdr rlgensymfast!* + 1));

inline procedure lto_gensym();
   lto_gensym1 rlgensymbase!*;

asserted procedure lto_gensym1(base: Id): Id;
   begin scalar l, w; integer c;
      c := atsoc(base, rlgensymcountal!*);
      if c then
      	 cdr c := cdr c + 1
      else <<
	 c := base . 1;
	 push(c, rlgensymcountal!*)
      >>;
      l := explode cdr c;
      for i := length l + 1 : rlgensymlen!* do push('!0, l);
      w := compress nconc(explode base, l);
      if !*rlgensymintern then intern w else remob w;
      return w
   end;

procedure lto_maxkl(kl);
   % Maximum of a kernel list. [kl] is a list of kernels. Returns the greatest
   % kernel w.r.t. kord!* or nil if [kl] is nil.
   begin scalar m, w;
      if null kl then
      	 return nil;
      m := pop kl;
      while kl do <<
	 w := pop kl;
	 if ordop(m, w) then
	    m := w
      >>;
      return m
   end;

asserted procedure lto_0listp(l: List): Boolean;
   % Is [l] a list of zeros?
   null l or eqn(car l, 0) and lto_0listp cdr l;

asserted procedure lto_alphap(x: Id): ExtraBoolean;
   begin scalar alphabet, c, l;
      alphabet := '(a b c d e f g h i j k l m n o p q r s t u v w x y z
	 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z);
      c := t;
      l := explode x;
      while c and l do
	 c := pop l memq alphabet;
      return c
   end;

asserted procedure lto_upcase(s: String): String;
   compress for each c in explode s collect lto_charUpcase c;

asserted procedure lto_charUpcase(c: Id): Id;
   begin scalar table;
      table := '((!a . !A) (!b . !B) (!c . !C) (!d . !D) (!e .  !E) (!f . !F)
       	 (!g . !G) (!h . !H) (!i . !I) (!j . !J) (!k . !K) (!l . !L) (!m . !M)
         (!n . !N) (!o . !O) (!p . !P) (!q . !Q) (!r . !R) (!s . !S) (!t . !T)
         (!u . !U) (!v . !V) (!w . !W) (!x . !X) (!y . !Y) (!z. !Z));
      return lto_catsoc(c, table) or c
   end;

asserted procedure lto_downcase(s: String): String;
   compress for each c in explode s collect lto_charDowncase c;

asserted procedure lto_charDowncase(c: Id): Id;
   begin scalar table;
      table := '((!A . !a) (!B . !b) (!C . !c) (!D . !d) (!E .  !e) (!F . !f)
       	 (!G . !g) (!H . !h) (!I . !i) (!J . !j) (!K . !k) (!L . !l) (!M . !m)
         (!N . !n) (!O . !o) (!P . !p) (!Q . !q) (!R . !r) (!S . !s) (!T . !t)
         (!U . !u) (!V . !v) (!W . !w) (!X . !x) (!Y . !y) (!Z. !z));
      return lto_catsoc(c, table) or c
   end;

asserted procedure lto_stringDescriptionList(al: Alist, indent: Integer, colsep: Integer, len: Integer, xdtl: List): List;
   begin scalar line, lines, indentl, dt, ddl; integer llen, roffset, lendt;
      for i := 1:indent do <<
	 push('!!, indentl);
	 push('! , indentl)
      >>;
      for each pr in al do
	 llen := max2(llen, lto_strlen car pr);
      for each x in xdtl do
	 llen := max2(llen, lto_strlen x);
      roffset := indent + llen + colsep;
      line := indentl;
      for each pr in al do <<
	 dt := car pr;
	 lendt := lto_strlen dt;
	 for each c in explodec dt do <<
	    push('!!, line);
	    push(c, line)
	 >>;
	 ddl := lto_stringParagraph(cdr pr, 0, len - roffset);
	 for each l in ddl do <<
	    for i := indent +  lendt : roffset do <<
	       push('!!, line);
	       push('! , line)
	    >>;
	    for each c in explodec l do <<
	       push('!!, line);
	       push(c, line)
	    >>;
      	    push(id2string compress reverse line, lines);
      	    line := indentl;
	    lendt := 0
	 >>
      >>;
      return reversip lines
   end;

asserted procedure lto_stringParagraph(s: String, indent: Integer, len: Integer): List;
   lto_stringFormat(lto_stringSplit(s, {'! , !$eol!$, cr!*, ff!*, tab!*}), indent, len);

asserted procedure lto_stringSplit(s: String, fsl: List): String;
   % Split a string into a list of strings; fs is a list of identifiers used as
   % field separators.
   begin scalar wl, sl, fsl;
      for each c in explodec s do
	 if c memq fsl then <<
	    if wl then <<
	       push(id2string compress reversip wl, sl);
	       wl := nil
	    >>
      	 >> else <<
	    push('!!, wl);
	    push(c, wl)
	 >>;
      if wl then
	 push(id2string compress reversip wl, sl);
      return reversip sl
   end;

asserted procedure lto_stringFormat(sl: List, indent: Integer, len: Integer): List;
   % Convert a list [sl] of words into a list of lines of length at most [len]
   % with an indent of [indent] spaces.
   begin scalar line, lines, indentl, s; integer l, slen;
      l := len - indent;
      for i := 1:indent do <<
	 push('!!, indentl);
	 push('! , indentl)
      >>;
      line := indentl;
      for each rest on sl do <<
	 s := car rest;
	 slen := lto_strlen s;
	 if slen > l and line neq indentl then <<
	    push(id2string compress reverse cddr line, lines);
	    line := indentl;
	    l := len - indent
	 >>;
	 for each c in explodec s do <<
	    push('!!, line);
	    push(c, line)
	 >>;
	 l := l - slen;
	 if cdr rest then <<
	    push('!!, line);
	    push('! , line);
	    l := l - 1
	 >>
      >>;
      push(if line then id2string compress reversip line else "", lines);
      return reversip lines
   end;

asserted procedure lto_strlen(s: String): Integer;
   % Number of characters in [s] excluding the double quotes.
   length explodec s;

asserted procedure lto_vertexCover(el: List): List;
   % [el] is a list of pairs of interned identifiers representing edges. Returns
   % a list of identifiers representing vertices. The result is a minimum vertex
   % cover of [el].
   begin scalar oc, seenl, fl, obj, z, zz, w, best;
      oc := rl_set '(r);
      for each e in el do <<
	 for each v in {car e, cdr e} do
	    if not (v memq seenl) then <<
	       push(v, seenl);
	       push(lto_vcZeroOrOne !*k2f v, fl);
	       obj := addf(obj, !*k2f v)
	    >>;
	 push(lto_vcEdgeGeqOne(!*k2f car e, !*k2f cdr e), fl)
      >>;
      zz := intern gensym();
      z := !*k2f zz;
      w := ofsf_xopt!-ansl!-ansl ofsf_xopt!-xopt
 	 cl_ex(rl_smkn('and, ofsf_0mk2('geq, addf(z, negf obj)) . fl), {zz});
      best := pop w;
      for each ans in w do
	 if lto_vcBetterp(ans, best, z) then
 	    best := ans;
      w := for each pr in ofsf_xopt!-ans!-pt best join
	 if eqn(cdr pr, 1) then
 	    {car pr};
      rl_set oc;
      return w
   end;

asserted procedure lto_vcZeroOrOne(v: SF): Formula;
   rl_mkn('or, {ofsf_0mk2('equal, v), ofsf_0mk2('equal, addf(v, negf 1))});

asserted procedure lto_vcEdgeGeqOne(v1: SF, v2: SF): Formula;
   ofsf_0mk2('geq, addf(addf(v1, v2), negf 1));

asserted procedure lto_vcBetterp(a1: Pair, a2: Pair, z: SF): Boolean;
   addf(negf ofsf_arg2l ofsf_xopt!-ans!-gd a1, z) < addf(negf ofsf_arg2l ofsf_xopt!-ans!-gd a2, z);

asserted procedure lto_loremIpsumAl(): Alist;
   '(("Lorem" .  "Lorem ipsum dolor sit amet, consectetur adipisici elit, sed eiusmod tempor incidunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquid ex ea commodi consequat. Quis aute iure reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint obcaecat cupiditat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.")
     ("Duis" .  "Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.")
     ("Ut" . "Ut  wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.")
     ("Nam" . "Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.")
     ("Duis" . "Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis.")
     ("At" . "At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, At accusam aliquyam diam diam dolore dolores duo eirmod eos erat, et nonumy sed tempor et et invidunt justo labore Stet clita ea et gubergren, kasd magna no rebum. sanctus sea sed takimata ut vero voluptua. est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat.")
     ("Consetetur" . "Consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet."));

asserted procedure lto_loremIpsum(): String;
   lto_sconcat(for each rpr on lto_loremIpsumAl() join
      {cdar rpr, if cdr rpr then " " else ""});

endmodule;  % [lto]

end;  % of file
