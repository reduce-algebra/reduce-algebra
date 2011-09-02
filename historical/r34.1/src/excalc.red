module excalc; % header for EXCALC, a differential geometry package.

% Author: Eberhard Schruefer;

create!-package('(excalc exintro aux degform exdf forder frames hodge
                  idexf indices indxprin innerprod liedf lievalform
                  partdf partitsf vardf vecanalys wedge),
                '(contrib excalc));

%************ patches ***************;

% Meaning of ^ and # changed.  !!!! BE AWARE OF THIS "!!!

remprop('!^,'newnam);

% plus and difference changed because we are dealing with non-
% homogenous terms

deflist('
  ((difference getrtypeor)
   (plus getrtypeor)
 ),'rtypefn);

fluid '(depl!*);    % !*ignoreeol

global '(bndeq!* detm!*);

share bndeq!*,detm!*;

global '(lftshft!*);

% !*ignoreeol := t;    % To allow for Excalc's special constructs.


% Smacros used by more than one EXCALC module:

smacro procedure ldpf u;
   %selector for leading standard form in patitioned sf;
   caar u;

smacro procedure tpsf u;
   %selector for leading term in partitioned sf;
   car u;

smacro procedure !*k2pf u;
   u .* (1 ./ 1) .+ nil;

smacro procedure negpf u;
   multpfsq(u,(-1) ./ 1);

smacro procedure lowerind u;
   list('minus,u);

smacro procedure lwf u;
   %selector for leading factor in wedge.
   car u;

smacro procedure rwf u;
   %selector for the rest of factors in wedge.
   cdr u;

smacro procedure lftshftp u;
   smemqlp(lftshft!*,u);

smacro procedure get!-impfun!-args u;
   % Get dependencies of id u.
   cdr assoc(u,depl!*);

smacro procedure get!*fdeg u;
   (if x then car x else nil) where x = get(u,'fdegree);

smacro procedure get!*ifdeg u;
   (if x then cdr x else nil)
    where x = assoc(length cdr u,get(car u,'ifdegree));


%*********************************************************************;
%*********************************************************************;
%                   Differential Geometry Package                     ;
%*********************************************************************;
% This version runs in REDUCE 3.3
%*********************************************************************;
% Version: 2.z                                                        ;
% E.Schruefer 03/12/87                                                ;
%*********************************************************************;
%                       testsite copy                                 ;
% ====== this program must not be redistributed or copied ======      ;
%*********************************************************************;

endmodule;


module exintro;

% Author: Eberhard Schruefer.

fluid '(depl!*);

global '(dimex!* lftshft!* detm!* basisforml!* sgn!* wedgemtch!*
         bndeq!* basisvectorl!* indxl!* nosuml!* !*nosum coord!*
         keepl!* metricd!* metricu!* !*product!-rule);

% Some initialiations.

dimex!* := !*q2f simp 'dim;
sgn!* := !*k2q 'sgn;
!*product!-rule := t;

rlistat('(pform fdomain remfdomain tvector spacedim forder remforder
          frame dualframe keep closedform xpnd noxpnd
          isolate remisolate));

symbolic procedure spacedim u;
   begin
     dimex!* := !*q2f simp car u
   end;

symbolic procedure fdomain u;
   %Sets up implicit dependencies;
   while u do
     <<if not eqexpr car u then errpri2(car u,'hold)
        else begin scalar y;
               rmsubs();
               y := get(cadar u,'rtype);
               remprop(cadar u,'rtype);
               for each x  in cdr caddar u do
                 <<if indvarp x then
                     for each j in mkaindxc flatindxl cdr x do
                        depend1(cadar u,prepsq simpindexvar
                                sublis(pair(flatindxl cdr x,j),x),t)
                    else depend1(cadar u,x,t)>>;
               flag(list cadar u,'impfun);
               if y then put(cadar u,'rtype,y)
             end;
       u := cdr u>>;


symbolic procedure remfdomain u;
%Removes implicit dependencies;
   begin scalar x;
     for each j in u do
         if x := assoc(j,depl!*) then <<depl!* := delete(x,depl!*);
                                        remflag(list j,'impfun)>>
          else rerror(excalc,1,list(j," had no dependencies"));
   end;

symbolic procedure putform(u,v);
     if atom u then put(!*a2k u,'fdegree,list !*q2f simp v)
      else
       begin scalar x,y; integer n;
         n := length cdr u;
         if (x := get(car u,'ifdegree)) and (y := assoc(n,x))
             then x := delete(y,x);
         put(car u,'ifdegree,if x then (n . !*q2f simp v) . x
                              else list(n . !*q2f simp v));
         x := car u;
         flag(list x,'indexvar); %this should go.
         put(x,'rtype,'indexed!-form);
         put(x,'simpfn,'simpindexvar);
         put(x,'partitfn,'partitindexvar);
         flag(list x,'full);
         put(x,'prifn,'indvarprt);
         if null numr simp v then flag(list x,'covariant)
      end;

symbolic procedure pform u;
   begin rmsubs();
     for each j in u do
       if not eqexpr j then errpri2(j,'hold)
        else putform(cadr j,caddr j)
   end;

symbolic procedure tvector u;
   for each j in u do putform(j,-1);

symbolic procedure getlower u;
   cdr atsoc(u,metricd!*);

symbolic procedure getupper u;
   cdr atsoc(u,metricu!*);

symbolic procedure xpnd u;
   <<rmsubs(); remflag(u,'noxpnd)>>;

symbolic procedure noxpnd u;
   <<rmsubs(); flag(u,'noxpnd)>>;

symbolic procedure closedform u;
   <<rmsubs(); flag(u,'closed)>>;


symbolic procedure memqcar(u,v);
   null atom u and car u memq v;

endmodule;


module aux;

% Author: Eberhard Schruefer;

fluid '(!*nat);

global '(coord!* basisforml!* keepl!*);

symbolic procedure boundindp(u,v);
   if null u then t else member(car u,v) and boundindp(cdr u,v);

symbolic procedure memblp(u,v);
   if null u then nil
    else if atom u then member(u,v)
    else memblp(car u,v) or memblp(cdr u,v);

symbolic procedure displayframe;
   begin scalar x,scoord;
     terpri!* t;
     scoord := coord!*;
     coord!* := nil;
     for each j in basisforml!* do
       <<x := assoc(j,keepl!*);
         maprin car x;
         prin2!* " = ";
         maprin reval cdr x;
         terpri!* t>>;
%was     varpri(reval cdr x,list mkquote car x,t)>>;
     if !*nat then terpri!* t;
     coord!* := scoord
   end;

put('displayframe,'stat,'endstat);

%symbolic procedure form!*coeff u;
%begin scalar x,inds; %integer n;
 %inds:=cdr u;
 %n:=length inds;
 %x:=simp!* car u;
 %y:=dstrsdf numr x;


 %put('fcoeff,'simpfn,'form!*coeff);


endmodule;


module degform;

% Author: Eberhard Schruefer;

global '(frlis!* dimex!*);

symbolic procedure deg!*farg u;
   %Calculates the sum of degrees of the elements of the list u;
   if null cdr u then deg!*form car u else
    begin scalar z;
      for each j in u do z := addf(deg!*form j,z);
      return z
    end;

symbolic procedure deg!*form u;
%U is a prefix expression. Result is the degree of u;
   if atom u then get!*fdeg u
    else (if flagp(x,'indexvar) then get!*ifdeg u
           else if x eq 'wedge then deg!*farg cdr u
           else if x eq 'd then addd(1,deg!*form cadr u)
           else if x eq 'hodge then addf(dimex!*,negf deg!*form cadr u)
           else if x eq 'partdf then if cddr u then nil else -1
           else if x eq 'liedf then deg!*form caddr u
           else if x eq 'innerprod then addd(-1,deg!*form caddr u)
           else if x memq '(plus minus difference quotient) then
                     deg!*form cadr u
           else if x eq 'times then deg!*farg cdr u
           else nil) where x = car u;

symbolic procedure exformp u;
   %test for exterior forms and vectors in prefix expressions;
   if null u or numberp u then nil
    else if atom u and u memq frlis!* then t
    else if atom u then get(u,'fdegree)
    else if flagp(car u,'indexvar)
            then assoc(length cdr u,get(car u,'ifdegree))
    else if car u eq '!*sq then exformp prepsq cadr u
    else if car u memq '(wedge d partdf hodge innerprod liedf) then t
    else if get(car u,'dname) then nil
    else lexformp cdr u or exformp car u;

symbolic procedure lexformp u;
   u and (exformp car u or lexformp cdr u);


endmodule;


module exdf;

% Author: Eberhard Schruefer;

global '(naturalframe2coframe dbaseform2base2form basisforml!* dimex!*
         subfg!*);


put('d,'simpfn,'simpexdf);

put('d,'rtypefn,'getrtypecar);

put('d,'partitfn,'partitexdf);

symbolic procedure partitexdf u;
   exdfpf partitop car u;

symbolic procedure simpexdf u;
   !*pf2sq partitexdf u;

symbolic procedure mkexdf u;
   begin scalar x,y;
     return if x := opmtch(y := list('d,u))
               then partitop x
             else mkupf y
   end;

symbolic procedure exdfpf u;
   if null u then nil
    else addpf(if ldpf u = 1
                  then exdf0 lc u
                else addpf(multpfsq(exdfk ldpf u,lc u),
                           mkuniquewedge wedgepf2(exdf0 lc u,
                                                  !*k2pf list ldpf u)),
               exdfpf red u);

symbolic procedure exdfk u;
   if u = 1 or eqcar(u,'d) or dim!<!=deg u
            or flagp(lid u,'closed) then nil
    else if flagp('d,'noxpnd) or lftshftp u then mkexdf u
    else if atomf u then
           if (not flagp('partdf,'noxpnd)) and
                   flagp(lid u,'impfun)
              then dimpfun(u,get!-impfun!-args lid u)
    else if coordp u then
            if subfg!*
               then !*pfsq2pf cdr atsoc(u,naturalframe2coframe)
             else mkexdf u
    else if basisformp u and dbaseform2base2form then
             !*pfsq2pf cdr atsoc(u,dbaseform2base2form)
          else mkexdf u
    else if (car u eq 'wedge) then dwedge cdr u
    else if car u memq '(hodge innerprod liedf) then mkexdf u
    else if car u eq 'partdf then
           if not flagp('partdf,'noxpnd) and atomf cadr u
              then dimpfun(u,get!-impfun!-args lid cadr u)
          else mkexdf u
    else begin scalar x,y,z;
           if null(x := get(car u,'dfn)) then return mkexdf u;
           z := cdr u;
           for each j in
               for each k in z collect partitexdf list k do
            <<if j then
               y := addpf(multpfsq(j,simp subla(pair(caar x,z),cdar x)),
                          y);
              x := cdr x>>;
           return y
         end;

symbolic procedure lid u;
   if atom u then u else car u;

symbolic procedure atomf u;
   atom u or flagp(car u,'indexvar);

symbolic procedure dim!<!=deg u;
   (null x or (fixp x and x<=0))
    where x = addf(dimex!*,negf deg!*form u);

symbolic procedure dim!<deg u;
   begin scalar x;
     x := addf(dimex!*,negf deg!*farg u);
     return if numberp x and minusp x then t
             else nil
   end;

symbolic procedure dimpfun(u,v);
   if null v then nil
    else addpf(multpfsq(exdfp0(car v . 1),partdfsq(simp u,car v)),
               dimpfun(u,cdr v));

symbolic procedure exdf0 u;
   multpfsq(addpf(exdff0 numr u,multpfsq(exdff0 negf denr u,u)),
            1 ./ denr u);

symbolic procedure exdff0 u;
   if domainp u then nil
    else addpf(addpf(multpfsq(exdff0 lc u,!*p2q lpow u),
                     multpfsq(exdfp0 lpow u,lc u ./ 1)),
               exdff0 red u);

symbolic procedure exdfp0 u; %weighted vars ??
   begin scalar pv,n,z;
     pv := car u;
      n := pdeg u;
     return if (sfp pv or exformp pv or null subfg!*)
               and (z := if sfp pv then exdff0 pv
                          else exdfk pv)
               then if n = 1 then z
                     else multpfsq(z,!*t2q((pv to (n - 1)) .* n))
             else nil
   end;

symbolic procedure dwedge u;
   %u is a wedge argument, result is a pf.
   mkuniquewedge dwedge1(u,nil);

symbolic procedure dwedge1(u,v);
   if null rwf u
      then mkunarywedge multpfsq(exdfk lwf u,mksgnsq v)
    else addpf(wedgepf2(!*k2pf lwf u,
                       dwedge1(rwf u,addf(v,deg!*form lwf u))),
               multpfsq(wedgepf2(exdfk lwf u,!*k2pf rwf u),mksgnsq v));

symbolic procedure exdfprn u;
   <<prin2!* "d"; rembras cadr u>>;

put('d,'prifn,'exdfprn);

endmodule;


module forder;

% Author: Eberhard Schruefer;

global '(keepl!* wedgemtch!* lftshft!* indxl!* subfg!*);

fluid '(kord!*);


symbolic procedure add2l(u,v);
   !*a2k u . if u memq v then delete(u,v) else v;

symbolic procedure forder u;
   forder1 u;

symbolic procedure forder1 u;
   (lambda x;
    while x do
    <<kord!* := add2l(car x,kord!*);
      if eqcar(car x,'wedge) then
         for each j in reverse cdar x do
             kord!* := add2l(j,kord!*);
      x:=cdr x>>)
    reverse u;

symbolic procedure remforder u;
   for each j in u do kord!* := delete(j,kord!*);

symbolic procedure isolate u;
   rerror(excalc,2,"Sorry, ISOLATE not supported in this version");
%  for each j in u do
%    <<lftshft!* := !*a2k car u . lftshft!*;
%      kord!* := !*a2k car u . kord!*>>;

symbolic procedure remisolate u;
   for each j in u do lftshft!* := delete(j,lftshft!*);

symbolic procedure worderp(x,y);
   if null atom x and flagp(car x,'indexvar) and
      null atom y and flagp(car y,'indexvar)
      then indexvarordp(x,y)
    else if atom x or (x memq kord!*) then
            if atom y or (y memq kord!*) then ordop(x,y)
             else worderp(x,peel y)
    else if atom y or (y memq kord!*) then worderp(peel x,y)
    else worderp(peel x,peel y);

symbolic procedure indexvarordp(u,v);
   if null(car u eq car v) then ordop(u,v)
    else ((if boundindp(x,indxl!*)
            then if boundindp(y,indxl!*)
                    then indordlp(x,y)
                  else t
           else if boundindp(y,indxl!*) then nil
           else ordop(u,v))
          where x = flatindxl cdr u, y = flatindxl cdr v);

symbolic procedure indordlp(u,v);
   if null u then nil
    else if null v then t
    else if car u eq car v then indordlp(cdr u, cdr v)
    else if atom car u
            then if atom car v then indordp(car u,car v)
                  else t
          else nil;

symbolic procedure peel u;
   if car u memq '(liedf innerprod) then u := caddr u
    else if car u eq 'quotient then
            if worderp(cadr u,caddr u) then u:=cadr u
             else u:=caddr u
    else u:=cadr u;

symbolic procedure indordp(u,v);
   begin scalar x;
     x := indxl!*;
     if null(u memq x) then return t;
     a: if null x then return orderp(u,v);
     if u eq car x then return t
     else if v eq car x then return nil;
     x:=cdr x;
     go to a
  end;

symbolic procedure indordn u;
   if null u then nil
    else if null cdr u then u
    else if null cddr u then indord2(car u,cadr u)
    else indordad(car u,indordn cdr u);

symbolic procedure indord2(u,v);
   if indordp(u,v) then list(u,v) else list(v,u);

symbolic procedure indordad(a,u);
   if null u then list a
    else if indordp(a,car u) then a . u
    else car u . indordad(a,cdr u);

symbolic procedure keep u;
   while u do
     <<if not eqexpr car u then errpri2(car u,'hold)
        else begin scalar x,y,z;
       z := subfg!*;
       subfg!* := nil;
       x := !*a2k cadar u;
       y := !*a2k caddar u;
       forder1 list(x,y);
       keepl!* := (x . y) . keepl!*;
       flag(list x,'keep);
       put(x,'keepl,list y);
       subfg!* := z;
       putdep(x,y);
       if null exdfk y then flag(list x,'closed);
       if eqcar(y,'wedge) then
         <<wedgemtch!*:=(cdr y . x) . wedgemtch!*;
           for each j in cdr y do
             wedgemtch!* := (list(x,j) . nil) . wedgemtch!*>>
       else let2(y,x,nil,t)
     end;
     u := cdr u>>;

symbolic procedure putdep(u,v);
   for each j in cdr v do
     if atom j then depend1(u,j,t) else putdep(u,j);

endmodule;


module frames;

% Author: Eberhard Schruefer;

global '(basisforml!* basisvectorl!* keepl!* naturalframe2coframe
         dbaseform2base2form dimex!* indxl!* naturalvector2framevector
         subfg!* metricd!* metricu!* coord!* cursym!* detm!*
         commutator!-of!-framevectors);

fluid '(alglist!* kord!*);

symbolic procedure coframestat;
   begin scalar framel,metric;
     flag('(with),'delim);
     framel := cdr rlis();
     remflag('(with),'delim);
     if cursym!* eq '!*semicol!* then go to a;
     if scan() eq 'metric then metric := xread t
      else if cursym!* eq 'signature then metric := rlis()
      else symerr('coframe,t);
     a: cofram(framel,metric)
   end;

put('coframe,'stat,'coframestat);


%put('cofram,'formfn,'formcofram);

symbolic procedure cofram(u,v);
   begin scalar alglist!*;
     rmsubs();
     u := for each j in u collect
              if car j eq 'equal then cdr j else list j;
     putform(caar u,1);
     basisforml!* := for each j in u collect !*a2k car j;
     indxl!* := for each j in basisforml!* collect cadr j;
     dimex!* := length u;
     basisvectorl!* := nil;
     if null v then
          metricd!* := nlist(1,dimex!*)
      else if car v eq 'signature then
          metricd!* := for each j in cdr v collect aeval j;
     if null v or (car v eq 'signature) then
       <<detm!* := simp car metricd!*;
         for each j in cdr metricd!* do
             detm!* := multsq(simp j,detm!*);
           detm!* := mk!*sq detm!*;
           metricu!* := metricd!*:= pair(indxl!*,for each j in
                           pair(indxl!*,metricd!*) collect list j)>>
      else mkmetric v;
     if flagp('partdf,'noxpnd) then remflag('(partdf),'noxpnd);
     putform('eps . indxl!*,0);
     flag('(eps),'antisymmetric);
     flag('(eps),'covariant);
     setk('eps . for each j in indxl!* collect lowerind j,1);
     if null cdar u then return;
     keepl!* := append(for each j in u collect
                         !*a2k car j . cadr j,keepl!*);
     coframe1 for each j in u collect cadr j
  end;

symbolic procedure coframe1 u;
   begin scalar osubfg,scoord,v,y,w;
     osubfg := subfg!*;
     subfg!* := nil;
     v := for each j in u collect
            <<y := partitop j;
              scoord := pickupcoords(y,scoord);
              y>>;
     if length scoord neq dimex!*
       then rerror(excalc,3,"badly formed basis");
     w := !*pf2matwrtcoords(v,scoord);
     naturalvector2framevector := v;
     subfg!* := nil;
     naturalframe2coframe := pair(scoord,
          for each j in lnrsolve(w,for each k in basisforml!*
                                       collect list !*k2q k)
              collect mk!*sqpf partitsq!* car j);
     subfg!* := osubfg;
     coord!* := scoord;
     dbaseform2base2form := pair(basisforml!*,
          for each j in v collect mk!*sqpf repartit exdfpf j)
   end;

symbolic procedure pickupcoords(u,v);
   %u is a pf, v a list. Picks up vars in exdf and declares them as
   %zero forms.
   if null u then v
    else if null eqcar(ldpf u,'d)
      then rerror(excalc,4,"badly formed basis")
    else if null v then <<putform(cadr ldpf u,0);
                          pickupcoords(red u,cadr ldpf u . nil)>>
    else if ordop(cadr ldpf u,car v)
      then if cadr ldpf u eq car v
              then pickupcoords(red u,v)
            else <<putform(cadr ldpf u,0);
                   pickupcoords(red u,cadr ldpf u . v)>>
    else pickupcoords(red u,car v . pickupcoords(!*k2pf ldpf u,cdr v));

symbolic procedure !*pf2matwrtcoords(u,v);
   if null u then nil
    else !*pf2colwrtcoords(car u,v) . !*pf2matwrtcoords(cdr u,v);

symbolic procedure !*pf2colwrtcoords(u,v);
   if null v then nil
    else if u and (cadr ldpf u eq car v)
            then lc u . !*pf2colwrtcoords(red u,cdr v)
    else (nil ./ 1) . !*pf2colwrtcoords(u,cdr v);

symbolic procedure coordp u;
   u memq coord!*;

symbolic procedure mkmetric u;
   begin scalar x,y,okord;
     putform(list(cadr u,nil,nil),0);
     flag(list cadr u,'symmetric);
     flag(list cadr u,'covariant);
     okord := kord!*;
     kord!* := basisforml!*;
     x := simp!* caddr u;
     y := indxl!*;
     metricu!* := t; %to make simpindexvar work;
     for each j in indxl!* do
       <<for each k in y do
           setk(list(cadr u,lowerind j,lowerind k),0);
         y := cdr y>>;
     for each j on partitsq(x,'basep) do
       if ldeg ldpf j = 2 then
           setk(list(cadr u,lowerind cadr mvar ldpf j,
                            lowerind cadr mvar ldpf j),
                mk!*sq lc j)
        else
           setk(list(cadr u,lowerind cadr mvar ldpf j,
                            lowerind cadr mvar lc ldpf j),
                mk!*sq multsq(lc j,1 ./ 2));
     kord!* := okord;
     x := for each j in indxl!* collect
            for each k in indxl!* collect
               simpindexvar list(cadr u,lowerind j,lowerind k);
     y := lnrsolve(x,generateident length indxl!*);
     metricd!* := mkasmetric x;
     metricu!* := mkasmetric y;
     detm!* := mk!*sq detq x
   end;

symbolic procedure mkasmetric u;
   for each j in pair(indxl!*,u) collect
        car j . begin scalar w,z;
                  w := indxl!*;
                  for each k in cdr j do
                    <<if numr k then
                         z := (car w . mk!*sq k) . z;
                         w := cdr w>>;
                  return z
                 end;

symbolic procedure frame u;
   begin scalar y;
     putform(list(car u,nil),-1);
     flag(list car u,'covariant);
     basisvectorl!* :=
         for each j in indxl!* collect !*a2k list(car u,lowerind j);
     if null dbaseform2base2form then return;
     commutator!-of!-framevectors :=
       for each j in pickupwedges dbaseform2base2form collect
         list(cadadr j,cadadr cdr j) . mk!*sqpf mkcommutatorfv(j,
                                                 dbaseform2base2form);
     y := pair(basisvectorl!*,
               naturalvector2framevector);
     naturalvector2framevector := for each j in coord!* collect
                                      j . mk!*sqpf mknat2framv(j,y)
   end;

symbolic procedure pickupwedges u;
   pickupwedges1(u,nil);

symbolic procedure pickupwedges1(u,v);
   if null u then v
    else if null cdar u then pickupwedges1(cdr u,v)
    else if null v then pickupwedges1((caar u . red cdar u) . cdr u,
                                      ldpf cdar u . nil)
    else if ldpf cdar u memq v
            then pickupwedges1(if red cdar u
                                  then (caar u . red cdar u) . cdr u
                                else cdr u,v)
          else   pickupwedges1(if red cdar u
                                  then (caar u . red cdar u) . cdr u
                                else cdr u,ldpf cdar u . v);

symbolic procedure mkbasevector u;
   !*a2k list(caar basisvectorl!*,lowerind u);

symbolic procedure mkcommutatorfv(u,v);
   if null v then nil
    else addpf(mkcommutatorfv1(u,mkbasevector cadaar v,cdar v),
               mkcommutatorfv(u,cdr v));

symbolic procedure mkcommutatorfv1(u,v,w);
   if null w then nil
    else if u eq  ldpf w
            then v .* negsq simp!* lc w .+ nil
    else if ordop(u,ldpf w) then nil
    else mkcommutatorfv1(u,v,red w);

symbolic procedure mknat2framv(u,v);
   if null v then nil
    else addpf(mknat2framv1(u,caar v,cdar v),mknat2framv(u,cdr v));

symbolic procedure mknat2framv1(u,v,w);
   if null w then nil
    else if u eq cadr ldpf w
            then v .* lc w .+ nil
    else if ordop(u,cadr ldpf w) then nil
    else mknat2framv1(u,v,red w);

symbolic procedure dualframe u;
   rerror(excalc,5,"Dualframe no longer supported - use frame instead");

symbolic procedure riemannconx u;
   riemconnection car u;

put('riemannconx,'stat,'rlis);

smacro procedure mkbasformsq u;
   mksq(list(caar basisforml!*,u),1);

symbolic procedure riemconnection u;
   %calculates the riemannian connection and stores it in u;
   begin
     putform(list(u,nil,nil),1);
     flag(list u,'covariant);
     flag(list u,'antisymmetric);
     for each j in indxl!* do
       for each k in indxl!* do if (j neq k) and indordp(j,k) then
                                 setk(list(u,lowerind j,lowerind k),0);
     riemconpart1 u;
     riemconpart2 u;
     riemconpart3 u
    end;

symbolic procedure riemconpart1 u;
   begin scalar covbaseform,indx1,indx2,indx3,varl,w,z;
     for each l in dbaseform2base2form do
       <<covbaseform := partitindexvar list(caar l,
                                            lowerind cadar l);
         for each j on cdr l do
         <<varl := cdr ldpf j;
           indx1 := cadar varl;
           indx2 := cadadr varl;
           for each y on covbaseform do
             <<w := list(u,lowerind indx1,lowerind indx2);
               z := multsq(-1 ./ 2,!*pf2sq multpfsq(lt y .+ nil,
                                                    simp!* lc j));
               setk(w,mk!*sq addsq(z,mksq(w,1)));
               indx3 := cadr ldpf y;
               z := multsq(-1 ./ 2,multsq(lc y,simp!* lc j));
               if indx1 neq indx3 then
                  if indordp(indx1,indx3) then
                     <<w := list(u,lowerind indx1,lowerind indx3);
                       setk(w,mk!*sq addsq(multsq(z,mkbasformsq indx2),
                                           mksq(w,1)))>>
                else
                     <<w := list(u,lowerind indx3,lowerind indx1);
                       setk(w,mk!*sq addsq(multsq(negsq z,
                                      mkbasformsq indx2),mksq(w,1)))>>;
               if indx2 neq indx3 then
                  if indordp(indx2,indx3) then
                     <<w := list(u,lowerind indx2,lowerind indx3);
                       setk(w,mk!*sq addsq(multsq(negsq z,
                                       mkbasformsq indx1),mksq(w,1)))>>
                else
                     <<w := list(u,lowerind indx3,lowerind indx2);
                       setk(w,mk!*sq addsq(multsq(z,
                                       mkbasformsq indx1),mksq(w,1)))>>
      >>>>>>
   end;


symbolic procedure riemconpart2 u;
   begin scalar dgkl,indx1,indx2,varl,w,z;
     if null(dgkl := mkmetricconx2 metricd!*)
        then return;
     for each j in dgkl do
       for each y on cdr j do
         <<varl := ldpf y;
           indx1 := cadar varl;
           indx2 := cadadr varl;
           w := list(u,lowerind indx1,lowerind indx2);
           z := multsq(-1 ./ 2,multsq(!*k2q car j,lc y));
           setk(w,mk!*sq addsq(z,mksq(w,1)))>>
    end;

symbolic procedure mkmetricconx2 u;
   if null u then nil
    else (if x then (ldpf mkupf list(caar basisforml!*,caar u) . x)
                     . mkmetricconx2 cdr u
           else mkmetricconx2 cdr u)
          where x = mkmetricconx21 cdar u;

symbolic procedure mkmetricconx21 u;
   if null u then nil
    else addpf(wedgepf2(exdf0 simp!* cdar u,
               !*k2pf list ldpf mkupf list(caar basisforml!*,caar u)),
               mkmetricconx21 cdr u);

symbolic procedure riemconpart3 u;
   begin scalar dg,dgk,dgkl,w,x,z;
     if null (dg := mkmetricconx3 metricd!*)
        then return;
     remflag(list u,'antisymmetric);
     for each j in indxl!* do
       <<if dg and (dgk := atsoc(j,dg))
            then dgk := cdr dgk
          else dgk := nil;
         for each k in indxl!* do
             if indordp(j,k) then
             <<w := list(u,lowerind j,lowerind k);
               x := if j eq k then nil ./ 1 else mksq(w,1);
               if dgk and (dgkl := atsoc(k,dgk))
                  then dgkl := cdr dgkl
                else dgkl := nil ./ 1;
               z := multsq(1 ./ 2,dgkl);
               setk(w,mk!*sq addsq(z,x));
               w := list(u,lowerind k,lowerind j);
               setk(w,mk!*sq addsq(z,negsq x))>>>>
   end;

symbolic procedure mkmetricconx3 u;
   if null u then nil
    else ((if x then (caar u . x) . mkmetricconx3 cdr u
            else mkmetricconx3 cdr u)
           where x = mkmetricconx31 cdar u);

symbolic procedure mkmetricconx31 u;
   if null u then nil
    else ((if x then (caar u . x) . mkmetricconx31 cdr u
            else mkmetricconx31 cdr u)
           where x = !*pf2sq exdf0 simp!* cdar u);

symbolic procedure basep u;
   if domainp u then nil
    else or(if sfp mvar u then basep mvar u
             else eqcar(mvar u,caar basisforml!*),
            basep lc u,basep red u);


symbolic procedure wedgefp u;
   if domainp u then nil
    else or(if sfp mvar u then wedgefp mvar u
             else eqcar(mvar u,'wedge),
            wedgefp lc u,wedgefp red u);

endmodule;


module hodge;

% Author: Eberhard Schruefer;

global '(dimex!* sgn!* detm!* basisforml!*);

symbolic procedure formhodge(u,vars,mode);
   if mode eq 'symbolic then 'hash . formlis(cdr u,vars,mode)
    else 'list . mkquote 'hodge . formlis(cdr u,vars,mode);

put('hash,'formfn,'formhodge);

put('hodge,'simpfn,'simphodge);

put('hodge,'rtypefn,'getrtypecar);

put('hodge,'partitfn,'partithodge);

symbolic procedure partithodge u;
   hodgepf partitop car u;

symbolic procedure simphodge u;
   !*pf2sq partithodge u;

symbolic procedure mkhodge u;
   begin scalar x,y;
     return if x := opmtch(y := list('hodge,u))
               then partitop x
             else if deg!*form u = dimex!*
                     then 1 .* mksq(y,1) .+ nil
                   else mkupf y
   end;

smacro procedure mkbaseform u;
   mkupf list(caar basisforml!*,u);

symbolic procedure basisformp u;
   null atom u and (u memq basisforml!*);

symbolic procedure hodgepf u;
   if null u then nil
    else addpf(multpfsq(hodgek ldpf u,lc u),hodgepf red u);

symbolic procedure hodgek u;
   if eqcar(u,'hodge)
      then cadr u .* multsq(mksgnsq multf(deg!*form cadr u,
                              addf(dimex!*,negf deg!*form cadr u)),
                                   sgn!*) .+ nil
    else if basisformp u then dual list u
    else if eqcar(u,'wedge) and boundindp(cdr u,basisforml!*) then
            dual cdr u
    else mkhodge u;

symbolic procedure dual u;
   (multpfsq(mkdual xpnddual u,
             simpexpt list(mk!*sq(absf!* numr x ./
                                  absf!* denr x),'(quotient 1 2))))
    where x = simp!* detm!*;

symbolic procedure !*met2pf u;
   metpf1 getupper cadr u;

symbolic procedure xpnddual u;
   if null cdr u
      then mkunarywedge !*met2pf car u
    else wedgepf2(!*met2pf car u,xpnddual cdr u);

symbolic procedure metpf1 u;
   if null u then nil
    else addpf(multpfsq(mkbaseform caar u,simp cdar u),metpf1 cdr u);

symbolic procedure mkdual u;
   if null u then nil
    else addpf(multpfsq(((if null x then nil
                           else if cdr ldpf x
                                   then multpfsq(mkuniquewedge1 ldpf x,
                                                 lc x)
                           else car ldpf x .* lc x .+ nil)
                          where x = dualk ldpf u),
                         lc u),mkdual red u);

symbolic procedure dualk u;
   begin scalar x;
     x := !*k2pf basisforml!*;
     a: x := dualk2(car u,x);
        if null(u := cdr u) then return x;
        go to a
   end;


symbolic procedure dualk2(u,v);
   dualk0(u,v,nil);

symbolic procedure dualk0(u,v,w);
   if u eq car ldpf v
      then if null cdr ldpf v
              then list 1 .* multsq(mksgnsq w,lc v) .+ nil
            else cdr ldpf v .* multsq(mksgnsq w,lc v) .+ nil
    else if null cdr ldpf v then nil
    else wedgepf2(!*k2pf ldpf car v,
                  dualk0(u,cdr ldpf v .* lc v .+ nil,addf(w,1)));

symbolic procedure hodgeprn u;
   <<prin2!* "#"; rembras cadr u>>;

put('hodge,'prifn,'hodgeprn);

endmodule;


module idexf;

% Author: Eberhard Schruefer

global '(exfideal!*);

symbolic procedure exterior!-ideal u;
   begin scalar x,y;
     rmsubs();
     for each j in u do
       if indexvp j then
          for each k in mkaindxc(y := flatindxl cdr j) do
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


module indices;

% Author: Eberhard Schruefer.

fluid '(!*exp !*msg !*nat !*sub2 alglist!* frasc!*);

global '(mcond!*);

global '(!*nosum indxl!* nosuml!* metricu!*);

symbolic procedure indexeval(u,v);
   % Toplevel evaluation function for indexed quantities.
   begin scalar v,x,alglist!*;
     v := simp!* u;
     x := subfg!*;
     subfg!* := nil;
     % We don't substitute values here, since indexsymmetries can
     % save us a lot of work.
     v := quotsq(xpndind partitsq(numr v ./ 1,'indvarpf),
                 xpndind partitsq(denr v ./ 1,'indvarpf));
     subfg!* := x;
     % If there are no free indices, we have already the result;
     % otherwise indxlet does the further simplification.
     if numr v and
    null indvarpf !*t2f lt numr v then v := exc!-mk!*sq2 resimp v
      else v := prepsqxx v;
     % We have to convert to prefix here, since we don't have a tag.
     % This is a big source of inefficiency.
     return v
   end;

symbolic procedure exc!-mk!*sq2 u;  %this is taken from matr;
   begin scalar x;
        x := !*sub2;   %since we need value for each element;
        u := subs2 u;
        !*sub2 := x;
        return mk!*sq u
   end;

symbolic procedure xpndind u;
   %performs the implied summation over repeated indices;
   begin scalar x,y;
     y := nil ./ 1;
     a: if null u then return y;
     if null(x := contind ldpf u) then
        y := addsq(multsq(!*f2q ldpf u,lc u),y)
      else for each k in mkaindxc x do
        y := addsq(multsq(subcindices(ldpf u,pair(x,k)),lc u),y);
     u := red u;
     go to a
   end;

symbolic procedure subcindices(u,l);
   % Substitutes dummy indices from a-list l into s.f. u;
   % discriminates indices from variables.
   begin scalar alglist!*;
     return if domainp u then u ./ 1
             else addsq(multsq(
                           exptsq(if flagp(car mvar u,'indexvar) then
                                        simpindexvar subla(l,mvar u)
                                   else simp subindk(l,mvar u),ldeg u),
                               subcindices(lc u,l)),
                       subcindices(red u,l))
   end;

symbolic procedure subindk(l,u);
   %Substitutes indices from a-list l into kernel u;
   %discriminates indices from variables;
   car u . for each j in cdr u collect
               if atom j then j
                else if idp car j and get(car j,'dname) then j
                else if flagp(car j,'indexvar) then
                                  car j . subla(l,cdr j)
                else subindk(l,j);

put('form!-with!-free!-indices,'evfn,'indexeval);

put('indexed!-form,'rtypefn,'freeindexchk);

put('form!-with!-free!-indices,'setprifn,'indxpri);

symbolic procedure freeindexchk u;
   if u and indxl!* and indxchk u then 'form!-with!-free!-indices
    else nil;

symbolic procedure indvarp u;
   %typechecking for variables with free indices on prefix forms;
   null !*nosum and indxl!* and
    if eqcar(u,'!*sq) then
       indvarpf numr cadr u or indvarpf denr cadr u
     else freeindp u;

symbolic procedure indvarpf u;
   %typechecking for free indices in s.f.'s;
   if domainp u then nil
    else or(if sfp mvar u then indvarpf mvar u
             else freeindp mvar u,
            indvarpf lc u,indvarpf red u);

symbolic procedure freeindp u;
   begin scalar x;
     return if null u or numberp u then nil
             else if atom u then nil
             else if car u eq '!*sq then freeindp prepsq cadr u
             else if idp car u and get(car u,'dname) then nil
             else if flagp(car u,'indexvar) then indxchk cdr u
             else if (x := get(car u,'indexfun)) then
                                      freeindp apply1(x,cdr u)
             else if car u eq 'partdf then
                     if null cddr u then freeindp cadr u
                      else freeindp cadr u or freeindp caddr u
             else lfreeindp cdr u or freeindp car u
   end;

symbolic procedure lfreeindp u;
   u and (freeindp car u or lfreeindp cdr u);

symbolic procedure indxchk u;
   %returns t if u contains at least one free index;
   begin scalar x,y;
   x := u;
   y := union(indxl!*,nosuml!*);
   a: if null x then return nil;
      if null ((if atom car x
                 then if numberp car x then !*num2id abs car x
                       else car x
                 else if numberp cadar x then !*num2id cadar x
                       else cadar x) memq y)
                then return t;
      x := cdr x;
      go to a
   end;

symbolic procedure indexrange u;
   <<indxl!* := mkindxl u; nil>>;

symbolic procedure nosum u;
   <<nosuml!* := union(mkindxl u,nosuml!*); nil>>;

symbolic procedure renosum u;
   <<nosuml!* := setdiff(mkindxl u,nosuml!*); nil>>;

symbolic procedure mkindxl u;
   for each j in u collect if numberp j then !*num2id j
                            else j;

rlistat('(indexrange nosum renosum));

smacro procedure upindp u;
%tests if u is a contravariant index;
   atom revalind u;

symbolic procedure allind u;
   %returns a list of all unbound indices found in standard form u;
   allind1(u,nil);

symbolic procedure allind1(u,v);
   if domainp u then v
    else allind1(red u,allind1(lc u,append(v,allindk mvar u)));

symbolic procedure allindk u;
   begin scalar x;
     return if atom u then nil
             else if flagp(car u,'indexvar) then
                     <<for each j in cdr u do
                         if atom(j := revalind j)
                            then if null(j memq indxl!*)
                                    then x := j . x
                                  else nil
                          else if null(cadr j memq indxl!*)
                                  then x := j . x;
                       reverse x>>
             else if (x := get(car u,'indexfun)) then
                           allindk apply1(x,cdr u)
             else if car u eq 'partdf then
                     if null cddr u then
                        for each j in allindk cdr u collect lowerind j
                      else append(allindk cadr u,
                                  for each j in allindk cddr u collect
                                                lowerind j)
             else append(allindk car u,allindk cdr u)
   end;

symbolic procedure contind u;
   %returns a list of indices over which summation has to be performed;
   begin scalar dnlist,uplist;
     for each j in allind u do
       if upindp j then uplist := j . uplist
        else dnlist := cadr j . dnlist;
     return setdiff(intersection(uplist,dnlist),nosuml!*)
   end;

symbolic procedure mkaindxc u;
    %u is a list of free indices. result is a list of lists of all
    %possible index combinations;
    begin scalar r,x;
      r := list u;
      for each k in u do
        if x := getindexr k then r := mappl(x,k,r);
      return r
    end;

symbolic procedure mappl(u,v,w);
   if null u then nil
    else append(subst(car u,v,w),mappl(cdr u,v,w));

symbolic procedure getindexr u;
   %Kludge to indexclasses;
   if memq(u,indxl!*) then nil else indxl!*;

symbolic procedure flatindxl u;
   for each j in u collect if atom j then j else cadr j;

symbolic procedure indexlet(u,v,ltype,b,rtype);
   if flagp(car u,'indexvar) then
      if b then setindexvar(u,v)
       else begin scalar y,z,msg;
              msg := !*msg;
              !*msg := nil; %for now.
              u := mvar numr simp0 u;    %is this right?
              z := flatindxl cdr u;
              for each j in if flagp(car u,'antisymmetric) then
                               comb(indxl!*,length z)
                             else mkaindxc z do
                let2(mvar numr simp0 subla(pair(z,j),u),nil,nil,nil);
              !*msg := msg;
              y := get(car u,'ifdegree);
              z := assoc(length cdr u,y);
              y := delete(z,y);
              remprop(car u,'ifdegree);
              if y then put(car u,'ifdegree,y)
               else <<remprop(car u,'rtype);
                      remflag(list car u,'indexvar)>>
             end
    else if subla(frasc!*,u) neq u then
         put(car(u := subla(frasc!*,u)),'opmtch,
             xadd!*((for each j in cdr u collect revalind j) .
                  list(nil . (if mcond!* then mcond!* else t),v,nil),
          get(car u,'opmtch),b))
    else setindexvar(u,v);

put('form!-with!-free!-indices,'typeletfn,'indexlet);

symbolic procedure setindexvar(u,v);
   begin scalar r,s,w,x,y,z,z1,alglist!*;
     x := metricu!* . flagp(car u,'covariant);
     metricu!* := nil; %index position must not be changed here;
     if cdr x then remflag(list car u,'covariant);
     u := simp0 u;
     if red numr u
        or (denr u neq 1) then rerror(excalc,6,"Illegal assignment");
     u := numr u;
     r := cancel(1 ./ lc u);
     u := mvar u;
     metricu!* := car x;
     if cdr x then flag(list car u,'covariant);
     z1 := allindk u;
     z := flatindxl z1;
    if indxl!* and metricu!* then
      <<z1 := for each j in z1 collect
                if flagp(car u,'covariant)
                   then if upindp j then
                           <<u := car u . subst(lowerind j,j,cdr u);
                             'lower . j>>
                         else cadr j
                 else if upindp j then j
                       else <<u := car u . subst(j,cadr j,cdr u);
                              'raise . cadr j>>;
        u := car u . for each j in cdr u collect revalind j>>
     else z1 := z;
    r := multsq(simp!* v,r);
    w := for each j in if flagp(car u,'antisymmetric) then
                            comb(indxl!*,length z)
                   else mkaindxc z collect
      <<x := mkletindxc pair(z1,j);
        s := nil ./ 1;
        y := subfg!*;
        subfg!* := nil;
        for each k in x do
          s := addsq(multsq(car k,subfindices(numr r,cdr k)),s);
        subfg!* := y;
        y := !*q2f simp0 subla(pair(z,j),u);
    mvar y . exc!-mk!*sq2 multsq(subf(if minusf y then negf numr s
                                      else numr s,nil),
                               invsq subf(multf(denr r,denr s),nil))>>;
      for each j in w do let2(car j,cdr j,nil,t)
    end;

symbolic procedure mkletindxc u;
   %u is a list of dotted pairs. Left part is unbound index and action.
   %Right part is bound index.
   begin scalar r; integer n;
     r := list((1 ./ 1) . for each j in u collect
                            if atom car j then car j else cdar j);
     for each k in u do
       <<n := n + 1;
         if atom car k then
             r := for each j in r collect car j . subindexn(k,n,cdr j)
        else r := mapletind(if caar k eq 'raise then getupper cdr k
                             else getlower cdr k,
                            cdar k,r,n)>>;
     return r
   end;

symbolic procedure subindexn(u,n,v);
   if n=1 then u . cdr v
    else car v . subindexn(u,n-1,cdr v);

symbolic procedure mapletind(u,v,w,n);
   if null u then nil
    else append(for each j in w collect
                 multsq(simp!* cdar u,car j) .
                 subindexn(v . caar u,n,cdr j),
                mapletind(cdr u,v,w,n));

put('form!-with!-free!-indices,'setelemfn,'setindexvar);

remflag('(clear),'lose);   % We must use this definition.

symbolic procedure clear u;
   begin
     rmsubs();
     remflag('(t),'reserved);  %t is very often used as a coordinate;
     for each x in u do if flagp(x,'share) then
         if not flagp(x,'reserved) then set(x,x) else rsverr x
          else <<let2(x,x,nil,nil); let2(x,x,t,nil);
         % Above, x instead of nil is passed to let2 as rhs to make
         % type inference work.
         if atom x and get(x,'fdegree) then
            <<remprop(x,'fdegree); remprop(x,'rtype)>>>>;
     mcond!* := frasc!* := nil;
     flag('(t),'reserved)
   end;

symbolic procedure subfindices(u,l);
   %Substitutes free indices from a-list l into s.f. u;
   %discriminates indices from variables;
   begin scalar alglist!*;
     return if domainp u then u ./ 1
             else addsq(multsq(if atom mvar u then !*p2q lpow u
                                else if sfp mvar u then
                                   exptsq(subfindices(mvar u,l),ldeg u)
                                else if flagp(car mvar u,'indexvar)
                                        then  exptsq(simpindexvar
                                               subla(l,mvar u),ldeg u)
                                else if car mvar u memq
                                       '(wedge d partdf innerprod
                                         liedf hodge vardf) then
                                   exptsq(simp
                                            subindk(l,mvar u),ldeg u)
                              else !*p2q lpow u,subfindices(lc u,l)),
                       subfindices(red u,l))
   end;

symbolic procedure indxpri1 u;
   begin scalar metricu,il,dnlist,uplist,r,x,y,z;
     metricu := metricu!*;
     metricu!* := nil;
     il := allind !*t2f lt numr simp0 u;
     for each j in il do
          if upindp j
             then uplist := j . uplist
           else dnlist := cadr j . dnlist;
         for each j in intersection(uplist,dnlist) do
             il := delete(j,delete(revalind
                                  lowerind j,il));
         metricu!* := metricu;
     y := flatindxl il;
     r := simp!* u;
     for each j in mkaindxc y do
       <<x := pair(y,j);
     z := exc!-mk!*sq2 multsq(subfindices(numr r,x),1 ./ denr r);
        if null(!*nero and (z = 0)) then
         <<maprin list('setq,subla(x,'ns . il),z);
           if not !*nat then prin2!* "$";
           terpri!* t>>>>
       end;

symbolic procedure indxpri(v,u);
   begin scalar x,y,z;
     y := flatindxl allindk v;
     for each j in if flagp(car v,'antisymmetric) and
                      coposp cdr v then comb(indxl!*,length y)
                    else mkaindxc y do
       <<x := pair(y,j);
         z := aeval subla(x,v);
         if null(!*nero and (z = 0)) then
         <<maprin list('setq,subla(x,v),z);
         if not !*nat then prin2!* "$";
         terpri!* t>>>>
    end;

symbolic procedure coposp u;
   %checks if all indices in list u are either in a covariant or
   %a contravariant position.;
   null cdr u or if atom car u then contposp cdr u
                  else covposp cdr u;

symbolic procedure contposp u;
   %checks if all indices in list u are contravariant;
   null u or (atom car u and contposp cdr u);

symbolic procedure covposp u;
   %checks if all indices in list u are covariant;
   null u or (null atom car u and covposp cdr u);

put('ns,'prifn,'indvarprt);

symbolic procedure simpindexvar u;
   %simplification function for indexed quantities;
   !*pf2sq partitindexvar u;

symbolic procedure partitindexvar u;
   %partition function for indexed quantities;
   begin scalar freel,x,y,z,v,sgn,w;
     x := for each j in cdr u collect
              (if atom k then
                  if numberp k then
                     if minusp k then lowerind !*num2id abs k
                      else !*num2id k
                   else k
                else if numberp cadr k then lowerind !*num2id cadr k
                      else k) where k = revalind j;
     w := deg!*form u;
     if null metricu!* then go to a;
     z := x;
     if null flagp(car u,'covariant) then
        <<while z and (atom car z or
                       not(cadar z memq indxl!*)) do
             <<y := car z . y;
               if null atom car z then freel := cadar z . freel;
               z := cdr z>>;
               if z then <<v := nil;
                           y := reverse y;
                           for each j in getlower cadar z do
                            v := addpf(multpfsq(partitindexvar(car u .
                                   append(y,car j . cdr z)),
                                               simp cdr j),v);
                           return v>>>>
      else
        <<while z and (null atom car z or
                       not(car z memq indxl!*)) do
             <<y := car z . y;
               if atom car z then freel := car z . freel;
               z := cdr z>>;
               if z then <<v := nil;
                           y := reverse y;
                           for each j in getupper car z do
                             v := addpf(multpfsq(partitindexvar(car u .
                                   append(y,lowerind car j . cdr z)),
                                          simp cdr j),v);
                           return v>>>>;
    a: if null coposp x or (null flagp(car u,'symmetric) and
                            null flagp(car u,'antisymmetric)) then
              return if w then mkupf(car u . x)
                      else 1 .* mksq(car u . x,1) .+ nil;
       x := for each j in x collect if atom j then j else cadr j;
       if flagp(car u,'symmetric) then x := indordn x
        else if flagp(car u,'antisymmetric) then
            <<if repeats x then return nil
               else if not permp(z := indordn x,x) then sgn := t;
               x := z>>;
       if flagp(car u,'covariant) then
          x := for each j in x collect
                 if j memq freel then j else lowerind j
        else if null metricu!* and null atom cadr u then
          x := for each j in x collect lowerind j
        else
          x := for each j in x collect
                 if j memq freel then lowerind j else j;
       return if w then if sgn then  negpf mkupf(car u . x)
                         else mkupf(car u . x)
               else if sgn then 1 .* negsq mksq(car u . x,1) .+ nil
                     else 1 .* mksq(car u . x,1) .+ nil
    end;

symbolic procedure !*num2id u;
%converts a numeric index to an id;
  %if u = 0 then rerror(excalc,7,"0 not allowed as index") else
   if u<10 then intern cdr assoc(u,
             '((0 . !0) (1 . !1) (2 . !2) (3 . !3) (4 . !4)
               (5 . !5) (6 . !6) (7 . !7) (8 . !8) (9 . !9)))
    else intern compress append(explode '!!,explode u);

symbolic procedure revalind u;
   begin scalar x,y,alglist!*;
     x := subfg!*;
     subfg!* := nil;
     u := subst('!0,0,u);
     % The above line is used to avoid the simplifaction of -0 to 0.
     y := prepsq simp u;
     subfg!* := x;
     return y
   end;

endmodule;


module indxprin; % Functions for special print.

% Author: Eberhard Schruefer;

fluid '(!*nat !*nero !*revpri orig!* pline!* posn!* ycoord!* ymax!*
        ymin!*);

global '(obrkp!* !*eraise spare!*);

symbolic procedure indvarprt u;
    if null !*nat then <<prin2!* car u;
                         prin2!* "(";
                         if cddr u then inprint('!*comma!*,0,cdr u)
                          else maprin cadr u;
                         prin2!* ")" >>
     else begin scalar y; integer l;
            l := flatsizec flatindxl u+length cdr u-1;
            if l>(linelength nil-spare!*)-posn!* then terpri!* t;
            %avoid breaking of an indexed variable over a line;
            y := ycoord!*;
            prin2!* car u;
            for each j on cdr u do
              <<ycoord!* :=  y + if atom car j then 1 else -1;
                if ycoord!*>ymax!* then ymax!* := ycoord!*;
                if ycoord!*<ymin!* then ymin!* := ycoord!*;
                prin2!* if atom car j then car j else cadar j;
                if cdr j then prin2!* " ">>;
            ycoord!* := y
          end;

symbolic procedure rembras u;
   if !*nat and (atom u or null get(car u,'infix))
       then <<prin2!* " ";
              maprin u>>
    else <<prin2!* "(";
           maprin u;
           prin2!* ")">>;

put('form!-with!-free!-indices,'tag,'form!-with!-free!-indices);

put('form!-with!-free!-indices,'prifn,'indxpri1);

flag('(form!-with!-free!-indices),'sprifn);

put('indvarprt,'expt,'inbrackets);


endmodule;


module innerprod;

% Author: Eberhard Schruefer.

global '(basisvectorl!* keepl!*);

newtok '((!_ !|) innerprod);

infix innerprod;

precedence innerprod,times;

%flag('(innerprod),'nary); %not done for now, but might be worthwhile.

flag('(innerprod),'spaced);

put('innerprod,'simpfn,'simpinnerprod);

put('innerprod,'rtypefn,'getrtypeor);

put('innerprod,'partitfn,'partitinnerprod);

symbolic procedure partitinnerprod u;
   innerprodpf(partitop car u,
               partitop cadr u);

symbolic procedure mkinnerprod(u,v);
   begin scalar x,y;
     return if x := opmtch(y := list('innerprod,u,v))
               then partitop x
             else if deg!*form v = 1
                     then if numr(x := mksq(y,1)) then 1 .* x .+ nil
                           else nil
                   else mkupf y
   end;

symbolic procedure simpinnerprod u;
   !*pf2sq partitinnerprod u;


symbolic procedure innerprodpf(u,v);
   if null u or null v then nil
    else if ldpf v = 1 then nil
    else
      begin scalar res,x;
        for each j on u do
          for each k on v do
            if x := innerprodf(ldpf j,ldpf k)
               then res := addpf(multpfsq(x,multsq(lc j,lc k)),res);
        return res
      end;

symbolic procedure basisvectorp u;
   null atom u and u memq basisvectorl!*;

symbolic procedure tvectorp u;
   (numberp x and x<0) where x = deg!*form ldpf u;

symbolic procedure innerprodf(u,v);
   %Inner product dispatching routine.
   if null tvectorp !*k2pf u then
        rerror(excalc,8,
               "First argument of inner product must be a vector")
    else if v = 1 then nil %is this test necessary??
    else if eqcar(v,'wedge)
            then innerprodwedge(u,cdr v)
    else if eqcar(u,'partdf) and null freeindp cadr u
            then innerprodnvec(u,v)
    else if basisvectorp u and basisformp v
            then innerprodbasis(u,v)
    else if eqcar(v,'innerprod)
            then if u eq cadr v then nil
                  else if ordop(u,cadr v) then mkinnerprod(u,v)
                        else negpf innerprodpf(!*k2pf cadr v,
                                               innerprodf(u,caddr v))
    else mkinnerprod(u,v);

symbolic procedure innerprodwedge(u,v);
   mkuniquewedge innerprodwedge1(u,v,nil);

symbolic procedure innerprodwedge1(u,v,w);
   if null rwf v then mkunarywedge
                      multpfsq(innerprodf(u,lwf v),mksgnsq w)
    else addpf(if null rwf rwf v and (deg!*form lwf rwf v = 1)
                  then multpfsq(!*k2pf list lwf v,
                       multsq(mksgnsq addf(deg!*form lwf v,w),
                              !*pf2sq innerprodf(u,lwf rwf v)))
                else wedgepf2(!*k2pf lwf v,
                              innerprodwedge1(u,rwf v,
                                    addf(w,deg!*form lwf v))),
               if deg!*form lwf v = 1
                  then multpfsq(!*k2pf rwf v,
                                multsq(!*pf2sq innerprodf(u,lwf v),
                                       mksgnsq w))
                else wedgepf2(innerprodf(u,lwf v),
                              rwf v .* mksgnsq w .+ nil));


symbolic procedure innerprodnvec(u,v);
   if eqcar(v,'d) and null deg!*form cadr v
      and null freeindp cadr v
      then if cadr u eq cadr v then 1 .* (1 ./ 1) .+ nil
            else nil
    else if basisformp v
            then begin scalar x,osubfg;
                   osubfg := subfg!*;
                   subfg!* := nil;
                   x := innerprodpf(!*k2pf u,
                                    partitop cdr assoc(v,keepl!*));
                   subfg!* := osubfg;
                   return repartit x
                 end;

symbolic procedure innerprodbasis(u,v);
   if freeindp u or freeindp v then mkinnerprod(u,v)
    else if cadadr u eq cadr v then 1 .* (1 ./ 1) .+ nil
          else nil;


endmodule;


module liedf;

% Author: Eberhard Schruefer;

global '(commutator!-of!-framevectors);

newtok '((!| !_ ) liedf);

infix liedf;

%flag('(liedf),'nary); %Not done for now, but should be considered.

flag('(liedf),'spaced);

precedence liedf,innerprod;

put('liedf,'simpfn,'simpliedf);

put('liedf,'rtypefn,'getrtypeor);

symbolic procedure simpliedf u;
   !*pf2sq partitliedf u;

put('liedf,'partitfn,'partitliedf);

symbolic procedure partitliedf u;
   liedfpf(partitop car u,partitop cadr u);

symbolic procedure mkliedf(u,v);
   begin scalar x,y;
     return if x := opmtch(y := list('liedf,u,v))
               then partitop x
             else mkupf y
   end;


symbolic procedure liedfpf(u,v);
   if null tvectorp u then
      rerror(excalc,9,
             "First argument of lie derivative must be a vector")
    else if null tvectorp v then
             addpf(exdfpf innerprodpf(u,v),
                   innerprodpf(u,exdfpf v))
    else begin scalar x;
           for each k on u do
             for each l on v do
               x := addpf(liedftt(lt k,lt l),x);
           return x
         end;

symbolic procedure liedftt(u,v);
   begin scalar x;
     return addpf(multpfsq(liedfk(car u,car v),multsq(tc u,tc v)),
                  addpf(if x := innerprodpf(!*k2pf car u,exdf0 tc v)
                           then car v .*
                                multsq(!*pf2sq x,tc u) .+ nil
                         else nil,
                        if x := innerprodpf(!*k2pf car v,exdf0 tc u)
                           then car u .*
                                negsq multsq(!*pf2sq x,tc v) .+ nil
                   else nil))
   end;

symbolic procedure liedfk(u,v);
   if u eq v then nil
    else if eqcar(u,'partdf) and eqcar(v,'partdf) then nil
    else if basisvectorp u and basisvectorp v
            then if null ordop(u,v)
                    then negpf liedfk(v,u)
                  else if commutator!-of!-framevectors
                          then get!-structure!-const(u,v)
                  else mkliedf(u,v)
    else if eqcar(v,'liedf)
            then if ordop(u,cadr v) then mkliedf(u,v)
                  else addpf(liedfpf(liedfk(u,cadr v),!*k2pf caddr v),
                             liedfpf(!*k2pf cadr v,
                                     liedfpf(!*k2pf u,!*k2pf caddr v)))
    else if worderp(u,v) then mkliedf(u,v)
          else negpf mkliedf(v,u);

symbolic procedure get!-structure!-const(u,v);
   %We currently assume that only the basis has structure consts.
   begin scalar x;
     return if x := assoc(list(cadadr u,cadadr v),
                          commutator!-of!-framevectors)
               then !*pfsq2pf cdr x
             else nil
   end;


endmodule;


module lievalform;

% Author: Eberhard Schruefer

symbolic procedure liebrackstat;
   begin scalar x;
     x := xread nil;
     scan();
     return 'lie . cdr x
   end;

flag(list '!},'delim); %Since Liebrackets can be nested we can't
                       %remove the flag in the stat proc;

put('!{,'stat,'liebrackstat); %We'd rather liked to use squarebrackets;
                       %but they are not available on most terminals;


put('lie,'prifn,'lieprn);

symbolic procedure lieprn u;
   <<prin2!* "{";
     inprint('!*comma!*,0,u);
     prin2!* "}">>;

endmodule;


module partdf;   % Adaption of df module.

% Author: Eberhard Schruefer.

fluid '(alglist!* depl!* posn!* wtl!*);

global '(frlis!* naturalvector2framevector keepl!* !*product!-rule);

newtok '((!@) partdf);

symbolic procedure simppartdf0 u;
   begin scalar v;
     if null cdr u then
           if coordp(u := reval car u)
              and (v := atsoc(u,naturalvector2framevector))
              then return !*pf2sq !*pfsq2pf cdr v
            else return mksq(list('partdf,u),1);
     if null subfg!* or freeindp car u or freeindp cadr u
                     or (cddr u and freeindp caddr u)
           then return mksq('partdf . revlis u,1);
     v := cdr u;
     u := simp!* car u;
     for each j in v do
         u := partdfsq(u,!*a2k j);
    return u
   end;

put('partdf,'simpfn,'simppartdf);

put('partdf,'rtypefn,'getrtypeor);

put('partdf,'partitfn,'partitpartdf);

symbolic procedure partitpartdf u;
   if null cdr u then mknatvec !*a2k car u
    else 1 .* simppartdf0 u .+ nil;

symbolic procedure simppartdf u;
   !*pf2sq partitpartdf u;

symbolic procedure mknatvec u;
   begin scalar x,y;
     return if x := atsoc(u,naturalvector2framevector)
               then !*pfsq2pf cdr x
             else if x := opmtch(y := list('partdf,u))
               then partitop x
             else mkupf y
   end;

symbolic procedure partdfsq(u,v);
   multsq(addsq(partdff(numr u,v),
                  multsq(u,partdff(negf denr u,v))),
                 1 ./ denr u);

symbolic procedure partdff(u,v);
   if domainp u then nil ./ 1
    else addsq(if null !*product!-rule then partdft(lt u,v)
                else addsq(multpq(lpow u,partdff(lc u,v)),
                           multsq(partdfpow(lpow u,v),lc u ./ 1)),
                partdff(red u,v));

symbolic procedure partdft(u,v);
   begin scalar x,y;
   x := partdft1(!*t2q u,v);
   y := nil ./ 1;
   for each j on x do
     if null domainp ldpf j then
        y := addsq(multsq(if domainp lc ldpf j then
                             multsq(partdfpow(lpow ldpf j,v),
                                    lc ldpf j ./ 1)
                           else mksq(list('partdf,prepf ldpf j,v),1),
                          lc j),y);
   return y
   end;

symbolic procedure partdft1(u,v);
   (if null x then nil
     else if domainp x then 1 .* u .+ nil
     else addpsf(if sfp mvar x and numr partdfpow(lpow mvar x,v)
                     then multpsf(exptpsf(partdft1(mvar u ./ 1,v),
                                          ldeg x),
                             partdft1(cancel(lc x ./ y),v))
                 else if null sfp mvar x and numr partdfpow(lpow x,v)
                          then multpsf(!*p2f lpow x .* (1 ./ 1)  .+ nil,
                                       partdft1(cancel(lc x ./ y),v))
                 else multsqpsf(!*p2q lpow x,
                              partdft1(cancel(lc x ./ y),v)),
                partdft1(cancel(red x ./ y),v)))
    where x = numr u, y = denr u;

symbolic procedure partdfpow(u,v);
   begin scalar x,z; integer n;
       n := cdr u;
       u := car u;
       z := nil ./ 1;
       if u eq v then z := 1 ./ 1
        else if atomf u then
                if x := assoc(u,keepl!*) then
                       begin scalar alglist!*;
                         z := partdfsq(simp0 cdr x,v)
                       end
                 else if ndepends(if x := get(lid u,'varlist)
                                     then lid u . cdr x
                                   else lid u,v)
                      then z := mksq(list('partdf,u,v),1)
                 else return nil ./ 1
        else if sfp u then z := partdff(u,v)
        else if car u eq '!*sq then z := partdfsq(cadr u,v)
        else if x := get(car u,'dfn) then
                 for each j in
                    for each k in cdr u collect partdfsq(simp k,v)
                  do <<if numr j then
                        z := addsq(multsq(j,simp
                                     subla(pair(caar x,cdr u),cdar x)),
                                   z);
                 x := cdr x>>
        else if car u eq 'partdf then
                if ndepends(lid cadr u,v) then
                   if assoc(list('partdf,cadr u,v),
                            get('partdf,'kvalue)) then
                       <<z := mksq(list('partdf,cadr u,v),1);
                         for each j in cddr u do
                             z := partdfsq(z,j)>>
                    else
                       <<z := 'partdf . cadr u . ordn(v . cddr u);
                         z := if x := opmtch z then simp x
                               else mksq(z,1)>>
                 else return nil ./ 1;
       if x := atsoc(u,wtl!*) then z := multpq('k!* to (-cdr x),z);
   return if n=1 then z
           else multsq(!*t2q((u to (n-1)) .* n),z)
   end;

symbolic procedure ndepends(u,v);
   if null u or numberp u or numberp v then nil
    else if u=v then u
    else if atom u and u memq frlis!* then t
    else if (lambda x; x and lndepends(cdr x,v)) assoc(u,depl!*)
     then t
    else if not atom u and idp car u and get(car u,'dname) then nil
    else if not atomf u
      and (lndepends(cdr u,v) or ndepends(car u,v)) then t
    else if atomf v or idp car v and get(car v,'dname) then nil
    else ndependsl(u,cdr v);

symbolic procedure lndepends(u,v);
   u and (ndepends(car u,v) or lndepends(cdr u,v));

symbolic procedure ndependsl(u,v);
   u and (ndepends(u,car v) or ndependsl(u,cdr v));

symbolic procedure partdfprn u;
    if null !*nat then <<prin2!* '!@;
                         prin2!* "(";
                         if cddr u then inprint('!*comma!*,0,cdr u)
                          else maprin cadr u;
                         prin2!* ")" >>
     else begin scalar y; integer l;
            l := flatsizec flatindxl cdr u+1;
            if l>(linelength nil-spare!*)-posn!* then terpri!* t;
            %avoids breaking of the operator over a line;
            y := ycoord!*;
            prin2!* '!@;
            ycoord!* :=  y - if (null cddr u and indexvp cadr u) or
                                (cddr u and indexvp caddr u) then 2
                              else 1;
                if ycoord!*<ymin!* then ymin!* := ycoord!*;
                if null cddr u then <<maprin cadr u;
                                     ycoord!* := y>>
                 else <<for each j on cddr u do
                          <<maprin car j;
                            if cdr j then prin2!* " ">>;
                        ycoord!* := y;
                        if atom cadr u then prin2!* cadr u
                         else <<prin2!* "(";
                                maprin cadr u;
                                prin2!* ")">>>>
          end;

put('partdf,'prifn,'partdfprn);

symbolic procedure indexvp u;
   null atom u and flagp(car u,'indexvar);


endmodule;


module partitsf;

% Author: Eberhard Schruefer;

fluid '(alglist!* !*exp);

symbolic procedure partitop u;
   begin scalar x,alglist!*;
   return
   if atom u then if x := get(u,'avalue)
                     then partitsq!* simp!* cadr x
                   else if get!*fdeg u then mkupf u
                   else if numr(x := simp!* u)
                           then 1 .* x .+ nil
                   else nil
    else if x := get(car u,'partitfn)
            then if flagp(car u,'full) then apply1(x,u)
                  else apply1(x,cdr u)
    else if car u eq '!*sq then partitsq!* simp!* u
    else if car u eq 'plus then
            <<for each j in cdr u do
                x := addpf(partitop j,x); x>>
    else if car u eq 'minus then negpf partitop cadr u
    else if car u eq 'difference then
            addpf(partitop cadr u,
                  negpf partitop caddr u)
    else if car u eq 'times then
            <<x := partitop cadr u;
              for each j in cddr u do
                x := multpfs(partitop j,x);
              x>>
    else if car u eq 'quotient then
               multpfsq(partitop cadr u,simprecip cddr u)
    else if car u eq 'recip then
               1 .* simprecip cdr u .+ nil
    else if numr(x := simp!* u)
            then 1 .* x .+ nil
    else nil
  end;

symbolic procedure mkupf u;
   begin scalar x;
     x := mksq(u,1);
     return if null numr x then nil
             else if (denr x = 1) and (lc numr x = 1)
                     and null red numr x and null sfp mvar numr x
                     then !*k2pf mvar numr x
             else partitsq!* x
   end;


symbolic procedure partitsq(u,v);
   %U is a standardquotient. Result is a form in which expressions
   %satisfying the test v are distributed and the rest is kept
   %recursive. Leaves unexpanded structure if possible;
   (if null x then nil
     else if domainp x then 1 .* u .+ nil
     else addpsf(if sfp mvar x and apply1(v,mvar x)
                     then multpsf(exptpsf(partitsq(mvar x ./ 1,v),
                                          ldeg x),
                             partitsq(cancel(lc x ./ y),v))
                 else if null sfp mvar x and apply1(v,!*k2f mvar x)
                          then multpsf(!*p2f lpow x .* (1 ./ 1)  .+ nil,
                                       partitsq(cancel(lc x ./ y),v))
                 else multsqpsf(!*p2q lpow x,
                              partitsq(cancel(lc x ./ y),v)),
                partitsq(cancel(red x ./ y),v)))
    where x = numr u, y = denr u;


symbolic procedure exptpsf(u,n);
   begin scalar x;
    x := u;
    while (n := n-1) > 0 do x := multpsf(u,x);
   return x
   end;

symbolic procedure exptpf(u,n);
   begin scalar x;
    x := u;
    while (n := n-1) > 0 do x := multpfs(u,x);
   return x
   end;

symbolic procedure addpsf(u,v);
   if null u then v
    else if null v then u
    else if domainp ldpf u then addmpsf(u,v)
    else if domainp ldpf v then addmpsf(v,u)
    else if ldpf u = ldpf v then
       (lambda x,y;
        if null numr x then y else ldpf u .* x .+ y)
       (addsq(lc u,lc v),addpsf(red u,red v))
    else if ordpp(lpow ldpf u,lpow ldpf v) then lt u .+ addpsf(red u,v)
    else lt v .+ addpsf(u,red v);

symbolic procedure addpf(u,v);
   if null u then v
    else if null v then u
    else if ldpf u = 1 then addmpf(u,v)
    else if ldpf v = 1 then addmpf(v,u)
    else if ldpf u = ldpf v then
       (lambda x,y;
        if null numr x then y else ldpf u .* x .+ y)
       (addsq(lc u,lc v),addpf(red u,red v))
    else if ordop(ldpf u,ldpf v) then lt u .+ addpf(red u,v)
    else lt v .+ addpf(u,red v);

symbolic procedure addmpf(u,v);
   if null v then u
    else if ldpf v = 1 then 1 .* addsq(lc u,lc v) .+ nil
    else lt v .+ addmpf(u,red v);

symbolic procedure addmpsf(u,v);
   if null v then u else
   if domainp ldpf v then 1 .* addsq(multsq(ldpf u ./ 1,lc u),
                                     multsq(ldpf v ./ 1,lc v)) .+ nil
    else lt v .+ addmpsf(u,red v);

symbolic procedure multpsf(u,v);
   if null u or null v then nil
    else addpsf(addpsf(multtpsf(lt u,lt v),multpsf(red u,v)),
                multpsf(!*t2f lt u,red v));

symbolic procedure multpfs(u,v);
   if null u or null v then nil
    else if ldpf u = 1 then multpfsq(v,lc u)
    else if ldpf v = 1 then multpfsq(u,lc v)
    else addpf(addpf(multttpf(lt u,lt v),multpfs(red u,v)),
               multpfs(lt u .+ nil,red v));

symbolic procedure multttpf(u,v);
   if car u = 1 then car v .* multsq(tc u,tc v) .+ nil
    else if car v = 1 then car u .* multsq(tc u,tc v) .+ nil
    else rerror(excalc,10,"Illegal factor in pf");

symbolic procedure multpfsq(u,v);
   if null u or null numr v then nil
    else ldpf u .* multsq(lc u,v) .+ multpfsq(red u,v);

symbolic procedure multtpsf(u,v);
   begin scalar x,xexp;
    xexp := !*exp;
    !*exp := t;
    x := if car u = 1 then car v
          else if car v = 1 then car u
          else multf(tpsf u,tpsf v);
    !*exp := xexp;
   return multsqpsf(multsq(tc u,tc v),x .* (1 ./ 1)  .+ nil)
   end;

symbolic procedure multsqpsf(u,v);
   if null numr u or null v then nil
    else ldpf v .* multsq(u,lc v) .+ multsqpsf(u,red v);

symbolic procedure repartit u;
   if null u then nil
    else addpf(multpfsq(partitop ldpf u,lc u),repartit red u);

symbolic procedure partitsq!* u;
   %U is a standardquotient. Partitfunction for *sq's.
   %Leaves unexpanded structure if possible;
   (if null x then nil
     else if domainp x then 1 .* u .+ nil
     else addpf(if sfp mvar x and sfexform1p lt mvar x
                     then multpfsq(exptpf(partitsq!*(mvar x ./ 1),
                                         ldeg x),
                                   cancel(lc x ./ y))
                 else if null sfp mvar x and deg!*form mvar x
                          then mvar x .* cancel(lc x ./ y) .+ nil
                 else multpfsq(partitsq!*(lc x ./ y),
                               !*p2q lpow x),
                partitsq!*(red x ./ y)))
    where x = numr u, y = denr u;

symbolic procedure sfexform1p u;
   (if sfp tvar u then sfexform1p lt tvar u
     else deg!*form tvar u)
   or (null domainp tc u and sfexform1p lt tc u);

symbolic procedure !*pf2sq u;
   begin scalar res;
     res := nil ./ 1;
     if null u then return res;
     for each j on u do
       res := addsq(multsq(if ldpf j = 1 then 1 ./ 1
                            else !*k2q ldpf j,lc j),res);
     return res
   end;

symbolic procedure mk!*sqpf u;
   if null u then nil
    else ldpf u .* mk!*sq lc u .+ mk!*sqpf red u;

symbolic procedure !*pfsq2pf u;
   if null u then nil
    else (lambda x;
          if numr x
             then ldpf u .* x .+ !*pfsq2pf red u
           else !*pfsq2pf red u)
          simp!* lc u;

endmodule;


module vardf;

% Author: Eberhard Schruefer.

fluid '(depl!* kord!*);

global '(keepl!* bndeq!*);

symbolic procedure simpvardf u;
   if indvarpf numr simp0 cadr u then mksq('vardf . u,1)
    else begin scalar b,r,v,w,x,y,z;
         v := !*a2k cadr u;
         if null cddr u
          then w := intern compress append(explode '!',
                           explode if atom v then v
                                    else car v)
          else w := caddr u;
         if null atom v then w := w . cdr v;
         putform(w,prepf deg!*form v);
         kord!* := append(list(w := !*a2k w),kord!*);
         if x := assoc(v,depl!*) then
            for each j in cdr x do depend1(w,j,t);
         x := varysq(simp!* car u,v,w);
         b := y := nil ./ 1;
          while x do
              if (z := mvar ldpf x) eq w then
                              <<y := addsq(lc x,y);
                                x := red x>>
               else if eqcar(z,'wedge) then
                        if cadr z eq w then
                           <<y := addsq(multsq(!*k2q('wedge . cddr z),
                                               lc x),y);
                             x := red x>>
                         else if eqcar(cadr z,'d) then
                             <<y := addsq(simp list('wedge,list('d,
                                           list('times,'wedge . cddr z,
                                                 prepsq lc x))),y);
                               b := addsq(multsq(!*k2q('wedge . w .
                                                       cddr z),lc x),
                                          b);
                               x := red x>>
                        else rerror(excalc,11,list("Wrong ordering ",z))
               else if eqcar(z,'partdf) then
                     <<r := reval list('innerprod,
                                        list('partdf,caddr z),
                                        prepsq lc x);
                       x := addpsf((if cdddr z then
                                      !*k2f('partdf . w . cdddr z)
                                     else !*k2f w)
                                      .* negsq simp list('d,r)
                                      .+ nil,red x);
                       b := addsq(multsq(if cdddr z then
                                          !*k2q('partdf . w . cdddr z)
                                          else !*k2q w,simp r),b)>>
               else << b := addsq(multsq(simp cadr z,lc x),b);
                       x := red x>>;
     kord!* := cdr kord!*;
     bndeq!* := mk!*sq b;
     return y
     end;

put('vardf,'simpfn,'simpvardf);

put('vardf,'rtypefn,'getrtypeor);

put('vardf,'partitfn,'partitvardf);

symbolic procedure partitvardf u;
   partitsq!* simpvardf u;

symbolic procedure varysq(u,v,w);
   multpsf(addpsf(varyf(numr u,v,w),
                  multpsf(1 .* u .+ nil,varyf(negf denr u,v,w))),
           1 .* (1 ./ denr u) .+ nil);

symbolic procedure varyf(u,v,w);
   if domainp u then nil
    else addpsf(addpsf(multpsf(1 .* !*p2q lpow u .+ nil,
                               varyf(lc u,v,w)),
                       multpsf(varyp(lpow u,v,w),
                               1 .* (lc u ./ 1) .+ nil)),
                varyf(red u,v,w));

symbolic procedure varyp(u,v,w);
   begin scalar x,z; integer n;
       n := cdr u;
       u := car u;
       if u eq v then z := !*k2f w .* (1 ./ 1) .+ nil
        else if atomf u then
                if x := assoc(u,keepl!*) then
                   begin scalar alglist!*;
                         z := varysq(simp0 cdr x,v,w)
                   end
                 else if null atom u and null atom v then
                         if u=v then !*k2f w .* (1 ./ 1) .+ nil
                          else nil
                 else if null atom v then nil
                 else if depends(u,v) then
                         z := !*k2f w .* simp list('partdf,u,v) .+ nil
                 else nil
        else if sfp u then z := varyf(u,v,w)
        else if car u eq '!*sq then z := varysq(cadr u,v,w)
        else if x := get(car u,'dfn) then
                 for each j in
                    for each k in cdr u collect varysq(simp k,v,w)
                  do <<if j then
                        z := addpsf(multpsf(j,1 .* simp
                                     subla(pair(caar x,cdr u),cdar x)
                                   .+ nil),z);
                 x := cdr x>>
        else if x := get(car u,'varyfn) then z := apply3(x,cdr u,v,w)
        else if ndepends(u,v) then
                   z := !*k2f w .* simp list('partdf,u,v) .+ nil
        else nil;
   return if n=1 then z
           else multpsf(1 .* !*t2q((u to (n-1)) .* n) .+ nil,z)
   end;

symbolic procedure varywedge(u,v,w);
   begin scalar x,y,z;
   x := list 'wedge;
   for each j on u do
     <<y := varysq(simp car j,v,w);
       if y then
        z := addpsf(if deg!*form w then
                       !*a2f append(x,prepf ldpf y . cdr j)
                                      .* lc y .+ nil
                     else ldpf y .* multsq(1 ./ denr lc y,simp
                             append(x,prepf numr lc y . cdr j))
                             .+ nil,z);
       x := append(x,list car j)>>;
   return z
   end;

put('wedge,'varyfn,'varywedge);

symbolic procedure varyexdf(u,v,w);
   begin scalar x;
    for each j on varysq(simp car u,v,w) do
      if j then
       x := addpsf(!*a2f list('d,mvar ldpf j) .* lc j .+ nil,x);
   return x
   end;

put('d,'varyfn,'varyexdf);

symbolic procedure varyhodge(u,v,w);
   begin scalar x;
    for each j on varysq(simp car u,v,w) do
      if j then
       x := addpsf(!*a2f list('hodge,mvar ldpf j) .* lc j .+ nil,x);
   return x
   end;

put('hodge,'varyfn,'varyhodge);

symbolic procedure varypartdf(u,v,w);
   begin scalar x;
    for each j on varysq(simp car u,v,w) do
      if j then
       x := addpsf(!*a2f('partdf . mvar ldpf j . cdr u) .* lc j .+ nil,
                   x);
   return x
   end;

put('partdf,'varyfn,'varypartdf);

symbolic procedure simpnoether u;
   if indvarpf numr simp0 caddr u then mksq('noether . u,1)
    else begin scalar x,y;
           simpvardf list(car u,cadr u);
           x := simp!* bndeq!*;
           y := intern compress append(explode '!',
                                       explode if atom cadr u
                                                  then cadr u
                                                else caadr u);
           if null atom cadr u then y := y . cdadr u;
           y := list(y . list('liedf,caddr u,cadr u));
           return addsq(multsq(subf(numr x,y),1 ./ denr x),
                        negsq simp list('innerprod,caddr u,car u))
         end;

put('noether,'simpfn,'simpnoether);

symbolic procedure noetherind u;
   caddr u;

put('noether,'indexfun,'noetherind);

put('noether,'rtypefn,'getrtypeor);

endmodule;


module vecanalys;

%author: Eberhard Schruefer;

symbolic procedure basis u;
   cofram(for each j in u collect cdr j,nil);

rlistat '(basis);

symbolic procedure simpgrad u;
   simp!*('d . u);

put('grad,'simpfn,'simpgrad);

symbolic procedure simpcurl u;
   simp!* list('hodge,'d . u);

put('curl,'simpfn,'simpcurl);

symbolic procedure simpdiv u;
   simp!* list('hodge,list('d,'hodge . u));

put('div,'simpfn,'simpdiv);

newtok '((!. !* !.) crossprod);
infix crossprod;

symbolic procedure simpcrossprod u;
   simp!* list('hodge,'wedge . u);

put('crossprod,'simpfn,'simpcrossprod);

symbolic procedure simpdotprod u;
   simp!* list('hodge,list('wedge,car u,list('hodge,cadr u)));

put('cons,'simpfn,'simpdotprod);

symbolic procedure hodge3dpri u;
   %converts the form notation to vector notation for output;
   if caar u eq 'd then
        if eqcar(cadar u,'hodge) then maprin('div . cdadar u)
         else maprin('curl . cdar u)
    else if caar u eq 'wedge then
              if eqcar(cadar u,'hodge) then
                     inprint('cons,0,cdadar u)
               else inprint('crossprod,0,cdar u);

endmodule;


module wedge;

% Author: Eberhard Schruefer;

global '(dimex!* lftshft!* wedgemtch!*);

newtok '((!^) wedge);

flag('(wedge),'nary);

infix wedge;

precedence wedge,times;

smacro procedure wedgeordp(u,v); worderp(u,v);

put('wedge,'simpfn,'simpwedge);

put('wedge,'rtypefn,'getrtypeor);

put('wedge,'partitfn,'partitwedge);

symbolic procedure partitwedge u;
   if null cdr u then partitop car u
            else mkuniquewedge xpndwedge u;


symbolic procedure oddp m;
   fixp m and remainder(m,2)=1;

symbolic procedure mksgnsq u;
   if null (u := evenfree u) then 1 ./ 1
    else if u = 1 then (-1) ./ 1
    else simpexpt list(-1,mk!*sq(u ./ 1));

symbolic procedure evenfree u;
   if null u then nil
    else if numberp u then absf cdr qremd(u,2)
    else addf(absf cdr qremd(!*t2f lt u,2),evenfree red u);

symbolic procedure mkwedge u; !*k2pf u;

symbolic procedure wedgemtch u;
   begin scalar x,y,z;
     y := u;
     a: x := car y . x;
    if z := assoc(reverse x,wedgemtch!*) then
       return if cdr z then if cdr y then
                               'wedge . append(cdr z,cdr y)
                             else cdr z
               else 0;
    y := cdr y;
    if y then go to a else return nil
   end;


symbolic procedure simpwedge u;
   !*pf2sq partitwedge u;

symbolic procedure xpndwedge u;
   if null cdr u
      then mkunarywedge partitop car u
    else wedgepf2(partitop car u,xpndwedge cdr u);

symbolic procedure mkunarywedge u;
   if null u then nil
    else list ldpf u .* lc u .+ mkunarywedge red u;

symbolic procedure mkuniquewedge u;
   if null u then nil
    else addpf(multpfsq(mkuniquewedge1 ldpf u,lc u),
               mkuniquewedge red u);

symbolic procedure mkuniquewedge1 u;
   if null cdr u
      then mkupf car u
    else begin scalar x;
           return if wedgemtch!* and (x := wedgemtch u)
                     then partitop x
                   else mkupf('wedge . u)
         end;

symbolic procedure wedgepf2(u,v);
   %Basic binary exterior product routine.
   %v is an exterior product (without wedge tag), u a form.
   if null u or null v then nil
    else addpf(wedget2(lt u,lt v),
               addpf(wedgepf2(lt u .+ nil,red v),wedgepf2(red u,v)));

smacro procedure multwedgesq(u,v);
   %possible entry for lazy multiplication.
   multsq(u,v);

symbolic procedure wedget2(u,v);
   if car u = 1 then car v .* multsq(cdr u,cdr v) .+ nil
    else if caar v = 1 then list car u .* multsq(cdr u,cdr v) .+ nil
    else multpfsq(wedgek2(car u,car v,nil),multwedgesq(tc u,tc v));

symbolic procedure wedgek2(u,v,w);
   if u eq car v and null eqcar(u,'wedge)
      then if oddp deg!*form u then nil
            else multpfsq(wedgef(u . v),mksgnsq w)
    else if eqcar(car v,'wedge) then wedgek2(u,cdar v,w)
    else if eqcar(u,'wedge)
            then multpfsq(wedgewedge(cdr u,v),mksgnsq w)
    else if wedgeordp(u,car v)
            then multpfsq(wedgef(u . v),mksgnsq w)
    else if cdr v
            then wedgepf2(!*k2pf car v,
                          wedgek2(u,cdr v,addf(w,multf(deg!*form u,
                                                   deg!*form car v))))
    else multpfsq(wedgef list(car v,u),
                  mksgnsq addf(w,multf(deg!*form u,deg!*form car v)));

symbolic procedure wedgewedge(u,v);
   if null cdr u then wedgepf2(!*k2pf car u,!*k2pf v)
    else wedgepf2(!*k2pf car u,wedgewedge(cdr u,v));


symbolic procedure wedgef u;
     if dim!<deg u then nil
      else if eqcar(car u,'hodge) then
              (if m = deg!*farg cdr u then
                  multpfsq(wedgepf2(!*k2pf cadar u,
                                    mkunarywedge
                                     hodgepf if cddr u
                                              then mkuniquewedge1 cdr u
                                              else !*k2pf cadr u),
                           mksgnsq multf(m,addf(m,negf dimex!*)))
                else mkwedge u)
               where m = deg!*form cadar u
      else if eqcar(car u,'d) and (flagp('d,'noxpnd)
              or lftshftp cadar u) then
                    addpf(mkunarywedge dwedge(cadar u . cdr u),
                          multpfsq(wedgepf2(!*k2pf cadar u,
                                            mkunarywedge
                                              if cddr u
                                                 then dwedge cdr u
                                               else exdfk cadr u),
                                   negsq mksgnsq deg!*form cadar u))
      else mkwedge u;

endmodule;


end;
