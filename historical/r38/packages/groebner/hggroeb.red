module hggroeb; % Homogeneous Graded Grobner bases.

%    Buchberger algorithm for homogeneous graded polynomial
%    systems. d1 and d2 are positive integers (d2 may be
%    infinity). Compute the basis for the sectin [d1,d2].
%
%    see Becker-Weispfenning, Chapter 10.
%
%    A local redefinition of the function groebspolynom is
%    used to exclude pairs which do not fit into the grade interval. 

fluid '(dd!-1!*, dd!-2!*);

% imported fluids.

symbolic procedure dd_groebner!* q;
  (begin scalar vars,w,np,oldorder,!*redefmsg;
         integer pcount!*;
      w := for each j in groerevlist u
              collect if eqexpr j then !*eqn2a j else j;
      vars := groebnervars(w,nil);
      if null vars then rerror(groebner,4,"empty system groebner");
      groedomainmode();      
      oldorder := vdpinit vars;
                  % cancel common denominators
      w := for each j in w collect f2vdp numr simp j;
      dd_homog!-check w;
      if not !*vdpInteger then
      <<np := t;
        for each p in w do
          np := if np then vdpcoeffcientsfromdomain!? p else nil;
        if not np then <<!*vdpmodular:= nil; !*vdpinteger := t>>;
      >>;
      if !*groebprot then <<groebprotfile := '(list)>>;
      w := dd!-bbg(w);
      if !*gltbasis then 
        gltb := 
           'list . for each base in w collect
                   'list . for each j in base collect
                      vdp2a vdpfmon(a2vbc 1,vdpevlmon j);
      w := 'list . for each j in w collect vdp2a j;
      vdpcleanup();
      gvarslast := 'list . vars;
      return w
   end) where dd!-1!*=ieval car q,
            dd!-2!*=reval cadr q,
            u=reval caddr q;

put('dd_groebner,'psopfn,'dd_groebner!*);
 
put('dd_groebner,'number!-of!-args,3);

symbolic procedure dd!-bbg w;
  begin scalar r;
     copyd('groebspolynom,'dd!-groebspolynom);
     r:=errorset({'groebner2,mkquote w,nil},t,nil);
     copyd('groebspolynom,'true!-groebspolynom);
     if errorp r then rederr "dd_groebner failed";
     return caar r end;

symbolic procedure dd_homog!-check w;
  begin scalar d,q,tst,q;
    if not memq(dipsortmode!*,'(graded weighted gradlex revgradlex))
      then typerr(dipsortmode!*,"term order for dd_groebner");
    for each p in w do
    <<q:=p; p:=vdppoly p; 
      d:=ev!-gamma(dipevlmon p); p:=dipmred p;
      while not dipzero!? p do
        <<tst:=tst or d neq ev!-gamma(dipevlmon p); p:=dipmred p>>;
      if tst then typerr(vdp2a q,"homogeneous polynomial");
    >> end ;
      
copyd('true!-groebspolynom,'groebspolynom);

symbolic procedure dd!-groebspolynom(p1,p2);
  (if (dd!-1!* <= d and (dd!-2!*='infinity or d <= dd!-2!*)) then
       true!-groebspolynom(p1,p2) else a2vdp 0)
   where d=ev!-gamma vevlcm(vdpevlmon p1, vdpevlmon p2);

endmodule;;end;
