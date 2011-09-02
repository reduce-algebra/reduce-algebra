module part;  % Access and updates parts of an algebraic expression.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND. All rights reserved.

fluid '(!*intstr);

symbolic procedure revalpart u;
   begin scalar !*intstr,expn,v,z;
      !*intstr := t;   % To make following result in output form.
      expn := if (z := getrtype car u) eq 'list then listeval0 car u
               else reval car u;
      !*intstr := nil;
      v := cdr u;
      while v do
         begin scalar x,y;
           if atom expn then parterr(expn,car v)
            else if not numberp(x := reval car v)
             then msgpri("Invalid argument",car v,"to part",nil,t)
	    else if (y := get(car expn,'partop))
	     then return <<expn := apply2(y,expn,x); v := cdr v>>
            else if x=0
              then return <<expn :=
                              (if (getrtype w eq 'list) and (z := 'list)
                                 then listeval0 w
                                else if z eq 'list
                                 then <<!*intstr := t; w := reval w;
                                        !*intstr := z := nil; w>>
                                else w) where w = car expn;
                           v := nil>>
            else if x<0 then <<x := -x; y := reverse cdr expn>>
	    else y := cdr expn;
           if length y<x then parterr(expn,car v)
            else expn := (if (getrtype w eq 'list) and (z := 'list)
                            then listeval0 w
                           else if z eq 'list
                            then <<!*intstr := t; w := reval w;
                                   !*intstr := z := nil; w>>
                           else w) where w = nth(y,x);
           v := cdr v
        end;
      return reval expn
   end;

put('part,'psopfn,'revalpart);

flag('(part),'immediate);

symbolic procedure revalsetpart u;
   % Simplifies a SETPART expression.
   begin scalar !*intstr,x,y;
      x := reverse cdr u;
      !*intstr := t;
      y := reval car u;
      !*intstr := nil;
      return  revalsetp1(y,reverse cdr x,reval car x)
   end;

symbolic procedure revalsetp1(expn,ptlist,rep);
   if null ptlist then rep
    else if atom expn
             then msgpri("Expression",expn,
                         "does not have part",car ptlist,t)
    else begin scalar x,y;
      if not numberp(x := reval car ptlist)
             then msgpri("Invalid argument",car ptlist,"to part",nil,t)
       else return 
	if y := get(car expn,'setpartop) then apply3(y,expn,ptlist,rep)
         else if x=0 then rep . cdr expn
         else if x<0
          then car expn . 
                reverse ssl(reverse cdr expn,
                            -x,cdr ptlist,rep,expn . car ptlist)
         else car expn . ssl(cdr expn,x,cdr ptlist,
                             rep,expn . car ptlist)
   end;

symbolic procedure ssl(expn,indx,ptlist,rep,rest);
   if null expn
     then msgpri("Expression",car rest,"does not have part",cdr rest,t)
    else if indx=1 then revalsetp1(car expn,ptlist,rep) . cdr expn
    else car expn . ssl(cdr expn,indx-1,ptlist,rep,rest);

put('part,'rtypefn,'rtypepart);

symbolic procedure rtypepart u;
   if getrtypecar u then 'yetunknowntype else nil;
 
% symbolic procedure rtypepart(u);
%   if null cdr u then getrtypecar u
%    else begin scalar x,n;
%       x := car u;
%       if idp x then <<x := get(car u,'avalue);
%                       if x then x := cadr x>>;
%       if eqcar(x,'list) and numberp (n := aeval cadr u)
%         then return rtypepart(nth(cdr x,n) . cddr u)
%    end;
 
% put('part,'setqfn,'(lambda (u v w) (setpart!* u v w)));

put('setpart!*,'psopfn,'revalsetpart);

symbolic procedure arglength u;
   begin scalar !*intstr,x;
      if null u then return 0;
      !*intstr := t;
      x := reval u;
      return if atom x then -1 else length cdr x
   end;

flag('(arglength),'opfn);

flag('(arglength),'noval);

endmodule;

end;
