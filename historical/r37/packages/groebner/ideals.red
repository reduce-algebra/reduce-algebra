module ideals;          % operators for polynomial ideals.

% Author: Herbert Melenk.

% Copyright (c) 1992 The RAND Corporation and Konrad-Zuse-Zentrum.
% All rights reserved.

create!-package('(ideals),'(contrib groebner));

imports groebner;

load!-package 'groebner;

fluid '(gb!-list!*);

global '(id!-vars!*);

share id!-vars!*;

symbolic procedure i!-setting u;
  begin scalar o;
    o := id!-vars!*;
    id!-vars!* := 'list . for each x in u collect reval x;
    gb!-list!* := nil;
    return o;
  end;

put('i_setting,'psopfn,'i!-setting);

algebraic operator I;

symbolic procedure ideal2list u;
   'list . cdr test!-ideal u;

symbolic operator ideal2list;

symbolic procedure GB u;
  begin scalar v,w;
    u:= test!-ideal reval u;
    v:={u,id!-vars!*,vdpsortmode!*};
    w:=assoc(v,gb!-list!*);
    return if w then cdr w else GB!-new u;
  end;

symbolic procedure GB!-new u;
  begin scalar v,w;
    u:= test!-ideal reval u;
    v:={u,id!-vars!*,vdpsortmode!*};
    w:='I . cdr groebnereval{'list . cdr u,id!-vars!*};
    gb!-list!* := (v.w) . gb!-list!*;
    gb!-list!* := ((w.cdr v).w) . gb!-list!*;
    return w;
  end;

symbolic operator GB;

symbolic procedure test!-ideal u;
  if not eqcar(id!-vars!*,'list) then 
      typerr(id!-vars!*,"ideal setting; set variables first")
    else
  if eqcar(u,'LIST) then 'I.cdr u
    else
  if not eqcar(u,'I) then typerr(u,"polynomial ideal") 
        else u;

symbolic procedure idealp u;
       eqcar(u,'I) or eqcar(u,'list);

symbolic operator idealp;

newtok '((!. !=) id!-equal);
algebraic operator id!-equal;
infix id!-equal;
precedence id!-equal,=;

symbolic procedure GB!-equal(a,b);
       if gb a = gb b then 1 else 0;

symbolic operator GB!-equal;

algebraic << let (~a .= ~b) => GB!-equal(a,b)
               when idealp a and idealp b>>;

symbolic procedure GB!-member(p,u);
  if 0=preduceeval{p,ideal2list GB u,id!-vars!*} then 1 else 0;

symbolic operator GB!-member;

algebraic operator member;

algebraic << let ~a member ~b => GB!-member(a,b)
               when idealp b>>;

symbolic procedure GB!-subset(a,b);
   begin scalar q;
     q:= t;
     a:=cdr test!-ideal reval a;
     b:=ideal2list GB b;
     for each p in a do 
      q:=q and 0=preduceeval{p,b,id!-vars!*};
     return if q then 1 else 0;
   end;

symbolic operator GB!-subset;

algebraic operator subset;

infix subset;
precedence subset,member;

algebraic << let (~a subset ~b) => GB!-subset(a,b)
               when idealp a and idealp b>>;

symbolic procedure GB!-plus(a,b);
    <<a := cdr test!-ideal reval a;
      b := cdr test!-ideal reval b;
     gb ('I.append(a,b))
    >>;

symbolic operator GB!-plus;

algebraic operator .+;

algebraic << let (~a .+ ~b) => GB!-plus(a,b)
               when idealp a and idealp b>>;

symbolic procedure GB!-times(a,b);
    <<a := cdr test!-ideal reval a;
      b := cdr test!-ideal reval b;
     gb ('I.
      for each p in a join 
       for each q in b collect
        {'times,p,q})
    >>;

symbolic operator GB!-times;

algebraic operator .*;

algebraic << let (~a .* ~b) => GB!-times(a,b)
               when idealp a and idealp b>>;

symbolic procedure GB!-intersect(a,b);
   begin scalar tt,oo,q,v;
      tt:='!-!-t; v:= id!-vars!*;
      oo := eval '(torder '(lex));
      a := cdr test!-ideal reval a;
      b := cdr test!-ideal reval b;
      q:='I. append(
       for each p in a collect {'times,tt,p},
       for each p in b collect {'times,{'difference,1,tt},p});
      id!-vars!* := 'list . tt. cdr id!-vars!*;
      q:= errorset({'gb,mkquote q},nil,!*backtrace);
      id!-vars!* := v;
      eval{'torder,mkquote{oo}};
      if errorp q then rederr "ideal intersection failed";
      q:=for each p in cdar q join if not smemq(tt,p) then {p};
      return gb('I . q);
   end;

symbolic operator GB!-intersect;

algebraic operator intersection;

algebraic << let intersection (~a , ~b) => GB!-intersect(a,b)
               when idealp a and idealp b>>;


newtok '((!. !:) id!-quotient);
algebraic operator id!-quotient;
infix id!-quotient;
precedence id!-quotient,/;

symbolic procedure GB!-quotient(a,b);
    <<a := test!-ideal reval a;
      b := test!-ideal reval b;
      GB!-quotient1(a,cdr b)>>;

symbolic procedure GB!-quotient1(a,b);
   begin scalar q;
     q:='I.cdr idquotienteval{ideal2list a,car b,id!-vars!*};
     return if null cdr b then q else
       GB!-intersect(q,GB!-quotient1(a,cdr b));
   end;

symbolic operator GB!-quotient;
algebraic operator over;

algebraic << let (~a ./ ~b) => GB!-quotient(a,b)
               when idealp a and idealp b>>;

algebraic << let (~a .: ~b) => GB!-quotient(a,b)
               when idealp a and idealp b>>;

endmodule;

end;
