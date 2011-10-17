module assist; % Header Module for REDUCE 3.5 and 3.6.

create!-package('(assist sl2psl switchxt baglist hcvctors genpurfn
                  control polyexns transfns vectorop grassman matrext
                  helpasst),
                '(contrib assist));  % helpasst

% % *****************************************************************
%
%                Author: H. Caprasse <caprasse@vm1.ulg.ac.be>.
%
% Version and Date:  Version 2.2, 15 February 1993.
%
% Revision history to versions 2.0 and 2.1 :
%
% 1 Mai 1993    : Correction to SPLITTERMS and RCONS
%               : New functions CYCLICPERMLIST, APPENDN,
%               : INSERT_KEEP_ORDER
%               : CHECKPROPLIST, EXTRACTLIST, SORTNUMLIST.
% 15 Mai 1993   : LIST_TO_IDS replaces MKIDN.
%               : SORTLIST generalises SORTNUMLIST to sort list of ids
%               : ALG_TO_SYMB  et SYMB_TO_ALG created.
%               : MERGE_LIST complementary funct. to INSERT_KEEP_ORDER
% 17 May 1993   : Creation of SYMMETRIZE
% 27 May 1993   : Various modifications and improvements,
% 12 June 1993  : Corrections to UNION, SYMB_TO_ALG and SYMMETRIZE
% 20 June 1993  : Addition of several functions
%               : in the module POLYEXNS.
%               : GCDNL, NORM_MON, NORM_POL, LIST_COEFF_POL
%               : Addition of PERM_TO_NUM and NUM_TO_PERM in module
%               : 'genpurfn'
% 25 June 1993  : Various modifications and corrections.
%               : Functions involved: DEPTH, ADDFD, REMVAR!: .
% 12 Dec. 1993  : Functions CONCSUMLOG and PLUSLOG eliminated.
%               : Function ALGSORT created. It will probably replace
%               : SORTLIST and SORTNUMLIST very soon.
%               : Module 'hcvectors' added. It provides functions to
%               : manipulate symbolic vector as list and for coercion
%               : of list to vector and vice-versa. Needed to run
%               : the package 'DUMMY.RED'.
%               : Module 'SL2PSL' added. By default it is entirely
%               : commented because all psl versions of REDUCE do not
%               : need it. For the other versions some of the included
%               : functions may be needed. It suffices to remove the
%               : comment characters where needed and recompile the
%               : package.
% 20 Dec. 1993  : Function ALGNLIST introduced. Module 'hcvectors'
%               : extended to allow to make coercions from lists
%               : to arrays.
%               : LIST_to_ARRAY, ARRAY_TO_LIST available.
%               : Function MKRANDTABL created.
% 21 Dec. 1993  : Module 'HELPASST' added.
% 21 Jan. 1994  : Corrections for a proper use of number|-of|-args.
%               : Corrections to EXTRACTLIST and LOWESTDEG
% 28 Jan. 1994  : Modification of LIST2VECT. Corrections to
%               : CLEARFUNCTIONS.
% ===============================================================

endmodule;


module sl2psl; % Definitions of functions in PSL but not SL.

% Some of these are already in the standard REDUCE now.

deflist('((fixp 1) (numberp 1) (floatp 1) (evenp 1) (oddp 1)
          (stringp 1) (idp 1) (ordp 2) (nordp 2) (equal 2)
                              (geq 2) (leq 2)),'number!-of!-args);

%symbolic procedure lastcar l;
% if atom l then l else
% if atom cdr l then car l else car lastpair cdr l;

symbolic procedure lconc(l1,l2);
% Both arguments are lists l1 is a list of the type
% ((a b c ... f) f)
% Useful for concatenating lists from right to left without copying.
% l1 may be nil to start with.
% REQUIRED FOR FUTURE RELEASE
 if null l1 then rplacd(list l2,lastpair l2) else
 if null car l1 then rplacd(rplaca(l1,l2),l2) else
 <<rplacd(cdr l1 ,l2); rplacd(l1, lastpair l2)>>;

symbolic procedure tconc(l,elm);
 <<elm:=cons(elm,nil);
   if null l then nconc(list elm,elm) else
   if null car l then  rplacd(rplaca(l,elm),elm) else
    <<rplacd(cdr l,elm);rplacd(l,elm)>>
 >>;

symbolic procedure adjoin(elm,st);
 % elm is any object, st is a set.
 if member(elm,st) then st else cons(elm,st);

symbolic procedure list2set u;
% Eliminates redundant elements .
% Replaces !:mkset u of the old ASSIST package.
 if null u then nil else if member(car u,cdr u) then list2set cdr u
 else car u . list2set cdr u;

symbolic procedure delqip1(elm,l);
 if not atom cdr l then
   if elm eq cadr l then rplacd(l,cddr l) else
    delqip1(elm,cdr l);

symbolic procedure delqip(elm,l);
 % Deletes elm from l without copying l.
 % This is the good definition given by Arthur Norman.
 if atom l then l else
 if elm eq car l then cdr l else
        <<delqip1(elm,l);l>>;

endmodule;


module switchxt;

fluid '(!*distribute);

switch distribute;

flag('(!*factor !*mcd !*div !*exp !*gcd !*rat !*rational !*rationalize
        !*intstr !*reduced !*ratpri !*revpri !*distribute
        !*ezgcd !*complex !*reduced !*lcm !*precise),'share)$

endmodule;


module baglist$

