module exaux;

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

end;
