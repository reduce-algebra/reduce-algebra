module hidden;

% Author: James H. Davenport.

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


fluid '(!*trint
        !*trjhd
        cancellationlist
        equalitystack
        hide
        indexlist
        indexmap
        inequalitystack
        lastreduction
        nindex
        popstack
        rhs
        ulist);

exports hiddentermgenerators;
imports interr,nextprime,mksp,addf,getv,!*multf,printsf,gcdf,quotf,negf;
imports makeprim,prin2,mkvect,copyvec,printdf;


% Package for dealing with linear subspaces defined
% by both equalities and inequalities


% Major datastructure -
% An equation is stored in a vector of length (length indexlist)
% elements 2::n are the coeffs of the various index quantities
% element 1 is constant part
% element 0 is number defining a pivot in the row
%
% all vector elements are standard forms

symbolic procedure newspace;
 begin scalar w;
    indexmap:=nil;
    nindex:=1;
    w:=indexlist;
    while w do <<
        nindex:=nindex+1;
        indexmap:=(car w . nindex) . indexmap;
        w:=cdr w >>;
    popstack:=equalitystack:=inequalitystack:=nil;
    if !*trint then printc "New space set up"
 end;

symbolic procedure currentspace;
% Picks up the current set of linear constraints so they can be stored
    (equalitystack . inequalitystack) . popstack;

% Restores a space saved by 'currentspace'
symbolic procedure setlinspace a;
 << popstack:=cdr a;
    a:=car a;
    equalitystack:=car a;
    inequalitystack:=cdr a;
    nil >>;


symbolic procedure newequation(eqqn,notflag);
% Declare the equation
%    eqqn=0
% (or if notflag is set)    eqqn ne 0
% to hold in addition to all previously declared relationships
% return 'inconsistent if this is not possible
 begin scalar newrow,newpivot,q1,r;
    if !*trint then <<
       prin2 "New ";
       if notflag then prin2 "in";
       printc "equality";
       printsf eqqn >>;
    if inequalitystack='inconsistent then interr "double inconsistency";
    popstack:=(equalitystack . inequalitystack) . popstack;
    newrow:=mkvect nindex; % Space for new row in eqqnstack
%   for i:=0:nindex do putv(newrow,i,nil); %set to zero
    expandinto(newrow,eqqn,1);
    makeprim(newrow,nindex); % Remove any common factors
    mapc(reverse equalitystack,function lambda j;
      eliminatewith(newrow,j));
    newpivot:=0;
    for i:=2:nindex do
      if getv(newrow,i) neq nil then newpivot:=i;
    if newpivot=0 then
       if (getv(newrow,1)=nil)=notflag then go to contradict
         else return 'redundant;
    putv(newrow,0,newpivot);
    if notflag then <<
      inequalitystack:=newrow . inequalitystack;
      if !*trint then printc "New inequality added";
      return 'consistent! inequality >>;
    equalitystack:=newrow . equalitystack;
    q1:=inequalitystack;
    inequalitystack:=nil;
wind:
    if q1=nil then return 'consistent! equality;
    r:=copyvec(car q1,nindex);
    q1:=cdr q1;
    eliminatewith(r,newrow);
    newpivot:=0;
    for i:=2:nindex do
      if getv(r,i) neq nil then newpivot:=i;
    if newpivot neq 0 then go to ok;
    if getv(r,1)=nil then go to contradict;
    go to wind;
contradict:
    equalitystack:=inequalitystack:='inconsistent;
    return 'inconsistent;
ok: putv(r,0,nil);
    makeprim(r,nindex);
    inequalitystack:=r . inequalitystack;
    go to wind
 end;

symbolic procedure expandinto(row,val,above);
    if domainp val then putv(row,1,addf(getv(row,1),!*multf(val,above)))
    else begin scalar x;
      x:=atsoc(mvar val,indexmap); % Process leading term first
      if x then << x:=cdr x;
        if not (tdeg lt val = 1) then
          interr "not linear in expandinto";
        putv(row,x,addf(getv(row,x),!*multf(lc val,above))) >>
    else expandinto(row,lc val,!*multf(above,((lpow val) .* 1) .+ nil));
    return expandinto(row,red val,above)
 end;

