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

procedure lto_sconcat(l);
   % List tools string concatenation. [l] is a list of strings.
   % Returns a string. The returned string is the concatenation of all
   % strings in [l].
   if l then
      if cdr l then
 	 lto_sconcat2(car l,lto_sconcat cdr l)
      else
	 car l;

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

procedure lto_subsetq(s1, s2);
   not s1 or car s1 memq s2 and lto_subset(cdr s1, s2);

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

procedure lto_maxkl(kl);
   % Maximum of a kernel list. [kl] is a list of kernels. Returns the biggest
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

endmodule;  % [lto]

end;  % of file
