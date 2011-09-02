% ----------------------------------------------------------------------
% $Id: lto.red,v 1.7 2003/01/29 10:44:08 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: lto.red,v $
% Revision 1.7  2003/01/29 10:44:08  sturm
% Moved list2set and list2vector to lto.red.
%
% Revision 1.6  1999/03/24 12:29:57  dolzmann
% Added the procedure lto_max for computing the maximum of a list of
% integers.
%
% Revision 1.5  1999/03/22 15:26:15  dolzmann
% Changed copyright information.
% Added and reformatted comments.
%
% Revision 1.4  1997/11/05 06:35:10  dolzmann
% Added comments.
% Moved system dependent procedures to the end of the file.
% Updated copyright message.
% Replaced "written by" in the CVS header by the usual copyright message.
%
% Revision 1.3  1996/10/17 12:31:52  sturm
% Moved sconcat2, sconcat, and at2str from qepcad.red to lto.red.
%
% Revision 1.2  1996/09/05 11:17:36  dolzmann
% Added procedures delq, delqip, delqip1, and adjoin for non-PSL versions.
%
% Revision 1.1  1996/04/30 12:06:44  sturm
% Merged ioto, lto, and sfto into rltools.
%
% Revision 1.1  1996/03/22 12:11:09  sturm
% Moved.
%
% Revision 1.4  1996/02/18 13:52:15  sturm
% Added procedure lto_natsoc.
%
% Revision 1.3  1996/02/18 12:39:18  dolzmann
% Added procedure lto_cassoc.
%
% Revision 1.2  1995/06/21  07:35:47  sturm
% Added procedures lto_nconcn, lto_alunion, and lto_almerge.
%
% Revision 1.1  1995/05/29  14:47:19  sturm
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(lto_rcsid!* lto_copyright!*);
   lto_rcsid!* := "$Id: lto.red,v 1.7 2003/01/29 10:44:08 sturm Exp $";
   lto_copyright!* := "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module lto;
% List tools.

procedure lto_insert(x,l);
   % List tools insert. [x] is any S-expression, [l] is a list. Conses
   % [x] to [l] if [x] is not already member of [l].
   if x member l then l else x . l;

procedure lto_insertq(x,l);
   % List tools insert testing with memq. [x] is any S-expression, [l]
   % is a list. Conses [x] to [l] if [x] is not already [memq].
   if x memq l then l else x . l;

procedure lto_mergesort(l,sortp);
   % List tools merge sort. [l] is a list; [sortp] is a function that
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
      return nconc(lto_mergesort(s1,sortp),crit . lto_mergesort(s2,sortp))
   end;

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
   % List tools assoc list merge. [all] is a list of alists $((k1 .
   % e1) ... (kn . en))$, where all ki are unique and all ei are
   % lists; [merge] is a function that maps two lists to another list.
   % Merges all alists in [all] into one alist, where the keys are the
   % union of all ki appearing in the members of [all], and the entry
   % to each key is obtained from the entries in [all] by applying
   % [merge]. All members of [all] are modified by this function.
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

procedure lto_at2str(s);
   % List tools atom to string. [s] is an atom. Returns the print name
   % of the atom [s] as a string.
   compress('!" . reversip('!" . reversip explode s));

procedure lto_max(l);
   % List tools maximum of a list. [l] is a list of integers. Rerurns
   % the maximum of [l].
   if null cdr l then car l else max(car l,lto_max cdr l);

!#if (not (memq 'psl lispsystem!*))
   procedure delq(x,l);
      % Delete with memq. [x] is ANY; [l] is a list. Returns a list.
      % The first occurence of an element identical to [x] in [l] is
      % deleted.
      if l then if car l eq x then cdr l else car l . delq(x,cdr l);
!#endif

!#if (not (memq 'psl lispsystem!*))
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
!#endif

!#if (not (memq 'psl lispsystem!*))
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
!#endif

!#if (not (memq 'psl lispsystem!*))
   procedure adjoin(x,l);
      % Adjoin. [x] is any S-expression, [l] is a list. Conses [x] to
      % [l] if [x] is not already member of [l].
      if x member l then l else x . l;
!#endif

!#if (not (memq 'psl lispsystem!*))
   procedure list2set(l);
      % Remove redundant elements from L.
      if not pairp l then
 	 nil
      else if car l member cdr l then
 	 list2set cdr l
      else
 	 car l . list2set cdr l;
!#endif
      
!#if (not (memq 'psl lispsystem!*))
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
!#endif

endmodule;  % [lto]

end;  % of file