symbolic procedure eliminatewith(newrow,oldrow);
   begin scalar pivotx,p,q;
    pivotx:=getv(oldrow,0);
    p:=getv(newrow,pivotx);
    if p=nil then return nil; %Nothing needs doing
    q:=getv(oldrow,pivotx);
    begin scalar gg;
      gg:=gcdf(p,q);
      p:=quotf(p,gg);
      q:=negf quotf(q,gg) end;
    for i:=1:nindex do
      putv(newrow,i,addf(!*multf(getv(newrow,i),q),
                         !*multf(getv(oldrow,i),p)));
    pivotx:=getv(newrow,0);
    putv(newrow,0,nil);
    makeprim(newrow,nindex);
    putv(newrow,0,pivotx);
    return nil
   end;

symbolic procedure dropequation;
   begin
    if atom popstack then interr "popstack underflow";
    equalitystack:=caar popstack;
    inequalitystack:=cdar popstack;
    popstack:=cdr popstack
   end;


symbolic procedure printlinspace();
 begin if equalitystack='inconsistent then <<
      printc "never happens";
      return nil >>;
    if equalitystack=nil then
      printc "no equalityies active"
    else << printc "subject to"; printeqns equalitystack >>;
    if atom inequalitystack then return nil;
    printc "except when";
    printeqns inequalitystack;
    return nil end;

symbolic procedure printeqns l;
 begin while l do <<
      printsf vec2sf(car l,indexmap);
      terpri();
      l:=cdr l >>;
    terpri();
    return nil end;

symbolic procedure vec2sf(x,indexmap);
 begin scalar r;
    r:=getv(x,1); % constant part
    for i:=2:nindex do begin
        scalar v;
        v:=indexmap;
        while not (i=cdar v) do v:=cdr v;
        v:=caar v;
        v:=(mksp(v,1) .* 1) .+ nil;
        r:=addf(r,!*multf(v,getv(x,i))) end;
    return r end;





symbolic procedure hiddentermgenerators(rhs);
 begin scalar p,q,reductions;
    cancellationlist:=nil;
    hide:=nil;
    newspace(); %Init linear subspace package
    eliminateconstofint();
    reductions:=constrainedreductions rhs;
    if !*trint then mapc(reductions,function printreduction);
    lastreduction:=lvlast reductions;
    p:=cdr reductions;
    while p do <<
        q:=reductions;
        while not (p eq q) do <<
            interfere(car p,car q); %May extend reductions list
            q:=cdr q >>;
        p:=cdr p >>;
    return nil
   end;




symbolic procedure lvlast l;
    if null l then interr "l=nil in lvlast"
    else if null cdr l then l
    else lvlast cdr l;

%symbolic procedure newreduction a;
%% Record a new reduction formula
%  begin
%    a:=list a;
%    rplacd(lastreduction,a);
%    lastreduction:=a
%   end;

symbolic procedure eliminateconstofint();
% Set up an inequality that gets rid of the constant of
% integration but no other positive terms. maybe this is
% done by a fudge.....
 begin scalar p,r,m,v,x;
    x:=indexlist;
    p:=lpow ulist;
% (a) find largest value in this thing
    m:=0;
    while p do << m:=max(m,car p); p:=cdr p >>;
    v:=0;
    p:=lpow ulist;
% now allocate a prime number > m to each index
    while p do <<
        m:=nextprime m;
        r:=addf(r,(mksp(car x,1) .* m) .+ nil);
        x:=cdr x;
        v:=v-m*car p;
        p:=cdr p >>;
    if not(v=0) then r:=addf(r,v);
    newequation(r,t); %Assert the inequality
    return nil
  end;

symbolic procedure constrainedreductions rhs;
 begin scalar rels,fg;
