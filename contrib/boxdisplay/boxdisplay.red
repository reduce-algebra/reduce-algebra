symbolic$

symbolic smacro procedure
  MakeDisplayBox(h,d,w,exp,op,args,parens!?,p,enc);
    list('Display!-Box,h,d,w,exp,op,args,parens!?,p,enc)$

symbolic smacro procedure CopyDisplayBox b;
  append(b,nil)$

symbolic smacro procedure BoxHeight box;
  cadr box$

symbolic smacro procedure BoxDepth box;
  caddr box$

symbolic smacro procedure BoxWidth box;
  cadddr box$

symbolic smacro procedure BoxExpression box;
  car cddddr box$

symbolic smacro procedure BoxOperator box;
  cadr cddddr box$

symbolic smacro procedure BoxArgList box;
  caddr cddddr box$

symbolic smacro procedure BoxIsParenthesized box;
  cadddr cddddr box$

symbolic smacro procedure BoxPenalty box;
  car cddddr cddddr box$

symbolic smacro procedure BoxIsNonBreakable box;
  null BoxPenalty box$

symbolic smacro procedure BoxEnclosingBox box;
  cadr cddddr cddddr box$

symbolic smacro procedure SetHeight(box,h);
  rplaca(cdr box,h)$

symbolic smacro procedure SetDepth(box,d);
  rplaca(cddr box,d)$

symbolic smacro procedure SetWidth(box,w);
  rplaca(cdddr box,w)$

symbolic smacro procedure SetExpression(box,exp);
  rplaca(cddddr box,exp)$

symbolic smacro procedure SetOperator(box,op);
  rplaca(cdr cddddr box,op)$

symbolic smacro procedure SetArgList(box,args);
  rplaca(cddr cddddr box,args)$

symbolic smacro procedure SetIsParenthesized(box,p);
  rplaca(cdddr cddddr box,p)$

symbolic smacro procedure SetPenalty(box,p);
  rplaca(cddddr cddddr box,p)$

symbolic smacro procedure SetEnclosingBox(box,enc);
  rplaca(cdr cddddr cddddr box,enc)$

symbolic smacro procedure IsAtomDisplayBox box;
  atom BoxExpression box$

symbolic smacro procedure ParenHeight(h,d);
  max(h,d+1)$

symbolic smacro procedure ParenDepth(h,d);
  max(h-1,d)$

symbolic smacro procedure ParenWidth(h,d);
  if h > 1 or d > 0 then 2 else 1$

symbolic procedure BuildDisplayBox (exp,parens!?);
  if atom exp then BuildAtomDisplayBox exp
   else begin scalar op,opp;
     op := car exp;
     opp := get(op,'BuildDisplayBox);
     return if not null opp then apply3(opp,op,exp,parens!?)
             else if not null get(op,'infix)
              then BuildInfixDisplayBox(op,exp,parens!?)
             else BuildOpDisplayBox(op,exp,parens!?);
   end$

symbolic procedure BuildAtomDisplayBox exp;
  MakeDisplayBox(1,0,lengthc exp,exp,nil,nil,nil,nil,nil)$

symbolic smacro procedure OpHeight op;
  1$

symbolic smacro procedure OpDepth op;
  0$

symbolic smacro procedure OpWidth op;
  begin scalar prt;
    prt := get(op,'prtch);
    prt := if null prt then op else prt;
    return if flagp(op,'spaced) then lengthc prt + 2
            else lengthc prt
  end$

symbolic smacro procedure HasPrecedenceOp(op1,op2);
  get(op1,'infix) >= get(op2,'infix)$

symbolic smacro procedure HasPrecedenceExp(op,subexp);
  if atom subexp or null get(op,'infix) then nil
   else HasPrecedenceOp(op,car subexp)$

symbolic procedure BuildOpDisplayBox(op,exp,parens!?);
  begin scalar arglist,argl; integer h,d,w,pwidth,pos;
    arglist := for each arg in cdr exp collect
      BuildDisplayBox(arg,HasPrecedenceExp(op,arg));
    h := OpHeight op; d := OpDepth op; w := OpWidth op;
    for each arg in arglist do <<
      if BoxHeight arg > h then h := BoxHeight arg;
      if BoxDepth arg > d then d := BoxDepth arg >>;
    if parens!? then <<
      h := max(h,ParenHeight(h,d));
      d := max(d,ParenDepth(h,d)) >>;
    pwidth := ParenWidth(h,d);
    pos := w + pwidth;
    for each arg in arglist do <<
      argl := list(pos,0,arg) . argl;
      pos := pos + BoxWidth arg + 1 >>;
    arglist := reversip argl;
    w := pos - 1 + pwidth;
    return MakeDisplayBox(h,d,w,exp,op,arglist,parens!?,0,nil)
  end$

symbolic procedure BuildInfixDisplayBox(op,exp,parens!?);
  if null cddr exp then begin scalar x;
     x := get(op,'unary);
     if null x then return BuildOpDisplayBox(op,exp,parens!?)
      else return BuildUnaryDisplayBox(x,exp,parens!?)
    end
   else BuildNaryDisplayBox(op,exp,parens!?)$


symbolic procedure BuildNaryDisplayBox(op,exp,parens!?);
  begin scalar arglist,argl; integer h,d,w,pos;
    arglist := for each arg in cdr exp collect
      BuildDisplayBox(arg,HasPrecedenceExp(op,arg));
    h := OpHeight op; d := OpDepth op; w := OpWidth op;
    for each arg in arglist do <<
      if BoxHeight arg > h then h := BoxHeight arg;
      if BoxDepth arg > d then d := BoxDepth arg >>;
    if parens!? then <<
      h := max(h,ParenHeight(h,d));
      d := max(d,ParenDepth(h,d)) >>;
    pos := if parens!? then ParenWidth(h,d) else 0;
    argl := list list(pos,0,car arglist);
    pos := pos + BoxWidth car arglist;
    for each arg in cdr arglist do <<
      if not (op eq get(BoxOperator arg,'alt)) then pos := pos + w;
      argl := list(pos,0,arg) . argl;
      pos := pos + BoxWidth arg >>;
    if parens!? then pos := pos + ParenWidth(h,d);
    return MakeDisplayBox(h,d,pos,exp,op,reversip argl,parens!?,0,nil)
  end$


symbolic procedure BuildUnaryDisplayBox(op,exp,parens!?);
  begin scalar arg,argl; integer h,d,w,pos;
    arg := cadr exp;
    arg := BuildDisplayBox(arg,HasPrecedenceExp(op,arg));
    h := OpHeight op; d := OpDepth op; w := OpWidth op;
    if BoxHeight arg > h then h := BoxHeight arg;
    if BoxDepth arg > d then d := BoxDepth arg;
    if parens!? then <<
      h := max(h,ParenHeight(h,d));
      d := max(d,ParenDepth(h,d)) >>;
    pos := if parens!? then w + ParenWidth(h,d) else w;
    argl := list(list(pos,0,arg));
    pos := pos + BoxWidth arg;
    if parens!? then pos := pos + ParenWidth(h,d);
    return MakeDisplayBox(h,d,pos,exp,op,argl,parens!?,0,nil)
  end$


symbolic procedure BuildExptDisplayBox(op,exp,parens!?);
  begin scalar base,exponent; integer h,d,w,pos;
    base := BuildDisplayBox(cadr exp,not atom cadr exp);
    exponent := BuildDisplayBox(caddr exp,not atom caddr exp);
    w := BoxWidth base + BoxWidth exponent;
    d := BoxDepth base;
    h := BoxHeight base + BoxDepth exponent + BoxHeight exponent;
    if parens!? then <<
      h := max(h,ParenHeight(h,d));
      d := max(d,ParenDepth(h,d)) >>;
    pos := if parens!? then ParenWidth(h,d) else 0;
    return
      MakeDisplayBox(h,d,w,exp,op,
                     list(list(pos,0,base),
                          list(pos + BoxWidth base,
                               BoxHeight base + BoxDepth exponent,
                               exponent)),
                     parens!?,nil,nil)
  end$

put('expt,'BuildDisplayBox,'BuildExptDisplayBox)$

symbolic procedure BuildQuotientDisplayBox(op,exp,parens!?);
  begin scalar numer,denom; integer h,d,w,pos1,pos2;
    numer := BuildDisplayBox(cadr exp,nil);
    denom := BuildDisplayBox(caddr exp,nil);
    w := max(BoxWidth numer,BoxWidth denom);
    if w = BoxWidth numer then <<
      pos1 := 1;
      pos2 := 1 + (BoxWidth numer - BoxWidth denom) / 2 >>
     else <<
      pos1 := 1 + (BoxWidth denom - BoxWidth numer) / 2;
      pos2 := 1 >>;
    h := BoxHeight numer + BoxDepth numer + 1;
    d := BoxHeight denom + BoxDepth denom;
    if parens!? then <<
      h := max(h,ParenHeight(h,d));
      d := max(d,ParenDepth(h,d));
      pos1 := pos1 + ParenWidth(h,d);
      pos2 := pos2 + ParenWidth(h,d) >>;
    return
      MakeDisplayBox(h,d,w+2,exp,op,
                     list(list(pos1,BoxDepth numer + 1,numer),
                          list(pos2,-BoxHeight denom,denom)),
                     parens!?,nil,nil)
  end$

put('quotient,'BuildDisplayBox,'BuildQuotientDisplayBox)$


symbolic procedure BuildIntDisplayBox(op,exp,parens!?);
  begin scalar integrand,var; integer h,d,w,pos;
    integrand := BuildDisplayBox(cadr exp,nil);
    var := BuildDisplayBox(caddr exp,nil);
    h := max(BoxHeight integrand,BoxHeight var);
    d := max(BoxDepth integrand,BoxDepth var);
    h := max(h,d+1); %max(IntSignHeight(h,d),h);
    d := h-1;        %max(IntSignDepth(h,d),d);
    w := BoxWidth integrand + BoxWidth var + 5;
    pos := BoxWidth integrand + 5;
    if parens!? then <<
      w := w + 2*ParenWidth(h,d);
      pos := pos + ParenWidth(h,d) >>;
    return
      MakeDisplayBox(h,d,w,exp,op,
                     list(list(ParenWidth(h,d) + 3,0,integrand),
                          list(pos,0,var)),
                     parens!?,nil,nil)
  end$


put('int,'BuildDisplayBox,'BuildIntDisplayBox)$


symbolic procedure BreakDisplayBox(box,width!-goal);
  if BoxWidth box <= width!-goal then nil . box
   else if BoxIsNonBreakable box
    then rederr("not implemented (breaking special display box)")
% BreakSpecialDisplayBox(box,width!-goal)
   else begin scalar x,y,z; integer offset;
     x := BoxArgList box;
     if null cdr x then return 
       ((for each pos
           in car BreakDisplayBox(caddr car x,width!-goal - car car x)
             collect (pos + car car x)) . box);
    loop:
     y := car x;
     x := cdr x;
     if null x then goto exitloop;
     if car car x - offset > width!-goal then <<
       offset := car y;
       z := car y . z;
       if BoxWidth caddr y > width!-goal then
         for each pos in car BreakDisplayBox(caddr y,width!-goal) do
           z := (offset := (car y + pos)) . z >>;
     goto loop;
    exitloop:
     if car y + BoxWidth caddr y - offset > width!-goal
       then if BoxWidth caddr y <= width!-goal
              then z := car y . z
             else for each pos in 
                    car BreakDisplayBox(caddr y,width!-goal) do
                z := (offset := (car y + pos)) . z;
     return reversip z . box
   end$



symbolic smacro procedure IsSpecialDisplayBox box;
  get(BoxOperator box,'InsertDisplayBox)$

fluid '(!*DisplayArrayDepth!*)$

symbolic smacro procedure GetLine(disparray,n);
  getv(disparray,n + !*DisplayArrayDepth!*)$

symbolic procedure InsertLeftParen(disparray,x,y,h,d);
  if h=1 and d=0 then PutChar(GetLine(disparray,y),x,'!()
   else begin integer p;
     p := ParenHeight(h,d) - 1;
     for i := -p+1 : p-1 do PutChar(GetLine(disparray,y+i),x,'!|);
     PutChar(GetLine(disparray,y+p),x,'!/);
     PutChar(GetLine(disparray,y-p),x,'!\);
   end$

symbolic procedure InsertRightParen(disparray,x,y,h,d);
  if h=1 and d=0 then PutChar(GetLine(disparray,y),x,'!))
   else begin integer p;
     x := x + 1;
     p := ParenHeight(h,d) - 1;
     for i := -p+1 : p-1 do PutChar(GetLine(disparray,y+i),x,'!|);
     PutChar(GetLine(disparray,y+p),x,'!\);
     PutChar(GetLine(disparray,y-p),x,'!/);
   end$

symbolic smacro procedure InsertParens(disparray,x1,x2,y,h,d);
  << InsertLeftParen(disparray,x1,y,h,d);
     InsertRightParen(disparray,x2,y,h,d) >>$


symbolic procedure InsertDisplayBox(box,disparray,x,y);
  begin integer h,d,w,l,argl; scalar u,v;
    h := BoxHeight box; d := BoxDepth box; w := BoxWidth box;
    if IsAtomDisplayBox box then <<
      u := explode2 BoxExpression box;
      v := GetLine(disparray,y);
      for i := 0 : w-1 do
        << PutChar(v,x+i,car u); u := cdr u >> >>
     else if IsSpecialDisplayBox box
      then apply(get(BoxOperator box,'InsertDisplayBox),
                 list(box,disparray,x,y))
     else if not null get(BoxOperator box,'infix)
      then InsertInfixDisplayBox(box,disparray,x,y)
     else <<
      u := explode2 BoxOperator box;
      l := length u;
      v := GetLine(disparray,y);
      for i := 0 : l-1 do << PutChar(v,x+i,car u); u := cdr u >>;
      PutChar(v,x+l,'!();
      argl := BoxArgList box;
      while not null cdr argl do begin integer x1,y1;
        x1 := x + car car argl;
        y1 := y + cadr car argl;
        InsertDisplayBox(caddr car argl,disparray,x1,y1);
        PutChar(v,x1 + BoxWidth caddr car argl,'!,);
        argl := cdr argl;
      end;
      InsertDisplayBox(caddr car argl,disparray,
                       x + car car argl,y + cadr car argl);
      PutChar(v,x+w-1,'!)) >>
  end$

symbolic procedure MakeDisplayArray box;
  begin scalar x,y; integer h,d,w;
    h := BoxHeight box; d := BoxDepth box; w := BoxWidth box;
    x := mkvect (h+d-1);
    for i := 0 : h+d-1 do <<
      y := mkvect (w-1);
      for j := 0 : w-1 do PutChar(y,j,'! );
      PutChar(x,i,y) >>;
    InsertDisplayBox(box,x,0,0) where !*DisplayArrayDepth!* := d;
    return x
  end$

symbolic procedure InsertInfixDisplayBox(box,disparray,x,y);
  if null cddr BoxExpression box
    then InsertUnaryDisplayBox(box,disparray,x,y)
   else InsertNaryDisplayBox(box,disparray,x,y)$


symbolic procedure InsertUnaryDisplayBox(box,disparray,x,y);
  begin integer h,d,w,l,x1,y1,x2; scalar u,v,arg,b;
    h := BoxHeight box; d := BoxDepth box; w := BoxWidth box;
    u := get(BoxOperator box,'prtch);
    u := explode2 if null u then BoxOperator box else u;
    if flagp(BoxOperator box,'spaced)
      then u := '!  . reversip ('!  . reversip u);
    l := length u - 1;
    v := GetLine(disparray,y);
    arg := car BoxArgList box;
    if BoxIsParenthesized box then <<
      InsertParens(disparray,x,x2,y,h,d);
      x1 := x + ParenWidth(h,d);
      x2 := x + w - ParenWidth(h,d) >>
     else << x1 := x; x2 := x + w >>;
    for i := 0 : l do PutChar(v,x1+i,nth(u,i+1));
    InsertDisplayBox(caddr arg,disparray,x + car arg,y + cadr arg);
  end$

symbolic procedure InsertNaryDisplayBox(box,disparray,x,y);
  begin integer h,d,w,l,x1,y1,x2,op; scalar u,v,argl,b;
    h := BoxHeight box; d := BoxDepth box; w := BoxWidth box;
    op := BoxOperator box;
    u := get(op,'prtch);
    u := explode2 if null u then op else u;
    if flagp(op,'spaced)
      then u := '!  . reversip ('!  . reversip u);
    l := length u - 1;
    v := GetLine(disparray,y);
    argl := BoxArgList box;
    while not null cdr argl do <<
      x1 := x + car car argl;
      y1 := y + cadr car argl;
      b := caddr car argl;
      argl := cdr argl;
      InsertDisplayBox(b,disparray,x1,y1);
      x2 := x1 + BoxWidth b;
      if not (op eq get(BoxOperator caddr car argl,'alt))
        then for i := 0 : l do PutChar(v,x2+i,nth(u,i+1)) >>;
    x1 := x + car car argl;
    InsertDisplayBox(caddr car argl,disparray,x1,y + cadr car argl);
    if BoxIsParenthesized box then 
      InsertParens(disparray,x,x1 + BoxWidth caddr car argl,y,h,d);
  end$


symbolic procedure InsertExptDisplayBox(box,disparray,x,y);
  << InsertDisplayBox(caddr car BoxArgList box,disparray,x,y);
     InsertDisplayBox(caddr cadr BoxArgList box,disparray,
                      x + car cadr BoxArgList box,
                      y + cadr cadr BoxArgList box) >>$

put('expt,'InsertDisplayBox,'InsertExptDisplayBox)$


symbolic procedure InsertQuotientDisplayBox(box,disparray,x,y);
  begin scalar numer,denom; integer first,last;
    numer := car BoxArgList box;
    denom := cadr BoxArgList box;
    InsertDisplayBox(caddr numer,disparray,
                     x + car numer,y + cadr numer);
    InsertDisplayBox(caddr denom,disparray,
                     x + car denom,y + cadr denom);
    first := if BoxIsParenthesized box
               then ParenWidth(BoxHeight box,BoxDepth box)
              else 0;
    last := BoxWidth box - first - 1;
    for i := first : last do
      PutChar(GetLine(disparray,y),x + i,'!-)
  end$

put('quotient,'InsertDisplayBox,'InsertQuotientDisplayBox)$


symbolic procedure InsertIntDisplayBox(box,disparray,x,y);
  begin integer h,d,p;
    h := BoxHeight box; d := BoxDepth box;
    p := ParenHeight(h,d) - 1;
    for i := -p+1 : p-1 do
      PutChar(GetLine(disparray,y+i),x+1,'!|);
    PutChar(GetLine(disparray,y+p),x+1,'!/);
    PutChar(GetLine(disparray,y-p),x+1,'!/);
    InsertDisplayBox(caddr car BoxArgList box,disparray,x+3,y);
    p := car cadr BoxArgList box;
    PutChar(GetLine(disparray,y),p-1,'d);
    InsertDisplayBox(caddr cadr BoxArgList box,disparray,x+p,y);
    if BoxIsParenthesized box then
      InsertParens(disparray,x,x+p+BoxWidth cadr BoxArgList box,y,h,d)
  end$


put('int,'InsertDisplayBox,'InsertIntDisplayBox)$


symbolic procedure PrintDisplayArray disparray;
  << for i := upbv disparray step -1 until 0 do begin scalar v;
       v := getv(disparray,i);
       terpri();
       for j := 0 : upbv v do princ getv(v,j)
     end;
     terpri() >>$

fluid '(!*LeftMargin!* !*RightMargin!*)$

!*LeftMargin!* := 0$
!*RightMargin!* := linelength nil$

symbolic procedure PutChar(line,x,c);
  if x>=!*LeftMargin!* and x<!*RightMargin!*
    then putv(line,x-!*LeftMargin!*,c)$

symbolic procedure
  MakePartialDisplayArray(box,!*LeftMargin!*,!*RightMargin!*);
    begin scalar x,y; integer h,d,w;
      h := BoxHeight box; d := BoxDepth box;
      w := !*RightMargin!* - !*LeftMargin!*;
      x := mkvect (h+d-1);
      for i := 0 : h+d-1 do <<
        y := mkvect (w-1);
      for j := 0 : w-1 do putv(y,j,'! );
      putv(x,i,y) >>;
      InsertDisplayBox(box,x,0,0) where !*DisplayArrayDepth!* := d;
      return x
    end$

symbolic procedure PrintPrefixForm u;
  begin scalar b,breaks; integer l,r;
    b := BuildDisplayBox(u,nil);
    breaks := car BreakDisplayBox(b,linelength nil);
    if null breaks then 
      PrintDisplayArray MakePartialDisplayArray(b,0,BoxWidth b)
     else <<
      breaks := append(breaks,list BoxWidth b);
      l := 0;
      while breaks do <<
        r := car breaks;
        PrintDisplayArray MakePartialDisplayArray(b,l,r);
        l := r;
        breaks := cdr breaks >> >>
  end$


end;
