% mathtex.red                     Rainer Schoepf and Arthur Norman 2015


% The aim in due course is to convert algebraic expressions into
% a layout that would be a reasonable approximation to the one that
% TeX would have used. This builds on the code in boxdisplay.red that
% Rainer had written, but will now take a much more agressive line in
% positioning characters based on metrics from the STIX family of
% Unicode fonts.

symbolic$

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% During initial development I wan to be able to test by loading just
% this file into Reduce. So I will cause that to read in the other
% things I need... In the fullness of time and if things end up working
% well a tidier build scheme will be established.

on comp, backtrace;

in "charmetrics.red"$
in "uninames.red"$


#if (memq 'psl lispsystem!*)

% This will only be used on numbers here, so issues of Unicode do
% not intrude.

symbolic procedure explodecn u;
  for each x in explode2 u collect car id2list x;

#endif

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Question: With this many components should a Display_Box be
% converted to be represented as a vector or a tree-like structure
% rather than a rather long list? Well that is just a performance not
% a functionality issue so not to be fussed about just now!

symbolic inline procedure
  MakeDisplayBox(h,d,w,exp,op,args,parens!?,p,enc);
    list('Display_Box,h,d,w,exp,op,args,parens!?,p,enc)$

% The "accessors" statement defines the names functions to access
% parts of the data structure. It also defines functions with name such
% as set_BoxHeight for updating the structure, and arranges that Reduce
% can recognize the selectors on the left hand side of an assigment
% statement so that e.g.
%    BoxHeight b := ...
% becomes valid.

accessors (!_ . (BoxHeight . (BoxDepth . (BoxWidth . (BoxExpression .
                (BoxOperator . (BoxArgList . (BoxIsParenthesized .
                (BoxPenalty . (BoxEnclosingBox . !_))))))))))$

symbolic inline procedure CopyDisplayBox b;
  append(b,nil)$

symbolic inline procedure BoxIsNonBreakable box;
  null BoxPenalty box$

symbolic inline procedure IsAatomDisplayBox box;
  atom BoxExpression box$

% The current plan is that all measurements built into boxes here will be
% in units of 1/1000th of a point or possibly pixel. The metric information
% I have about fonts is based on a 1000-unit high character cell. I will scale
% these measurements by the font size in points. Now a quick sketch of the
% balance between accuracy and overflow. An A4 page at a resolution of 1200
% dpi has around 13 million pixels from top to bottom and that fits within
% 24-bits (ie comfortably within a CSL fixnum, and even more comfortably
% within a C 32-bit word). The smallest point size I think it could make sense
% to display would be 5pt, and at that the x height would end up at around
% 2500 units - on a reasonable screen it is more likely that characters will
% end up around 10000 units tall. I think that that means that rounding errors
% due to fixed point measurements will not be important at all. In particular
% rounding and conversion at the point of final rendering will be a much
% greater risk - especially on-screen but even when displaying on high
% resolution printers with characters ending up up to an inch tall.


symbolic inline procedure ParenHeight(h,d);
  max(h,d+1)$

symbolic inline procedure ParenDepth(h,d);
  max(h-1,d)$

symbolic inline procedure ParenWidth(h,d);
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

% Here I will measure and format a string of characters. This has
% to be done relative to a given font and size. I will specify the font
% as one of the codes as in charmetrics.red, so e.g.
%    CurrentFont := get('SizeOneSym, 'font_number);
% while the size will be an integer representing the actual font
% size to be used. I will put these in the range 16-52, with an attempt
% to get the size ratios between them abough right. My idea here is that
% if I ask for fonts at an integer point size then the renderer may get on
% better than if I ask for fractional sizes, and the choices here are
% rather broadly correct (in pixels) for a display on a high definition
% screen...  However these can then be adjusted later by somebody who has
% proper sensitivity to appearance.
%
%    tiny          17
%    scriptsize    18  
%    footnotesize  20
%    small         22
%    normalsize    24
%    large         26
%    Large         28
%    LARGE         34
%    huge          40
%    Huge          50

fluid '(CurrentFont CurrentSize);

CurrentFont := get('General, 'font_number);
CurrentSize := 24;

% This returns a list of x-offsets and codepoints, and also leave
% c_width, c_llx etc set with information about a bounding box for the
% text. Again remember that all this is done in internal units that would
% make a 1-point character fit in a box of height 1000.

symbolic procedure MeasureSymbol a;
  begin
    scalar c, w, r, first, k, height, depth, left, right;
% The next line takes a symbol and delivers a list of the Unicode
% characters that make it up. So for instance
%      wideid2list '!#alpha;!#omega;;     => (945 969)
% (note that the symbol there contains two Greek letters).
% This function can be given a symbol or a string or a number.
    if numberp a then c := explodecn a
    else if stringp a then c := widestring2list a
    else c := wideid2list a;
    prin2 "TRACE: "; print c;
    w := k := 0;
    first := t;
    for each x in c do <<
% If I am on the second or subsequent character of a word then I cgeck to
% see if it kerns with this character, and adjust my running width (w)
% accordingly.
      if not first then k := lookupkernadjustment x;
      prin2 "** Kern info = "; print k;
      w := w + k;
% Now look up the width of the current character (and in the process leave
% behind information that can be used for kerning the one that will come
% after it. I will make it an ERROR to try to use a character not supported
% in the font that is being used.
      if not lookupchar(CurrentFont, x) then
        error(0, "Character not available in font");
      if first then <<
        left := c_llx;
        right := c_urx;
        height := c_ury;
        depth := c_lly >>
      else <<
        right := w + c_urx;
        height := max(height, c_ury);
        depth := min(depth, c_llx) >>;
      r := ((CurrentSize*w) . x) . r;% List of characters and their positions.
      w := w + c_width;
      first := nil >>;
    c_llx := CurrentSize*left;
    c_urx := CurrentSize*right;
    c_lly := CurrentSize*depth;
    c_ury := CurrentSize*height;
    c_width := CurrentSize*w;
    return reversip r
  end;

% The two test cases here should yield different spacings because of
% kerning.  Specifically "VAR" shoudl end up narrower than "VRA".

MeasureSymbol '!V!A!R;
c_width;
MeasureSymbol '!V!R!A;
c_width;



symbolic procedure BuildAtomDisplayBox exp;
  MakeDisplayBox(1,0,lengthc exp,exp,nil,nil,nil,nil,nil)$

symbolic inline procedure OpHeight op;
  1$

symbolic inline procedure OpDepth op;
  0$

symbolic inline procedure OpWidth op;
  begin scalar prt;
    prt := get(op,'prtch);
    prt := if null prt then op else prt;
    return if flagp(op,'spaced) then lengthc prt + 2
            else lengthc prt
  end$

symbolic inline procedure HasPrecedenceOp(op1,op2);
  get(op1,'infix) >= get(op2,'infix)$

symbolic inline procedure HasPrecedenceExp(op,subexp);
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


symbolic procedure BreakDisplayBox(box,width_goal);
  if BoxWidth box <= width_goal then nil . box
   else if BoxIsNonBreakable box
    then rederr("not implemented (breaking special display box)")
% BreakSpecialDisplayBox(box,width_goal)
   else begin scalar x,y,z; integer offset;
     x := BoxArgList box;
     if null cdr x then return 
       ((for each pos
           in car BreakDisplayBox(caddr car x,width_goal - car car x)
             collect (pos + car car x)) . box);
    loop:
     y := car x;
     x := cdr x;
     if null x then goto exitloop;
     if car car x - offset > width_goal then <<
       offset := car y;
       z := car y . z;
       if BoxWidth caddr y > width_goal then
         for each pos in car BreakDisplayBox(caddr y,width_goal) do
           z := (offset := (car y + pos)) . z >>;
     goto loop;
    exitloop:
     if car y + BoxWidth caddr y - offset > width_goal
       then if BoxWidth caddr y <= width_goal
              then z := car y . z
             else for each pos in 
                    car BreakDisplayBox(caddr y,width_goal) do
                z := (offset := (car y + pos)) . z;
     return reversip z . box
   end$



symbolic inline procedure IsSpecialDisplayBox box;
  get(BoxOperator box,'InsertDisplayBox)$

fluid '(!*DisplayArrayDepth!*)$

symbolic inline procedure GetLine(disparray,n);
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

symbolic inline procedure InsertParens(disparray,x1,x2,y,h,d);
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
      PutChar(GetLine(disparray,y),x + i,'_)
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
