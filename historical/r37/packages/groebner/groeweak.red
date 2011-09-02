module groeweak; % weak test for f ~ 0 modulo G


fluid '(!*groebweak current!-modulus pairsdone!* !*vdpInteger
         groebmodular!* !*groebfac);
switch groebweak;

symbolic procedure groebweakzerotest(f,G,type);
     % test f==0 modulo G with ON MODULAR
  begin scalar f1,c,vev,divisor,oldmode,a;
      if vdpzero!? f then return f;
      if current!-modulus= 1 then setmod list 2097143;
      oldmode := setdmode('modular,t);
      f := groebvdp2mod f;
      f1 := vdpzero(); a:= vbcfi 1;
      while not vdpzero!? f and vdpzero!? f1 do
          begin    
            vev:=vdpevlmon f; c:=vdpLbc f;
            if type = 'sort then
                 while g
                       and vevcompless!? (vev,vdpevlmon (car g))
                            do g := cdr g;
            divisor :=
               if type = 'tree then groebsearchinstree(vev,g)
                               else groebsearchinlist (vev,g);
            if divisor and !*trgroebs then
                       << prin2 "//m-";
                          prin2 vdpnumber divisor >>;
            if divisor then
                      if vdplength divisor = 1 then
                            f := vdpcancelmvev(f,vdpevlmon divisor)
                          else
                           <<divisor := groebvdp2mod(divisor);
                            if divisor then f := 
                              groebreduceonesteprat(f,nil,c,vev,divisor)
                            else f1 := f>>
               else
                    f1 := f;
          end;   
      if not vdpzero!? f1 and !*trgroebs then
       <<prin2t " - nonzero result in modular reduction:";
         vdpprint f1 >>;
      setdmode('modular,nil);
      if oldmode then setdmode(get(oldmode,'dname),t);
      return vdpzero!? f1;
   end;

smacro procedure tt(s1,s2);
  % lcm of leading terms of s1 and s2
       vevlcm(vdpevlmon s1,vdpevlmon s2);

symbolic procedure groebweaktestbranch!=1(poly,g,d);
     % test GB(G) == {1} in modular style
       groebweakbasistest(list poly,g,d);

symbolic procedure groebweakbasistest(g0,g,d);
    begin scalar oldmode,d,d1,d2,p,p1,s,h;
      scalar !*vdpinteger;     % switch to field type calclulation
      return nil;
      if not !*groebfac then return nil;
      if current!-modulus= 1 then setmod list 2097143;
       if !*trgroeb then
          prin2t "---------------- modular test of branch ------";
      oldmode := setdmode('modular,t);
      g0 := for each p in g0 collect groebvdp2mod p;
      g := for each p in g collect groebvdp2mod p;
      d := for each p in d collect list (car p,
             groebvdp2mod cadr p, groebvdp2mod caddr p);
      while d or g0 do
       begin
          if g0 then
          <<          % take next poly from input
               h := car g0; g0 := cdr g0; p := list(nil,h,h) >>
             else
          <<          % take next poly from pairs
               p := car d;
               d := delete (p,d);
               s := groebspolynom (cadr p, caddr p);
               h:=groebsimpcontnormalform groebnormalform(s,g,'sort);
                  if vdpzero!? h then !*trgroeb and groebmess4(p,d);
          >>;
          if vdpzero!? h then 
              <<pairsdone!* := (vdpnumber cadr p . vdpnumber caddr p)
                              . pairsdone!*;
                goto bott>>;
          if vevzero!? vdpevlmon h then % base 1 found
                  <<         !*trgroeb and groebmess5(p,h);
                   goto stop>>;
          s:= nil;
          h := vdpenumerate h; !*trgroeb and groebmess5(p,h);
                              % construct new critical pairs
          d1 := nil;
          for each f in g do
                    <<d1 := groebcplistsortin(list(tt(f,h),f,h),d1);
                      if tt(f,h) = vdpevlmon(f) then
                              <<g := delete (f,g); 
                                !*trgroeb and groebmess2 f>>;
                      >>;
                  !*trgroeb and groebmess51(d1);
          d2 := nil;
          while d1 do
                  <<d1 := groebinvokecritf d1;
                    p1 := car d1; d1 := cdr d1;
                    d2 := groebinvokecritbuch4 (p1,d2);
                    d1 := groebinvokecritm (p1,d1) >>;
          d := groebinvokecritb (h,d);
          d := groebcplistmerge(d,d2);
          g := h . g;
          goto bott;
    stop:        d := g := g0 := nil;
    bott:
       end;
          if !*trgroeb and null g then
          prin2t "**** modular test detects empty branch!";
          if !*trgroeb then 
          prin2t "------ end of  modular test of branch ------"; 
       setdmode('modular,nil);
       if oldmode then setdmode(get(oldmode,'dname),t);
       return  null g;
    end;

fluid '(!*localtest);

symbolic procedure groebfasttest(g0,g,d,g99);
     if !*localtest then 
       <<!*localtest := nil; g99 := nil;
         groebweakbasistest(g0,g,d)>>
     else if !*groebweak and g and vdpunivariate!? car g
            then groebweakbasistest(g0,g,d);

symbolic procedure groebvdp2mod f;
   %convert a vdp in modular form
   % in case of headterm loss, nil is returned
     begin scalar u,c,mf;
        u := vdpgetprop(f,'modimage);
        if u then return if u='nasty then nil else u;
        mf := vdpresimp f;
        if !*gsugar then vdpputprop(mf,'sugar,vdpgetprop(f,'sugar));
	c := errorset!*(list('vbcinv,mkquote vdplbc mf),nil);
        if not pairp c then 
        <<prin2t "************** nasty module (loss of headterm) ****";
          print f; print u; vdpprint f; vdpprint u;
          vdpputprop(f,'modimage,'nasty);
          return nil>>;
        u := vdpvbcprod(mf,car c);
        vdpputprop(u,'number,vdpgetprop(f,'number));
        vdpPutProp(f,'modimage,u);
        if !*gsugar then vdpputprop(u,'sugar,vdpGetProp(f,'sugar));
        return u;
     end;


symbolic procedure groebmodeval(f,break);
     % evaluate LISP form r with REDUCE modular domain
  begin scalar oldmode,a,!*vdpinteger,groebmodular!*;
      groebmodular!* := t; break := nil;
      if current!-modulus= 1 then setmod list 2097143;
      oldmode := setdmode('modular,t);
      a := errorset!*(f,t);
      setdmode('modular,nil);
      if oldmode then setdmode(get(oldmode,'dname),t);
      return if atom a then nil else car a;
   end;

endmodule;
 
end;