global('(!:flaglis !:proplis));

% 1. Functions which works on LIST_like objects.

algebraic procedure frequency lst;
% gives a LIST of PAIRS  {{el1,freq1} ...{eln,freqn}}.
% Procedure created by E. Schruefer.
   <<clear count!?!?; operator count!?!?; frequency1 lst>>;

algebraic procedure frequency1 lst;
if lst = {} then {}
else begin scalar r,el;
      el := first lst;
      if numberp count!?!? el
      then <<count!?!? el := count!?!? el + 1; r:=frequency1 rest lst>>
       else r :=
        {el,count!?!? el} . <<count!?!? el := 1; frequency1 rest lst>>;
        return r
       end;

symbolic procedure sequences n;
% Works properly, both in the symbolic and in the algebraic mode.
if !*mode eq 'symbolic then sequsymb n else
algebraic sequalg n;

flag('(sequences),'opfn);

symbolic procedure sequsymb n;
% Corresponds to the one below in the symbolic mode.
if n=1 then list(list(0),list(1))
 else for each s in sequsymb (n-1) conc list(0 . s,1 . s);

algebraic procedure sequalg n;
% Gives the list  {{0,0 ...,0},{0,0, ..., 1}, ...{1,1, ..., 1}}
% "conc" used in an explicit way.
   if n = 1 then {{0},{1}}
    else for each s in sequalg(n - 1) conc {0 . s,1 . s};

algebraic procedure split(u,v);
% split(list(a,b,c),list(1,1,1)); ==> {{A},{B},{C}}
% split(bag(a,b,c,d),list(1,1,2)); ==> {{A},{B},{C,D}}
% etc.
if baglistp u and baglistp v then
 begin scalar x;
    return for each n in v collect
             for i := 1:n collect
                 <<x := u.1; u := rest u; x>>
    end
 else lisp rederr(list(u,v,": must be lists or bags"));

symbolic procedure extremum(l,fn);
% Gives the extremum of elements in list l with respect
% to an ordering function fn. It may be ORDP etc ..
if atom l then l else
(if null x then nil else
 maximum3(x ,cadr l,fn))where x=cdr l;

flag('(extremum),'opfn);

symbolic procedure maximum3(l,m,fn);
if null l then m else
if apply2(fn,car l,m) then maximum3(cdr l,car l,fn) else
 maximum3(cdr l, m,fn);

symbolic procedure rmklis u$
begin scalar s,ss;integer n;
if length u = 2  then
<<s:=reval car u; n:=reval cadr u;
if car s eq 'list then
  ss:=append(s,cdr rmklis(list(n+1-length s))) else nil>> else
if length u=1 then
 <<n:=reval car u; for j:=1:n do s:=0 . s; ss:='list . s>>
else nil;
return ss end;

put('mklist,'psopfn,'rmklis);

symbolic procedure algnlist(u,n);
% Puts n copies of the list or bag u  in a list .
symb_to_alg nlist(alg_to_symb u,n);

flag('(algnlist),'opfn);

symbolic procedure insert_keep_order(u,l,fn);
% The message for the number of args works only if number!-of!-args
% is used.
(if x and x=1  or atom l then
typerr(list(l,fn),"list and binary function")
else 'list . insert_keep_order1(u,cdr l,fn)) where
                                          x=get(fn,'number!-of!-args);

flag('(insert_keep_order),'opfn);

symbolic procedure insert_keep_order1(u,l,fn);
% u is any object, l is a list and fn is a BINARY boolean function.
if null l then list u else
if apply(fn,list(u,car l)) then u . l else
car l . insert_keep_order1(u,cdr l,fn);

symbolic procedure merge_list(l1,l2,fn);
% fn is a binary boolean function
'list . merge_list1(cdr l1,cdr l2,fn);

flag('(merge_list),'opfn);

symbolic procedure merge_list1(l1,l2,fn);
% Returns the (physical) merge of the two sorted lists l1 and l2.
% Example of use :
% l1:=list(1,2,3)$ l2:=list(1,4,5)$
% merge(l1,l2,'lessp); ==> (1 1 2 3 4 5)
% l1 and l2 are destroyed
% This is complementary to the function INSERT_KEEP_ORDER
  if null l1 then l2
  else if null l2 then l1
  else if apply2(fn,car l1,car l2) then
                               rplacd(l1,merge_list1(cdr l1,l2,fn))
  else rplacd(l2,merge_list1(l1,cdr l2,fn));

% 2. Introduction of BAG-like objects.

put('bag,'simpfn,'simpiden);

flag('(bag),'bag)$  % the default bag
flag('(bag),'reserved)$

symbolic (!:flaglis:=union(list list('bag,'bag),!:flaglis))$

symbolic procedure !:delete(u,prop,val)$
if prop then
for each x in !:proplis do if x=list(u,prop,val)
              then !:proplis:=delete(x,!:proplis) else nil else
for each x in !:flaglis do if x=list(u,val)
              then !:flaglis:=delete(x,!:flaglis);

symbolic procedure !:bagno u; u eq 'list or flagp(u,'boolean);

symbolic procedure !:bagyes u; getd u or
                  gettype u member list('tvector,'vector) or
                  flagp( u,'opfn) or
                  get(u,'simpfn) or get(u,'psopfn) or
                  get(u,'fdegree) or get(u,'ifdegree);

symbolic procedure simpbagprop u$
% gives the bag property to ident. or baglike-list of identifiers U
% V is T if one creates the property or 0 if one destroys it.
% Use is bagprop(<list of atoms>,T or 0)
% Makes tests to avoid giving this property to an unsuitable object.
   begin scalar id,bool;
   id:= car u; bool:= if  cadr u eq t then t;
   if listp id then
    << for each x in id do simpbagprop list(x,bool) $
     return bool>> else
   if  idp id and bool=t then
         if !:bagno id then typerr (id,"BAG") else
         if !:bagyes id then <<flag(list id,'bag),go to l1>> else
         <<put(id,'simpfn,'simpiden)$ flag(list id,'bag)$ go to l1>>
   else
   if  idp id and not bool  then
   <<remflag(list id,'bag); go to l1>>
   else  rederr("BAD ARGUMENT for bagprop");
l1: if bool then !:flaglis:=union(list list(id,'bag),!:flaglis)
      else !:delete(id,nil,'bag) end;

symbolic procedure putbag u; simpbagprop list(u,t);
% gives the bag property to ident. or baglike-list of identifiers u
% V is T to create the bag property.

symbolic procedure clearbag u; simpbagprop list(u,0);
% destroys the bag property of the identifier or the baglike-list u

symbolic rlistat '(putbag clearbag);

symbolic procedure bagp(u)$
% test of the baglike property of U$
not atom u and flagp(car u ,'bag)$

flag('(bagp),'boolean);

symbolic procedure nbglp(u,n)$
%Function which determines if U is not a bag at the level N.
% Used in DEPTH.
if n=0 then not baglistp u else
if atom u or not bglp!:!: car u  then nil else
begin scalar uu$ uu:= u$
 l1:  uu:=cdr uu$
    if null uu then return t$
    if nbglp(car uu,n-1) then  go to l1 else
          return nil end$

symbolic procedure bglp!:!: u;
if not atom u then bglp!:!: car u else
     if (flagp(u,'bag) or u eq 'list) then t else nil;

symbolic procedure baglistp u;
% This function is supposed to act on a prefix simplified expression.
not atom u and ( car u eq 'list  or flagp(car u,'bag));

symbolic procedure nul!: u; baglistp u and null cdr u;

symbolic flag('(baglistp nul!:),'boolean);

symbolic procedure alistp u$
% Not for use in algebraic mode.
if null u then t else
(not atom car u) and alistp cdr u;

symbolic procedure abaglistp u;
% For use in algebraic mode. Recognizes when a bag-like object
% contains bags which themselves contain two and only two objects.
if null baglistp u or null baglistp cadr u then nil else
     begin;
l1:  u:=cdr u;
    if null u then return t ;
     if length car u <3 then return nil else go to l1 end;

         flag('(abaglistp),'boolean);

% Definitions of operations on lists

symbolic procedure rexplis u;
% THIS PROCEDURE GENERALIZES BAGLIST TO ANY OBJECT AND GIVES A LIST OF
% THE ARGUMENTS OF U.
if atom ( u:=reval car u) then nil else
% if kernp mksq(u,1) then 'list . cdr u ;
if kernp mksq(u,1) then
  'list . for each i in cdr u collect mk!*sq simp!* i ;

%symbolic procedure rexplis u;
% THIS PROCEDURE GENERALIZES BAGLIST TO ANY OBJECT AND GIVES A LIST OF
% THE ARGUMENTS OF U.
%if atom ( u:=reval car u) then nil else
%if kernp mksq(u,1) then 'list . cdr u ;

put('kernlist,'psopfn,'rexplis);

symbolic procedure rlisbag u$
begin scalar x,prf;
x:=reval car u; prf :=reval cadr u;
if atom x then return nil else
<<simpbagprop list(prf,t) ; x:=prf . cdr x>>;
return x end;

symbolic put('listbag,'psopfn,'rlisbag);

symbolic procedure rfirst li;
  if bagp( li:=reval car li) then
  if null cdr li then car li . nil else  car li . cadr li . nil else
  if car li neq 'list then typerr(li,"list or bag")
  else if null cdr li then parterr(li,1)
  else cadr li;

put('first,'psopfn,'rfirst);

symbolic procedure rsecond li;
 if bagp( li:=reval car li) then
      if null cdr li or null cddr li then  car li . nil
      else  car li . caddr li . nil
  else if car li neq 'list then typerr(li,"list or bag")
  else if null cdr li or null cddr li then parterr(li,2)
  else caddr li;

put('second,'psopfn,'rsecond);

symbolic procedure rthird li;
  if bagp( li:=reval car li) then
    if null cdr li  or null cddr li or null cdddr li
       then car li . nil else  car li . cadddr li . nil
    else if car li neq 'list then typerr(li,"list or bag")
  else if null cdr li or null cddr li or null cdddr li
    then parterr(li,3)
    else cadddr li;

symbolic procedure rrest li;
if bagp( li:=reval car li) then
  if null cdr li then li . nil else  car li . cddr li  else
if car li neq 'list then typerr(li,"list or bag")
else 'list . if null (li:=cdr li) then li else cdr li;

symbolic put('rest,'psopfn,'rrest);

symbolic procedure rreverse u;
<<u:=reval car u;
if bagp u then car u . reverse cdr u
else if car u neq 'list  then typerr(u,"list or bag")
else 'list . reverse cdr u>>;

symbolic  put('reverse,'psopfn,'rreverse);

symbolic procedure rlast u;
<<u:=reval car u;
if bagp u then if null cdr u then u else
    car u . lastcar cdr u . nil
 else if car u neq 'list  then typerr(u,"list or bag")
 else  if null cdr u then nil
 else lastcar cdr u>>;

%symbolic procedure rlast u;
%<<u:=reval car u;
%if bagp u then if null cdr u then u else
%    car u . car reverse cdr u . nil
% else if car u neq 'list  then typerr(u,"list or bag")
% else  if null cdr u then nil
% else car  reverse cdr u>>;

symbolic put('last,'psopfn,'rlast);

%symbolic procedure rdc u;
%if null cdr u then nil else car u . rdc cdr u;

smacro procedure be_last u;
delete(lastcar u, u);

symbolic procedure rbelast u;
<<u:=reval car u;
 if baglistp u then car u . be_last cdr u
 else typerr(u,"list or bag") >>;

%symbolic procedure rbelast u;
%<<u:=reval car u;
%if bagp u then if null cdr u then u else car u . rdc cdr u
%else if car u neq 'list then typerr(u,"list or bag")
%else if null cdr u then u else 'list . rdc cdr u>>;

put('belast,'psopfn,'rbelast);

symbolic procedure rappend u;
   begin scalar x,y;
    if length u neq 2 then rederr("append has TWO arguments");
       x:=reval car u;
       y:=reval cadr u;
    if baglistp x and baglistp y  then
                      return car x . append(cdr x,cdr y)
    else typerr(list(x,y),"list or bag")
   end ;

put('append,'psopfn,'rappend);

symbolic procedure rappendn u;
% This append function works for any number of arguments and all
% types of kernels.
   begin scalar x,y;
      x:= revlis u;
      y:=for each i in x collect mkquote if atom i then
         rederr("arguments must be kernels or lists") else cdr i;
      x:=  eval expand(y,'append);
      return 'list .  x
end ;

put('appendn,'psopfn,'rappendn);

symbolic procedure rcons u;
% Dans ASSIST.RED
% This procedure does not work perfectly well when the package
% HEPHYS is entered because ISIMPA is applied by reval1 on the
% result of RCONS. When it is given by (BAG (LIST A B) C D) it gives
% the output BAG({A,B}) erasing C and D ! It is due to the fact that
% ISIMP1 and ISIMP2 do not accept SQ forms for identifiers.
% So avoid inputs like list(a,b).bag(c,d) when HEPHYS is loaded.
 begin scalar x,y,z;
%      if (y := getrtypeor(x := revlis u)) eq 'hvector


%        then return if get('cons,'opmtch) and (z:=opmtch('cons . x))
%                      then reval z
%                    else prepsq simpdot x
      if (y := getrtypeor(x := revlis u)) eq 'hvector
    then return if get('cons,'opmtch) and (z := opmtch('cons . x))
                   then reval z
                 else prepsq subs2 simpdot x
      else if getrtype(y:=cadr x) eq 'list
             then return  'list . car x . cdadr x
      else if bagp y
             then return   z:=car y . car x . cdr y
       else if fixp y
   then return z:= if get('rcons,'cleanupfn) then 'bag . revalpart u
                                else revalpart u
       else typerr(x,"list or bag")
   end;

symbolic procedure isimpa(u,v);
   if eqcar(u,'list) then u else
   if eqcar(u,'bag) then cdr u else !*q2a1(isimpq simp u,v);

flag('(isimpa),'lose);

symbolic put('cons,'setqfn,'(lambda (u v w) (setpart!* u v w)));

symbolic put('cons,'psopfn,'rcons);

symbolic procedure lengthreval u;
   begin scalar v,w;
      if length u neq 1
        then rederr "LENGTH called with wrong number of arguments"
       else if idp car u and arrayp car u
        then return 'list . get(car u,'dimension)
       else if bagp (u:=reval car u)
        then return  length cdr u;
      v := aeval u;
      if (w := getrtype v) and (w := get(w,'lengthfn))
        then return apply1(w,v)
       else if atom v then return 1
       else if not idp car v or not(w := get(car v,'lengthfn))
        then typerr(u,"length argument")
       else return apply1(w,cdr v)
   end;

symbolic put('length,'psopfn,'lengthreval);
symbolic put('size,'psopfn,'lengthreval);

symbolic procedure rremove u;
% Allows one to remove the element n of bag u.
% First argument is a bag or list, second is an integer.
 if length u neq 2 then
       rederr("remove called with wrong number of arguments") else
begin scalar x;integer n;
x:=reval car u; n:=reval cadr u;
if baglistp x  then return car x . remove(cdr x,n) else
rederr(" first argument is a list or a bag, second is an integer")
 end;

symbolic put('remove,'psopfn,'rremove);

symbolic procedure rdelete u;
begin scalar x,y;
x:=reval car u; y:=reval cadr u;
if baglistp y then return delete(x,y) end;

symbolic put('delete,'psopfn,'rdelete);

% Use is delete(<any>,<bag or list>)

symbolic procedure delete_all(ob,u);
'list . del_all_obj(ob,cdr u);

flag('(delete_all),'opfn);

symbolic procedure del_all_obj(ob,u);
% Deletes from list u ALL objects ob
if null u then nil else
if car u = ob then del_all_obj(ob,cdr u) else
  car u . del_all_obj(ob,cdr u);

symbolic procedure rmember u;
% First argument is anything, second argument is a bag or list.
begin scalar x,y$
  x:=reval car u;
  y:=reval cadr u;
 if baglistp y then
              if (x:=member(x,cdr y))
              then return car y . x else return nil
else typerr(y,"list or bag") end;

symbolic put('member,'psopfn,'rmember);

% INPUT MUST BE " member (any , < bag OR list> ) ".

symbolic procedure relmult u;
if length u neq 2 then
      rederr("elmult called with wrong number of arguments") else
begin scalar x,y; integer n;
   x:=reval car u;  % It is the object the multiplicity of which one
                  % wants to compute.
   y:=reval cadr u; % IT IS THE list OR bag
 if x=y then return 1 else
 if baglistp y then
            <<y:=cdr y;
             while not null (y:=member(x,y)) do <<y:=cdr y;n:=n+1>>>>
         else typerr(y,"list or bag");
 return n end;

symbolic put('elmult,'psopfn,'relmult);

% Use is  " elmult (any , < bag OR list> ) " .

symbolic procedure rpair u$
begin scalar x,y,prf$
 if length u neq 2 then
      rederr("pair called with wrong number of arguments");
 x:=reval car u; y:=reval cadr u$
 if not (baglistp x and baglistp y) then
                  rederr("arguments must be lists or bags") else
 prf:=car x;x:=cdr x; y:=cdr y;
 y:=pair(x,for each j in y collect list j);
 return y:=prf . for each j in y collect prf . j  end;

symbolic put('pair,'psopfn,'rpair);

symbolic procedure delpair(elt,u);
'list .
  for each j in  delasc(elt,for each i  in cdr u collect cdr i)
                                                  collect 'list . j ;

flag('(delpair),'opfn);

symbolic procedure depth!: u;
   if not atom u and (car u eq 'list or flagp(car u,'bag))
      then 1 + (if cdr u then depth!: cadr u else 0)
    else 0;

symbolic procedure rdepth(u)$
% Use is depth(<BAG or LIST>).
begin scalar x; integer n;
 x := reval car u;
 if nbglp(x,n:=depth!: x) then
     return n else return "bag or list of unequal depths" end;

put('depth,'psopfn,'rdepth);

symbolic procedure rinsert u;
% Use is insert(<any>, <list or bag>, <integer>).
begin scalar x,bg,bbg,prf; integer n;
   bg:=reval cadr u; n:=reval caddr u;
 if not baglistp bg then typerr(bg,"list or bag") else
 if n<=0 then rederr("third argument must be positive an integer") else
 if (n:=n+1) > length bg then return append(bg,x:=list reval car u);
   prf:=car bg; x:=reval car u;
   for i:=3:n do <<bg:=cdr bg; bbg:=car bg . bbg>>;
   bbg:=reverse bbg;
  return bbg:=prf . append(bbg,cons(x,cdr bg))
 end;

symbolic put('insert,'psopfn,'rinsert);

% Use is : insert(<any>, <list or bag>, <integer>).

symbolic procedure rposition u$
% Use is position(<any>,<LIST or BAG>).
begin scalar el,bg; integer n;
el:=reval car u;
if not baglistp (bg:=reval cadr u) then typerr(bg," list or bag");
n:=length( bg:=cdr bg);
if (bg:=member(el,bg))
             then return (n:=n+1-length bg)  else
 msgpri(nil,el,"is not present in list or bag",nil,nil) end;

put('position,'psopfn,'rposition);

% **********

% The functions below, when applied to objects containing SEVERAL bag
% prefixes have a rule to select them in the output object when this
% one is itself a bag: the first level prefix has priority over all
% other prefixes and will be selected, when needed, as the envelope
% of the output.

symbolic procedure !:assoc u;
if length u neq 2 then
      rederr("asfirst called with wrong number of arguments") else
 begin scalar x,y,prf;
  x:=reval car u; y:=reval cadr u;
 if null baglistp y then typerr(y,"list or bag");
  prf:=car y; y:=cdr y;
 if null alistp y then typerr(y, "association list") else
      y:=for each j in y collect cdr j;
 return  if null (y:=assoc(x,y)) then nil else prf . y   end;

symbolic put('asfirst,'psopfn,'!:assoc);

% Use is : asfirst(<key>,<a-list> | <a-bag>)

symbolic procedure !:rassoc u;
if length u neq 2 then
      rederr("assecond called with wrong number of arguments") else
begin scalar x,y,prf;
 x:=reval car u; y:=reval cadr u;
 if null baglistp y then typerr(y,"list or bag");
  prf:=car y; y:=cdr y;
 if null alistp y then typerr(y, "association list") else
     y:=for each j in y collect cdr j;
 return  if null (y:=rassoc(list x,y)) then nil else prf . y   end;

symbolic put('assecond,'psopfn,'!:rassoc);

% Use is : assecond(<key>,<a-list>|<a-bag>)

symbolic procedure !:assoc2 u;
if length u neq 2 then
      rederr("asrest called with wrong number of arguments") else
begin scalar x,y,prf;
  x:=reval car u; y:=reval cadr u;
 if null baglistp x or null baglistp y then
   typerr(list(x,y),"list or bag");
  prf:=car y; y:=cdr y; x:=cdr x;
 if null alistp y then typerr(y, "association list") else
     y:=for each j in y collect cdr j;
 return  if null (y:=assoc2(x,y)) then nil else prf . y   end;

symbolic put('asrest,'psopfn,'!:assoc2);

% Use is : asrest(<key>,<a-list>|<a-bag>)

symbolic procedure lastassoc!*(u,v);
% Use is :
% aslast(<key as a last element>,<a-list>|<a-bag>)
% Finds the sublist in which u is the last element in the
% compound list  or bag v, or nil if it is not found.
   if null v then nil
    else begin scalar vv; vv:=car v;
          while length vv > 1  do vv:=cdr vv;
          if u = car vv then return car v
    else return lastassoc!*(u,cdr v) end;

symbolic procedure !:lassoc u;
if length u neq 2 then
      rederr("aslast called with wrong number of arguments") else
begin scalar x,y,prf;
  x:=reval car u; y:=reval cadr u;
 if null baglistp y then typerr(y,"list or bag");
  prf:=car y; y:=cdr y;
 if null alistp y then typerr(y, "association list") else
      y:=for each j in y collect cdr j;
 return  if null (y:=lastassoc!*(x,y)) then nil else prf . y   end;

symbolic put('aslast,'psopfn,'!:lassoc);

symbolic procedure rasflist u;
% Use is :
% asflist(<key as a first element>,<a-list>|<a-bag>)
% This procedure gives the LIST (or BAG) associated with the KEY con-
% tained in the first argument. The KEY is here the FIRST element
% of each sublist contained in the association list .
if length u neq 2 then
      rederr("ASFLIST called with wrong number of arguments") else
begin scalar x,y,prf,res,aa;
 x:=reval car u; y:=reval cadr u; prf:=car y;
 if null cdr y then return y;
 for each j in cdr y do if car j neq prf then
 rederr list("prefix INSIDE the list or bag neq to",prf);
  l1: aa:=!:assoc(list(x,y));
     if not aa then return prf . reverse res;
     res:=aa . res;
     y:=delete(aa,y);
     go to l1;
                end$

symbolic put('asflist,'psopfn,'rasflist);

symbolic procedure rasslist u;
% Use is :
% asslist(<key as the second element>,<a-list>|<a-bag>)
if length u neq 2 then
      rederr("ASSLIST called with wrong number of arguments") else
begin scalar x,y,prf,res,aa;
 x:=reval car u; y:=reval cadr u; prf:=car y;
 if null cdr y then return y;
 for each j in cdr y do if car j neq prf then
 rederr list("prefix INSIDE the list or bag neq to",prf);
  l1: aa:=!:rassoc(list(x,y));
     if not aa then return prf . reverse res;
     res:=aa . res;
     y:=delete(aa,y);
     go to l1;
                end$

symbolic put('asslist,'psopfn,'rasslist);

symbolic procedure !:sublis u;
% Use is :
% restaslist(<bag-like object containing keys>,<a-list>|<a-bag>)
% Output is a list containing the values associated to the selected
% keys.
if length u neq 2 then
    rederr("restaslist called with wrong number of arguments") else
begin scalar x,y,yy,prf;
  x:=reval car u;
  y:=reval cadr u; prf:=car y;
 if null baglistp y then typerr(y,"list or bag") else
 if null alistp (y:=cdr y) then typerr(y," association list or bag")
 else  y:=for each j in y collect cdr j;
 if baglistp x then <<x:=cdr x; x:=for each j in x collect
                                            if  assoc(j,y) then j>>;
  y:=sublis(y,x); if atom y then yy:=list y else
  for each j in y do if not null j then yy:=j . yy;
  yy:=reverse yy;
  return  prf . for each j in yy collect
                     if atom j then prf . j . nil else prf . j$
        end$

symbolic put('restaslist,'psopfn,'!:sublis);

% Use is :
% restaslist(<bag-like object containing keys>,<a-list>|<a-bag>)
% Output is a list containing the values associated to the selected
% keys.
% ******* End of functions which may change bag- or list- prefixes.

% FOR SUBSTITUTION OF IDENTIFIERS IT IS CONVENIENT TO USE :

symbolic procedure !:subst u;
 reval subst(reval car u,reval cadr u,reval caddr u);

symbolic put('substitute,'psopfn,'!:subst);

% Use is : substitute(<newid>,<oldid>,<in any>).
% May serve to transform ALL bags into lists or vice-versa.

symbolic procedure !:repla u;
if length u neq 2 then
      rederr("repfirst called with wrong number of arguments") else
begin scalar x,y,prf;
  y:=reval car u; x:= reval cadr u;
 if null baglistp x then typerr(x,"list or bag");
  prf:= car x; x:=cdr x;
  return prf . rplaca(x,y) end;

symbolic put('repfirst,'psopfn,'!:repla);

% Use is : repfirst(<any>, <bag or list>);

symbolic procedure !:repld u;
% Use is : replast(<any>, <bag or list>);
begin scalar x,y,prf;
 if length u neq 2 then
       rederr("replast called with wrong number of arguments");
  y:=reval car u; x:= reval cadr u;
 if null baglistp x then typerr(u,"list or bag");
  prf:= car x; x:=cdr x;
  return prf . rplacd(x,list y) end;

symbolic put('represt,'psopfn,'!:repld);


% HERE ARE FUNCTIONS FOR SETS.

symbolic procedure !:union u$
begin scalar x,y,prf;
 if length u neq 2 then
       rederr("union called with wrong number of arguments");
  x:=reval car u; y:=reval cadr u;
 if not setp y then rederr "second argument to UNION must be a set";
 if baglistp x and baglistp y then
 <<prf:=car y; y:=prf . union(cdr x,cdr y)>> else return nil;
  return y end;

symbolic put('union,'psopfn,'!:union);

symbolic procedure setp u;
null repeats u;

symbolic flag('(setp),'boolean);

%symbolic procedure !:mkset u$
%if null u then nil else if member(car u,cdr u) then !:mkset cdr u
%else car u . !:mkset cdr u$

symbolic procedure rmkset u;
begin scalar x,prf$
  x:=reval car u; prf:=car x;
 if baglistp x then return prf . list2set cdr x
end;

%symbolic procedure rmkset u;
%begin scalar x,prf$
%  x:=reval car u; prf:=car x;
% if baglistp x then return prf . !:mkset cdr x end;

symbolic put('mkset,'psopfn,'rmkset);

symbolic procedure !:setdiff u$
begin scalar x,y,prf;
 if length u neq 2 then
       rederr("diffset called with wrong number of arguments");
  x:=reval car u; y:=reval cadr u;
 if baglistp x and baglistp y then
    <<prf:=car y; y:=prf . setdiff(cdr x,cdr y)>> else return nil;
 return y end;

symbolic put('diffset,'psopfn,'!:setdiff);

symbolic procedure !:symdiff u$
begin scalar x,y,prf;
 if length u neq 2 then
       rederr("symdiff called with wrong number of arguments");
  x:=reval car u; y:=reval cadr u; prf:=car x;
 if setp x and setp y then return
    prf . append(setdiff(x:=cdr x,y:=cdr y),setdiff(y,x))
 end;

symbolic put('symdiff,'psopfn,'!:symdiff);

symbolic procedure !:xn u$
begin scalar x,y,prf;
  if length u neq 2 then
      rederr("intersect called with wrong number of arguments");
    x:=reval car u; y:=reval cadr u;
  if setp x and setp y then return car x . intersection(cdr x,cdr y)
 end;

symbolic put('intersect,'psopfn,'!:xn);

endmodule;


module hcvctors;

symbolic smacro procedure mkve n;
mkvect(n-1);

symbolic smacro procedure mkve!* n;
% n is an integer
% as mkvect but initialize to 0 instead of nil.
% for general tables, use mkarray1(list(i1,...),'algebraic).
mkarray1(list(n),'algebraic);
symbolic smacro procedure putve(ve,i,elt);
% To identify numerology to the one of lists.
% Use: for i:=1:upbve tri  do putve(tri,i,i); ==> [1 2 3 4]
putv(ve,i-1,elt);

symbolic smacro procedure  venth(u,i);
% To identify numerology to the one of lists.
getv(u,i-1);

symbolic smacro procedure array_to_vect u;
% For the use in the algebraic mode, it may be usefull to coerce to
% ARRAYS and vice-versa
% Use: array_to_vect algebraic <array>
  cadr get(u,'avalue);

symbolic procedure mkrandtabl(u,base,ar);
% u is a list of 2 integers which determine the dimensions of the array
% base is integer  or decimal.
% Output is a table of random numbers
if not fixp base and not !*rounded then
                              rederr("ROUNDED should be on") else
begin scalar ve; integer lu;
 lu:=length(u:=alg_to_symb u);
 % if lu > 2 then typerr(u,"one or two integer list");
 ve:=mkarray1(u,'algebraic);
  if lu=1 then
    for i:=1:car u do
       putve(ve,i, if not fixp base then
         mk!*sq((make!:rd random(cdr base)) . 1)
                              else random(base)) else
  if lu=2 then <<
                  for i:=1:car u do putve(ve,i,mkve!* cadr u);
                  for i:=1:car u do for j:=1:cadr u do
                         putve(venth(ve,i),j, if not fixp base then
                               mk!*sq((make!:rd random(cdr base)) . 1)
                                               else random(base))>>
  else return typerr(u,"one or two integer list");
  vect_to_array(list(ve,ar),u);
  return symb_to_alg lengthreval list ar
end;

flag('(mkrandtabl),'opfn);

symbolic procedure upbve u;
% Should be used in FOR ... DO loops.
if null upbv u then 0 else upbv u +1;

% ILLUSTRATION of use of the above macros and function.
%for i:=1:upbve tri do
%        for j:=1:upbve venth(tri,i) do
%               putve(venth(tri,i),j,i*j);

symbolic procedure dimvect u;
% u is a vector or vector of vector or ..
% Gives the dimension of each level.
% Valid only for rectangular patterns.
% May also be used for Young tableaux to get the dimensions of the
% FIRST row and COLUMNS.
if null u then nil else
  (upbv u + 1) . dimvect ((if not vectorp x then nil
  else x) where x=getv(u,0));

 symbolic procedure index_elt(elt,u);
 % elt is an atom or a number
 % return the position index.
 begin scalar idx; integer ii;
  ii:=1;
  repeat   <<if elt = venth(u,ii) then idx:=ii else nil; ii:=ii+1;>>
  until not null idx or ii=upbve u + 1;
  return idx
 end;

 symbolic procedure vect2list u;
 % Coerce a vector into a list at any level. Suitable for the
 % symbolic mode.
 for i := 0 : upbv u collect
 (if null upbv x then x
       else vect2list x) where x= getv(u,i);

%symbolic procedure vectlist u;
 % Suitable for the algebraic mode.
 % Use: vectlist symbolic <defined vector>
% 'list . vect2list1 u;

%  flag('(vectlist),'opfn);

symbolic procedure list_str u;
% generates the list of dimensions for the array construction.
%if not listp u  then
%          rederr "Argument to 'list_str' must be a list"
% it is supposed  to pass the test of homo_lst.
 if not listp car u  then length u  . nil
  else length u  . list_str car u;

symbolic procedure n_first_lst(u,n);
if n=0 then nil else
car u  . n_first_lst(cdr u,n-1);

symbolic procedure homo_lst(u,n);
% n indicates the level of homogeneity.
% u is the list.
% It should be filtered by depth which gives n+1 and
% generated by alg_to_symb <algebraic list>
if not listp u then
  rederr " Argument to 'homo_lst' has not the correct dimension"
else
  if n=0 then  1 else
   begin integer nl;
         scalar su;
   su:=u; nl:=length car su;
  % It is supposed here that car su is also a list.
   su:=cdr su ;
   if null su then 1;
   while su and nl= length car su do su:=cdr su;
   if null su then return
     for each i in u product homo_lst(i,n-1)
   else return 0
end;

%  symbolic procedure vect2list1 u;
 % Coerce a vector into a list at any level. Suitable for the
 % algebraic mode.
% for i := 0 : upbv u collect
% (if null upbv x then
%      if atom x then x
%       else 'list . x
%    else vect2list1 x) where x= getv(u,i);

symbolic procedure list_to_array(u,n,arr);
% Suitable for the algebraic mode.
% Defines n-dimensional arrays.
begin scalar lu;
lu:=alg_to_symb u;
<<vect_to_array(list(list2vectn(lu,n), arr),
   n_first_lst(list_str lu,n));
   remflag(list arr,'used!*)>>;
end;

flag('(list_to_array,array_to_list),'opfn);

symbolic procedure array_to_list u;
% Transforms an array into a list.
% Suitable for the algebraic mode.
% Works at all levels.
symb_to_alg vect2list array_to_vect u;

symbolic procedure list2vectn(u,n);
if n=1 then list2vect u else
begin scalar ll,x;
 if homo_lst(u,n-1)=1 then ll:=list_str u else
 rerror(alg,1,list(n,"Too large to coerce to an array"));
 x:=mkvect (first ll -1); ll:=cdr ll;
 for i:=1: upbv x +1 do putve(x,i,list2vectn(nth(u,i),n-1));
 return x
end;

symbolic procedure list2vect u; list2vect!*(u,'algebraic);

symbolic procedure list2vect!*(u,v); % should replace list2vect
% Coerce a list into a vector
% v may be either SYMBOLIC or ALGEBRAIC
  begin scalar x;
      x:=mkvect(length u -1);
         for i:=1:upbv x +1 do putve(x,i,
            if v = 'algebraic then symb_to_alg nth(u,i) else nth(u,i));
  return x end;

symbolic procedure vect_to_array(u,dim);
% u is a list (vector, array_id)
<< typechk(cadr u,'array);put(cadr u,'rtype,'array);
   put(cadr u ,'avalue,list('array, car u));
      put(cadr u,'dimension, dim)>>;

symbolic procedure vectappend(v1,v2);
 if not vectorp v1 then typerr(v1,"vector") else
 if not vectorp v2 then vectappend1(v1,v2) else
  begin scalar new;integer dim;
    new:=mkvect(upbv v1 + upbv v2 +1 );
    dim:=upbv v1 + 1;
    for i:=1:dim do putve(new,i,venth(v1,i));
    for i:=(dim+1):(upbv new + 1) do putve(new,i,venth(v2,i-dim));
   return new
end;

symbolic procedure vectappend1(v1,v2);
   begin scalar new; integer dim;
      new:=mkvect(dim:=upbv v1 +1);
      for i:=1:dim do putve(new,i,venth(v1,i));
      putve(new,dim+1,v2);
  return new end;

symbolic procedure vectadd(v1,v2);
  % v1 and v2 are supposed to be two numeric vectors.
  % So we use PLUS and not SIMPPLUS.
 if not vectorp v1 or not vectorp v2 then
                                rederr("arguments must be vectors")
  else
    begin scalar vadd;
     vadd:=mkvect upbv v1;
     for i:=1:upbve v1 do putve(vadd,i, venth(v1,i)+venth(v2,i));
     return vadd
    end;

 symbolic procedure setelve(ve,l,val);
 % Sets any elements of ve, at any level to val.
 % USE:
 % for i:=1:upbve tri do
 %        for j:=1:upbve venth(tri,i) do
 %               setelve(tri,list(i,j),i+j);
  if null l then nil else
  if null cdr l then putve(ve,car l, val) else
  setelve(venth(ve,car l),cdr l,val);

 symbolic procedure ltrident n;
 % Construct a lower triangular matrix of unit vectors
   begin scalar a;
    a:=mkve!* n;
    for i:=1:n do
    << putve(a,i,mkve!* i);
         for j:=1:i-1 do putve(venth(a,i), j, 0);
        putve(venth(a,i),i,1);>>;
     return a
     end;

endmodule;


module genpurfn;

%=====================================================================$
%                                                                     $
% VARIOUS GENERAL PURPOSE FUNCTIONS                                   $
%                                                                     $
%=====================================================================$

% 1. GENERALIZATION OF EXISTING FUNCTIONS

symbolic procedure rmkidnew(u);
if null u or null (u:=reval car u) then gensym() else mkid(u,gensym());

put('mkidnew,'psopfn,'rmkidnew); % Usage mkidnew() or mkidnew(<id>).

%symbolic procedure mkidn(u)$
% use the procedure LIST_TO_IDS instead
% generalizes "mkid" for any number of atoms
% Input is mkidn(list(a1,...ak) | bag(a1,...,ak)).
% expand(cdr u, 'mkid);

% flag('(mkidn),'opfn);

symbolic procedure list_to_ids l;
if atom l then rederr "argument for list_to_ids must be a list"
else
intern compress for each i in cdr l join explode i;

flag('(list_to_ids),'opfn);

symbolic procedure simpsetf u;
% generalizes the function "set" to kernels.
  begin scalar x;
     x := simp!* car u;
if not kernp x  or fixp (!*q2a x) then
                           typerr(!*q2a x,"setvalue kernel") else
      x:=!*q2a x;
     let0 list(list('equal,x,mk!*sq(u := simp!* cadr u)));
     return u
  end;

put ('setvalue, 'simpfn, 'simpsetf);

newtok '((!= !=) setvalue ! !=!=! );

infix ==;

flag('(prin2 ) ,'opfn); % To make it available in the alg. mode.


% 2. NEW ELEMENTARY FUNCTIONS CLOSELY RELATED TO EXISTING ONES.

symbolic procedure oddp u$
% Tests if integer U is odd. Is also defined in EXCALC;
not evenp u;

flag('(oddp),'boolean);

symbolic procedure followline(n)$
%It allows to go to a new line at the position  given by the integer N.
<< terpri()$ spaces(n)>>$

symbolic flag('(followline ) ,'opfn);

% 3. NEW GENERAL PURPOSE FUNCTIONS.

symbolic procedure charnump!: x;
 if x member list('!0,'!1,'!2,'!3,'!4,'!5,'!6,'!7,'!8,'!9) then t ;

symbolic procedure charnump u;
if null u then t else charnump!: car u and charnump cdr u;

 symbolic procedure detidnum u;
 % Allows one to extract the index number from the identifier u.
 if idp u then
   begin scalar uu;
      if length(uu:= cdr explode u) =1 then go to l1
      else
        while not charnump uu do uu:=cdr uu;
   l1: uu:= compress uu;
      if fixp uu then return uu end;

flag('(detidnum),'opfn);

symbolic procedure dellastdigit u;
% Strips an integer from its last digit.
if fixp u then compress reverse cdr reverse explode u
else typerr(u,"integer");

flag('(dellastdigit),'opfn);

symbolic procedure randomlist(n,trial);
% This procedure gives a list of trials in number "trial" of
% random numbers between 0 and n. For the algorithm see KNUTH vol. 2.
'list . lisp for j:=1:trial collect random n;

flag('(randomlist),'opfn);

symbolic procedure transpose(l,i,j);
% i,j are integers, l is a list.
% DESTROYS the initial list.
 begin scalar tmp;
 tmp:=nth(l,i);
 nth(l,i):=nth(l,j);
 nth(l,j):=tmp;
 return l
end;

algebraic procedure combnum(n,nu)$
% Number of combinations of n objects nu to nu.
if nu>n then
rederr "second argument cannot be bigger than first argument"
else  factorial(n)/factorial(nu)/factorial(n-nu)$

symbolic procedure cyclicpermlist l;
% Gives all cyclic permutations of elements of the list l.
if atom l then nil else
 begin scalar x; integer le;
 l:=cdr l;
 le:=length l;
 x:= ('list . l) . x;
 for i:=2:le do x:=('list . (l:=append(cdr l,list car l))) . x;
 return 'list .  reversip x
end;

flag('(cyclicpermlist),'opfn);

symbolic procedure rpermutation u;
if not baglistp(u:=reval car u) then
   nil else if null cdr u then 'list . nil  else
 begin scalar x,prf$ prf:=car u$
    u:=cdr u$
    x:=for each j in  u
    conc  mapcons(permutations delete(j,u),j)$
    x:=for each j in x collect prf . j$
    return prf . x end;

put('permutations,'psopfn,'rpermutation);

symbolic procedure perm_to_num(nindl,indl);
% INPUT : 'indl' : a list of indices.
%         'perm' : a permutation of 'indl'.
% OUTPUT : an INTEGER (between 0 and (indl)!-1 ) in one-to-one
%          correspondence with 'nindl' for the given 'indl'.
begin integer ln,fln,r,num,pos;
 nindl:=cdr nindl;
 if (ln:=length nindl)= 1 then return num;
 fln:=rnfactorial!* mkratnum ln;
 while ln>=1 do <<
                  << r:=rposition list(lastcar nindl,indl);
                    nindl:=for each j in be_last nindl collect
                       <<pos:=rposition list(j,indl);
                          if pos>r then nth(cdr indl,pos-1) else j
                       >>;
                    fln:=fln/ln; num:=num + (ln-r)*fln;
                   >>;
       ln:=ln-1 >>;
return num
end;

symbolic procedure num_to_perm(num,indl);
% Does the reverse job. num is an INTEGER. indl is a list of numbers.
% Constructs the corresponding permutation list starting from indl.
begin integer rk,j,f,m,lst; scalar nindl;
indl:=cdr indl;
rk:=length indl;
f:=rnfactorial!* mkratnum rk;
while rk>=1 do <<
                  <<f:=f/rk; m:=rnfloor!* mkratnum(num/f);
                    num:=num-m*f; j:=rk-m;
                    lst:=nth(indl,j); indl:=remove(indl,j);
                    nindl:=lst . nindl>>;
                  rk:=rk-1
                >>;
return 'list . nindl
end;

flag('(perm_to_num num_to_perm),'opfn);

symbolic procedure !:comb(u)$
begin scalar x,prf; integer n;
 if length u neq 2 then
      rederr "combinations called with wrong number of arguments";
 x:=reval car u ;  if not baglistp x then return nil ;
 prf :=car x; x:=cdr x; n:=reval cadr u;
 return prf . (for each j in comb(x,n) collect prf . j)
end;

 put('combinations,'psopfn,'!:comb);

 put('symmetrize,'simpfn,'simpsumsym);

 flag('(symmetrize),'listargp);

symbolic procedure simpsumsym(u);
% The use is SYMMETRIZE(LIST(A,B,...J),operator,perm_function)
% or SYMMETRIZE(LIST(LIST(A,B,C...)),operator,perm_function).
% Works both for OPFN and symbolic procedure functions.
% Does not yet allow odd permutations.
if length u neq 3 then rederr("3 arguments required for symmetrize")
else
begin scalar uu,x,res,oper,fn,bool,boolfn; integer n;
  fn:= caddr u;
  if not(gettype fn eq 'procedure) then typerr(fn,"procedure");
  uu:=(if flagp(fn,'opfn) then <<boolfn:=t; reval x>>
          else cdr reval x) where x=car u;
  n:=length uu;
  oper:=cadr u;
   if not idp oper then typerr(oper,"operator") else
   if null flagp(oper,'opfn) then
     if null get(oper,'simpfn) then put(oper,'simpfn,'simpiden);
     flag(list oper, 'listargp);
  x:=if listp  car uu and not boolfn then
                <<bool:=t;apply1(fn, cdar uu)>> else
     if boolfn and listp cadr uu then
                <<bool:=t;apply1(fn,cadr uu)>> else
                        apply1(fn,uu);
  if flagp(fn,'opfn) then x:=alg_to_symb x;
  n:=length x -1;
  if not bool then <<
 res:=( oper . car x) .** 1 .* 1 .+ nil;
 for i:=1:n do << uu:=cadr x; aconc(res,(oper . uu) .** 1 .* 1 );
                                       delqip(uu,x);>>;
           >>
  else
 << res:=(oper . list('list .
      for each i in car x collect mk!*sq simp!* i)) .** 1 .* 1 .+ nil;
    for i:=1:n do << uu:=cadr x;
    aconc(res,(oper . list('list .
          for each i in uu collect mk!*sq simp!* i)) .** 1 .* 1 );
     delqip(uu,x);>>;
  >>;
  if get(oper,'opmtch) or flagp(oper,'opfn) then
        res:=resimp( res ./ 1) else res:=res ./ 1;
return  res
end;

symbolic procedure sortnumlist l;
% Procedure valid only for list of integers.
% Returns the sorted list without destroying l.
'list . (if length x < 10 then bubblesort1 x else
   quicksort_i_to_j(x,1,length x))where x=cdr l ;

flag('(sortnumlist),'opfn);

symbolic procedure sortlist(l,fn);
if numlis cdr l  then
      if fn eq 'lessp  then sortnumlist l else
      if fn eq 'geq then
      ( 'list . (reverse(if length x <10 then bubblesort1 x else
               quicksort_i_to_j(x,1,length x))) where x=cdr l) else
                             nil else
'list . bubsort1(cdr l,fn);

flag('(sortlist),'opfn);

symbolic procedure bubblesort1 l;
% Elements of l are supposed to be numbers.
begin integer ln;
ln:=length l;
for i:=1:ln do
    for j:=i+1:ln do
           if i neq j and nth(l,i)>nth(l,j) then
            transpose(l,i,j) else nil;
return l
end;

symbolic procedure bubsort1(l,fn);
% Elements of l are numbers or identifiers.
% fn is any ordering function.
begin integer ln;
ln:=length l;
for i:=1:ln do
    for j:=i+1:ln do
           if i neq j and
                apply2(fn,nth(l,j),nth(l,i)) then
            transpose(l,i,j) else nil;
return l
end;

symbolic procedure find_pivot_index(l,i,j);
% l is the list, i and  j are integers.
begin scalar key; integer k;
key:=nth(l,i);
k:=i+1;
a: if k=j+1 then return -1;
if nth(l,k) > key then return k else
if nth(l,k) < key then return i;
 k:=k+1; go to a
end;

symbolic procedure partition(l,i,j,pivot);
% Writes l, all elements less than  pivot to the left
% and elements greater or equal to the right of pivot.
% returns the new pivot.
begin integer le,ri;
le:=i; ri:=j;
a: if le>ri then return le;
     transpose(l,le,ri);
while nth(l,le) < pivot do le:=le+1;
   while nth(l,ri) >= pivot do ri:=ri-1;
   go to a
end;

symbolic procedure quicksort_i_to_j(l, i,j);
begin integer k,pi;
pi:=find_pivot_index(l,i,j);
return if pi neq -1 then
        <<pi:=nth(l,pi); k:=partition(l,i,j,pi);
          quicksort_i_to_j(l,i,k-1);quicksort_i_to_j(l,k,j);l>>
        else l
end;

symbolic procedure algsort(u,v);
% Based on the PSL sort function.
% May replace all the above functions.
symb_to_alg sort(alg_to_symb u,v);

symbolic operator algsort;

symbolic procedure listofvars u $
if null u  or numberp u  then nil else
if atom u then list u else
varsinargs if eqcar(u,'list) then cdr reval u  else cdr u$

symbolic procedure varsinargs(u)$
if null u then nil else
append(listofvars car u,varsinargs cdr u)$

symbolic procedure rfuncvar(u)$
% U is an arbitrary expression
% Gives a list which contains all the variables whom U depends
% in an ARBITRARY order$
<<if atom (u:=reval car u) then
if not flagp(u,'reserved) then
        if depatom u neq u  then depatom u else nil
else nil else
 begin scalar wi,aa$
 aa:=listofvars(u)$
 if null cdr aa then return
      if flagp(car aa,'reserved) or flagp(car aa,'constant)
      then nil else car aa
 else aa:=list2set aa $ wi:=aa$
  while wi do if flagp(car wi ,'reserved) then
    <<aa:=delete(car wi ,aa)$ wi:=cdr wi >> else wi:=cdr wi $
  return aa:='list . aa end >>;

symbolic put('funcvar,'psopfn ,'rfuncvar);

flag('(e i),'reserved);

symbolic procedure implicit u;
if atom u then u else
 begin scalar prf;
 prf:=car u;
 if get(prf,'simpfn) neq 'simpiden  then
                  rederr list(u,"must be an OPERATOR");
 remprop(car u,'simpfn);
 depl!*:=union(list (car u . reverse
           for each y in cdr u collect implicit y),depl!*);
 return prf end;

symbolic procedure depatom a$
%Gives a list of variables declared in DEPEND commands whom A depends
%A must be an atom$
    if not atom a then rederr("ARGUMENT MUST BE AN ATOM") else
         if null assoc(a,depl!*) then a  else
                            'list . reverse cdr assoc(a,depl!*);
flag('(depatom),'opfn);

symbolic procedure explicit u$
% U is an atom. It gives a function named A which depends on the
% variables detected by DEPATOM and this to all levels$
begin scalar aa$
    aa:=depatom u $
    if aa = u then  return u$
    put(u,'simpfn,'simpiden)$
    return u . (for each x in cdr aa collect explicit x) end$

symbolic flag('(implicit explicit),'opfn);

symbolic procedure simplify u;
% Enforces simplifications if necessary.
% u is any expression.
mk!*sq resimp simp!* reval u;

flag('(simplify),'opfn);

% 4. FUNCTIONS TO DEAL WITH PROPERTIES IN THE ALGEBRAIC MODE.

symbolic procedure checkproplist(l,fn);
% fn may be the name of a function or the expression 'function <name
if atom l then rederr("First argument must be a list") else
 checkproplist1(cdr l,fn);

flag('(checkproplist),'boolean);

symbolic procedure checkproplist1(l,fn);
% Checks if the list l has the property defined by the function fn.
% fn should preferably be  'function <name_function>'.
 if null l then t else
 if fn eq 'numberp then
   if apply1(function evalnumberp, car l) then checkproplist1(cdr l,fn)
    else  nil else
 if fn eq 'floatp then
    if atom car l then nil else
    if apply1(function floatp, cdar l ) then checkproplist1(cdr l,fn)
    else nil else
 if get(fn,'number!-of!-args)=1  then
    if apply1(fn,car l) then checkproplist1(cdr l,fn)
    else  nil else
 if get(fn,'number!-of!-args)=2 then
    if apply(fn,list(car l,cadr l)) then checkproplist1(cdr l,fn)
 else nil;

symbolic procedure extractlist(l,fn);
 % The message will be issued only when number!-of!-args is used.
(if x and x > 1 then
   rederr("UNARY boolean function required as argument") else
'list . extractlist1(cdr l,fn)) where x=get(fn,'number!-of!-args);

flag('(extractlist),'opfn);

symbolic procedure extractlist1(l,fn);
% fn is a boolean function. Result is a new list which contains the
% elements satisfying the fn selection criteria.
 if null l then nil
 else
  if fn eq 'numberp then
          if apply1(function evalnumberp,car l) then
                         car l . extractlist1(cdr l,fn)
          else extractlist1(cdr l,fn)
  else
  if fn eq 'floatp then
          if atom car l then extractlist1(cdr l,fn) else
          if apply1(function floatp, cdar l)
               then car l . extractlist1(cdr l,fn)
          else extractlist1(cdr l,fn)
  else
  if apply1(fn,car l) then  car l . extractlist1(cdr l,fn)
     else extractlist1(cdr l,fn);

symbolic procedure putflag(u,flg,b)$
% Allows one to put or erase any FLAG on the identifier U.
% U is an idf or a list of idfs, FLAG is an idf, B is T or 0.
if not idp u and not null baglistp u then
              <<for each x in cdr u do putflag(x,flg,b)$ t>>
 else      if idp u and b eq t then
            <<flag(list u, flg)$
              !:flaglis:=union(list list(u, flg),!:flaglis)$ flg>>
 else      if idp u and b equal 0 then
            <<remflag( list u, flg)$ !:delete(u,nil,flg)$>>
 else rederr "*** VARIABLES ARE (idp OR list of flags, T or 0).";

symbolic procedure putprop(u,prop,val,b)$
% Allows to put or erase any PROPERTY on the object U
% U is an idf or a list of idfs, B is T or 0$
if not idp u and baglistp u then
              <<for each x in cdr u do putprop(x,prop,val,b)$ t>>
 else      if idp u and b eq t then
            <<put(u, prop,val)$
              !:proplis:=union(list list(u,prop,val),!:proplis)$ u>>
 else      if idp u and b equal 0 then
            <<remprop( u, prop)$  !:delete(u,prop,val)$ >>
 else rederr "*** VARIABLES ARE (idp OR list of idps, T or 0).";

symbolic  flag('(putflag putprop),'opfn)$

symbolic procedure rdisplayprop(u)$
% U is the idf whose properties one wants to display.Result is a
% list which contains them$
begin scalar x,val,aa$ x:=reval car u; val:=reval cadr u;
for each j in !:proplis do if car j eq x and cadr j eq val
                          then aa:=('list . cdr j) . aa;
return if length aa =1 then first aa else 'list . aa
end;

symbolic put('displayprop,'psopfn,'rdisplayprop)$
symbolic put('displayflag,'psopfn,'rdisplayflag)$

symbolic procedure rdisplayflag(u)$
% U is the idf whose properties one wants to display.Result is a
% list which contains them$
begin scalar x,aa$ x:=reval car u;
 for each j in !:flaglis do if car j=x then aa:=cons(cadr j,aa)$
 return 'list . aa end;

symbolic procedure clrflg!: u;
for each x in !:flaglis do
            if u eq car x then putflag(car x,cadr x,0) ;

symbolic procedure clearflag u;
% If u equals "all" all flags are eliminated.
% If u is a1,a2,a3.....an flags of these identifiers are eliminated.
if null cdr u and car u eq 'all then for each x in !:flaglis
          do putflag (car x,cadr x,0) else
 if null cdr u then clrflg!: car u else
                for each  y in u do clrflg!: y;

symbolic procedure clrprp!: u;
for each x in !:proplis do
          if u eq car x then putprop(car x,cadr x,caddr x,0);

symbolic procedure clearprop u;
% If u equals "all" all properties are eliminated.
% If u is a1,a2,a3...an properties of these identifiers are eliminated.
if null cdr u and car u eq 'all then for each x in !:proplis
          do putprop(car x,cadr x,caddr x,0) else
if null cdr u then clrprp!: car u else
                for each  y in u do clrprp!: y;

symbolic put('clearflag,'stat,'rlis);
symbolic put('clearprop,'stat,'rlis);

endmodule;


module control;

% functions which offer a BETTER CONTROL on $
                % various objects and of the ALREADY USED quantities $

% 1. BOOLEAN functions.

flag('(null idp flagp),'boolean); % NOT COMMENTED

symbolic procedure nordp(u,v);
% TRUE if a>b, FALSE if a=<b.
not ordp(u,v);

symbolic procedure depvarp(u,v)$
% V is an idf. or a kernel$
    if depends(u,v)  then t else nil$

symbolic procedure alatomp(u)$
% U is any expression . Test if U is an idf. whose only value is its
% printname or another atom$
 fixp u or idp u$

symbolic procedure alkernp u$
% U is any expression . Test if U is a kernel.$
not stringp u  and kernp(simp!* u)$

symbolic procedure precp(u,v)$
% Tests if the operator U has precedence over the operator V.
begin integer nn$scalar uu,vv,aa$
    uu:=u$ vv:=v$aa:=preclis!*$
    if or(not(uu member aa),not(vv member aa)) then return nil$
    nn:=lpos(u,aa)$;
    nn:=nn-lpos(v,aa)$
    if nn geq 0 then return t else return nil end$

flag('(nordp alatomp alkernp precp depvarp stringp ),'boolean)$

% THE SUBSEQUENT DECLARATION IS USEFUL FOR "TEACHING PURPOSES".


flag('(alatomp precp depvarp alkernp depatom ) ,'opfn);


% 2. MISCELLANEOUS functions.

symbolic procedure korderlist;
% gives a list of the user defined internal order of the
% indeterminates. Just state KORDERLIST; to get it.
kord!*;

 flag('(korderlist), 'opfn);
 put('korderlist,'stat,'endstat);

symbolic procedure remsym u;
% ALLOWS TO ELIMINATE THE DECLARED SYMMETRIES.
for each j in u do
  if flagp(j,'symmetric) then remflag(list j,'symmetric) else
  if flagp(j,'antisymmetric) then remflag(list j,'antisymmetric);

        put('remsym,'stat,'rlis);

% 3. Control of SWITCHES.

symbolic procedure switches;
%This procedure allows to  see the values of the main switches$
<<terpri();
prin2 "      **** exp:=";prin2 !*exp;prin2 " .................... ";
prin2 "allfac:= ";prin2 !*allfac;prin2 " ****";terpri(); terpri();
prin2 "      **** ezgcd:=";prin2 !*ezgcd;prin2 " ................. ";
prin2 "gcd:= ";prin2 !*gcd;prin2 " ****";terpri();terpri();
prin2 "      **** mcd:=";prin2 !*mcd;prin2 " ....................... ";
prin2 "lcm:= ";prin2 !*lcm;prin2 " ****";terpri();terpri();
prin2 "      **** div:=";prin2 !*div;prin2 " ................... ";
prin2 "rat:= ";prin2 !*rat;prin2 " ****";terpri();terpri();
prin2 "      **** intstr:=";prin2 !*intstr;prin2 " ........... ";
prin2 "rational:= ";prin2 !*rational;prin2 " ****";terpri();terpri();
prin2 "      **** precise:=";prin2 !*precise;prin2 " ........... ";
prin2 "reduced:= ";prin2 !*reduced;prin2 " ****";terpri();terpri();
prin2 "      **** complex:=";prin2 !*complex;prin2 " ....... ";
prin2 "rationalize:= ";prin2 !*rationalize;
prin2 " ****";terpri();terpri();
prin2 "      **** factor:= "; prin2 !*factor;prin2 " ....... ";
prin2 "combineexpt:= ";prin2 !*combineexpt;
                                  prin2 " ****";terpri();terpri();
prin2 "      **** complex:= "; prin2 !*complex;prin2 " ....... ";
prin2 "distribute:= ";prin2 !*distribute;prin2 " ****";>>$

symbolic procedure switchorg$
%It puts all switches relevant to current algebra calculations to
% their initial values.
<< !*exp:=t;
   !*allfac:=t;
   !*gcd:=nil;
   !*mcd:=t;
   !*div:=nil;
   !*rat:=nil;
   !*distribute:=nil;
   !*intstr:=nil;
   !*rational:=nil;
   !*ezgcd:=nil;
   !*ratarg:=nil;
   !*precise:=nil;
   !*complex:=nil;
   !*heugcd:=nil;
   !*lcm:=t;
   !*factor:=nil;
   !*ifactor:=nil;
   !*rationalize:=nil;
   !*reduced:=nil;
   !*savestructr:=nil;
   !*combineexpt:=nil
                      >>;

flag('(switchorg ),'opfn)$

deflist('((switches endstat) (switchorg endstat) ),
           'stat)$

% 4. Control of USER DEFINED objects.
% This  aims to extract from the history of the run
% the significant data defined by the user.
% It DOES NOT give insights on
% operations done in the SYMBOLIC mode.

symbolic procedure remvar!:(u,v)$
% This procedure traces and clear both assigned or saved scalars and
% lists.
 begin scalar buf,comm,lv;
     buf:=inputbuflis!*;
     for each x in buf do if not atom (comm:=caddr x)
                                 and car comm = 'setk then
  begin scalar obj;
  l1: if null cddr comm  or car comm eq 'prog then return lv;
         obj:=cadadr comm;
       if  gettype obj  eq v then
     lv:=adjoin(obj,lv);
         comm:=caddr comm;
         go to l1  end;
 if null u then
    <<for each x in lv do clear x; return t>> else return lv
     end;

flag('(displaylst displayscal),'noform);

symbolic  procedure displayscal;
% Allows to see all scalar variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
 union(remvar!:(t,'scalar),remsvar!:(t,'scalar));

symbolic  procedure displaylst$
% Allows to see all list variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
  union(remvar!:(t,'list),remsvar!:(t,'list)) ;

symbolic procedure clearscal$
% Allows to clear all scalar variables introduced
% DIRECTLY ON THE CONSOLE;
<<remvar!:(nil,'scalar);remsvar!:(nil,'scalar)>>$

symbolic procedure clearlst$
% Allows to clear all list variables introduced
% DIRECTLY ON THE CONSOLE;
<<remvar!:(nil,'list);remsvar!:(nil,'list)>>;

symbolic procedure remsvar!:(u,v)$
 begin scalar buf,comm,lsv,obj;
     buf:= inputbuflis!*;
     for each x in buf do
      if not atom (comm:=caddr x) and car comm eq 'saveas then
         if  v eq t then
             if gettype (obj:=cadr cadadr comm)
                  member list('scalar,'list,'matrix,'hvector,'tvector)
                  then lsv:=adjoin(obj,lsv)
             else nil
         else if v eq gettype (obj:=cadr cadadr comm)
                  then lsv:=adjoin(obj,lsv);
%     lsv:= !:mkset lsv$
    if null u then
    <<for each x in lsv do clear x$ return t>> else return lsv
     end;

flag('(displaysvar),'noform);

symbolic  procedure displaysvar;
% Allows to see all variables created by SAVEAS.
remsvar!:(t,t) ;

symbolic  procedure clearsvar;
% Allows to clear  all variables created.
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file.
remsvar!:(nil,t);

symbolic procedure rema!:(u);
% This function works to trace or to clear arrays.
 begin scalar buf,comm,la$
     buf:=inputbuflis!*$
     for each x in buf do if not atom (comm:=caddr x) and
                car comm eq 'arrayfn then
     begin scalar arl,obj;
         arl:=cdaddr comm;
     l1: if null arl then return la else
           if gettype (obj:=cadadr car arl ) eq 'array then
             la:=adjoin(obj,la);
         arl:=cdr arl$
         go to l1  end$
  if null u then
   <<for each x in la do clear x$ return t>> else return la
 end;

flag('(displayar),'noform);

symbolic  procedure displayar;
% Allows to see all array variables created.
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file.
 rema!:(t)$

symbolic procedure clearar;
% Allows to clear array variables introduced
% DIRECTLY ON THE CONSOLE;
rema!:(nil)$

% This file shoul be loaded together with remscal.red

symbolic procedure remm!:(u)$
% This function works to trace or to clear matrices. Be CAREFUL to use
% the declaration MATRIX on input (not m:=mat(...) directly).
% declaration MATRIX ..
%x ==> (97 SYMBOLIC (MATRIX (LIST (LIST (QUOTE MM) 1 1))))
% Declaration MM:=MAT((...))
% x==>(104 ALGEBRAIC
%       (SETK (QUOTE M2) (AEVAL (LIST (QUOTE MAT) (LIST 1) (LIST 1)))))
 begin scalar buf,comm,lm;
     buf:= inputbuflis!*;
  for each x in buf do if  not atom (comm:=caddr x) and
                           car comm eq 'matrix then
      begin scalar lob,obj;
      lob:=cdadr comm;
   l1: if null lob then return lm else
       if gettype(obj:=if length car lob = 2 then cadr car lob else
                    cadadr car lob) then
          lm:=adjoin(obj,lm);
      lob:=cdr lob;
      go to l1  end$
lm :=union(lm,remvar!:(t,'matrix));
if null u then
 <<for each x in lm do clear x$ return t>> else return lm
 end;

flag('(displaymat),'noform);

symbolic procedure displaymat$
% Allows to see all variables of matrix type
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
union( remm!:(t),remsvar!:(t,'matrix));

symbolic procedure clearmat$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
<<remm!:(nil);remsvar!:(nil,'matrix)>>;

symbolic procedure remv!:(u)$
% This function works to trace or to clear vectors.
 begin scalar buf,av$
     buf:= inputbuflis!*$
  for each x in buf do if not atom (x:=caddr x) and
              car x member list('vector,'tvector,'index)
         then
     begin scalar uu,xx$
         uu:=cdadr x$
     l1: if null uu then return av else
           if gettype(xx:=cadar uu) or get(xx,'fdegree) then
             av:=adjoin(xx,av);
         uu:=cdr uu$
         go to l1  end$
  if null u then
   <<for each x in av do clear x$ return t>> else return av
 end$

flag('(displayvec),'noform);

symbolic  procedure displayvec$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
union(remv!:(t),union(remsvar!:(t,'hvector),remsvar!:(t,'tvector)) );

symbolic procedure clearvec$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
<<remv!:(nil);remsvar!:(nil,'hvector);remsvar!:(nil,'tvector)>>;

symbolic procedure remf!:(u)$
% This function works to trace or to clear forms.
 begin scalar buf,av$
     buf:= inputbuflis!*$
     for each x in buf do if not atom (x:=caddr x) and
                              car x eq 'pform then
     begin scalar uu,xx$
         uu:=cdadr x$
     l1: if null uu then return av else
           if get(xx:=cadadr cdar uu ,'fdegree) or
             (not atom xx and get(xx:=cadr xx,'ifdegree))
    then
             av:=adjoin(xx,av);
         uu:=cdr uu$
         go to l1  end$
  if null u then
   <<for each x in av do clear x$ return t>> else return av
 end$

flag('(displayform),'noform);

symbolic  procedure displayform$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
union(remf!:(t),remvar!:(t,'pform));

symbolic procedure clearform$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
<<remf!:(nil);remvar!:(nil,'pform)>>;



symbolic procedure clear!_all;
<<remvar!: (nil,'scalar); remvar!:(nil,'list); remvar!:(nil,'pform);
  remsvar!:(nil,t);rema!: nil;remv!: nil;remm!: nil; remf!: nil ;t>>;

symbolic procedure show u;
begin u:=car u;
           if u eq 'scalars then
              return write "scalars are: ", displayscal()
           else
           if u eq 'lists  then
              return write "lists are: ", displaylst()
           else
           if u eq 'arrays then
               return write "arrays are: ", displayar()
           else
           if u eq 'matrices then
                       return write "matrices are: ",displaymat()
           else
           if u member list('vectors,'tvectors,'indices)  then
                       return  write "vectors are: ", displayvec()
           else
           if u eq 'forms then
                        return write "forms are: ", displayform()
           else
           if u eq 'all then for each i in
            list('scalars,'arrays,'lists,'matrices,'vectors,'forms) do
                        <<show list i;lisp terpri()>>;
end;

put('show,'stat,'rlis);

symbolic procedure suppress u;
begin u:=car u;
            if u member list('vectors,'tvectors,'indices) then
                       return clearvec() else
            if u eq 'variables then return clearvar() else
            if u eq 'scalars then return clearscal() else
            if u eq 'lists then return clearlst() else
            if u eq 'saveids  then return clearsvar() else
            if u eq 'matrices then return clearmat() else
            if u eq 'arrays then return clearar() else
            if u eq 'forms then return clearform() else
            if u eq 'all then return clear!_all() end;

put('suppress,'stat,'rlis);


% 5. Means to CLEAR operators and functions.

symbolic procedure clearop u;
<<clear u; remopr u; remprop(u , 'kvalue);remprop(u,'klist)$
  for each x in !:flaglis do
            if u eq car x then putflag(u,cadr x,0) else nil;
  for each x in !:proplis do
            if u eq car x then putprop(u,cadr x,caddr x,0)
                              else nil;
     remflag(list u,'used!*); t>>;

symbolic flag('(clearop),'opfn);

symbolic procedure clearfunctions u$
% U is any number of idfs. This function erases properties of  non
% protected functions described by the idfs.
% It is very convenient but is dangerous if applied to the
% basic functions of the system since most of them  are NOT protected.
% It clears all properties introduced by PUTFLAG, PUTPROP and DEPEND.
begin scalar uu,vv$
l1: uu:=car u$
    vv:=cdr rdisplayflag (list  uu )$
    if flagp(uu,'lose) then go to l2 else
    << terpri();spaces(5)$
       write "*** ",uu," is unprotected : Cleared ***"$
       followline(0)>>$
  for each x in !:proplis do
            if u eq car x then putprop(u,cadr x,caddr x,0)
                              else nil;
    remprop('uu,'!*lambdalink);
  if get(uu,'simpfn) then <<clearop uu; remprop(uu,'!:ft!:);
      remprop(uu,'!:gf!:)>> ;
    remprop(uu,'psopfn);
    remprop(uu,'expr);
  if get(uu,'subr) then remd uu$
    remprop(uu,'stat);
    remprop(uu,'dfn);
    remprop(uu,'rtypefn);
    remprop(uu,'number!-of!-args);
    remflag(list uu,'opfn)$
    remflag(list uu,'full)$
    remflag(list uu,'odd)$
    remflag(list uu,'even)$
    remflag(list uu,'boolean)$
    remflag(list uu,'used!*)$
    for each x in vv do putflag( uu,x,0)$
    depl!*:=delete(assoc(uu,depl!*),depl!*);
    remflag(list uu,'impfun)$ % to be effective in EXCALC;
    u:= cdr u$ go to l3$
l2: << spaces(5)$
       write "*** ",uu," is a protected function: NOT cleared ***"$
       terpri(); u:=cdr u>>$
l3: if null u then <<terpri();
              return "Clearing is complete">> else

    go to l1 end$

symbolic rlistat '(clearfunctions);


endmodule;


module polyexns;

%=====================================================================

% ADDITIONAL FUNCTIONS FOR POLYNOME AND RATIONAL EXPRESSION
% MANIPULATIONS.

%=====================================================================

symbolic procedure fix_or_str u;
fixp u or stringp u;

symbolic procedure rgcdnl u;
% Searches the common gcd of all the integers inside the list u.
( if length x = 1 then abs car x else
 eval expand(x,'gcdn) ) where x=cdr revlis car u;

put('gcdnl,'psopfn,'rgcdnl);

symbolic procedure alg_to_symb u;
% transforms standard quotient expressions into prefix symbolic ones.
% dd => (LIST 1 (!*SQ ((((A . 2) . 1)) . 1) T)
% !*SQ ((((A . 1) . 1)) . 1) T) 3 (LIST 4))
% alg_to_symb dd ==> (1 (EXPT A 2) A 3 (4))
%
if null u  then nil else
if atom u then  u else
if car u neq 'list then reval u else
if car u eq 'list  then
  for each i in cdr u collect alg_to_symb i;

symbolic procedure symb_to_alg u;
% transforms prefix lisp list into an algebraic list.
% if null u then nil else
if null u then list('list) else
if fix_or_str u  then u else
if atom u then mk!*sq simp!* u  else
if listp u and  (getd car u or get(car u,'simpfn) )
                                 then  mk!*sq simp!* u else
if atomlis u then 'list . for each i in u collect
        if null i then list('list) else
        if fix_or_str i then i else
                            mk!*sq simp!* i
else
  'list . for each i in u collect symb_to_alg i ;

%algebraic procedure ecrase x;
% Flattens an algebraic list.
%lisp symb_to_alg flattens1 alg_to_symb algebraic x;

%symbolic procedure flattens1 x;
% ll; ==> ((A B) ((C D) E))
% flattens1 ll; (A B C D E)
%if atom x then list x else
%if cdr x then append(flattens1 car x, flattens1 cdr x) else
%   flattens1 car x;

fluid '(!*distribute);

switch distribute;

symbolic procedure addfd (u,v);
% It contains a modification to ADDF to avoid
% a recursive representation.
% U and V are standard forms. Value is a standard form.
if null u then v
else if null v then u
else if  domainp u then addd(u,v)
else if  domainp v then addd(v,u)
else if ordp(lpow u,lpow v)
then lt u .+ addfd(red u,v)
else lt v .+ addfd (u,red v);

symbolic procedure distribute u;
%  Works ONLY when RATIONAL is ON.
begin scalar s;
 s:=simp!* u;
 return mk!*sq (distri!_pol(numr s) ./ denr s)
end;

symbolic flag('(distribute),'opfn);

symbolic procedure distri!_pol u;
% This function assumes that u is a polynomial given
% as a standard form. It transforms its recursive representation into
% a distributive representation.
if null u then nil else
if atom u then u else
if red u  then
   addfd(distri!_pol !*t2f lt u,distri!_pol red u)
     else
 begin scalar x,y;
 x:=1 ;
 y:=u;
 while  not atom y and null red y do
                        <<x:=multf(x,!*p2f lpow y); y:=lc y>>;
 if atom y then return multf(x,y) else
 return
 addfd(distri!_pol multf(x,distri!_pol !*t2f lt y),
       distri!_pol multf(x,distri!_pol red y))
end;

symbolic procedure leadterm u;
<<u:=simp!* u; if !*distribute  then u:=distri!_pol numr u ./ denr u
  else u; if domainp u then mk!*sq u
  else  mk!*sq(!*t2f lt numr u ./ denr u)>>;

symbolic flag('(leadterm redexpr ),'opfn);

symbolic procedure redexpr u;
<<u:=simp!* u; if !*distribute  then u:=distri!_pol numr u ./ denr u
  else u; if domainp u then mk!*sq(nil ./ 1) else
  mk!*sq( red numr u ./ denr u)>>;

symbolic procedure list!_of!_monom u;
% It takes a polynomial in distributive form.
% returns a list of monoms.
% u is numr simp!* (algebraic expression)
% if domainp u then u else  ELIMINATED
begin scalar exp,lmon,mon;
     exp:=u;
% l:  if null exp then return lmon ; OLD statement
l:  if null exp then return lmon else
    if domainp exp then return exp . lmon ;
    mon:=if atom exp then exp else lt exp;
    lmon:=(!*t2f mon ) . lmon;
    exp:=red exp;
     go to l;
end;

symbolic procedure monom y;
if !*rational then rederr "MONOM does only work on rings of integers"
else
begin scalar x;
x:=numr simp!* y;
x:=distri!_pol x;
x:=reversip list!_of!_monom x;
x:=for each m in x collect mk!*sq(m ./ 1);
return 'list . x end;

symbolic flag('(monom),'opfn);

symbolic procedure coeff_mon u;
% argument is lt numr simp!* "algebraic value".
if atom u then u else
coeff_mon((if atom x then x else lt x)where x=red u);

algebraic procedure list_coeff_pol u;
% Gives the list of coefficients of multivariate polynomial u.
% Terms are distributed.
for each i in monom u collect (lisp coeff_mon (if atom i then i else
                                                    lt numr simp!* i));

algebraic procedure norm_mon u;
% Sets the coefficient of the monom u to 1.
if u=0 then 0 else u/(lisp coeff_mon lt numr simp!* algebraic u);

algebraic procedure norm_pol u;
% Tries to put the leading coefficient to 1 i.e. u to normal form.
% If not, it puts the coefficient of the leading term positive.
if u=0 then 0 else
        begin scalar uu,sign;
        uu:=list_coeff_pol u;
        sign:=first uu /(abs first uu);
       if gcdnl uu = abs first uu then return u:= u/first uu
        else return sign * u
        end ;

symbolic procedure pol_ordp(u,v);
% u and v are multivariate polynomials. General ordering function.
(x<y or (x=y and ordp(u,v))) where x = length u, y = length v ;

flag('(pol_ordp),'opfn);

symbolic procedure !&dpol u$
% RETURNS A LIST WHICH CONTAINS THE QUOTIENT POLYNOMIAL and THE
% REMAINDER.
if length u neq 2 then rederr "divpol must have two arguments"
else
begin scalar poln,pold,aa,ratsav$
if lisp (!*factor) then off factor; % This restriction is
                                  % necessary for some implementatins .
    poln:= simp!* car u$
    pold:= simp!* cadr u$
    if denr poln neq 1 or denr pold neq 1 then
    rederr(" arguments must be polynomials")$
    poln:=numr poln$ pold:=numr pold$
    if lc poln neq 1 or lc poln neq lc pold then
                       <<ratsav:=lisp (!*rational); on rational>>;
    aa:=qremf(poln,pold)$
 aa:=mksq(list('list ,prepsq!*( car aa . 1), prepsq!*(cdr aa . 1)),1)$
    if not ratsav then off rational;
    return  aa end$

put('divpol,'simpfn,'!&dpol)$

symbolic procedure lowestdeg(u,v)$
% IT EXTRACTS THE LOWEST DEGREE IN V OUT OF THE POLYNOMIAL U.
% U is the POLYNOMIAL. V is an ID or a KERNEL.
begin scalar x,y,uu,vv;
    uu:=simp!* u$
% It is not yet clear if I should take into account purely numerical
% terms in the polynomial. I opted for YES but if one wants NO then
% it is enough to put a comment sign on the second return.
   if domainp uu then return 0;
    uu:=!*q2f uu;
    vv:=erase_pol_cst uu;
    if vv neq uu then return 0;
    vv:=!*a2k v;
    x:=setkorder list v;
    y:=reorder uu; setkorder x;
    y:=reverse y;
    uu:=mvar y;
    if not atom uu then if car uu eq 'expt then
         rederr("exponents must be integers")$
    if uu neq vv then return 0 else
        return  ldeg y end$

flag('(lowestdeg),'opfn)$

symbolic procedure erase_pol_cst u;
% u is a standard form.
if null u or numberp u then nil
 else lt u . erase_pol_cst red u;

flag('(lowestdeg),'opfn)$


% splitting expressions
% splitterms retuns list of plus-terms and minus-terms.

symbolic operator splitterms; % necessary to make it algebraic.

symbolic procedure splitterms u;
   begin scalar a,b;
     if fixp u and evallessp(u, 0) then return
           'list . ('list . 0 . nil) . ('list .  list('minus, u)
                                                       . nil) . nil
     else if
        atom u  or not(car u member(list('plus,'minus))) then  return
           'list . ('list . u . nil) . ('list . 0 . nil) . nil
     else if
        car u eq 'minus then return
           'list . ('list . 0 . nil) . ('list . cdr u) . nil;
     while(u:=cdr u) do
        if atom car u or not (caar u eq 'minus) then a:= car u . a
         else b:=cadar u . b;
     if null a then a:=0 . nil;
     if null b then b:=0 . nil;
     return 'list . ('list . reversip a) . ('list . reversip b) . nil;
   end;

algebraic procedure splitplusminus(u);
% Applies to rational functions.
begin scalar uu;
uu:=splitterms num u;
return list((for each j in first uu sum j) /den u,
            - (for each j in second uu sum j)/den u)
end;

endmodule;


module transfns;

algebraic;

algebraic procedure trigexpand wws;
  wws where { sin(~x+~y) => sin(x)*cos(y)+cos(x)*sin(y),
              cos(~x+~y) => cos(x)*cos(y)-sin(x)*sin(y),
              sin((~n)*~x) => sin(x)*cos((n-1)*x)+cos(x)*sin((n-1)*x)
                   when fixp n and n>1,
              cos((~n)*~x) => cos(x)*cos((n-1)*x)-sin(x)*sin((n-1)*x)
                   when fixp n and n>1 };

algebraic procedure hypexpand wws;
  wws where {sinh(~x+~y) => sinh(x)*cosh(y)+cosh(x)*sinh(y),
             cosh(~x+~y) => cosh(x)*cosh(y)+sinh(x)*sinh(y),
           sinh((~n)*~x) => sinh(x)*cosh((n-1)*x)+cosh(x)*sinh((n-1)*x)
                   when fixp n and n>1,
           cosh((~n)*~x) => cosh(x)*cosh((n-1)*x)+sinh(x)*sinh((n-1)*x)
                   when fixp n and n>1 };

operator !#ei!&; !#ei!&(0):=1;

trig!#ei!& := {!#ei!&(~x)**(~n) => !#ei!&(n*x),
               !#ei!&(~x)*!#ei!&(~y) => !#ei!&(x+y)};

let trig!#ei!&;

algebraic procedure trigreduce wws;
        <<wws:=(wws where {cos(~x) => (!#ei!&(x)+!#ei!&(-x))/2,
                           sin(~x) => -i*(!#ei!&(x)-!#ei!&(-x))/2});
          wws:=(wws where {!#ei!&(~x) => cos x +i*sin x})>>;

algebraic procedure hypreduce wws;
        <<wws:=(wws where {cosh(~x) => (!#ei!&(x)+!#ei!&(-x))/2,
                           sinh(~x) => (!#ei!&(x)-!#ei!&(-x))/2});
          wws:=(wws where {!#ei!&(~x) => cosh(x)+sinh(x)})>>;

endmodule;


module vectorop;

% This small module makes basic operation between EXPLICIT vectors
% available. They are assumed to be represented by BAGS or LISTS.


% Mixed product  is restricted to 3-space vectors.
% Generalization is still NEEDED.                 ;

symbolic procedure depthl1!: u;
 if null u then t else (caar u neq 'list) and depthl1!: cdr u;

symbolic procedure depthl1 u;
not null getrtype u and  depthl1!: cdr u;

symbolic procedure !:vect(u,v,bool);
   %returns a list whose elements are the sum of each  list elements.
   % null v check not necessary;
   if null u then nil
else  addsq(car u,if null bool then car v else negsq car v)
                                          . !:vect(cdr u,cdr v,bool);
symbolic procedure rsumvect(u);
begin scalar x,y,prf;
x:=reval car u;y:=reval cadr u; prf:=car x;
 if (rdepth list x = 0) or (rdepth list y = 0) then
    rederr " both arguments must be of depth 1 " else
x:=cdr x; y:=cdr y;
if length x neq length y then rederr "vector mismatch";
x:=for each j in x collect simp!* j;
y:=for each j in y collect simp!* j;
return prf . (for each j in !:vect(x,y,nil) collect mk!*sq j) end;

         put('sumvect,'psopfn,'rsumvect);

symbolic procedure rminvect(u);
begin scalar x,y,prf;
x:=reval car u;y:=reval cadr u; prf:=car x;
 if (rdepth list x = 0) or (rdepth list y = 0) then
    rederr " both arguments must be of depth 1 " else
x:=cdr x; y:=cdr y;
if length x neq length y then rederr "vector mismatch";
x:=for each j in x collect simp!* j;
y:=for each j in y collect simp!* j;
return prf . (for each j in !:vect(x,y,'minus) collect mk!*sq j) end;

put('minvect,'psopfn,'rminvect);

symbolic procedure !:scalprd(u,v);
   %returns scalar product of two lists;
   if null u and null v then nil ./ 1
    else addsq(multsq(car u,car v),!:scalprd(cdr u,cdr v));

symbolic procedure sscalvect(u);
begin scalar x,y;
  x:=reval car u;y:=reval cadr u;
 if (rdepth list x = 0) or (rdepth list y = 0) then
     rederr " both arguments must be of depth 1 " else
 if length x neq length y then rederr "vector mismatch";
  x:=cdr x; y:=cdr y;
  x:=for each j in x collect simp!* j;
  y:=for each j in y collect simp!* j;
 return mk!*sq !:scalprd(x,y)
end;

symbolic put('scalvect,'psopfn,'sscalvect);

symbolic procedure !:pvect3 u;
begin scalar x,y; integer xl;
 if (rdepth list car u = 0) or (rdepth cdr u = 0) then
    rederr " both arguments must be of depth 1 " else
x:=reval car u;y:=reval cadr u;
if (xl:=length x) neq 4 then rederr "not 3-space vectors" else
if xl neq length y then rederr "vector mismatch" ;
x:=cdr x; y:=cdr y;
x:=for each j in x collect simp!* j;
y:=for each j in y collect simp!* j;
return
 list( addsq(multsq(cadr x,caddr y),negsq multsq(caddr x,cadr y)),
        addsq(multsq(caddr x,car y),negsq multsq(car x,caddr y)),
         addsq(multsq(car x,cadr y),negsq multsq(cadr x,car y)))
  end;

symbolic procedure rcrossvect u;
% implemented only with LIST prefix;
'list . (for each j in !:pvect3 u collect mk!*sq j);

symbolic put ('crossvect,'psopfn,'rcrossvect);

symbolic procedure smpvect u;
begin scalar x;
if  (rdepth list car u =0) then
    rederr " arguments must be of depth 1 "  else
x:=reval car u; u:=cdr u;
x:=cdr x;
if length x neq 3 then rederr " not 3-space vector";
x:=for each j in x collect simp!* j;
return mk!*sq !:scalprd(x,!:pvect3 u) end;


symbolic put('mpvect,'psopfn,'smpvect);


endmodule;


module grassman;

% fichier de manipulation des variables de Grassmann.
% RATIONAL functions involving Grasman variables inside the
% denominator NOT ALLOWED.
%
symbolic procedure putgrass u;
% Allows to define Grassmann  variables.
for each i in u do
  if not idp i then typerr(i,"grassman variable")
  else <<flag(list i,'noncom); put(i,'simpfn,'simpiden);
                     flag(list i, 'grassman);>> ;

rlistat '(putgrass remgrass);

symbolic procedure remgrass u;
% Erase the Grassman properties of the identifiers in  u.
for each i in u do
   if flagp(i,'grassman) then
    <<remflag(list i,'grassman);remflag(list i ,'noncom);
                                            clearop i;>>;

symbolic procedure grassp u;
not atom u and flagp(car u, 'grassman);

lisp flag('(grassp),'boolean);

symbolic procedure grassparityini u;
% Not used anymore
if  grassp u then 1 else 0;

symbolic procedure grassparity u;
if atom u then 0 else
if flagp(car u,'grassman) then 1 else
if car u eq 'plus then "parity undefined" else
if car u eq 'minus then grassparity cadr u else
if car u eq 'times
  then remainder(for each i in cdr u sum grassparity i,2) else
if car u eq 'expt then if oddp caddr u then grassparity cadr u  else 0
else
if car u eq 'quotient then grassparity cadr u
else 0;

flag('(grassparity ghostfactor),'opfn);

symbolic procedure ghostfactor(u,v);
% (-1)^(grassparity u * grassparity v)
if reval list('times, grassparity u, grassparity v) = 0 then 1 else -1;

% *****************
% For the time being we let the explicit manipulation of
% Grassman variables as matching rules :
% here is an example of use of the previous functions :
% to try them erase the %
% putgrass eta,prond;

% grasskernel:=
% {(~x)*(~y) => y*x when grassp x and  not grassp y,
% prond(~x)*eta(~y) => -eta(y)*prond(x),
% eta(~x)*eta(~y) => -eta y*eta x when nordp(x,y),
% prond(~x)*prond(~y) => -prond y*prond x when nordp(x,y),
% (~x)*(~x) => 0 when grassp x};

% let grasskernel;
% ***********************

endmodule;


module matrext;

% This module defines additional utility functions for manipulating
% matrices.  Coercions to BAG and LIST structures are defined.

symbolic procedure natnumlis u;
   % True if U is a list of natural numbers.
   % Taken from MATR.RED for bootstrap purpose.
null u or numberp car u and fixp car u and car u>0 and natnumlis cdr u;

symbolic procedure mkid!:(x,y);
  % creates the ID XY from identifier X and (evaluated) atom Y.
  if not idp x or null getrtype x then typerr(x,"MKID root")
   else if atom y and (idp y or fixp y and not minusp y)
    then intern compress nconc(explode x,explode y)
   else typerr(y,"MKID index");

symbolic procedure mkidm(u,j);
% This function allows us to RELATE TWO MATRICES by concatanation of
% characters. u AND uj should BOTH be matrices.
  matsm cadr get(mkid!:(u,j),'avalue) ;

symbolic  put('mkidm,'rtypefn,'getrtypecar);

symbolic  flag('(mkidm),'matflg);

symbolic  procedure baglmat (u,op);
% this procedure maps U into the matrix whose name is OP;
% it cannot REDEFINE the matrix OP.
% This is to avoid accidental redefinition of a previous matrix;
if getrtype op  then rederr list(op,"should be an identifier")
else
 begin scalar x,y;
  if atom op then if not (y:=gettype op) then put(op,'rtype,'matrix)
                  else typerr(list(y,op),"matrix");
  if rdepth list u neq 2 then rederr("depth of list or bag must be 2");
      x:=cdr u;
      x:= for each j in x collect for each k in cdr j collect k;
    put(op,'avalue,list('matrix,'mat . x));
return t end;

symbolic flag('(baglmat),'opfn);

symbolic procedure rcoercemat u;
% Transforms a matrix into a bag or list. Argument is a list (mat,idp).
% idp is the name to  be given to the line or column vectors.
% The idp-envelope of the bag is the same as the one of the one of the
% subbags$
begin scalar x,prf;
 x:=reval car u;
if getrtype x neq 'matrix then rederr list(x,"should be a matrix");
 prf:= cadr u;
if car x neq 'mat then typerr(x,"matrix") else
 if prf neq 'list then  <<prf:=reval prf; simpbagprop list(prf,t)>>;
 x:=cdr x;
 x:= for each j in x collect (prf .  j);
return prf . x end;

symbolic put('coercemat,'psopfn,'rcoercemat);
symbolic put('rcoercemat,'number!_of!_args,2);

symbolic procedure n!-1zero(n,k)$
if n=0 then nil else
if k=1 then 1 . nzero(n-1) else
if k=n then  append(nzero(n-1) , (1 . nil))  else
append(nzero(k-1), (1 . nzero(n-k)))$

symbolic procedure unitmat u$
% It creates unit matrices. The argument is of the form A(2),B(5)....$
begin scalar l,sy,x,aa$
for each s in u do
<< if atom s or length (l:= revlis cdr s) neq 1 or not natnumlis l
      then errpri2(s,'hold) else
<<aa:=nil;sy:=car s; x:=gettype sy; if not null x then if x eq 'matrix
                                    then lprim list(x,sy,"redefined")
                                    else typerr(list(x,sy),"matrix");
         l:=car l; for n:=1:l do aa:=n!-1zero(l,l-n+1) . aa$
        put(sy,'rtype,'matrix);
        put(sy,'avalue,list('matrix,'mat . aa))>>>>;
 end$

symbolic put('unitmat,'stat,'rlis);

symbolic procedure  submat (u,nl,nc);
% Allows to extract from the matrix M the matrix obtained when
% the row NL and the column NC have been dropped.
% When NL and NC are out of range gives a copy of M;
if getrtype u neq 'matrix then rederr list(u,"should be a matrix")
else
begin scalar x;
x:=  matsm  u;
    if and(nl=0,nc=0) then return  x else
    if nl neq 0 then x:=remove(x,nl)$
    if nc neq 0 then
         x:=for each j in x collect remove(j,nc);
    return x end;

symbolic put('submat,'rtypefn,'getrtypecar);
symbolic flag('(submat),'matflg);

symbolic procedure matsubr(m,bgl,nr)$
if getrtype m neq 'matrix then rederr list(m,"should be a matrix")
else
begin scalar x,y,res; integer xl;
% It allows to replace row NR of the matrix M by the bag or list BGL;
y:=reval bgl;
 if not baglistp y  then typerr(y,"bag or list") else
 if nr leq 0 then rederr " THIRD ARG. MUST BE POSITIVE"
 else
    x:=matsm m$ xl:=length x$
   if length( y:=cdr y) neq xl then  rederr " MATRIX MISMATCH"$
    y:= for each j in y collect simp j;
   if nr-xl >0 then rederr " row number is out of range";
    while (nr:=nr-1) >0
              do <<res:=car x . res$ x:=cdr x >>;
           rplaca(x,y) ;
           res:=append(  reverse res, x) ;
    return  res   end;

symbolic put('matsubr,'rtypefn,'getrtypecar);
symbolic flag('(matsubr),'matflg);


symbolic procedure matsubc(m,bgl,nc)$
if getrtype m neq 'matrix then rederr list(m,"should be a matrix")
else
begin scalar x,y,res; integer xl;
%It allows to replace column NC of the matrix M by the bag or list BGL
y:=reval bgl;
 if not baglistp y  then typerr(y,"bag or list") else
 if nc leq 0 then rederr " THIRD ARG. MUST BE POSITIVE"
 else
    x:=tp1 matsm m$ xl:=length x$
   if length( y:=cdr y) neq xl then  rederr " MATRIX MISMATCH"$
    y:= for each j in y collect simp j;
   if nc-xl >0 then rederr " column  number is out of range";
    while (nc:=nc-1) >0
              do <<res:=car x . res$ x:=cdr x >>;
           rplaca(x,y) ;
           res:=tp1 append(  reverse res, x) ;
    return  res   end;

symbolic put('matsubc,'rtypefn,'getrtypecar);
symbolic flag('(matsubc),'matflg);

symbolic procedure rmatextr u$
% This function allows to extract row N from matrix A and
% to place it inside a bag whose name is LN$
begin scalar x,y; integer n,nl;
x:= matsm car u; y:= reval cadr u; n:=reval caddr u;
if  not fixp n then
rederr "Arguments are: matrix, vector name, line number" else
if not baglistp list y  then  simpbagprop list(y, t)$
nl:=length x;
if n<= 0  or n>nl then return nil$
while n>1 do <<x:=cdr x$ n:=n-1>>$
if null x then return nil$
return x:=y . ( for each j in car x  collect prepsq j) end$

symbolic procedure rmatextc u$
% This function allows to extract column N from matrix A and
% to place it inside a bag whose name is LN$
begin scalar x,y; integer n,nc;
x:= tp1 matsm car u; y:= reval cadr u; n:=reval caddr u;
if  not fixp n then
rederr "Arguments are: matrix, vector name, line number" else
if not baglistp list y  then  simpbagprop list(y, t)$
nc:=length x;
if n<= 0  or n>nc then return nil$
while n>1 do <<x:=cdr x$ n:=n-1>>$
if null x then return nil$
return x:=y . ( for each j in car x  collect prepsq j) end$

symbolic put('matextr,'psopfn,'rmatextr);
symbolic put('matextc,'psopfn,'rmatextc);

symbolic procedure  hconcmat(u,v)$
% Gives the horizontal concatenation of matrices U and V$
  hconcmat!:(matsm u,matsm v );

symbolic procedure hconcmat!:(u,v)$
if null u then v else if null v then u else
append(car u,car v) . hconcmat!:(cdr u,cdr v)$

symbolic put('hconcmat,'rtypefn,'getrtypecar);
symbolic flag('(hconcmat),'matflg);

symbolic procedure vconcmat (u,v)$
% Gives the vertical concatenation of matrices U and V$
 append(matsm u,matsm v);

symbolic put('vconcmat,'rtypefn,'getrtypecar);
symbolic flag('(vconcmat),'matflg);

symbolic procedure tprodl(u,v)$
begin scalar aa,ul$
l1: if null u then return aa$
    ul:=car u$
    ul:=multsm(ul,v)$
    aa:=hconcmat!:(aa,ul)$
    u:=cdr u$
    go to l1$
    end$

symbolic procedure tpmat(u,v)$
% Constructs the direct product of two matrices;
if null gettype u  then multsm(simp u,matsm v) else
if null gettype v then multsm(simp v,matsm u) else
begin scalar aa,uu,vv$
    uu:=matsm u$ vv:=matsm v$
    for each x in uu do aa:=append (aa,tprodl(x,vv))$
return aa end;

infix tpmat$

         put('tpmat,'rtypefn, 'getrtypecar);
         flag('(tpmat),'matflg)$

algebraic procedure hermat (m,hm);
% hm must be an identifier with NO value. Returns the
% Hermitiam Conjugate matrix.
begin scalar ml,ll; %ll:=length M;
m:=tp m;
ml:=coercemat(m,list);
ll:=list(length first ml,length ml);
ml:=for j:=1: first ll collect for k:=1:second ll collect
        sub(i=-i,(ml.j).k);
baglmat(ml,hm);
return hm end;

symbolic procedure seteltmat(m,elt,i,j);
% Sets the matrix element (i,j) to elt. Returns the modified matrix.
begin scalar res;res:=matsm m;
rplaca(pnth(nth(res,i),j),simp elt);
return res end;

put('seteltmat,'rtypefn,'getrtypecar);
flag('(seteltmat),'matflg);

symbolic procedure simpgetelt u;
% Gets the matrix element (i,j). Returns the element.
begin scalar mm;
mm:=matsm car u;
return nth(nth(mm,cadr u),caddr u) end;

put('geteltmat, 'simpfn,'simpgetelt);

endmodule;


module helpasst;

algebraic procedure assist();
<<write " Arguments must be integers from 3 to 15 ";
 write " They correspond to the section numbers in the documentation:";
  write  " 3 for switches ", "   4 for lists      ","  5 for bags    ",
         "  6 for sets ";
  write " 7 for utilities ", "  8 for properties ",
                                  "  9 for control functions ";
  write " 10 for polynomes "," 11 for trigonometric  or
                                                 hyperbolic functions";
  write " 12 for arrays ","    13 for  vectors ";
  write " 14 for grassmann variables ","          15 for matrices";>>;

algebraic procedure helpassist(n);
if n = assist then assist() else
if not fixp n then rederr("Argument must be an integer") else
if n>=16 then "no help for this argument"
else
 begin scalar xx;
 xx:= asflist(n,assist_func);
return if length xx=1 then rest first xx else
       for each i in xx collect rest i
end;

algebraic(
assist_func:= {{4, "mklist", "algnlist", "frequency", "sequences",
              "kernlist", "insert_keep_order", "merge_list", "delete"},
              { 5, "putbag", "clearbag", "bagp", "baglistp", "split"
                , "alistp", "abaglistp", "listbag"},
              {4,"first", "second", "third", "rest", "reverse",
               "last", "belast", "append", "appendn", "cons", "length",
               "remove", "delete", "delete_all",
              "member", "elmult", "pair", "delpair", "depth", "insert",
               "position", "asfirst", "asrest", "aslast", "asflist",
               "asslist", "substitute", "repfirst", "represt"},
              {6, "union", "setp", "mkset", "setdiff", "symdiff"},
              {7, "mkidnew", "list_to_ids", "oddp", "followline",
              "detidnum", "dellastdigit"},
              {7, "randomlist", "mkrandtabl","combnum",
              "cyclicpermlist", "permutations", "perm_to_num",
              "num_to_perm", "symmetrize",
                 "extremum", "sortnumlist", "sortlist","algsort"},
              {7, "funcvar", "implicit", "depatom", "explicit",
              "simplify"},
              {7, "checkproplist", "extractlist"},
              {8, "putflag", "putprop", "displayprop", "displayflag",
               "clearflag", "clearprop"},
              {9, "nordp", "depvarp", "alatomp", "alkernp", "precp",
                "korderlist", "remsym"},
              {3,  "switches", "switchorg"},
              {9, "show", "suppress", "clearop", "clearfunctions"},
              {10, "alg_to_symb", "symb_to_alg"},
              {10, "gcdnl", "distribute", "leadterm", "redexpr",
              "monom",   "lowestdeg",  "splitterms", "splitplusminus",
              "norm_mon", "norm_pol", "list_coeff_pol"},
              {11, "trigexpand", "hypexpand","trigreduce","hypreduce"},
              {12, "list_to_array", "array_to_list"},
              {13, "sumvect", "minvect", "sscalvect", "crossvect",
               "mpvect"},
              {14, "putgrass", "remgrass", "grassp", "grassparity",
                    "ghostfactor"},
              {15, "mkidm", "baglmat", "coercemat", "unitmat","submat",
                "matsubr", "matsubc",
              "matextr", "matextc", "hconcmat", "vconcmat",
               "tpmat","hermat","seteltmat", "getelmat"}})$

endmodule;


end;
