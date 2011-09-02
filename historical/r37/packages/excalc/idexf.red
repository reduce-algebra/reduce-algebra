module idexf;

% Author: Eberhard Schruefer

global '(exfideal!*);

symbolic procedure exterior!-ideal u;
   begin scalar x,y;
     rmsubs();
     for each j in u do
       if indexvp j then
	  for each k in mkaindxc(y := flatindxl cdr j,nil) do
             x := partitsq(simpindexvar(car j . subla(pair(y,k),cdr j)),
                           'wedgefp) . x
        else x := partitsq(simp!* j,'wedgefp) . x;
     exfideal!* := append(x,exfideal!*);
   end;

rlistat '(exterior!-ideal);

symbolic procedure remexf(u,v);
   begin scalar lu,lv,x,y,z;
     lv := ldpf v;
     a: if null u or domainp(lu := ldpf u) then
           return u;
        if x := divexf(lu,lv) then
         <<y := partitsq(simp list('wedge,prepf v,x),'wedgefp);
           z := negsq quotsq(lc u,lc y);
           u := addpsf(u,multpsf(1 .* z .+ nil,y))>>
         else return u;
        go to a
   end;

symbolic procedure divexf(u,v);
   begin scalar x,y;
     x := prepf u;
     y := prepf v;
     if atom x then x := list x
      else if car x eq 'wedge then x := cdr x;
     if atom y then y := list y
      else if car y eq 'wedge then y := cdr y;
     a: if null y then return 'wedge . x;
        if null(x := delform(car y,x)) then return nil;
        y := cdr y;
        go to a
   end;

symbolic procedure delform(u,v);
   delform1(u,v,nil);

symbolic procedure delform1(u,v,w);
   if null v then nil
    else if u = car v then if w or cdr v
                              then append(reverse w,cdr v)
                            else list 1
    else delform1(u,cdr v,car v . w);

symbolic procedure exf!-mod!-ideal u;
   begin
     for each j in exfideal!* do u := remexf(u,j);
     return u
   end;

endmodule;

end;
