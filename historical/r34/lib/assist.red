module assist; % Header Module for REDUCE 3.4 Extensions.

% ********************************************************************
%
%                Author: H. Caprasse <u214001@bliulg11.bitnet>.
%                      or            <u214001@vm1.ulg.ac.be>
%
% Version and Date:  Version 1.0, 1 June 1991.

% Revision history : none
%
% ********************************************************************

endmodule;


module switchext$

fluid '(!*distribute);

switch distribute;

%********** Functions for the manipulation of the switches.$


% Notice that the switches FLOAT,.. are not included . If the user
% wants it can be done in the same way as shown here$


%********** Functions for the manipulation of the switches.$

symbolic procedure switches$
%This procedure allows to  see the values of the main switches$
<<prin2 "      **** exp:=";prin2 !*exp;prin2 " ************* ";
prin2 "div:= ";prin2 !*div;prin2 " ****";terpri(); terpri();
prin2 "      **** gcd:=";prin2 !*gcd;prin2 " *********** ";
prin2 "mcd:= ";prin2 !*mcd;prin2 " ****";terpri();terpri();
prin2 "     **** allfac:=";prin2 !*allfac;prin2 " *********** ";
prin2 "intstr:= ";prin2 !*intstr;prin2 " ****";terpri();terpri();
prin2 "      **** rat:=";prin2 !*rat;prin2 " *********** ";
prin2 "rational:= ";prin2 !*rational;prin2 " ****";terpri();terpri();
prin2 "   *** factor:= "; prin2 !*factor;prin2 " *********** ";
prin2 "distribute:= ";prin2 !*distribute;prin2 " ***";>>$

         flag('(switches),'opfn)$

flag('(!*factor !*mcd !*div !*exp !*gcd !*rat !*rational
        !*intstr !*reduced !*ratpri !*revpri !*distribute),'share)$

symbolic procedure switchoff$
%It puts off all switches.It is provided for convenience$
<< !*exp:=nil$ !*allfac:=nil$ !*gcd:=nil$ !*rat:=nil$ !*factor:=nil$
   !*intstr:=nil$ !*mcd:=nil$ !*div:=nil$ !*rational:=nil>>$

symbolic procedure switchorg$
%It puts all switches to their value when entering the system$
<< !*exp:=t$ !*allfac:=t$ !*gcd:=nil$ !*mcd:=t$ !*div:=nil$!*rat:=nil$
   !*intstr:=nil$ !*rational:=nil>>$

flag('(switchorg switchoff),'opfn)$

