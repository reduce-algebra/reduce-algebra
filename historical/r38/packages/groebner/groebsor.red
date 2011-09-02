module groebsor;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Maintenance of lists of critical pairs(sorting etc .).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure groebcplistsortin(p,pl);
% Distributive polynomial critical pair list sort. pl is a
% special list for Groebner calculation, p is a pair.
% Returns the updated list pl(p sorted into).
 if null pl then list p else
 <<groebcplistsortin1(p,pl);pl>>;

symbolic procedure groebcplistsortin1(p,pl);
% Destructive insert of ' p ' into nonnull ' pl ' .
 if not groebcpcompless!?(car pl,p)
  then <<rplacd(pl,car pl . cdr pl);rplaca(pl,p)>>
   else if null cdr pl then rplacd(pl,list p)
   else groebcplistsortin1(p,cdr pl);

symbolic procedure groebcplistsort g;
 <<for each p in g do gg:=groebcplistsortin(p,gg);gg>> where gg=nil;

symbolic procedure groebcplistmerge(pl1,pl2);
% Distributive polynomial critical pair list merge. pl1 and pl2
% are critical pair lists used in the Groebner calculation.
% groebcplistmerge(pl1,pl2) returns the merged list.
begin scalar cpl1,cpl2,sl;
 if null pl1 then return pl2;
 if null pl2 then return pl1;
 cpl1:=car pl1;cpl2:=car pl2;
 sl:=groebcpcompless!?(cpl1,cpl2);
 return(if sl then cpl1 . groebcplistmerge(cdr pl1,pl2)
  else cpl2 . groebcplistmerge(pl1,cdr pl2)) end;

symbolic procedure groebcpcompless!?(p1,p2);
% Compare 2 pairs wrt their sugar(=cadddr) or their lcm(=car).
 if !*gsugar then
 (if not(d=0)then d < 0 else if not(q=0)then q < 0 else
   vdpnumber(caddr p1)< vdpnumber(caddr p2)
  ) where d=cadddr p1 - cadddr p2,q=vevcomp(car p1,car p2)
  else vevcompless!?(car p1,car p2);

endmodule;;end;