top:
    if rhs=nil then return reversewoc rels;
    fg:=newequation(numr lc rhs,t); %non-zero leading term
    if not(fg='inconsistent) then
        rels:=(rhs . currentspace()) . rels;
    dropequation();
    fg:=newequation(numr lc rhs,nil); %now lt = 0
    if fg='inconsistent then return reversewoc rels;
    rhs:=red rhs;
    go to top end;

symbolic procedure printreduction a;
 begin
    printc "**** REDUCTION FORMULA ****";
    printdf car a;
    setlinspace cdr a;
    printlinspace()
 end;

symbolic procedure interfere(a,b);
 begin
   if !*trjhd then printc "potential cancellation detected"
 end;


%**********************************************************************;
% From here down I have code left over from the previous version


%symbolic procedure shiftmatch(form,p1,p2);
%    sfsublis(form,shiftassoc(p1,p2,indexlist));

%symbolic procedure shiftassoc(p1,p2,l);
%    if null l then nil
%    else ((car l) . (caar p1 - caar p2)) .
%                         shiftassoc(cdr p1,cdr p2,cdr l);


%symbolic procedure sfsublis(fm,l);
%    if domainp fm then fm
%    else begin
%      scalar w;
%      w:=atsoc(mvar fm,l);
%      if w neq nil then <<
%        w:=cdr w;
%        if w=0 then w:=nil >>;
%      w:=(mksp(mvar fm,1) .* 1) .+ w;
%      w:=!*multf(w,sfsublis(lc fm,l));
%      return addf(w,sfsublis(red fm,l)) end;





%symbolic procedure constantofintegration();
% begin scalar n;
%    if not null inequalitystack then return nil;
%%To be recognized, the term here must be totally constrained
%%by equalities, and must match the c of i already set in ulist
%    n:=length equalitystack;
%    if not (n=nindex-1) then return nil;
%    return matchp(lpow ulist,equalitystack,inequalitystack) end;


%symbolic procedure dfsublis(p,l);
%    dfsublis1(p,l,mapcar(l,function cdr));

%symbolic procedure dfsublis1(p,l1,l2);
%    if null p then nil
%    else (lambda coef,rest;
%      if null coef then rest else
%        (pluslists(lpow p,l2) .* (coef ./ denr lc p)) .+ rest)
%      (sfsublis(numr lc p,l1),dfsublis1(red p,l1,l2));

%symbolic procedure pluslists(l1,l2);
%    if null l1 then nil
%    else ((caar l1 + car l2) . nil) . pluslists(cdr l1,cdr l2);


%symbolic procedure invertclashes();
% begin
%    cancellationlist:=nil;
%    mapc(hide,function clash);
%    mapc(cancellationlist,function printcancel);
% end;

%symbolic procedure printcancel l;
% begin
%    equalitystack:=caar l;
%    inequalitystack:=cdar l;
%    printc "A phantom may be needed when the leading term satisfies";
%    printlinspace();
%    printc "offsets =";
%    mapc(cdr l,function printc);
%    terpri()
% end;


%symbolic procedure clash(a);
%% A is the structure ((a . b) . (equal . inequal))
%% create a corresponding entry on calcellationlist
% begin
%    scalar rf1,rf2,lineq;
%    lineq:=cdr a;
%    rf1:=caar a;
%    rf2:=cdar a;
%    a:=plusdf(red rf1,red rf2);
%% Now lt a is maybe important term left over
%    lineq:=shifteqns(car lineq,unlist lpow a) .
%             shifteqns(cdr lineq,unlist lpow a);
%    a:=formdeltas(lpow a,lpow rf1);
%    cancellationlist:=(lineq . list a) . cancellationlist;
%    return nil
% end;

%symbolic procedure unlist l;
%    if null l then nil
%    else caar l . unlist cdr l;


%symbolic procedure formdeltas(a,b);
%    if null a then nil
%    else (caar a - caar b) . formdeltas(cdr a,cdr b);

%symbolic procedure shifteqns(l,delta);
%    if null l then nil
%    else shifteqn(car l,delta) . shifteqns(cdr l,delta);


%symbolic procedure shifteqn(v,delta);
% begin scalar w,i,new;
%    new:=mkvect nindex;
%    for i:=0:nindex do putv(new,i,getv(v,i));
%    v:=new;
%    i:=2;
%    w:=nil;
%    while delta do <<
%        w:=addf(w,!*multf(getv(v,i),car delta));
%        delta:=cdr delta >>;
%    putv(v,1,addf(getv(v,1),negf w));
%    return v
% end;

endmodule;

end;

