module traverso;

% Buchberger algorithm base on "sugar" strategy
%  see Giovini-Mora-Niesi-Robbiano-Traverso:
%   One sugar gube, please. ISSAC 91 proceddings, pp 49-54 

fluid '(!*gtraverso!-sloppy !*gsugar);

!*gtraverso!-sloppy := t;

symbolic procedure gtraverso (g0,fact,groebres,abort1);
  begin scalar g,d,s,h,p,!*gsugar;

    fact := nil; groebres := nil; abort1 := nil;

    !*gsugar := t;

    g0:=for each fj in g0 join
          if not vdpzero!? fj then
          <<groebsavelterm fj;
               {gsetsugar(vdpenumerate vdpsimpcont fj,nil)}>>;

  main_loop:
    if null g0 and null d then return gtraverso!-final g;

    if g0 then 
         <<h:=car g0;g0:=cdr g0;
           p := list(nil,h,h)
         >>
       else
         <<p := car d;
           d := cdr d;
           s := groebspolynom (cadr p, caddr p);
                  !*trgroeb and groebmess3 (p,s);
           h:=groebsimpcontnormalform groebnormalform(s,g,'list);
           if vdpzero!? h then 
           <<!*trgroeb and groebmess4(p,d); goto main_loop>>;

            if vevzero!? vdpevlmon h then % base 1 found
                  <<   !*trgroeb and groebmess5(p,h);
                       d:=g:=g0:=nil;
                  >>;       
         >>;

         h := groebenumerate h; !*trgroeb and groebmess5(p,h);
         groebsavelterm h;

          % new pair list
         d := gtraverso!-pairlist(h,g,d);
          
          % new basis
         g := nconc(g,{h});
         goto main_loop;
   end;

symbolic procedure gtraverso!-pairlist(gk,g,d);
  % gk: new polynomial,
  % g:  current basis,
  % d:  old pair list.
  begin scalar ev,r,n,nn,q;
     % delete triange relations from old pair list.
    d := gtraverso!-pairs!-discard1(gk,d);

     % build new pair list.
    ev := vdpevlmon gk;
    for each p in g do
     if not groebbuchcrit4t(ev,vdpevlmon p) 
       then r := vevlcm(ev,vdpevlmon p).r
       else n := groebmakepair(p,gk) . n;
  
     % delete from new pairs equivalents to coprime lcm.
    for each q in r do
     for each p in n do
      if car p=q then n:=delete(p,n);

     % discard multiples: collect survivers in n
    if !*gtraverso!-sloppy then !*gsugar:=nil;
    n := groebcplistsort(n);
    !*gsugar := t;   

    nn := n; n:=nil;
    for each p in nn do
    <<q:=nil;
      for each r in n do 
        q:=q or vevdivides!?(car r,car p);
      if not q then n:=groebcplistsortin(p,n);
    >>;

    return groebcplistmerge(d,reversip n);
  end;

symbolic procedure gtraverso!-pairs!-discard1(gk,d);
  % crit B 
  begin scalar gi,gj,tij,evk;
   evk:=vdpevlmon gk;
   for each pij in d do
   <<tij := car pij; gi:=cadr pij; gj:=caddr pij;
    if vevstrictlydivides!?(tt(gi,gk),tij)
       and vevstrictlydivides!?(tt(gj,gk),tij)
      then d:=delete(pij,d);
   >>;
   return d;
  end;

symbolic procedure vevstrictlydivides!?(ev1,ev2);
   not(ev1=ev2) and vevdivides!?(ev1,ev2); 

symbolic procedure gtraverso!-final g;
  % final reduction and sorting;
  begin scalar r,p,!*gsugar;
   g:=vdplsort g; % descending
   while g do
   <<p:=car g; g:=cdr g;
     if not groebsearchinlist(vdpevlmon p,g) then
       r := groebsimpcontnormalform groebnormalform(p,g,'list) . r;
   >>;
   return list reversip r;
  end;

endmodule;

end;


