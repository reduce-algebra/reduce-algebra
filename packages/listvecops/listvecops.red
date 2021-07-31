module listvecops;   % Vector operations on lists.

% Author: Eberhard Schruefer

% Copyright (c) 2014, Eberhard Schruefer.  All rights reserved.

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

% $Id$
create!-package('(listvecops),nil);

global '(cursym!*);

symbolic procedure listplus(u,v);
  begin scalar r,z;
    z := for each j in u collect reval1(j,v);
    while car z = 0 do z := cdr z;
    r := cdar z;
    z := cdr z;
    for each j in z do if j=0 then nil else if null eqcar(j,'list) 
                          then rederr "Only a list can be added to a list."
                        else r := listadd2(r,cdr j,v);
    return 'list . r
  end;

symbolic procedure listadd2(u,v,w);
   if null u then if v then rederr "Unequal length lists in add."
                   else nil
    else if null v then rederr "Unequal length lists in add."
    else reval1({'plus,car u,car v},w) . listadd2(cdr u,cdr v,w);

put('plus,'rtypefn,'getrtypeor); %This would allow for stricter type checking.
       
put('plus,'listfn,'listplus);

symbolic procedure listdifference(u,v);
  begin scalar x,y;
    x := reval1(car u,v);
    if null eqcar(x,'list) then rederr "Type error in difference.";
    x := cdr x;
    y := reval1(cadr u,v);
    if null eqcar(y,'list) then rederr "Type error in difference.";
    y := cdr y;
    if length x neq length y 
       then rederr "Not equal length lists found in difference.";
    return 'list . listdifference2(x,y,v)
  end;

symbolic procedure listdifference2(u,v,w);
   if null u then nil
    else reval1({'difference,car u,car v},w) . listdifference2(cdr u,cdr v,w);

put('difference,'listfn,'listdifference);

put('difference,'rtypefn,'getrtypeor); % This is different from the default.
                                       % It is needed to process aggregates.

symbolic procedure listminus(u,v);
   begin scalar x;
     x := reval1(car u,v);
     if null eqcar(x,'list) then return x;
     return 'list . for each j in cdr x collect reval1({'minus,j},v);
   end;

put('minus,'listfn,'listminus);

symbolic procedure listtimes(u,v); 
  begin scalar x,z;
     x := reval1(car u,v);
     for each j in cdr u do
         <<z := reval1(j,v);
           x := if eqcar(z,'list) 
                   then if eqcar(x,'list) then 'list . listtimes2(cdr x,cdr z,v)
                    else 'list . listtimes1(cdr z,x,v)
            else if eqcar(x,'list) then 'list . listtimes1(cdr x,z,v)
            else reval1({'times,x,z},v)>>;
     return x 
   end;

symbolic procedure listtimes1(u,v,w);
   for each j in u collect reval1({'times,j,v},w);

symbolic procedure listtimes2(u,v,w);
   if null u then if v then rederr "Unequal length lists found in times."
                   else nil
    else if null v then rederr "Unequal length lists found in times."
    else reval1({'times,car u,car v},w) . listtimes2(cdr u,cdr v,w);

put('times,'listfn,'listtimes); 

symbolic procedure listquotient(u,v);
  begin scalar x,y;
    x := reval1(car u,v);
    y := reval1(cadr u,v);
    return 'list . if null eqcar(x,'list) 
                     then for each j in cdr y collect reval1({'quotient,x,j},v)
                    else if eqcar(y,'list) then listquotient2(cdr x,cdr y,v)
                    else for each j in cdr x collect reval1({'quotient,j,y},v);
  end;

symbolic procedure listquotient2(u,v,w);
    if null u then if v then rederr "Unequal length lists found in quotient."
                   else nil
    else if null v then rederr "Unequal length lists found in quotient."
    else reval1({'quotient,car u,car v},w) . listquotient2(cdr u, cdr v,w);

put('quotient,'listfn,'listquotient);

symbolic procedure listexpt(u,v);
   begin scalar x,y;
     x := reval1(car u,v);
     y := reval1(cadr u,v);
     return 'list . if null eqcar(x,'list) 
                       then for each j in cdr y collect reval1({'expt,x,j},v)
                     else if null eqcar(y,'list) 
                       then for each j in cdr x collect reval1({'expt,j,y},v)
                     else listexpt2(cdr x,cdr y,v)
   end;

symbolic procedure listexpt2(u,v,w);
       if null u then if v then rederr "Unequal length lists found in expt."
                   else nil
    else if null v then rederr "Unequal length lists found in expt."
    else reval1({'expt,car u,car v},w) . listexpt2(cdr u,cdr v,w);

put('expt,'rtypefn,'getrtypeor);
put('expt,'listfn,'listexpt);

symbolic procedure listdotprod(u,v);
   begin scalar x,y;
     x := reval1(car u,v);
     y := reval1(cadr u,v);
     if null(eqcar(x,'list) and eqcar(y,'list)) 
        then rederr "Dot product can only be applied to two lists.";
     return mk!*sq listdotprod2(cdr x,cdr y);
   end;

symbolic procedure simpldot u;
   begin scalar x,y;
     x := reval1(car u,nil);
     y := reval1(cadr u,nil);
     if null(eqcar(x,'list) and eqcar(y,'list)) 
      then return multsq(simp x,simp y);
     return simp listdotprod2(cdr x,cdr y)
   end;

put('ldot,'simpfn,'simpldot);

symbolic procedure listdotprod2(u,v);
   begin scalar x;
     x := 0;
     a: if null u then if v 
           then rederr "Unequal length lists found in dot product."
                        else return x
         else if null v 
                 then rederr "Unequal length lists found in dot product.";
        x := reval1({'plus,reval1({'ldot,car u,car v},nil),x},nil);
        u := cdr u;
        v := cdr v;
        go to a
   end;

infix ldot;
precedence ldot,times;

newtok '((!* !.) ldot);

symbolic procedure listdf(u,v);
   begin scalar x;
     x := reval1(car u,v);
     return 'list . for each j in cdr x collect reval1('df . j . cdr u,v);
   end;

put('df,'listfn,'listdf);
put('df,'rtypefn,'getrtypecar);

symbolic procedure listint(u,v);
   begin scalar x;
     x := reval1(car u,v);
     return 'list . for each j in cdr x collect reval1('int . j . cdr u,v);
   end;

put('int,'listfn,'listint);
put('int,'rtypefn,'getrtypecar);

symbolic procedure listnth u;
   begin scalar n;
     n := reval1(cadr u,t);
     u := reval1(car u,t);
     return nth(cdr u,n)
   end;

put('lnth,'psopfn,'listnth);

put('lnth,'rtypefn,'(lambda (x) (quote yetunknowntype)));

% Provide underscore as an infix operator for part as an alternative to
% access list elements (as used by Rene).

infix lnth;
newtok '(( !_ ) lnth);
precedence lnth,times;


% The following allows for destructively changing elements
% of a list via lnth(l,j) := <exprn>.
% It would have been nice to interface the Lisp function nth
% to algebraic mode. However, using nth on the lhs on an
% assignment makes this awkward to do as the setqfn facility
% is mode less and one would need to write formfn's for the
% lower level functions involved. Therefore it is not done
% at the moment. 

symbolic procedure setlnth u;
   begin scalar l,i,x;
     l := cdr lntheval0 car u;
     i := reval cadr u;
     x := reval caddr u;
     setcar(pnth(l,i),x);
     rmsubs();
     return x
   end;

symbolic procedure lntheval0 u;
   begin scalar x;
     if atom u then if eqcar(x := get(u,'avalue),'list) 
                       then return cadr x
                     else rederr {u," is not a list"};
     if car u eq 'list then return u
      else if car u eq 'lnth 
        then return nth(lntheval0 cadr u,caddr u + 1);
     rederr {u," invalid expression for lnth"}
   end;

put('setlnth!*,'psopfn,'setlnth);

put('lnth,'setqfn,'(lambda (u v w) (setlnth!* u v w)));

% A lazy hack to allow for list procedures.
% 

symbolic procedure listprocify u;
  if atom u then u
  else if eqcar(u, 'procedure) then 'listproc . u
  else car u . for each a in cdr u collect listprocify a;

symbolic procedure readlistproc;
   begin
     scalar w;
     cursym!* := 'procedure;
     w := procstat1 'algebraic;
% Now w will be either       (procedure ...)
%                   or       (progn ... ... (procedure ...))
% where the first parts of the progn block establish file and line-number
% information.
     return listprocify w; 
   end;

put('listproc,'stat,'readlistproc);

symbolic procedure formlistproc(u,v,w);
   begin 
     return {'progn,
             formproc(cdr u,v,w),
             {'put,mkquote caddr u,''rtypefn,''(lambda(x) 'list)},
             {'put,mkquote caddr u,''listfn,
              {'list,''lambda,''(x y),
                     {'list,''listproceval,mkquote mkquote caddr u,''x,''y}}},
             {'remflag,{'list,mkquote caddr u},''opfn},
             mkquote caddr u}
   end;

put('listproc,'formfn,'formlistproc);

symbolic procedure listproceval(op,u,v);
   reval1(opfneval(op . u),v);
     

endmodule;

end;