deflist('((switches endstat) (switchorg endstat) (switchoff endstat)),
           'stat)$

endmodule$


module baglist$

symbolic procedure rmklis u$
% This function works only for LIST-like objects.
begin scalar s,ss;integer n;
argnochk('mklist . u);
if length u = 2  then
<<s:=reval car u; n:=reval cadr u;
if car s eq 'list then  ss:=
     append(s,cdr rmklis(list(n+1-length s))) else nil>> else
if length u=1 then
 <<n:=reval car u; for j:=1:n do s:=0 . s; ss:='list . s>>
else nil;
return ss end;

put('mklist,'psopfn,'rmklis);

global '(!:flaglis !:proplis); % To make properties and flags
                               % available in algebraic mode.

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
% gives the bag property to identifier or baglike-list of identifiers U
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
% gives the bag property to identifier or baglike-list of identifiers u
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
<<argnochk('kernlist . u);
if atom ( u:=reval car u) then nil else
if kernp mksq(u,1) then 'list . cdr u>> ;

put('kernlist,'psopfn,'rexplis);

symbolic procedure rlisbag u$
begin scalar x,prf;
argnochk('listbag . u);
x:=reval car u; prf :=reval cadr u;
if atom x then return nil else
<<simpbagprop list(prf,t) ; x:=prf . cdr x>>;
return x end;

symbolic put('rlisbag,'number!_of!_args,2);
symbolic put('listbag,'psopfn,'rlisbag);


symbolic procedure rfirst li;
<<argnochk('first . li);
  if bagp( li:=reval car li) then
  if null cdr li then car li . nil else  car li . cadr li . nil else
  if car li neq 'list then typerr(li,"list or bag")
  else if null cdr li then parterr(li,1)
  else cadr li>>$

put('first,'psopfn,'rfirst);

symbolic procedure rsecond li;
   <<argnochk ('second . li);
   if bagp( li:=reval car li) then
   if null cdr li or null cddr li then  car li . nil
    else  car li . caddr li . nil
   else if car li neq 'list then typerr(li,"list or bag")
   else if null cdr li or null cddr li then parterr(li,2)
   else caddr li>>;

put('second,'psopfn,'rsecond);

symbolic procedure rthird li;
   <<argnochk ('third . li);
     if bagp( li:=reval car li) then
    if null cdr li  or null cddr li or null cdddr li
    then car li . nil else  car li . cadddr li . nil
    else if car li neq 'list then typerr(li,"list or bag")
    else if null cdr li or null cddr li or null cdddr li
    then parterr(li,3)
    else cadddr li>>;

symbolic procedure rrest li;
<<argnochk('rest . li);
if bagp( li:=reval car li) then
if null cdr li then li . nil else  car li . cddr li  else
if car li neq 'list then typerr(li,"list or bag")
else 'list . if null (li:=cdr li) then li else cdr li>>$

symbolic put('rest,'psopfn,'rrest);

symbolic procedure rreverse u;
<<argnochk('reverse . u); u:=reval car u;
if bagp u then car u . reverse cdr u  else
if car u neq 'list  then typerr(u,"list or bag")
else 'list . reverse cdr u>>$

         put('reverse,'psopfn,'rreverse);

symbolic procedure rlast u;
<<argnochk('last . u); u:=reval car u;
if bagp u then if null cdr u then u else
    car u . car reverse cdr u . nil
 else if car u neq 'list  then typerr(u,"list or bag")
 else  if null cdr u then nil
 else car  reverse cdr u>>$

symbolic put('last,'psopfn,'rlast);

symbolic procedure rdc u;
if null cdr u then nil else car u . rdc cdr u;

symbolic procedure rbelast u;
<<argnochk('belast . u); u:=reval car u;
if bagp u then if null cdr u then u else car u . rdc cdr u else
if car u neq 'list then typerr(u,"list or bag")
else if null cdr u then u else 'list . rdc cdr u>>$

put('belast,'psopfn,'rbelast);

symbolic procedure rappend u;
   begin scalar x,y;
      argnochk ('append . u);
   if length u neq 2 then rederr("append has TWO arguments");
      x:=reval car u;
      y:=reval cadr u;
   if baglistp x and baglistp y  then
                     return car x . append(cdr x,cdr y) else
       typerr(list(x,y),"list or bag")
  end ;

put('rappend,'number!_of!_args,2);
put('append,'psopfn,'rappend);

symbolic procedure rcons u;
   begin scalar x,y;
      argnochk ('cons . u);
      if (y := getrtype(x := reval cadr u)) eq 'vector
        then return prepsq simpdot u
       else if y eq 'list
         then return  'list . reval car u . cdr x
       else if bagp x
         then return  car x . reval car u . cdr x
       else if fixp x
          then return x:=revalpart u
       else typerr(x,"list or bag")
   end;

symbolic put('rcons,'number!_of!_args,2);
symbolic put('cons,'setqfn,'setpart!*);
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
argnochk('remove . u);
x:=reval car u; n:=reval cadr u;
if baglistp x  then return car x . remove(cdr x,n) else
rederr(" first argument is a list or a bag, second is an integer")
 end;

symbolic put('rremove,'number!_of!_args,2);
symbolic put('remove,'psopfn,'rremove);

symbolic procedure rdelete u;
begin scalar x,y;
x:=reval car u; y:=reval cadr u;
if baglistp y then return delete(x,y) end;

symbolic put('delete,'psopfn,'rdelete);
% Use is delete(<any>,<bag or list>)

symbolic procedure rmember u;
% First argument is anything, second argument is a bag or list.
begin scalar x,y$
 argnochk('member . u);
 x:=reval car u;
 y:=reval cadr u;
if baglistp y then
              if (x:=member(x,cdr y))
              then return car y . x else return nil
 else typerr(y,"list or bag") end;

symbolic put('rmember,'number!_of!_args,2);
symbolic put('member,'psopfn,'rmember);

% INPUT MUST BE " member (any , < bag OR list> ) ".

symbolic procedure relmult u;
if length u neq 2 then
      rederr("elmult called with wrong number of arguments") else
begin scalar x,y; integer n;
 argnochk('elmult . u);
 x:=reval car u;  % It is the object the multiplicity of which one
                  % wants to compute.
 y:=reval cadr u; % IT IS THE list OR bag
if x=y then return 1 else
if baglistp y then
            <<y:=cdr y;
             while not null (y:=member(x,y)) do <<y:=cdr y;n:=n+1>>>>
         else typerr(y,"list or bag");
return n end;

symbolic put('relmult,'number!_of!_args,2);
symbolic put('elmult,'psopfn,'relmult);

% Use is  " elmult (any , < bag OR list> ) " .

symbolic procedure rpair u$
begin scalar x,y,prf$
argnochk('pair . u);
if length u neq 2 then
      rederr("pair called with wrong number of arguments");
x:=reval car u; y:=reval cadr u$
if not (baglistp x and baglistp y) then
                  rederr("arguments must be lists or bags") else
prf:=car x;x:=cdr x; y:=cdr y;
y:=pair(x,for each j in y collect list j);
return y:=prf . for each j in y collect prf . j  end;

symbolic put('rpair,'number!_of!_args,2);
symbolic put('pair,'psopfn,'rpair);

symbolic procedure depth!: u;
   if not atom u and (car u eq 'list or flagp(car u,'bag))
     then 1 + depth!: cadr u
    else 0;

symbolic procedure rdepth(u)$
% Use is depth(<BAG or LIST>).
begin scalar x; integer n;
argnochk('depth . u);
x := reval car u;
if nbglp(x,n:=depth!: x) then
     return n else return "bag or list of unequal depths" end;

put('depth,'psopfn,'rdepth);

symbolic procedure rinsert u;
% Use is insert(<any>, <list or bag>, <integer>).
begin scalar x,bg,bbg,prf; integer n;
argnochk('insert . u);
bg:=reval cadr u; n:=reval caddr u;
if not baglistp bg then typerr(bg,"list or bag") else
if n<=0 then rederr("third argument must be positive an integer") else
if (n:=n+1) > length bg then return append(bg,x:=list reval car u);
 prf:=car bg; x:=reval car u;
 for i:=3:n do <<bg:=cdr bg; bbg:=car bg . bbg>>;
 bbg:=reverse bbg;
 return bbg:=prf . append(bbg,cons(x,cdr bg))
 end;

symbolic put('insert,'number!_of!_args ,3);
symbolic put('insert,'psopfn,'rinsert);

symbolic procedure rposition u$
% Use is position(<any>,<LIST or BAG>).
begin scalar el,bg; integer n;
el:=reval car u;
if not baglistp (bg:=reval cadr u) then typerr(bg," list or bag");
n:=length( bg:=cdr bg);
if (bg:=member(el,bg))
             then return (n:=n+1-length bg)  else
 msgpri(nil,el,"is not present in list or bag",nil,nil) end;

put('rposition,'number!_of!_args,2);
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
argnochk('asfirst . u);
x:=reval car u; y:=reval cadr u;
if null baglistp y then typerr(y,"list or bag");
prf:=car y; y:=cdr y;
if null alistp y then typerr(y, "association list") else
    y:=for each j in y collect cdr j;
return  if null (y:=assoc(x,y)) then nil else prf . y   end;

symbolic put ('!:assoc,'number!_of!_args,2);
symbolic put('asfirst,'psopfn,'!:assoc);

% Use is : asfirst(<key>,<a-list>Y<a-bag>)

symbolic procedure !:rassoc u;
if length u neq 2 then
      rederr("assecond called with wrong number of arguments") else
begin scalar x,y,prf;
argnochk('assecond . u);
x:=reval car u; y:=reval cadr u;
if null baglistp y then typerr(y,"list or bag");
prf:=car y; y:=cdr y;
if null alistp y then typerr(y, "association list") else
    y:=for each j in y collect cdr j;
return  if null (y:=rassoc!*(x,y)) then nil else prf . y   end;

symbolic procedure rassoc!*(u,v);
   % Finds term in which U is the first term in the right part of a term
   % in the association list V, or NIL if term is not found.
   if null v then nil
    else if u = cadar v then car v
    else rassoc!*(u,cdr v);

symbolic put ('!:rassoc,'number!_of!_args,2);
symbolic put('assecond,'psopfn,'!:rassoc);

% Use is : assecond(<key>,<a-list>Y<a-bag>)

symbolic procedure !:assoc2 u;
if length u neq 2 then
      rederr("asrest called with wrong number of arguments") else
begin scalar x,y,prf;
argnochk('asrest . u);
x:=reval car u; y:=reval cadr u;
if null baglistp x or null baglistp y then
 typerr(list(x,y),"list or bag");
prf:=car y; y:=cdr y; x:=cdr x;
if null alistp y then typerr(y, "association list") else
    y:=for each j in y collect cdr j;
return  if null (y:=assoc2(x,y)) then nil else prf . y   end;

symbolic put ('!:assoc2,'number!_of!_args,2);
symbolic put('asrest,'psopfn,'!:assoc2);

% Use is : asrest(<key>,<a-list>Y<a-bag>)

symbolic procedure lastassoc!*(u,v);
% Use is :
% aslast(<key as a last element>,<a-list>Y<a-bag>)
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
argnochk('aslast . u);
x:=reval car u; y:=reval cadr u;
if null baglistp y then typerr(y,"list or bag");
prf:=car y; y:=cdr y;
if null alistp y then typerr(y, "association list") else
    y:=for each j in y collect cdr j;
return  if null (y:=lastassoc!*(x,y)) then nil else prf . y   end;

symbolic put ('!:lassoc,'number!_of!_args,2);
symbolic put('aslast,'psopfn,'!:lassoc);

symbolic procedure rasflist u;
% Use is :
% asflist(<key as a first element>,<a-list>Y<a-bag>)
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
% asslist(<key as the second element>,<a-list>Y<a-bag>)
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
% restaslist(<bag-like object containing keys>,<a-list>Y<a-bag>)
% Output is a list containing the values associated to the selected
% keys.
if length u neq 2 then
    rederr("restaslist called with wrong number of arguments") else
begin scalar x,y,yy,prf;
argnochk('sublis . u);
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

symbolic put('!:sublis,'number!_of!_args,2);
symbolic put('restaslist,'psopfn,'!:sublis);

% Use is :
% restaslist(<bag-like object containing keys>,<a-list>Y<a-bag>)
% Output is a list containing the values associated to the selected
% keys.
% ******* End of functions which may change bag- or list- prefixes.

% FOR SUBSTITUTION OF IDENTIFIERS IT IS CONVENIENT TO USE :

symbolic procedure !:subst u;
<<argnochk('substitute . u);
        reval subst(reval car u,reval cadr u,reval caddr u)>>;

symbolic put('!:subst,'number!_of!_args,3);
symbolic put('substitute,'psopfn,'!:subst);

% Use is : substitute(<newid>,<oldid>,<in any>).
% May serve to transform ALL bags into lists or vice-versa.

symbolic procedure !:repla u;
if length u neq 2 then
      rederr("repfirst called with wrong number of arguments") else
begin scalar x,y,prf;
 argnochk('repfirst . u);
y:=reval car u; x:= reval cadr u;
if null baglistp x then typerr(x,"list or bag");
prf:= car x; x:=cdr x;
return prf . rplaca(x,y) end;

symbolic put('!:repla,'number!_of!_args,2);
symbolic put('repfirst,'psopfn,'!:repla);

% Use is : repfirst(<any>, <bag or list>);

symbolic procedure !:repld u;
% Use is : replast(<any>, <bag or list>);
begin scalar x,y,prf;
 argnochk('represt . u);
if length u neq 2 then
      rederr("replast called with wrong number of arguments");
y:=reval car u; x:= reval cadr u;
if null baglistp x then typerr(u,"list or bag");
prf:= car x; x:=cdr x;
return prf . rplacd(x,list y) end;

symbolic put('!:repld,'number!_of!_args,2);
symbolic put('represt,'psopfn,'!:repld);

symbolic procedure rinsert u;
begin scalar x,bg,bbg,prf; integer n;
argnochk('insert . u);
bg:=reval cadr u; n:=reval caddr u;
if not baglistp bg then typerr(bg,"list or bag") else
if n<=0 then rederr("third argument must be positive integer") else
if (n:=n+1) > length bg then return append(bg,x:=list reval car u);
 prf:=car bg; x:=reval car u;
 for i:=3:n do <<bg:=cdr bg; bbg:=car bg . bbg>>;
 bbg:=reverse bbg;
 return bbg:=prf . append(bbg,cons(x,cdr bg))
 end;

symbolic put('insert,'number!_of!_args ,3);
symbolic put('insert,'psopfn,'rinsert);

% Use is : insert(<any>, <list or bag>, <integer>).

% HERE ARE FUNCTIONS FOR SETS.

symbolic procedure !:union u$
begin scalar x,y,prf;
argnochk('union . u);
if length u neq 2 then
      rederr("union called with wrong number of arguments");
x:=reval car u; y:=reval cadr u;
if baglistp x and baglistp y then
<<prf:=car y; y:=prf . union(cdr x,cdr y)>> else return nil;
return y end;

symbolic put('!:union,'number!_of!_args,2);
symbolic put('union,'psopfn,'!:union);

symbolic procedure setp u;
null repeats u;

symbolic flag('(setp),'boolean);

symbolic procedure !:mkset u$
if null u then nil else if member(car u,cdr u) then !:mkset cdr u
else car u . !:mkset cdr u$

symbolic procedure rmkset u;
begin scalar x,prf$
 argnochk('mkset . u); x:=reval car u; prf:=car x;
  if baglistp x then return prf . !:mkset cdr x end;

symbolic put('mkset,'psopfn,'rmkset);

symbolic procedure !:setdiff u$
begin scalar x,y,prf;
argnochk('diffset . u);
if length u neq 2 then
      rederr("diffset called with wrong number of arguments");
x:=reval car u; y:=reval cadr u;
if baglistp x and baglistp y then
<<prf:=car y; y:=prf . setdiff(cdr x,cdr y)>> else return nil;
return y end;

symbolic put('!:setdiff,'number!_of!_args,2);
symbolic put('diffset,'psopfn,'!:setdiff);

symbolic procedure !:symdiff u$
begin scalar x,y,prf;
argnochk('symdiff . u);
if length u neq 2 then
      rederr("symdiff called with wrong number of arguments");
x:=reval car u; y:=reval cadr u; prf:=car x;
if setp x and setp y then return
prf . append(setdiff(x:=cdr x,y:=cdr y),setdiff(y,x))
 end;

symbolic put('!:symdiff,'number!_of!_args,2);
symbolic put('symdiff,'psopfn,'!:symdiff);

symbolic procedure !:xn u$
begin scalar x,y,prf;
argnochk('intersect . u);
if length u neq 2 then
      rederr("intersect called with wrong number of arguments");
x:=reval car u; y:=reval cadr u;
if setp x and setp y then return car x . intersection(cdr x,cdr y)
 end;

symbolic put('!:xn,'number!_of!_args,2);
symbolic put('intersect,'psopfn,'!:xn);

endmodule ;

module genpurfunc;

%=====================================================================$
%                                                                     $
% VARIOUS GENERAL PURPOSE FUNCTIONS                                   $
%                                                                     $
%=====================================================================$

% 1. GENERALIZATION OF EXISTING FUNCTIONS


symbolic procedure mkidn(u)$
% generalizes "mkid" for any number of atoms
% Input is mkidn(list(a1,...ak)Ybag(a1,...,ak)).
expand(cdr u, 'mkid);

flag('(mkidn),'opfn);


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

symbolic procedure inf2(n,m);
if evalgreaterp(n,m) then m else n;

symbolic procedure sup2(n,m);
if evalgreaterp(n,m) then n else m;

symbolic procedure minlist u;
% Selects the smallest number in a list of numbers.
if null cdr u then nil else expand(cdr u,'inf2);

symbolic procedure maxlist u;
% Selects the biggest number from the list of numbers u .
if null cdr u then nil else expand(cdr u,'sup2);

flag('(inf2,sup2,minlist maxlist),'opfn);

flag('(prin2 ) ,'opfn); % To make it available in the alg. mode.


% 2. NEW ELEMENTARY FUNCTIONS CLOSELY RELATED TO EXISTING ONES.

symbolic procedure oddp u$
% Tests if integer U is odd. Is also defined in EXCALC;
fixp u and  remainder(u,2)=1$

symbolic procedure evenp  u;
not oddp u;

symbolic flag('(oddp evenp),'boolean);

symbolic procedure followline(n)$
% It allows to go to a new line at the position  given by the integer N.
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

symbolic procedure randomlist(n,trial);
% This procedure gives a list of trials in number "trial" of
% random numbers between 0 and n. For the algorithm see KNUTH vol. 2.
'list . lisp for j:=1:trial collect random n;

flag('(randomlist),'opfn);

symbolic procedure simpfact u;
begin scalar var; var:=reval cadr u;
if not (fixp var) or (var < 0) then return mksq(u,1)
else return fact!-num var . 1;
end;

symbolic procedure fact!-num n;   % simple factorial
%     then error(50,list(n,"invalid factorial argument"))
     if (n > 16) then facpart(1,n)
      else begin scalar m;
       m:=1;
       for i:=1:n do m:=m*i;
       return m;
     end;

symbolic procedure facpart (a,e);
    if a = e then a else
        if (e-1) = a then a * e else
            facpart(a,(a+e)/2) * facpart((a+e)/2 + 1,e);

put('fact,'simpfn,'simpfact);
flag('(fact), 'full);

algebraic procedure combnum(n,nu)$
% Number of combinations of n objects nu to nu.




























if nu>n then
rederr "second argument cannot be bigger than first argument"
else  fact(n)/fact(nu)/fact(n-nu)$

symbolic procedure rpermutation u;
<<argnochk('permutations . u); if not baglistp(u:=reval car u) then
nil else if null cdr u then 'list . nil  else
begin scalar x,prf$ prf:=car u$
    u:=cdr u$
    x:=for each j in  u
    conc  mapcons(permutations delete(j,u),j)$
    x:=for each j in x collect prf . j$
    return prf . x end>>;

put('permutations,'psopfn,'rpermutation);

symbolic procedure !:comb(u)$
begin scalar x,prf; integer n;
argnochk('combinations . u);
if length u neq 2 then
     rederr "combinations called with wrong number of arguments";
x:=reval car u ;  if not baglistp x then return nil ;
prf :=car x; x:=cdr x; n:=reval cadr u;
return prf . (for each j in comb(x,n) collect prf . j)
 end;

symbolic put('combinations,'psopfn,'!:comb);

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
% if null cdr aa then return car aa else
  if null cdr aa then return
      if flagp(car aa,'reserved) or flagp(car aa,'constant)
      then nil else car aa else
  aa:=!:mkset aa $ wi:=aa$
  while wi do if flagp(car wi ,'reserved) then
    <<aa:=delete(car wi ,aa)$ wi:=cdr wi >> else wi:=cdr wi $
  return aa:='list . aa end >>;

flag('(e i),'reserved);

symbolic procedure listofvars u $
if null u  or numberp u  then nil else
if atom u then list u else
varsinargs cdr u $

symbolic procedure varsinargs(u)$
if null u then nil else
append(listofvars car u,varsinargs cdr u)$

symbolic put('funcvar,'psopfn ,'rfuncvar);

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

% 4. FUNCTIONS TO DEAL WITH PROPERTIES IN THE ALGEBRAIC MODE.

global('(!:flaglis !:proplis));
symbolic(!:flaglis:=union(list list('bag,'bag),!:flaglis));

symbolic procedure putflag(u,flg,b)$
% Allows one to put or erase any FLAG on the identifier U.
% U is an idf or a list of idfs, FLAG is an idf, B is T or 0.
if not idp u and not null baglistp u then
              <<for each x in cdr u do putflag(x,flg,b)$ t>>
 else      if idp u and b eq t then
            <<flag(list u, flg)$
              !:flaglis:=union(list list(u, flg),!:flaglis)$ u>>
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
return 'list . aa end;

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

flag('(null idp flagp),'boolean);

symbolic procedure nordp(u,v);
% TRUE if a>b, FALSE if a=<b. NOT USED HERE.
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


 symbolic procedure remvar!:(u,v)$
 begin scalar buf,av$
     buf:=cdr inputbuflis!*$
     for each x in buf do if car (x:=cadr x) ='setk then
     begin scalar uu,xx$
       uu:=x;
     l1: if null cddr uu then return av$
         xx:=cadadr uu$
     if  gettype xx  eq v then
        av:=cons(xx,av)$
        uu:=caddr uu$
        go to l1  end$
    av:= !:mkset av$
    if null u then
    <<for each x in av do clear x$ return t>> else return av
     end$

flag('(displayvar displaylst displatscal),'noform);

symbolic  procedure displayvar$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
 remvar!:(t,'variable);

symbolic  procedure displayscal$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
 remvar!:(t,'scalar);

symbolic  procedure displaylst$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
  remvar!:(t,'list) $

symbolic procedure clearvar$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
remvar!:(nil,'variable)$

symbolic procedure clearscal$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
remvar!:(nil,'scalar)$

symbolic procedure clearlst$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
remvar!:(nil,'list)$

 symbolic procedure rema!:(u)$
% This function works to trace or to clear arrays.
 begin scalar buf,av$
     buf:=cdr inputbuflis!*$
     for each x in buf do if car(x:=cadr x) eq 'arrayfn then
     begin scalar uu,xx$
         uu:=cdaddr x$
     l1: if null uu then return av else
           if gettype (xx:=cadadr car uu ) eq 'array then
             av:=cons(xx,av);
         uu:=cdr uu$
         go to l1  end$
  av:= !:mkset av$
  if null u then
   <<for each x in av do clear x$ return t>> else return av
 end$

flag('(displayar),'noform);

symbolic  procedure displayar$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
 rema!:(t)$

symbolic procedure clearar$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
rema!:(nil)$

 symbolic procedure remsvar!:(u)$
 begin scalar buf,av$
     buf:=cdr inputbuflis!*$
     for each x in buf do if car (x:=cadr x) eq 'saveas then
        if  gettype (x:=cadr cadadr x)
                member list('scalar,' variable,'list)
         then av:=cons(x,av)$
     av:= !:mkset av$
    if null u then
    <<for each x in av do clear x$ return t>> else return av
     end$

 flag('(displaysavar),'noform);

symbolic  procedure displaysvar$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
remsvar!:(t) $

symbolic  procedure clearsvar$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
 remsvar!:(nil)$

 symbolic procedure remm!:(u)$
% This function works to trace or to clear matrices. Be CAREFUL to use
% the declaration MATRIX on input (not m:=mat(...) directly).
 begin scalar buf,av$
     buf:=cdr inputbuflis!*$
  for each x in buf do if  car(x:=cadr x) eq 'matrix  then
     begin scalar uu,xx$
         uu:=cdadr x$
     l1: if null uu then return av else
          if gettype(xx:=if length car uu = 2 then cadr car uu else
                       cadadr car uu) then
             av:=cons(xx,av);
         uu:=cdr uu$
         go to l1  end$
  av:= !:mkset av$
  if null u then
   <<for each x in av do clear x$ return t>> else return av
 end$

symbolic flag('(displaymat),'noform);

symbolic procedure displaymat$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
  remm!:(t)$

symbolic procedure clearmat$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
remm!:(nil)$

 symbolic procedure remv!:(u)$
% This function works to trace or to clear matrices.
 begin scalar buf,av$
     buf:=cdr inputbuflis!*$
  for each x in buf do if
              car(x:=cadr x) member list('vector,'tvector,'index)
         then
     begin scalar uu,xx$
         uu:=cdadr x$
     l1: if null uu then return av else
           if gettype(xx:=cadar uu) or get(xx,'fdegree) then
             av:=cons(xx,av);
         uu:=cdr uu$
         go to l1  end$
  av:= !:mkset av$
  if null u then
   <<for each x in av do clear x$ return t>> else return av
 end$

flag('(displayvec),'noform);

symbolic  procedure displayvec$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
remv!:(t) $

symbolic procedure clearvec$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
remv!:(nil)$

 symbolic procedure remf!:(u)$
% This function works to trace or to clear arrays.
 begin scalar buf,av$
     buf:=cdr inputbuflis!*$
     for each x in buf do if car(x:=cadr x) eq 'pform then
     begin scalar uu,xx$
         uu:=cdadr x$
     l1: if null uu then return av else
           if get(xx:=cadadr cdar uu ,'fdegree) or
              get(xx:=cadr cadadr cdar uu,'ifdegree) then
             av:=cons(xx,av);
         uu:=cdr uu$
         go to l1  end$
  av:= !:mkset av$
  if null u then
   <<for each x in av do clear x$ return t>> else return av
 end$

         flag('(displayform),'noform);

symbolic  procedure displayform$
% Allows to see all variables which have been assigned
% independently DIRECTLY ON THE CONSOLE. It does not work
% for assignments introduced THROUGH an input file;
 remf!:(t) $

symbolic procedure clearform$
% Allows to clear all user variables introduced
% DIRECTLY ON THE CONSOLE;
remf!:(nil)$

symbolic procedure clear!_all;
<<remvar!: (nil,'variable);remvar!: (nil,'scalar);
    remvar!:(nil,'list);remsvar!: nil;
       rema!: nil;remv!: nil;remm!: nil; remf!: nil ;t>>;

symbolic procedure show u;
begin u:=car u;
           if u member list('vectors,'tvectors,'indices)  then
                       return  displayvec() else
         if u eq 'variables  then return displayvar() else
         if u eq 'scalars then return displayscal() else
         if u eq 'lists  then return displaylst() else
         if u eq 'saveids  then return displaysvar() else
         if u eq 'matrices then return displaymat() else
         if u eq 'arrays then  return displayar() else
         if u eq 'forms then  return displayform() end;

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

% 3. Means to CLEAR operators and functions.

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
    if get(uu,'simpfn) then <<clearop uu; remprop(uu,'!:ft!:);
       remprop(uu,'!:gf!:)>> else
    if get(uu,'psopfn) then remprop(uu,'psopfn) else
    if get(uu,'expr) then remprop(uu,'expr) else
    if get(uu,'subr) then remd uu$
    remprop(uu,'stat);
    remprop(uu,'dfn);
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

module polyextensions;

%=====================================================================

% ADDITIONAL FUNCTIONS FOR POLYNOME AND RATIONAL EXPRESSION
% MANIPULATIONS.

%=====================================================================

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
%else if peq(lpow u,lpow v) or ordpp(lpow u,lpow v)
else if ordpp(lpow u,lpow v)
then lt u .+ addfd(red u,v)
else lt v .+ addfd (u,red v);


symbolic procedure distribute u;
% Gives a polynome in distributed form in the algebraic mode.
list('!*sq,distri!_pol numr simp!* u  ./ 1,t);

flag('(distribute),'opfn);

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
                        <<x:=multf(!*p2f lpow y,x); y:=lc y>>;
 if atom y then return multf(x,y) else
 return
 addfd(distri!_pol multf(x,distri!_pol !*t2f lt y),
       distri!_pol multf(x,distri!_pol red y))

end;

symbolic procedure leadterm u;
<<u:=simp!* u; if !*distribute  then u:=distri!_pol numr u ./ denr u
  else u; if domainp u then mk!*sq u
  else  mk!*sq(!*t2f lt numr u ./ denr u)>>;

flag('(leadterm redexpr ),'opfn);
flag('(leadterm redexpr ),'noval);

symbolic procedure redexpr u;
<<u:=simp!* u; if !*distribute  then u:=distri!_pol numr u ./ denr u
  else u; if domainp u then mk!*sq(nil ./ 1) else
  mk!*sq( red numr u ./ denr u)>>;

symbolic procedure list!_of!_monom u;
% It takes a polynomial in distributive form.
% returns a list of monoms.
% u is numr simp!* (algebraic expression)
if domainp u then u else
begin scalar exp,lmon,mon;
     exp:=u;
l:  if null exp then return lmon ;
      mon:=lt exp;
    lmon:=(!*t2f mon ) . lmon;
     exp:=red exp;
     go to l;
end;

symbolic procedure monomterm y;
begin scalar x;
x:=numr simp!* y;
x:=distri!_pol x;
x:=list!_of!_monom x;
x:=for each m in x collect mk!*sq(m ./ 1);
return 'list . x end;

algebraic procedure monom(u);
% Use: monom <polynome>
begin scalar x,xx;
xx:= lisp monomterm u ;
return xx
end;

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
% IT EXTRACTS THE LOWEST DEGREE IN V OF THE POLYNOMIAL U.
begin scalar x,y,uu,vv,mvy$
    uu:=simp!* u$
    if domainp uu then return 0$
    uu:=!*q2f uu;
    vv:=!*a2k v$
    x:=setkorder list v$
    y:=reorder uu$ setkorder x$
    y:=reverse y$y$
    if fixp y then return 0$
    mvy:=mvar y$
    if not atom mvy then if car mvy eq 'expt then
         rederr("exponents must be integers")$
    if mvy neq vv then return 0 else
         return  ldeg y end$

flag('(lowestdeg),'opfn)$

endmodule;


module transfunctions;

algebraic;

algebraic procedure trigexpand(wws);
begin scalar aa,ratsav; %ratsav:=rational;
  % if rational=0 then on rational;
    aa:=wws;
    for all x,y let
                   sin(x+y)=sin(x)*cos(y)+cos(x)*sin(y),
                   cos(x+y)=cos(x)*cos(y)-sin(x)*sin(y);
    for all x,n such that fixp n and n>1 let
                   sin(n*x)=sin(x)*cos((n-1)*x)+cos(x)*sin((n-1)*x),
                   cos(n*x)=cos(x)*cos((n-1)*x)-sin(x)*sin((n-1)*x);
    aa:=aa;
    for all x,y clear cos(x+y),sin(x+y);
    for all x,n such that fixp n and n>1 clear sin(n*x),cos(n*x);
    return aa end;

algebraic procedure hypexpand(wws);
begin scalar aa,ratsav; %ratsav:=rational;
 aa:=wws;
 for all x,y let
                sinh(x+y)=sinh(x)*cosh(y)+cosh(x)*sinh(y),
                cosh(x+y)=cosh(x)*cosh(y)+sinh(x)*sinh(y);
 for all x,n such that fixp n and n>1 let
                sinh(n*x)=sinh(x)*cosh((n-1)*x)+cosh(x)*
                 sinh((n-1)*x),
                cosh(n*x)=cosh(x)*cosh((n-1)*x)+sinh(x)*
                 sinh((n-1)*x);
    aa:=aa;
    for all x,y clear cosh(x+y),sinh(x+y);
    for all x,n such that fixp n and n>1 clear sinh(n*x),cosh(n*x);
    return aa end;


operator !#ei!&; !#ei!&(0):=1;

for all x,n let !#ei!&(x)**n=!#ei!&(n*x);
for all x,y let !#ei!&(x)*!#ei!&(y)=!#ei!&(x+y);

algebraic procedure trigreduce(wws);
    begin scalar aa;aa:=wws;
    for all x let cos(x)=(!#ei!&(x)+!#ei!&(-x))/2,
                  sin(x)=-i*(!#ei!&(x)-!#ei!&(-x))/2;
    aa:=aa;
    for all x clear cos(x),sin(x);
    for all x let !#ei!&(x)=cos(x)+i*sin(x);
    aa:=aa;
    for all x clear !#ei!&(x);
    return aa end;

algebraic procedure hypreduce(wws);
    begin scalar aa;aa:=wws;
    for all x let cosh(x)=(!#ei!&(x)+!#ei!&(-x))/2,
                  sinh(x)=(!#ei!&(x)-!#ei!&(-x))/2;
    aa:=aa;
    for all x clear cosh(x),sinh(x);
    for all x let !#ei!&(x)=cosh(x)+sinh(x);
    aa:=aa;
    for all x clear !#ei!&(x);
    return aa end;

algebraic procedure logplus(wws);
begin scalar aa;
    aa:=wws;
    for all x,n let
       log(x/n)=log(x)-log(n),
       log(x*n)=log(x)+log(n),
       log(sqrt(x))=1/2*log(x),
       log(x**n)=n*log(x);
    aa:=aa;
    for all x,n clear log(x/n),log(x*n),log(sqrt(x)),log(x**n);
   return aa end;

algebraic procedure concsumlog (exp);
if den exp neq 1 then concsumlog(num exp)/concsumlog(den exp) else
 begin scalar ex; ex:=exp;
% realizes the concatenation of "sum over i c(i)*log x(i)".
operator e!_log!_conc;

for all x,y,z let
                  log(x*e!_log!_conc(y)/z)=log(x/z)+y,
                  log(x*e!_log!_conc(-y)/z)=log(x/z)-y,
                  log(x*e!_log!_conc(-y))=log(x)-y,
                  log(x*e!_log!_conc(y))=log(x)+y,
                  log(e!_log!_conc(y))=y;

for all a,x,y let
                  e!_log!_conc(-a*log(x)) = 1/x**a,
                  e!_log!_conc(a*log (x)) = x**a,
                  e!_log!_conc(-log x)=1/x,
                  e!_log!_conc(log x)=x,
                  e!_log!_conc(x+y)=e!_log!_conc(x)*e!_log!_conc(y);

 ex:=log e!_log!_conc(ex);

for all x,y,z clear
                log(x*e!_log!_conc(y)/z),
                log(x*e!_log!_conc(-y)/z),
                log(x*e!_log!_conc(-y)),
                log(x*e!_log!_conc(y)),
                log(e!_log!_conc(y));

for all a,x,y clear
                  e!_log!_conc(-a*log(x)),
                  e!_log!_conc(a*log (x)) ,
                  e!_log!_conc(-log x),
                  e!_log!_conc(log x),
                  e!_log!_conc(x+y);

clearop e!_log!_conc;

return ex end;

symbolic;

endmodule;

module vectoroper;

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
argnochk('sumvect . u);
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
argnochk('minvect . u);
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
argnochk('scalvect . u);
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
<<% implemented only with LIST prefix;
 argnochk('crossvect . u);
'list . (for each j in !:pvect3 u collect mk!*sq j)>>;

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





module matrext;

% This module defines additional utility functions for manipulating
% matrices.  Coercions to BAG and LIST structures are defined.

symbolic procedure natnumlis u;
   % True if U is a list of natural numbers.
   % Taken from MATR.RED for bootstrap purpose.
   null u
      or numberp car u and fixp car u and car u>0 and natnumlis cdr u;

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
if atom op then if not (y:=gettype op) then put(op,'rtype,'matrix) else
typerr(list(y,op),"matrix");
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
<< if idp s or length (l:= revlis cdr s) neq 1 or not natnumlis l
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
% This function allows to extract the row N from the matrix A and
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
% This function allows to extract the row N from the matrix A and
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

end;
